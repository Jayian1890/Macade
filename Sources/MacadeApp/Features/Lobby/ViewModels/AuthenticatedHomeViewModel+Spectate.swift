import Foundation

extension AuthenticatedHomeViewModel {
    func applyLiveStreamUpdate(_ update: FightcadeLiveStreamUpdate) {
        let targetChannels = targetChannelNames(channelName: update.channelName, gameID: update.stream.gameID)
        let playerNames = Set(update.players.map { normalizedUsername($0) })

        for channelName in targetChannels {
            guard var users = usersByChannel[channelName] else {
                continue
            }

            var changed = false
            for index in users.indices where playerNames.contains(normalizedUsername(users[index].name)) {
                let user = users[index]
                users[index] = FightcadeChannelUser(
                    id: user.id,
                    name: user.name,
                    gravatarHash: user.gravatarHash,
                    countryCode: user.countryCode,
                    ping: user.ping,
                    virtualPing: user.virtualPing,
                    rank: user.rank,
                    matchCount: user.matchCount,
                    rankedSetting: user.rankedSetting,
                    region: user.region,
                    isAway: user.isAway,
                    isPlaying: true,
                    isUsingWifi: user.isUsingWifi,
                    isUsingProxy: user.isUsingProxy,
                    preventsBadChallenges: user.preventsBadChallenges,
                    preventsWifiChallenges: user.preventsWifiChallenges,
                    stream: update.stream
                )
                changed = true
            }

            if changed {
                usersByChannel[channelName] = users
            }
        }
    }

    func canSpectate(_ user: FightcadeChannelUser, in channel: FightcadeChannel) -> Bool {
        guard user.isPlaying,
              !user.isCurrentUser(session: session),
              user.stream != nil,
              channel.launchEmulator != nil else {
            return false
        }

        if let streamGameID = user.stream?.gameID?.nonEmpty,
           let channelGameID = channel.launchGameID,
           streamGameID.caseInsensitiveCompare(channelGameID) != .orderedSame {
            return false
        }

        return user.stream?.gameID?.nonEmpty != nil || channel.launchGameID != nil
    }

    func spectate(_ user: FightcadeChannelUser, in channel: FightcadeChannel) {
        guard canSpectate(user, in: channel),
              let stream = user.stream,
              let emulator = channel.launchEmulator,
              let gameID = stream.gameID?.nonEmpty ?? channel.launchGameID else {
            errorMessage = FightcadeLaunchError.missingGame.localizedDescription
            return
        }

        Task { @MainActor in
            isLaunchingGame = true
            defer { isLaunchingGame = false }

            do {
                activeMatchOpponentUsername = nil
                activeMatchOpponentChannelName = nil
                activeEmulationSession?.stop()
                activeEmulationSession = try await launcher.openEmbedded(.spectate(
                    channelID: channel.id,
                    emulator: emulator,
                    gameID: gameID,
                    quarkID: stream.quarkID,
                    port: stream.port
                ))
                selectedChannelID = channel.id
                requestPlayerListFocus(username: user.name, channelName: channel.name)
                showGameplay()
                appendSystemMessage("Watching \(user.name)'s match for \(gameID)", channelName: channel.name)
            } catch let error as FightcadeLaunchError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not launch spectator."
            }
        }
    }

    private func normalizedUsername(_ value: String) -> String {
        value.folding(options: [.caseInsensitive, .diacriticInsensitive], locale: nil).lowercased()
    }
}
