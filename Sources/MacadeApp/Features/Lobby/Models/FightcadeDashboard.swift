import Foundation

struct FightcadeDashboard: Equatable, Sendable {
    let connectedUsername: String
    let welcomeMessage: String?
    let channels: [FightcadeChannel]
    let browserSections: [FightcadeWelcomeSection]
    let loadedAt: Date

    init(
        connectedUsername: String,
        welcomeMessage: String?,
        channels: [FightcadeChannel],
        browserSections: [FightcadeWelcomeSection] = [],
        loadedAt: Date = .now
    ) {
        self.connectedUsername = connectedUsername
        self.welcomeMessage = welcomeMessage
        self.channels = channels
        self.browserSections = browserSections
        self.loadedAt = loadedAt
    }
}
