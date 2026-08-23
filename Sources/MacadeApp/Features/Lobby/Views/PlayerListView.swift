import SwiftUI

struct PlayerListView: View {
    let channel: FightcadeChannel
    let users: [FightcadeChannelUser]
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var searchText = ""
    @AppStorage("playerListSort") private var selectedSortRawValue = PlayerListSort.smart.rawValue
    @AppStorage("playerListGroup") private var selectedGroupRawValue = PlayerListGroup.status.rawValue
    @AppStorage("playerListSidebarWidth") private var playerListWidth = 300.0
    @State private var detailUserID: FightcadeChannelUser.ID?
    @State private var isDetailPaneMinimized = true
    @State private var resizeStartWidth: Double?

    var body: some View {
        let state = makeListState()
        let sections = PlayerListGrouping.sections(
            for: selectedGroup,
            rows: state.visibleRows,
            watchMatches: watchMatches(from: state.rows)
        )

        VStack(alignment: .leading, spacing: 0) {
            HStack(spacing: MacadeSpacing.xSmall) {
                TextField("Search", text: $searchText)
                    .textFieldStyle(.plain)
                    .foregroundStyle(MacadeColor.ink)

                Spacer()

                groupMenu
                sortMenu
            }
            .font(MacadeTypography.body)
            .padding(.horizontal, MacadeSpacing.small)
            .frame(height: 34)
            .background(MacadeColor.panel.opacity(0.7), in: RoundedRectangle(cornerRadius: 12))
            .padding(.horizontal, MacadeSpacing.small)
            .padding(.bottom, MacadeSpacing.small)

            ScrollViewReader { proxy in
                ScrollView {
                    LazyVStack(alignment: .leading, spacing: 10) {
                        ForEach(sections) { section in
                            groupedSection(section, focusedID: state.detailRow?.id)
                        }
                    }
                    .padding(.horizontal, MacadeSpacing.small)
                    .padding(.bottom, MacadeSpacing.small)
                }
                .onAppear {
                    applyFocusRequest(viewModel.playerListFocusRequest, proxy: proxy)
                }
                .onChange(of: viewModel.playerListFocusRequest) { _, request in
                    applyFocusRequest(request, proxy: proxy)
                }
                .onChange(of: users) { _, _ in
                    applyFocusRequest(viewModel.playerListFocusRequest, proxy: proxy)
                }
            }

            if let detailRow = state.detailRow {
                PlayerDetailPane(
                    channel: channel,
                    user: detailRow.user,
                    viewModel: viewModel,
                    isChallengeable: detailRow.isChallengeable,
                    isChallenging: detailRow.isChallenging,
                    isCurrentUser: detailRow.isCurrentUser,
                    isMinimized: $isDetailPaneMinimized
                )
                .padding(.horizontal, MacadeSpacing.small)
                .padding(.bottom, MacadeSpacing.small)
            }
        }
        .frame(width: playerListWidth)
        .frame(maxHeight: .infinity)
        .background { MacadeFrostedFill(opacity: 0.5) }
        .overlay(alignment: .leading) {
            playerListResizeHandle
        }
        .animation(.smooth(duration: 0.16), value: isDetailPaneMinimized)
    }

    @ViewBuilder
    private func groupedSection(_ section: PlayerListGroupSection, focusedID: FightcadeChannelUser.ID?) -> some View {
        DisclosureGroup {
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
            .font(.system(size: 11, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.inkMuted)
        }
    }

    private var playerListResizeHandle: some View {
        Rectangle()
            .fill(.clear)
            .frame(width: 8)
            .contentShape(Rectangle())
            .gesture(
                DragGesture()
                    .onChanged { value in
                        let base = resizeStartWidth ?? playerListWidth
                        resizeStartWidth = base
                        playerListWidth = min(max(base - value.translation.width, 240), 460)
                    }
                    .onEnded { _ in
                        resizeStartWidth = nil
                    }
            )
            .overlay(alignment: .leading) {
                Rectangle()
                    .fill(MacadeColor.divider)
                    .frame(width: 1)
            }
            .help("Resize player list")
    }

    private func makeListState() -> PlayerListState {
        let rows = users.map { makeRow(for: $0) }
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

    private func makeRow(for user: FightcadeChannelUser) -> PlayerListRowState {
        PlayerListRowState(
            user: user,
            isCurrentUser: isCurrentUser(user),
            isChallengeable: viewModel.canChallenge(user, in: channel),
            isChallenging: viewModel.isChallenging(user, in: channel),
            isWatchable: viewModel.canSpectate(user, in: channel)
        )
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

    private func isCurrentUser(_ user: FightcadeChannelUser) -> Bool {
        user.isCurrentUser(session: viewModel.session)
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
