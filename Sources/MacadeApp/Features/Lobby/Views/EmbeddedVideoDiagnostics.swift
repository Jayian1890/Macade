import Foundation

@MainActor
final class EmbeddedVideoDiagnostics {
    private let fileManager: FileManager
    private var handle: FileHandle?
    private var currentSessionID: UUID?
    private var intervalStart = ProcessInfo.processInfo.systemUptime
    private var lastDrawTime: TimeInterval?
    private var lastFrameIndex: UInt64 = 0
    private var renderedFrames = 0
    private var duplicateFrames = 0
    private var missingFrames = 0
    private var failedFrames = 0
    private var maxFrameGap: UInt64 = 0
    private var maxDrawIntervalMs = 0.0
    private var totalSnapshotMs = 0.0
    private var maxSnapshotMs = 0.0
    private var totalUploadMs = 0.0
    private var maxUploadMs = 0.0
    private var totalDrawMs = 0.0
    private var maxDrawMs = 0.0
    private var spikeSamples: [String] = []

    init(fileManager: FileManager = .default) {
        self.fileManager = fileManager
        openLog()
    }

    isolated deinit {
        try? handle?.close()
    }

    func sessionDidChange(_ session: FightcadeEmbeddedSession?) {
        guard currentSessionID != session?.id else { return }
        currentSessionID = session?.id
        resetInterval()
        lastDrawTime = nil
        lastFrameIndex = 0
        guard let session else {
            append("session cleared")
            return
        }
        append("session id=\(session.id.uuidString) mode=\(session.mode.rawValue) game=\(session.gameID) title=\(session.title)")
    }

    func recordDuplicateFrame() {
        duplicateFrames += 1
        flushSummaryIfNeeded()
    }

    func recordMissingFrame(reason: String) {
        missingFrames += 1
        if missingFrames <= 3 {
            append("missing reason=\(reason)")
        }
        flushSummaryIfNeeded()
    }

    func recordFailure(reason: String) {
        failedFrames += 1
        append("failure reason=\(reason)")
        flushSummaryIfNeeded()
    }

    func recordFrame(frameIndex: UInt64, snapshotMs: Double, uploadMs: Double, drawMs: Double) {
        let now = Self.now
        let drawIntervalMs = lastDrawTime.map { (now - $0) * 1_000 } ?? 0
        let frameGap = lastFrameIndex == 0 || frameIndex <= lastFrameIndex ? 0 : frameIndex - lastFrameIndex
        lastDrawTime = now
        lastFrameIndex = frameIndex
        renderedFrames += 1
        totalSnapshotMs += snapshotMs
        totalUploadMs += uploadMs
        totalDrawMs += drawMs
        maxSnapshotMs = max(maxSnapshotMs, snapshotMs)
        maxUploadMs = max(maxUploadMs, uploadMs)
        maxDrawMs = max(maxDrawMs, drawMs)
        maxDrawIntervalMs = max(maxDrawIntervalMs, drawIntervalMs)
        maxFrameGap = max(maxFrameGap, frameGap)

        if spikeSamples.count < 3, drawIntervalMs > 25 || snapshotMs > 4 || uploadMs > 4 || drawMs > 8 || frameGap > 1 {
            spikeSamples.append("frame=\(frameIndex) gap=\(frameGap) intervalMs=\(format(drawIntervalMs)) snapshotMs=\(format(snapshotMs)) uploadMs=\(format(uploadMs)) drawMs=\(format(drawMs))")
        }

        flushSummaryIfNeeded()
    }

    private func flushSummaryIfNeeded() {
        guard Self.now - intervalStart >= 2 else { return }
        let elapsed = max(Self.now - intervalStart, 0.001)
        let avgSnapshot = renderedFrames > 0 ? totalSnapshotMs / Double(renderedFrames) : 0
        let avgUpload = renderedFrames > 0 ? totalUploadMs / Double(renderedFrames) : 0
        let avgDraw = renderedFrames > 0 ? totalDrawMs / Double(renderedFrames) : 0
        let samples = spikeSamples.isEmpty ? "none" : spikeSamples.joined(separator: " | ")
        append("summary fps=\(format(Double(renderedFrames) / elapsed)) rendered=\(renderedFrames) duplicate=\(duplicateFrames) missing=\(missingFrames) failed=\(failedFrames) maxGap=\(maxFrameGap) avgSnapshotMs=\(format(avgSnapshot)) maxSnapshotMs=\(format(maxSnapshotMs)) avgUploadMs=\(format(avgUpload)) maxUploadMs=\(format(maxUploadMs)) avgDrawMs=\(format(avgDraw)) maxDrawMs=\(format(maxDrawMs)) maxIntervalMs=\(format(maxDrawIntervalMs)) samples=\(samples)")
        resetInterval()
    }

    private func resetInterval() {
        intervalStart = Self.now
        renderedFrames = 0
        duplicateFrames = 0
        missingFrames = 0
        failedFrames = 0
        maxFrameGap = 0
        maxDrawIntervalMs = 0
        totalSnapshotMs = 0
        maxSnapshotMs = 0
        totalUploadMs = 0
        maxUploadMs = 0
        totalDrawMs = 0
        maxDrawMs = 0
        spikeSamples = []
    }

    private func openLog() {
        guard let logsURL = fileManager.urls(for: .libraryDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Logs")
            .appendingPathComponent("Macade") else { return }
        try? fileManager.createDirectory(at: logsURL, withIntermediateDirectories: true)
        let url = logsURL.appendingPathComponent("fightcade-embedded-video-latest.log")
        fileManager.createFile(atPath: url.path, contents: nil)
        handle = try? FileHandle(forWritingTo: url)
        append("log: \(url.path)")
    }

    private func append(_ message: String) {
        guard let data = "\(Date()) \(message)\n".data(using: .utf8) else { return }
        try? handle?.write(contentsOf: data)
    }

    private func format(_ value: Double) -> String {
        String(format: "%.2f", value)
    }

    static var now: TimeInterval {
        ProcessInfo.processInfo.systemUptime
    }
}
