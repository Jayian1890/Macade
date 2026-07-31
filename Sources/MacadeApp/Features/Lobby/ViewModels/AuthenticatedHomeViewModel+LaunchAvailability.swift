extension AuthenticatedHomeViewModel {
    func launchTestGame() {
        guard let channel = selectedChannel else {
            return
        }

        launchGame(for: channel, mode: .test)
    }

    func checkROM() {
        guard let channel = selectedChannel else {
            return
        }

        launchGame(for: channel, mode: .checkROM)
    }

    func launchTraining() {
        guard let channel = selectedChannel else {
            return
        }

        launchGame(for: channel, mode: .training)
    }

    var canLaunchSelectedGameLocally: Bool {
        guard let emulator = selectedChannel?.launchEmulator else {
            return false
        }

        return launcher.canLaunchLocalGame(emulator: emulator)
    }

    var selectedLocalLaunchUnavailableText: String? {
        guard let emulator = selectedChannel?.launchEmulator,
              !canLaunchSelectedGameLocally else {
            return nil
        }

        return "Native \(emulator) runtime not installed"
    }

    var selectedHasLocalROM: Bool {
        guard let emulator = selectedChannel?.launchEmulator,
              let gameID = selectedChannel?.launchGameID else {
            return false
        }

        return launcher.hasLocalROM(emulator: emulator, gameID: gameID)
    }
}

enum GameLaunchMode {
    case checkROM
    case test
    case training
}
