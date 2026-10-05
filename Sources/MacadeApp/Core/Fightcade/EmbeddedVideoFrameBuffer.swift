import Foundation

/// Captures publication bursts independently of vsync without pacing the emulator.
/// Two images bound latency; overflow drops the oldest image to recover promptly.
final class EmbeddedVideoFrameBuffer: @unchecked Sendable {
    private let stream: FightcadeEmbeddedVideoStream
    private let lock = NSLock()
    private let captureLock = NSLock()
    private struct CapturedFrame {
        let frame: FightcadeEmbeddedVideoFrame
        let time: TimeInterval
    }
    private var frames: [CapturedFrame] = []
    private var lastCapturedIndex: UInt64 = 0
    private var dropped = 0
    private var task: Task<Void, Never>?

    init(stream: FightcadeEmbeddedVideoStream, startPolling: Bool = true) {
        self.stream = stream
        if startPolling {
            task = Task.detached(priority: .userInitiated) { [weak self] in
                while !Task.isCancelled {
                    self?.capture()
                    do { try await Task.sleep(for: .milliseconds(1)) }
                    catch { break }
                }
            }
        }
    }

    deinit { task?.cancel() }

    func capture() {
        captureLock.withLock {
            _ = stream.withNextFrame(after: lastCapturedIndex) { frame in
                // Pixel copying must not hold the queue lock needed by the display callback.
                let captured = CapturedFrame(frame: FightcadeEmbeddedVideoFrame(width: frame.width, height: frame.height,
                    pitch: frame.pitch, bytesPerPixel: frame.bytesPerPixel, pixelFormat: frame.pixelFormat,
                    frameIndex: frame.frameIndex, spectatorCount: frame.spectatorCount,
                    overlayState: frame.overlayState, bytes: Data(bytes: frame.baseAddress, count: frame.byteCount)),
                    time: ProcessInfo.processInfo.systemUptime)
                lastCapturedIndex = frame.frameIndex
                lock.withLock {
                    frames.append(captured)
                    if frames.count > 2 { frames.removeFirst(); dropped += 1 }
                }
            }
        }
    }

    func next() -> (frame: FightcadeEmbeddedVideoFrame?, dropped: Int, ageMs: Double) {
        lock.withLock {
            let captured = frames.isEmpty ? nil : frames.removeFirst()
            let ageMs = captured.map { (ProcessInfo.processInfo.systemUptime - $0.time) * 1_000 } ?? 0
            let result = (captured?.frame, dropped, ageMs)
            dropped = 0
            return result
        }
    }
}
