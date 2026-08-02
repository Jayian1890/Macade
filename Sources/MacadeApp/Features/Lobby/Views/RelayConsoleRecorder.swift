import AppKit

@MainActor
final class RelayConsoleRecorder {
    private var monitor: Any?
    private weak var activeSession: FightcadeEmbeddedSession?
    private var controllerPreferences = MacadeControllerPreferences.defaults
    private var recordedFrames: [MacadeRelayFrame] = []
    private var pressedNodes: [UInt16: MacadeRelayNode] = [:]
    private var pressOrder: [UInt16] = []
    private var lastTimestamp: TimeInterval?
    private var cancelHandler: (() -> Void)?

    var isActive: Bool { monitor != nil }

    func start(
        controllerPreferences: MacadeControllerPreferences,
        activeSession: FightcadeEmbeddedSession?,
        onCancel: @escaping () -> Void
    ) {
        cancel()
        self.controllerPreferences = controllerPreferences
        self.activeSession = activeSession
        cancelHandler = onCancel
        monitor = NSEvent.addLocalMonitorForEvents(matching: [.keyDown, .keyUp]) { [weak self] event in
            guard let self else { return event }
            let handled = MainActor.assumeIsolated {
                self.handle(event)
            }
            return handled ? nil : event
        }
    }

    func stop() -> [MacadeRelayFrame] {
        guard isActive else { return [] }
        if !pressedNodes.isEmpty {
            appendSegment(until: ProcessInfo.processInfo.systemUptime)
        }
        releasePressedKeys()
        removeMonitor()
        let output = recordedFrames
        reset()
        return output
    }

    func cancel() {
        releasePressedKeys()
        removeMonitor()
        reset()
    }

    deinit {
        MainActor.assumeIsolated {
            cancel()
        }
    }

    private func handle(_ event: NSEvent) -> Bool {
        switch event.type {
        case .keyDown:
            if event.keyCode == 53 {
                cancel()
                cancelHandler?()
                return true
            }
            guard !event.isARepeat,
                  pressedNodes[event.keyCode] == nil,
                  let node = RelayInputMapper.node(for: event, controllerPreferences: controllerPreferences),
                  !pressedNodes.values.contains(where: { $0.scancode == node.scancode }) else {
                return true
            }

            appendSegment(until: event.timestamp)
            pressedNodes[event.keyCode] = node
            pressOrder.append(event.keyCode)
            lastTimestamp = event.timestamp
            activeSession?.inputClient.sendKey(scancode: node.scancode, isPressed: true)
            return true
        case .keyUp:
            guard let node = pressedNodes[event.keyCode] else { return true }
            appendSegment(until: event.timestamp)
            pressedNodes.removeValue(forKey: event.keyCode)
            pressOrder.removeAll { $0 == event.keyCode }
            lastTimestamp = event.timestamp
            activeSession?.inputClient.sendKey(scancode: node.scancode, isPressed: false)
            return true
        default:
            return false
        }
    }

    private func appendSegment(until timestamp: TimeInterval) {
        guard let lastTimestamp else {
            self.lastTimestamp = timestamp
            return
        }

        let milliseconds = max(0, Int(((timestamp - lastTimestamp) * 1_000).rounded()))
        guard milliseconds > 0 else { return }

        let nodes = pressOrder.compactMap { pressedNodes[$0] }
        if nodes.isEmpty {
            guard !recordedFrames.isEmpty else { return }
            recordedFrames[recordedFrames.count - 1].gapMilliseconds = clampedGap(milliseconds)
        } else {
            recordedFrames.append(MacadeRelayFrame(
                nodes: nodes,
                holdMilliseconds: clampedHold(milliseconds),
                gapMilliseconds: 0
            ))
        }
    }

    private func releasePressedKeys() {
        for keyCode in pressOrder.reversed() {
            guard let node = pressedNodes[keyCode] else { continue }
            activeSession?.inputClient.sendKey(scancode: node.scancode, isPressed: false)
        }
    }

    private func removeMonitor() {
        if let monitor {
            NSEvent.removeMonitor(monitor)
            self.monitor = nil
        }
    }

    private func reset() {
        recordedFrames.removeAll()
        pressedNodes.removeAll()
        pressOrder.removeAll()
        lastTimestamp = nil
        activeSession = nil
        cancelHandler = nil
    }

    private func clampedHold(_ milliseconds: Int) -> Int {
        min(max(milliseconds, MacadeRelayProfile.holdRange.lowerBound), MacadeRelayProfile.holdRange.upperBound)
    }

    private func clampedGap(_ milliseconds: Int) -> Int {
        min(max(milliseconds, MacadeRelayProfile.gapRange.lowerBound), MacadeRelayProfile.gapRange.upperBound)
    }
}
