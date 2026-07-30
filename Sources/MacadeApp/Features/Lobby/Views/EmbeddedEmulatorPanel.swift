import AppKit
import SwiftUI
import QuartzCore
import MetalKit

struct EmbeddedEmulatorPanel: View {
    let session: FightcadeEmbeddedSession
    let isChannelChatVisible: Bool
    let onToggleChannelChat: () -> Void
    let onStop: () -> Void

    var body: some View {
        VStack(spacing: 0) {
            sessionBar

            GeometryReader { proxy in
                let frame = aspectFrame(in: proxy.size)
                ZStack {
                    Color.black

                    ZStack {
                        FightcadeEmbeddedVideoView(session: session)

                        if let overlayState = session.overlayState, overlayState.isEnabled {
                            NativeEmulatorOverlay(state: overlayState)
                        }
                    }
                    .frame(width: frame.width, height: frame.height)
                }
                .frame(width: proxy.size.width, height: proxy.size.height)
            }
        }
        .background(.black)
    }

    private func aspectFrame(in size: CGSize) -> CGSize {
        let aspect = CGFloat(max(session.videoAspectRatio, 0.1))
        guard size.width > 0, size.height > 0 else { return size }
        if size.width / size.height > aspect {
            return CGSize(width: size.height * aspect, height: size.height)
        }

        return CGSize(width: size.width, height: size.width / aspect)
    }

    private var sessionBar: some View {
        HStack(spacing: MacadeSpacing.small) {
            Image(systemName: session.mode == .spectate ? "eye.fill" : "gamecontroller.fill")
                .font(.system(size: 12, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)
                .help(session.mode.rawValue)

            Text(session.gameID.uppercased())
                .font(.system(size: 12, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
                .lineLimit(1)
                .help(session.title)

            statusDot

            Spacer()

            if session.mode == .match || session.mode == .spectate {
                EmbeddedEmulatorSessionControls(session: session)
            }

            Button(chatModeTitle) {
                onToggleChannelChat()
            }
            .buttonStyle(.borderless)
            .font(.system(size: 11, weight: .black, design: .monospaced))
            .foregroundStyle(isChannelChatVisible ? MacadeColor.warning : MacadeColor.inkMuted)
            .help(isChannelChatVisible ? "Hide channel chat" : "Show channel chat")

            Button(role: .destructive, action: onStop) {
                Image(systemName: "xmark.circle.fill")
                    .font(.system(size: 13, weight: .black))
                    .frame(width: 24, height: 24)
            }
            .buttonStyle(.borderless)
            .foregroundStyle(MacadeColor.ink)
            .help("Stop")
        }
        .padding(.horizontal, MacadeSpacing.small)
        .frame(height: 32)
        .background(MacadeColor.sidebar.opacity(0.62))
        .overlay(alignment: .bottom) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }

    private var statusDot: some View {
        Circle()
            .fill(session.isActive ? MacadeColor.warning : MacadeColor.inkMuted)
            .frame(width: 7, height: 7)
            .help(session.statusText)
    }

    private var isChatInputActive: Bool {
        session.overlayState?.isChatInputActive == true
    }

    private var chatModeTitle: String {
        isChannelChatVisible ? "GAME" : "CHAT"
    }
}

private struct NativeEmulatorOverlay: View {
    let state: FightcadeEmbeddedOverlayState

    var body: some View {
        GeometryReader { proxy in
            ZStack {
                scoreLayer(size: proxy.size)
                detailLayer(size: proxy.size)
                spectatorLayer(size: proxy.size)
                chatLayer(size: proxy.size)
            }
            .frame(width: proxy.size.width, height: proxy.size.height)
        }
        .allowsHitTesting(false)
    }

    private func scoreLayer(size: CGSize) -> some View {
        let boxWidth = min(max(size.width / 2 - 32, 128), 220)
        let topY: CGFloat = 24

        return ZStack {
            OverlayPlayerBox(
                prefix: "P1",
                player: player(at: 0),
                isLocalPlayer: !state.isSpectator && state.player == 0,
                width: boxWidth
            )
            .position(x: size.width * 0.25, y: topY)

            OverlayPlayerBox(
                prefix: "P2",
                player: player(at: 1),
                isLocalPlayer: !state.isSpectator && state.player == 1,
                width: boxWidth
            )
            .position(x: size.width * 0.75, y: topY)

            Text(centerText)
                .font(.system(size: 11, weight: .black, design: .monospaced))
                .foregroundStyle(.white)
                .padding(.horizontal, 10)
                .frame(height: 18)
                .background(.black.opacity(0.76), in: Capsule())
                .position(x: size.width / 2, y: topY + 14)
        }
    }

    private func detailLayer(size: CGSize) -> some View {
        VStack(spacing: 6) {
            Text(detailText)
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(.white.opacity(0.84))

            if state.systemFrames > 0, !state.systemMessage.isEmpty {
                Text(state.systemMessage)
                    .font(.system(size: 11, weight: .black, design: .monospaced))
                    .foregroundStyle(.white)
                    .padding(.horizontal, 10)
                    .frame(height: 20)
                    .background(.black.opacity(0.78), in: Capsule())
            }
        }
        .lineLimit(1)
        .position(x: size.width / 2, y: 62)
    }

    @ViewBuilder
    private func spectatorLayer(size: CGSize) -> some View {
        if state.isSpectator, spectatorDisplayCount > 0 {
            Text("Spectators \(spectatorDisplayCount)")
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
                .padding(.horizontal, 10)
                .frame(height: 22)
                .background(.black.opacity(0.78), in: Capsule())
                .position(x: size.width / 2, y: max(18, size.height - 18))
        }
    }

    @ViewBuilder
    private func chatLayer(size: CGSize) -> some View {
        if state.isChatInputActive || state.chatFrames > 0, !chatRows.isEmpty {
            VStack(alignment: .leading, spacing: 3) {
                ForEach(chatRows) { row in
                    Text(row.text)
                        .font(.system(size: 10, weight: .bold, design: .monospaced))
                        .foregroundStyle(row.isInput ? .white : MacadeColor.warning.opacity(0.92))
                        .lineLimit(1)
                }
            }
            .padding(.horizontal, 8)
            .padding(.vertical, 6)
            .frame(width: min(360, max(120, size.width - 16)), alignment: .leading)
            .background(.black.opacity(0.82), in: RoundedRectangle(cornerRadius: 8))
            .position(
                x: min(360, max(120, size.width - 16)) / 2 + 8,
                y: max(20, size.height - chatHeight / 2 - 8)
            )
        }
    }

    private var centerText: String {
        state.ranked > 1 ? "FT\(state.ranked)" : "VS"
    }

    private var detailText: String {
        if state.isSpectator {
            return "Spectating"
        }

        if state.ping > 0 {
            return "Ping \(state.ping)ms | Delay \(state.delay)"
        }

        return "Delay \(state.delay)"
    }

    private var spectatorDisplayCount: Int {
        max(0, state.spectators - 1)
    }

    private var chatRows: [OverlayChatRow] {
        var rows = state.chatLines.reversed().map { line in
            OverlayChatRow(text: "\(line.name): \(line.text)", isInput: false)
        }

        if state.isChatInputActive {
            rows.append(OverlayChatRow(text: "> \(state.chatInput)_", isInput: true))
        }

        return rows
    }

    private var chatHeight: CGFloat {
        CGFloat(chatRows.count * 13 + 12)
    }

    private func player(at index: Int) -> FightcadeEmbeddedOverlayState.Player {
        guard state.players.indices.contains(index) else {
            return FightcadeEmbeddedOverlayState.Player(
                name: "",
                country: "",
                rank: -1,
                score: 0,
                fallbackName: "Player \(index + 1)"
            )
        }

        return state.players[index]
    }

    private struct OverlayChatRow: Identifiable {
        let id = UUID()
        let text: String
        let isInput: Bool
    }
}

private struct OverlayPlayerBox: View {
    let prefix: String
    let player: FightcadeEmbeddedOverlayState.Player
    let isLocalPlayer: Bool
    let width: CGFloat

    var body: some View {
        VStack(spacing: 1) {
            Text("\(prefix) \(player.displayName)\(isLocalPlayer ? " *" : "")")
                .font(.system(size: 12, weight: .black, design: .monospaced))
                .foregroundStyle(.white)
                .lineLimit(1)

            Text("\(player.score)")
                .font(.system(size: 13, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
        }
        .padding(.horizontal, 8)
        .frame(width: width, height: 40)
        .background(.black.opacity(0.8), in: RoundedRectangle(cornerRadius: 8))
    }
}

private struct FightcadeEmbeddedVideoView: NSViewRepresentable {
    let session: FightcadeEmbeddedSession

    func makeNSView(context: Context) -> EmbeddedVideoNSView {
        let view = EmbeddedVideoNSView()
        view.session = session
        return view
    }

    func updateNSView(_ nsView: EmbeddedVideoNSView, context: Context) {
        nsView.session = session
    }
}
