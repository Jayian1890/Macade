import Foundation

extension AuthenticatedHomeViewModel {
    var selectedBrowserChannel: FightcadeChannel? {
        guard let id = browser.selectedPreviewChannelID else {
            return browserChannels.first
        }

        return browserChannels.first { $0.id == id } ?? browserChannels.first
    }

    func loadBrowserFilterOptions() {
        guard !browser.isLoadingFilterOptions else {
            return
        }

        browser.isLoadingFilterOptions = true
        Task {
            defer { browser.isLoadingFilterOptions = false }

            do {
                let options = try await lobbyService.loadChannelFilterOptions()
                browser.filterOptions = options.withFallbackSystems(derivedSystems)
            } catch {
                browser.filterOptions = browser.filterOptions.withFallbackSystems(derivedSystems)
            }
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

    func scheduleBrowserSearch() {
        browser.searchTask?.cancel()
        browser.searchTask = Task { [weak self] in
            try? await Task.sleep(for: .milliseconds(350))
            guard !Task.isCancelled else { return }
            await self?.loadBrowserResults(resetPage: true)
        }
    }

    func loadBrowserResults(resetPage: Bool) async {
        if resetPage {
            browser.page = 1
            browser.hasMorePages = false
        }

        let request = browser.searchRequest
        guard request.hasServerCriteria else {
            browser.results = []
            browser.lastSearchFailed = false
            return
        }

        browser.isLoadingResults = true
        browser.lastSearchFailed = false
        defer { browser.isLoadingResults = false }

        do {
            let result = try await lobbyService.searchChannels(request)
            if request.page == 1 {
                browser.results = result.channels
            } else {
                browser.results.append(contentsOf: result.channels.filter { channel in
                    !browser.results.contains(where: { $0.id == channel.id })
                })
            }
            browser.hasMorePages = result.hasMorePages
        } catch {
            browser.lastSearchFailed = true
            if browser.results.isEmpty {
                browser.results = filteredChannels
            }
        }
    }

    func loadNextBrowserPage() {
        guard browser.hasMorePages, !browser.isLoadingResults else {
            return
        }

        browser.page += 1
        Task { await loadBrowserResults(resetPage: false) }
    }

    func selectBrowserPreview(_ channel: FightcadeChannel) {
        browser.selectedPreviewChannelID = channel.id
    }

    func joinFromBrowser(_ channel: FightcadeChannel) {
        selectedChannelID = channel.id
        isShowingChannelBrowser = false
        isShowingChannelChat = false
        join(channel)
    }

    func applyBrowserSystem(_ system: String?) {
        browser.selectedSystem = system
        browser.page = 1
        scheduleBrowserSearch()
    }

    func clearBrowserFilters() {
        browser.resetFilters()
        browser.results = []
        browser.lastSearchFailed = false
    }

    func toggleFavorite(_ channel: FightcadeChannel) {
        let newValue = !channel.isFavorite
        Task {
            do {
                try await lobbyService.setFavorite(newValue, for: channel)
                replaceChannel(channel.withFavorite(newValue))
                if browser.mode == .favorites || browser.results.contains(where: { $0.id == channel.id }) {
                    await loadBrowserResults(resetPage: true)
                }
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

    private var derivedSystems: [String] {
        Array(Set(channels.compactMap(\.system).filter { !$0.isEmpty }))
            .sorted { $0.localizedCaseInsensitiveCompare($1) == .orderedAscending }
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
            loadedAt: dashboard.loadedAt
        ), restoringJoinedChannels: false)

        if let index = browser.results.firstIndex(where: { $0.id == channel.id }) {
            browser.results[index] = channel
        }
    }
}

private extension FightcadeChannelFilterOptions {
    func withFallbackSystems(_ fallbackSystems: [String]) -> FightcadeChannelFilterOptions {
        FightcadeChannelFilterOptions(
            systems: systems.isEmpty ? fallbackSystems : systems,
            genres: genres,
            years: years
        )
    }
}
