import Foundation
import Observation

enum LobbyBrowserFilter: Equatable {
    case all
    case ranked
    case favorites
}

struct FightcadeBrowserCategory: Identifiable, Equatable, Sendable {
    enum Kind: Equatable, Sendable {
        case all
        case ranked
        case favorites
        case system(String)
    }

    let kind: Kind
    let title: String
    let gameCount: Int
    let playerCount: Int

    var id: String {
        switch kind {
        case .all: "all"
        case .ranked: "ranked"
        case .favorites: "favorites"
        case .system(let system): "system:\(system)"
        }
    }
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
    var selectedPreviewChannelID: FightcadeChannel.ID?
    var isSearchingRemotely = false

    var hasActiveFilters: Bool {
        mode != .all
            || selectedSystem != nil
            || !query.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
    }

    func resetFilters() {
        query = ""
        mode = .all
        selectedSystem = nil
    }
}
