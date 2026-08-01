import XCTest
@testable import MacadeApp

final class ChannelTVTests: XCTestCase {
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

    private func makeChannel(gameID: String) -> FightcadeChannel {
        FightcadeChannel(
            id: gameID,
            name: gameID,
            title: "Street Fighter III",
            gameID: gameID,
            system: "Arcade",
            emulator: "fbneo",
            playerCount: nil,
            spectatorCount: nil,
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
}
