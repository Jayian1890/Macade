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
        XCTAssertEqual(rows["readyfriend"]?.onlineStateText, "ONLINE")
        XCTAssertEqual(rows["readyfriend"]?.statusText, "Ready in Street Fighter III")
        XCTAssertEqual(rows["readyfriend"]?.isChallengeable, true)
        XCTAssertEqual(rows["readyfriend"]?.isWatchable, false)
        XCTAssertEqual(rows["playingfriend"]?.isChallengeable, false)
        XCTAssertEqual(rows["playingfriend"]?.isWatchable, true)
        XCTAssertEqual(rows["playingfriend"]?.statusText, "Playing in Street Fighter III")
        XCTAssertEqual(rows["missing"]?.isOnline, false)
        XCTAssertEqual(rows["missing"]?.onlineStateText, "OFFLINE")
        XCTAssertEqual(rows["missing"]?.statusText, "Not seen in joined rooms")
    }

    @MainActor
    func testDashboardRestoreAutojoinsOnlySavedJoinedChannels() async {
        let savedChannel = makeChannel(id: "sfiii3n", title: "Street Fighter III", isFavorite: false)
        let favoriteChannel = makeChannel(id: "kof98", title: "The King of Fighters '98", isFavorite: true)
        let lobbyService = RecordingLobbyService(dashboard: FightcadeDashboard(
            connectedUsername: "Me",
            welcomeMessage: nil,
            channels: [savedChannel, favoriteChannel],
            browserSections: [FightcadeWelcomeSection(
                title: "Favorites",
                channels: [favoriteChannel],
                categories: [],
                events: []
            )]
        ))
        let joinedStore = InMemoryJoinedChannelStore(ids: [savedChannel.id])
        let viewModel = AuthenticatedHomeViewModel(
            session: AuthSession(username: "me", displayName: "Me", sessionCookie: "cookie"),
            lobbyService: lobbyService,
            joinedChannelStore: joinedStore,
            channelCache: EmptyChannelCache(),
            friendStore: InMemoryFriendStore()
        )

        await viewModel.loadDashboard()

        let joinedNames = await lobbyService.waitForJoinedChannelNames(count: 1)
        XCTAssertEqual(joinedNames, [savedChannel.name])
        let restoredBackendJoin = await waitFor { viewModel.joinedChannelIDs == Set([savedChannel.id]) }
        XCTAssertTrue(restoredBackendJoin)
        XCTAssertEqual(joinedStore.ids, [savedChannel.id])
        XCTAssertFalse(viewModel.joinedChannelIDs.contains(favoriteChannel.id))
    }

    private func temporaryDirectory() -> URL {
        FileManager.default.temporaryDirectory
            .appendingPathComponent("MacadeFriendTests-\(UUID().uuidString)", isDirectory: true)
    }

    private func makeChannel(id: String, title: String, isFavorite: Bool) -> FightcadeChannel {
        FightcadeChannel(
            id: id,
            name: id,
            title: title,
            gameID: id,
            system: "Arcade",
            emulator: "fbneo",
            playerCount: nil,
            spectatorCount: nil,
            isRanked: true,
            isFavorite: isFavorite,
            supportsTraining: true
        )
    }

    @MainActor
    private func waitFor(_ condition: @escaping @MainActor () -> Bool) async -> Bool {
        for _ in 0..<100 {
            if condition() {
                return true
            }

            try? await Task.sleep(for: .milliseconds(10))
        }

        return condition()
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

private actor RecordingLobbyService: FightcadeLobbyServicing {
    private let dashboard: FightcadeDashboard
    private var eventContinuations: [AsyncStream<FightcadeLobbyEvent>.Continuation] = []
    private var joinedChannelNames: [String] = []

    init(dashboard: FightcadeDashboard) {
        self.dashboard = dashboard
    }

    func eventStream() -> AsyncStream<FightcadeLobbyEvent> {
        AsyncStream { continuation in
            Task { self.addEventContinuation(continuation) }
        }
    }

    func connect(for session: AuthSession) async throws -> FightcadeDashboard {
        await waitForEventListener()
        return dashboard
    }

    func refreshChannels() async throws {}

    func searchChannels(_ request: FightcadeChannelSearchRequest) async throws -> FightcadeChannelSearchResult {
        FightcadeChannelSearchResult(channels: [], page: request.page, hasMorePages: false)
    }

    func loadChannelFilterOptions() async throws -> FightcadeChannelFilterOptions {
        FightcadeChannelFilterOptions()
    }

    func loadUpcomingEvents(limit: Int) async throws -> [FightcadeEvent] { [] }

    func setFavorite(_ isFavorite: Bool, for channel: FightcadeChannel) async throws {}

    func join(channel: FightcadeChannel) async throws {
        joinedChannelNames.append(channel.name)
        emit(.joinedChannel(channel.name))
    }

    func leave(channel: FightcadeChannel) async throws {
        emit(.leftChannel(channel.name))
    }

    func sendChat(_ message: String, to channel: FightcadeChannel, from username: String) async throws {}

    func challenge(_ user: FightcadeChannelUser, in channel: FightcadeChannel, ranked: Int) async throws -> FightcadeChallenge {
        FightcadeChallenge(username: user.name, channelName: channel.name, challengeID: 1, ranked: ranked)
    }

    func acceptChallenge(_ challenge: FightcadeChallenge) async throws {}

    func rejectChallenge(_ challenge: FightcadeChallenge) async throws {}

    func cancelChallenge(_ challenge: FightcadeChallenge) async throws {}

    func disconnect() async {}

    func waitForJoinedChannelNames(count: Int) async -> [String] {
        for _ in 0..<100 {
            if joinedChannelNames.count >= count {
                return joinedChannelNames
            }

            try? await Task.sleep(for: .milliseconds(10))
        }

        return joinedChannelNames
    }

    private func addEventContinuation(_ continuation: AsyncStream<FightcadeLobbyEvent>.Continuation) {
        eventContinuations.append(continuation)
    }

    private func waitForEventListener() async {
        for _ in 0..<100 {
            if !eventContinuations.isEmpty {
                return
            }

            try? await Task.sleep(for: .milliseconds(10))
        }
    }

    private func emit(_ event: FightcadeLobbyEvent) {
        for continuation in eventContinuations {
            continuation.yield(event)
        }
    }
}

private final class InMemoryJoinedChannelStore: JoinedChannelPersisting {
    var ids: [FightcadeChannel.ID]

    init(ids: [FightcadeChannel.ID] = []) {
        self.ids = ids
    }

    func joinedChannelIDs(for session: AuthSession) -> [FightcadeChannel.ID] {
        ids
    }

    func saveJoinedChannelIDs(_ ids: [FightcadeChannel.ID], for session: AuthSession) {
        self.ids = ids
    }
}

private actor EmptyChannelCache: FightcadeChannelCaching {
    func loadChannels(for session: AuthSession) async -> [FightcadeChannel] { [] }

    func saveChannels(_ channels: [FightcadeChannel], for session: AuthSession) async {}
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
