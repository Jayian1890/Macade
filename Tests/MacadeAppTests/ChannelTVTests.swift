import XCTest
@testable import Macade

final class ChannelTVTests: XCTestCase {
    func testTVChannelsUseSpectatorsAsPlayerCountTieBreaker() {
        let lowSpectators = makeChannel(gameID: "low", title: "Low", playerCount: 8, spectatorCount: 1)
        let highSpectators = makeChannel(gameID: "high", title: "High", playerCount: 8, spectatorCount: 12)
        let fewerPlayers = makeChannel(gameID: "fewer", title: "Fewer", playerCount: 7, spectatorCount: 99)

        let sortedIDs = channelTVChannels(from: [lowSpectators, fewerPlayers, highSpectators]).map(\.id)

        XCTAssertEqual(sortedIDs, ["high", "low", "fewer"])
    }

    func testCandidatesGroupPairPlayersByStream() {
        let channel = makeChannel(gameID: "sfiii3n")
        let stream = FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785013981484-4901", port: 7001)
        let candidates = channelTVMatchCandidates(
            in: channel,
            users: [
                makeUser("PlayerTwo", stream: stream),
                makeUser("PlayerOne", stream: stream),
                makeUser("Me", stream: stream)
            ],
            session: AuthSession(username: "me", displayName: "Me")
        )

        XCTAssertEqual(candidates.count, 1)
        XCTAssertEqual(candidates[0].title, "PlayerOne vs PlayerTwo")
        XCTAssertEqual(candidates[0].gameID, "sfiii3n")
        XCTAssertEqual(candidates[0].stream, stream)
    }

    func testCandidatesIgnoreMismatchedStreamGameID() {
        let channel = makeChannel(gameID: "sfiii3n")
        let candidates = channelTVMatchCandidates(
            in: channel,
            users: [
                makeUser("OtherGame", stream: FightcadeSpectatorStream(gameID: "kof98", quarkID: "1785013981484-4901", port: 7001))
            ],
            session: AuthSession(username: "me", displayName: "Me")
        )

        XCTAssertTrue(candidates.isEmpty)
    }

    func testRandomCandidateSkipsBlockedMatches() {
        let channel = makeChannel(gameID: "sfiii3n")
        let firstStream = FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785013981484-4901", port: 7001)
        let secondStream = FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785013981484-4902", port: 7002)
        let candidates = channelTVMatchCandidates(
            in: channel,
            users: [
                makeUser("First", stream: firstStream),
                makeUser("Second", stream: secondStream)
            ],
            session: AuthSession(username: "me", displayName: "Me")
        )
        let blockedID = candidates.first { $0.stream == firstStream }?.id
        var generator = FixedRandomNumberGenerator()

        let selected = channelTVRandomCandidate(
            from: candidates,
            blockedIDs: Set([blockedID].compactMap { $0 }),
            using: &generator
        )

        XCTAssertEqual(selected?.stream, secondStream)
    }

    func testReplayLinkParsesFightcadeReplayURLInChatText() throws {
        let message = FightcadeChatMessage(
            channelName: "sfiii3nr1",
            username: "player",
            body: "ggs replay: https://replay.fightcade.com/fbneo/sfiii3nr1/1785591363134-2108)",
            kind: .user
        )

        let link = try XCTUnwrap(message.fightcadeReplayLink)

        XCTAssertEqual(link.url.absoluteString, "https://replay.fightcade.com/fbneo/sfiii3nr1/1785591363134-2108")
        XCTAssertEqual(link.emulator, "fbneo")
        XCTAssertEqual(link.gameID, "sfiii3nr1")
        XCTAssertEqual(link.replayID, "1785591363134-2108")
    }

    func testReplayLaunchUsesObservedQuarkReplayRoute() {
        let launch = FightcadeReplayLaunch(
            emulator: "fbneo",
            gameID: "sfiii3nr1",
            replayPath: "/tmp/1785591363134-2108.fcreplay"
        )

        XCTAssertEqual(launch.quarkCommand, "quark:replay,/tmp/1785591363134-2108.fcreplay")
        XCTAssertTrue(FightcadeEmbeddedLaunch.replay(channelID: "sfiii3nr1", launch: launch).requiresQuark)
    }

    func testReplayStreamLaunchUsesFightcadeWebRedirectShape() {
        let launch = FightcadeReplayStreamLaunch(
            emulator: "fbneo",
            gameID: "sfiii3nr1",
            quarkID: "1785591363134-2108.7",
            port: 7100
        )

        XCTAssertEqual(launch.quarkCommand, "quark:stream,sfiii3nr1,1785591363134-2108.7,7100")
        XCTAssertTrue(FightcadeEmbeddedLaunch.replayStream(channelID: "sfiii3nr1", launch: launch).requiresQuark)
    }

    @MainActor
    func testChallengeAndAutoMatchRequireMatchCapabilityAndROM() {
        let launcher = RouteGatedFightcadeLauncher()
        let channel = makeChannel(gameID: "sfiii3n")
        let user = makeIdleUser("Opponent")
        let viewModel = makeViewModel(channel: channel, launcher: launcher)
        viewModel.joinedChannelIDs = [channel.id]

        XCTAssertFalse(viewModel.canChallenge(user, in: channel))
        XCTAssertFalse(viewModel.canToggleAutoMatch(for: channel))

        launcher.capabilities = [.fightcadeMatch]
        XCTAssertFalse(viewModel.canChallenge(user, in: channel))
        XCTAssertFalse(viewModel.canToggleAutoMatch(for: channel))

        launcher.roms = [launcher.romKey(emulator: "fbneo", gameID: "sfiii3n")]
        XCTAssertTrue(viewModel.canChallenge(user, in: channel))
        XCTAssertTrue(viewModel.canToggleAutoMatch(for: channel))

        let challenge = FightcadeChallenge(
            username: user.name,
            channelName: channel.name,
            challengeID: 1,
            ranked: FightcadeChallenge.defaultRankedValue
        )
        XCTAssertTrue(viewModel.canAcceptIncomingChallenge(challenge))

        launcher.roms.removeAll()
        XCTAssertFalse(viewModel.canAcceptIncomingChallenge(challenge))
    }

    @MainActor
    func testSpectateWebReplayAndTVRequireSpectateCapabilityAndROM() throws {
        let launcher = RouteGatedFightcadeLauncher()
        let channel = makeChannel(gameID: "sfiii3n")
        let stream = FightcadeSpectatorStream(gameID: channel.gameID, quarkID: "1785013981484-4901", port: 7001)
        let user = makeUser("Opponent", stream: stream)
        let link = FightcadeReplayLink(
            url: try XCTUnwrap(URL(string: "https://replay.fightcade.com/fbneo/sfiii3n/1785013981484-4901")),
            emulator: "fbneo",
            gameID: "sfiii3n",
            replayID: "1785013981484-4901"
        )
        let viewModel = makeViewModel(channel: channel, launcher: launcher)
        viewModel.joinedChannelIDs = [channel.id]

        XCTAssertFalse(viewModel.canSpectate(user, in: channel))
        XCTAssertFalse(viewModel.canOpenFightcadeReplay(link))
        XCTAssertTrue(viewModel.fightcadeTVChannels.isEmpty)

        launcher.capabilities = [.fightcadeSpectate]
        XCTAssertFalse(viewModel.canSpectate(user, in: channel))
        XCTAssertFalse(viewModel.canOpenFightcadeReplay(link))
        XCTAssertTrue(viewModel.fightcadeTVChannels.isEmpty)

        launcher.roms = [launcher.romKey(emulator: "fbneo", gameID: "sfiii3n")]
        XCTAssertTrue(viewModel.canSpectate(user, in: channel))
        XCTAssertTrue(viewModel.canOpenFightcadeReplay(link))
        XCTAssertEqual(viewModel.fightcadeTVChannels.map(\.id), [channel.id])
    }

    @MainActor
    private func makeViewModel(
        channel: FightcadeChannel,
        launcher: RouteGatedFightcadeLauncher
    ) -> AuthenticatedHomeViewModel {
        let viewModel = AuthenticatedHomeViewModel(
            session: AuthSession(username: "me", displayName: "Me"),
            launcher: launcher
        )
        viewModel.dashboard = FightcadeDashboard(
            connectedUsername: "Me",
            welcomeMessage: nil,
            channels: [channel]
        )
        return viewModel
    }

    private func makeChannel(
        gameID: String,
        title: String = "Street Fighter III",
        playerCount: Int? = nil,
        spectatorCount: Int? = nil
    ) -> FightcadeChannel {
        FightcadeChannel(
            id: gameID,
            name: gameID,
            title: title,
            gameID: gameID,
            system: "Arcade",
            emulator: "fbneo",
            playerCount: playerCount,
            spectatorCount: spectatorCount,
            isRanked: true,
            isFavorite: false,
            supportsTraining: true
        )
    }

    private func makeUser(_ name: String, stream: FightcadeSpectatorStream) -> FightcadeChannelUser {
        FightcadeChannelUser(
            id: name,
            name: name,
            gravatarHash: nil,
            countryCode: nil,
            ping: nil,
            virtualPing: nil,
            rank: nil,
            matchCount: nil,
            rankedSetting: nil,
            region: nil,
            isAway: false,
            isPlaying: true,
            isUsingWifi: false,
            isUsingProxy: false,
            preventsBadChallenges: false,
            preventsWifiChallenges: false,
            stream: stream
        )
    }

    private func makeIdleUser(_ name: String) -> FightcadeChannelUser {
        FightcadeChannelUser(
            id: name,
            name: name,
            gravatarHash: nil,
            countryCode: nil,
            ping: nil,
            virtualPing: nil,
            rank: nil,
            matchCount: nil,
            rankedSetting: nil,
            region: nil,
            isAway: false,
            isPlaying: false,
            isUsingWifi: false,
            isUsingProxy: false,
            preventsBadChallenges: false,
            preventsWifiChallenges: false,
            stream: nil
        )
    }

    private struct FixedRandomNumberGenerator: RandomNumberGenerator {
        mutating func next() -> UInt64 {
            0
        }
    }
}

@MainActor
final class RouteGatedFightcadeLauncher: FightcadeLaunching {
    var capabilities = Set<FightcadeRuntimeCapability>()
    var roms = Set<String>()

    func canLaunchLocalGame(emulator: String) -> Bool {
        true
    }

    func canLaunchFightcadeRoute(_ capability: FightcadeRuntimeCapability, emulator: String) -> Bool {
        capabilities.contains(capability)
    }

    func hasLocalROM(emulator: String, gameID: String) -> Bool {
        roms.contains(romKey(emulator: emulator, gameID: gameID))
    }

    func open(_ route: FightcadeLaunchRoute) async throws {
        throw StubError.unexpectedLaunch
    }

    func openEmbedded(_ launch: FightcadeEmbeddedLaunch) async throws -> FightcadeEmbeddedSession {
        throw StubError.unexpectedLaunch
    }

    func romKey(emulator: String, gameID: String) -> String {
        "\(emulator.lowercased()):\(gameID.lowercased())"
    }

    private enum StubError: Error {
        case unexpectedLaunch
    }
}
