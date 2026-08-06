import Foundation

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
        let configuration = autoMatchConfiguration(for: channel)
        guard isAutoMatching(in: channel) else {
            return isJoinedForAutoMatch(channel)
                ? "Auto match within \(configuration.rankTolerance) rank, same country or under \(configuration.maximumPing) ms"
                : "Join this room to enable auto match"
        }

        switch autoMatchStatesByChannel[channel.name]?.status ?? .searching {
        case .idle, .searching:
            return "Auto match is searching"
        case .waiting(let usernames):
            return "Waiting for \(usernames.joined(separator: ", "))"
        case .noEligiblePlayers:
            return "No eligible auto match players"
        case .allEligiblePlayersTried:
            return "Eligible players are cooling down"
        case .currentUserUnavailable:
            return "Waiting for your roster entry"
        case .missingCurrentUserRank:
            return "Your rank is unavailable"
        case .paused(let reason):
            return reason
        }
    }

    func autoMatchOutcomeText(for channel: FightcadeChannel) -> String? {
        guard let state = autoMatchStatesByChannel[channel.name] else {
            return nil
        }

        return state.outcomes.summaryText
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

    @discardableResult
    func removeAutoMatchChallenge(_ challenge: FightcadeChallenge) -> Bool {
        guard var state = autoMatchStatesByChannel[challenge.channelName] else {
            return false
        }

        let wasActive = state.activeChallengeIDs.remove(challenge.id) != nil
        autoMatchStatesByChannel[challenge.channelName] = state
        return wasActive
    }

    func clearAutoMatchChallengeIDs() {
        for channelName in Array(autoMatchStatesByChannel.keys) {
            var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
            state.activeChallengeIDs.removeAll()
            state.managedChallengeIDs.removeAll()
            autoMatchStatesByChannel[channelName] = state
        }
    }

    func isAutoMatchManagedChallenge(_ challenge: FightcadeChallenge) -> Bool {
        guard let state = autoMatchStatesByChannel[challenge.channelName] else {
            return false
        }

        return state.activeChallengeIDs.contains(challenge.id)
            || state.managedChallengeIDs.contains(challenge.id)
    }

    @discardableResult
    func recordAutoMatchChallengeCanceled(_ challenge: FightcadeChallenge) -> Bool {
        recordAutoMatchChallengeOutcome(challenge, status: .searching, outcome: .canceled)
    }

    @discardableResult
    func recordAutoMatchChallengeRejected(_ challenge: FightcadeChallenge) -> Bool {
        recordAutoMatchChallengeOutcome(challenge, status: .searching, outcome: .rejected)
    }

    @discardableResult
    func recordAutoMatchChallengeAccepted(_ challenge: FightcadeChallenge) -> Bool {
        recordAutoMatchChallengeOutcome(challenge, status: .idle, outcome: .accepted, startsCooldown: false)
    }

    @discardableResult
    func recordAutoMatchChallengeWarning(
        _ warning: FightcadeChallengeWarning,
        clearedChallenges: [FightcadeChallenge]
    ) -> Bool {
        let autoMatchChallenges = clearedChallenges.filter(isAutoMatchManagedChallenge)
        guard !autoMatchChallenges.isEmpty else {
            return false
        }

        for challenge in autoMatchChallenges {
            _ = recordAutoMatchChallengeOutcome(challenge, status: .paused(warning.message), outcome: .failed)
        }

        return true
    }

    func cancelUnavailableAutoMatchChallenges(in channelName: String) {
        guard let state = autoMatchStatesByChannel[channelName], !state.activeChallengeIDs.isEmpty else {
            return
        }

        let users = usersByChannel[channelName] ?? []
        let unavailableChallenges = outgoingChallenges.filter { challenge in
            state.activeChallengeIDs.contains(challenge.id) && !canKeepAutoMatchChallenge(challenge, users: users)
        }
        guard !unavailableChallenges.isEmpty else {
            return
        }

        for challenge in unavailableChallenges {
            clearChallenge(challenge)
        }

        Task { [weak self, unavailableChallenges] in
            guard let self else { return }
            for challenge in unavailableChallenges {
                try? await lobbyService.cancelChallenge(challenge)
            }
        }
    }

    private func startAutoMatch(for channel: FightcadeChannel) {
        guard isJoinedForAutoMatch(channel), autoMatchTasksByChannel[channel.name] == nil else {
            return
        }

        var state = autoMatchStatesByChannel[channel.name] ?? FightcadeAutoMatchState()
        state.isEnabled = true
        state.activeChallengeIDs.removeAll()
        state.challengeCooldownsByUsername = activeCooldowns(in: state, now: .now)
        state.outcomes = FightcadeAutoMatchOutcomes()
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

            let configuration = autoMatchConfiguration(for: channelName)
            let attempt = makeAutoMatchAttempt(for: channel, configuration: configuration)
            guard !attempt.users.isEmpty else {
                updateAutoMatchStatus(attempt.status, channelName: channelName)
                await sleep(seconds: 5)
                continue
            }

            let sentChallenges = await sendAutoMatchChallenges(attempt.users, in: channel)
            guard !sentChallenges.isEmpty else {
                if case .paused = autoMatchStatesByChannel[channelName]?.status {
                    await sleep(seconds: 5)
                    continue
                }

                updateAutoMatchStatus(.noEligiblePlayers, channelName: channelName)
                await sleep(seconds: 5)
                continue
            }

            updateAutoMatchWaitingState(sentChallenges, channelName: channelName)
            await waitForAutoMatchChallengesToResolve(
                Set(sentChallenges.map(\.id)),
                channelName: channelName,
                timeoutSeconds: configuration.acceptanceTimeoutSeconds
            )
            guard !Task.isCancelled else { return }
            await cancelUnacceptedAutoMatchChallenges(sentChallenges, channelName: channelName)
        }
    }

    private func makeAutoMatchAttempt(
        for channel: FightcadeChannel,
        configuration: FightcadeAutoMatchConfiguration
    ) -> FightcadeAutoMatchAttempt {
        let state = pruneAutoMatchCooldowns(channelName: channel.name)
        let attempt = FightcadeAutoMatchPlanner(configuration: configuration).attempt(
            users: usersByChannel[channel.name] ?? [],
            session: session,
            activeChallengeUsernames: challengeBlockedUsernames(in: channel.name),
            challengedUsernames: Set(state.challengeCooldownsByUsername.keys)
        )

        var nextState = state
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
                recordAutoMatchSendFailure(username: user.name, channelName: channel.name, message: error.localizedDescription)
            } catch {
                recordAutoMatchSendFailure(username: user.name, channelName: channel.name, message: "Could not send auto match challenge.")
            }
        }
        return sentChallenges
    }

    private func waitForAutoMatchChallengesToResolve(
        _ challengeIDs: Set<String>,
        channelName: String,
        timeoutSeconds: Int
    ) async {
        for _ in 0..<timeoutSeconds {
            guard !Task.isCancelled else { return }

            let activeChallengeIDs = autoMatchStatesByChannel[channelName]?.activeChallengeIDs ?? []
            if activeChallengeIDs.isDisjoint(with: challengeIDs) {
                return
            }

            await sleep(seconds: 1)
        }
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
        switch state.status {
        case .paused:
            break
        default:
            state.status = .searching
        }
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
    }

    private func updateAutoMatchStatus(_ status: FightcadeAutoMatchStatus, channelName: String) {
        var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
        state.status = status
        autoMatchStatesByChannel[channelName] = state
    }

    private func rememberAutoMatchChallenge(_ challenge: FightcadeChallenge) {
        var state = autoMatchStatesByChannel[challenge.channelName] ?? FightcadeAutoMatchState()
        state.activeChallengeIDs.insert(challenge.id)
        state.managedChallengeIDs.insert(challenge.id)
        state.challengeCooldownsByUsername[normalizedUsername(challenge.username)] = cooldownExpiration(channelName: challenge.channelName)
        state.outcomes.invited += 1
        autoMatchStatesByChannel[challenge.channelName] = state
    }

    private func recordAutoMatchChallengeOutcome(
        _ challenge: FightcadeChallenge,
        status: FightcadeAutoMatchStatus,
        outcome: FightcadeAutoMatchOutcomeKind,
        startsCooldown: Bool = true
    ) -> Bool {
        guard var state = autoMatchStatesByChannel[challenge.channelName],
              state.activeChallengeIDs.contains(challenge.id) || state.managedChallengeIDs.contains(challenge.id) else {
            return false
        }

        state.activeChallengeIDs.remove(challenge.id)
        state.managedChallengeIDs.remove(challenge.id)
        if startsCooldown {
            state.challengeCooldownsByUsername[normalizedUsername(challenge.username)] = cooldownExpiration(channelName: challenge.channelName)
        }
        state.outcomes.record(outcome)
        state.status = status
        autoMatchStatesByChannel[challenge.channelName] = state
        return true
    }

    private func recordAutoMatchSendFailure(username: String, channelName: String, message: String) {
        var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
        state.challengeCooldownsByUsername[normalizedUsername(username)] = cooldownExpiration(channelName: channelName)
        state.outcomes.failed += 1
        state.status = .paused(message)
        autoMatchStatesByChannel[channelName] = state
    }

    private func canAutoMatchChallenge(_ user: FightcadeChannelUser, in channel: FightcadeChannel) -> Bool {
        isJoinedForAutoMatch(channel)
            && user.name.caseInsensitiveCompare(session.displayName) != .orderedSame
            && user.name.caseInsensitiveCompare(session.username) != .orderedSame
            && !user.isAway
            && !user.isPlaying
            && !challengeBlockedUsernames(in: channel.name).contains(normalizedUsername(user.name))
            && !isAutoMatchUserCoolingDown(user.name, channelName: channel.name)
    }

    private func canKeepAutoMatchChallenge(_ challenge: FightcadeChallenge, users: [FightcadeChannelUser]) -> Bool {
        guard let user = users.first(where: {
            normalizedUsername($0.name) == normalizedUsername(challenge.username)
        }) else {
            return false
        }

        return !user.isAway && !user.isPlaying
    }

    private func pruneAutoMatchCooldowns(channelName: String) -> FightcadeAutoMatchState {
        var state = autoMatchStatesByChannel[channelName] ?? FightcadeAutoMatchState()
        state.challengeCooldownsByUsername = activeCooldowns(in: state, now: .now)
        autoMatchStatesByChannel[channelName] = state
        return state
    }

    private func activeCooldowns(in state: FightcadeAutoMatchState, now: Date) -> [String: Date] {
        state.challengeCooldownsByUsername.filter { $0.value > now }
    }

    private func isAutoMatchUserCoolingDown(_ username: String, channelName: String) -> Bool {
        let state = pruneAutoMatchCooldowns(channelName: channelName)
        guard let expiresAt = state.challengeCooldownsByUsername[normalizedUsername(username)] else {
            return false
        }

        return expiresAt > .now
    }

    private func cooldownExpiration(channelName: String) -> Date {
        Date().addingTimeInterval(TimeInterval(autoMatchConfiguration(for: channelName).retryCooldownSeconds))
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
