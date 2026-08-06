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

    @MainActor
    private func makeViewModel() -> AuthenticatedHomeViewModel {
        AuthenticatedHomeViewModel(session: AuthSession(username: "me", displayName: "Me"))
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
