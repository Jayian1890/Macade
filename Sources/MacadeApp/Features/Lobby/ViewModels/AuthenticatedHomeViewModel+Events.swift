extension AuthenticatedHomeViewModel {
    func handle(_ event: FightcadeLobbyEvent) {
        switch event {
        case .channelsUpdated(let channels):
            let mergedChannels = mergeUpdatedChannels(channels)
            applyDashboard(FightcadeDashboard(
                connectedUsername: dashboard?.connectedUsername ?? session.displayName,
                welcomeMessage: dashboard?.welcomeMessage,
                channels: mergedChannels,
                browserSections: dashboard?.browserSections ?? []
            ), restoringJoinedChannels: false)
            saveChannelsToCache(mergedChannels)
        case .joinedChannel(let channelName):
            joinedChannelIDs.insert(channelName)
            saveJoinedChannels()
            let selectedChannelMissing = selectedChannelID.map { selectedID in
                !channels.contains { $0.id == selectedID }
            } ?? true
            if selectedChannelMissing || isShowingChannelBrowser {
                selectedChannelID = channelName
                isShowingChannelBrowser = false
            }
        case .leftChannel(let channelName):
            stopAutoMatch(in: channelName, cancelsOutstandingChallenges: true)
            joinedChannelIDs.remove(channelName)
            saveJoinedChannels()
            usersByChannel[channelName] = nil
            if selectedChannelID == channelName {
                if let nextChannel = joinedChannels.first {
                    selectedChannelID = nextChannel.id
                    isShowingChannelBrowser = false
                    isShowingGameplay = false
                } else {
                    isShowingChannelBrowser = true
                    isShowingGameplay = false
                }
            }
        case .usersUpdated(let channelName, let users):
            usersByChannel[channelName] = users.sorted(by: sortUsers)
            updateChannelPlayerCount(channelName: channelName, count: users.count)
            cancelUnavailableAutoMatchChallenges(in: channelName)
        case .userJoined(let channelName, let user):
            var users = usersByChannel[channelName] ?? []
            users.removeAll { $0.id == user.id }
            users.append(user)
            usersByChannel[channelName] = users.sorted(by: sortUsers)
            updateChannelPlayerCount(channelName: channelName, count: users.count)
        case .userLeft(let channelName, let username):
            usersByChannel[channelName]?.removeAll { $0.id == username }
            updateChannelPlayerCount(channelName: channelName, count: usersByChannel[channelName]?.count ?? 0)
            cancelUnavailableAutoMatchChallenges(in: channelName)
        case .userStatusUpdated(let update):
            applyUserStatusUpdate(update)
            for channelName in targetChannelNames(channelName: update.channelName, gameID: update.stream?.gameID) {
                cancelUnavailableAutoMatchChallenges(in: channelName)
            }
        case .liveStreamUpdated(let update):
            applyLiveStreamUpdate(update)
        case .chatMessage(let message):
            appendReceivedChatMessage(message)
        case .channelMotd(let motd):
            appendChannelMotd(motd)
        case .challengeReceived(let challenge):
            guard !isOutgoingChallengeEcho(challenge) else {
                break
            }

            playIncomingChallengeSound()
            rememberIncomingChallenge(challenge)
        case .challengeCanceled(let challenge):
            let isAutoMatchChallenge = recordAutoMatchChallengeCanceled(challenge)
            clearChallenge(challenge)
            if !isAutoMatchChallenge {
                appendSystemMessage("\(challenge.username) canceled the challenge", channelName: challenge.channelName)
            }
        case .challengeRejected(let challenge):
            let isAutoMatchChallenge = recordAutoMatchChallengeRejected(challenge)
            clearChallenge(challenge)
            if !isAutoMatchChallenge {
                appendSystemMessage("\(challenge.username) rejected the challenge", channelName: challenge.channelName)
            }
        case .challengeAccepted(let challenge):
            recordAutoMatchChallengeAccepted(challenge)
            stopAllAutoMatch()
            rememberMatchOpponent(challenge)
            Task { await settleChallenges(afterAccepting: challenge) }
            appendSystemMessage("\(challenge.username) accepted the challenge", channelName: challenge.channelName)
        case .challengeRestricted(let warning):
            handleChallengeWarning(warning)
        case .matchStarted(let start):
            stopAllAutoMatch()
            rememberMatchOpponent(for: start)
            clearChallenges()
            launchMatch(start)
        case .error(let message):
            errorMessage = message
        }
    }

    private func sortUsers(_ lhs: FightcadeChannelUser, _ rhs: FightcadeChannelUser) -> Bool {
        switch (lhs.ping, rhs.ping) {
        case let (left?, right?) where left != right:
            return left < right
        case (_?, nil):
            return true
        case (nil, _?):
            return false
        default:
            break
        }

        return lhs.name.localizedCaseInsensitiveCompare(rhs.name) == .orderedAscending
    }
}
