import Foundation

extension AuthenticatedHomeViewModel {
    func applyUserStatusUpdate(_ update: FightcadeUserStatusUpdate) {
        let targetChannels = targetChannelNames(channelName: update.channelName, gameID: update.stream?.gameID)

        for channelName in targetChannels {
            guard var users = usersByChannel[channelName],
                  let userIndex = users.firstIndex(where: { user in
                      user.name.compare(update.username, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
                  }) else {
                continue
            }

            let user = users[userIndex]
            users[userIndex] = FightcadeChannelUser(
                id: user.id,
                name: user.name,
                gravatarHash: user.gravatarHash,
                countryCode: user.countryCode,
                ping: user.ping,
                virtualPing: user.virtualPing,
                rank: user.rank,
                matchCount: user.matchCount,
                rankedSetting: user.rankedSetting,
                region: user.region,
                isAway: update.isAway ?? user.isAway,
                isPlaying: update.isPlaying ?? user.isPlaying,
                isUsingWifi: update.isUsingWifi ?? user.isUsingWifi,
                isUsingProxy: user.isUsingProxy,
                preventsBadChallenges: user.preventsBadChallenges,
                preventsWifiChallenges: user.preventsWifiChallenges,
                stream: update.stream ?? (update.isPlaying == false ? nil : user.stream)
            )
            usersByChannel[channelName] = users
        }
    }

    func targetChannelNames(channelName: String?, gameID: String?) -> [String] {
        if let channelName {
            if usersByChannel[channelName] != nil {
                return [channelName]
            }

            if let channel = channels.first(where: { $0.launchGameID == channelName }) {
                return [channel.name]
            }

            return [channelName]
        }

        if let gameID = gameID?.nonEmpty {
            return channels.filter { $0.launchGameID == gameID }.map(\.name)
        }

        return Array(usersByChannel.keys)
    }
}
