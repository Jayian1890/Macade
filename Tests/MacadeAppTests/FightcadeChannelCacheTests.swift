import XCTest
@testable import MacadeApp

final class FightcadeChannelCacheTests: XCTestCase {
    func testSaveThenLoadChannelsRoundTripsSessionScopedCache() async throws {
        let rootURL = FileManager.default.temporaryDirectory
            .appendingPathComponent("MacadeChannelCacheTests-\(UUID().uuidString)", isDirectory: true)
        defer { try? FileManager.default.removeItem(at: rootURL) }

        let cache = FileFightcadeChannelCache(rootURL: rootURL)
        let session = AuthSession(username: "Player/One", displayName: "Player One")
        let otherSession = AuthSession(username: "Player Two", displayName: "Player Two")
        let channels = [
            FightcadeChannel(
                id: "sfiii3n",
                name: "sfiii3n",
                title: "Street Fighter III 3rd Strike",
                gameID: "sfiii3n",
                system: "Arcade",
                emulator: "fbneo",
                playerCount: 42,
                spectatorCount: 7,
                isRanked: true,
                isFavorite: false,
                supportsTraining: true
            )
        ]

        await cache.saveChannels(channels, for: session)

        let loadedChannels = await cache.loadChannels(for: session)
        let otherChannels = await cache.loadChannels(for: otherSession)
        XCTAssertEqual(loadedChannels, channels)
        XCTAssertEqual(otherChannels, [])
    }

    func testEmptySaveDoesNotClearExistingCache() async throws {
        let rootURL = FileManager.default.temporaryDirectory
            .appendingPathComponent("MacadeChannelCacheTests-\(UUID().uuidString)", isDirectory: true)
        defer { try? FileManager.default.removeItem(at: rootURL) }

        let cache = FileFightcadeChannelCache(rootURL: rootURL)
        let session = AuthSession(username: "player", displayName: "Player")
        let channels = [
            FightcadeChannel(
                id: "kof98",
                name: "kof98",
                title: "King of Fighters '98",
                gameID: "kof98",
                system: nil,
                emulator: "fbneo",
                playerCount: 12,
                spectatorCount: nil,
                isRanked: false,
                isFavorite: true,
                supportsTraining: false
            )
        ]

        await cache.saveChannels(channels, for: session)
        await cache.saveChannels([], for: session)

        let loadedChannels = await cache.loadChannels(for: session)
        XCTAssertEqual(loadedChannels, channels)
    }
}
