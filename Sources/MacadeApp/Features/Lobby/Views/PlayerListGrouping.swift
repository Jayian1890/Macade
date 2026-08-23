import SwiftUI

enum PlayerListGroup: String, CaseIterable, Identifiable {
    case status
    case rank
    case ping

    var id: String { rawValue }

    var title: String {
        switch self {
        case .status: "Status"
        case .rank: "Rank"
        case .ping: "Connection"
        }
    }

    var symbolName: String {
        switch self {
        case .status: "circle.grid.2x2.fill"
        case .rank: "rosette"
        case .ping: "speedometer"
        }
    }
}

struct PlayerListGroupSection: Identifiable {
    let id: String
    let title: String
    let symbolName: String
    let rows: [PlayerListRowState]
    let watchMatches: [WatchMatchRowState]

    var isEmpty: Bool { rows.isEmpty && watchMatches.isEmpty }
}

enum PlayerListGrouping {
    static func sections(
        for group: PlayerListGroup,
        rows: [PlayerListRowState],
        watchMatches: [WatchMatchRowState]
    ) -> [PlayerListGroupSection] {
        switch group {
        case .status:
            return statusSections(rows: rows, watchMatches: watchMatches)
        case .rank:
            return rankSections(rows: rows)
        case .ping:
            return pingSections(rows: rows)
        }
    }

    private static func statusSections(
        rows: [PlayerListRowState],
        watchMatches: [WatchMatchRowState]
    ) -> [PlayerListGroupSection] {
        let watchableIDs = Set(watchMatches.flatMap { $0.rows.map(\.id) })
        return [
            PlayerListGroupSection(
                id: "available",
                title: "Available",
                symbolName: "gamecontroller",
                rows: rows.filter { $0.isChallengeable && !$0.user.isPlaying },
                watchMatches: []
            ),
            PlayerListGroupSection(
                id: "playing",
                title: "Playing",
                symbolName: "play.fill",
                rows: rows.filter { $0.user.isPlaying && !watchableIDs.contains($0.id) },
                watchMatches: []
            ),
            PlayerListGroupSection(
                id: "watching",
                title: "Watch",
                symbolName: "eye.fill",
                rows: [],
                watchMatches: watchMatches
            ),
            PlayerListGroupSection(
                id: "away",
                title: "Away",
                symbolName: "moon.zzz.fill",
                rows: rows.filter { $0.user.isAway && !$0.user.isPlaying },
                watchMatches: []
            )
        ]
        .filter { !$0.isEmpty }
    }

    private static func rankSections(rows: [PlayerListRowState]) -> [PlayerListGroupSection] {
        let order = ["S", "A", "B", "C", "D", "E", "Unranked"]
        let grouped = Dictionary(grouping: rows) { rankKey(for: $0.user) }
        return order.compactMap { key in
            guard let groupedRows = grouped[key], !groupedRows.isEmpty else {
                return nil
            }

            return PlayerListGroupSection(
                id: "rank-\(key)",
                title: key,
                symbolName: "rosette",
                rows: groupedRows,
                watchMatches: []
            )
        }
    }

    private static func pingSections(rows: [PlayerListRowState]) -> [PlayerListGroupSection] {
        let bands: [(id: String, title: String, symbol: String, match: (Int?) -> Bool)] = [
            ("good", "Good", "network", { ping in (ping ?? Int.max) < 90 }),
            ("fair", "Fair", "network.badge.shield.half.filled", { ping in
                guard let ping else { return false }
                return ping >= 90 && ping < 150
            }),
            ("poor", "Poor", "exclamationmark.triangle.fill", { ping in (ping ?? 0) >= 150 }),
            ("unknown", "Unknown", "questionmark.circle.fill", { $0 == nil })
        ]

        return bands.compactMap { band in
            let groupedRows = rows.filter { band.match($0.user.ping) }
            guard !groupedRows.isEmpty else { return nil }
            return PlayerListGroupSection(
                id: "ping-\(band.id)",
                title: band.title,
                symbolName: band.symbol,
                rows: groupedRows,
                watchMatches: []
            )
        }
    }

    private static func rankKey(for user: FightcadeChannelUser) -> String {
        guard let rank = user.rank, rank > 0 else {
            return "Unranked"
        }

        switch rank {
        case 1: return "E"
        case 2: return "D"
        case 3: return "C"
        case 4: return "B"
        case 5: return "A"
        default: return "S"
        }
    }
}

enum PlayerListSort: String, CaseIterable, Identifiable {
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

struct PlayerListState {
    let rows: [PlayerListRowState]
    let visibleRows: [PlayerListRowState]
    let detailRow: PlayerListRowState?
}

struct PlayerListRowState: Identifiable, Equatable {
    var id: FightcadeChannelUser.ID { user.id }

    let user: FightcadeChannelUser
    let isCurrentUser: Bool
    let isChallengeable: Bool
    let isChallenging: Bool
    let isWatchable: Bool
}
