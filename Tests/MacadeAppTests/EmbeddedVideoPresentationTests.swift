import AppKit
import MetalKit
import XCTest
@testable import Macade

@MainActor
final class EmbeddedVideoPresentationTests: XCTestCase {
    func testDisplayPoliciesCover60AndHighRefreshRates() {
        XCTAssertTrue(EmbeddedVideoDisplayPolicy(refreshRate: 60).usesBurstBuffer)
        XCTAssertFalse(EmbeddedVideoDisplayPolicy(refreshRate: 120).usesBurstBuffer)
        XCTAssertFalse(EmbeddedVideoDisplayPolicy(refreshRate: 144).usesBurstBuffer)
        XCTAssertEqual(EmbeddedVideoDisplayPolicy(refreshRate: 120).frameIntervalMilliseconds, 8.3333333333, accuracy: 0.0001)
        XCTAssertEqual(EmbeddedVideoDisplayPolicy(refreshRate: 144).frameIntervalMilliseconds, 6.9444444444, accuracy: 0.0001)
    }

    func testSessionLogsSurviveConsumerRecreationAndLatestLinkReplacement() throws {
        let directory = try makeDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        let local = try makeSession(directory: directory, mode: .singlePlayer)
        let log = local.videoDiagnostics
        log.consumerAttached()
        log.recordFrame(frameIndex: 1, snapshotMs: 0, uploadMs: 0, drawMs: 0)
        log.consumerDetached()
        let first = try String(contentsOf: log.url, encoding: .utf8)
        log.consumerAttached()
        log.recordFrame(frameIndex: 90, snapshotMs: 0, uploadMs: 0, drawMs: 0)
        log.consumerDetached()
        let recreated = try String(contentsOf: log.url, encoding: .utf8)
        XCTAssertTrue(recreated.hasPrefix(first))
        XCTAssertFalse(recreated.contains("gap=89"), "Reattaching must not count hidden time as dropped frames")
        let online = try makeSession(directory: directory, mode: .match)
        XCTAssertNotEqual(log.url, online.videoDiagnostics.url)
        XCTAssertEqual(try String(contentsOf: log.url, encoding: .utf8), recreated)
        let latest = directory.appendingPathComponent("fightcade-embedded-video-latest.log")
        XCTAssertEqual(latest.resolvingSymlinksInPath(), online.videoDiagnostics.url)
        local.markTerminated(status: 0)
        online.markTerminated(status: 0)
        XCTAssertTrue(try String(contentsOf: log.url, encoding: .utf8).contains("session ended"))
    }

    func testSameModeSessionsAndLegacyLatestFileAreNotTruncated() throws {
        let directory = try makeDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        let latest = directory.appendingPathComponent("fightcade-embedded-video-latest.log")
        try "legacy evidence".write(to: latest, atomically: true, encoding: .utf8)
        let first = try makeSession(directory: directory, mode: .singlePlayer)
        let second = try makeSession(directory: directory, mode: .singlePlayer)
        XCTAssertNotEqual(first.videoDiagnostics.url, second.videoDiagnostics.url)
        XCTAssertTrue(try String(contentsOf: first.videoDiagnostics.url, encoding: .utf8).contains(first.id.uuidString))
        let legacy = try XCTUnwrap(FileManager.default.contentsOfDirectory(at: directory,
            includingPropertiesForKeys: nil).first { $0.lastPathComponent.contains("-legacy-") })
        XCTAssertEqual(try String(contentsOf: legacy, encoding: .utf8), "legacy evidence")
        first.stop()
        second.stop()
    }

    func testSummarySeparatesSubmissionsPresentationsDuplicatesAndPublicationGaps() throws {
        let directory = try makeDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        let session = try makeSession(directory: directory, mode: .match)
        let log = session.videoDiagnostics
        log.recordTick(timestamp: 1, targetTimestamp: 1 + 1.0 / 144)
        log.recordFrame(frameIndex: 100, snapshotMs: 0.1, uploadMs: 0.2, drawMs: 0.3)
        log.recordDuplicateFrame()
        log.recordFrame(frameIndex: 103, snapshotMs: 0.1, uploadMs: 0.2, drawMs: 0.3)
        log.recordPresented(frameIndex: 100, time: 1, isNewFrame: true)
        log.recordPresented(frameIndex: 103, time: 1.02, isNewFrame: true)
        log.recordPresented(frameIndex: 103, time: 1.03, isNewFrame: false)
        session.stop()
        let text = try String(contentsOf: log.url, encoding: .utf8)
        XCTAssertTrue(text.contains("submitted=2 presented=2 duplicate=1"))
        XCTAssertTrue(text.contains("skipped=2 maxGap=3"))
        XCTAssertTrue(text.contains("targetIntervalMs=6.94"))
        XCTAssertTrue(text.contains("maxPresentedIntervalMs=20.00"))
        log.recordPresented(frameIndex: 104, time: 1.04, isNewFrame: true)
        log.finish(reason: "again")
        XCTAssertEqual(try String(contentsOf: log.url, encoding: .utf8), text)
    }

    func testRealMetalConsumerSwitchesSessionsWithSameFrameIndexAndReleasesDisplayLink() async throws {
        guard MTLCreateSystemDefaultDevice() != nil, NSScreen.main != nil else {
            throw XCTSkip("Requires a Metal device and attached display")
        }
        let directory = try makeDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        let local = try makeSession(directory: directory, mode: .singlePlayer)
        let online = try makeSession(directory: directory, mode: .match)
        defer { local.stop(); online.stop() }
        try publishFrame(in: local.videoStream, index: 1)
        try publishFrame(in: online.videoStream, index: 1)
        let window = NSWindow(contentRect: NSRect(x: 100, y: 100, width: 320, height: 240),
                              styleMask: [.titled], backing: .buffered, defer: false)
        window.isReleasedWhenClosed = false
        defer { window.close() }
        var view: EmbeddedVideoNSView? = EmbeddedVideoNSView()
        weak let weakView = view
        window.contentView = view
        view?.session = local
        window.orderFront(nil)
        try await Task.sleep(for: .milliseconds(500))
        view?.session = online
        try await Task.sleep(for: .milliseconds(500))
        view?.session = nil
        let localLog = try String(contentsOf: local.videoDiagnostics.url, encoding: .utf8)
        let onlineLog = try String(contentsOf: online.videoDiagnostics.url, encoding: .utf8)
        XCTAssertTrue(localLog.contains(local.id.uuidString))
        XCTAssertTrue(onlineLog.contains(online.id.uuidString))
        window.makeFirstResponder(nil)
        window.orderOut(nil)
        window.contentView = nil
        view = nil
        for _ in 0..<20 where weakView != nil {
            try await Task.sleep(for: .milliseconds(50))
        }
        XCTAssertNil(weakView, "The display link must not retain its view")
    }

    func testBurstBufferPreservesOrderOwnsPixelsAndBoundsBacklog() throws {
        let directory = try makeDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        let session = try makeSession(directory: directory, mode: .singlePlayer)
        defer { session.stop() }
        let buffer = EmbeddedVideoFrameBuffer(stream: session.videoStream, startPolling: false)
        try publishFrame(in: session.videoStream, index: 1, pixel: 1)
        buffer.capture()
        buffer.capture() // Re-reading a publication must not enqueue a duplicate.
        try publishFrame(in: session.videoStream, index: 2, pixel: 2)
        buffer.capture()
        let first = try XCTUnwrap(buffer.next().frame)
        XCTAssertEqual(first.frameIndex, 1)
        XCTAssertEqual(first.bytes, Data(repeating: 1, count: 16))
        for index: UInt64 in [3, 4] {
            try publishFrame(in: session.videoStream, index: index)
            buffer.capture()
        }
        let next = buffer.next()
        XCTAssertEqual(next.frame?.frameIndex, 3)
        XCTAssertEqual(next.dropped, 1)
        XCTAssertEqual(buffer.next().frame?.frameIndex, 4)
        XCTAssertNil(buffer.next().frame)
        session.videoStream.close()
        buffer.capture()
        XCTAssertNil(buffer.next().frame)
    }

    private func makeDirectory() throws -> URL {
        let url = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: url, withIntermediateDirectories: true)
        return url
    }

    private func makeSession(directory: URL, mode: FightcadeEmbeddedSession.Mode) throws -> FightcadeEmbeddedSession {
        let id = UUID()
        let video = try FightcadeEmbeddedVideoStream(fileURL: directory.appendingPathComponent("\(id).video"), byteCount: 8192)
        return try FightcadeEmbeddedSession(id: id, channelID: "sfiii3nr1", mode: mode,
            emulator: "fbneo", gameID: "sfiii3nr1", title: mode.rawValue,
            logURL: directory.appendingPathComponent("\(id).log"), videoStream: video,
            inputClient: FightcadeEmbeddedInputClient(socketPath: "/tmp/macade-video-test-\(id).sock"))
    }

    /// Test fixture using the existing shared-memory ABI; no emulator or timing substitution.
    private func publishFrame(in stream: FightcadeEmbeddedVideoStream, index: UInt64, pixel: UInt8 = 255) throws {
        let handle = try FileHandle(forWritingTo: stream.fileURL)
        defer { try? handle.close() }
        for (offset, value) in [(16, 2), (20, 2), (24, 8), (28, 4), (40, 0)] {
            var word = UInt32(value)
            try handle.seek(toOffset: UInt64(offset))
            try withUnsafeBytes(of: &word) { try handle.write(contentsOf: Data($0)) }
        }
        try handle.seek(toOffset: 4096)
        try handle.write(contentsOf: Data(repeating: pixel, count: 16))
        var frame = index
        try handle.seek(toOffset: 48)
        try withUnsafeBytes(of: &frame) { try handle.write(contentsOf: Data($0)) }
    }
}
