import Foundation

struct FightcadeChannelUser: Identifiable, Equatable, Sendable {
    let id: String
    let name: String
    let gravatarHash: String?
    let countryCode: String?
    let ping: Int?
    let virtualPing: Int?
    let rank: Int?
    let matchCount: Int?
    let rankedSetting: Int?
    let region: String?
    let isAway: Bool
    let isPlaying: Bool
    let isUsingWifi: Bool
    let isUsingProxy: Bool
    let preventsBadChallenges: Bool
    let preventsWifiChallenges: Bool
    let stream: FightcadeSpectatorStream?

    var displayRank: String? {
        guard let rank, rank > 0 else {
            return nil
        }

        switch rank {
        case 1:
            return "E"
        case 2:
            return "D"
        case 3:
            return "C"
        case 4:
            return "B"
        case 5:
            return "A"
        default:
            return "\(rank)"
        }
    }

    var avatarURL: URL? {
        guard let gravatarHash, !gravatarHash.isEmpty else {
            return nil
        }

        return URL(string: "https://www.gravatar.com/avatar/\(gravatarHash)?s=68&d=retro&r=g")
    }
}

struct FightcadeSpectatorStream: Equatable, Sendable {
    let gameID: String?
    let quarkID: String
    let port: Int
}

struct FightcadeChallengeWarning: Equatable, Sendable {
    let username: String?
    let channelName: String?
    let challengeID: Int?
    let message: String
}

struct FightcadeUserStatusUpdate: Equatable, Sendable {
    let username: String
    let channelName: String?
    let isAway: Bool?
    let isPlaying: Bool?
    let isUsingWifi: Bool?
    let stream: FightcadeSpectatorStream?
}

struct FightcadeLiveStreamUpdate: Equatable, Sendable {
    let channelName: String?
    let players: [String]
    let stream: FightcadeSpectatorStream
}

enum FightcadeLobbyEvent: Sendable {
    case channelsUpdated([FightcadeChannel])
    case joinedChannel(String)
    case leftChannel(String)
    case usersUpdated(String, [FightcadeChannelUser])
    case userJoined(String, FightcadeChannelUser)
    case userLeft(String, String)
    case userStatusUpdated(FightcadeUserStatusUpdate)
    case liveStreamUpdated(FightcadeLiveStreamUpdate)
    case chatMessage(FightcadeChatMessage)
    case challengeReceived(FightcadeChallenge)
    case challengeCanceled(FightcadeChallenge)
    case challengeRejected(FightcadeChallenge)
    case challengeAccepted(FightcadeChallenge)
    case challengeRestricted(FightcadeChallengeWarning)
    case matchStarted(FightcadeMatchStart)
    case error(String)
}
