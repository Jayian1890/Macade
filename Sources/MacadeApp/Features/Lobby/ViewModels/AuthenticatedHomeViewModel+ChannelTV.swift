import Foundation

struct ChannelTVMatchCandidate: Identifiable, Equatable {
    let id: String
    let title: String
    let user: FightcadeChannelUser
    let stream: FightcadeSpectatorStream
    let gameID: String
}

func channelTVMatchCandidates(
    in channel: FightcadeChannel,
    users: [FightcadeChannelUser],
    session: AuthSession
) -> [ChannelTVMatchCandidate] {
    guard channel.launchEmulator != nil else {
        return []
    }

    let channelGameID = channel.launchGameID
    let watchableUsers = users.filter { user in
        guard user.isPlaying,
              !user.isCurrentUser(session: session),
              let stream = user.stream else {
            return false
        }

        if let streamGameID = stream.gameID?.nonEmpty,
           let channelGameID,
           streamGameID.caseInsensitiveCompare(channelGameID) != .orderedSame {
            return false
        }

        return stream.gameID?.nonEmpty != nil || channelGameID != nil
    }
    let grouped = Dictionary(grouping: watchableUsers) { user in
        guard let stream = user.stream else { return user.id }
        return channelTVStreamIdentity(stream: stream, gameID: stream.gameID?.nonEmpty ?? channelGameID)
    }

    return grouped.values.compactMap { users in
        let sortedUsers = users.sorted { lhs, rhs in
            lhs.name.localizedCaseInsensitiveCompare(rhs.name) == .orderedAscending
        }
        guard let user = sortedUsers.first,
              let stream = user.stream,
              let gameID = stream.gameID?.nonEmpty ?? channelGameID else {
            return nil
        }

        return ChannelTVMatchCandidate(
            id: channelTVStreamIdentity(stream: stream, gameID: gameID),
            title: sortedUsers.prefix(2).map(\.name).joined(separator: " vs "),
            user: user,
            stream: stream,
            gameID: gameID
        )
    }
    .sorted { lhs, rhs in
        lhs.title.localizedCaseInsensitiveCompare(rhs.title) == .orderedAscending
    }
}

private func channelTVStreamIdentity(stream: FightcadeSpectatorStream, gameID: String?) -> String {
    "\(gameID ?? ""):\(baseChannelTVQuarkID(stream.quarkID)):\(stream.port)"
}

private func baseChannelTVQuarkID(_ quarkID: String) -> String {
    guard let dotIndex = quarkID.lastIndex(of: "."),
          quarkID[quarkID.index(after: dotIndex)...].allSatisfy(\.isNumber) else {
        return quarkID
    }

    return String(quarkID[..<dotIndex])
}

extension AuthenticatedHomeViewModel {
    func canStartChannelTV(in channel: FightcadeChannel) -> Bool {
        guard channel.launchEmulator != nil else {
            return false
        }

        if let activeEmulationSession,
           activeEmulationSession.mode == .match,
           activeEmulationSession.isActive {
            return false
        }

        return true
    }

    func showChannelTV(for channel: FightcadeChannel) {
        guard canStartChannelTV(in: channel) else {
            errorMessage = "Stop the active match before starting TV."
            return
        }

        selectedChannelID = channel.id
        isShowingChannelBrowser = false
        isShowingGameplay = false
        isShowingChannelTV = true
        isShowingChannelChat = false
        channelTVStatusText = "Finding spectatable matches..."
        startChannelTVLoop(for: channel.id)
    }

    func ensureChannelTVRunning(for channel: FightcadeChannel) {
        guard isShowingChannelTV, selectedChannelID == channel.id, channelTVTask == nil else {
            return
        }

        startChannelTVLoop(for: channel.id)
    }

    func stopChannelTV() {
        stopChannelTVSession(stoppingSession: true)
        isShowingChannelBrowser = false
        isShowingGameplay = false
    }

    func stopChannelTVSession(stoppingSession: Bool) {
        let wasRunningTV = isShowingChannelTV || channelTVTask != nil || channelTVCurrentStreamID != nil
        channelTVTask?.cancel()
        channelTVTask = nil
        channelTVCurrentStreamID = nil
        channelTVBlockedStreamIDs.removeAll()
        channelTVStatusText = nil
        isShowingChannelTV = false
        isShowingChannelChat = false

        if stoppingSession,
           wasRunningTV,
           activeEmulationSession?.mode == .spectate {
            activeEmulationSession?.stop()
            activeEmulationSession = nil
        }
    }

    var selectedChannelTVSession: FightcadeEmbeddedSession? {
        guard isShowingChannelTV,
              let selectedChannel,
              let activeEmulationSession,
              activeEmulationSession.channelID == selectedChannel.id,
              activeEmulationSession.mode == .spectate else {
            return nil
        }

        return activeEmulationSession
    }

    private func startChannelTVLoop(for channelID: FightcadeChannel.ID) {
        channelTVTask?.cancel()
        channelTVBlockedStreamIDs.removeAll()
        channelTVCurrentStreamID = nil
        channelTVTask = Task { [weak self] in
            await self?.runChannelTV(channelID: channelID)
        }
    }

    private func runChannelTV(channelID: FightcadeChannel.ID) async {
        while !Task.isCancelled {
            guard isShowingChannelTV, selectedChannelID == channelID else {
                return
            }

            guard let channel = channels.first(where: { $0.id == channelID }) else {
                channelTVStatusText = "Waiting for channel data..."
                await sleepBeforeNextTVAttempt(seconds: 3)
                continue
            }

            if let activeEmulationSession,
               activeEmulationSession.mode == .match,
               activeEmulationSession.isActive {
                channelTVStatusText = "Active match in progress."
                return
            }

            let candidates = channelTVMatchCandidates(
                in: channel,
                users: usersByChannel[channel.name] ?? [],
                session: session
            )
            guard !candidates.isEmpty else {
                channelTVBlockedStreamIDs.removeAll()
                channelTVStatusText = "No spectatable matches. Waiting for the next stream..."
                await sleepBeforeNextTVAttempt(seconds: 5)
                continue
            }

            guard let candidate = candidates.first(where: { !channelTVBlockedStreamIDs.contains($0.id) }) else {
                channelTVBlockedStreamIDs.removeAll()
                channelTVStatusText = "Cycling back through available streams..."
                await sleepBeforeNextTVAttempt(seconds: 4)
                continue
            }

            await launchChannelTV(candidate, in: channel)
        }
    }

    private func launchChannelTV(_ candidate: ChannelTVMatchCandidate, in channel: FightcadeChannel) async {
        guard let emulator = channel.launchEmulator else {
            channelTVStatusText = FightcadeLaunchError.missingGame.localizedDescription
            channelTVBlockedStreamIDs.insert(candidate.id)
            return
        }

        isLaunchingGame = true
        defer { isLaunchingGame = false }

        do {
            if let activeEmulationSession, activeEmulationSession.mode != .match {
                activeEmulationSession.stop()
            }
            activeMatchOpponentUsername = nil
            activeMatchOpponentChannelName = nil

            let session = try await launcher.openEmbedded(.spectate(
                channelID: channel.id,
                emulator: emulator,
                gameID: candidate.gameID,
                quarkID: candidate.stream.quarkID,
                port: candidate.stream.port
            ))
            guard !Task.isCancelled, isShowingChannelTV else {
                session.stop()
                return
            }

            activeEmulationSession = session
            channelTVCurrentStreamID = candidate.id
            selectedChannelID = channel.id
            channelTVStatusText = "Watching \(candidate.title)"
            appendSystemMessage("TV tuned to \(candidate.title)", channelName: channel.name)
            await waitForChannelTVSession(session, streamID: candidate.id)
        } catch let error as FightcadeLaunchError {
            errorMessage = error.localizedDescription
            channelTVStatusText = error.localizedDescription
            channelTVBlockedStreamIDs.insert(candidate.id)
            await sleepBeforeNextTVAttempt(seconds: 2)
        } catch {
            errorMessage = "Could not launch spectator."
            channelTVStatusText = "Could not launch spectator."
            channelTVBlockedStreamIDs.insert(candidate.id)
            await sleepBeforeNextTVAttempt(seconds: 2)
        }
    }

    private func waitForChannelTVSession(_ session: FightcadeEmbeddedSession, streamID: String) async {
        while !Task.isCancelled,
              isShowingChannelTV,
              activeEmulationSession?.id == session.id {
            if !session.isActive || session.videoStream.overlaySnapshot()?.isMatchEnded == true {
                break
            }

            await sleepBeforeNextTVAttempt(milliseconds: 500)
        }

        guard !Task.isCancelled, isShowingChannelTV else {
            return
        }

        if activeEmulationSession?.id == session.id {
            session.stop()
            activeEmulationSession = nil
        }

        channelTVBlockedStreamIDs.insert(streamID)
        if channelTVCurrentStreamID == streamID {
            channelTVCurrentStreamID = nil
        }
        channelTVStatusText = "Finding the next spectatable match..."
    }

    private func sleepBeforeNextTVAttempt(seconds: Int) async {
        await sleepBeforeNextTVAttempt(milliseconds: seconds * 1_000)
    }

    private func sleepBeforeNextTVAttempt(milliseconds: Int) async {
        try? await Task.sleep(for: .milliseconds(milliseconds))
    }
}
