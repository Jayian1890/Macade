import XCTest
@testable import Macade

final class FightcadeUserStatusReporterTests: XCTestCase {
    func testStatusHashMatchesWindowsLauncherFormula() {
        let payload = FightcadeUserStatusPayload(
            token: "tok",
            userStatus: "stcable",
            uuid: "uuid",
            guid: "guid",
            huid: "huid"
        )

        XCTAssertEqual(payload.hash, "a766b975ff83d1c99d33dbefa38235e6")
    }
}
