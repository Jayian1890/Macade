import Foundation

struct FightcadeChatMessage: Identifiable, Equatable, Sendable {
    enum Kind: Equatable, Sendable {
        case user
        case system
        case local
        case motd
    }

    let id: UUID
    let channelName: String
    let username: String
    let body: String
    let kind: Kind
    let events: [FightcadeEvent]
    let sentAt: Date

    init(
        id: UUID = UUID(),
        channelName: String,
        username: String,
        body: String,
        kind: Kind,
        events: [FightcadeEvent] = [],
        sentAt: Date = .now
    ) {
        self.id = id
        self.channelName = channelName
        self.username = username
        self.body = body
        self.kind = kind
        self.events = events
        self.sentAt = sentAt
    }

    var isJoinLeaveSystemMessage: Bool {
        guard kind == .system else {
            return false
        }

        let normalized = body.trimmingCharacters(in: .whitespacesAndNewlines).lowercased()
        return normalized.hasPrefix("joined ")
            || normalized.hasPrefix("left ")
            || normalized.contains(" joined ")
            || normalized.contains(" left ")
    }
}
