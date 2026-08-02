import AppKit
import SwiftUI
import QuartzCore
import MetalKit

struct EmbeddedEmulatorPanel: View {
    let session: FightcadeEmbeddedSession
    let isChannelChatVisible: Bool
    let channelChatOverlay: AnyView?
    let videoOverlay: AnyView?
    let onToggleChannelChat: () -> Void
    let onMatchEnded: () -> Void
    let onStop: () -> Void

    @State private var polledOverlayState: FightcadeEmbeddedOverlayState?

    init(
        session: FightcadeEmbeddedSession,
        isChannelChatVisible: Bool,
        channelChatOverlay: AnyView?,
        videoOverlay: AnyView? = nil,
        onToggleChannelChat: @escaping () -> Void,
        onMatchEnded: @escaping () -> Void,
        onStop: @escaping () -> Void
    ) {
        self.session = session
        self.isChannelChatVisible = isChannelChatVisible
        self.channelChatOverlay = channelChatOverlay
        self.videoOverlay = videoOverlay
        self.onToggleChannelChat = onToggleChannelChat
        self.onMatchEnded = onMatchEnded
        self.onStop = onStop
    }

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

                        if let videoOverlay {
                            videoOverlay
                        }
                    }
                    .frame(width: frame.width, height: frame.height)

                    if let channelChatOverlay, isChannelChatVisible {
                        channelChatOverlay
                            .frame(width: frame.width, height: frame.height)
                            .position(x: proxy.size.width / 2, y: proxy.size.height / 2)
                            .transition(.opacity)
                    }
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
        size
    }

    private var sessionBar: some View {
        HStack(spacing: MacadeSpacing.small) {
            Image(systemName: modeIconName)
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

            if session.mode == .match || session.mode == .spectate || session.mode == .replay {
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

    private var modeIconName: String {
        switch session.mode {
        case .spectate:
            "eye.fill"
        case .replay:
            "play.tv.fill"
        case .test, .training, .direct, .match:
            "gamecontroller.fill"
        }
    }

    private func pollOverlayState() async {
        while !Task.isCancelled, session.isActive {
            if let state = session.videoStream.overlaySnapshot() {
                if state.isMatchEnded, session.mode == .match {
                    onMatchEnded()
                    return
                }
                guard state != polledOverlayState else {
                    try? await Task.sleep(for: .milliseconds(150))
                    continue
                }
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
