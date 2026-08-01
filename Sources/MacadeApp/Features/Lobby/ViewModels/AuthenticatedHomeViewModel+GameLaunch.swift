import Foundation

extension AuthenticatedHomeViewModel {
    func launchGame(for channel: FightcadeChannel, mode: GameLaunchMode) {
        guard let emulator = channel.launchEmulator,
              let gameID = channel.launchGameID else {
            errorMessage = FightcadeLaunchError.missingGame.localizedDescription
            return
        }

        Task { @MainActor in
            isLaunchingGame = true
            defer { isLaunchingGame = false }

            do {
                switch mode {
                case .checkROM:
                    try await launcher.open(.checkROM(emulator: emulator, gameID: gameID))
                    appendSystemMessage("ROM found for \(gameID)", channelName: channel.name)
                case .test:
                    activeMatchOpponentUsername = nil
                    activeMatchOpponentChannelName = nil
                    activeEmulationSession?.stop()
                    activeEmulationSession = try await launcher.openEmbedded(
                        .test(channelID: channel.id, emulator: emulator, gameID: gameID)
                    )
                    appendSystemMessage("Launched \(emulator) for \(gameID)", channelName: channel.name)
                case .training:
                    activeMatchOpponentUsername = nil
                    activeMatchOpponentChannelName = nil
                    activeEmulationSession?.stop()
                    activeEmulationSession = try await launcher.openEmbedded(
                        .training(channelID: channel.id, emulator: emulator, gameID: gameID)
                    )
                    appendSystemMessage("Launched training for \(gameID)", channelName: channel.name)
                }
            } catch let error as FightcadeLaunchError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not launch game."
            }
        }
    }

    func launchMatch(_ start: FightcadeMatchStart) {
        guard let channel = channels.first(where: { $0.name == start.channelName }),
              let emulator = channel.launchEmulator,
              let gameID = start.gameID?.nonEmpty ?? channel.launchGameID else {
            errorMessage = FightcadeLaunchError.missingGame.localizedDescription
            return
        }

        Task { @MainActor in
            isLaunchingGame = true
            defer { isLaunchingGame = false }

            do {
                let match = FightcadeMatchLaunch(
                    emulator: emulator,
                    gameID: gameID,
                    quarkID: start.quarkID,
                    playerID: start.playerID,
                    port: start.port,
                    delay: start.delay,
                    ranked: start.ranked,
                    token: start.token
                )
                activeEmulationSession?.stop()
                activeEmulationSession = try await launcher.openEmbedded(
                    .match(channelID: channel.id, match: match)
                )
                appendSystemMessage("Launched match for \(gameID)", channelName: channel.name)
            } catch let error as FightcadeLaunchError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not launch game."
            }
        }
    }
}
