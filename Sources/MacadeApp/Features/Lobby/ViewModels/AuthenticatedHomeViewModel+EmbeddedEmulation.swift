extension AuthenticatedHomeViewModel {
    var selectedEmulationSession: FightcadeEmbeddedSession? {
        guard let selectedChannel else {
            return nil
        }

        return activeEmulationSession?.channelID == selectedChannel.id ? activeEmulationSession : nil
    }

    func stopActiveEmulationSession() {
        activeEmulationSession?.stop()
        activeEmulationSession = nil
        activeMatchOpponentUsername = nil
        activeMatchOpponentChannelName = nil
        isShowingChannelChat = false
    }

    func finishActiveMatchSession() {
        let channelName = activeMatchOpponentChannelName ?? selectedChannel?.name
        activeEmulationSession?.stop()
        activeEmulationSession = nil
        activeMatchOpponentUsername = nil
        activeMatchOpponentChannelName = nil
        isShowingChannelChat = false
        if let channelName {
            appendSystemMessage("Match ended", channelName: channelName)
        }
    }
}
