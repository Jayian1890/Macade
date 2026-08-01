import XCTest
@testable import MacadeApp

final class FightcadeWelcomeParserTests: XCTestCase {
    func testBrowserSectionsPreserveWelcomeOrderAndTypes() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "results": [
                [
                    "title": "Popular games",
                    "channels": [[
                        "name": "The King of Fighters '98",
                        "gameid": "kof98",
                        "clients": 291,
                        "system": "Arcade FC2",
                        "emulator": "fbneo",
                        "ranked": true,
                        "training": true
                    ]]
                ],
                [
                    "title": "Browse categories",
                    "categories": ["Popular", "My Favorites", "Fighter", "NAOMI"]
                ],
                [
                    "title": "Upcoming Events",
                    "events": [[
                        "name": "Tournament",
                        "author": "organizer",
                        "date": 1_785_610_800_000,
                        "gameid": "sf2rb4",
                        "image": "https://i.imgur.com/1cojbCV.png",
                        "link": "https://www.start.gg/example",
                        "region": "Region Free",
                        "stream": "https://www.twitch.tv/example"
                    ]]
                ]
            ]
        ]

        let sections = parser.browserSections(in: payload)

        XCTAssertEqual(sections.map(\.title), ["Popular games", "Browse categories", "Upcoming Events"])
        XCTAssertEqual(sections[0].channels.first?.gameID, "kof98")
        XCTAssertEqual(sections[1].categories, ["Popular", "My Favorites", "Fighter", "NAOMI"])
        XCTAssertEqual(sections[2].events.first?.imageURL?.absoluteString, "https://i.imgur.com/1cojbCV.png")
    }

    func testFavoritesSectionMarksChannelsAsFavorites() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "results": [[
                "title": "Favorites",
                "channels": [[
                    "name": "Street Fighter III 3rd Strike",
                    "gameid": "sfiii3nr1",
                    "system": "Arcade FC2",
                    "emulator": "fbneo"
                ]]
            ]]
        ]

        XCTAssertEqual(parser.browserSections(in: payload).first?.channels.first?.isFavorite, true)
    }
}
