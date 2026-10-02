import XCTest
@testable import Macade

@MainActor
final class GamepadSettingsViewModelTests: XCTestCase {
    private let input = GamepadGameInput(index: 6, title: "P1 Weak Punch", info: "703120666972652031", player: 1, analog: false)

    func testCaptureWaitsForReleaseAndMovesConflictingBinding() async throws {
        let service = ControllerStreamFixture()
        let model = GamepadSettingsViewModel(service: service)
        let settings = MacadeSettingsViewModel()
        model.selectedGame = GamepadGame(id: "sf2", title: "Street Fighter II")
        await model.start(settings: settings)
        defer { model.stop() }
        let button = MacadeGamepadControl(kind: "b", index: 0, direction: 0)
        service.send(controls: [button])
        try await eventually { model.selectedDevice != nil }
        model.beginCapture(input)
        XCTAssertFalse(model.captureArmed)
        service.send(controls: [])
        try await eventually { model.captureArmed }
        _ = settings.gamepadPreferences.set(.init(deviceID: "guid:s1234", gameID: "sf2", inputIndex: 9,
                                                  inputInfo: "703120666972652034", player: 1, control: button))
        service.send(controls: [button])
        try await eventually { model.captureInput == nil }
        XCTAssertEqual(settings.gamepadPreferences.bindings.first { $0.inputIndex == 6 }?.control, button)
        XCTAssertNil(settings.gamepadPreferences.bindings.first { $0.inputIndex == 9 }?.control)
        XCTAssertTrue(model.message?.contains("Moved") == true)
    }

    func testStickHeldAtCaptureIsNotTreatedAsRestingTrigger() async throws {
        let service = ControllerStreamFixture()
        let model = GamepadSettingsViewModel(service: service)
        let settings = MacadeSettingsViewModel()
        model.selectedGame = GamepadGame(id: "sf2", title: "Street Fighter II")
        await model.start(settings: settings)
        defer { model.stop() }
        let left = MacadeGamepadControl(kind: "a", index: 0, direction: -1)
        service.send(controls: [left], axes: [-32768, -32768], initial: [0, -32768])
        try await eventually { model.selectedDevice != nil }
        model.beginCapture(input)
        XCTAssertFalse(model.captureArmed)
        // Resting triggers don't prevent capture, but the held stick must be released.
        let triggerRest = MacadeGamepadControl(kind: "a", index: 1, direction: -1)
        service.send(controls: [triggerRest], axes: [0, -32768], initial: [0, -32768])
        try await eventually { model.captureArmed }
        service.send(controls: [left, triggerRest], axes: [-22000, -32768], initial: [0, -32768])
        try await eventually { model.captureInput == nil }
        XCTAssertEqual(settings.gamepadPreferences.bindings.first?.control, left)
    }

    func testDisconnectCancelsCaptureAndReconnectRetainsSelection() async throws {
        let service = ControllerStreamFixture()
        let model = GamepadSettingsViewModel(service: service)
        let settings = MacadeSettingsViewModel()
        await model.start(settings: settings)
        defer { model.stop() }
        service.send(controls: [])
        try await eventually { model.selectedDevice != nil }
        model.beginCapture(input)
        service.continuation?.yield(GamepadSnapshot(devices: []))
        try await eventually { model.selectedDevice == nil }
        XCTAssertNil(model.captureInput)
        XCTAssertEqual(model.selectedDeviceID, "guid:s1234")
        service.send(controls: [])
        try await eventually { model.selectedDevice != nil }
        XCTAssertEqual(model.selectedDeviceID, "guid:s1234")
    }

    func testConsoleModesCaptureReportedControlsWithoutModelNameMapping() async throws {
        let service = ControllerStreamFixture()
        let model = GamepadSettingsViewModel(service: service)
        let settings = MacadeSettingsViewModel()
        model.selectedGame = GamepadGame(id: "sf2", title: "Street Fighter II")
        await model.start(settings: settings)
        defer { model.stop() }
        // Names are aliases from the manuals; controls deliberately vary. This
        // verifies capture behavior, not a mapping for the physical products.
        let samples: [(String, MacadeGamepadControl)] = [
            ("Xbox Wireless Controller", .init(kind: "a", index: 5, direction: 1)),
            ("Wireless Controller", .init(kind: "h", index: 0, direction: 8)),
            ("Pro Controller", .init(kind: "b", index: 15, direction: 0))
        ]
        for (name, control) in samples {
            let rest = MacadeGamepadControl(kind: "a", index: 5, direction: -1)
            service.send(controls: [rest], axes: [0, 0, 0, 0, 0, -32768],
                         initial: [0, 0, 0, 0, 0, -32768], name: name)
            try await eventually { model.selectedDevice?.name == name }
            model.beginCapture(input)
            XCTAssertTrue(model.captureArmed)
            service.send(controls: control.kind == "a" ? [control] : [rest, control],
                         axes: [0, 0, 0, 0, 0, control.kind == "a" ? 32767 : -32768],
                         initial: [0, 0, 0, 0, 0, -32768], name: name)
            try await eventually { model.captureInput == nil }
            XCTAssertEqual(model.binding(for: input, settings: settings)?.control, control)
        }
    }

    func testSettingsSaveAndDiscardIncludeGamepadProfiles() throws {
        let suite = "GamepadSettingsTests.\(UUID().uuidString)"
        let defaults = try XCTUnwrap(UserDefaults(suiteName: suite))
        let directory = FileManager.default.temporaryDirectory.appendingPathComponent(UUID().uuidString)
        defer {
            defaults.removePersistentDomain(forName: suite)
            try? FileManager.default.removeItem(at: directory)
        }
        let model = MacadeSettingsViewModel(fbneoStore: FightcadeFBNeoSettingsStore(configDirectory: directory),
                                           preferencesStore: MacadeSettingsPreferencesStore(userDefaults: defaults))
        model.load()
        let binding = MacadeGamepadBinding(deviceID: "guid:s1234", gameID: "sf2", inputIndex: 6,
                                           inputInfo: input.info, player: 1, control: nil)
        _ = model.gamepadPreferences.set(binding)
        XCTAssertTrue(model.hasUnsavedChanges)
        model.discardChanges()
        XCTAssertFalse(model.hasUnsavedChanges)
        XCTAssertTrue(model.gamepadPreferences.bindings.isEmpty)
        _ = model.gamepadPreferences.set(binding)
        model.save()
        XCTAssertFalse(model.hasUnsavedChanges)
        XCTAssertEqual(MacadeGamepadPreferencesStore(userDefaults: defaults).load().bindings, [binding])
    }

    func testBundledSDLHelperContractAndDriverMetadata() async throws {
        let service = SDLGamepadService()
        defer { service.stop() }
        let games = try await service.games()
        XCTAssertTrue(games.contains { $0.id == "sf2" })
        let fighter = try await service.inputs(gameID: "sf2")
        XCTAssertEqual(fighter.first { $0.index == 6 }?.title, "P1 Weak Punch")
        XCTAssertEqual(fighter.filter { $0.player == 1 }.count, 12)
        let shooter = try await service.inputs(gameID: "1942")
        XCTAssertEqual(shooter.filter { $0.player == 1 }.count, 8)
        let racer = try await service.inputs(gameID: "outrun")
        XCTAssertEqual(racer.filter(\.analog).count, 3)
        var snapshot: GamepadSnapshot?
        for try await received in try service.monitor() {
            snapshot = received
            break
        }
        XCTAssertNotNil(snapshot)
        for device in snapshot?.devices ?? [] {
            XCTAssertEqual(device.initialAxes.count, device.axes.count)
            XCTAssertTrue(device.controls.allSatisfy(\.isValid))
        }
    }

    private func eventually(_ condition: () -> Bool) async throws {
        for _ in 0..<100 {
            if condition() { return }
            try await Task.sleep(for: .milliseconds(5))
        }
        XCTFail("Controller stream did not update the expected state")
    }
}

// A test-only input stream; production discovery is always the bundled SDL helper.
@MainActor
private final class ControllerStreamFixture: GamepadServicing {
    var continuation: AsyncThrowingStream<GamepadSnapshot, any Error>.Continuation?
    func monitor() throws -> AsyncThrowingStream<GamepadSnapshot, any Error> {
        AsyncThrowingStream { continuation = $0 }
    }
    func games() async throws -> [GamepadGame] { [] }
    func inputs(gameID: String) async throws -> [GamepadGameInput] { [] }
    func stop() { continuation?.finish(); continuation = nil }
    func send(controls: [MacadeGamepadControl], axes: [Int] = [0, 0], initial: [Int] = [0, 0], name: String = "Test controller") {
        continuation?.yield(GamepadSnapshot(devices: [GamepadDevice(id: "guid:s1234", name: name,
            hasSerial: true, controls: controls, axes: axes, initialAxes: initial)]))
    }
}
