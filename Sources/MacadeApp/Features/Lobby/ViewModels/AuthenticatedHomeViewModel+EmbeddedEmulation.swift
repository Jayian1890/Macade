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
}
