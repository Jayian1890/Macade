import XCTest
@testable import Macade

final class FightcadeAutoMatchTests: XCTestCase {
    func testDefaultConfigurationUsesThreeInvitesAndThirtySecondRotation() {
        let configuration = FightcadeAutoMatchConfiguration.default

        XCTAssertEqual(configuration.maxChallengesPerAttempt, 3)
        XCTAssertEqual(configuration.acceptanceTimeoutSeconds, 30)
        XCTAssertEqual(configuration.retryCooldownSeconds, 120)
    }

    func testConfigurationStorePersistsPerSessionAndChannel() {
        let suiteName = "MacadeAutoMatchTests-\(UUID().uuidString)"
        let userDefaults = UserDefaults(suiteName: suiteName)!
        defer { userDefaults.removePersistentDomain(forName: suiteName) }
        let store = UserDefaultsFightcadeAutoMatchConfigurationStore(userDefaults: userDefaults)
        let session = AuthSession(username: "me", displayName: "Me")
        let configuration = FightcadeAutoMatchConfiguration(
            maxChallengesPerAttempt: 4,
            acceptanceTimeoutSeconds: 45,
            rankTolerance: 2,
            maximumPing: 180,
            retryCooldownSeconds: 90
        )

        store.saveConfiguration(configuration, for: session, channelName: "sfiii3n")

        XCTAssertEqual(store.configuration(for: session, channelName: "sfiii3n"), configuration)
        XCTAssertEqual(store.configuration(for: session, channelName: "kof98"), .default)
        XCTAssertEqual(store.configuration(for: AuthSession(username: "other", displayName: "Other"), channelName: "sfiii3n"), .default)
    }

    @MainActor
    func testAutoMatchRejectedInviteClearsWithoutChatMessage() {
        let viewModel = makeViewModel()
        let challenge = makeChallenge(username: "Opponent")
        viewModel.outgoingChallenges = [challenge]
        viewModel.autoMatchStatesByChannel[challenge.channelName] = makeAutoMatchState(for: challenge)

        viewModel.handle(.challengeRejected(challenge))

        XCTAssertTrue(viewModel.outgoingChallenges.isEmpty)
        XCTAssertTrue(viewModel.chatMessagesByChannel[challenge.channelName, default: []].isEmpty)
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.activeChallengeIDs ?? [], [])
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.status, .searching)
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.outcomes.rejected, 1)
    }

    @MainActor
    func testAutoMatchWarningClearsInviteWithoutChatOrGlobalError() {
        let viewModel = makeViewModel()
        let challenge = makeChallenge(username: "Opponent")
        let message = "Cannot challenge this user because of ping restrictions."
        viewModel.outgoingChallenges = [challenge]
        viewModel.autoMatchStatesByChannel[challenge.channelName] = makeAutoMatchState(for: challenge)

        viewModel.handle(.challengeRestricted(FightcadeChallengeWarning(
            username: challenge.username,
            channelName: challenge.channelName,
            challengeID: challenge.challengeID,
            message: message
        )))

        XCTAssertTrue(viewModel.outgoingChallenges.isEmpty)
        XCTAssertNil(viewModel.errorMessage)
        XCTAssertTrue(viewModel.chatMessagesByChannel[challenge.channelName, default: []].isEmpty)
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.activeChallengeIDs ?? [], [])
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.status, .paused(message))
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.outcomes.failed, 1)
    }

    @MainActor
    func testAutoMatchCancelEchoIsSuppressedAfterInviteWasCleared() {
        let viewModel = makeViewModel()
        let challenge = makeChallenge(username: "Opponent")
        var state = makeAutoMatchState(for: challenge)
        state.activeChallengeIDs.removeAll()
        viewModel.autoMatchStatesByChannel[challenge.channelName] = state

        viewModel.handle(.challengeCanceled(challenge))

        XCTAssertTrue(viewModel.chatMessagesByChannel[challenge.channelName, default: []].isEmpty)
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.outcomes.canceled, 1)
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[challenge.channelName]?.managedChallengeIDs ?? [], [])
    }

    @MainActor
    func testManualRejectedInviteStillAddsChatMessage() {
        let viewModel = makeViewModel()
        let challenge = makeChallenge(username: "Opponent")
        viewModel.outgoingChallenges = [challenge]

        viewModel.handle(.challengeRejected(challenge))

        XCTAssertEqual(viewModel.chatMessagesByChannel[challenge.channelName]?.map(\.body), ["Opponent rejected the challenge"])
    }

    func testPlannerSelectsOnlyRankAndCountryOrPingEligibleUsers() {
        let planner = FightcadeAutoMatchPlanner()
        let session = AuthSession(username: "me", displayName: "Me")
        let users = [
            makeUser("Me", countryCode: "US", ping: nil, rank: 3),
            makeUser("sameCountry", countryCode: "US", ping: 300, rank: 3),
            makeUser("lowPing", countryCode: "CA", ping: 149, rank: 4),
            makeUser("tooFar", countryCode: "US", ping: 10, rank: 5),
            makeUser("tooSlow", countryCode: "JP", ping: 150, rank: 2),
            makeUser("playing", countryCode: "US", ping: 10, rank: 3, isPlaying: true),
            makeUser("away", countryCode: "US", ping: 10, rank: 3, isAway: true),
            makeUser("blocked", countryCode: "US", ping: 10, rank: 3)
        ]

        let attempt = planner.attempt(
            users: users,
            session: session,
            activeChallengeUsernames: ["blocked"],
            challengedUsernames: []
        )

        XCTAssertEqual(Set(attempt.users.map(\.name)), ["sameCountry", "lowPing"])
    }

    func testPlannerDoesNotRepeatAlreadyChallengedUsers() {
        let planner = FightcadeAutoMatchPlanner()
        let session = AuthSession(username: "me", displayName: "Me")
        let users = [
            makeUser("Me", countryCode: "US", ping: nil, rank: 3),
            makeUser("A", countryCode: "US", ping: 10, rank: 3),
            makeUser("B", countryCode: "US", ping: 20, rank: 3),
            makeUser("C", countryCode: "US", ping: 30, rank: 3),
            makeUser("D", countryCode: "US", ping: 40, rank: 3)
        ]

        let first = planner.attempt(
            users: users,
            session: session,
            activeChallengeUsernames: [],
            challengedUsernames: []
        )
        let firstNames = Set(first.users.map(\.name))
        let second = planner.attempt(
            users: users,
            session: session,
            activeChallengeUsernames: [],
            challengedUsernames: firstNames
        )
        let secondNames = Set(second.users.map(\.name))

        XCTAssertEqual(first.users.count, 3)
        XCTAssertEqual(second.users.count, 1)
        XCTAssertTrue(firstNames.isDisjoint(with: secondNames))

        let exhausted = planner.attempt(
            users: users,
            session: session,
            activeChallengeUsernames: [],
            challengedUsernames: firstNames.union(secondNames)
        )

        XCTAssertTrue(exhausted.users.isEmpty)
        XCTAssertEqual(exhausted.status, .allEligiblePlayersTried)
    }

    func testPlannerRequiresCurrentUserRank() {
        let planner = FightcadeAutoMatchPlanner()
        let session = AuthSession(username: "me", displayName: "Me")
        let users = [
            makeUser("Me", countryCode: "US", ping: nil, rank: nil),
            makeUser("A", countryCode: "US", ping: 10, rank: 3)
        ]

        let attempt = planner.attempt(
            users: users,
            session: session,
            activeChallengeUsernames: [],
            challengedUsernames: []
        )

        XCTAssertTrue(attempt.users.isEmpty)
        XCTAssertEqual(attempt.status, .missingCurrentUserRank)
    }

    func testPlannerAllowsEligibleIncomingChallenge() {
        let planner = FightcadeAutoMatchPlanner()
        let session = AuthSession(username: "me", displayName: "Me")
        let challenge = makeChallenge(username: "Opponent")
        let users = [
            makeUser("Me", countryCode: "US", ping: nil, rank: 3),
            makeUser("Opponent", countryCode: "CA", ping: 120, rank: 4)
        ]

        XCTAssertTrue(planner.isEligibleIncomingChallenge(challenge, users: users, session: session))
    }

    func testPlannerRejectsIncomingChallengeOutsideSettings() {
        let planner = FightcadeAutoMatchPlanner()
        let session = AuthSession(username: "me", displayName: "Me")
        let challenge = makeChallenge(username: "Opponent")
        let users = [
            makeUser("Me", countryCode: "US", ping: nil, rank: 3),
            makeUser("Opponent", countryCode: "JP", ping: 180, rank: 5)
        ]

        XCTAssertFalse(planner.isEligibleIncomingChallenge(challenge, users: users, session: session))
    }

    @MainActor
    func testAutoMatchAcceptsEligibleIncomingChallenge() async {
        let lobbyService = RecordingAutoMatchLobbyService()
        let viewModel = makeViewModel(lobbyService: lobbyService)
        let channel = makeChannel()
        let challenge = makeChallenge(username: "Opponent")
        var state = FightcadeAutoMatchState()
        state.isEnabled = true
        viewModel.joinedChannelIDs = [channel.id]
        viewModel.usersByChannel[channel.name] = [
            makeUser("Me", countryCode: "US", ping: nil, rank: 3),
            makeUser("Opponent", countryCode: "CA", ping: 120, rank: 4)
        ]
        viewModel.autoMatchStatesByChannel[channel.name] = state

        viewModel.handle(.challengeReceived(challenge))

        let acceptedChallenges = await lobbyService.waitForAcceptedChallenges(count: 1)
        XCTAssertEqual(acceptedChallenges, [challenge])
        XCTAssertEqual(viewModel.activeMatchOpponentUsername, "Opponent")
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[channel.name]?.isEnabled, false)
    }

    @MainActor
    func testAutoMatchLeavesIneligibleIncomingChallengeForManualResponse() async {
        let lobbyService = RecordingAutoMatchLobbyService()
        let viewModel = makeViewModel(lobbyService: lobbyService)
        let channel = makeChannel()
        let challenge = makeChallenge(username: "Opponent")
        var state = FightcadeAutoMatchState()
        state.isEnabled = true
        viewModel.joinedChannelIDs = [channel.id]
        viewModel.usersByChannel[channel.name] = [
            makeUser("Me", countryCode: "US", ping: nil, rank: 3),
            makeUser("Opponent", countryCode: "JP", ping: 180, rank: 5)
        ]
        viewModel.autoMatchStatesByChannel[channel.name] = state

        viewModel.handle(.challengeReceived(challenge))

        let acceptedChallenges = await lobbyService.waitForAcceptedChallenges(count: 1)
        XCTAssertEqual(acceptedChallenges, [])
        XCTAssertEqual(viewModel.incomingChallenges, [challenge])
        XCTAssertEqual(viewModel.autoMatchStatesByChannel[channel.name]?.isEnabled, true)
    }

    @MainActor
    private func makeViewModel() -> AuthenticatedHomeViewModel {
        AuthenticatedHomeViewModel(session: AuthSession(username: "me", displayName: "Me"))
    }

    @MainActor
    private func makeViewModel(lobbyService: any FightcadeLobbyServicing) -> AuthenticatedHomeViewModel {
        let launcher = RouteGatedFightcadeLauncher()
        launcher.capabilities = [.fightcadeMatch]
        launcher.roms = [launcher.romKey(emulator: "fbneo", gameID: "sfiii3n")]
        let viewModel = AuthenticatedHomeViewModel(
            session: AuthSession(username: "me", displayName: "Me"),
            lobbyService: lobbyService,
            launcher: launcher
        )
        viewModel.dashboard = FightcadeDashboard(
            connectedUsername: "Me",
            welcomeMessage: nil,
            channels: [makeChannel()]
        )
        return viewModel
    }

    private func makeChannel() -> FightcadeChannel {
        FightcadeChannel(
            id: "sfiii3n",
            name: "sfiii3n",
            title: "Street Fighter III 3rd Strike",
            gameID: "sfiii3n",
            system: "Arcade",
            emulator: "fbneo",
            playerCount: nil,
            spectatorCount: nil,
            isRanked: true,
            isFavorite: false,
            supportsTraining: true
        )
    }

    private func makeChallenge(username: String) -> FightcadeChallenge {
        FightcadeChallenge(username: username, channelName: "sfiii3n", challengeID: 7, ranked: FightcadeChallenge.defaultRankedValue)
    }

    private func makeAutoMatchState(for challenge: FightcadeChallenge) -> FightcadeAutoMatchState {
        var state = FightcadeAutoMatchState()
        state.isEnabled = true
        state.activeChallengeIDs = [challenge.id]
        state.managedChallengeIDs = [challenge.id]
        state.challengeCooldownsByUsername = [challenge.username.lowercased(): .distantFuture]
        state.status = .waiting(usernames: [challenge.username])
        return state
    }

    private func makeUser(
        _ name: String,
        countryCode: String?,
        ping: Int?,
        rank: Int?,
        isAway: Bool = false,
        isPlaying: Bool = false
    ) -> FightcadeChannelUser {
        FightcadeChannelUser(
            id: name,
            name: name,
            gravatarHash: nil,
            countryCode: countryCode,
            ping: ping,
            virtualPing: nil,
            rank: rank,
            matchCount: nil,
            rankedSetting: nil,
            region: nil,
            isAway: isAway,
            isPlaying: isPlaying,
            isUsingWifi: false,
            isUsingProxy: false,
            preventsBadChallenges: false,
            preventsWifiChallenges: false,
            stream: nil
        )
    }
}

private actor RecordingAutoMatchLobbyService: FightcadeLobbyServicing {
    private var acceptedChallenges: [FightcadeChallenge] = []

    func eventStream() -> AsyncStream<FightcadeLobbyEvent> {
        AsyncStream { _ in }
    }

    func connect(for session: AuthSession) async throws -> FightcadeDashboard {
        FightcadeDashboard(connectedUsername: session.displayName, welcomeMessage: nil, channels: [])
    }

    func refreshChannels() async throws {}

    func searchChannels(matching query: String) async throws -> [FightcadeChannel] { [] }

    func loadUpcomingEvents(limit: Int) async throws -> [FightcadeEvent] { [] }

    func loadRecentMatches(for username: String, gameID: String, limit: Int) async throws -> [FightcadeRecentMatch] { [] }

    func setFavorite(_ isFavorite: Bool, for channel: FightcadeChannel) async throws {}

    func join(channel: FightcadeChannel) async throws {}

    func leave(channel: FightcadeChannel) async throws {}

    func sendChat(_ message: String, to channel: FightcadeChannel, from username: String) async throws {}

    func challenge(_ user: FightcadeChannelUser, in channel: FightcadeChannel, ranked: Int) async throws -> FightcadeChallenge {
        FightcadeChallenge(username: user.name, channelName: channel.name, challengeID: 1, ranked: ranked)
    }

    func acceptChallenge(_ challenge: FightcadeChallenge) async throws {
        acceptedChallenges.append(challenge)
    }

    func rejectChallenge(_ challenge: FightcadeChallenge) async throws {}

    func cancelChallenge(_ challenge: FightcadeChallenge) async throws {}

    func disconnect() async {}

    func waitForAcceptedChallenges(count: Int) async -> [FightcadeChallenge] {
        for _ in 0..<100 {
            if acceptedChallenges.count >= count {
                return acceptedChallenges
            }

            try? await Task.sleep(for: .milliseconds(10))
        }

        return acceptedChallenges
    }
}
