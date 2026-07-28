import XCTest
@testable import MacadeApp

final class FightcadeMatchLaunchTests: XCTestCase {
    func testFBNeoQuarkServedCommandMatchesFightcadeLauncherContract() {
        let launch = FightcadeMatchLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1234567890-42",
            playerID: 0,
            port: 7000,
            delay: 2,
            ranked: 3,
            token: "secret-token"
        )

        XCTAssertEqual(
            launch.quarkCommand,
            "quark:served,sfiii3n,1234567890-42.0,7000,2,3"
        )
    }

    func testFBNeoQuarkStreamCommandNormalizesSpectatorSuffix() {
        let launch = FightcadeSpectateLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1234567890-42.2",
            port: 7001
        )

        XCTAssertEqual(
            launch.quarkCommand,
            "quark:stream,sfiii3n,1234567890-42.2,7001"
        )
    }

    func testFBNeoQuarkTrainingCommandMatchesFightcadeLauncherContract() {
        let launch = FightcadeTrainingLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1234567890-42",
            playerID: 1,
            port: 7000,
            delay: 2
        )

        XCTAssertEqual(
            launch.quarkCommand,
            "quark:training,sfiii3n,1234567890-42.1,7000,2"
        )
    }

    func testFBNeoQuarkDirectCommandMatchesFightcadeLauncherContract() {
        let launch = FightcadeDirectLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            localPort: 6000,
            host: "203.0.113.20",
            remotePort: 6001,
            playerID: 0,
            delay: 2,
            ranked: 0
        )

        XCTAssertEqual(
            launch.quarkCommand,
            "quark:direct,sfiii3n,6000,203.0.113.20,6001,0,2,0"
        )
    }
}
