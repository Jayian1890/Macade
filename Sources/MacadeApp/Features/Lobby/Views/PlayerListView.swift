import SwiftUI

struct PlayerListView: View {
    let channel: FightcadeChannel
    let users: [FightcadeChannelUser]
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var searchText = ""
    @State private var selectedFilter: PlayerListFilter?
    @AppStorage("playerListSort") private var selectedSortRawValue = PlayerListSort.smart.rawValue
    @State private var detailUserID: FightcadeChannelUser.ID?
    @State private var isDetailPaneMinimized = false

    var body: some View {
        let state = makeListState()

        VStack(alignment: .leading, spacing: 0) {
            filterBar(state: state)

            HStack(spacing: MacadeSpacing.xSmall) {
                TextField("Search", text: $searchText)
                    .textFieldStyle(.plain)
                    .foregroundStyle(MacadeColor.ink)

                Spacer()

                sortMenu
            }
            .font(MacadeTypography.body)
            .padding(.horizontal, MacadeSpacing.small)
            .frame(height: 34)
            .background(MacadeColor.panel.opacity(0.7), in: RoundedRectangle(cornerRadius: 12))
            .padding(.horizontal, MacadeSpacing.small)
            .padding(.bottom, MacadeSpacing.small)

            ScrollView {
                LazyVStack(spacing: 4) {
                    ForEach(state.visibleRows) { row in
                        PlayerRow(
                            channel: channel,
                            row: row,
                            viewModel: viewModel,
                            isFocused: state.detailRow?.id == row.id
                        ) {
                            if activeMatchOpponentUsername == nil {
                                detailUserID = row.id
                            }
                        }
                    }
                }
                .padding(.horizontal, MacadeSpacing.small)
                .padding(.bottom, MacadeSpacing.small)
            }

            if let detailRow = state.detailRow {
                PlayerDetailPane(
                    user: detailRow.user,
                    isChallengeable: detailRow.isChallengeable,
                    isChallenging: detailRow.isChallenging,
                    isCurrentUser: detailRow.isCurrentUser,
                    isMinimized: $isDetailPaneMinimized
                )
                .padding(.horizontal, MacadeSpacing.small)
                .padding(.bottom, MacadeSpacing.small)
            }
        }
        .frame(width: 300)
        .frame(maxHeight: .infinity)
        .background(MacadeColor.sidebar.opacity(0.54))
        .overlay(alignment: .leading) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(width: 1)
        }
        .animation(.smooth(duration: 0.16), value: isDetailPaneMinimized)
    }

    private func makeListState() -> PlayerListState {
        let rows = users.map { makeRow(for: $0) }
        let query = searchText.trimmingCharacters(in: .whitespacesAndNewlines)
        let filteredRows = rows.filter { row in
            (selectedFilter?.includes(row) ?? true)
                && (query.isEmpty || row.user.name.localizedCaseInsensitiveContains(query))
        }
        let visibleRows = filteredRows.sorted(by: sortRows)
        let detailRow: PlayerListRowState?

        if let activeMatchOpponentUsername,
           let row = visibleRows.first(where: { usernameMatches($0.user.name, activeMatchOpponentUsername) }) {
            detailRow = row
        } else if let detailUserID,
           let row = visibleRows.first(where: { $0.id == detailUserID }) {
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

    private func filterBar(state: PlayerListState) -> some View {
        ScrollView(.horizontal, showsIndicators: false) {
            HStack(spacing: 6) {
                ForEach(PlayerListFilter.allCases) { filter in
                    Button {
                        selectedFilter = selectedFilter == filter ? nil : filter
                    } label: {
                        HStack(spacing: 4) {
                            Image(systemName: filter.symbolName)
                            Text("\(filter.count(in: state.rows))")
                                .foregroundStyle(selectedFilter == filter ? MacadeColor.midnight : MacadeColor.inkMuted)
                        }
                        .font(.system(size: 11, weight: .black, design: .rounded))
                        .foregroundStyle(selectedFilter == filter ? MacadeColor.midnight : MacadeColor.inkMuted)
                        .padding(.horizontal, 9)
                        .padding(.vertical, 6)
                        .background(filterBackground(for: filter), in: Capsule())
                    }
                    .buttonStyle(.plain)
                    .help(filter.title)
                }
            }
            .padding(.horizontal, MacadeSpacing.small)
        }
        .frame(height: 42)
    }

    private func filterBackground(for filter: PlayerListFilter) -> Color {
        selectedFilter == filter ? MacadeColor.neonCyan : MacadeColor.panel.opacity(0.72)
    }

    private func sortRows(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        selectedSort.compare(lhs, rhs)
    }

    private var selectedSort: PlayerListSort {
        PlayerListSort(rawValue: selectedSortRawValue) ?? .smart
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

private enum PlayerListSort: String, CaseIterable, Identifiable {
    case smart
    case name
    case rank
    case ping
    case status

    var id: String { rawValue }

    var title: String {
        switch self {
        case .smart: "Smart"
        case .name: "Name"
        case .rank: "Rank"
        case .ping: "Ping"
        case .status: "Status"
        }
    }

    var symbolName: String {
        switch self {
        case .smart: "sparkles"
        case .name: "textformat.abc"
        case .rank: "rosette"
        case .ping: "speedometer"
        case .status: "circle.grid.2x2.fill"
        }
    }

    func compare(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        if lhs.isCurrentUser != rhs.isCurrentUser {
            return lhs.isCurrentUser
        }

        switch self {
        case .smart:
            return smartCompare(lhs, rhs)
        case .name:
            return nameCompare(lhs, rhs)
        case .rank:
            return rankCompare(lhs, rhs)
        case .ping:
            return pingCompare(lhs, rhs)
        case .status:
            return statusCompare(lhs, rhs)
        }
    }

    private func smartCompare(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        if lhs.isChallengeable != rhs.isChallengeable {
            return lhs.isChallengeable
        }

        if lhs.isWatchable != rhs.isWatchable {
            return lhs.isWatchable
        }

        if let result = comparePing(lhs.user.ping, rhs.user.ping, bestFirst: false) {
            return result
        }

        return nameCompare(lhs, rhs)
    }

    private func nameCompare(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        lhs.user.name.localizedCaseInsensitiveCompare(rhs.user.name) == .orderedAscending
    }

    private func rankCompare(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        let leftRank = lhs.user.rank ?? 0
        let rightRank = rhs.user.rank ?? 0
        if leftRank != rightRank {
            return leftRank > rightRank
        }

        return nameCompare(lhs, rhs)
    }

    private func pingCompare(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        if let result = comparePing(lhs.user.ping, rhs.user.ping, bestFirst: true) {
            return result
        }

        return nameCompare(lhs, rhs)
    }

    private func statusCompare(_ lhs: PlayerListRowState, _ rhs: PlayerListRowState) -> Bool {
        let leftStatus = statusPriority(lhs)
        let rightStatus = statusPriority(rhs)
        if leftStatus != rightStatus {
            return leftStatus < rightStatus
        }

        return nameCompare(lhs, rhs)
    }

    private func comparePing(_ lhs: Int?, _ rhs: Int?, bestFirst: Bool) -> Bool? {
        switch (lhs, rhs) {
        case let (left?, right?) where left != right:
            return bestFirst ? left < right : left > right
        case (_?, nil):
            return true
        case (nil, _?):
            return false
        default:
            return nil
        }
    }

    private func statusPriority(_ row: PlayerListRowState) -> Int {
        if row.isChallengeable { return 0 }
        if row.isWatchable { return 1 }
        if row.user.isPlaying { return 2 }
        if row.user.isAway { return 3 }
        return 4
    }
}

private struct PlayerListState {
    let rows: [PlayerListRowState]
    let visibleRows: [PlayerListRowState]
    let detailRow: PlayerListRowState?
}

private struct PlayerListRowState: Identifiable, Equatable {
    var id: FightcadeChannelUser.ID { user.id }

    let user: FightcadeChannelUser
    let isCurrentUser: Bool
    let isChallengeable: Bool
    let isChallenging: Bool
    let isWatchable: Bool
}

private enum PlayerListFilter: String, CaseIterable, Identifiable {
    case available
    case playing
    case watchable
    case away

    var id: String { rawValue }

    var title: String {
        switch self {
        case .available: "Available"
        case .playing: "Playing"
        case .watchable: "Watch"
        case .away: "Away"
        }
    }

    var symbolName: String {
        switch self {
        case .available: "gamecontroller"
        case .playing: "play.fill"
        case .watchable: "eye.fill"
        case .away: "moon.zzz.fill"
        }
    }

    func count(in rows: [PlayerListRowState]) -> Int {
        rows.filter(includes).count
    }

    func includes(_ row: PlayerListRowState) -> Bool {
        switch self {
        case .available:
            row.isChallengeable
        case .playing:
            row.user.isPlaying
        case .watchable:
            row.isWatchable
        case .away:
            row.user.isAway
        }
    }
}

private struct PlayerRow: View {
    let channel: FightcadeChannel
    let row: PlayerListRowState
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let isFocused: Bool
    let onSelect: () -> Void

    private var user: FightcadeChannelUser { row.user }

    var body: some View {
        HStack(spacing: MacadeSpacing.small) {
            Text(user.countryFlag)
                .font(.system(size: 13))
                .frame(width: 22)

            Text(user.name)
                .font(.system(size: 16, weight: .bold, design: .rounded))
                .foregroundStyle(nameColor)
                .lineLimit(1)
                .layoutPriority(1)

            if row.isWatchable {
                Image(systemName: "eye.fill")
                    .font(.system(size: 11, weight: .black))
                    .foregroundStyle(MacadeColor.neonCyan)
                    .help("Watch match")
            }

            Spacer()

            HStack(spacing: 4) {
                iconPill(statusSymbolName, accent: user.statusAccent, help: statusHelpText)
                iconPill(user.connectionSymbolName, accent: user.connectionAccent, help: user.connectionDetail)
            }
        }
        .padding(.horizontal, MacadeSpacing.small)
        .frame(height: 40)
        .background(isFocused ? MacadeColor.panel.opacity(0.82) : .clear, in: RoundedRectangle(cornerRadius: 12))
        .contentShape(Rectangle())
        .onTapGesture(perform: onSelect)
        .onTapGesture(count: 2) {
            if row.isWatchable {
                viewModel.spectate(user, in: channel)
            } else if row.isChallengeable {
                viewModel.challenge(user, in: channel)
            }
        }
        .contextMenu {
            Button("Watch Match") {
                viewModel.spectate(user, in: channel)
            }
            .disabled(!row.isWatchable)

            Menu("Challenge") {
                Button("Unranked") {
                    viewModel.challenge(user, in: channel)
                }

                ForEach(3...20, id: \.self) { rounds in
                    Button("FT\(rounds)") {
                        viewModel.challenge(user, in: channel, ranked: rounds)
                    }
                }
            }
            .disabled(!row.isChallengeable)
        }
    }

    private var nameColor: Color {
        if row.isChallenging {
            return MacadeColor.neonCyan
        }

        if row.isCurrentUser {
            return MacadeColor.warning
        }

        if user.isPlaying || user.isAway {
            return MacadeColor.inkMuted.opacity(0.58)
        }

        return row.isChallengeable || isFocused ? MacadeColor.ink : MacadeColor.inkMuted
    }

    private var statusSymbolName: String {
        row.isCurrentUser ? "person.crop.circle.fill" : user.statusSymbolName
    }

    private var statusHelpText: String {
        row.isCurrentUser ? "You" : user.listStatusText.capitalized
    }

    private func iconPill(_ symbolName: String, accent: Color, help: String) -> some View {
        Image(systemName: symbolName)
            .font(.system(size: 11, weight: .black))
            .foregroundStyle(accent)
            .frame(width: 20, height: 17)
            .background(accent.opacity(0.12), in: Capsule())
            .help(help)
    }
}
