import XCTest
@testable import MacadeApp

final class FightcadeLobbyPayloadParserTests: XCTestCase {
    func testLauncherTokenReadsLoggedInUserToken() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "user": [
                "name": "player",
                "token": "live-token"
            ]
        ]

        XCTAssertEqual(parser.launcherToken(in: payload), "live-token")
    }

    func testStartEventParsesNullRankedAsUnrankedMatchStart() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "req": "start",
            "channelname": "Street Fighter III 3rd Strike: Fight for the Future (Japan 990512, NO CD)",
            "delay": 1,
            "gameid": "sfiii3nr1",
            "playerid": 1,
            "port": 7001,
            "quarkid": "1785013981484-4901",
            "ranked": NSNull(),
            "token": "live-token"
        ]

        let event = parser.event(in: payload, currentChannelName: nil)

        guard case .matchStarted(let start) = event else {
            return XCTFail("Expected matchStarted event")
        }

        XCTAssertEqual(start.channelName, "Street Fighter III 3rd Strike: Fight for the Future (Japan 990512, NO CD)")
        XCTAssertEqual(start.gameID, "sfiii3nr1")
        XCTAssertEqual(start.quarkID, "1785013981484-4901")
        XCTAssertEqual(start.playerID, 1)
        XCTAssertEqual(start.port, 7001)
        XCTAssertEqual(start.ranked, 0)
        XCTAssertEqual(start.delay, 1)
        XCTAssertEqual(start.token, "live-token")
    }

    func testUsersParsePlayingFalseAsChallengeableState() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "users": [
                [
                    "name": "opponent",
                    "away": false,
                    "playing": false,
                    "wlan": true,
                    "vping": 37,
                    "proxy": true,
                    "ranked": 3,
                    "matches": 21,
                    "region": "Region Free",
                    "gameid": "sfiii3n",
                    "quarkid": "1785073365625-9431",
                    "port": 7001,
                    "prevent_bad_challenges": true,
                    "prevent_wifi_challenges": true
                ]
            ]
        ]

        let users = parser.users(in: payload)

        XCTAssertEqual(users.count, 1)
        XCTAssertFalse(users[0].isAway)
        XCTAssertFalse(users[0].isPlaying)
        XCTAssertTrue(users[0].isUsingWifi)
        XCTAssertEqual(users[0].virtualPing, 37)
        XCTAssertTrue(users[0].isUsingProxy)
        XCTAssertEqual(users[0].rankedSetting, 3)
        XCTAssertEqual(users[0].matchCount, 21)
        XCTAssertEqual(users[0].region, "Region Free")
        XCTAssertEqual(users[0].stream, FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785073365625-9431", port: 7001))
        XCTAssertTrue(users[0].preventsBadChallenges)
        XCTAssertTrue(users[0].preventsWifiChallenges)
    }

    func testUsersAttachStreamsFromJoinQuarks() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "gameid": "kof98",
            "users": [
                ["name": "Mahaloz", "playing": false],
                ["name": "idle", "playing": false]
            ],
            "quarks": [
                [
                    "players": ["Mahaloz", "yulanxl"],
                    "port": 7001,
                    "quarkid": "1785073071864-8625"
                ]
            ]
        ]

        let users = parser.users(in: payload)

        XCTAssertEqual(users[0].stream, FightcadeSpectatorStream(gameID: "kof98", quarkID: "1785073071864-8625", port: 7001))
        XCTAssertTrue(users[0].isPlaying)
        XCTAssertNil(users[1].stream)
        XCTAssertFalse(users[1].isPlaying)
    }

    func testUsersInferPlayingFromNestedGameStream() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "users": [
                [
                    "name": "opponent",
                    "game": [
                        "gameid": "sfiii3n",
                        "quarkid": "1785073365625-9431",
                        "port": 7001
                    ]
                ]
            ]
        ]

        let users = parser.users(in: payload)

        XCTAssertEqual(users[0].stream, FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785073365625-9431", port: 7001))
        XCTAssertTrue(users[0].isPlaying)
    }

    func testChallengeFailureParsesRestrictionWarning() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "req": "challenge",
            "username": "opponent",
            "channelname": "sfiii3n",
            "challengeid": 7,
            "result": 403,
            "response": "Cannot challenge this user because of ping restrictions."
        ]

        let event = parser.event(in: payload, currentChannelName: nil)

        guard case .challengeRestricted(let warning) = event else {
            return XCTFail("Expected challengeRestricted event")
        }

        XCTAssertEqual(warning.username, "opponent")
        XCTAssertEqual(warning.channelName, "sfiii3n")
        XCTAssertEqual(warning.challengeID, 7)
        XCTAssertEqual(warning.message, "Cannot challenge this user because of ping restrictions.")
    }

    func testBrokenChallengeWarningParsesRestrictionWarning() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "req": "broken",
            "channelname": "sfiii3n",
            "chat": "Cannot challenge this user from your region."
        ]

        let event = parser.event(in: payload, currentChannelName: nil)

        guard case .challengeRestricted(let warning) = event else {
            return XCTFail("Expected challengeRestricted event")
        }

        XCTAssertEqual(warning.channelName, "sfiii3n")
        XCTAssertEqual(warning.message, "Cannot challenge this user from your region.")
    }

    func testStatusEventParsesPlayingUpdate() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "req": "stplaying",
            "username": "opponent",
            "channelname": "sfiii3n",
            "gameid": "sfiii3n",
            "quarkid": "1785073365625-9431",
            "port": 7001
        ]

        let event = parser.event(in: payload, currentChannelName: nil)

        guard case .userStatusUpdated(let update) = event else {
            return XCTFail("Expected userStatusUpdated event")
        }

        XCTAssertEqual(update.username, "opponent")
        XCTAssertEqual(update.channelName, "sfiii3n")
        XCTAssertEqual(update.isPlaying, true)
        XCTAssertNil(update.isAway)
        XCTAssertNil(update.isUsingWifi)
        XCTAssertEqual(update.stream, FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785073365625-9431", port: 7001))
    }

    func testQuarkStatsParsesLiveStreamUpdate() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "req": "quarkstats",
            "channelname": "kof98",
            "quark": [
                "players": ["Mahaloz", "yulanxl"],
                "port": 7001,
                "quarkid": "1785073071864-8625",
                "spectators": 2
            ]
        ]

        let event = parser.event(in: payload, currentChannelName: nil)

        guard case .liveStreamUpdated(let update) = event else {
            return XCTFail("Expected liveStreamUpdated event")
        }

        XCTAssertEqual(update.channelName, "kof98")
        XCTAssertEqual(update.players, ["Mahaloz", "yulanxl"])
        XCTAssertEqual(update.stream, FightcadeSpectatorStream(gameID: nil, quarkID: "1785073071864-8625", port: 7001))
    }
}
