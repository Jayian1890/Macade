import Foundation

struct AuthSession: Equatable, Sendable {
    let username: String
    let displayName: String
    let sessionCookie: String?
    let launcherToken: String?
    let signedInAt: Date

    init(
        username: String,
        displayName: String,
        sessionCookie: String? = nil,
        launcherToken: String? = nil,
        signedInAt: Date = .now
    ) {
        self.username = username
        self.displayName = displayName
        self.sessionCookie = sessionCookie
        self.launcherToken = launcherToken
        self.signedInAt = signedInAt
    }
}
