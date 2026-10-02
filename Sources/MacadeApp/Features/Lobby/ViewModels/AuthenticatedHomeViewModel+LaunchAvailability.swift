extension AuthenticatedHomeViewModel {
    func singlePlayerUnavailableReason(for channel: FightcadeChannel) -> String? {
        guard !isLaunchingGame, !isDownloadingROM, !isDeletingROM else { return "Game launch or ROM operation in progress." }
        if let session = activeEmulationSession, session.isActive,
           session.mode == .match || session.mode == .direct {
            return "Stop the active match before starting single player."
        }
        guard let emulator = channel.launchEmulator, let gameID = channel.launchGameID else {
            return FightcadeLaunchError.missingGame.localizedDescription
        }
        guard launcher.canLaunchLocalGame(emulator: emulator) else { return "Native \(emulator) runtime not installed." }
        guard launcher.hasLocalROM(emulator: emulator, gameID: gameID) else { return "Download this game's ROM from Resources first." }
        return nil
    }

    func launchSinglePlayer(in channel: FightcadeChannel) {
        guard !isLaunchingGame else { return }
        if let reason = singlePlayerUnavailableReason(for: channel) {
            errorMessage = reason
            return
        }
        launchGame(for: channel, mode: .singlePlayer)
    }

    func playerListRows(for users: [FightcadeChannelUser], in channel: FightcadeChannel) -> [PlayerListRowState] {
        // A roster redraw checks each runtime/game once, rather than once per
        // player. This snapshot is discarded immediately; actions revalidate.
        var availability: [PlayerListAvailabilityKey: Bool] = [:]
        func canLaunch(_ capability: FightcadeRuntimeCapability, emulator: String, gameID: String) -> Bool {
            let key = PlayerListAvailabilityKey(capability: capability, emulator: emulator, gameID: gameID)
            if let cached = availability[key] { return cached }
            let result = canLaunchFightcadeGame(capability, emulator: emulator, gameID: gameID)
            availability[key] = result
            return result
        }
        return users.map { user in
            PlayerListRowState(user: user, isCurrentUser: user.isCurrentUser(session: session),
                isChallengeable: canChallenge(user, in: channel) {
                    guard let emulator = channel.launchEmulator, let gameID = channel.launchGameID else { return false }
                    return canLaunch(.fightcadeMatch, emulator: emulator, gameID: gameID)
                }, isChallenging: isChallenging(user, in: channel),
                isWatchable: canSpectate(user, in: channel) { emulator, gameID in
                    canLaunch(.fightcadeSpectate, emulator: emulator, gameID: gameID)
                })
        }
    }

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
    case singlePlayer
    case checkROM
    case test
    case training
}

private struct PlayerListAvailabilityKey: Hashable {
    let capability: FightcadeRuntimeCapability
    let emulator: String
    let gameID: String
}
