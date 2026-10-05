import Foundation

/// One writer per emulator session, independent of SwiftUI view lifetimes.
@MainActor
final class EmbeddedVideoDiagnostics {
    let url: URL
    private var handle: FileHandle?
    private var finished = false
    private var intervalStart = ProcessInfo.processInfo.systemUptime
    private var lastDrawTime: TimeInterval?
    private var lastTickTime: TimeInterval?
    private var lastPresentedTime: TimeInterval?
    private var lastFrameIndex: UInt64 = 0
    private var displayDescription = ""
    private var renderedFrames = 0
    private var presentedFrames = 0
    private var duplicateFrames = 0
    private var missingFrames = 0
    private var failedFrames = 0
    private var busyFrames = 0
    private var bufferDrops = 0
    private var maxBufferAgeMs = 0.0
    private var ticks = 0
    private var skippedFrames: UInt64 = 0
    private var maxFrameGap: UInt64 = 0
    private var maxDrawIntervalMs = 0.0
    private var maxTickIntervalMs = 0.0
    private var maxPresentedIntervalMs = 0.0
    private var targetIntervalMs = 0.0
    private var totalSnapshotMs = 0.0
    private var maxSnapshotMs = 0.0
    private var totalUploadMs = 0.0
    private var maxUploadMs = 0.0
    private var totalDrawMs = 0.0
    private var maxDrawMs = 0.0
    private var spikeSamples: [String] = []

    init(sessionID: UUID, mode: String, emulator: String, gameID: String, launchLogURL: URL) {
        // The launcher supplies the log directory. UUIDs prevent same-second collisions.
        let label = mode.lowercased().replacingOccurrences(of: " ", with: "-")
        url = launchLogURL.deletingLastPathComponent()
            .appendingPathComponent("fightcade-embedded-video-\(label)-\(sessionID.uuidString).log")
        let manager = FileManager.default
        do {
            try manager.createDirectory(at: url.deletingLastPathComponent(), withIntermediateDirectories: true)
            if !manager.fileExists(atPath: url.path) { manager.createFile(atPath: url.path, contents: nil) }
            handle = try FileHandle(forWritingTo: url)
            try handle?.seekToEnd()
            // Only the link is replaced. Never truncate an earlier session's file.
            let latest = url.deletingLastPathComponent().appendingPathComponent("fightcade-embedded-video-latest.log")
            if let attributes = try? manager.attributesOfItem(atPath: latest.path),
               attributes[.type] as? FileAttributeType != .typeSymbolicLink {
                let legacy = url.deletingLastPathComponent()
                    .appendingPathComponent("fightcade-embedded-video-legacy-\(UUID().uuidString).log")
                try manager.moveItem(at: latest, to: legacy)
            } else {
                try? manager.removeItem(at: latest)
            }
            try? manager.createSymbolicLink(at: latest, withDestinationURL: url)
        } catch {
            NSLog("Embedded video diagnostics could not open %@: %@", url.path, error.localizedDescription)
        }
        append("session id=\(sessionID.uuidString) mode=\(mode) emulator=\(emulator) game=\(gameID) launchLog=\(launchLogURL.path)")
        append("metrics: submittedFPS counts new frames committed, presentedFPS counts new drawable presentation callbacks; duplicate means no new publication at a display tick; skipped counts publication indices never submitted (not emulated/GGPO frames)")
    }

    isolated deinit {
        finish(reason: "released")
    }

    func consumerAttached() {
        flushSummary(force: true)
        resetCadence()
        append("consumer attached")
    }

    func consumerDetached() {
        flushSummary(force: true)
        resetCadence()
        append("consumer detached")
    }

    func recordDisplay(name: String, rate: Int) {
        let description = "display=\(name) requestedHz=\(rate) clock=NSView.CADisplayLink vsync=on consumer=\(rate <= 60 ? "buffered-2" : "latest")"
        guard description != displayDescription else { return }
        flushSummary(force: true)
        resetCadence()
        displayDescription = description
        append(description)
    }

    func recordTick(timestamp: Double, targetTimestamp: Double) {
        ticks += 1
        if let lastTickTime { maxTickIntervalMs = max(maxTickIntervalMs, (timestamp - lastTickTime) * 1_000) }
        lastTickTime = timestamp
        targetIntervalMs = max(0, targetTimestamp - timestamp) * 1_000
        flushSummary()
    }

    func recordPresented(frameIndex: UInt64, time: Double, isNewFrame: Bool) {
        guard !finished, isNewFrame, time > 0 else { return }
        presentedFrames += 1
        if let lastPresentedTime, time > lastPresentedTime {
            maxPresentedIntervalMs = max(maxPresentedIntervalMs, (time - lastPresentedTime) * 1_000)
        }
        lastPresentedTime = max(lastPresentedTime ?? 0, time)
    }

    func recordBufferRead(dropped: Int, ageMs: Double) {
        bufferDrops += dropped
        maxBufferAgeMs = max(maxBufferAgeMs, ageMs)
    }

    func recordBusy() { busyFrames += 1; flushSummary() }
    func recordDuplicateFrame() { duplicateFrames += 1; flushSummary() }

    func recordMissingFrame(reason: String) {
        missingFrames += 1
        if missingFrames <= 3 { append("missing reason=\(reason)") }
        flushSummary()
    }

    func recordFailure(reason: String) {
        failedFrames += 1
        if failedFrames <= 3 { append("failure reason=\(reason)") }
        flushSummary()
    }

    func recordFrame(frameIndex: UInt64, snapshotMs: Double, uploadMs: Double, drawMs: Double) {
        let now = Self.now
        let drawIntervalMs = lastDrawTime.map { (now - $0) * 1_000 } ?? 0
        let frameGap = lastFrameIndex == 0 || frameIndex <= lastFrameIndex ? 0 : frameIndex - lastFrameIndex
        lastDrawTime = now
        lastFrameIndex = frameIndex
        renderedFrames += 1
        skippedFrames += frameGap > 1 ? frameGap - 1 : 0
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
        flushSummary()
    }

    func finish(reason: String) {
        guard !finished else { return }
        flushSummary(force: true)
        append("session ended reason=\(reason)")
        finished = true
        try? handle?.close()
        handle = nil
    }

    private func flushSummary(force: Bool = false) {
        guard !finished, force || Self.now - intervalStart >= 2 else { return }
        let elapsed = max(Self.now - intervalStart, 0.001)
        let count = Double(max(renderedFrames, 1))
        let samples = spikeSamples.isEmpty ? "none" : spikeSamples.joined(separator: " | ")
        if ticks + renderedFrames + presentedFrames + missingFrames + failedFrames > 0 {
            append("summary seconds=\(format(elapsed)) callbackHz=\(format(Double(ticks) / elapsed)) targetIntervalMs=\(format(targetIntervalMs)) submittedFPS=\(format(Double(renderedFrames) / elapsed)) presentedFPS=\(format(Double(presentedFrames) / elapsed)) submitted=\(renderedFrames) presented=\(presentedFrames) duplicate=\(duplicateFrames) missing=\(missingFrames) failed=\(failedFrames) gpuBusy=\(busyFrames) bufferDrops=\(bufferDrops) maxBufferAgeMs=\(format(maxBufferAgeMs)) skipped=\(skippedFrames) maxGap=\(maxFrameGap) avgSnapshotMs=\(format(totalSnapshotMs / count)) maxSnapshotMs=\(format(maxSnapshotMs)) avgUploadMs=\(format(totalUploadMs / count)) maxUploadMs=\(format(maxUploadMs)) avgDrawMs=\(format(totalDrawMs / count)) maxDrawMs=\(format(maxDrawMs)) maxSubmitIntervalMs=\(format(maxDrawIntervalMs)) maxTickIntervalMs=\(format(maxTickIntervalMs)) maxPresentedIntervalMs=\(format(maxPresentedIntervalMs)) samples=\(samples)")
        }
        intervalStart = Self.now
        renderedFrames = 0
        presentedFrames = 0
        duplicateFrames = 0
        missingFrames = 0
        failedFrames = 0
        busyFrames = 0
        bufferDrops = 0
        maxBufferAgeMs = 0
        ticks = 0
        skippedFrames = 0
        maxFrameGap = 0
        maxDrawIntervalMs = 0
        maxTickIntervalMs = 0
        maxPresentedIntervalMs = 0
        totalSnapshotMs = 0
        maxSnapshotMs = 0
        totalUploadMs = 0
        maxUploadMs = 0
        totalDrawMs = 0
        maxDrawMs = 0
        spikeSamples = []
    }

    private func resetCadence() {
        lastDrawTime = nil
        lastTickTime = nil
        lastPresentedTime = nil
        lastFrameIndex = 0
    }

    private func append(_ message: String) {
        guard !finished, let data = "\(Date()) \(message)\n".data(using: .utf8) else { return }
        try? handle?.write(contentsOf: data)
    }

    private func format(_ value: Double) -> String { String(format: "%.2f", value) }
    static var now: TimeInterval { ProcessInfo.processInfo.systemUptime }
}
