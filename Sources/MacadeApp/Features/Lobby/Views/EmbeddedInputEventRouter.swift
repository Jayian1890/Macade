import AppKit
import Foundation

@MainActor
final class EmbeddedInputEventRouter {
    static let shared = EmbeddedInputEventRouter()

    private weak var session: FightcadeEmbeddedSession?
    private var chatInput = EmbeddedChatInputController()
    private var relayInput = EmbeddedRelayController()
    private var localMonitor: Any?
    private var globalMonitor: Any?
    private var diagnosticCount = 0
    private var controllerPreferences = MacadeControllerPreferencesStore().load()
    private var preferencesObserver: NSObjectProtocol?

    private init() {
        preferencesObserver = NotificationCenter.default.addObserver(
            forName: .macadeControllerPreferencesDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            Task { @MainActor in
                self?.controllerPreferences = MacadeControllerPreferencesStore().load()
                self?.appendDiagnostic("controller preferences reloaded\n")
            }
        }
    }

    func bind(session: FightcadeEmbeddedSession?) {
        self.session = session
        chatInput = EmbeddedChatInputController()
        relayInput.reset()
        startMonitors()
        appendDiagnostic("bind session=\(session?.id.uuidString ?? "nil") active=\(session?.isActive == true)\n")
    }

    func unbind(session: FightcadeEmbeddedSession?) {
        if self.session === session {
            self.session = nil
            relayInput.reset()
            appendDiagnostic("unbind session=\(session?.id.uuidString ?? "nil")\n")
        }
    }

    func setChatActive(_ isActive: Bool, for session: FightcadeEmbeddedSession) {
        guard self.session === session, session.isActive else { return }

        if isActive {
            chatInput.begin(session: session)
            appendDiagnostic("chat-begin requested\n")
        } else {
            chatInput.cancel(session: session)
            appendDiagnostic("chat-cancel requested\n")
        }
    }

    @discardableResult
    func handle(_ event: NSEvent, source: String) -> Bool {
        guard let session, session.isActive, shouldRoute(event) else {
            return false
        }

        logEvent(event, source: source)
        switch event.type {
        case .keyDown:
            if chatInput.keyDown(with: event, session: session) {
                appendDiagnostic("chat-consumed keyDown keyCode=\(event.keyCode) chars=\(event.charactersIgnoringModifiers ?? "")\n")
                return true
            }
            if relayInput.keyDown(with: event, session: session) {
                appendDiagnostic("relay-consumed keyDown keyCode=\(event.keyCode) chars=\(event.charactersIgnoringModifiers ?? "")\n")
                return true
            }
            send(event: event, isPressed: true, session: session)
            return true
        case .keyUp:
            if chatInput.keyUp(with: event) {
                appendDiagnostic("chat-consumed keyUp keyCode=\(event.keyCode) chars=\(event.charactersIgnoringModifiers ?? "")\n")
                return true
            }
            if relayInput.keyUp(with: event) {
                appendDiagnostic("relay-consumed keyUp keyCode=\(event.keyCode) chars=\(event.charactersIgnoringModifiers ?? "")\n")
                return true
            }
            send(event: event, isPressed: false, session: session)
            return true
        default:
            return false
        }
    }

    private func startMonitors() {
        if localMonitor == nil {
            localMonitor = NSEvent.addLocalMonitorForEvents(matching: [.keyDown, .keyUp]) { [weak self] event in
                guard let self else { return event }
                let handled = MainActor.assumeIsolated {
                    self.handle(event, source: "local")
                }
                return handled ? nil : event
            }
            appendDiagnostic("local monitor installed\n")
        }

        if globalMonitor == nil {
            globalMonitor = NSEvent.addGlobalMonitorForEvents(matching: [.keyDown, .keyUp]) { [weak self] event in
                Task { @MainActor [weak self] in
                    _ = self?.handle(event, source: "global")
                }
            }
            appendDiagnostic("global monitor installed\n")
        }
    }

    private func shouldRoute(_ event: NSEvent) -> Bool {
        if isTextInputFocused {
            return false
        }

        if event.modifierFlags.intersection(.deviceIndependentFlagsMask).contains(.command) {
            return false
        }

        return event.type == .keyDown || event.type == .keyUp
    }

    private var isTextInputFocused: Bool {
        guard let responder = NSApp.keyWindow?.firstResponder else { return false }
        if responder is NSTextView { return true }
        if responder is NSTextField { return true }
        if responder is RelayCaptureResponder { return true }
        return false
    }

    private func send(event: NSEvent, isPressed: Bool, session: FightcadeEmbeddedSession) {
        guard let scancode = controllerPreferences.targetScancode(for: event.keyCode) ?? SDLScancodeMapper.scancode(for: event) else {
            appendDiagnostic("unmapped keyCode=\(event.keyCode) chars=\(event.charactersIgnoringModifiers ?? "")\n")
            return
        }

        appendDiagnostic("send keyCode=\(event.keyCode) chars=\(event.charactersIgnoringModifiers ?? "") scancode=\(scancode) pressed=\(isPressed ? 1 : 0)\n")
        session.inputClient.sendKey(scancode: scancode, isPressed: isPressed)
    }

    private func logEvent(_ event: NSEvent, source: String) {
        guard diagnosticCount < 40 else { return }
        diagnosticCount += 1
        appendDiagnostic(
            "event source=\(source) type=\(event.type.rawValue) keyCode=\(event.keyCode) chars=\(event.charactersIgnoringModifiers ?? "") active=\(session?.isActive == true)\n"
        )
    }

    private func appendDiagnostic(_ message: String) {
        Self.appendDiagnostic("\(Date()) \(message)")
    }

    private static func appendDiagnostic(_ line: String) {
        guard let logsURL = FileManager.default.urls(for: .libraryDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Logs")
            .appendingPathComponent("Macade") else {
            return
        }

        try? FileManager.default.createDirectory(at: logsURL, withIntermediateDirectories: true)
        let url = logsURL.appendingPathComponent("fightcade-embedded-input-events-latest.log")
        guard let data = line.data(using: .utf8) else { return }

        if !FileManager.default.fileExists(atPath: url.path) {
            FileManager.default.createFile(atPath: url.path, contents: nil)
        }

        guard let handle = try? FileHandle(forWritingTo: url) else { return }
        defer { try? handle.close() }
        _ = try? handle.seekToEnd()
        try? handle.write(contentsOf: data)
    }
}
