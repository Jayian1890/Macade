import AppKit
import MetalKit

final class EmbeddedVideoNSView: MTKView, MTKViewDelegate {
    var session: FightcadeEmbeddedSession? {
        didSet {
            guard oldValue !== session else { return }
            EmbeddedInputEventRouter.shared.unbind(session: oldValue)
            EmbeddedInputEventRouter.shared.bind(session: session)
            videoStream = session?.videoStream
            diagnostics.sessionDidChange(session)
        }
    }

    private var commandQueue: MTLCommandQueue?
    private var bgraPipelineState: MTLRenderPipelineState?
    private var rgb565PipelineState: MTLRenderPipelineState?
    private var frameTexture: MTLTexture?
    private var frameTextureSize = CGSize.zero
    private var frameTexturePixelFormat: MTLPixelFormat = .invalid
    private var lastFrameIndex: UInt64 = 0
    private var scanlinesEnabled = false
    private let videoUpload = EmbeddedVideoUpload()
    private let diagnostics = EmbeddedVideoDiagnostics()
    private var videoStream: FightcadeEmbeddedVideoStream?
    private var settingsObserver: NSObjectProtocol?

    private struct PreparedFrame {
        let width: Int
        let height: Int
        let bytesPerPixel: Int
        let pixelFormat: UInt32
        let frameIndex: UInt64
        let overlayState: FightcadeEmbeddedOverlayState?
        let snapshotMs: Double
        let uploadMs: Double
    }

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
        bgraPipelineState = Self.makePipeline(device: device, pixelFormat: colorPixelFormat, fragmentName: "fragment_bgra")
        rgb565PipelineState = Self.makePipeline(device: device, pixelFormat: colorPixelFormat, fragmentName: "fragment_rgb565")
        delegate = self
        reloadVideoSettings()
        settingsObserver = NotificationCenter.default.addObserver(forName: .fightcadeFBNeoSettingsDidChange, object: nil, queue: .main) { [weak self] _ in
            Task { @MainActor in self?.reloadVideoSettings() }
        }
    }

    isolated deinit {
        if let settingsObserver {
            NotificationCenter.default.removeObserver(settingsObserver)
        }
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
        let drawStart = EmbeddedVideoDiagnostics.now
        guard let videoStream else { diagnostics.recordMissingFrame(reason: "no-stream"); return }
        let snapshotStart = EmbeddedVideoDiagnostics.now
        let read = videoStream.withNextFrame(after: lastFrameIndex) { frame -> PreparedFrame? in
            let snapshotMs = (EmbeddedVideoDiagnostics.now - snapshotStart) * 1_000
            let uploadStart = EmbeddedVideoDiagnostics.now
            guard upload(frame: frame) else { return nil }
            return PreparedFrame(
                width: frame.width,
                height: frame.height,
                bytesPerPixel: frame.bytesPerPixel,
                pixelFormat: frame.pixelFormat,
                frameIndex: frame.frameIndex,
                overlayState: frame.overlayState,
                snapshotMs: snapshotMs,
                uploadMs: (EmbeddedVideoDiagnostics.now - uploadStart) * 1_000
            )
        }

        let frame: PreparedFrame
        switch read {
        case .missing:
            diagnostics.recordMissingFrame(reason: "no-snapshot")
            return
        case .duplicate:
            diagnostics.recordDuplicateFrame()
            return
        case .frame(let preparedFrame):
            guard let preparedFrame else { diagnostics.recordFailure(reason: "upload"); return }
            frame = preparedFrame
        }

        guard let drawable = currentDrawable,
              let descriptor = currentRenderPassDescriptor,
              let commandBuffer = commandQueue?.makeCommandBuffer(),
              let encoder = commandBuffer.makeRenderCommandEncoder(descriptor: descriptor),
              let pipelineState = pipelineState(for: frame) else { diagnostics.recordFailure(reason: "metal"); return }

        lastFrameIndex = frame.frameIndex
        if session?.overlayState != frame.overlayState {
            session?.overlayState = frame.overlayState
        }

        var scanlines = scanlinesEnabled ? UInt32(1) : UInt32(0)
        encoder.setViewport(Self.viewport(aspectRatio: session?.videoAspectRatio ?? 4.0 / 3.0, drawableSize: drawableSize))
        encoder.setRenderPipelineState(pipelineState)
        encoder.setFragmentTexture(frameTexture, index: 0)
        encoder.setFragmentBytes(&scanlines, length: MemoryLayout<UInt32>.size, index: 0)
        if frame.bytesPerPixel == 2 {
            var sourceIsRGB565 = frame.pixelFormat == 1 ? UInt32(1) : UInt32(0)
            encoder.setFragmentBytes(&sourceIsRGB565, length: MemoryLayout<UInt32>.size, index: 1)
        }
        encoder.drawPrimitives(type: .triangleStrip, vertexStart: 0, vertexCount: 4)
        encoder.endEncoding()
        commandBuffer.present(drawable)
        commandBuffer.commit()
        diagnostics.recordFrame(
            frameIndex: frame.frameIndex,
            snapshotMs: frame.snapshotMs,
            uploadMs: frame.uploadMs,
            drawMs: (EmbeddedVideoDiagnostics.now - drawStart) * 1_000
        )
    }

    private func reloadVideoSettings() {
        scanlinesEnabled = (try? FightcadeFBNeoSettingsStore().load().scanlines) ?? false
    }

    private func upload(frame: FightcadeEmbeddedVideoFrame) -> Bool {
        guard let pixelFormat = EmbeddedVideoUpload.pixelFormat(for: frame) else { return false }

        if frameTexture == nil || frameTextureSize.width != CGFloat(frame.width) || frameTextureSize.height != CGFloat(frame.height) || frameTexturePixelFormat != pixelFormat {
            let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: pixelFormat, width: frame.width, height: frame.height, mipmapped: false)
            descriptor.usage = [.shaderRead]
            frameTexture = device?.makeTexture(descriptor: descriptor)
            frameTextureSize = CGSize(width: frame.width, height: frame.height)
            frameTexturePixelFormat = pixelFormat
        }
        guard let frameTexture else { return false }
        return videoUpload.upload(frame: frame, to: frameTexture)
    }

    private func upload(frame: FightcadeEmbeddedMappedVideoFrame) -> Bool {
        guard let pixelFormat = EmbeddedVideoUpload.pixelFormat(for: frame) else { return false }

        if frameTexture == nil || frameTextureSize.width != CGFloat(frame.width) || frameTextureSize.height != CGFloat(frame.height) || frameTexturePixelFormat != pixelFormat {
            let descriptor = MTLTextureDescriptor.texture2DDescriptor(pixelFormat: pixelFormat, width: frame.width, height: frame.height, mipmapped: false)
            descriptor.usage = [.shaderRead]
            frameTexture = device?.makeTexture(descriptor: descriptor)
            frameTextureSize = CGSize(width: frame.width, height: frame.height)
            frameTexturePixelFormat = pixelFormat
        }
        guard let frameTexture else { return false }
        return videoUpload.upload(frame: frame, to: frameTexture)
    }

    private func pipelineState(for frame: PreparedFrame) -> MTLRenderPipelineState? {
        frame.bytesPerPixel == 2 ? rgb565PipelineState : bgraPipelineState
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

    private static func makePipeline(device: MTLDevice?, pixelFormat: MTLPixelFormat, fragmentName: String) -> MTLRenderPipelineState? {
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

        fragment half4 fragment_bgra(VertexOut in [[stage_in]], texture2d<half> frame [[texture(0)]], constant uint &scanlines [[buffer(0)]]) {
            constexpr sampler frameSampler(address::clamp_to_edge, filter::nearest);
            half4 color = frame.sample(frameSampler, in.texCoord);
            color.a = 1.0h;
            uint row = min(uint(in.texCoord.y * frame.get_height()), frame.get_height() - 1);
            if (scanlines != 0 && (row & 1) != 0) {
                color.rgb *= 0.55h;
            }
            return color;
        }

        fragment half4 fragment_rgb565(VertexOut in [[stage_in]], texture2d<ushort, access::read> frame [[texture(0)]], constant uint &scanlines [[buffer(0)]], constant uint &sourceIsRGB565 [[buffer(1)]]) {
            uint width = frame.get_width();
            uint height = frame.get_height();
            uint2 coord = uint2(min(uint(in.texCoord.x * float(width)), width - 1), min(uint(in.texCoord.y * float(height)), height - 1));
            uint value = uint(frame.read(coord).r);
            half high = half((value >> 11) & 0x1f) / 31.0h;
            half green = half((value >> 5) & 0x3f) / 63.0h;
            half low = half(value & 0x1f) / 31.0h;
            half red = sourceIsRGB565 != 0 ? high : low;
            half blue = sourceIsRGB565 != 0 ? low : high;
            half4 color = half4(red, green, blue, 1.0h);
            if (scanlines != 0 && (coord.y & 1) != 0) {
                color.rgb *= 0.55h;
            }
            return color;
        }
        """
        guard let library = try? device.makeLibrary(source: source, options: nil),
              let vertex = library.makeFunction(name: "vertex_main"),
              let fragment = library.makeFunction(name: fragmentName) else { return nil }
        let descriptor = MTLRenderPipelineDescriptor()
        descriptor.vertexFunction = vertex
        descriptor.fragmentFunction = fragment
        descriptor.colorAttachments[0].pixelFormat = pixelFormat
        return try? device.makeRenderPipelineState(descriptor: descriptor)
    }
}
