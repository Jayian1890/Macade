import XCTest
@testable import MacadeApp

final class FightcadeRecentMatchTests: XCTestCase {
    func testSearchQuarksResponseDecodesCurrentChannelReplayMatch() throws {
        let json = #"""
        {
          "results": {
            "results": [
              {
                "quarkid": "1785711957006-5736",
                "channelname": "Street Fighter III 3rd Strike",
                "date": 1785711957006,
                "duration": 418.356,
                "emulator": "fbneo",
                "gameid": "sfiii3nr1",
                "num_matches": 3,
                "players": [
                  { "name": "jayian1890", "country": "US", "rank": 2, "score": 3 },
                  { "name": "MAURICIO DELGADO V.", "country": "EC", "rank": 2, "score": 0 }
                ],
                "ranked": 3,
                "replay_file": "1785711957006-5736-replay.fs"
              }
            ],
            "count": 1
          },
          "res": "OK"
        }
        """#

        let response = try JSONDecoder().decode(FightcadeRecentMatchSearchResponse.self, from: Data(json.utf8))
        let match = try XCTUnwrap(response.matches.first)

        XCTAssertEqual(match.quarkID, "1785711957006-5736")
        XCTAssertEqual(match.gameID, "sfiii3nr1")
        XCTAssertEqual(match.opponentName(for: "jayian1890"), "MAURICIO DELGADO V.")
        XCTAssertEqual(match.scoreText(for: "jayian1890"), "3-0")
        XCTAssertEqual(match.replayLink?.url.absoluteString, "https://replay.fightcade.com/fbneo/sfiii3nr1/1785711957006-5736")
    }

    func testReplayLinkRequiresReplayFile() throws {
        let json = #"""
        {
          "results": {
            "results": [
              {
                "quarkid": "1785687414715-8062",
                "date": 1785687414715,
                "duration": 102.632,
                "emulator": "fbneo",
                "gameid": "sfiii3nr1",
                "players": [
                  { "name": "jayian1890", "score": 0 },
                  { "name": "B1mnanaJo3", "score": 0 }
                ],
                "ranked": 3
              }
            ],
            "count": 1
          },
          "res": "OK"
        }
        """#

        let response = try JSONDecoder().decode(FightcadeRecentMatchSearchResponse.self, from: Data(json.utf8))
        let match = try XCTUnwrap(response.matches.first)

        XCTAssertFalse(match.hasReplay)
        XCTAssertNil(match.replayLink)
        XCTAssertEqual(match.scoreText(for: "B1mnanaJo3"), "0-0")
    }
}
