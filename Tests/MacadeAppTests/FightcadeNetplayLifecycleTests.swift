import XCTest
@testable import Macade

final class FightcadeNetplayLifecycleTests: XCTestCase {
    func testNativeUsePortsPreparationDoesNotSetProxyEnvironment() {
        let preparation = FightcadeEmbeddedNetplayPreparation.nativeUsePorts(.udpPunchFailed)

        XCTAssertTrue(preparation.environment.isEmpty)
    }

    @MainActor
    func testLauncherCompletesNetplayPreparationBeforeStartingProcess() async throws {
        let supportURL = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: supportURL) }
        let runtime = FightcadeRuntime(applicationSupportURL: supportURL)
        try Data([0x01]).write(to: runtime.romURL(emulator: "fbneo", gameID: "sfiii3n"))
        let preparer = FailingNetplayPreparer()
        let registry = FightcadeProcessRegistry()
        let launcher = FightcadeLauncher(
            runtime: runtime,
            processRegistry: registry,
            netplayPreparer: preparer
        )
        let launch = FightcadeEmbeddedLaunch.match(
            channelID: "sfiii3n",
            match: FightcadeMatchLaunch(
                emulator: "fbneo",
                gameID: "sfiii3n",
                quarkID: "1234567890-42",
                playerID: 0,
                port: 7000,
                delay: 2,
                ranked: 0,
                token: nil
            )
        )

        do {
            _ = try await launcher.openEmbedded(launch)
            XCTFail("Expected netplay preparation failure")
        } catch let error as NetplayPreparationTestError {
            XCTAssertEqual(error, .expected)
        }

        let callCount = await preparer.callCount()
        XCTAssertEqual(callCount, 1)
        XCTAssertTrue(registry.processIDs().isEmpty)
    }

    func testProxyReportsPermanentTransportFailureAndClosesOnce() async {
        let local = FailingProxyTransport(error: POSIXError(.ECONNRESET))
        let peer = FailingProxyTransport(error: POSIXError(.ETIMEDOUT))
        let proxy = FightcadeUDPProxy(
            peerTransport: peer,
            localTransport: local,
            configuration: FightcadeUDPProxyConfiguration(
                peer: FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006),
                localEmulatorPort: 7001
            )
        )

        let result = await proxy.run()

        guard case .transportFailure(let message) = result else {
            return XCTFail("Expected transport failure")
        }
        XCTAssertFalse(message.isEmpty)
        XCTAssertEqual(local.closeCount, 1)
        XCTAssertEqual(peer.closeCount, 1)
        proxy.close()
        XCTAssertEqual(local.closeCount, 1)
        XCTAssertEqual(peer.closeCount, 1)
    }

    @MainActor
    func testEmbeddedSessionPreservesProxyFailureAfterProcessExit() throws {
        let directory = temporaryDirectory()
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: directory) }
        let video = try FightcadeEmbeddedVideoStream(fileURL: directory.appendingPathComponent("video.mcade"))
        let input = try FightcadeEmbeddedInputClient(socketPath: directory.appendingPathComponent("input.sock").path)
        let session = FightcadeEmbeddedSession(
            id: UUID(),
            channelID: "sfiii3n",
            mode: .match,
            emulator: "fbneo",
            gameID: "sfiii3n",
            title: "Match",
            logURL: directory.appendingPathComponent("launch.log"),
            videoStream: video,
            inputClient: input
        )
        let process = Process()
        process.executableURL = URL(fileURLWithPath: "/bin/sleep")
        process.arguments = ["30"]
        try process.run()
        session.attach(process: process)

        session.failAndTerminate("Peer connection failed")
        process.waitUntilExit()
        session.markTerminated(status: process.terminationStatus)

        XCTAssertEqual(session.status, .failed("Peer connection failed"))
        XCTAssertFalse(session.isActive)
    }

    private func temporaryDirectory() -> URL {
        FileManager.default.temporaryDirectory
            .appendingPathComponent("MacadeTests")
            .appendingPathComponent(UUID().uuidString)
    }
}

private enum NetplayPreparationTestError: Error, Equatable {
    case expected
}

private actor FailingNetplayPreparer: FightcadeEmbeddedNetplayPreparing {
    private var calls = 0

    func prepare(for match: FightcadeMatchLaunch) async throws -> FightcadeEmbeddedNetplayPreparation {
        calls += 1
        throw NetplayPreparationTestError.expected
    }

    func callCount() -> Int {
        calls
    }
}

private final class FailingProxyTransport: FightcadeUDPTransporting, @unchecked Sendable {
    private let error: Error
    private let lock = NSLock()
    private var closes = 0

    init(error: Error) {
        self.error = error
    }

    var closeCount: Int {
        lock.withLock { closes }
    }

    func send(_ data: Data, to endpoint: FightcadeNetplayEndpoint) async throws {}

    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> (Data, FightcadeNetplayEndpoint) {
        throw error
    }

    func close() {
        lock.withLock { closes += 1 }
    }
}
