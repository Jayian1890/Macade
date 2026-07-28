import Foundation

protocol FightcadeLobbyServicing: Sendable {
    func eventStream() async -> AsyncStream<FightcadeLobbyEvent>
    func connect(for session: AuthSession) async throws -> FightcadeDashboard
    func refreshChannels() async throws
    func searchChannels(_ request: FightcadeChannelSearchRequest) async throws -> FightcadeChannelSearchResult
    func loadChannelFilterOptions() async throws -> FightcadeChannelFilterOptions
    func loadUpcomingEvents(limit: Int) async throws -> [FightcadeEvent]
    func setFavorite(_ isFavorite: Bool, for channel: FightcadeChannel) async throws
    func join(channel: FightcadeChannel) async throws
    func leave(channel: FightcadeChannel) async throws
    func sendChat(_ message: String, to channel: FightcadeChannel, from username: String) async throws
    func challenge(_ user: FightcadeChannelUser, in channel: FightcadeChannel, ranked: Int) async throws -> FightcadeChallenge
    func acceptChallenge(_ challenge: FightcadeChallenge) async throws
    func rejectChallenge(_ challenge: FightcadeChallenge) async throws
    func cancelChallenge(_ challenge: FightcadeChallenge) async throws
    func disconnect() async
}

enum FightcadeLobbyError: LocalizedError, Equatable {
    case missingSessionCookie
    case loginExpired
    case networkUnavailable
    case rateLimited
    case unexpectedResponse(String)

    var errorDescription: String? {
        switch self {
        case .missingSessionCookie:
            "Sign out and log in again."
        case .loginExpired:
            "Sign in again."
        case .networkUnavailable:
            "Could not reach lobby."
        case .rateLimited:
            "Fightcade is rate limiting requests. Wait a moment before trying again."
        case .unexpectedResponse(let message):
            message
        }
    }
}
