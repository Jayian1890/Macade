import SwiftUI

struct PlayerListView: View {
    let channel: FightcadeChannel
    let users: [FightcadeChannelUser]
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @Bindable var layout: LobbyLayoutViewModel
    @State private var collapsedSections: Set<String> = ["playing", "watching", "away"]
    @State private var searchText = ""
    @AppStorage("playerListSort") private var selectedSortRawValue = PlayerListSort.smart.rawValue
    @AppStorage("playerListGroup") private var selectedGroupRawValue = PlayerListGroup.status.rawValue
    @State private var detailUserID: FightcadeChannelUser.ID?
    @State private var isDetailPaneMinimized = true

    var body: some View {
        let state = makeListState()
        let sections = PlayerListGrouping.sections(
            for: selectedGroup,
            rows: state.visibleRows,
            watchMatches: watchMatches(from: state.rows)
        )

        VStack(alignment: .leading, spacing: 0) {
            HStack {
                Text("Players").font(MacadeTypography.control)
                Spacer()
                Text("\(state.visibleRows.count)").font(MacadeTypography.metadata)
                    .foregroundStyle(MacadeColor.inkMuted)
            }
            .padding(.horizontal, MacadeSpacing.medium)
            .frame(height: MacadeLayout.toolbarHeight)

            HStack(spacing: MacadeSpacing.xSmall) {
                Image(systemName: "magnifyingglass").foregroundStyle(MacadeColor.inkMuted)
                TextField("Find a player", text: $searchText)
                    .textFieldStyle(.plain)
                    .foregroundStyle(MacadeColor.ink)
                groupMenu
                sortMenu
            }
            .font(MacadeTypography.body)
            .padding(.horizontal, MacadeSpacing.small)
            .frame(height: MacadeLayout.controlHeight)
            .background(MacadeColor.panel, in: RoundedRectangle(cornerRadius: MacadeLayout.controlRadius))
            .padding(.horizontal, MacadeSpacing.small)
            .padding(.bottom, MacadeSpacing.small)

            if let detailRow = state.detailRow, !isDetailPaneMinimized {
                MacadeResizableSplitView(
                    axis: .vertical, fixedSide: .trailing, dimension: $layout.playerDetailsHeight,
                    minimum: MacadeLayout.detailsMinimum, maximum: MacadeLayout.detailsMaximum,
                    flexibleMinimum: MacadeLayout.rosterMinimumHeight,
                    defaultDimension: MacadeLayout.detailsDefault, label: "player details"
                ) {
                    roster(sections: sections, focusedID: state.detailRow?.id)
                } trailing: {
                    details(for: detailRow)
                }
            } else {
                roster(sections: sections, focusedID: state.detailRow?.id)
                if let detailRow = state.detailRow { details(for: detailRow) }
            }
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background { MacadeFrostedFill(opacity: 0.5) }
    }

    private func roster(sections: [PlayerListGroupSection], focusedID: FightcadeChannelUser.ID?) -> some View {
        ScrollViewReader { proxy in
            ScrollView {
                LazyVStack(alignment: .leading, spacing: MacadeSpacing.small) {
                    ForEach(sections) { section in
                        groupedSection(section, focusedID: focusedID)
                    }
                }
                .padding(.horizontal, MacadeSpacing.small)
                .padding(.bottom, MacadeSpacing.small)
            }
            .onAppear { applyFocusRequest(viewModel.playerListFocusRequest, proxy: proxy) }
            .onChange(of: viewModel.playerListFocusRequest) { _, request in
                applyFocusRequest(request, proxy: proxy)
            }
            .onChange(of: users) { _, _ in
                applyFocusRequest(viewModel.playerListFocusRequest, proxy: proxy)
            }
        }
        .frame(maxHeight: .infinity)
    }

    private func details(for row: PlayerListRowState) -> some View {
        PlayerDetailPane(channel: channel, user: row.user, viewModel: viewModel,
            isChallengeable: row.isChallengeable, isChallenging: row.isChallenging,
            isCurrentUser: row.isCurrentUser, isMinimized: $isDetailPaneMinimized)
            .padding(.horizontal, MacadeSpacing.small)
            .padding(.bottom, MacadeSpacing.small)
    }

    @ViewBuilder
    private func groupedSection(_ section: PlayerListGroupSection, focusedID: FightcadeChannelUser.ID?) -> some View {
        DisclosureGroup(isExpanded: Binding(
            get: { !collapsedSections.contains(section.id) || !searchText.isEmpty },
            set: { expanded in
                guard searchText.isEmpty,
                      expanded == collapsedSections.contains(section.id) else { return }
                if expanded { collapsedSections.remove(section.id) }
                else { collapsedSections.insert(section.id) }
            }
        )) {
            LazyVStack(spacing: 4) {
                ForEach(section.watchMatches) { match in
                    WatchMatchRow(match: match, channel: channel, viewModel: viewModel)
                }

                ForEach(section.rows) { row in
                    PlayerRow(
                        channel: channel,
                        row: row,
                        viewModel: viewModel,
                        isFocused: focusedID == row.id
                    ) {
                        detailUserID = row.id
                        viewModel.clearPlayerListFocusRequest()
                    }
                    .id(row.id)
                }
            }
            .padding(.top, 4)
        } label: {
            HStack(spacing: 6) {
                Image(systemName: section.symbolName)
                Text(section.title)
                Spacer()
                Text("\(section.rows.count + section.watchMatches.count)")
                    .foregroundStyle(MacadeColor.inkMuted)
            }
            .font(MacadeTypography.control)
            .foregroundStyle(MacadeColor.inkMuted)
        }
    }

    private func makeListState() -> PlayerListState {
        let rows = viewModel.playerListRows(for: users, in: channel)
        let query = searchText.trimmingCharacters(in: .whitespacesAndNewlines)
        let filteredRows = rows.filter { row in
            query.isEmpty || row.user.name.localizedCaseInsensitiveContains(query)
        }
        let visibleRows = filteredRows.sorted(by: sortRows)
        let detailRow: PlayerListRowState?

        if let detailUserID,
           let row = visibleRows.first(where: { $0.id == detailUserID }) {
            detailRow = row
        } else if let activeMatchOpponentUsername,
                  let row = visibleRows.first(where: { usernameMatches($0.user.name, activeMatchOpponentUsername) }) {
            detailRow = row
        } else {
            detailRow = visibleRows.first { $0.isCurrentUser } ?? visibleRows.first
        }

        return PlayerListState(rows: rows, visibleRows: visibleRows, detailRow: detailRow)
    }

    private func watchMatches(from rows: [PlayerListRowState]) -> [WatchMatchRowState] {
        let query = searchText.trimmingCharacters(in: .whitespacesAndNewlines)
        let watchableRows = rows.filter(\.isWatchable)
        let grouped = Dictionary(grouping: watchableRows) { row in
            row.user.stream?.quarkID ?? row.user.id
        }

        return grouped.values.compactMap { group in
            let sortedRows = group.sorted(by: sortRows)
            guard query.isEmpty || sortedRows.contains(where: { $0.user.name.localizedCaseInsensitiveContains(query) }) else {
                return nil
            }

            return WatchMatchRowState(rows: sortedRows)
        }
        .sorted { lhs, rhs in
            lhs.title.localizedCaseInsensitiveCompare(rhs.title) == .orderedAscending
        }
    }

    private func applyFocusRequest(_ request: PlayerListFocusRequest?, proxy: ScrollViewProxy) {
        guard let request,
              request.channelName == channel.name,
              let user = users.first(where: { usernameMatches($0.name, request.username) }) else {
            return
        }

        let query = searchText.trimmingCharacters(in: .whitespacesAndNewlines)
        if !query.isEmpty, !user.name.localizedCaseInsensitiveContains(query) {
            searchText = ""
        }

        detailUserID = user.id
        isDetailPaneMinimized = false
        viewModel.clearPlayerListFocusRequest(request)

        DispatchQueue.main.async {
            withAnimation(.smooth(duration: 0.18)) {
                proxy.scrollTo(user.id, anchor: .center)
            }
        }
    }

    private func sortRows(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        selectedSort.compare(lhs, rhs)
    }

    private var selectedSort: PlayerListSort {
        PlayerListSort(rawValue: selectedSortRawValue) ?? .smart
    }

    private var selectedGroup: PlayerListGroup {
        PlayerListGroup(rawValue: selectedGroupRawValue) ?? .status
    }

    private var sortMenu: some View {
        Menu {
            ForEach(PlayerListSort.allCases) { sort in
                Button {
                    selectedSortRawValue = sort.rawValue
                } label: {
                    Label(sort.title, systemImage: sort.symbolName)
                }
            }
        } label: {
            Image(systemName: selectedSort.symbolName)
                .font(.system(size: 11, weight: .black))
                .foregroundStyle(MacadeColor.inkMuted)
                .frame(width: 24, height: 24)
                .background(MacadeColor.panel.opacity(0.9), in: Circle())
        }
        .menuStyle(.button)
        .buttonStyle(.plain)
        .help("Sort by \(selectedSort.title)")
    }

    private var groupMenu: some View {
        Menu {
            ForEach(PlayerListGroup.allCases) { group in
                Button {
                    selectedGroupRawValue = group.rawValue
                } label: {
                    Label(group.title, systemImage: group.symbolName)
                }
            }
        } label: {
            Image(systemName: selectedGroup.symbolName)
                .font(.system(size: 11, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)
                .frame(width: 24, height: 24)
                .background(MacadeColor.panel.opacity(0.9), in: Circle())
        }
        .menuStyle(.button)
        .buttonStyle(.plain)
        .help("Group by \(selectedGroup.title)")
    }

    private var activeMatchOpponentUsername: String? {
        guard let session = viewModel.selectedEmulationSession,
              session.mode == .match,
              session.isActive,
              viewModel.activeMatchOpponentChannelName == channel.name else {
            return nil
        }

        return viewModel.activeMatchOpponentUsername
    }

    private func usernameMatches(_ lhs: String, _ rhs: String) -> Bool {
        lhs.compare(rhs, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
    }
}
