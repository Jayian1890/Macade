import Foundation

extension AuthenticatedHomeViewModel {
    func loadCachedChannelsIfAvailable(replacingCurrentDashboard: Bool) async {
        guard replacingCurrentDashboard || dashboard?.channels.isEmpty != false else {
            return
        }

        let cachedChannels = await channelCache.loadChannels(for: session)
        guard !cachedChannels.isEmpty else {
            return
        }

        applyDashboard(
            FightcadeDashboard(
                connectedUsername: dashboard?.connectedUsername ?? session.displayName,
                welcomeMessage: dashboard?.welcomeMessage,
                channels: cachedChannels
            ),
            restoringJoinedChannels: true,
            joiningRestoredChannels: false
        )
    }

    func applyDashboard(
        _ loadedDashboard: FightcadeDashboard,
        restoringJoinedChannels: Bool,
        joiningRestoredChannels: Bool = true
    ) {
        dashboard = loadedDashboard
        if restoringJoinedChannels {
            restoreJoinedChannels(from: loadedDashboard, joiningServerChannels: joiningRestoredChannels)
        }
        selectFirstChannelIfNeeded(from: loadedDashboard.channels)
    }

    func saveChannelsToCache(_ channels: [FightcadeChannel]) {
        let channelCache = channelCache
        let session = session
        Task {
            await channelCache.saveChannels(channels, for: session)
        }
    }

    func restoreJoinedChannels(from dashboard: FightcadeDashboard, joiningServerChannels: Bool) {
        let savedIDs = joinedChannelStore.joinedChannelIDs(for: session)
        guard !savedIDs.isEmpty else {
            return
        }

        let channelsByID = Dictionary(uniqueKeysWithValues: dashboard.channels.map { ($0.id, $0) })
        let channels = savedIDs.compactMap { channelsByID[$0] }
        guard !channels.isEmpty else {
            return
        }

        joinedChannelIDs.formUnion(channels.map(\.id))
        selectedChannelID = channels.first?.id
        isShowingChannelBrowser = false

        guard joiningServerChannels else {
            return
        }

        for channel in channels {
            join(channel, forcingServerJoin: true)
        }
    }

    func saveJoinedChannels() {
        let orderedIDs = channels.map(\.id).filter { joinedChannelIDs.contains($0) }
        let unknownIDs = joinedChannelIDs.filter { id in !orderedIDs.contains(id) }.sorted()
        joinedChannelStore.saveJoinedChannelIDs(orderedIDs + unknownIDs, for: session)
    }

    private func selectFirstChannelIfNeeded(from channels: [FightcadeChannel]) {
        guard selectedChannelID == nil || !channels.contains(where: { $0.id == selectedChannelID }) else {
            return
        }

        selectedChannelID = channels.first?.id
    }
}
