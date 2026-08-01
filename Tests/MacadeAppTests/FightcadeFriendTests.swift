import XCTest
@testable import MacadeApp

final class FightcadeFriendTests: XCTestCase {
    func testFileFriendStoreRoundTripsSessionScopedFriends() async throws {
        let root = temporaryDirectory()
        let store = FileFightcadeFriendStore(rootURL: root)
        let firstSession = AuthSession(username: "PlayerOne", displayName: "PlayerOne")
        let secondSession = AuthSession(username: "PlayerTwo", displayName: "PlayerTwo")

        await store.saveFriends([
            FightcadeFriend(username: "zeta"),
            FightcadeFriend(username: "Alpha"),
            FightcadeFriend(username: "alpha")
        ], for: firstSession)
        await store.saveFriends([
            FightcadeFriend(username: "other")
        ], for: secondSession)

        let firstFriends = await store.loadFriends(for: firstSession)
        let secondFriends = await store.loadFriends(for: secondSession)

        XCTAssertEqual(firstFriends.map(\.username), ["Alpha", "zeta"])
        XCTAssertEqual(secondFriends.map(\.username), ["other"])
    }

    @MainActor
    func testViewModelAddsRemovesAndRejectsDuplicateOrCurrentUserFriends() {
        let viewModel = AuthenticatedHomeViewModel(
            session: AuthSession(username: "me", displayName: "Me"),
            friendStore: InMemoryFriendStore()
        )

        XCTAssertTrue(viewModel.addFriend(named: "Opponent"))
        XCTAssertFalse(viewModel.addFriend(named: "opponent"))
        XCTAssertFalse(viewModel.addFriend(named: "me"))
        XCTAssertFalse(viewModel.addFriend(named: "Me"))
        XCTAssertTrue(viewModel.isFriend("opponent"))
        XCTAssertEqual(viewModel.friends.map(\.username), ["Opponent"])

        viewModel.removeFriend(named: "OPPONENT")

        XCTAssertFalse(viewModel.isFriend("Opponent"))
        XCTAssertTrue(viewModel.friends.isEmpty)
    }

    @MainActor
    func testFriendRowsUseJoinedRosterForChallengeAndWatchActions() {
        let channel = FightcadeChannel(
            id: "sfiii3n",
            name: "sfiii3n",
            title: "Street Fighter III",
            gameID: "sfiii3n",
            system: "Arcade",
            emulator: "fbneo",
            playerCount: nil,
            spectatorCount: nil,
            isRanked: true,
            isFavorite: false,
            supportsTraining: true
        )
        let viewModel = AuthenticatedHomeViewModel(
            session: AuthSession(username: "me", displayName: "Me"),
            friendStore: InMemoryFriendStore()
        )
        viewModel.dashboard = FightcadeDashboard(connectedUsername: "Me", welcomeMessage: nil, channels: [channel])
        viewModel.joinedChannelIDs = [channel.id]
        viewModel.usersByChannel[channel.name] = [
            makeUser("ReadyFriend", isPlaying: false),
            makeUser("PlayingFriend", isPlaying: true, stream: FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "123-456", port: 7001))
        ]
        viewModel.friends = [
            FightcadeFriend(username: "readyfriend"),
            FightcadeFriend(username: "playingfriend"),
            FightcadeFriend(username: "missing")
        ]

        let rows = Dictionary(uniqueKeysWithValues: viewModel.friendRows.map { ($0.friend.id, $0) })

        XCTAssertEqual(rows["readyfriend"]?.user?.name, "ReadyFriend")
        XCTAssertEqual(rows["readyfriend"]?.channel?.id, channel.id)
        XCTAssertEqual(rows["readyfriend"]?.isChallengeable, true)
        XCTAssertEqual(rows["readyfriend"]?.isWatchable, false)
        XCTAssertEqual(rows["playingfriend"]?.isChallengeable, false)
        XCTAssertEqual(rows["playingfriend"]?.isWatchable, true)
        XCTAssertEqual(rows["missing"]?.isOnline, false)
    }

    private func temporaryDirectory() -> URL {
        FileManager.default.temporaryDirectory
            .appendingPathComponent("MacadeFriendTests-\(UUID().uuidString)", isDirectory: true)
    }

    private func makeUser(
        _ name: String,
        isPlaying: Bool,
        stream: FightcadeSpectatorStream? = nil
    ) -> FightcadeChannelUser {
        FightcadeChannelUser(
            id: name,
            name: name,
            gravatarHash: nil,
            countryCode: "US",
            ping: 42,
            virtualPing: nil,
            rank: 3,
            matchCount: nil,
            rankedSetting: nil,
            region: nil,
            isAway: false,
            isPlaying: isPlaying,
            isUsingWifi: false,
            isUsingProxy: false,
            preventsBadChallenges: false,
            preventsWifiChallenges: false,
            stream: stream
        )
    }
}

private final class InMemoryFriendStore: FightcadeFriendPersisting, @unchecked Sendable {
    var friends: [FightcadeFriend] = []

    func loadFriends(for session: AuthSession) async -> [FightcadeFriend] {
        friends
    }

    func saveFriends(_ friends: [FightcadeFriend], for session: AuthSession) async {
        self.friends = friends
    }
}
