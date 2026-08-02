import Foundation

struct ChannelTVMatchCandidate: Identifiable, Equatable {
    let id: String
    let title: String
    let user: FightcadeChannelUser
    let stream: FightcadeSpectatorStream
    let gameID: String
}

func channelTVChannels(from joinedChannels: [FightcadeChannel]) -> [FightcadeChannel] {
    joinedChannels.sorted { lhs, rhs in
        let leftPlayers = lhs.playerCount ?? 0
        let rightPlayers = rhs.playerCount ?? 0
        if leftPlayers != rightPlayers {
            return leftPlayers > rightPlayers
        }

        let leftSpectators = lhs.spectatorCount ?? 0
        let rightSpectators = rhs.spectatorCount ?? 0
        if leftSpectators != rightSpectators {
            return leftSpectators > rightSpectators
        }

        return lhs.title.localizedCaseInsensitiveCompare(rhs.title) == .orderedAscending
    }
}

func channelTVRandomCandidate<R: RandomNumberGenerator>(
    from candidates: [ChannelTVMatchCandidate],
    blockedIDs: Set<String>,
    using generator: inout R
) -> ChannelTVMatchCandidate? {
    candidates
        .filter { !blockedIDs.contains($0.id) }
        .randomElement(using: &generator)
}

func channelTVRandomCandidate(
    from candidates: [ChannelTVMatchCandidate],
    blockedIDs: Set<String>
) -> ChannelTVMatchCandidate? {
    var generator = SystemRandomNumberGenerator()
    return channelTVRandomCandidate(from: candidates, blockedIDs: blockedIDs, using: &generator)
}

func channelTVMatchCandidates(
    in channel: FightcadeChannel,
    users: [FightcadeChannelUser],
    session: AuthSession
) -> [ChannelTVMatchCandidate] {
    guard channel.launchEmulator != nil else {
        return []
    }

    let channelGameID = channel.launchGameID
    let watchableUsers = users.filter { user in
        guard user.isPlaying,
              !user.isCurrentUser(session: session),
              let stream = user.stream else {
            return false
        }

        if let streamGameID = stream.gameID?.nonEmpty,
           let channelGameID,
           streamGameID.caseInsensitiveCompare(channelGameID) != .orderedSame {
            return false
        }

        return stream.gameID?.nonEmpty != nil || channelGameID != nil
    }
    let grouped = Dictionary(grouping: watchableUsers) { user in
        guard let stream = user.stream else { return user.id }
        return channelTVStreamIdentity(stream: stream, gameID: stream.gameID?.nonEmpty ?? channelGameID)
    }

    return grouped.values.compactMap { users in
        let sortedUsers = users.sorted { lhs, rhs in
            lhs.name.localizedCaseInsensitiveCompare(rhs.name) == .orderedAscending
        }
        guard let user = sortedUsers.first,
              let stream = user.stream,
              let gameID = stream.gameID?.nonEmpty ?? channelGameID else {
            return nil
        }

        return ChannelTVMatchCandidate(
            id: channelTVStreamIdentity(stream: stream, gameID: gameID),
            title: sortedUsers.prefix(2).map(\.name).joined(separator: " vs "),
            user: user,
            stream: stream,
            gameID: gameID
        )
    }
    .sorted { lhs, rhs in
        lhs.title.localizedCaseInsensitiveCompare(rhs.title) == .orderedAscending
    }
}

private func channelTVStreamIdentity(stream: FightcadeSpectatorStream, gameID: String?) -> String {
    "\(gameID ?? ""):\(baseChannelTVQuarkID(stream.quarkID)):\(stream.port)"
}

private func baseChannelTVQuarkID(_ quarkID: String) -> String {
    guard let dotIndex = quarkID.lastIndex(of: "."),
          quarkID[quarkID.index(after: dotIndex)...].allSatisfy(\.isNumber) else {
        return quarkID
    }

    return String(quarkID[..<dotIndex])
}
