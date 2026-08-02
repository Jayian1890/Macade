import Foundation
import Observation

enum LobbyBrowserFilter: Equatable {
    case all
    case ranked
    case favorites
}

enum FightcadeBrowserLayoutMode: String, CaseIterable, Sendable {
    case grid
    case list
}

enum FightcadeChannelBrowserSort: String, CaseIterable, Identifiable, Sendable {
    case playersDescending
    case playersAscending
    case spectatorsDescending
    case spectatorsAscending
    case titleAscending
    case titleDescending
    case systemAscending
    case systemDescending
    case rankedFirst
    case favoritesFirst
    case joinedFirst

    var id: String { rawValue }

    var title: String {
        switch self {
        case .playersDescending: "Players High to Low"
        case .playersAscending: "Players Low to High"
        case .spectatorsDescending: "Spectators High to Low"
        case .spectatorsAscending: "Spectators Low to High"
        case .titleAscending: "Title A to Z"
        case .titleDescending: "Title Z to A"
        case .systemAscending: "System A to Z"
        case .systemDescending: "System Z to A"
        case .rankedFirst: "Ranked First"
        case .favoritesFirst: "Favorites First"
        case .joinedFirst: "Joined First"
        }
    }

    var shortTitle: String {
        switch self {
        case .playersDescending: "Players"
        case .playersAscending: "Low Pop"
        case .spectatorsDescending: "Spectators"
        case .spectatorsAscending: "Low Watch"
        case .titleAscending: "A-Z"
        case .titleDescending: "Z-A"
        case .systemAscending: "System"
        case .systemDescending: "System Z"
        case .rankedFirst: "Ranked"
        case .favoritesFirst: "Favorites"
        case .joinedFirst: "Joined"
        }
    }

    var symbolName: String {
        switch self {
        case .playersDescending, .playersAscending: "person.2.fill"
        case .spectatorsDescending, .spectatorsAscending: "eye.fill"
        case .titleAscending, .titleDescending: "textformat.abc"
        case .systemAscending, .systemDescending: "rectangle.3.group"
        case .rankedFirst: "rosette"
        case .favoritesFirst: "star.fill"
        case .joinedFirst: "checkmark.circle.fill"
        }
    }

    func sorted(_ channels: [FightcadeChannel], joinedChannelIDs: Set<FightcadeChannel.ID>) -> [FightcadeChannel] {
        channels.sorted { compare($0, $1, joinedChannelIDs: joinedChannelIDs) }
    }

    private func compare(_ lhs: FightcadeChannel, _ rhs: FightcadeChannel, joinedChannelIDs: Set<FightcadeChannel.ID>) -> Bool {
        switch self {
        case .playersDescending:
            return activityCompare(lhs, rhs)
        case .playersAscending:
            return countCompare(lhs.playerCount, rhs.playerCount, highFirst: false) ?? titleCompare(lhs, rhs)
        case .spectatorsDescending:
            return countCompare(lhs.spectatorCount, rhs.spectatorCount, highFirst: true) ?? activityCompare(lhs, rhs)
        case .spectatorsAscending:
            return countCompare(lhs.spectatorCount, rhs.spectatorCount, highFirst: false) ?? titleCompare(lhs, rhs)
        case .titleAscending:
            return titleCompare(lhs, rhs)
        case .titleDescending:
            return titleCompare(rhs, lhs)
        case .systemAscending:
            return textCompare(lhs.system, rhs.system, ascending: true) ?? titleCompare(lhs, rhs)
        case .systemDescending:
            return textCompare(lhs.system, rhs.system, ascending: false) ?? titleCompare(lhs, rhs)
        case .rankedFirst:
            return boolCompare(lhs.isRanked, rhs.isRanked) ?? activityCompare(lhs, rhs)
        case .favoritesFirst:
            return boolCompare(lhs.isFavorite, rhs.isFavorite) ?? activityCompare(lhs, rhs)
        case .joinedFirst:
            return boolCompare(joinedChannelIDs.contains(lhs.id), joinedChannelIDs.contains(rhs.id)) ?? activityCompare(lhs, rhs)
        }
    }

    private func activityCompare(_ lhs: FightcadeChannel, _ rhs: FightcadeChannel) -> Bool {
        countCompare(lhs.playerCount, rhs.playerCount, highFirst: true)
            ?? countCompare(lhs.spectatorCount, rhs.spectatorCount, highFirst: true)
            ?? titleCompare(lhs, rhs)
    }

    private func titleCompare(_ lhs: FightcadeChannel, _ rhs: FightcadeChannel) -> Bool {
        textCompare(lhs.title, rhs.title, ascending: true)
            ?? textCompare(lhs.name, rhs.name, ascending: true)
            ?? (lhs.id.localizedCaseInsensitiveCompare(rhs.id) == .orderedAscending)
    }

    private func countCompare(_ lhs: Int?, _ rhs: Int?, highFirst: Bool) -> Bool? {
        let leftCount = lhs ?? 0
        let rightCount = rhs ?? 0
        guard leftCount != rightCount else { return nil }
        return highFirst ? leftCount > rightCount : leftCount < rightCount
    }

    private func boolCompare(_ lhs: Bool, _ rhs: Bool) -> Bool? {
        lhs == rhs ? nil : lhs
    }

    private func textCompare(_ lhs: String?, _ rhs: String?, ascending: Bool) -> Bool? {
        let left = lhs?.trimmingCharacters(in: .whitespacesAndNewlines) ?? ""
        let right = rhs?.trimmingCharacters(in: .whitespacesAndNewlines) ?? ""
        if left.isEmpty != right.isEmpty { return !left.isEmpty }

        let result = left.localizedCaseInsensitiveCompare(right)
        guard result != .orderedSame else { return nil }
        return ascending ? result == .orderedAscending : result == .orderedDescending
    }
}

struct FightcadeChannelSearchRequest: Equatable, Sendable {
    var filter: String = ""
    var genre: String?
    var year: String?
    var system: String?
    var ranked: Bool?
    var favorites = false
    var page = 1
    var paginated = true

    var hasServerCriteria: Bool {
        !filter.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
            || genre?.isEmpty == false
            || year?.isEmpty == false
            || system?.isEmpty == false
            || ranked != nil
            || favorites
    }

    var trimmedFilter: String {
        filter.trimmingCharacters(in: .whitespacesAndNewlines)
    }

    func payload() -> [String: Any] {
        var payload: [String: Any] = [
            "req": "channels",
            "paginated": paginated,
            "page": page
        ]

        if !trimmedFilter.isEmpty {
            payload["filter"] = trimmedFilter
        }

        payload["genre"] = genre
        payload["year"] = year
        payload["system"] = system
        payload["ranked"] = ranked
        payload["favorites"] = favorites
        return payload
    }
}

struct FightcadeChannelSearchResult: Equatable, Sendable {
    let channels: [FightcadeChannel]
    let page: Int
    let hasMorePages: Bool
}

struct FightcadeChannelFilterOptions: Equatable, Sendable {
    var systems: [String] = []
    var genres: [String] = []
    var years: [String] = []
}

struct FightcadeWelcomeSection: Identifiable, Equatable, Sendable {
    let title: String
    let channels: [FightcadeChannel]
    let categories: [String]
    let events: [FightcadeEvent]

    var id: String { title }

    var isEmpty: Bool {
        channels.isEmpty && categories.isEmpty && events.isEmpty
    }
}

struct FightcadeEvent: Identifiable, Equatable, Sendable {
    let name: String
    let author: String?
    let date: Date
    let gameID: String
    let imageURL: URL?
    let link: URL?
    let region: String?
    let stream: URL?

    var id: String { "\(gameID):\(date.timeIntervalSince1970):\(name)" }

    var previewURL: URL? {
        if let imageURL {
            return imageURL
        }

        return gamePreviewURL
    }

    var fallbackPreviewURLs: [URL] {
        [gamePreviewURL, FightcadeChannel.unsupportedPreviewURL].compactMap { $0 }
    }

    private var gamePreviewURL: URL? {
        FightcadeChannel.previewURL(for: gameID)
    }
}

@MainActor
@Observable
final class FightcadeChannelBrowserState {
    var query = ""
    var mode: LobbyBrowserFilter = .all
    var selectedSystem: String?
    var selectedGenre: String?
    var selectedYear: String?
    var selectedPreviewChannelID: FightcadeChannel.ID?
    var layoutMode: FightcadeBrowserLayoutMode = .grid
    var sort = FightcadeChannelBrowserSort.playersDescending
    var results: [FightcadeChannel] = []
    var filterOptions = FightcadeChannelFilterOptions()
    var isLoadingResults = false
    var isLoadingFilterOptions = false
    var isShowingFilters = false
    var page = 1
    var hasMorePages = false
    var lastSearchFailed = false

    @ObservationIgnored var searchTask: Task<Void, Never>?

    var searchRequest: FightcadeChannelSearchRequest {
        FightcadeChannelSearchRequest(
            filter: query,
            genre: selectedGenre,
            year: selectedYear,
            system: selectedSystem,
            ranked: mode == .ranked ? true : nil,
            favorites: mode == .favorites,
            page: page,
            paginated: true
        )
    }

    var hasActiveFilters: Bool {
        mode != .all
            || selectedSystem != nil
            || selectedGenre != nil
            || selectedYear != nil
            || !query.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
    }

    func resetFilters() {
        query = ""
        mode = .all
        selectedSystem = nil
        selectedGenre = nil
        selectedYear = nil
        page = 1
    }
}
