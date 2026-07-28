import Foundation

struct FightcadeDashboard: Equatable, Sendable {
    let connectedUsername: String
    let welcomeMessage: String?
    let channels: [FightcadeChannel]
    let loadedAt: Date

    init(
        connectedUsername: String,
        welcomeMessage: String?,
        channels: [FightcadeChannel],
        loadedAt: Date = .now
    ) {
        self.connectedUsername = connectedUsername
        self.welcomeMessage = welcomeMessage
        self.channels = channels
        self.loadedAt = loadedAt
    }
}
