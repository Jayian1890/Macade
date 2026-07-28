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
        let imageID = ["kof9", "kof2", "kf2k"].contains { previewID.contains($0) } ? "unsupported" : previewID
        return URL(string: "https://web.fightcade.com/static/previews/\(imageID).png")
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
