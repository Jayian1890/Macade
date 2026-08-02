import SwiftUI

struct ChannelBrowserView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    private let columns = [GridItem(.adaptive(minimum: 188, maximum: 226), spacing: 10)]

    var body: some View {
        VStack(spacing: 0) {
            searchHeader
            statusBanner
            browserContent
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background(browserBackground)
        .onAppear {
            viewModel.loadBrowserFilterOptions()
            viewModel.loadUpcomingEvents()
        }
    }

    private var searchHeader: some View {
        VStack(spacing: MacadeSpacing.xSmall) {
            HStack(spacing: MacadeSpacing.medium) {
                Spacer(minLength: 24)

                HStack(spacing: MacadeSpacing.medium) {
                    Image(systemName: "magnifyingglass")
                        .foregroundStyle(MacadeColor.inkMuted.opacity(0.7))

                    TextField("Search games", text: queryBinding)
                        .textFieldStyle(.plain)
                        .font(.system(size: 22, weight: .medium, design: .rounded))
                        .multilineTextAlignment(.center)
                }
                .padding(.horizontal, MacadeSpacing.medium)
                .frame(maxWidth: 620)
                .frame(height: 58)
                .overlay(alignment: .bottom) {
                    Rectangle()
                        .fill(MacadeColor.neonCyan.opacity(0.8))
                        .frame(height: 1)
                }

                Button {
                    viewModel.browser.isShowingFilters.toggle()
                } label: {
                    Image(systemName: "slider.horizontal.3")
                        .font(.system(size: 23, weight: .light))
                }
                .buttonStyle(.plain)
                .foregroundStyle(viewModel.browser.hasActiveFilters ? MacadeColor.warning : MacadeColor.inkMuted.opacity(0.55))
                .popover(isPresented: $viewModel.browser.isShowingFilters) {
                    filterPopover
                }

                sortMenu

                Button {
                    viewModel.browser.layoutMode = viewModel.browser.layoutMode == .grid ? .list : .grid
                } label: {
                    Image(systemName: viewModel.browser.layoutMode == .grid ? "list.bullet" : "square.grid.2x2")
                        .font(.system(size: 19, weight: .bold))
                }
                .buttonStyle(.plain)
                .foregroundStyle(MacadeColor.inkMuted.opacity(0.65))

                Spacer(minLength: 24)
            }

            activeFilterChips
        }
        .frame(minHeight: 92)
        .background(.ultraThinMaterial)
    }

    private var sortMenu: some View {
        Menu {
            Section("Activity") {
                sortButton(.playersDescending)
                sortButton(.playersAscending)
                sortButton(.spectatorsDescending)
                sortButton(.spectatorsAscending)
            }
            Section("Game") {
                sortButton(.titleAscending)
                sortButton(.titleDescending)
                sortButton(.systemAscending)
                sortButton(.systemDescending)
            }
            Section("Priority") {
                sortButton(.rankedFirst)
                sortButton(.favoritesFirst)
                sortButton(.joinedFirst)
            }
        } label: {
            HStack(spacing: 5) {
                Image(systemName: viewModel.browser.sort.symbolName)
                Text(viewModel.browser.sort.shortTitle)
            }
            .font(.system(size: 12, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.inkMuted.opacity(0.72))
            .padding(.horizontal, 9)
            .frame(height: 28)
            .background(MacadeColor.panel.opacity(0.56), in: Capsule())
        }
        .menuStyle(.button)
        .buttonStyle(.plain)
        .help("Sort by \(viewModel.browser.sort.title)")
    }

    private func sortButton(_ sort: FightcadeChannelBrowserSort) -> some View {
        Button {
            viewModel.browser.sort = sort
        } label: {
            Label(sort.title, systemImage: viewModel.browser.sort == sort ? "checkmark.circle.fill" : sort.symbolName)
        }
    }

    private var queryBinding: Binding<String> {
        Binding {
            viewModel.browser.query
        } set: { value in
            viewModel.browser.query = value
            viewModel.scheduleBrowserSearch()
        }
    }

    @ViewBuilder
    private var statusBanner: some View {
        if let errorMessage = viewModel.errorMessage {
            Text(errorMessage)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.warning)
                .padding(.horizontal, MacadeSpacing.large)
                .frame(height: 38)
                .frame(maxWidth: .infinity, alignment: .leading)
                .background(MacadeColor.warning.opacity(0.12))
        } else if viewModel.browser.lastSearchFailed {
            Text("Live browser search failed. Showing last real channel data.")
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.warning)
                .padding(.horizontal, MacadeSpacing.large)
                .frame(height: 38)
                .frame(maxWidth: .infinity, alignment: .leading)
                .background(MacadeColor.warning.opacity(0.12))
        }
    }

    private var browserContent: some View {
        ScrollView {
            VStack(alignment: .leading, spacing: 22) {
                if viewModel.browser.isLoadingResults && viewModel.browserChannels.isEmpty {
                    ProgressView("Loading games...")
                        .foregroundStyle(MacadeColor.inkMuted)
                        .frame(maxWidth: .infinity, minHeight: 260)
                } else if viewModel.browserChannels.isEmpty && !viewModel.isLoading {
                    ContentUnavailableView("No Channels", systemImage: "magnifyingglass")
                        .foregroundStyle(MacadeColor.inkMuted)
                        .frame(maxWidth: .infinity, minHeight: 300)
                } else if isShowingLandingSections {
                    landingSections
                } else {
                    if viewModel.browser.layoutMode == .grid {
                        ChannelCardSection(title: resultsTitle, channels: viewModel.browserChannels)
                    } else {
                        ChannelListSection(title: resultsTitle, channels: viewModel.browserChannels)
                    }

                    if viewModel.browser.hasMorePages {
                        Button("Load More") {
                            viewModel.loadNextBrowserPage()
                        }
                        .buttonStyle(.borderedProminent)
                        .disabled(viewModel.browser.isLoadingResults)
                    }
                }
            }
            .padding(MacadeSpacing.medium)
        }
        .scrollIndicators(.hidden)
    }

    private var isShowingLandingSections: Bool {
        viewModel.browser.mode == .all && !viewModel.browser.hasActiveFilters && viewModel.browser.results.isEmpty
    }

    @ViewBuilder
    private var landingSections: some View {
        if viewModel.browserLandingSections.isEmpty {
            fallbackLandingSections
        } else {
            ForEach(viewModel.browserLandingSections) { section in
                welcomeSection(section)
            }
        }
    }

    @ViewBuilder
    private var fallbackLandingSections: some View {
        ChannelCardSection(title: "POPULAR GAMES", channels: viewModel.popularChannels)
        CategoryStrip(
            channels: viewModel.channels,
            favoriteCount: viewModel.favoriteChannels.count,
            onSelectCategory: selectCategory
        )
        ChannelCardSection(title: "HIDDEN GEMS", channels: viewModel.hiddenGemChannels)
        EventCardSection(title: "UPCOMING EVENTS", events: viewModel.upcomingEvents)

        if !viewModel.favoriteChannels.isEmpty {
            ChannelCardSection(title: "FAVORITES", channels: viewModel.favoriteChannels)
        }
    }

    @ViewBuilder
    private func welcomeSection(_ section: FightcadeWelcomeSection) -> some View {
        if !section.categories.isEmpty {
            CategoryStrip(
                title: section.title.uppercased(),
                categories: section.categories,
                channels: viewModel.channels,
                favoriteCount: viewModel.favoriteChannels.count,
                onSelectCategory: selectCategory
            )
        }

        if !section.channels.isEmpty {
            ChannelCardSection(title: section.title.uppercased(), channels: section.channels)
        }

        if !section.events.isEmpty {
            EventCardSection(title: section.title.uppercased(), events: section.events)
        }
    }

    private var activeFilterChips: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            if viewModel.browser.mode == .ranked {
                FilterChip(title: "Ranked") { viewModel.showChannelBrowser() }
            }

            if viewModel.browser.mode == .favorites {
                FilterChip(title: "Favorites") { viewModel.showChannelBrowser() }
            }

            if let system = viewModel.browser.selectedSystem {
                FilterChip(title: system) { viewModel.applyBrowserSystem(nil) }
            }

            if let genre = viewModel.browser.selectedGenre {
                FilterChip(title: genre) {
                    viewModel.browser.selectedGenre = nil
                    viewModel.scheduleBrowserSearch()
                }
            }

            if let year = viewModel.browser.selectedYear {
                FilterChip(title: year) {
                    viewModel.browser.selectedYear = nil
                    viewModel.scheduleBrowserSearch()
                }
            }

            if viewModel.browser.hasActiveFilters {
                Button("Clear") {
                    viewModel.clearBrowserFilters()
                }
                .buttonStyle(.plain)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
            }
        }
        .frame(height: 24)
    }

    private var filterPopover: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            Text("Filters")
                .font(.system(size: 18, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)

            filterSection(title: "System", options: filterSystems, selected: viewModel.browser.selectedSystem) {
                viewModel.applyBrowserSystem($0)
            }

            filterSection(title: "Genre", options: viewModel.browser.filterOptions.genres, selected: viewModel.browser.selectedGenre) { genre in
                viewModel.browser.selectedGenre = genre
                viewModel.scheduleBrowserSearch()
            }

            filterSection(title: "Year", options: viewModel.browser.filterOptions.years, selected: viewModel.browser.selectedYear) { year in
                viewModel.browser.selectedYear = year
                viewModel.scheduleBrowserSearch()
            }

            Button("Clear Filters") {
                viewModel.clearBrowserFilters()
            }
            .buttonStyle(.bordered)
        }
        .padding(MacadeSpacing.large)
        .frame(width: 320)
        .background(MacadeColor.midnight)
    }

    private var filterSystems: [String] {
        let systems = viewModel.browser.filterOptions.systems.isEmpty
            ? Array(Set(viewModel.channels.compactMap(\.system))).sorted()
            : viewModel.browser.filterOptions.systems
        return systems.sorted(by: sortSystemsByUserCount)
    }

    private func sortSystemsByUserCount(_ lhs: String, _ rhs: String) -> Bool {
        let leftCount = userCount(forSystem: lhs)
        let rightCount = userCount(forSystem: rhs)
        if leftCount != rightCount {
            return leftCount > rightCount
        }

        return lhs.localizedCaseInsensitiveCompare(rhs) == .orderedAscending
    }

    private func userCount(forSystem system: String) -> Int {
        viewModel.channels.reduce(0) { total, channel in
            guard channel.system?.localizedCaseInsensitiveCompare(system) == .orderedSame else {
                return total
            }

            return total + (channel.playerCount ?? 0)
        }
    }

    private func filterSection(
        title: String,
        options: [String],
        selected: String?,
        onSelect: @escaping (String?) -> Void
    ) -> some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
            Text(title.uppercased())
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)

            if options.isEmpty {
                Text("No live options")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted.opacity(0.7))
            } else {
                LazyVGrid(columns: [GridItem(.adaptive(minimum: 86), spacing: 6)], spacing: 6) {
                    Button("Any") { onSelect(nil) }
                        .buttonStyle(FilterOptionButtonStyle(isSelected: selected == nil))

                    ForEach(options.prefix(12), id: \.self) { option in
                        Button(option) { onSelect(option) }
                            .buttonStyle(FilterOptionButtonStyle(isSelected: selected == option))
                    }
                }
            }
        }
    }

    private var browserBackground: some View {
        LinearGradient(
            colors: [MacadeColor.deepPlum.opacity(0.22), .clear, MacadeColor.arcadeBlue.opacity(0.16)],
            startPoint: .topLeading,
            endPoint: .bottomTrailing
        )
    }

    private func selectCategory(_ category: String) {
        let normalizedCategory = category.normalizedBrowserCategory
        if normalizedCategory == "popular" {
            viewModel.showPopularChannels()
            return
        }

        if normalizedCategory == "my favorites" || normalizedCategory == "favorites" {
            viewModel.showFavoriteChannels()
            return
        }

        viewModel.browser.mode = .all
        viewModel.browser.query = ""
        viewModel.browser.selectedYear = nil

        if let genre = matchingOption(category, in: viewModel.browser.filterOptions.genres) {
            viewModel.browser.selectedSystem = nil
            viewModel.browser.selectedGenre = genre
            viewModel.scheduleBrowserSearch()
            return
        }

        if let system = matchingOption(category, in: filterSystems) {
            viewModel.browser.selectedGenre = nil
            viewModel.applyBrowserSystem(system)
            return
        }

        viewModel.browser.selectedGenre = nil
        viewModel.browser.selectedSystem = nil
        viewModel.browser.query = category
        viewModel.scheduleBrowserSearch()
    }

    private func matchingOption(_ value: String, in options: [String]) -> String? {
        let normalizedValue = value.normalizedBrowserCategory
        return options.first { $0.normalizedBrowserCategory == normalizedValue }
    }

    private var resultsTitle: String {
        switch viewModel.browser.mode {
        case .all:
            "SEARCH RESULTS"
        case .ranked:
            "RANKED"
        case .favorites:
            "FAVORITES"
        }
    }

    @ViewBuilder
    private func ChannelCardSection(title: String, channels: [FightcadeChannel]) -> some View {
        if !channels.isEmpty {
            VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                SectionTitle(title)

                LazyVGrid(columns: columns, alignment: .leading, spacing: 14) {
                    ForEach(channels) { channel in
                        ChannelCard(
                            channel: channel,
                            isSelected: viewModel.isBrowserChannelSelected(channel),
                            isJoined: viewModel.isBrowserChannelJoined(channel),
                            previewAction: { viewModel.selectBrowserPreview(channel) },
                            openAction: { viewModel.joinFromBrowser(channel) },
                            favoriteAction: { viewModel.toggleFavorite(channel) },
                            joinAction: { viewModel.joinFromBrowser(channel) }
                        )
                    }
                }
            }
        }
    }

    @ViewBuilder
    private func ChannelListSection(title: String, channels: [FightcadeChannel]) -> some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            SectionTitle(title)

            VStack(spacing: 1) {
                ForEach(channels) { channel in
                    ChannelListRow(
                        channel: channel,
                        isSelected: viewModel.isBrowserChannelSelected(channel),
                        isJoined: viewModel.isBrowserChannelJoined(channel),
                        previewAction: { viewModel.selectBrowserPreview(channel) },
                        openAction: { viewModel.joinFromBrowser(channel) },
                        favoriteAction: { viewModel.toggleFavorite(channel) },
                        joinAction: { viewModel.joinFromBrowser(channel) }
                    )
                }
            }
            .clipShape(RoundedRectangle(cornerRadius: 12))
        }
    }

    @ViewBuilder
    private func EventCardSection(title: String, events: [FightcadeEvent]) -> some View {
        if !events.isEmpty {
            VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                SectionTitle(title)

                LazyVGrid(columns: columns, alignment: .leading, spacing: 14) {
                    ForEach(events) { event in
                        FightcadeEventCard(event: event)
                    }
                }
            }
        }
    }
}
