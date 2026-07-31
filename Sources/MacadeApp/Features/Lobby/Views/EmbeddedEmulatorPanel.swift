import AppKit
import SwiftUI
import QuartzCore
import MetalKit

struct EmbeddedEmulatorPanel: View {
    let session: FightcadeEmbeddedSession
    let isChannelChatVisible: Bool
    let onToggleChannelChat: () -> Void
    let onStop: () -> Void

    @State private var polledOverlayState: FightcadeEmbeddedOverlayState?

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

                        if let state = netplayLoadingState {
                            NetplayLoadingOverlay(state: state, gameID: session.gameID)
                        }
                    }
                    .frame(width: frame.width, height: frame.height)
                }
                .frame(width: proxy.size.width, height: proxy.size.height)
            }
        }
        .background(.black)
        .task(id: session.id) {
            await pollOverlayState()
        }
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

    private var currentOverlayState: FightcadeEmbeddedOverlayState? {
        session.overlayState ?? polledOverlayState
    }

    private var netplayLoadingState: NetplayLoadingState? {
        guard session.mode == .match || session.mode == .direct || session.mode == .spectate else { return nil }
        var phase = currentOverlayState?.connectionPhase ?? 0
        if session.mode == .spectate, session.overlayState != nil, phase >= NetplayLoadingPhase.matchReady.rawValue {
            phase = NetplayLoadingPhase.ready.rawValue
        }
        if phase == NetplayLoadingPhase.ready.rawValue { return nil }
        return NetplayLoadingState(status: session.status, phase: phase)
    }

    private var chatModeTitle: String {
        isChannelChatVisible ? "GAME" : "CHAT"
    }

    private func pollOverlayState() async {
        while !Task.isCancelled, session.isActive {
            if let state = session.videoStream.overlaySnapshot(), state != polledOverlayState {
                polledOverlayState = state
            }
            try? await Task.sleep(for: .milliseconds(150))
        }
    }
}

private enum NetplayLoadingPhase: Int, CaseIterable {
    case launch = 0
    case connectServer = 1
    case serverConnected = 2
    case matchInfo = 3
    case matchReady = 4
    case peerConnected = 5
    case synchronizing = 6
    case ready = 7
    case disconnected = 8

    var title: String {
        switch self {
        case .launch: "Launch Runtime"
        case .connectServer: "Connect Server"
        case .serverConnected: "Server Linked"
        case .matchInfo: "Fetch Match Info"
        case .matchReady: "Match Loaded"
        case .peerConnected: "Peer Connected"
        case .synchronizing: "Synchronize"
        case .ready: "Ready"
        case .disconnected: "Disconnected"
        }
    }

    var detail: String {
        switch self {
        case .launch: "Starting FBNeo and native GGPO"
        case .connectServer: "Opening Fightcade session"
        case .serverConnected: "Authenticated with Fightcade"
        case .matchInfo: "Receiving players and match metadata"
        case .matchReady: "Preparing the game state"
        case .peerConnected: "UDP peer handshake completed"
        case .synchronizing: "Exchanging sync packets"
        case .ready: "Rollback session is live"
        case .disconnected: "Connection closed before ready"
        }
    }
}

private struct NetplayLoadingState {
    let status: FightcadeEmbeddedSession.Status
    let phase: Int

    var currentPhase: NetplayLoadingPhase {
        NetplayLoadingPhase(rawValue: phase) ?? .launch
    }

    var completedPhase: Int {
        switch status {
        case .failed, .terminated:
            NetplayLoadingPhase.disconnected.rawValue
        default:
            phase
        }
    }
}

private struct NetplayLoadingOverlay: View {
    let state: NetplayLoadingState
    let gameID: String

    var body: some View {
        ZStack {
            LinearGradient(
                colors: [.black.opacity(0.9), MacadeColor.panel.opacity(0.84), .black.opacity(0.92)],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )

            VStack(alignment: .leading, spacing: 18) {
                header
                stepList
            }
            .padding(22)
            .frame(maxWidth: 520, alignment: .leading)
            .background(.black.opacity(0.58), in: RoundedRectangle(cornerRadius: 18))
            .overlay(RoundedRectangle(cornerRadius: 18).stroke(MacadeColor.neonCyan.opacity(0.36), lineWidth: 1))
            .shadow(color: MacadeColor.neonCyan.opacity(0.18), radius: 24)
            .padding(24)
        }
        .allowsHitTesting(false)
    }

    private var header: some View {
        VStack(alignment: .leading, spacing: 6) {
            Text("NETPLAY LINK")
                .font(.system(size: 11, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
                .tracking(2)

            Text(gameID.uppercased())
                .font(.system(size: 28, weight: .black, design: .monospaced))
                .foregroundStyle(.white)

            Text(state.currentPhase.detail)
                .font(.system(size: 12, weight: .bold, design: .monospaced))
                .foregroundStyle(MacadeColor.inkMuted)
        }
    }

    private var stepList: some View {
        VStack(alignment: .leading, spacing: 10) {
            ForEach(NetplayLoadingPhase.allCases.filter { $0 != .disconnected }, id: \.rawValue) { phase in
                NetplayLoadingStepRow(phase: phase, state: rowState(for: phase))
            }
        }
    }

    private func rowState(for phase: NetplayLoadingPhase) -> NetplayLoadingStepRow.State {
        if state.currentPhase == .disconnected { return phase.rawValue < state.completedPhase ? .done : .waiting }
        if phase.rawValue < state.completedPhase { return .done }
        if phase.rawValue == state.completedPhase { return .active }
        return .waiting
    }
}

private struct NetplayLoadingStepRow: View {
    enum State { case done, active, waiting }

    let phase: NetplayLoadingPhase
    let state: State

    var body: some View {
        HStack(spacing: 10) {
            Image(systemName: symbolName)
                .font(.system(size: 12, weight: .black))
                .foregroundStyle(color)
                .frame(width: 18)

            Text(phase.title)
                .font(.system(size: 12, weight: .black, design: .monospaced))
                .foregroundStyle(state == .waiting ? MacadeColor.inkMuted.opacity(0.55) : .white)

            Spacer(minLength: 8)
        }
        .padding(.horizontal, 10)
        .frame(height: 28)
        .background(state == .active ? MacadeColor.neonCyan.opacity(0.12) : .white.opacity(0.04), in: Capsule())
    }

    private var symbolName: String {
        switch state {
        case .done: "checkmark.circle.fill"
        case .active: "dot.radiowaves.left.and.right"
        case .waiting: "circle"
        }
    }

    private var color: Color {
        switch state {
        case .done: MacadeColor.rankC
        case .active: MacadeColor.neonCyan
        case .waiting: MacadeColor.inkMuted.opacity(0.45)
        }
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
