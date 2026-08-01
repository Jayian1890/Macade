import Foundation

struct FightcadeFriend: Identifiable, Codable, Equatable, Sendable {
    let username: String
    let displayName: String?
    let addedAt: Date

    var id: String { Self.normalized(username) }

    var title: String {
        displayName?.nonEmpty ?? username
    }

    init(username: String, displayName: String? = nil, addedAt: Date = .now) {
        self.username = username.trimmingCharacters(in: .whitespacesAndNewlines)
        self.displayName = displayName?.trimmingCharacters(in: .whitespacesAndNewlines).nonEmpty
        self.addedAt = addedAt
    }

    static func normalized(_ value: String) -> String {
        value.trimmingCharacters(in: .whitespacesAndNewlines)
            .folding(options: [.caseInsensitive, .diacriticInsensitive], locale: nil)
            .lowercased()
    }
}

struct FightcadeFriendRowState: Identifiable, Equatable {
    let friend: FightcadeFriend
    let user: FightcadeChannelUser?
    let channel: FightcadeChannel?
    let isChallengeable: Bool
    let isChallenging: Bool
    let isWatchable: Bool

    var id: String { friend.id }

    var title: String {
        user?.name ?? friend.title
    }

    var statusText: String {
        guard let user else {
            return "Offline"
        }

        if user.isPlaying {
            return channel.map { "Playing \($0.title)" } ?? "Playing"
        }

        if user.isAway {
            return channel.map { "Away in \($0.title)" } ?? "Away"
        }

        return channel.map { "Ready in \($0.title)" } ?? "Ready"
    }

    var isOnline: Bool { user != nil }
}
