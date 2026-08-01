import XCTest
@testable import MacadeApp

final class FightcadePreviewURLTests: XCTestCase {
    func testChannelPreviewURLUsesCurrentKOFAsset() {
        let channel = FightcadeChannel(
            id: "kof98",
            name: "The King of Fighters '98",
            title: "The King of Fighters '98",
            gameID: "kof98",
            system: "Arcade FC2",
            emulator: "fbneo",
            playerCount: 1,
            spectatorCount: nil,
            isRanked: true,
            isFavorite: false,
            supportsTraining: true
        )

        XCTAssertEqual(channel.previewURL?.absoluteString, "https://web.fightcade.com/static/previews/kof98.png")
    }

    func testChannelPreviewURLStripsFC1Prefix() {
        let channel = FightcadeChannel(
            id: "fc1_sfiii3n",
            name: "Street Fighter III 3rd Strike",
            title: "Street Fighter III 3rd Strike",
            gameID: "fc1_sfiii3n",
            system: "Arcade FC1",
            emulator: "fc1",
            playerCount: nil,
            spectatorCount: nil,
            isRanked: false,
            isFavorite: false,
            supportsTraining: false
        )

        XCTAssertEqual(channel.previewURL?.absoluteString, "https://web.fightcade.com/static/previews/sfiii3n.png")
    }

    func testEventUsesImageBeforeGamePreviewFallbacks() {
        let imageURL = URL(string: "https://i.imgur.com/example.png")!
        let event = FightcadeEvent(
            name: "Tournament",
            author: nil,
            date: Date(timeIntervalSince1970: 0),
            gameID: "kof2002",
            imageURL: imageURL,
            link: nil,
            region: nil,
            stream: nil
        )

        XCTAssertEqual(event.previewURL, imageURL)
        XCTAssertEqual(event.fallbackPreviewURLs.first?.absoluteString, "https://web.fightcade.com/static/previews/kof2002.png")
    }
}
