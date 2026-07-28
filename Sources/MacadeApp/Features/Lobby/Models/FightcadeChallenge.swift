import Foundation

struct FightcadeChallenge: Identifiable, Equatable, Sendable {
    let username: String
    let channelName: String
    let challengeID: Int
    let ranked: Int

    var id: String {
        "\(channelName):\(username):\(challengeID)"
    }
}
