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
                } else if viewModel.browser.mode == .all && !viewModel.browser.hasActiveFilters && viewModel.browser.results.isEmpty {
                    ChannelCardSection(title: "POPULAR GAMES", channels: viewModel.popularChannels)
                    CategoryStrip(
                        channels: viewModel.channels,
                        favoriteCount: viewModel.favoriteChannels.count,
                        onSelectPopular: viewModel.showChannelBrowser,
                        onSelectFavorites: viewModel.showFavoriteChannels,
                        onSelectSystem: selectCategory
                    )
                    ChannelCardSection(title: "HIDDEN GEMS", channels: viewModel.hiddenGemChannels)
                    EventCardSection(title: "UPCOMING EVENTS", events: viewModel.upcomingEvents)

                    if !viewModel.favoriteChannels.isEmpty {
                        ChannelCardSection(title: "FAVORITES", channels: viewModel.favoriteChannels)
                    }
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
        viewModel.browser.filterOptions.systems.isEmpty
            ? Array(Set(viewModel.channels.compactMap(\.system))).sorted()
            : viewModel.browser.filterOptions.systems
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

    private func selectCategory(_ system: String) {
        viewModel.browser.mode = .all
        viewModel.applyBrowserSystem(system)
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
                            isSelected: viewModel.browser.selectedPreviewChannelID == channel.id,
                            isJoined: viewModel.joinedChannelIDs.contains(channel.id),
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
                        isSelected: viewModel.browser.selectedPreviewChannelID == channel.id,
                        isJoined: viewModel.joinedChannelIDs.contains(channel.id),
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
