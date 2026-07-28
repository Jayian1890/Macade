import XCTest
@testable import MacadeApp

final class MacadeSettingsPreferencesStoreTests: XCTestCase {
    func testPreferencesUseIsolatedUserDefaults() throws {
        let suiteName = "MacadeSettingsPreferencesStoreTests.\(UUID().uuidString)"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suiteName))
        defer { defaults.removePersistentDomain(forName: suiteName) }
        let store = MacadeSettingsPreferencesStore(userDefaults: defaults)

        store.forceWiredConnectionStatus = true
        store.lobbyDiagnosticsEnabled = true
        store.includeLobbyDiagnosticChatBodies = true

        XCTAssertTrue(store.forceWiredConnectionStatus)
        XCTAssertTrue(store.lobbyDiagnosticsEnabled)
        XCTAssertTrue(store.includeLobbyDiagnosticChatBodies)

        store.lobbyDiagnosticsEnabled = false

        XCTAssertFalse(store.lobbyDiagnosticsEnabled)
        XCTAssertFalse(store.includeLobbyDiagnosticChatBodies)
    }
}
