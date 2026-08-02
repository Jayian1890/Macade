import Foundation

extension AuthenticatedHomeViewModel {
    func toggleAutoMatch(for channel: FightcadeChannel) {
        if isAutoMatching(in: channel) {
            stopAutoMatch(in: channel.name, reason: "Auto match disabled.", cancelsOutstandingChallenges: true)
        } else {
            startAutoMatch(for: channel)
        }
    }

    func isAutoMatching(in channel: FightcadeChannel) -> Bool {
        autoMatchStatesByChannel[channel.name]?.isEnabled == true
    }

    func canToggleAutoMatch(for channel: FightcadeChannel) -> Bool {
        isAutoMatching(in: channel) || isJoinedForAutoMatch(channel)
    }

    func autoMatchHelpText(for channel: FightcadeChannel) -> String {
        guard isAutoMatching(in: channel) else {
            return isJoinedForAutoMatch(channel)
                ? "Auto match players within one rank, same country or under 150 ms"
                : "Join this room to enable auto match"
        }

        switch autoMatchStatesByChannel[channel.name]?.status ?? .searching {
        case .idle, .searching:
            return "Auto match is searching"
        case .waiting(let usernames):
            return "Waiting for \(usernames.joined(separator: ", "))"
        case .noEligiblePlayers:
            return "No eligible auto match players"
        case .currentUserUnavailable:
            return "Waiting for your roster entry"
        case .missingCurrentUserRank:
            return "Your rank is unavailable"
        case .paused(let reason):
            return reason
        }
    }

    func stopAutoMatch(in channelName: String, reason: String? = nil, cancelsOutstandingChallenges: Bool = false) {
        let activeChallengeIDs = autoMatchStatesByChannel[channelName]?.activeChallengeIDs ?? []
        let challengesToCancel = outgoingChallenges.filter { activeChallengeIDs.contains($0.id) }

        autoMatchTasksByChannel[channelName]?.cancel()
        autoMatchTasksByChannel[channelName] = nil

        if cancelsOutstandingChallenges {
            Task { [weak self, challengesToCancel] in
                await self?.cancelAutoMatchChallenges(challengesToCancel)
            }
        }

        var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
        state.isEnabled = false
        state.activeChallengeIDs.removeAll()
        state.status = .idle
        autoMatchStatesByChannel[channelName] = state

        if let reason {
            appendSystemMessage(reason, channelName: channelName)
        }
    }

    func stopAllAutoMatch(cancelsOutstandingChallenges: Bool = false) {
        let channelNames = Set(autoMatchStatesByChannel.keys).union(autoMatchTasksByChannel.keys)
        for channelName in channelNames {
            stopAutoMatch(in: channelName, cancelsOutstandingChallenges: cancelsOutstandingChallenges)
        }
    }

    func removeAutoMatchChallenge(_ challenge: FightcadeChallenge) {
        var state = autoMatchStatesByChannel[challenge.channelName] ?? FightcadeAutoMatchState()
        state.activeChallengeIDs.remove(challenge.id)
        autoMatchStatesByChannel[challenge.channelName] = state
    }

    func clearAutoMatchChallengeIDs() {
        for channelName in Array(autoMatchStatesByChannel.keys) {
            var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
            state.activeChallengeIDs.removeAll()
            autoMatchStatesByChannel[channelName] = state
        }
    }

    private func startAutoMatch(for channel: FightcadeChannel) {
        guard isJoinedForAutoMatch(channel), autoMatchTasksByChannel[channel.name] == nil else {
            return
        }

        var state = autoMatchStatesByChannel[channel.name] ?? FightcadeAutoMatchState()
        state.isEnabled = true
        state.status = .searching
        autoMatchStatesByChannel[channel.name] = state
        appendSystemMessage("Auto match enabled.", channelName: channel.name)

        autoMatchTasksByChannel[channel.name] = Task { [weak self] in
            await self?.runAutoMatchLoop(channel: channel)
        }
    }

    private func runAutoMatchLoop(channel: FightcadeChannel) async {
        let channelName = channel.name
        defer {
            autoMatchTasksByChannel[channelName] = nil
            if autoMatchStatesByChannel[channelName]?.isEnabled == true {
                var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
                state.isEnabled = false
                state.activeChallengeIDs.removeAll()
                state.status = .idle
                autoMatchStatesByChannel[channelName] = state
            }
        }

        while !Task.isCancelled, autoMatchStatesByChannel[channelName]?.isEnabled == true {
            guard isJoinedForAutoMatch(channel) else {
                stopAutoMatch(in: channelName, reason: "Auto match stopped because you left the room.", cancelsOutstandingChallenges: true)
                return
            }

            if isSendingChallenge {
                updateAutoMatchStatus(.paused("Waiting for the current challenge request."), channelName: channelName)
                await sleep(seconds: 2)
                continue
            }

            let attempt = makeAutoMatchAttempt(for: channel)
            guard !attempt.users.isEmpty else {
                updateAutoMatchStatus(attempt.status, channelName: channelName)
                await sleep(seconds: 5)
                continue
            }

            let sentChallenges = await sendAutoMatchChallenges(attempt.users, in: channel)
            guard !sentChallenges.isEmpty else {
                updateAutoMatchStatus(.noEligiblePlayers, channelName: channelName)
                await sleep(seconds: 5)
                continue
            }

            updateAutoMatchWaitingState(sentChallenges, channelName: channelName)
            await sleep(seconds: FightcadeAutoMatchConfiguration.default.acceptanceTimeoutSeconds)
            guard !Task.isCancelled else { return }
            await cancelUnacceptedAutoMatchChallenges(sentChallenges, channelName: channelName)
        }
    }

    private func makeAutoMatchAttempt(for channel: FightcadeChannel) -> FightcadeAutoMatchAttempt {
        let state = autoMatchStatesByChannel[channel.name] ?? FightcadeAutoMatchState()
        let blockedUsernames = challengeBlockedUsernames(in: channel.name)
        let attempt = FightcadeAutoMatchPlanner().attempt(
            users: usersByChannel[channel.name] ?? [],
            session: session,
            blockedUsernames: blockedUsernames,
            rotationIndex: state.rotationIndex
        )

        var nextState = state
        nextState.rotationIndex = attempt.nextRotationIndex
        nextState.status = attempt.status
        autoMatchStatesByChannel[channel.name] = nextState
        return attempt
    }

    private func sendAutoMatchChallenges(
        _ users: [FightcadeChannelUser],
        in channel: FightcadeChannel
    ) async -> [FightcadeChallenge] {
        var sentChallenges: [FightcadeChallenge] = []
        for user in users where canAutoMatchChallenge(user, in: channel) {
            do {
                let challenge = try await lobbyService.challenge(
                    user,
                    in: channel,
                    ranked: FightcadeChallenge.defaultRankedValue
                )
                rememberOutgoingChallenge(challenge)
                rememberAutoMatchChallenge(challenge)
                sentChallenges.append(challenge)
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
                updateAutoMatchStatus(.paused(error.localizedDescription), channelName: channel.name)
            } catch {
                errorMessage = "Could not send auto match challenge."
                updateAutoMatchStatus(.paused("Could not send auto match challenge."), channelName: channel.name)
            }
        }
        return sentChallenges
    }

    private func cancelUnacceptedAutoMatchChallenges(
        _ challenges: [FightcadeChallenge],
        channelName: String
    ) async {
        let challengeIDs = Set(challenges.map(\.id))
        let staleChallenges = outgoingChallenges.filter { challenge in
            challengeIDs.contains(challenge.id)
        }

        for challenge in staleChallenges {
            try? await lobbyService.cancelChallenge(challenge)
            clearChallenge(challenge)
        }

        var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
        state.activeChallengeIDs.subtract(challengeIDs)
        state.status = .searching
        autoMatchStatesByChannel[channelName] = state
    }

    private func cancelAutoMatchChallenges(_ challenges: [FightcadeChallenge]) async {
        for challenge in challenges {
            try? await lobbyService.cancelChallenge(challenge)
            clearChallenge(challenge)
        }
    }

    private func updateAutoMatchWaitingState(_ challenges: [FightcadeChallenge], channelName: String) {
        var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
        state.activeChallengeIDs = Set(challenges.map(\.id))
        state.status = .waiting(usernames: challenges.map(\.username))
        autoMatchStatesByChannel[channelName] = state
        appendSystemMessage("Auto match challenged \(challenges.map(\.username).joined(separator: ", ")).", channelName: channelName)
    }

    private func updateAutoMatchStatus(_ status: FightcadeAutoMatchStatus, channelName: String) {
        var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
        state.status = status
        autoMatchStatesByChannel[channelName] = state
    }

    private func rememberAutoMatchChallenge(_ challenge: FightcadeChallenge) {
        var state = autoMatchStatesByChannel[challenge.channelName] ?? FightcadeAutoMatchState()
        state.activeChallengeIDs.insert(challenge.id)
        autoMatchStatesByChannel[challenge.channelName] = state
    }

    private func canAutoMatchChallenge(_ user: FightcadeChannelUser, in channel: FightcadeChannel) -> Bool {
        isJoinedForAutoMatch(channel)
            && user.name.caseInsensitiveCompare(session.displayName) != .orderedSame
            && user.name.caseInsensitiveCompare(session.username) != .orderedSame
            && !user.isAway
            && !user.isPlaying
            && !challengeBlockedUsernames(in: channel.name).contains(normalizedUsername(user.name))
    }

    private func challengeBlockedUsernames(in channelName: String) -> Set<String> {
        Set((incomingChallenges + outgoingChallenges)
            .filter { $0.channelName == channelName }
            .map { normalizedUsername($0.username) })
    }

    private func isJoinedForAutoMatch(_ channel: FightcadeChannel) -> Bool {
        joinedChannelIDs.contains(channel.id) || joinedChannelIDs.contains(channel.name)
    }

    private func sleep(seconds: Int) async {
        try? await Task.sleep(for: .seconds(seconds))
    }

    private func normalizedUsername(_ username: String) -> String {
        username.folding(options: [.caseInsensitive, .diacriticInsensitive], locale: nil)
            .trimmingCharacters(in: .whitespacesAndNewlines)
            .lowercased()
    }
}
