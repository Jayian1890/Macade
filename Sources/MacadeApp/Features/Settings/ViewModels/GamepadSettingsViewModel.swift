import Foundation
import Observation

@MainActor
@Observable
final class GamepadSettingsViewModel {
    var devices: [GamepadDevice] = []
    var selectedDeviceID = "" { didSet { cancelCapture() } }
    var search = ""
    var games: [GamepadGame] = []
    var selectedGame: GamepadGame?
    var player = 1 { didSet { cancelCapture() } }
    var inputs: [GamepadGameInput] = []
    var captureInput: GamepadGameInput?
    var captureArmed = false
    var message: String?
    var error: String?
    var isLoading = false
    private var rest: Set<MacadeGamepadControl> = []
    private let service: any GamepadServicing
    private var monitorTask: Task<Void, Never>?
    private var gameTask: Task<Void, Never>?
    private var generation = 0

    init(service: any GamepadServicing = SDLGamepadService()) { self.service = service }

    var selectedDevice: GamepadDevice? { devices.first { $0.id == selectedDeviceID } }
    var playerInputs: [GamepadGameInput] { inputs.filter { $0.player == player } }
    var availablePlayers: [Int] { Array(Set(inputs.map(\.player))).sorted() }
    var matchingGames: [GamepadGame] {
        let query = search.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !query.isEmpty else { return [] }
        return Array(games.filter {
            $0.id.localizedCaseInsensitiveContains(query) || $0.title.localizedCaseInsensitiveContains(query)
        }.sorted { ($0.id == query ? 0 : 1, $0.id) < ($1.id == query ? 0 : 1, $1.id) }.prefix(8))
    }

    func start(settings: MacadeSettingsViewModel) async {
        error = nil
        do {
            let stream = try service.monitor()
            monitorTask = Task { [weak self, weak settings] in
                do {
                    for try await snapshot in stream {
                        guard let self, let settings, !Task.isCancelled else { break }
                        self.receive(snapshot, settings: settings)
                    }
                } catch {
                    guard !Task.isCancelled else { return }
                    self?.error = error.localizedDescription
                }
            }
            let catalog = try await service.games()
            guard !Task.isCancelled else { return }
            games = catalog
            if selectedGame == nil {
                let recent = UserDefaults.standard.string(forKey: "MacadeLastFBNeoGame")
                if let game = games.first(where: { $0.id == recent }) { select(game) }
            }
        } catch { self.error = error.localizedDescription }
    }

    func stop() {
        monitorTask?.cancel(); monitorTask = nil
        gameTask?.cancel(); gameTask = nil
        generation += 1
        service.stop()
        cancelCapture()
    }

    func select(_ game: GamepadGame) {
        cancelCapture()
        selectedGame = game
        search = ""
        inputs = []
        isLoading = true
        gameTask?.cancel()
        generation += 1
        let request = generation
        gameTask = Task { [weak self] in
            guard let self else { return }
            do {
                let loaded = try await service.inputs(gameID: game.id)
                guard !Task.isCancelled, generation == request else { return }
                inputs = loaded
                player = availablePlayers.first ?? 1
                error = nil
            } catch {
                guard !Task.isCancelled, generation == request else { return }
                self.error = error.localizedDescription
            }
            if generation == request { isLoading = false }
        }
    }

    func beginCapture(_ input: GamepadGameInput) {
        guard selectedDevice != nil else { return }
        captureInput = input
        captureArmed = false
        rest = selectedDevice?.restingControls ?? []
        message = "Release buttons and center the sticks, then press or move the control for \(input.title)."
        // Do not depend on a new SDL event to arm when already neutral.
        armIfNeutral()
    }

    func cancelCapture() { captureInput = nil; captureArmed = false }

    func binding(for input: GamepadGameInput, settings: MacadeSettingsViewModel) -> MacadeGamepadBinding? {
        settings.gamepadPreferences.bindings.first {
            $0.gameID == selectedGame?.id && $0.inputIndex == input.index && $0.inputInfo == input.info
        }
    }

    func clear(_ input: GamepadGameInput, settings: MacadeSettingsViewModel) {
        apply(nil, input: input, settings: settings)
    }

    func reset(settings: MacadeSettingsViewModel) {
        guard let game = selectedGame else { return }
        cancelCapture()
        settings.gamepadPreferences.bindings.removeAll {
            $0.gameID == game.id && $0.player == player
        }
        message = "Restored FBNeo bindings for this game and player. Save and relaunch to apply."
    }

    private func receive(_ snapshot: GamepadSnapshot, settings: MacadeSettingsViewModel) {
        devices = snapshot.devices
        if selectedDeviceID.isEmpty, let first = devices.first { selectedDeviceID = first.id }
        guard selectedDevice != nil else { cancelCapture(); return }
        guard let input = captureInput else { return }
        if !captureArmed { armIfNeutral(); return }
        guard let control = selectedDevice?.controls.first(where: {
            !rest.contains($0) && (!input.analog || $0.kind == "a")
        }) else { return }
        let captured = input.analog ? MacadeGamepadControl(kind: "x", index: control.index, direction: 0) : control
        apply(captured, input: input, settings: settings)
        cancelCapture()
    }

    private func armIfNeutral() {
        guard let device = selectedDevice else { return }
        if Set(device.controls).subtracting(rest).isEmpty { captureArmed = true }
    }

    private func apply(_ control: MacadeGamepadControl?, input: GamepadGameInput, settings: MacadeSettingsViewModel) {
        guard let game = selectedGame, !selectedDeviceID.isEmpty else { return }
        let conflict = settings.gamepadPreferences.set(MacadeGamepadBinding(
            deviceID: selectedDeviceID, gameID: game.id, inputIndex: input.index,
            inputInfo: input.info, player: input.player, control: control
        ))
        message = conflict
            ? "Moved this control from its previous action. Save and relaunch to apply."
            : "\(input.title): \(control?.title ?? "unbound"). Save and relaunch to apply."
    }
}
