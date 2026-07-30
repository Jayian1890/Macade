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

private final class EmbeddedVideoNSView: MTKView, MTKViewDelegate {
    var session: FightcadeEmbeddedSession? {
        didSet {
            guard oldValue !== session else { return }
            EmbeddedInputEventRouter.shared.unbind(session: oldValue)
            EmbeddedInputEventRouter.shared.bind(session: session)
            videoStream = session?.videoStream
        }
    }

    private var commandQueue: MTLCommandQueue?
    private var pipelineState: MTLRenderPipelineState?
    private var frameTexture: MTLTexture?
    private var frameTextureSize = CGSize.zero
    private var frameTexturePixelFormat: MTLPixelFormat = .invalid
    private var lastFrameIndex: UInt64 = 0
    private var scanlinesEnabled = false
    private var videoStream: FightcadeEmbeddedVideoStream?

    init() {
        let device = MTLCreateSystemDefaultDevice()
        super.init(frame: .zero, device: device)
        configureMetalView(device: device)
    }

    required init(coder: NSCoder) {
        super.init(coder: coder)
        configureMetalView(device: device)
    }

    private func configureMetalView(device: MTLDevice?) {
        colorPixelFormat = .bgra8Unorm
        clearColor = MTLClearColor(red: 0, green: 0, blue: 0, alpha: 1)
        framebufferOnly = true
        presentsWithTransaction = false
        enableSetNeedsDisplay = false
        isPaused = false
        preferredFramesPerSecond = 60
        commandQueue = device?.makeCommandQueue()
        pipelineState = Self.makePipeline(device: device, pixelFormat: colorPixelFormat)
        delegate = self
        reloadVideoSettings()
    }

    override var acceptsFirstResponder: Bool { true }

    override func viewDidMoveToWindow() {
        super.viewDidMoveToWindow()
        if window == nil {
            EmbeddedInputEventRouter.shared.unbind(session: session)
        } else {
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

    func mtkView(_ view: MTKView, drawableSizeWillChange size: CGSize) { }

    func draw(in view: MTKView) {
        guard let videoStream,
              let frame = videoStream.snapshot(),
              frame.frameIndex != lastFrameIndex,
              upload(frame: frame),
              let drawable = currentDrawable,
              let descriptor = currentRenderPassDescriptor,
              let commandBuffer = commandQueue?.makeCommandBuffer(),
              let encoder = commandBuffer.makeRenderCommandEncoder(descriptor: descriptor),
              let pipelineState else { return }

        lastFrameIndex = frame.frameIndex
        if session?.overlayState != frame.overlayState {
            session?.overlayState = frame.overlayState
        }

        var scanlines = scanlinesEnabled ? UInt32(1) : UInt32(0)
        encoder.setViewport(Self.viewport(aspectRatio: session?.videoAspectRatio ?? 4.0 / 3.0, drawableSize: drawableSize))
        encoder.setRenderPipelineState(pipelineState)
        encoder.setFragmentTexture(frameTexture, index: 0)
        encoder.setFragmentBytes(&scanlines, length: MemoryLayout<UInt32>.size, index: 0)
        encoder.drawPrimitives(type: .triangleStrip, vertexStart: 0, vertexCount: 4)
        encoder.endEncoding()
        commandBuffer.present(drawable)
        commandBuffer.commit()
    }

    private func reloadVideoSettings() {
        scanlinesEnabled = (try? FightcadeFBNeoSettingsStore().load().scanlines) ?? false
    }

    private func upload(frame: FightcadeEmbeddedVideoFrame) -> Bool {
        let pixelFormat: MTLPixelFormat
        switch frame.bytesPerPixel {
        case 2:
            pixelFormat = .b5g6r5Unorm
        case 4:
            pixelFormat = .bgra8Unorm
        default:
            return false
        }

        if frameTexture == nil || frameTextureSize.width != CGFloat(frame.width) || frameTextureSize.height != CGFloat(frame.height) || frameTexturePixelFormat != pixelFormat {
            let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: pixelFormat, width: frame.width, height: frame.height, mipmapped: false)
            descriptor.usage = [.shaderRead]
            frameTexture = device?.makeTexture(descriptor: descriptor)
            frameTextureSize = CGSize(width: frame.width, height: frame.height)
            frameTexturePixelFormat = pixelFormat
        }
        guard let frameTexture else { return false }
        frame.bytes.withUnsafeBytes { bytes in
            if let baseAddress = bytes.baseAddress {
                frameTexture.replace(region: MTLRegionMake2D(0, 0, frame.width, frame.height), mipmapLevel: 0, withBytes: baseAddress, bytesPerRow: frame.pitch)
            }
        }
        return true
    }

    private static func viewport(aspectRatio: Double, drawableSize: CGSize) -> MTLViewport {
        let sourceAspect = max(aspectRatio, 0.1)
        let drawableAspect = Double(drawableSize.width) / Double(drawableSize.height)
        let width: Double
        let height: Double
        if drawableAspect > sourceAspect {
            height = Double(drawableSize.height)
            width = height * sourceAspect
        } else {
            width = Double(drawableSize.width)
            height = width / sourceAspect
        }
        return MTLViewport(originX: (Double(drawableSize.width) - width) / 2, originY: (Double(drawableSize.height) - height) / 2, width: width, height: height, znear: 0, zfar: 1)
    }

    private static func makePipeline(device: MTLDevice?, pixelFormat: MTLPixelFormat) -> MTLRenderPipelineState? {
        guard let device else { return nil }
        let source = """
        #include <metal_stdlib>
        using namespace metal;

        struct VertexOut {
            float4 position [[position]];
            float2 texCoord;
        };

        vertex VertexOut vertex_main(uint vertexID [[vertex_id]]) {
            float2 positions[4] = { float2(-1.0, -1.0), float2(1.0, -1.0), float2(-1.0, 1.0), float2(1.0, 1.0) };
            float2 texCoords[4] = { float2(0.0, 1.0), float2(1.0, 1.0), float2(0.0, 0.0), float2(1.0, 0.0) };
            VertexOut out;
            out.position = float4(positions[vertexID], 0.0, 1.0);
            out.texCoord = texCoords[vertexID];
            return out;
        }

        fragment half4 fragment_main(VertexOut in [[stage_in]], texture2d<half> frame [[texture(0)]], constant uint &scanlines [[buffer(0)]]) {
            constexpr sampler frameSampler(address::clamp_to_edge, filter::nearest);
            half4 color = frame.sample(frameSampler, in.texCoord);
            color.a = 1.0h;
            uint row = min(uint(in.texCoord.y * frame.get_height()), frame.get_height() - 1);
            if (scanlines != 0 && (row & 1) != 0) {
                color.rgb *= 0.55h;
            }
            return color;
        }
        """
        guard let library = try? device.makeLibrary(source: source, options: nil),
              let vertex = library.makeFunction(name: "vertex_main"),
              let fragment = library.makeFunction(name: "fragment_main") else { return nil }
        let descriptor = MTLRenderPipelineDescriptor()
        descriptor.vertexFunction = vertex
        descriptor.fragmentFunction = fragment
        descriptor.colorAttachments[0].pixelFormat = pixelFormat
        return try? device.makeRenderPipelineState(descriptor: descriptor)
    }
}
