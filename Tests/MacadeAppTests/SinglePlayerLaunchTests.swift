import XCTest
@testable import Macade

@MainActor
final class SinglePlayerLaunchTests: XCTestCase {
    func testPlayerOneGamepadRestrictionOnlyAppliesToLocalFBNeoSinglePlayer() {
        for mode: FightcadeEmbeddedSession.Mode in [.singlePlayer, .test, .training, .match, .direct, .spectate, .replay] {
            let launch = FightcadeEmbeddedLaunch(channelID: channel.id, mode: mode,
                emulator: "fbneo", gameID: channel.gameID!, arguments: [channel.gameID!],
                title: "Input policy", match: nil)
            XCTAssertEqual(launch.restrictsGamepadToPlayerOne, mode == .singlePlayer)
            let networkArgument = FightcadeEmbeddedLaunch(channelID: channel.id, mode: mode,
                emulator: "fbneo", gameID: channel.gameID!, arguments: ["quark:direct,sfiii3nr1,7000,127.0.0.1,7001,1,0"],
                title: "Input policy", match: nil)
            XCTAssertFalse(networkArgument.restrictsGamepadToPlayerOne)
        }
        XCTAssertFalse(FightcadeEmbeddedLaunch.singlePlayer(channelID: channel.id,
            emulator: "snes9x", gameID: "snes_smwu").restrictsGamepadToPlayerOne)
    }

    func testUnavailableRuntimeAndROMDoNotStartAnEmulator() {
        let launcher = RouteGatedFightcadeLauncher()
        let model = makeModel(launcher: launcher)
        launcher.localAvailable = false
        model.launchSinglePlayer(in: channel)
        XCTAssertEqual(model.errorMessage, "Native fbneo runtime not installed.")
        launcher.localAvailable = true
        model.launchSinglePlayer(in: channel)
        XCTAssertEqual(model.errorMessage, "Download this game's ROM from Resources first.")
        XCTAssertTrue(launcher.embeddedLaunches.isEmpty)
        XCTAssertFalse(model.isLaunchingGame)
    }

    func testLocalLaunchDoesNotNeedRoomMembershipOrNetplayCapabilityAndRejectsDuplicateClicks() async throws {
        let launcher = RouteGatedFightcadeLauncher()
        launcher.roms = [launcher.romKey(emulator: "fbneo", gameID: channel.gameID!)]
        let model = makeModel(launcher: launcher)
        XCTAssertTrue(model.joinedChannelIDs.isEmpty)
        XCTAssertNil(model.singlePlayerUnavailableReason(for: channel))
        model.launchSinglePlayer(in: channel)
        XCTAssertTrue(model.isLaunchingGame)
        model.launchSinglePlayer(in: channel)
        await waitForLaunch(model)
        let launch = try XCTUnwrap(launcher.embeddedLaunches.first)
        XCTAssertEqual(launcher.embeddedLaunches.count, 1)
        XCTAssertEqual(launch.channelID, channel.id)
        XCTAssertEqual(launch.arguments, [channel.gameID!])
        XCTAssertEqual(launch.mode, .singlePlayer)
        XCTAssertFalse(launch.requiresQuark)
        XCTAssertNil(launch.match)
        XCTAssertFalse(model.isLaunchingGame)
        XCTAssertEqual(model.errorMessage, "Could not launch game.")
        XCTAssertNil(model.activeEmulationSession)
        XCTAssertFalse(model.isShowingGameplay)
    }

    func testSinglePlayerCannotReplaceAnActiveMatchOrDirectSession() throws {
        let launcher = RouteGatedFightcadeLauncher()
        launcher.roms = [launcher.romKey(emulator: "fbneo", gameID: channel.gameID!)]
        let model = makeModel(launcher: launcher)
        let directory = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        defer { try? FileManager.default.removeItem(at: directory) }
        for mode: FightcadeEmbeddedSession.Mode in [.match, .direct] {
            let video = try FightcadeEmbeddedVideoStream(fileURL: directory.appendingPathComponent("\(mode.rawValue).video"))
            let input = try FightcadeEmbeddedInputClient(socketPath: directory.appendingPathComponent("input.sock").path)
            let session = FightcadeEmbeddedSession(id: UUID(), channelID: channel.id, mode: mode,
                emulator: "fbneo", gameID: channel.gameID!, title: "Match",
                logURL: directory.appendingPathComponent("launch.log"), videoStream: video, inputClient: input)
            model.activeEmulationSession = session
            model.launchSinglePlayer(in: channel)
            XCTAssertTrue(session.isActive)
            XCTAssertEqual(model.activeEmulationSession?.id, session.id)
            XCTAssertTrue(launcher.embeddedLaunches.isEmpty)
            XCTAssertEqual(model.errorMessage, "Stop the active match before starting single player.")
            video.close()
            input.close()
        }
    }

    func testInstalledFBNeoSinglePlayerRendersFramesAndStops() async throws {
        guard ProcessInfo.processInfo.environment["MACADE_SINGLE_PLAYER_RUNTIME"] == "1" else {
            throw XCTSkip("Opt in with TEST_RUNNER_MACADE_SINGLE_PLAYER_RUNTIME=1; requires the installed sfiii3nr1 ROM and no active FBNeo game.")
        }
        let probe = Process()
        let output = Pipe()
        probe.executableURL = URL(fileURLWithPath: "/bin/ps")
        probe.arguments = ["-axo", "comm=,args="]
        probe.standardOutput = output
        try probe.run()
        let processes = String(decoding: output.fileHandleForReading.readDataToEndOfFile(), as: UTF8.self)
        probe.waitUntilExit()
        guard !processes.split(separator: "\n").contains(where: {
            ($0.contains("/macfbneo") || $0.contains("/fcadefbneo")) && !$0.contains(" --macade-controllers")
        }) else { throw XCTSkip("An FBNeo game is already running; leave it undisturbed.") }
        let launcher = FightcadeLauncher()
        let model = makeModel(launcher: launcher)
        XCTAssertNil(model.singlePlayerUnavailableReason(for: channel))
        model.launchSinglePlayer(in: channel)
        await waitForLaunch(model)
        let session = try XCTUnwrap(model.activeEmulationSession, model.errorMessage ?? "Missing session")
        defer { model.stopActiveEmulationSession() }
        XCTAssertTrue(model.isShowingGameplay)
        XCTAssertEqual(model.selectedChannelID, channel.id)
        XCTAssertEqual(model.activeEmulationChannel?.id, channel.id)
        XCTAssertEqual(session.mode, .singlePlayer)
        XCTAssertTrue(session.title.hasPrefix("Single Player"))
        let launchLog = try String(contentsOf: session.logURL, encoding: .utf8)
        XCTAssertTrue(launchLog.contains("MACADE_SINGLE_PLAYER_INPUT=1"))

        let deadline = ContinuousClock.now + .seconds(30)
        var firstFrame: FightcadeEmbeddedVideoFrame?
        while ContinuousClock.now < deadline, session.isActive {
            if let frame = session.videoStream.snapshot(), frame.bytes.contains(where: { $0 != 0 }) {
                firstFrame = frame
                break
            }
            try await Task.sleep(for: .milliseconds(100))
        }
        let frame = try XCTUnwrap(firstFrame, "No rendered frame; status \(session.statusText), log \(session.logURL.path)")
        XCTAssertGreaterThan(frame.width, 0)
        XCTAssertGreaterThan(frame.height, 0)
        try await Task.sleep(for: .milliseconds(250))
        XCTAssertGreaterThan(try XCTUnwrap(session.videoStream.snapshot()).frameIndex, frame.frameIndex)
        print("Single Player native verification: \(session.gameID), \(frame.width)x\(frame.height), frame \(frame.frameIndex), \(session.statusText)")
        model.stopActiveEmulationSession()
        XCTAssertNil(model.activeEmulationSession)
        XCTAssertFalse(model.isShowingGameplay)
        for _ in 0..<60 {
            if case .terminated = session.status { break }
            try await Task.sleep(for: .milliseconds(50))
        }
        guard case .terminated = session.status else { return XCTFail("Emulator did not terminate: \(session.statusText)") }
    }

    private var channel: FightcadeChannel {
        FightcadeChannel(id: "sfiii3nr1", name: "sfiii3nr1", title: "Street Fighter III 3rd Strike",
            gameID: "sfiii3nr1", system: "Arcade", emulator: "fbneo", playerCount: nil,
            spectatorCount: nil, isRanked: true, isFavorite: false, supportsTraining: true)
    }

    private func makeModel(launcher: any FightcadeLaunching) -> AuthenticatedHomeViewModel {
        let model = AuthenticatedHomeViewModel(session: AuthSession(username: "local-validation", displayName: "Local"), launcher: launcher)
        model.dashboard = FightcadeDashboard(connectedUsername: "Local", welcomeMessage: nil, channels: [channel])
        return model
    }

    private func waitForLaunch(_ model: AuthenticatedHomeViewModel) async {
        for _ in 0..<100 where model.isLaunchingGame {
            try? await Task.sleep(for: .milliseconds(50))
        }
    }
}
