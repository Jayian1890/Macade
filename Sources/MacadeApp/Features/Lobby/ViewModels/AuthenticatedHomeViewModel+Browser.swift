import Foundation

extension AuthenticatedHomeViewModel {
    var browserCategories: [FightcadeBrowserCategory] {
        let all = FightcadeBrowserCategory(
            kind: .all,
            title: "All",
            gameCount: channels.count,
            playerCount: channels.reduce(0) { $0 + ($1.playerCount ?? 0) }
        )
        let rankedChannels = channels.filter(\.isRanked)
        let ranked = FightcadeBrowserCategory(
            kind: .ranked,
            title: "Ranked",
            gameCount: rankedChannels.count,
            playerCount: rankedChannels.reduce(0) { $0 + ($1.playerCount ?? 0) }
        )
        let favoriteChannels = channels.filter(\.isFavorite)
        let favorites = FightcadeBrowserCategory(
            kind: .favorites,
            title: "Favorites",
            gameCount: favoriteChannels.count,
            playerCount: favoriteChannels.reduce(0) { $0 + ($1.playerCount ?? 0) }
        )
        let systems = Dictionary(grouping: channels) { channel in
            channel.system?.trimmingCharacters(in: .whitespacesAndNewlines).nonEmpty ?? "Unknown"
        }
        let systemCategories = systems.map { system, channels in
            FightcadeBrowserCategory(
                kind: .system(system),
                title: system,
                gameCount: channels.count,
                playerCount: channels.reduce(0) { $0 + ($1.playerCount ?? 0) }
            )
        }
        .sorted { lhs, rhs in
            if lhs.playerCount != rhs.playerCount { return lhs.playerCount > rhs.playerCount }
            if lhs.gameCount != rhs.gameCount { return lhs.gameCount > rhs.gameCount }
            return lhs.title.localizedCaseInsensitiveCompare(rhs.title) == .orderedAscending
        }

        return [all, ranked, favorites] + systemCategories
    }

    func applyBrowserCategory(_ category: FightcadeBrowserCategory) {
        switch category.kind {
        case .all:
            browser.mode = .all
            browser.selectedSystem = nil
        case .ranked:
            browser.mode = .ranked
            browser.selectedSystem = nil
        case .favorites:
            browser.mode = .favorites
            browser.selectedSystem = nil
        case .system(let system):
            browser.mode = .all
            browser.selectedSystem = system
        }
    }

    func isBrowserCategorySelected(_ category: FightcadeBrowserCategory) -> Bool {
        switch category.kind {
        case .all:
            browser.mode == .all && browser.selectedSystem == nil
        case .ranked:
            browser.mode == .ranked && browser.selectedSystem == nil
        case .favorites:
            browser.mode == .favorites && browser.selectedSystem == nil
        case .system(let system):
            browser.mode == .all && browser.selectedSystem == system
        }
    }

    func loadUpcomingEvents() {
        Task {
            do {
                upcomingEvents = try await lobbyService.loadUpcomingEvents(limit: 12)
            } catch {
                upcomingEvents = []
            }
        }
    }

    func searchBrowserRemotely() {
        let query = browser.query.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !query.isEmpty, !browser.isSearchingRemotely else {
            return
        }

        browser.isSearchingRemotely = true
        errorMessage = nil
        Task {
            defer { browser.isSearchingRemotely = false }

            do {
                let foundChannels = try await lobbyService.searchChannels(matching: query)
                let mergedChannels = channels.mergingKnownChannels(foundChannels)
                applyDashboard(FightcadeDashboard(
                    connectedUsername: dashboard?.connectedUsername ?? session.displayName,
                    welcomeMessage: dashboard?.welcomeMessage,
                    channels: mergedChannels,
                    browserSections: dashboard?.browserSections ?? []
                ), restoringJoinedChannels: false)
                saveChannelsToCache(mergedChannels)
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not search Fightcade."
            }
        }
    }

    func selectBrowserPreview(_ channel: FightcadeChannel) {
        browser.selectedPreviewChannelID = canonicalBrowserChannel(for: channel).id
    }

    func joinFromBrowser(_ channel: FightcadeChannel) {
        let channel = canonicalBrowserChannel(for: channel)
        browser.selectedPreviewChannelID = channel.id
        rememberChannel(channel)

        if joinedChannelIDs.contains(channel.id) {
            selectedChannelID = channel.id
            isShowingChannelBrowser = false
            isShowingGameplay = false
            isShowingChannelChat = false
            return
        }

        join(channel)
    }

    func isBrowserChannelSelected(_ channel: FightcadeChannel) -> Bool {
        guard let selectedPreviewChannelID = browser.selectedPreviewChannelID else {
            return false
        }

        return channel.id == selectedPreviewChannelID
            || canonicalBrowserChannel(for: channel).id == selectedPreviewChannelID
    }

    func isBrowserChannelJoined(_ channel: FightcadeChannel) -> Bool {
        joinedChannelIDs.contains(canonicalBrowserChannel(for: channel).id)
    }

    func clearBrowserFilters() {
        browser.resetFilters()
    }

    func toggleFavorite(_ channel: FightcadeChannel) {
        let channel = canonicalBrowserChannel(for: channel)
        let newValue = !channel.isFavorite
        Task {
            do {
                try await lobbyService.setFavorite(newValue, for: channel)
                replaceChannel(channel.withFavorite(newValue))
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not update favorite."
            }
        }
    }

    func toggleChannelChat() {
        isShowingChannelChat.toggle()
    }

    func startChannelRefreshLoop() {
        channelRefreshTask?.cancel()
        channelRefreshTask = Task { [weak self] in
            while !Task.isCancelled {
                try? await Task.sleep(for: .seconds(30))
                guard !Task.isCancelled else { return }

                do {
                    try await self?.lobbyService.refreshChannels()
                } catch {
                    continue
                }
            }
        }
    }

    func mergeUpdatedChannels(_ updatedChannels: [FightcadeChannel]) -> [FightcadeChannel] {
        channels.mergingLiveChannels(updatedChannels)
    }

    func updateChannelPlayerCount(channelName: String, count: Int) {
        guard let channel = channels.first(where: { $0.id == channelName || $0.name == channelName }) else {
            return
        }

        replaceChannel(channel.withPlayerCount(count))
    }

    private func replaceChannel(_ channel: FightcadeChannel) {
        guard let dashboard else {
            return
        }

        let updatedChannels = dashboard.channels.map { existing in
            existing.id == channel.id ? channel : existing
        }
        applyDashboard(FightcadeDashboard(
            connectedUsername: dashboard.connectedUsername,
            welcomeMessage: dashboard.welcomeMessage,
            channels: updatedChannels,
            browserSections: dashboard.browserSections.replacingChannel(channel),
            loadedAt: dashboard.loadedAt
        ), restoringJoinedChannels: false)
    }

    private func canonicalBrowserChannel(for channel: FightcadeChannel) -> FightcadeChannel {
        if let exactMatch = channels.first(where: { $0.id == channel.id || $0.name == channel.name }) {
            return exactMatch
        }

        if let gameID = channel.gameID?.nonEmpty,
           let gameMatch = channels.first(where: { $0.gameID == gameID }) {
            return gameMatch
        }

        return channels.first { $0.matchesBrowserChannel(channel) } ?? channel
    }
}

extension FightcadeChannel {
    func withPlayerCount(_ playerCount: Int?) -> FightcadeChannel {
        FightcadeChannel(
            id: id,
            name: name,
            title: title,
            gameID: gameID,
            system: system,
            emulator: emulator,
            playerCount: playerCount,
            spectatorCount: spectatorCount,
            isRanked: isRanked,
            isFavorite: isFavorite,
            supportsTraining: supportsTraining
        )
    }
}

private extension FightcadeChannel {
    func matchesBrowserChannel(_ channel: FightcadeChannel) -> Bool {
        id == channel.id
            || name == channel.name
            || (gameID?.nonEmpty != nil && gameID == channel.gameID)
            || !favoriteMatchKeys.isDisjoint(with: channel.favoriteMatchKeys)
    }
}

private extension Array where Element == FightcadeWelcomeSection {
    func replacingChannel(_ channel: FightcadeChannel) -> [FightcadeWelcomeSection] {
        map { section in
            FightcadeWelcomeSection(
                title: section.title,
                channels: section.channels.map { $0.matchesBrowserChannel(channel) ? channel : $0 },
                categories: section.categories,
                events: section.events
            )
        }
    }
}
