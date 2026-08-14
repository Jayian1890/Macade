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

    func canLaunchFightcadeGame(
        _ capability: FightcadeRuntimeCapability,
        emulator: String,
        gameID: String
    ) -> Bool {
        launcher.canLaunchFightcadeGame(capability, emulator: emulator, gameID: gameID)
    }

    func canLaunchFightcadeGame(_ capability: FightcadeRuntimeCapability, in channel: FightcadeChannel) -> Bool {
        guard let emulator = channel.launchEmulator,
              let gameID = channel.launchGameID else {
            return false
        }

        return canLaunchFightcadeGame(capability, emulator: emulator, gameID: gameID)
    }

    func canAcceptIncomingChallenge(_ challenge: FightcadeChallenge) -> Bool {
        guard let channel = challengeChannel(for: challenge) else {
            return false
        }

        return canLaunchFightcadeGame(.fightcadeMatch, in: channel)
    }

    func canOpenFightcadeReplay(_ link: FightcadeReplayLink) -> Bool {
        canLaunchFightcadeGame(
            .fightcadeSpectate,
            emulator: link.emulator,
            gameID: link.gameID
        )
    }

    func challengeChannel(for challenge: FightcadeChallenge) -> FightcadeChannel? {
        channels.first {
            $0.id.compare(challenge.channelName, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
                || $0.name.compare(challenge.channelName, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
        }
    }

    func unavailableFightcadeLaunchMessage(for channel: FightcadeChannel) -> String {
        "Fightcade play is unavailable for \(channel.title). Install its local ROM and a runtime that supports this route."
    }
}

enum GameLaunchMode {
    case checkROM
    case test
    case training
}
