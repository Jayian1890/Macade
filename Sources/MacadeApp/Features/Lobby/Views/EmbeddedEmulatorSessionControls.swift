import AppKit
import SwiftUI

struct EmbeddedEmulatorSessionControls: View {
    let session: FightcadeEmbeddedSession

    @State private var settings = FightcadeFBNeoSettings.defaults
    @State private var settingsStatus: String?

    private let settingsStore = FightcadeFBNeoSettingsStore()

    var body: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            if session.mode == .replay {
                ReplayPlaybackControls(session: session)
            }

            recordMenu
            scaleMenu
            scanlinesButton
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

    private var scanlinesButton: some View {
        Button {
            updateSettings { $0.scanlines.toggle() }
        } label: {
            controlLabel("Scanlines", isActive: settings.scanlines)
        }
        .buttonStyle(.plain)
        .help(settingsStatus ?? (settings.scanlines ? "Disable scanlines" : "Enable scanlines"))
    }

    private var scaleMenu: some View {
        Menu {
            Button("Fit") {
                updateSettings { $0.embeddedVideoScale = 0 }
            }

            Divider()

            ForEach(1...5, id: \.self) { scale in
                Button("\(scale)x") {
                    updateSettings { $0.embeddedVideoScale = scale }
                }
            }
        } label: {
            controlLabel(scaleTitle, isActive: settings.embeddedVideoScale > 0)
        }
        .menuStyle(.borderlessButton)
        .help("Embedded video scale")
    }

    private var scaleTitle: String {
        settings.embeddedVideoScale > 0 ? "\(settings.embeddedVideoScale)x" : "Fit"
    }

    private var sessionLogExists: Bool {
        FileManager.default.fileExists(atPath: session.logURL.path)
    }

    private func controlLabel(_ title: String, isActive: Bool = false) -> some View {
        Text(title)
            .font(.system(size: 11, weight: .black, design: .monospaced))
            .foregroundStyle(isActive ? MacadeColor.neonCyan : MacadeColor.inkMuted)
    }

    private func updateSettings(_ update: (inout FightcadeFBNeoSettings) -> Void) {
        var next = settings
        update(&next)
        next = next.normalized()
        let previousVideoScale = settings.embeddedVideoScale

        do {
            try settingsStore.save(next)
            settings = next
            if next.embeddedVideoScale != previousVideoScale {
                session.inputClient.setVideoScale(next.embeddedVideoScale)
            }
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

private struct ReplayPlaybackControls: View {
    let session: FightcadeEmbeddedSession
    @State private var scrubFrame = 0.0
    @State private var isScrubbing = false

    private let stepFrames = 300

    var body: some View {
        if let state = session.overlayState?.replayControl {
            HStack(spacing: 5) {
                iconButton("backward.fill", help: "Reverse 5 seconds") {
                    session.inputClient.stepReplay(by: -stepFrames)
                }

                iconButton(state.isPaused ? "play.fill" : "pause.fill", help: state.isPaused ? "Play" : "Pause") {
                    session.inputClient.setReplayPaused(!state.isPaused)
                }

                iconButton("forward.fill", isActive: state.isFastForwarding, help: "Fast forward") {
                    session.inputClient.setReplayFastForwarding(!state.isFastForwarding)
                }

                Slider(
                    value: Binding(
                        get: { isScrubbing ? scrubFrame : Double(state.currentFrame) },
                        set: { scrubFrame = $0; isScrubbing = true }
                    ),
                    in: 0...Double(max(state.totalFrames, state.bufferedFrames, 1)),
                    step: 1,
                    onEditingChanged: scrubChanged
                )
                .frame(width: 132)
                .disabled(!state.isSeekable)

                Text(frameText(state))
                    .font(.system(size: 10, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.inkMuted)
                    .frame(width: 86, alignment: .trailing)
            }
            .help(state.isSeekable ? "Scrub through buffered replay frames" : "Replay is buffering before seeking is available")
        }
    }

    private func iconButton(_ name: String, isActive: Bool = false, help: String, action: @escaping () -> Void) -> some View {
        Button(action: action) {
            Image(systemName: name)
                .font(.system(size: 10, weight: .black))
                .frame(width: 22, height: 22)
                .foregroundStyle(isActive ? MacadeColor.midnight : MacadeColor.inkMuted)
                .background(isActive ? MacadeColor.warning : MacadeColor.panel.opacity(0.82), in: Circle())
        }
        .buttonStyle(.plain)
        .help(help)
    }

    private func scrubChanged(_ editing: Bool) {
        guard !editing else { return }
        session.inputClient.seekReplay(to: Int(scrubFrame.rounded()))
        isScrubbing = false
    }

    private func frameText(_ state: FightcadeReplayControlState) -> String {
        let total = max(state.totalFrames, state.bufferedFrames)
        guard total > 0 else { return "-- / --" }
        return "\(state.currentFrame) / \(total)"
    }
}
