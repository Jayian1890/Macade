import AppKit
import SwiftUI
import QuartzCore

struct EmbeddedEmulatorPanel: View {
    let session: FightcadeEmbeddedSession
    let isChannelChatVisible: Bool
    let onToggleChannelChat: () -> Void
    let onStop: () -> Void

    var body: some View {
        VStack(spacing: 0) {
            sessionBar

            ZStack {
                FightcadeEmbeddedVideoView(session: session)

                if let overlayState = session.overlayState, overlayState.isEnabled {
                    NativeEmulatorOverlay(state: overlayState)
                }
            }
        }
        .background(.black)
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
                .background(.black.opacity(0.56), in: Capsule())
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
                    .background(.black.opacity(0.58), in: Capsule())
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
                .background(.black.opacity(0.58), in: Capsule())
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
            .background(.black.opacity(0.62), in: RoundedRectangle(cornerRadius: 8))
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
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(.white)
                .lineLimit(1)

            Text("\(player.score)")
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
        }
        .padding(.horizontal, 6)
        .frame(width: width, height: 34)
        .background(.black.opacity(0.56), in: RoundedRectangle(cornerRadius: 8))
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

private final class EmbeddedVideoNSView: NSView {
    var session: FightcadeEmbeddedSession? {
        didSet {
            guard oldValue !== session else { return }
            EmbeddedInputEventRouter.shared.unbind(session: oldValue)
            EmbeddedInputEventRouter.shared.bind(session: session)
            videoStream = session?.videoStream
        }
    }

    private let imageLayer = CALayer()
    private let renderQueue = DispatchQueue(label: "com.macade.embedded-video.render", qos: .userInteractive)
    private var displayLink: CADisplayLink?
    private var lastFrameIndex: UInt64 = 0
    private var isRendering = false
    private var scanlinesEnabled = false
    private var videoStream: FightcadeEmbeddedVideoStream?

    override init(frame frameRect: NSRect) {
        super.init(frame: frameRect)
        wantsLayer = true
        layer?.backgroundColor = NSColor.black.cgColor
        imageLayer.contentsGravity = .resizeAspect
        imageLayer.magnificationFilter = .nearest
        imageLayer.minificationFilter = .nearest
        imageLayer.actions = [
            "bounds": NSNull(),
            "contents": NSNull(),
            "frame": NSNull(),
            "position": NSNull()
        ]
        layer?.addSublayer(imageLayer)
        reloadVideoSettings()
    }

    required init?(coder: NSCoder) {
        nil
    }

    override var acceptsFirstResponder: Bool { true }

    override func layout() {
        super.layout()
        imageLayer.frame = bounds
    }

    override func viewDidMoveToWindow() {
        super.viewDidMoveToWindow()
        if window == nil {
            stopDisplayLink()
            EmbeddedInputEventRouter.shared.unbind(session: session)
        } else {
            startDisplayLink()
            EmbeddedInputEventRouter.shared.bind(session: session)
            window?.makeFirstResponder(self)
        }
    }

    override func mouseDown(with event: NSEvent) {
        window?.makeFirstResponder(self)
    }

    override func keyDown(with event: NSEvent) {
        if !EmbeddedInputEventRouter.shared.handle(event, source: "view") {
            super.keyDown(with: event)
        }
    }

    override func keyUp(with event: NSEvent) {
        if !EmbeddedInputEventRouter.shared.handle(event, source: "view") {
            super.keyUp(with: event)
        }
    }

    private func startDisplayLink() {
        guard displayLink == nil else { return }
        let displayLink = CADisplayLink(target: self, selector: #selector(displayLinkDidFire))
        displayLink.preferredFrameRateRange = CAFrameRateRange(minimum: 60, maximum: 60, preferred: 60)
        displayLink.add(to: .main, forMode: .common)
        self.displayLink = displayLink
    }

    private func stopDisplayLink() {
        displayLink?.invalidate()
        displayLink = nil
    }

    @objc private func displayLinkDidFire() {
        drawLatestFrame()
    }

    private func drawLatestFrame() {
        guard !isRendering, let videoStream else {
            return
        }

        let previousFrameIndex = lastFrameIndex
        let scanlinesEnabled = scanlinesEnabled
        isRendering = true
        renderQueue.async { [weak self, videoStream, previousFrameIndex, scanlinesEnabled] in
            guard let frame = videoStream.snapshot(), frame.frameIndex != previousFrameIndex else {
                DispatchQueue.main.async {
                    self?.isRendering = false
                }
                return
            }

            let image = Self.makeImage(from: frame, scanlinesEnabled: scanlinesEnabled)
            DispatchQueue.main.async { [weak self] in
                guard let self else { return }
                self.isRendering = false
                guard frame.frameIndex > self.lastFrameIndex else { return }
                self.lastFrameIndex = frame.frameIndex
                if self.session?.overlayState != frame.overlayState {
                    self.session?.overlayState = frame.overlayState
                }
                CATransaction.begin()
                CATransaction.setDisableActions(true)
                self.imageLayer.contents = image
                CATransaction.commit()
            }
        }
    }

    private func reloadVideoSettings() {
        scanlinesEnabled = (try? FightcadeFBNeoSettingsStore().load().scanlines) ?? false
    }

    nonisolated private static func makeImage(from frame: FightcadeEmbeddedVideoFrame, scanlinesEnabled: Bool) -> CGImage? {
        var rgba = [UInt8](repeating: 0, count: frame.width * frame.height * 4)

        for y in 0..<frame.height {
            let sourceRow = y * frame.pitch
            let targetRow = y * frame.width * 4

            for x in 0..<frame.width {
                let source = sourceRow + x * frame.bytesPerPixel
                let target = targetRow + x * 4
                guard source + frame.bytesPerPixel <= frame.bytes.count else { continue }

                if frame.bytesPerPixel == 2 {
                    let value = UInt16(frame.bytes[source]) | (UInt16(frame.bytes[source + 1]) << 8)
                    rgba[target] = UInt8(((value >> 11) & 0x1F) * 255 / 31)
                    rgba[target + 1] = UInt8(((value >> 5) & 0x3F) * 255 / 63)
                    rgba[target + 2] = UInt8((value & 0x1F) * 255 / 31)
                    rgba[target + 3] = 255
                } else {
                    rgba[target] = frame.bytes[source + 2]
                    rgba[target + 1] = frame.bytes[source + 1]
                    rgba[target + 2] = frame.bytes[source]
                    rgba[target + 3] = 255
                }

                if scanlinesEnabled && y.isMultiple(of: 2) == false {
                    rgba[target] = UInt8((UInt16(rgba[target]) * 11) / 20)
                    rgba[target + 1] = UInt8((UInt16(rgba[target + 1]) * 11) / 20)
                    rgba[target + 2] = UInt8((UInt16(rgba[target + 2]) * 11) / 20)
                }
            }
        }

        guard let provider = CGDataProvider(data: Data(rgba) as CFData) else {
            return nil
        }

        return CGImage(
            width: frame.width,
            height: frame.height,
            bitsPerComponent: 8,
            bitsPerPixel: 32,
            bytesPerRow: frame.width * 4,
            space: CGColorSpaceCreateDeviceRGB(),
            bitmapInfo: CGBitmapInfo(rawValue: CGImageAlphaInfo.last.rawValue),
            provider: provider,
            decode: nil,
            shouldInterpolate: false,
            intent: .defaultIntent
        )
    }
}
