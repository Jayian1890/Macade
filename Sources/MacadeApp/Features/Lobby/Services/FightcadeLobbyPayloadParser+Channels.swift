extension FightcadeLobbyPayloadParser {
    func channels(in payload: [String: Any]) -> [FightcadeChannel] {
        var dictionaries: [[String: Any]] = []
        collectChannelDictionaries(from: payload["channels"], into: &dictionaries)
        collectChannelDictionaries(from: payload["results"], into: &dictionaries)
        return dictionaries
            .compactMap(channel)
            .uniquedByID()
            .sorted(by: sortChannels)
    }

    private func collectChannelDictionaries(from value: Any?, into result: inout [[String: Any]]) {
        if let values = value as? [Any] {
            for value in values {
                collectChannelDictionaries(from: value, into: &result)
            }
            return
        }

        guard let dictionary = value as? [String: Any] else { return }
        if looksLikeChannel(dictionary) {
            result.append(dictionary)
        }
        collectChannelDictionaries(from: dictionary["channels"], into: &result)
        collectChannelDictionaries(from: dictionary["results"], into: &result)
    }

    private func channel(from dictionary: [String: Any]) -> FightcadeChannel? {
        guard let name = stringValue(in: dictionary, keys: ["channelname", "name", "id", "gameid"]),
              looksLikeChannel(dictionary) else {
            return nil
        }
        let title = stringValue(
            in: dictionary,
            keys: ["channelname", "name", "title", "gamename", "description", "longname"]
        ) ?? name

        return FightcadeChannel(
            id: name,
            name: name,
            title: title,
            gameID: stringValue(in: dictionary, keys: ["gameid"]),
            system: stringValue(in: dictionary, keys: ["system", "platform", "console"]),
            emulator: stringValue(in: dictionary, keys: ["emulator", "emu"]),
            playerCount: intValue(in: dictionary, keys: ["clients", "users", "players", "numplayers", "num_players", "numusers", "num_users", "online", "nplayers", "usercount", "player_count"]),
            spectatorCount: intValue(in: dictionary, keys: ["spectators", "streams", "watching", "numspectators", "num_spectators", "spectator_count"]),
            isRanked: boolValue(in: dictionary, keys: ["ranked"]),
            isFavorite: boolValue(in: dictionary, keys: ["fav", "favorite", "isFavorite"]),
            supportsTraining: boolValue(in: dictionary, keys: ["training"])
        )
    }

    private func sortChannels(_ lhs: FightcadeChannel, _ rhs: FightcadeChannel) -> Bool {
        let leftPlayers = lhs.playerCount ?? 0
        let rightPlayers = rhs.playerCount ?? 0
        if leftPlayers != rightPlayers {
            return leftPlayers > rightPlayers
        }
        return lhs.name.localizedCaseInsensitiveCompare(rhs.name) == .orderedAscending
    }

    private func looksLikeChannel(_ dictionary: [String: Any]) -> Bool {
        let channelKeys = ["channelname", "gameid", "gamename", "emulator", "system", "ranked", "clients", "available_for"]
        return channelKeys.contains { dictionary[$0] != nil }
    }
}

private extension Array where Element == FightcadeChannel {
    func uniquedByID() -> [FightcadeChannel] {
        var seen = Set<String>()
        return filter { seen.insert($0.id).inserted }
    }
}
