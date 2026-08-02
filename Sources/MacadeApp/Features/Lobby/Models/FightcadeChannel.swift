import Foundation

struct FightcadeChannel: Identifiable, Equatable, Codable, Sendable {
    let id: String
    let name: String
    let title: String
    let gameID: String?
    let system: String?
    let emulator: String?
    let playerCount: Int?
    let spectatorCount: Int?
    let isRanked: Bool
    let isFavorite: Bool
    let supportsTraining: Bool

    var subtitle: String {
        [system, emulator]
            .compactMap { $0 }
            .filter { !$0.isEmpty }
            .joined(separator: " · ")
    }

    var playerCountText: String {
        playerCount.map(String.init) ?? "--"
    }

    var previewURL: URL? {
        guard let previewSource = gameID?.nonEmpty ?? name.nonEmpty else {
            return nil
        }

        let previewID = previewSource.replacingOccurrences(of: "fc1_", with: "")
        return Self.previewURL(for: previewID)
    }

    var fallbackPreviewURL: URL? {
        Self.unsupportedPreviewURL
    }

    var favoriteMatchKeys: Set<String> {
        [id, name, title, gameID ?? ""]
            .map(\.normalizedFightcadeFavoriteKey)
            .filter { !$0.isEmpty }
            .asSet
    }

    static let unsupportedPreviewURL = URL(string: "https://web.fightcade.com/static/previews/unsupported.png")

    static func previewURL(for gameID: String) -> URL? {
        let previewID = gameID.replacingOccurrences(of: "fc1_", with: "")
        return URL(string: "https://web.fightcade.com/static/previews/\(previewID).png")
    }

    func withFavorite(_ favorite: Bool) -> FightcadeChannel {
        FightcadeChannel(
            id: id,
            name: name,
            title: title,
            gameID: gameID,
            system: system,
            emulator: emulator,
            playerCount: playerCount,
            spectatorCount: spectatorCount,
            isRanked: isRanked,
            isFavorite: favorite,
            supportsTraining: supportsTraining
        )
    }
}

extension Array where Element == FightcadeChannel {
    func sortedByUserCountDescending() -> [FightcadeChannel] {
        sorted { lhs, rhs in
            let leftCount = lhs.playerCount ?? 0
            let rightCount = rhs.playerCount ?? 0
            if leftCount != rightCount {
                return leftCount > rightCount
            }

            return lhs.title.localizedCaseInsensitiveCompare(rhs.title) == .orderedAscending
        }
    }
}

extension String {
    var normalizedFightcadeFavoriteKey: String {
        trimmingCharacters(in: .whitespacesAndNewlines)
            .replacingOccurrences(of: "’", with: "'")
            .lowercased()
    }
}

private extension Array where Element == String {
    var asSet: Set<String> {
        Set(self)
    }
}
