import SwiftUI

struct ChannelBrowserView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    private let columns = [GridItem(.adaptive(minimum: 188, maximum: 226), spacing: 10)]

    var body: some View {
        VStack(spacing: 0) {
            browserHeader
            statusBanner
            browserContent
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background(browserBackground)
    }

    private var browserHeader: some View {
        VStack(spacing: MacadeSpacing.xSmall) {
            HStack(spacing: MacadeSpacing.medium) {
                VStack(alignment: .leading, spacing: 3) {
                    Text(title)
                        .font(.system(size: 24, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)

                    Text(summary)
                        .font(.system(size: 11, weight: .bold, design: .monospaced))
                        .foregroundStyle(MacadeColor.inkMuted)
                }

                Spacer(minLength: MacadeSpacing.medium)

                HStack(spacing: MacadeSpacing.small) {
                    Image(systemName: "magnifyingglass")
                        .foregroundStyle(MacadeColor.inkMuted.opacity(0.72))

                    TextField("Search games", text: queryBinding)
                        .textFieldStyle(.plain)
                        .font(.system(size: 18, weight: .medium, design: .rounded))
                        .onSubmit {
                            viewModel.searchBrowserRemotely()
                        }

                    Button {
                        viewModel.searchBrowserRemotely()
                    } label: {
                        if viewModel.browser.isSearchingRemotely {
                            ProgressView()
                                .controlSize(.small)
                        } else {
                            Text("Search Fightcade")
                        }
                    }
                    .buttonStyle(.bordered)
                    .controlSize(.small)
                    .disabled(trimmedQuery.isEmpty || viewModel.browser.isSearchingRemotely)
                }
                .padding(.horizontal, MacadeSpacing.medium)
                .frame(maxWidth: 680)
                .frame(height: 46)
                .background(MacadeColor.panel.opacity(0.62), in: RoundedRectangle(cornerRadius: 13))
                .overlay(RoundedRectangle(cornerRadius: 13).stroke(MacadeColor.stroke, lineWidth: 1))

                if viewModel.browser.hasActiveFilters {
                    Button("Clear") {
                        viewModel.clearBrowserFilters()
                    }
                    .buttonStyle(.bordered)
                    .controlSize(.small)
                }
            }

            syncStatus
        }
        .padding(.horizontal, MacadeSpacing.large)
        .padding(.vertical, MacadeSpacing.medium)
        .background(.ultraThinMaterial)
    }

    @ViewBuilder
    private var syncStatus: some View {
        if viewModel.isLoading || viewModel.browser.isSearchingRemotely {
            HStack(spacing: MacadeSpacing.small) {
                ProgressView()
                    .controlSize(.small)

                Text(statusText)
                    .font(.system(size: 11, weight: .bold, design: .monospaced))
                    .foregroundStyle(MacadeColor.inkMuted)
                    .lineLimit(1)

                Spacer(minLength: 0)
            }
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
        }
    }

    private var browserContent: some View {
        ScrollView {
            VStack(alignment: .leading, spacing: 24) {
                categoriesSection
                gamesSection
                upcomingEventsSection
            }
            .padding(MacadeSpacing.medium)
        }
        .scrollIndicators(.hidden)
    }

    private var categoriesSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            SectionTitle("Categories")

            LazyVGrid(columns: [GridItem(.adaptive(minimum: 138), spacing: 8)], alignment: .leading, spacing: 8) {
                ForEach(viewModel.browserCategories) { category in
                    CategoryButton(
                        category: category,
                        isSelected: viewModel.isBrowserCategorySelected(category)
                    ) {
                        viewModel.applyBrowserCategory(category)
                    }
                }
            }
        }
    }

    @ViewBuilder
    private var gamesSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            SectionTitle("Games")

            if viewModel.browserChannels.isEmpty && viewModel.isLoading {
                ProgressView("Connecting to Fightcade...")
                    .foregroundStyle(MacadeColor.inkMuted)
                    .frame(maxWidth: .infinity, minHeight: 220)
            } else if viewModel.browserChannels.isEmpty {
                ContentUnavailableView(emptyGamesTitle, systemImage: "rectangle.3.group")
                    .foregroundStyle(MacadeColor.inkMuted)
                    .frame(maxWidth: .infinity, minHeight: 220)
            } else {
                LazyVGrid(columns: columns, alignment: .leading, spacing: 14) {
                    ForEach(viewModel.browserChannels) { channel in
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
    private var upcomingEventsSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            SectionTitle("Upcoming Events")

            if viewModel.upcomingEvents.isEmpty {
                ContentUnavailableView("No Upcoming Events", systemImage: "calendar")
                    .foregroundStyle(MacadeColor.inkMuted)
                    .frame(maxWidth: .infinity, minHeight: 160)
            } else {
                LazyVGrid(columns: columns, alignment: .leading, spacing: 14) {
                    ForEach(viewModel.upcomingEvents) { event in
                        FightcadeEventCard(event: event)
                    }
                }
            }
        }
    }

    private var queryBinding: Binding<String> {
        Binding {
            viewModel.browser.query
        } set: { value in
            viewModel.browser.query = value
        }
    }

    private var trimmedQuery: String {
        viewModel.browser.query.trimmingCharacters(in: .whitespacesAndNewlines)
    }

    private var statusText: String {
        if viewModel.browser.isSearchingRemotely {
            return "Searching Fightcade for \"\(trimmedQuery)\"..."
        }

        return viewModel.channels.isEmpty ? "Loading active Fightcade games..." : "Refreshing live activity..."
    }

    private var emptyGamesTitle: String {
        trimmedQuery.isEmpty ? "No Known Games" : "No Cached Matches"
    }

    private var title: String {
        switch viewModel.browser.mode {
        case .all: "Browse Games"
        case .ranked: "Ranked Games"
        case .favorites: "Favorite Games"
        }
    }

    private var summary: String {
        let visibleCount = viewModel.browserChannels.count
        let totalCount = viewModel.channels.count
        let activeCount = viewModel.channels.reduce(0) { $0 + ($1.playerCount ?? 0) }
        return "\(visibleCount) shown · \(totalCount) known · \(activeCount) players online"
    }

    private var browserBackground: some View {
        LinearGradient(
            colors: [MacadeColor.deepPlum.opacity(0.22), .clear, MacadeColor.arcadeBlue.opacity(0.16)],
            startPoint: .topLeading,
            endPoint: .bottomTrailing
        )
    }
}

private struct CategoryButton: View {
    let category: FightcadeBrowserCategory
    let isSelected: Bool
    let action: () -> Void

    var body: some View {
        Button(action: action) {
            VStack(alignment: .leading, spacing: 4) {
                Text(category.title.uppercased())
                    .font(.system(size: 12, weight: .black, design: .rounded))
                    .lineLimit(1)

                Text("\(category.gameCount) games · \(category.playerCount) players")
                    .font(.system(size: 10, weight: .bold, design: .monospaced))
                    .foregroundStyle(isSelected ? MacadeColor.midnight.opacity(0.72) : MacadeColor.inkMuted)
                    .lineLimit(1)
            }
            .padding(.horizontal, 10)
            .frame(maxWidth: .infinity, minHeight: 48, alignment: .leading)
            .background(isSelected ? MacadeColor.warning : MacadeColor.panel.opacity(0.72), in: RoundedRectangle(cornerRadius: 10))
            .overlay(RoundedRectangle(cornerRadius: 10).stroke(isSelected ? MacadeColor.warning : MacadeColor.stroke, lineWidth: 1))
            .foregroundStyle(isSelected ? MacadeColor.midnight : MacadeColor.ink)
        }
        .buttonStyle(.plain)
    }
}
