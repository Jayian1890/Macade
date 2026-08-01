extension AuthenticatedHomeViewModel {
    var selectedEmulationSession: FightcadeEmbeddedSession? {
        guard let selectedChannel else {
            return nil
        }

        return activeEmulationSession?.channelID == selectedChannel.id ? activeEmulationSession : nil
    }

    var activeEmulationChannel: FightcadeChannel? {
        guard let activeEmulationSession else {
            return nil
        }

        return channels.first { $0.id == activeEmulationSession.channelID }
    }

    func stopActiveEmulationSession() {
        activeEmulationSession?.stop()
        activeEmulationSession = nil
        activeMatchOpponentUsername = nil
        activeMatchOpponentChannelName = nil
        isShowingChannelChat = false
        isShowingGameplay = false
    }

    func finishActiveMatchSession() {
        let channelName = activeMatchOpponentChannelName ?? selectedChannel?.name
        activeEmulationSession?.stop()
        activeEmulationSession = nil
        activeMatchOpponentUsername = nil
        activeMatchOpponentChannelName = nil
        isShowingChannelChat = false
        isShowingGameplay = false
        if let channelName {
            appendSystemMessage("Match ended", channelName: channelName)
        }
    }
}
