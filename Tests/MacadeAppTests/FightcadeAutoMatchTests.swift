import XCTest
@testable import MacadeApp

final class FightcadeAutoMatchTests: XCTestCase {
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

        XCTAssertEqual(first.users.count, 2)
        XCTAssertEqual(second.users.count, 2)
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
