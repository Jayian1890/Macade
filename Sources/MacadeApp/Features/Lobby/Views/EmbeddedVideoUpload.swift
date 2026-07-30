import Metal

final class EmbeddedVideoUpload {
    static func pixelFormat(for frame: FightcadeEmbeddedVideoFrame) -> MTLPixelFormat? {
        pixelFormat(bytesPerPixel: frame.bytesPerPixel)
    }

    static func pixelFormat(for frame: FightcadeEmbeddedMappedVideoFrame) -> MTLPixelFormat? {
        pixelFormat(bytesPerPixel: frame.bytesPerPixel)
    }

    private static func pixelFormat(bytesPerPixel: Int) -> MTLPixelFormat? {
        switch bytesPerPixel {
        case 2:
            .r16Uint
        case 4:
            .bgra8Unorm
        default:
            nil
        }
    }

    func upload(frame: FightcadeEmbeddedVideoFrame, to texture: MTLTexture) -> Bool {
        frame.bytes.withUnsafeBytes { bytes in
            guard let baseAddress = bytes.baseAddress else { return false }
            return upload(
                width: frame.width,
                height: frame.height,
                pitch: frame.pitch,
                bytesPerPixel: frame.bytesPerPixel,
                byteCount: frame.bytes.count,
                baseAddress: baseAddress,
                to: texture
            )
        }
    }

    func upload(frame: FightcadeEmbeddedMappedVideoFrame, to texture: MTLTexture) -> Bool {
        upload(
            width: frame.width,
            height: frame.height,
            pitch: frame.pitch,
            bytesPerPixel: frame.bytesPerPixel,
            byteCount: frame.byteCount,
            baseAddress: frame.baseAddress,
            to: texture
        )
    }

    private func upload(width: Int, height: Int, pitch: Int, bytesPerPixel: Int, byteCount: Int, baseAddress: UnsafeRawPointer, to texture: MTLTexture) -> Bool {
        guard width > 0,
              height > 0,
              pitch >= width * bytesPerPixel,
              byteCount >= pitch * height else {
            return false
        }

        switch bytesPerPixel {
        case 4, 2:
            texture.replace(
                region: MTLRegionMake2D(0, 0, width, height),
                mipmapLevel: 0,
                withBytes: baseAddress,
                bytesPerRow: pitch
            )
            return true
        default:
            return false
        }
    }

}
