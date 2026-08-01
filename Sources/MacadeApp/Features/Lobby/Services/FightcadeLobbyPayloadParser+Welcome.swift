import Foundation

extension FightcadeLobbyPayloadParser {
    func favoriteChannelKeys(in payload: [String: Any]) -> Set<String> {
        var keys = Set<String>()
        collectFavoriteChannelKeys(from: payload, into: &keys)
        return keys
    }

    func browserSections(in payload: [String: Any]) -> [FightcadeWelcomeSection] {
        let sections = (payload["results"] as? [Any])?.compactMap { $0 as? [String: Any] } ?? []
        return sections.compactMap(welcomeSection).filter { !$0.isEmpty }
    }

    private func welcomeSection(from dictionary: [String: Any]) -> FightcadeWelcomeSection? {
        guard let title = welcomeStringValue(in: dictionary, keys: ["title", "name"]), !title.isEmpty else {
            return nil
        }

        let isFavoritesSection = title.localizedCaseInsensitiveContains("favorite")
        let channels = (dictionary["channels"] as? [Any] ?? [])
            .compactMap { $0 as? [String: Any] }
            .compactMap(welcomeChannel)
            .map { isFavoritesSection ? $0.withFavorite(true) : $0 }
            .uniquedByIDPreservingOrder()

        let categories = (dictionary["categories"] as? [Any] ?? [])
            .compactMap(welcomeStringValue)
            .filter { !$0.isEmpty }

        let events = (dictionary["events"] as? [Any] ?? [])
            .compactMap { $0 as? [String: Any] }
            .compactMap(welcomeEvent)

        return FightcadeWelcomeSection(title: title, channels: channels, categories: categories, events: events)
    }

    private func collectFavoriteChannelKeys(from value: Any, into keys: inout Set<String>) {
        if let dictionary = value as? [String: Any] {
            for (key, child) in dictionary {
                if key == "favorites_channels" {
                    collectStringKeys(from: child, into: &keys)
                } else {
                    collectFavoriteChannelKeys(from: child, into: &keys)
                }
            }
            return
        }

        if let array = value as? [Any] {
            for item in array {
                collectFavoriteChannelKeys(from: item, into: &keys)
            }
        }
    }

    private func collectStringKeys(from value: Any, into keys: inout Set<String>) {
        if let string = welcomeStringValue(value) {
            let key = string.normalizedFightcadeFavoriteKey
            if !key.isEmpty {
                keys.insert(key)
            }
            return
        }

        if let array = value as? [Any] {
            for item in array {
                collectStringKeys(from: item, into: &keys)
            }
        }
    }

    private func welcomeChannel(from dictionary: [String: Any]) -> FightcadeChannel? {
        guard let name = welcomeStringValue(in: dictionary, keys: ["channelname", "name", "id", "gameid"]),
              looksLikeWelcomeChannel(dictionary) else {
            return nil
        }

        let title = welcomeStringValue(in: dictionary, keys: ["channelname", "name", "title", "gamename", "description", "longname"])
            ?? name

        return FightcadeChannel(
            id: name,
            name: name,
            title: title,
            gameID: welcomeStringValue(in: dictionary, keys: ["gameid"]),
            system: welcomeStringValue(in: dictionary, keys: ["system", "platform", "console"]),
            emulator: welcomeStringValue(in: dictionary, keys: ["emulator", "emu"]),
            playerCount: welcomeIntValue(in: dictionary, keys: ["clients", "users", "players", "numplayers", "num_players", "numusers", "num_users", "online", "nplayers", "usercount", "player_count"]),
            spectatorCount: welcomeIntValue(in: dictionary, keys: ["spectators", "streams", "watching", "numspectators", "num_spectators", "spectator_count"]),
            isRanked: welcomeBoolValue(in: dictionary, keys: ["ranked"]),
            isFavorite: welcomeBoolValue(in: dictionary, keys: ["fav", "favorite", "isFavorite"]),
            supportsTraining: welcomeBoolValue(in: dictionary, keys: ["training"])
        )
    }

    private func welcomeEvent(from dictionary: [String: Any]) -> FightcadeEvent? {
        guard let name = welcomeStringValue(in: dictionary, keys: ["name", "title"]),
              let gameID = welcomeStringValue(in: dictionary, keys: ["gameid", "gameId"]),
              let milliseconds = welcomeDoubleValue(in: dictionary, keys: ["date", "time"]) else {
            return nil
        }

        return FightcadeEvent(
            name: name,
            author: welcomeStringValue(in: dictionary, keys: ["author"]),
            date: Date(timeIntervalSince1970: milliseconds / 1000),
            gameID: gameID,
            imageURL: welcomeStringValue(in: dictionary, keys: ["image", "thumbnail"]).flatMap(URL.init(string:)),
            link: welcomeStringValue(in: dictionary, keys: ["link", "url"]).flatMap(URL.init(string:)),
            region: welcomeStringValue(in: dictionary, keys: ["region"]),
            stream: welcomeStringValue(in: dictionary, keys: ["stream"]).flatMap(URL.init(string:))
        )
    }

    private func looksLikeWelcomeChannel(_ dictionary: [String: Any]) -> Bool {
        let channelKeys = ["channelname", "gameid", "gamename", "emulator", "system", "ranked", "clients", "available_for"]
        return channelKeys.contains { dictionary[$0] != nil }
    }

    private func welcomeStringValue(_ value: Any) -> String? {
        if let string = value as? String {
            return string
        }

        if let number = value as? NSNumber {
            return number.stringValue
        }

        return nil
    }

    private func welcomeStringValue(in dictionary: [String: Any], keys: [String]) -> String? {
        for key in keys {
            guard let rawValue = dictionary[key], let value = welcomeStringValue(rawValue) else {
                continue
            }

            if !value.isEmpty {
                return value
            }
        }

        return nil
    }

    private func welcomeIntValue(in dictionary: [String: Any], keys: [String]) -> Int? {
        for key in keys {
            if let value = dictionary[key] as? Int {
                return value
            }

            if let number = dictionary[key] as? NSNumber {
                return number.intValue
            }

            if let string = dictionary[key] as? String, let value = Int(string) {
                return value
            }

            if let array = dictionary[key] as? [Any] {
                return array.count
            }
        }

        return nil
    }

    private func welcomeDoubleValue(in dictionary: [String: Any], keys: [String]) -> Double? {
        for key in keys {
            if let value = dictionary[key] as? Double {
                return value
            }

            if let number = dictionary[key] as? NSNumber {
                return number.doubleValue
            }

            if let string = dictionary[key] as? String, let value = Double(string) {
                return value
            }
        }

        return nil
    }

    private func welcomeBoolValue(in dictionary: [String: Any], keys: [String]) -> Bool {
        for key in keys {
            if let value = dictionary[key] as? Bool {
                return value
            }

            if let number = dictionary[key] as? NSNumber {
                return number.boolValue
            }

            if let string = dictionary[key] as? String {
                return ["1", "true", "yes"].contains(string.lowercased())
            }
        }

        return false
    }
}

private extension Array where Element == FightcadeChannel {
    func uniquedByIDPreservingOrder() -> [FightcadeChannel] {
        var seen = Set<String>()
        var unique: [FightcadeChannel] = []

        for channel in self where seen.insert(channel.id).inserted {
            unique.append(channel)
        }

        return unique
    }
}
