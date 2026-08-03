import Foundation

extension AuthenticatedHomeViewModel {
    func openFightcadeReplay(_ link: FightcadeReplayLink, in channel: FightcadeChannel) {
        if let activeEmulationSession,
           activeEmulationSession.mode == .match,
           activeEmulationSession.isActive {
            errorMessage = "Stop the active match before opening a replay."
            return
        }

        channelTVTask?.cancel()
        channelTVTask = nil
        channelTVBlockedStreamIDs.removeAll()
        channelTVCurrentStreamID = "replay:\(link.id)"
        selectedChannelID = channel.id
        isShowingChannelBrowser = false
        isShowingGameplay = false
        isShowingChannelTV = true
        isShowingChannelChat = false
        channelTVStatusText = "Loading replay \(link.replayID)..."

        channelTVTask = Task { [weak self] in
            await self?.launchFightcadeReplay(link, in: channel)
        }
    }

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
                    showGameplay()
                    appendSystemMessage("Launched \(emulator) for \(gameID)", channelName: channel.name)
                case .training:
                    activeMatchOpponentUsername = nil
                    activeMatchOpponentChannelName = nil
                    activeEmulationSession?.stop()
                    activeEmulationSession = try await launcher.openEmbedded(
                        .training(channelID: channel.id, emulator: emulator, gameID: gameID)
                    )
                    showGameplay()
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
                stopChannelTVSession(stoppingSession: true)
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
                showGameplay()
                appendSystemMessage("Launched match for \(gameID)", channelName: channel.name)
            } catch let error as FightcadeLaunchError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not launch game."
            }
        }
    }

    private func launchFightcadeReplay(_ link: FightcadeReplayLink, in channel: FightcadeChannel) async {
        isLaunchingGame = true
        defer {
            isLaunchingGame = false
            channelTVTask = nil
        }

        do {
            if let activeEmulationSession,
               activeEmulationSession.mode != .match || !activeEmulationSession.isActive {
                activeEmulationSession.stop()
                self.activeEmulationSession = nil
            }
            activeMatchOpponentUsername = nil
            activeMatchOpponentChannelName = nil
            channelTVStatusText = "Tuning replay \(link.replayID)..."
            let session = try await launcher.openEmbedded(.replayStream(
                channelID: channel.id,
                launch: FightcadeReplayStreamLaunch(
                    emulator: link.emulator,
                    gameID: link.gameID,
                    quarkID: "\(link.replayID).7",
                    port: FightcadeReplayStreamLaunch.defaultPort
                )
            ))
            guard !Task.isCancelled, isShowingChannelTV else {
                session.stop()
                return
            }

            activeEmulationSession = session
            selectedChannelID = channel.id
            channelTVStatusText = "Playing replay \(link.replayID)"
            appendSystemMessage("Fightcade TV opened replay \(link.displayTitle)", channelName: channel.name)
            await waitForFightcadeReplaySession(session)
        } catch let error as FightcadeLaunchError {
            guard !Task.isCancelled else { return }
            errorMessage = error.localizedDescription
            channelTVStatusText = error.localizedDescription
        } catch {
            guard !Task.isCancelled else { return }
            errorMessage = "Could not open Fightcade replay."
            channelTVStatusText = "Could not open Fightcade replay."
        }
    }

    private func cachedFightcadeReplayURL(for link: FightcadeReplayLink) async throws -> URL {
        let directory = try fightcadeReplayCacheDirectory(for: link)
        let replayURL = directory.appendingPathComponent("\(link.replayID).fcreplay")
        if let size = try? replayURL.resourceValues(forKeys: [.fileSizeKey]).fileSize, size > 0 {
            return replayURL
        }

        var request = URLRequest(url: link.url, cachePolicy: .reloadIgnoringLocalCacheData, timeoutInterval: 45)
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")
        let (downloadURL, response) = try await URLSession.shared.download(for: request)
        guard let httpResponse = response as? HTTPURLResponse,
              (200..<300).contains(httpResponse.statusCode) else {
            throw URLError(.badServerResponse)
        }

        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        try? FileManager.default.removeItem(at: replayURL)
        try FileManager.default.moveItem(at: downloadURL, to: replayURL)
        return replayURL
    }

    private func fightcadeReplayCacheDirectory(for link: FightcadeReplayLink) throws -> URL {
        guard let root = FileManager.default.urls(for: .cachesDirectory, in: .userDomainMask).first else {
            throw URLError(.cannotCreateFile)
        }

        return root
            .appendingPathComponent("Macade")
            .appendingPathComponent("FightcadeReplays")
            .appendingPathComponent(link.emulator)
            .appendingPathComponent(link.gameID)
    }

    func waitForFightcadeReplaySession(_ session: FightcadeEmbeddedSession) async {
        while !Task.isCancelled,
              isShowingChannelTV,
              activeEmulationSession?.id == session.id,
              session.isActive {
            try? await Task.sleep(for: .milliseconds(500))
        }

        guard !Task.isCancelled, isShowingChannelTV else { return }
        if activeEmulationSession?.id == session.id {
            activeEmulationSession = nil
        }
        channelTVStatusText = "Replay ended."
    }
}
