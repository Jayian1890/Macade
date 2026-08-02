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

    var fightcadeReplayLink: FightcadeReplayLink? {
        FightcadeReplayLink.first(in: body)
    }
}

struct FightcadeReplayLink: Equatable, Sendable {
    let url: URL
    let emulator: String
    let gameID: String
    let replayID: String

    var id: String {
        "\(emulator):\(gameID):\(replayID)"
    }

    var displayTitle: String {
        "\(gameID) · \(replayID)"
    }

    static func first(in text: String) -> FightcadeReplayLink? {
        let pattern = #"https?://replay\.fightcade\.com/([A-Za-z0-9_-]+)/([A-Za-z0-9_-]+)/([A-Za-z0-9-]+)"#
        guard let regex = try? NSRegularExpression(pattern: pattern, options: [.caseInsensitive]),
              let match = regex.firstMatch(in: text, range: NSRange(text.startIndex..., in: text)),
              match.numberOfRanges == 4,
              let urlRange = Range(match.range(at: 0), in: text),
              let emulatorRange = Range(match.range(at: 1), in: text),
              let gameRange = Range(match.range(at: 2), in: text),
              let replayRange = Range(match.range(at: 3), in: text),
              let url = URL(string: String(text[urlRange])) else {
            return nil
        }

        return FightcadeReplayLink(
            url: url,
            emulator: String(text[emulatorRange]),
            gameID: String(text[gameRange]),
            replayID: String(text[replayRange])
        )
    }
}
