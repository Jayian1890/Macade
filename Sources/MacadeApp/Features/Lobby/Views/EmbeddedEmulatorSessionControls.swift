import AppKit
import SwiftUI

struct EmbeddedEmulatorSessionControls: View {
    let session: FightcadeEmbeddedSession

    @State private var settings = FightcadeFBNeoSettings.defaults
    @State private var settingsStatus: String?

    private let settingsStore = FightcadeFBNeoSettingsStore()

    var body: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            recordMenu
            videoMenu
            audioMenu
        }
        .onAppear(perform: reloadSettings)
        .onReceive(NotificationCenter.default.publisher(for: .fightcadeFBNeoSettingsDidChange)) { _ in
            reloadSettings()
        }
    }

    private var recordMenu: some View {
        Menu {
            Button("Open Session Log", action: openSessionLog)
                .disabled(!sessionLogExists)
            Button("Reveal Session Log", action: revealSessionLog)
                .disabled(!sessionLogExists)
            Button("Copy Session Summary", action: copySessionSummary)

            Divider()

            Button("Video Recording Unavailable") { }
                .disabled(true)
            Button("FBNeo Replay Recording Unavailable") { }
                .disabled(true)
        } label: {
            controlLabel("Record")
        }
        .menuStyle(.borderlessButton)
        .help("Session log and recording status")
    }

    private var videoMenu: some View {
        Menu {
            Toggle("Stretch to Window", isOn: boolBinding(\.stretchToWindow))
            Toggle("Show Scanlines", isOn: boolBinding(\.scanlines))
            Toggle("Software Brightness", isOn: boolBinding(\.softwareGamma))

            Divider()

            Button("Brightness +0.05") {
                updateSettings { $0.gamma = min(2.0, $0.gamma + 0.05) }
            }
            Button("Brightness -0.05") {
                updateSettings { $0.gamma = max(0.5, $0.gamma - 0.05) }
            }
            Button("Brightness: \(settings.gamma.formatted(.number.precision(.fractionLength(2))))") { }
                .disabled(true)

            settingsStatusItem
        } label: {
            controlLabel("Video")
        }
        .menuStyle(.borderlessButton)
        .help("FBNeo video settings")
    }

    private var audioMenu: some View {
        Menu {
            Button("Volume +5%") {
                updateSettings { $0.volume = min(100, $0.volume + 5) }
            }
            Button("Volume -5%") {
                updateSettings { $0.volume = max(0, $0.volume - 5) }
            }
            Button("Volume: \(settings.volume)%") { }
                .disabled(true)

            Divider()

            Picker("Sample Rate", selection: intBinding(\.sampleRate)) {
                Text("44.1 kHz").tag(44_100)
                Text("48 kHz").tag(48_000)
                Text("96 kHz").tag(96_000)
            }

            Toggle("DSP Filter", isOn: boolBinding(\.dspFilter))

            Picker("PCM Smoothing", selection: intBinding(\.pcmInterpolation)) {
                Text("Off").tag(0)
                Text("Standard").tag(1)
                Text("High").tag(3)
            }

            Picker("FM Smoothing", selection: intBinding(\.fmInterpolation)) {
                Text("Off").tag(0)
                Text("Standard").tag(1)
                Text("High").tag(3)
            }

            settingsStatusItem
        } label: {
            controlLabel("Audio")
        }
        .menuStyle(.borderlessButton)
        .help("FBNeo audio settings")
    }

    @ViewBuilder
    private var settingsStatusItem: some View {
        if let settingsStatus {
            Divider()
            Button(settingsStatus) { }
                .disabled(true)
        }
    }

    private var sessionLogExists: Bool {
        FileManager.default.fileExists(atPath: session.logURL.path)
    }

    private func controlLabel(_ title: String) -> some View {
        Text(title)
            .font(.system(size: 11, weight: .black, design: .monospaced))
            .foregroundStyle(MacadeColor.inkMuted)
    }

    private func boolBinding(_ keyPath: WritableKeyPath<FightcadeFBNeoSettings, Bool>) -> Binding<Bool> {
        Binding(
            get: { settings[keyPath: keyPath] },
            set: { newValue in
                updateSettings { $0[keyPath: keyPath] = newValue }
            }
        )
    }

    private func intBinding(_ keyPath: WritableKeyPath<FightcadeFBNeoSettings, Int>) -> Binding<Int> {
        Binding(
            get: { settings[keyPath: keyPath] },
            set: { newValue in
                updateSettings { $0[keyPath: keyPath] = newValue }
            }
        )
    }

    private func updateSettings(_ update: (inout FightcadeFBNeoSettings) -> Void) {
        var next = settings
        update(&next)
        next = next.normalized()

        do {
            try settingsStore.save(next)
            settings = next
            settingsStatus = nil
            NotificationCenter.default.post(name: .fightcadeFBNeoSettingsDidChange, object: nil)
        } catch {
            settingsStatus = "Save failed: \(error.localizedDescription)"
        }
    }

    private func reloadSettings() {
        do {
            settings = try settingsStore.load()
            settingsStatus = nil
        } catch {
            settings = FightcadeFBNeoSettings.defaults
            settingsStatus = "Using default settings"
        }
    }

    private func openSessionLog() {
        NSWorkspace.shared.open(session.logURL)
    }

    private func revealSessionLog() {
        NSWorkspace.shared.activateFileViewerSelecting([session.logURL])
    }

    private func copySessionSummary() {
        let pasteboard = NSPasteboard.general
        pasteboard.clearContents()
        pasteboard.setString(sessionSummary, forType: .string)
    }

    private var sessionSummary: String {
        [
            "Mode: \(session.mode.rawValue)",
            "Game: \(session.gameID)",
            "Title: \(session.title)",
            "Status: \(session.statusText)",
            "Log: \(session.logURL.path)"
        ].joined(separator: "\n")
    }
}
