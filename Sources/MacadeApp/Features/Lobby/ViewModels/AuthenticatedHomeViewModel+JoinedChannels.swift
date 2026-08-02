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
        selectFirstChannelIfNeeded(from: dashboard?.channels ?? loadedDashboard.channels)
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
        let knownChannels = dashboard.channels + dashboard.browserSections.flatMap(\.channels)
        guard !savedIDs.isEmpty else {
            if joiningServerChannels {
                isRestoringJoinedChannels = false
                restoringJoinedChannelCount = 0
            }
            return
        }

        var restoredIDs = Set<FightcadeChannel.ID>()
        let channels = savedIDs.compactMap { savedID -> FightcadeChannel? in
            guard let channel = channel(matching: savedID, in: knownChannels) ?? fallbackSavedChannel(for: savedID),
                  restoredIDs.insert(channel.id).inserted else {
                return nil
            }
            return channel
        }
        guard !channels.isEmpty else {
            if joiningServerChannels {
                isRestoringJoinedChannels = false
                restoringJoinedChannelCount = 0
            }
            return
        }

        rememberRestoredChannels(channels)
        selectedChannelID = channels.first?.id
        isShowingChannelBrowser = false

        guard joiningServerChannels else {
            return
        }

        restoringJoinedChannelCount = channels.count
        isRestoringJoinedChannels = true
        for channel in channels {
            join(channel, forcingServerJoin: true, restoringSavedChannel: true)
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

    private func channel(matching id: FightcadeChannel.ID, in channels: [FightcadeChannel]) -> FightcadeChannel? {
        if let channel = channels.first(where: { $0.id == id }) {
            return channel
        }

        let key = id.normalizedFightcadeFavoriteKey
        return channels.first { $0.favoriteMatchKeys.contains(key) }
    }

    private func fallbackSavedChannel(for id: FightcadeChannel.ID) -> FightcadeChannel? {
        let name = id.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !name.isEmpty else { return nil }
        return FightcadeChannel(
            id: name,
            name: name,
            title: name,
            gameID: nil,
            system: nil,
            emulator: nil,
            playerCount: nil,
            spectatorCount: nil,
            isRanked: false,
            isFavorite: false,
            supportsTraining: false
        )
    }

    private func rememberRestoredChannels(_ restoredChannels: [FightcadeChannel]) {
        guard let dashboard else { return }

        var knownIDs = Set(dashboard.channels.map(\.id))
        let missingChannels = restoredChannels.filter { knownIDs.insert($0.id).inserted }
        guard !missingChannels.isEmpty else { return }

        let channels = dashboard.channels + missingChannels
        self.dashboard = FightcadeDashboard(
            connectedUsername: dashboard.connectedUsername,
            welcomeMessage: dashboard.welcomeMessage,
            channels: channels,
            browserSections: dashboard.browserSections,
            loadedAt: dashboard.loadedAt
        )
        saveChannelsToCache(channels)
    }
}
