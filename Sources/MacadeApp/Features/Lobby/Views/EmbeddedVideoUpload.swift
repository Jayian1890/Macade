import Metal

final class EmbeddedVideoUpload {
    private var convertedRGB565Bytes = Data()

    static func pixelFormat(for frame: FightcadeEmbeddedVideoFrame) -> MTLPixelFormat? {
        switch frame.bytesPerPixel {
        case 2, 4:
            .bgra8Unorm
        default:
            nil
        }
    }

    func upload(frame: FightcadeEmbeddedVideoFrame, to texture: MTLTexture) -> Bool {
        switch frame.bytesPerPixel {
        case 4:
            return uploadBGRA(frame: frame, to: texture)
        case 2:
            return uploadRGB565(frame: frame, to: texture)
        default:
            return false
        }
    }

    private func uploadBGRA(frame: FightcadeEmbeddedVideoFrame, to texture: MTLTexture) -> Bool {
        guard frame.width > 0,
              frame.height > 0,
              frame.pitch >= frame.width * 4,
              frame.bytes.count >= frame.pitch * frame.height else {
            return false
        }

        frame.bytes.withUnsafeBytes { bytes in
            if let baseAddress = bytes.baseAddress {
                texture.replace(
                    region: MTLRegionMake2D(0, 0, frame.width, frame.height),
                    mipmapLevel: 0,
                    withBytes: baseAddress,
                    bytesPerRow: frame.pitch
                )
            }
        }
        return true
    }

    private func uploadRGB565(frame: FightcadeEmbeddedVideoFrame, to texture: MTLTexture) -> Bool {
        guard frame.width > 0,
              frame.height > 0,
              frame.pitch >= frame.width * 2,
              frame.bytes.count >= frame.pitch * frame.height else {
            return false
        }

        let requiredByteCount = frame.width * frame.height * 4
        if convertedRGB565Bytes.count != requiredByteCount {
            convertedRGB565Bytes = Data(count: requiredByteCount)
        }

        let sourceIsRGB565 = frame.pixelFormat == 1
        convertedRGB565Bytes.withUnsafeMutableBytes { outputBuffer in
            frame.bytes.withUnsafeBytes { inputBuffer in
                guard let source = inputBuffer.bindMemory(to: UInt8.self).baseAddress,
                      let destination = outputBuffer.bindMemory(to: UInt8.self).baseAddress else {
                    return
                }

                for y in 0..<frame.height {
                    let sourceRow = source.advanced(by: y * frame.pitch)
                    let destinationRow = destination.advanced(by: y * frame.width * 4)
                    for x in 0..<frame.width {
                        let value = UInt16(sourceRow[x * 2]) | (UInt16(sourceRow[x * 2 + 1]) << 8)
                        let high = UInt8((value >> 11) & 0x1f)
                        let green = UInt8((value >> 5) & 0x3f)
                        let low = UInt8(value & 0x1f)
                        let red5 = sourceIsRGB565 ? high : low
                        let blue5 = sourceIsRGB565 ? low : high
                        let offset = x * 4
                        destinationRow[offset] = (blue5 << 3) | (blue5 >> 2)
                        destinationRow[offset + 1] = (green << 2) | (green >> 4)
                        destinationRow[offset + 2] = (red5 << 3) | (red5 >> 2)
                        destinationRow[offset + 3] = 255
                    }
                }
            }
        }

        convertedRGB565Bytes.withUnsafeBytes { bytes in
            if let baseAddress = bytes.baseAddress {
                texture.replace(
                    region: MTLRegionMake2D(0, 0, frame.width, frame.height),
                    mipmapLevel: 0,
                    withBytes: baseAddress,
                    bytesPerRow: frame.width * 4
                )
            }
        }
        return true
    }
}
