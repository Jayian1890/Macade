import Foundation

extension AuthenticatedHomeViewModel {
    func canChallenge(_ user: FightcadeChannelUser) -> Bool {
        guard let selectedChannel else {
            return false
        }

        return canChallenge(user, in: selectedChannel)
    }

    func canChallenge(_ user: FightcadeChannelUser, in channel: FightcadeChannel) -> Bool {
        guard joinedChannelIDs.contains(channel.id) else {
            return false
        }

        return !isSendingChallenge
            && !hasOutgoingChallenge(for: user, in: channel)
            && !hasIncomingChallenge(from: user, in: channel)
            && user.name.caseInsensitiveCompare(session.displayName) != .orderedSame
            && !user.isAway
            && !user.isPlaying
    }

    func canChallenge(_ username: String, in channel: FightcadeChannel) -> Bool {
        guard let user = challengeableUser(named: username, in: channel) else {
            return false
        }

        return canChallenge(user, in: channel)
    }

    func isChallenging(_ user: FightcadeChannelUser, in channel: FightcadeChannel) -> Bool {
        hasOutgoingChallenge(for: user, in: channel)
    }

    func isChallenging(_ username: String, in channel: FightcadeChannel) -> Bool {
        outgoingChallenges.contains {
            $0.channelName == channel.name
                && $0.username.caseInsensitiveCompare(username) == .orderedSame
        }
    }

    func challenge(_ user: FightcadeChannelUser, in channel: FightcadeChannel, ranked: Int = FightcadeChallenge.defaultRankedValue) {
        guard canChallenge(user, in: channel) else {
            return
        }

        isSendingChallenge = true
        errorMessage = nil

        Task {
            defer { isSendingChallenge = false }

            do {
                let challenge = try await lobbyService.challenge(user, in: channel, ranked: ranked)
                rememberOutgoingChallenge(challenge)
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not send challenge."
            }
        }
    }

    func challenge(_ username: String, in channel: FightcadeChannel, ranked: Int = FightcadeChallenge.defaultRankedValue) {
        guard let user = challengeableUser(named: username, in: channel) else {
            return
        }

        challenge(user, in: channel, ranked: ranked)
    }

    func openChallengeChannel(_ challenge: FightcadeChallenge) {
        selectedChannelID = challenge.channelName
        isShowingChannelBrowser = false
    }

    var activeIncomingChallenge: FightcadeChallenge? {
        incomingChallenges.first
    }

    var activeOutgoingChallenge: FightcadeChallenge? {
        outgoingChallenges.first
    }

    func user(for challenge: FightcadeChallenge) -> FightcadeChannelUser? {
        usersByChannel[challenge.channelName]?.first {
            $0.name.compare(challenge.username, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
        }
    }

    func user(named username: String, in channel: FightcadeChannel) -> FightcadeChannelUser? {
        usersByChannel[channel.name]?.first {
            $0.name.compare(username, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
        }
    }

    func acceptIncomingChallenge() {
        guard let challenge = activeIncomingChallenge else {
            return
        }

        acceptIncomingChallenge(challenge)
    }

    func acceptIncomingChallenge(_ challenge: FightcadeChallenge) {
        guard incomingChallenges.contains(where: { $0.id == challenge.id }) else {
            return
        }

        rememberMatchOpponent(challenge)
        isSendingChallenge = true
        errorMessage = nil

        Task {
            defer { isSendingChallenge = false }

            do {
                try await lobbyService.acceptChallenge(challenge)
                await settleChallenges(afterAccepting: challenge)
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not accept challenge."
            }
        }
    }

    func rejectIncomingChallenge() {
        guard let challenge = activeIncomingChallenge else {
            return
        }

        rejectIncomingChallenge(challenge)
    }

    func rejectIncomingChallenge(_ challenge: FightcadeChallenge) {
        guard incomingChallenges.contains(where: { $0.id == challenge.id }) else {
            return
        }

        isSendingChallenge = true
        errorMessage = nil

        Task {
            defer { isSendingChallenge = false }

            do {
                try await lobbyService.rejectChallenge(challenge)
                incomingChallenges.removeAll { $0.id == challenge.id }
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not reject challenge."
            }
        }
    }

    func cancelOutgoingChallenge() {
        guard let challenge = activeOutgoingChallenge else {
            return
        }

        cancelOutgoingChallenge(challenge)
    }

    func cancelOutgoingChallenge(_ challenge: FightcadeChallenge) {
        guard outgoingChallenges.contains(where: { $0.id == challenge.id }) else {
            return
        }

        isSendingChallenge = true
        errorMessage = nil

        Task {
            defer { isSendingChallenge = false }

            do {
                try await lobbyService.cancelChallenge(challenge)
                outgoingChallenges.removeAll { $0.id == challenge.id }
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not cancel challenge."
            }
        }
    }

    private func challengeableUser(named username: String, in channel: FightcadeChannel) -> FightcadeChannelUser? {
        user(named: username, in: channel)
    }

    func clearChallenge(_ challenge: FightcadeChallenge) {
        incomingChallenges.removeAll { $0.id == challenge.id }
        outgoingChallenges.removeAll { $0.id == challenge.id }
    }

    func clearChallenges() {
        incomingChallenges.removeAll()
        outgoingChallenges.removeAll()
    }

    func rememberIncomingChallenge(_ challenge: FightcadeChallenge) {
        incomingChallenges.removeAll { $0.id == challenge.id }
        incomingChallenges.insert(challenge, at: 0)
    }

    func rememberOutgoingChallenge(_ challenge: FightcadeChallenge) {
        outgoingChallenges.removeAll {
            $0.id == challenge.id
                || ($0.channelName == challenge.channelName
                    && $0.username.caseInsensitiveCompare(challenge.username) == .orderedSame)
        }
        outgoingChallenges.insert(challenge, at: 0)
    }

    func matchOpponentUsername(for start: FightcadeMatchStart) -> String? {
        if activeMatchOpponentChannelName == start.channelName,
           let activeMatchOpponentUsername {
            return activeMatchOpponentUsername
        }

        if let challenge = (incomingChallenges + outgoingChallenges).first(where: { $0.channelName == start.channelName }) {
            return challenge.username
        }

        return nil
    }

    func rememberMatchOpponent(_ challenge: FightcadeChallenge) {
        activeMatchOpponentUsername = challenge.username
        activeMatchOpponentChannelName = challenge.channelName
    }

    func rememberMatchOpponent(for start: FightcadeMatchStart) {
        if let username = matchOpponentUsername(for: start) {
            activeMatchOpponentUsername = username
            requestPlayerListFocus(username: username, channelName: start.channelName, selectChannel: true)
        } else if activeMatchOpponentChannelName != start.channelName {
            activeMatchOpponentUsername = nil
        }

        activeMatchOpponentChannelName = start.channelName
    }

    func isOutgoingChallengeEcho(_ challenge: FightcadeChallenge) -> Bool {
        outgoingChallenges.contains {
            $0.id == challenge.id
                && $0.username.caseInsensitiveCompare(challenge.username) == .orderedSame
                && $0.channelName == challenge.channelName
        }
    }

    func handleChallengeWarning(_ warning: FightcadeChallengeWarning) {
        clearChallengeWarningTarget(warning)
        errorMessage = warning.message

        let channelName = warning.channelName ?? selectedChannel?.name ?? activeOutgoingChallenge?.channelName
        if let channelName {
            appendSystemMessage(warning.message, channelName: channelName)
        }
    }

    func settleChallenges(afterAccepting acceptedChallenge: FightcadeChallenge) async {
        guard isKnownChallenge(acceptedChallenge) else {
            clearChallenge(acceptedChallenge)
            return
        }

        let outgoingToCancel = outgoingChallenges.filter { $0.id != acceptedChallenge.id }
        let incomingToReject = incomingChallenges.filter { $0.id != acceptedChallenge.id }

        incomingChallenges.removeAll { $0.id != acceptedChallenge.id }
        outgoingChallenges.removeAll { $0.id != acceptedChallenge.id }

        for challenge in outgoingToCancel {
            try? await lobbyService.cancelChallenge(challenge)
        }

        for challenge in incomingToReject {
            try? await lobbyService.rejectChallenge(challenge)
        }

        incomingChallenges.removeAll { $0.id == acceptedChallenge.id }
        outgoingChallenges.removeAll { $0.id == acceptedChallenge.id }
    }

    private func isKnownChallenge(_ challenge: FightcadeChallenge) -> Bool {
        incomingChallenges.contains { $0.id == challenge.id }
            || outgoingChallenges.contains { $0.id == challenge.id }
    }

    private func clearChallengeWarningTarget(_ warning: FightcadeChallengeWarning) {
        if let challengeID = warning.challengeID {
            incomingChallenges.removeAll { $0.challengeID == challengeID }
            outgoingChallenges.removeAll { $0.challengeID == challengeID }
            return
        }

        if let username = warning.username, let channelName = warning.channelName {
            outgoingChallenges.removeAll {
                $0.channelName == channelName
                    && $0.username.caseInsensitiveCompare(username) == .orderedSame
            }
            return
        }

        if let username = warning.username {
            outgoingChallenges.removeAll {
                $0.username.caseInsensitiveCompare(username) == .orderedSame
            }
            return
        }

        if let channelName = warning.channelName,
           let index = outgoingChallenges.firstIndex(where: { $0.channelName == channelName }) {
            outgoingChallenges.remove(at: index)
            return
        }

        if !outgoingChallenges.isEmpty {
            outgoingChallenges.removeFirst()
        }
    }

    private func hasOutgoingChallenge(for user: FightcadeChannelUser, in channel: FightcadeChannel) -> Bool {
        outgoingChallenges.contains {
            $0.channelName == channel.name
                && $0.username.caseInsensitiveCompare(user.name) == .orderedSame
        }
    }

    private func hasIncomingChallenge(from user: FightcadeChannelUser, in channel: FightcadeChannel) -> Bool {
        incomingChallenges.contains {
            $0.channelName == channel.name
                && $0.username.caseInsensitiveCompare(user.name) == .orderedSame
        }
    }
}
