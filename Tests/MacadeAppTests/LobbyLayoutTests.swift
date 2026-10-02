import XCTest
@testable import Macade

@MainActor
final class LobbyLayoutTests: XCTestCase {
    func testHoverShowsSavedExpandedWidthWithoutPersistingItAndCanBePinned() async throws {
        let suite = "LobbyLayoutTests.\(UUID())"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suite))
        defer { defaults.removePersistentDomain(forName: suite) }
        let store = LobbyLayoutStore(defaults: defaults)
        let model = LobbyLayoutViewModel(store: store)
        model.sidebarWidth = 312
        model.toggleSidebar()
        model.updateSidebarHover(true)
        try await Task.sleep(for: .milliseconds(200))
        XCTAssertTrue(model.isSidebarExpanded)
        XCTAssertFalse(model.isSidebarPinned)
        XCTAssertEqual(model.displayedSidebarWidth, 312)
        XCTAssertEqual(LobbyLayoutViewModel(store: store).sidebarWidth, MacadeLayout.sidebarCompact)

        model.updateSidebarHover(false)
        try await Task.sleep(for: .milliseconds(180))
        XCTAssertEqual(model.displayedSidebarWidth, MacadeLayout.sidebarCompact)
        model.updateSidebarHover(true)
        try await Task.sleep(for: .milliseconds(200))
        model.toggleSidebar()
        model.endSidebarHover()
        XCTAssertTrue(model.isSidebarPinned)
        XCTAssertEqual(model.displayedSidebarWidth, 312)
        XCTAssertEqual(LobbyLayoutViewModel(store: store).sidebarWidth, 312)
    }

    func testWindowConstraintsPreserveChatSpaceWithoutLosingPreferredWidth() throws {
        let suite = "LobbyLayoutTests.\(UUID())"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suite))
        defer { defaults.removePersistentDomain(forName: suite) }
        let model = LobbyLayoutViewModel(store: LobbyLayoutStore(defaults: defaults))
        model.playerListWidth = 480
        let constrained = MacadeLayout.paneDimension(preferred: model.playerListWidth,
            total: 700, minimum: 240, maximum: 480, flexibleMinimum: 360)
        XCTAssertEqual(constrained, 332)
        XCTAssertEqual(700 - constrained - MacadeLayout.dividerWidth, 360)
        XCTAssertEqual(model.playerListWidth, 480)
        XCTAssertEqual(MacadeLayout.paneDimension(preferred: model.playerListWidth,
            total: 1100, minimum: 240, maximum: 480, flexibleMinimum: 360), 480)
        XCTAssertEqual(LobbyLayoutViewModel(store: LobbyLayoutStore(defaults: defaults)).playerListWidth, 480)
    }

    func testCollapseRestoresResizedNavigationAndAllDimensionsPersist() throws {
        let suite = "LobbyLayoutTests.\(UUID())"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suite))
        defer { defaults.removePersistentDomain(forName: suite) }
        let store = LobbyLayoutStore(defaults: defaults)
        let model = LobbyLayoutViewModel(store: store)
        model.sidebarWidth = 312
        model.playerDetailsHeight = 280
        model.toggleSidebar()
        XCTAssertEqual(model.sidebarWidth, MacadeLayout.sidebarCompact)
        model.toggleSidebar()
        XCTAssertEqual(model.sidebarWidth, 312)
        let restored = LobbyLayoutViewModel(store: store)
        XCTAssertEqual(restored.sidebarWidth, 312)
        XCTAssertEqual(restored.playerDetailsHeight, 280)
    }

    func testInvalidStoredSizesAndTinyContainersRemainBounded() throws {
        let suite = "LobbyLayoutTests.\(UUID())"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suite))
        defer { defaults.removePersistentDomain(forName: suite) }
        defaults.set(-500, forKey: "lobbySidebarWidth")
        defaults.set(10000, forKey: "playerListSidebarWidth")
        let model = LobbyLayoutViewModel(store: LobbyLayoutStore(defaults: defaults))
        XCTAssertEqual(model.sidebarWidth, MacadeLayout.sidebarCompact)
        XCTAssertEqual(model.playerListWidth, MacadeLayout.playersMaximum)
        for total: CGFloat in [0, 4, 100, 500] {
            let fixed = MacadeLayout.paneDimension(preferred: .infinity,
                total: total, minimum: 240, maximum: 480, flexibleMinimum: 360)
            XCTAssertGreaterThanOrEqual(fixed, 0)
            XCTAssertLessThanOrEqual(fixed + min(total, MacadeLayout.dividerWidth), total)
        }
    }
}
