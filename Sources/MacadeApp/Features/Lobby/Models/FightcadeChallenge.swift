import Foundation

struct FightcadeChallenge: Identifiable, Equatable, Sendable {
    static let defaultRankedValue = 3
    static let rankedValues = [2, 3, 5, 10, 20]

    let username: String
    let channelName: String
    let challengeID: Int
    let ranked: Int

    var id: String {
        "\(channelName):\(username):\(challengeID)"
    }
}
