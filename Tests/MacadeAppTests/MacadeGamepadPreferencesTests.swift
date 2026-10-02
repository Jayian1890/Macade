import XCTest
@testable import Macade

final class MacadeGamepadPreferencesTests: XCTestCase {
    private func binding(input: Int, control: MacadeGamepadControl? = nil, device: String = "guid:n0", game: String = "sf2") -> MacadeGamepadBinding {
        MacadeGamepadBinding(deviceID: device, gameID: game, inputIndex: input,
                             inputInfo: "703120666972652031", player: 1, control: control)
    }

    func testPersistenceRoundTripKeepsKeyboardPreferences() throws {
        let suite = "MacadeGamepadTests.\(UUID().uuidString)"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suite))
        defer { defaults.removePersistentDomain(forName: suite) }
        let keyboard = MacadeControllerPreferencesStore(userDefaults: defaults)
        keyboard.save(.defaults)
        let store = MacadeGamepadPreferencesStore(userDefaults: defaults)
        var preferences = MacadeGamepadPreferences()
        preferences.bindings = [binding(input: 6, control: .init(kind: "b", index: 2, direction: 0))]
        try store.save(preferences)
        XCTAssertEqual(store.load(), preferences)
        XCTAssertEqual(keyboard.load(), .defaults)
    }

    func testDuplicateControlMovesOnlyWithinDeviceGameAndPlayer() {
        let button = MacadeGamepadControl(kind: "b", index: 2, direction: 0)
        var preferences = MacadeGamepadPreferences(bindings: [
            binding(input: 6, control: button), binding(input: 7, control: button, device: "other:n0"),
            binding(input: 6, control: button, game: "kof98")
        ])
        XCTAssertTrue(preferences.set(binding(input: 8, control: button)))
        XCTAssertNil(preferences.bindings.first { $0.gameID == "sf2" && $0.inputIndex == 6 }?.control)
        XCTAssertEqual(preferences.bindings.first { $0.inputIndex == 7 }?.control, button)
        XCTAssertEqual(preferences.bindings.first { $0.gameID == "kof98" }?.control, button)
    }

    func testOneControllerOwnsAnActionAndClearIsDifferentFromReset() {
        let button = MacadeGamepadControl(kind: "b", index: 0, direction: 0)
        var preferences = MacadeGamepadPreferences(bindings: [binding(input: 6, control: button)])
        _ = preferences.set(binding(input: 6, device: "second:n0"))
        XCTAssertEqual(preferences.bindings.count, 1)
        XCTAssertEqual(preferences.bindings[0].deviceID, "second:n0")
        XCTAssertTrue(preferences.runtimeProjection.contains(" - 0 0\n"))
        preferences.bindings.removeAll()
        XCTAssertEqual(preferences.runtimeProjection, "MACADE_GAMEPADS 1\n")
    }

    func testUnknownVersionsAndInvalidRecordsAreNotProjected() {
        var preferences = MacadeGamepadPreferences(version: 2, bindings: [binding(input: 6)])
        XCTAssertTrue(preferences.normalized().bindings.isEmpty)
        preferences = MacadeGamepadPreferences(bindings: [
            binding(input: -1), binding(input: 6, game: "sf2\nInjected"),
            binding(input: 7, control: .init(kind: "a", index: 0, direction: 0)),
            binding(input: 8, control: .init(kind: "h", index: 0, direction: 3))
        ])
        XCTAssertTrue(preferences.normalized().bindings.isEmpty)
    }

    func testProjectionIsDeterministicAndAtomic() throws {
        let suite = "MacadeProjectionTests.\(UUID().uuidString)"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suite))
        let directory = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        defer {
            defaults.removePersistentDomain(forName: suite)
            try? FileManager.default.removeItem(at: directory)
        }
        let store = MacadeGamepadPreferencesStore(userDefaults: defaults)
        let preferences = MacadeGamepadPreferences(bindings: [binding(input: 9), binding(input: 6)])
        try store.save(preferences)
        let url = try store.writeRuntimeProjection(in: directory)
        let data = try String(contentsOf: url, encoding: .utf8)
        XCTAssertEqual(data, preferences.runtimeProjection)
        XCTAssertLessThan(try XCTUnwrap(data.range(of: " sf2 6 ")?.lowerBound),
                          try XCTUnwrap(data.range(of: " sf2 9 ")?.lowerBound))
    }
}
