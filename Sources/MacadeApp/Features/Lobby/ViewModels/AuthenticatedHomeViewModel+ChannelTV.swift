extension AuthenticatedHomeViewModel {
    var fightcadeTVChannels: [FightcadeChannel] {
        channelTVChannels(from: joinedChannels)
    }

    var channelTVCurrentChannel: FightcadeChannel? {
        guard isShowingChannelTV else {
            return nil
        }

        let channels = fightcadeTVChannels
        if let selectedChannelID,
           let channel = channels.first(where: { $0.id == selectedChannelID }) {
            return channel
        }

        return channels.first
    }

    var canStartFightcadeTV: Bool {
        if let activeEmulationSession,
           activeEmulationSession.mode == .match,
           activeEmulationSession.isActive {
            return false
        }

        return !fightcadeTVChannels.isEmpty
    }

    var canTuneFightcadeTVChannel: Bool {
        fightcadeTVChannels.count > 1
    }

    var canTuneFightcadeTVMatch: Bool {
        channelTVCurrentCandidates.count > 1
    }

    var channelTVSidebarValue: String? {
        if isShowingChannelTV {
            return "live"
        }

        let count = fightcadeTVChannels.count
        return count > 0 ? "\(count)" : nil
    }

    var channelTVChannelPositionText: String? {
        let channels = fightcadeTVChannels
        guard let current = channelTVCurrentChannel,
              let index = channels.firstIndex(where: { $0.id == current.id }) else {
            return nil
        }

        return "\(index + 1)/\(channels.count)"
    }

    var channelTVMatchPositionText: String? {
        let candidates = channelTVCurrentCandidates
        guard let streamID = channelTVCurrentStreamID,
              let index = candidates.firstIndex(where: { $0.id == streamID }) else {
            return candidates.isEmpty ? nil : "--/\(candidates.count)"
        }

        return "\(index + 1)/\(candidates.count)"
    }

    var channelTVCurrentMatchTitle: String? {
        let candidates = channelTVCurrentCandidates
        guard let streamID = channelTVCurrentStreamID,
              let candidate = candidates.first(where: { $0.id == streamID }) else {
            return candidates.isEmpty ? nil : "Finding match"
        }

        return candidate.title
    }

    func showFightcadeTV() {
        guard canStartFightcadeTV else {
            errorMessage = fightcadeTVChannels.isEmpty
                ? "Join a room before starting Fightcade TV."
                : "Stop the active match before starting Fightcade TV."
            return
        }

        let channels = fightcadeTVChannels
        let channel = selectedChannelID.flatMap { selectedID in
            channels.first { $0.id == selectedID }
        } ?? channels.first
        guard let channel else { return }

        isShowingChannelBrowser = false
        isShowingGameplay = false
        isShowingChannelTV = true
        isShowingChannelChat = false
        selectedChannelID = channel.id
        channelTVStatusText = "Tuning \(channel.title)..."
        startChannelTVLoop(for: channel.id)
    }

    func showPreviousFightcadeTVChannel() {
        tuneFightcadeTVChannel(offset: -1)
    }

    func showNextFightcadeTVChannel() {
        tuneFightcadeTVChannel(offset: 1)
    }

    func showPreviousFightcadeTVMatch() {
        tuneFightcadeTVMatch(offset: -1)
    }

    func showNextFightcadeTVMatch() {
        tuneFightcadeTVMatch(offset: 1)
    }

    func ensureChannelTVRunning(for channel: FightcadeChannel) {
        guard isShowingChannelTV,
              selectedChannelID == channel.id,
              channelTVTask == nil,
              channelTVCurrentStreamID?.hasPrefix("replay:") != true else {
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
           activeEmulationSession?.mode == .spectate || activeEmulationSession?.mode == .replay {
            activeEmulationSession?.stop()
            activeEmulationSession = nil
        }
    }

    var selectedChannelTVSession: FightcadeEmbeddedSession? {
        guard isShowingChannelTV,
              let channel = channelTVCurrentChannel,
              let activeEmulationSession,
              activeEmulationSession.channelID == channel.id,
              activeEmulationSession.mode == .spectate || activeEmulationSession.mode == .replay else {
            return nil
        }

        return activeEmulationSession
    }

    private func tuneFightcadeTVChannel(offset: Int) {
        guard canStartFightcadeTV else {
            errorMessage = fightcadeTVChannels.isEmpty
                ? "Join a room before starting Fightcade TV."
                : "Stop the active match before changing Fightcade TV channels."
            return
        }

        let channels = fightcadeTVChannels
        guard !channels.isEmpty else { return }

        let currentIndex = selectedChannelID.flatMap { selectedID in
            channels.firstIndex { $0.id == selectedID }
        } ?? 0
        let nextIndex = (currentIndex + offset + channels.count) % channels.count
        let channel = channels[nextIndex]

        if let activeEmulationSession, activeEmulationSession.mode != .match {
            activeEmulationSession.stop()
            self.activeEmulationSession = nil
        }

        isShowingChannelBrowser = false
        isShowingGameplay = false
        isShowingChannelTV = true
        isShowingChannelChat = false
        selectedChannelID = channel.id
        channelTVStatusText = "Tuning \(channel.title)..."
        startChannelTVLoop(for: channel.id)
    }

    private var channelTVCurrentCandidates: [ChannelTVMatchCandidate] {
        guard let channel = channelTVCurrentChannel else { return [] }
        return channelTVMatchCandidates(
            in: channel,
            users: usersByChannel[channel.name] ?? [],
            session: session
        )
    }

    private func tuneFightcadeTVMatch(offset: Int) {
        guard canStartFightcadeTV else {
            errorMessage = fightcadeTVChannels.isEmpty
                ? "Join a room before starting Fightcade TV."
                : "Stop the active match before changing Fightcade TV matches."
            return
        }

        guard let channel = channelTVCurrentChannel else { return }
        let candidates = channelTVCurrentCandidates
        guard !candidates.isEmpty else {
            channelTVStatusText = "No spectatable matches. Waiting for the next stream..."
            return
        }

        let currentIndex = channelTVCurrentStreamID.flatMap { streamID in
            candidates.firstIndex { $0.id == streamID }
        }
        let nextIndex: Int
        if let currentIndex {
            nextIndex = (currentIndex + offset + candidates.count) % candidates.count
        } else {
            nextIndex = offset < 0 ? candidates.count - 1 : 0
        }

        if let activeEmulationSession, activeEmulationSession.mode != .match {
            activeEmulationSession.stop()
            self.activeEmulationSession = nil
        }

        isShowingChannelBrowser = false
        isShowingGameplay = false
        isShowingChannelTV = true
        isShowingChannelChat = false
        selectedChannelID = channel.id
        channelTVStatusText = "Tuning \(candidates[nextIndex].title)..."
        startChannelTVLoop(for: channel.id, initialStreamID: candidates[nextIndex].id)
    }

    private func startChannelTVLoop(for channelID: FightcadeChannel.ID, initialStreamID: String? = nil) {
        channelTVTask?.cancel()
        channelTVBlockedStreamIDs.removeAll()
        channelTVCurrentStreamID = nil
        channelTVTask = Task { [weak self] in
            await self?.runChannelTV(channelID: channelID, initialStreamID: initialStreamID)
        }
    }

    private func runChannelTV(channelID: FightcadeChannel.ID, initialStreamID: String?) async {
        var initialStreamID = initialStreamID

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
                if switchToNextChannelWithMatches(after: channelID) {
                    return
                }

                channelTVBlockedStreamIDs.removeAll()
                channelTVStatusText = "No spectatable matches. Waiting for the next stream..."
                await sleepBeforeNextTVAttempt(seconds: 5)
                continue
            }

            let candidate = initialStreamID.flatMap { streamID in
                candidates.first { $0.id == streamID }
            } ?? channelTVRandomCandidate(from: candidates, blockedIDs: channelTVBlockedStreamIDs)
            initialStreamID = nil

            guard let candidate else {
                if switchToNextChannelWithMatches(after: channelID) {
                    return
                }

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

    private func switchToNextChannelWithMatches(after channelID: FightcadeChannel.ID) -> Bool {
        let channels = fightcadeTVChannels
        guard channels.count > 1,
              let currentIndex = channels.firstIndex(where: { $0.id == channelID }) else {
            return false
        }

        for offset in 1..<channels.count {
            let channel = channels[(currentIndex + offset) % channels.count]
            guard !channelTVMatchCandidates(
                in: channel,
                users: usersByChannel[channel.name] ?? [],
                session: session
            ).isEmpty else {
                continue
            }

            if let activeEmulationSession, activeEmulationSession.mode != .match {
                activeEmulationSession.stop()
                self.activeEmulationSession = nil
            }
            selectedChannelID = channel.id
            channelTVBlockedStreamIDs.removeAll()
            channelTVCurrentStreamID = nil
            channelTVStatusText = "Tuning \(channel.title)..."
            startChannelTVLoop(for: channel.id)
            return true
        }

        return false
    }

    private func sleepBeforeNextTVAttempt(seconds: Int) async {
        await sleepBeforeNextTVAttempt(milliseconds: seconds * 1_000)
    }

    private func sleepBeforeNextTVAttempt(milliseconds: Int) async {
        try? await Task.sleep(for: .milliseconds(milliseconds))
    }
}
