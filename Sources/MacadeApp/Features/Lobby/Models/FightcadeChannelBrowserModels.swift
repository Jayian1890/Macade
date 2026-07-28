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

struct FightcadeEvent: Identifiable, Equatable, Sendable {
    let name: String
    let author: String?
    let date: Date
    let gameID: String
    let link: URL?
    let region: String?
    let stream: URL?

    var id: String { "\(gameID):\(date.timeIntervalSince1970):\(name)" }

    var previewURL: URL? {
        let imageID = gameID.replacingOccurrences(of: "fc1_", with: "")
        let previewID = ["kof9", "kof2", "kf2k"].contains { imageID.contains($0) } ? "unsupported" : imageID
        return URL(string: "https://web.fightcade.com/static/previews/\(previewID).png")
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
