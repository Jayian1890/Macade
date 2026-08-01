import Foundation

extension AuthenticatedHomeViewModel {
    var friendRows: [FightcadeFriendRowState] {
        friends.map(friendRow).sorted { lhs, rhs in
            if lhs.isOnline != rhs.isOnline {
                return lhs.isOnline
            }

            return lhs.title.localizedCaseInsensitiveCompare(rhs.title) == .orderedAscending
        }
    }

    var canAddFriendFromDraft: Bool {
        canAddFriend(named: friendDraft)
    }

    func loadFriendsIfNeeded() async {
        guard !hasLoadedFriends else {
            return
        }

        friends = await friendStore.loadFriends(for: session)
        hasLoadedFriends = true
    }

    func addFriendFromDraft() {
        guard addFriend(named: friendDraft) else {
            return
        }

        friendDraft = ""
    }

    @discardableResult
    func addFriend(_ user: FightcadeChannelUser) -> Bool {
        addFriend(named: user.name, displayName: user.name)
    }

    @discardableResult
    func addFriend(named username: String, displayName: String? = nil) -> Bool {
        guard canAddFriend(named: username) else {
            return false
        }

        let friend = FightcadeFriend(username: username, displayName: displayName)
        friends.append(friend)
        friends = friends.uniquedAndSorted()
        saveFriends()
        return true
    }

    func removeFriend(_ friend: FightcadeFriend) {
        removeFriend(named: friend.username)
    }

    func removeFriend(_ user: FightcadeChannelUser) {
        removeFriend(named: user.name)
    }

    func removeFriend(named username: String) {
        let normalized = FightcadeFriend.normalized(username)
        guard friends.contains(where: { $0.id == normalized }) else {
            return
        }

        friends.removeAll { $0.id == normalized }
        saveFriends()
    }

    func isFriend(_ username: String) -> Bool {
        let normalized = FightcadeFriend.normalized(username)
        return friends.contains { $0.id == normalized }
    }

    func openFriend(_ row: FightcadeFriendRowState) {
        guard let user = row.user,
              let channel = row.channel else {
            return
        }

        requestPlayerListFocus(username: user.name, channelName: channel.name, selectChannel: true)
    }

    func challengeFriend(_ row: FightcadeFriendRowState, ranked: Int = FightcadeChallenge.defaultRankedValue) {
        guard let user = row.user,
              let channel = row.channel,
              row.isChallengeable else {
            return
        }

        challenge(user, in: channel, ranked: ranked)
    }

    func spectateFriend(_ row: FightcadeFriendRowState) {
        guard let user = row.user,
              let channel = row.channel,
              row.isWatchable else {
            return
        }

        spectate(user, in: channel)
    }

    private func canAddFriend(named username: String) -> Bool {
        let normalized = FightcadeFriend.normalized(username)
        guard !normalized.isEmpty,
              normalized != FightcadeFriend.normalized(session.username),
              normalized != FightcadeFriend.normalized(session.displayName) else {
            return false
        }

        return !friends.contains { $0.id == normalized }
    }

    private func friendRow(for friend: FightcadeFriend) -> FightcadeFriendRowState {
        let presence = friendPresence(for: friend)
        let user = presence?.user
        let channel = presence?.channel
        let isChallengeable = user.flatMap { user in channel.map { canChallenge(user, in: $0) } } ?? false
        let isChallenging = user.flatMap { user in channel.map { isChallenging(user, in: $0) } } ?? false
        let isWatchable = user.flatMap { user in channel.map { canSpectate(user, in: $0) } } ?? false

        return FightcadeFriendRowState(
            friend: friend,
            user: user,
            channel: channel,
            isChallengeable: isChallengeable,
            isChallenging: isChallenging,
            isWatchable: isWatchable
        )
    }

    private func friendPresence(for friend: FightcadeFriend) -> (user: FightcadeChannelUser, channel: FightcadeChannel)? {
        let channelOrder = channelsForFriendLookup()
        for channel in channelOrder {
            guard let user = usersByChannel[channel.name]?.first(where: { FightcadeFriend.normalized($0.name) == friend.id }) else {
                continue
            }

            return (user, channel)
        }

        return nil
    }

    private func channelsForFriendLookup() -> [FightcadeChannel] {
        var ordered: [FightcadeChannel] = []
        if let selectedChannel {
            ordered.append(selectedChannel)
        }

        ordered.append(contentsOf: joinedChannels)
        ordered.append(contentsOf: channels.filter { usersByChannel[$0.name] != nil })
        var seen = Set<FightcadeChannel.ID>()
        return ordered.filter { seen.insert($0.id).inserted }
    }

    private func saveFriends() {
        let snapshot = friends
        Task { await friendStore.saveFriends(snapshot, for: session) }
    }
}

private extension Array where Element == FightcadeFriend {
    func uniquedAndSorted() -> [FightcadeFriend] {
        var seen = Set<String>()
        var result: [FightcadeFriend] = []

        for friend in self where !friend.username.isEmpty && seen.insert(friend.id).inserted {
            result.append(friend)
        }

        return result.sorted {
            $0.title.localizedCaseInsensitiveCompare($1.title) == .orderedAscending
        }
    }
}
