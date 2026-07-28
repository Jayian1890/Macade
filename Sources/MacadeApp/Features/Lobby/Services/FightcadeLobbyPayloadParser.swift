import Foundation

struct FightcadeLobbyPayloadParser: Sendable {
    func decodeJSONObject(from data: Data) throws -> [String: Any] {
        guard let payload = try JSONSerialization.jsonObject(with: data) as? [String: Any] else {
            throw FightcadeLobbyError.unexpectedResponse("Could not load lobby.")
        }

        return payload
    }

    func hasLoggedInUser(in payload: [String: Any]) -> Bool {
        dictionaries(in: payload).contains { dictionary in
            stringValue(in: dictionary, keys: ["name", "username", "user"]) != nil
        }
    }

    func launcherToken(in payload: [String: Any]) -> String? {
        for dictionary in dictionaries(in: payload) + [payload] {
            if let token = stringValue(in: dictionary, keys: ["token"]), !token.isEmpty {
                return token
            }
        }

        return nil
    }

    func loginError(in payload: [String: Any]) -> FightcadeLobbyError? {
        if let result = intValue(in: payload, keys: ["result"]), result != 200 {
            return .loginExpired
        }

        let status = stringValue(in: payload, keys: ["res", "result", "status"])
        guard let status, ["KO", "ERROR", "FAIL", "FAILED"].contains(status.uppercased()) else {
            return nil
        }

        return .loginExpired
    }

    func responseError(in payload: [String: Any]) -> FightcadeLobbyError? {
        if isRateLimitError(in: payload) {
            return .rateLimited
        }

        if boolValue(in: payload, keys: ["isspam"]) {
            return .unexpectedResponse("Message not sent. Please stop spamming.")
        }

        if let result = intValue(in: payload, keys: ["result"]), result != 200 {
            return .unexpectedResponse(errorMessage(in: payload))
        }

        if let status = stringValue(in: payload, keys: ["res", "result", "status"]),
           ["KO", "ERROR", "FAIL", "FAILED"].contains(status.uppercased()) {
            return .unexpectedResponse(errorMessage(in: payload))
        }

        return nil
    }

    func isRateLimitError(in payload: [String: Any]) -> Bool {
        if intValue(in: payload, keys: ["result", "status"]) == 429 {
            return true
        }

        let message = errorMessage(in: payload).lowercased()
        return message.contains("too many requests") || message.contains("rate limit")
    }

    func welcomeMessage(in payload: [String: Any]) -> String? {
        let keys = ["welcome", "motd", "message", "msg", "html"]
        for dictionary in dictionaries(in: payload) + [payload] {
            if let message = stringValue(in: dictionary, keys: keys), !message.isEmpty {
                return message
            }
        }

        return nil
    }

    func channels(in payload: [String: Any]) -> [FightcadeChannel] {
        channelArrays(in: payload)
            .flatMap { $0.compactMap { $0 as? [String: Any] } }
            .compactMap(channel)
            .uniquedByID()
            .sorted(by: sortChannels)
    }

    func channelName(in payload: [String: Any]) -> String? {
        stringValue(in: payload, keys: ["channelname", "channel", "name", "gameid"])
            ?? (payload["game"] as? [String: Any]).flatMap { stringValue(in: $0, keys: ["channelname", "channel", "name", "gameid"]) }
            ?? (payload["quark"] as? [String: Any]).flatMap { stringValue(in: $0, keys: ["channelname", "channel", "name", "gameid"]) }
    }

    func users(in payload: [String: Any]) -> [FightcadeChannelUser] {
        guard let rawUsers = payload["users"] as? [Any] else {
            return []
        }

        let streamsByPlayerName = streamsByPlayerName(in: payload)
        return rawUsers.compactMap { $0 as? [String: Any] }
            .compactMap { user(from: $0, streamsByPlayerName: streamsByPlayerName) }
    }

    func requestIndex(in payload: [String: Any]) -> Int? {
        intValue(in: payload, keys: ["requestIdx", "idx"])
    }

    func event(in payload: [String: Any], currentChannelName: String?) -> FightcadeLobbyEvent? {
        let request = stringValue(in: payload, keys: ["req", "type", "event"])?.lowercased()

        if let warning = challengeWarning(in: payload, request: request, currentChannelName: currentChannelName) {
            return .challengeRestricted(warning)
        }

        if requestIndex(in: payload) != -1,
           let error = responseError(in: payload) {
            return .error(error.localizedDescription)
        }

        let channelList = channels(in: payload)
        if !channelList.isEmpty {
            return .channelsUpdated(channelList)
        }

        guard let request else {
            return nil
        }

        switch request {
        case "chat", "msg", "broken":
            return chatEvent(in: payload, request: request, currentChannelName: currentChannelName)
        case "join":
            guard let channelName = channelName(in: payload) ?? currentChannelName,
                  let user = userDictionary(in: payload).flatMap({ user(from: $0) }) else {
                return .chatMessage(systemMessage(in: payload, fallback: "joined", currentChannelName: currentChannelName))
            }

            return .userJoined(channelName, user)
        case "leave":
            guard let channelName = channelName(in: payload) ?? currentChannelName,
                  let username = username(in: payload) else {
                return .chatMessage(systemMessage(in: payload, fallback: "left", currentChannelName: currentChannelName))
            }

            return .userLeft(channelName, username)
        case "staway":
            return userStatusEvent(in: payload, isAway: true)
        case "stnoaway":
            return userStatusEvent(in: payload, isAway: false)
        case "chaway":
            return userStatusEvent(in: payload, currentChannelName: currentChannelName, isAway: true, isChannelScoped: true)
        case "chnoaway":
            return userStatusEvent(in: payload, currentChannelName: currentChannelName, isAway: false, isChannelScoped: true)
        case "stplaying":
            return userStatusEvent(in: payload, isPlaying: true)
        case "stnoplaying":
            return userStatusEvent(in: payload, isPlaying: false)
        case "quarkstats":
            return liveStreamUpdate(in: payload).map(FightcadeLobbyEvent.liveStreamUpdated)
        case "stwlan":
            return userStatusEvent(in: payload, isUsingWifi: true)
        case "stcable":
            return userStatusEvent(in: payload, isUsingWifi: false)
        case "kick":
            return .error("You were removed from the channel.")
        case "challenge":
            return challenge(in: payload, currentChannelName: currentChannelName).map(FightcadeLobbyEvent.challengeReceived)
        case "cancel":
            return challenge(in: payload, currentChannelName: currentChannelName).map(FightcadeLobbyEvent.challengeCanceled)
        case "reject":
            return challenge(in: payload, currentChannelName: currentChannelName).map(FightcadeLobbyEvent.challengeRejected)
        case "accept":
            return challenge(in: payload, currentChannelName: currentChannelName).map(FightcadeLobbyEvent.challengeAccepted)
        case "start":
            return matchStart(in: payload).map(FightcadeLobbyEvent.matchStarted)
        default:
            return nil
        }
    }

    private func userStatusEvent(
        in payload: [String: Any],
        currentChannelName: String? = nil,
        isAway: Bool? = nil,
        isPlaying: Bool? = nil,
        isUsingWifi: Bool? = nil,
        isChannelScoped: Bool = false
    ) -> FightcadeLobbyEvent? {
        guard let username = username(in: payload) else {
            return nil
        }

        let channelName = channelName(in: payload) ?? (isChannelScoped ? currentChannelName : nil)
        return .userStatusUpdated(
            FightcadeUserStatusUpdate(
                username: username,
                channelName: channelName,
                isAway: isAway,
                isPlaying: isPlaying,
                isUsingWifi: isUsingWifi,
                stream: stream(in: payload)
            )
        )
    }

    private func challenge(in payload: [String: Any], currentChannelName: String?) -> FightcadeChallenge? {
        guard let username = username(in: payload),
              let channelName = channelName(in: payload) ?? currentChannelName,
              let challengeID = intValue(in: payload, keys: ["challengeid", "challengeId", "id"]) else {
            return nil
        }

        return FightcadeChallenge(
            username: username,
            channelName: channelName,
            challengeID: challengeID,
            ranked: intValue(in: payload, keys: ["ranked"]) ?? 0
        )
    }

    private func matchStart(in payload: [String: Any]) -> FightcadeMatchStart? {
        guard let channelName = channelName(in: payload),
              let quarkID = stringValue(in: payload, keys: ["quarkid", "quarkId"]),
              let playerID = intValue(in: payload, keys: ["playerid", "playerId"]),
              let port = intValue(in: payload, keys: ["port"]),
              let delay = intValue(in: payload, keys: ["delay"]) else {
            return nil
        }

        return FightcadeMatchStart(
            channelName: channelName,
            gameID: stringValue(in: payload, keys: ["gameid", "gameId"]),
            quarkID: quarkID,
            playerID: playerID,
            port: port,
            ranked: intValue(in: payload, keys: ["ranked"]) ?? 0,
            delay: delay,
            token: stringValue(in: payload, keys: ["token"])
        )
    }

    private func chatEvent(
        in payload: [String: Any],
        request: String,
        currentChannelName: String?
    ) -> FightcadeLobbyEvent? {
        let channelName = stringValue(in: payload, keys: ["channelname", "channel", "gameid"])
            ?? currentChannelName
            ?? ""
        let body = stringValue(in: payload, keys: ["chat", "msg", "message", "text"])
            ?? stringValue(in: payload, keys: ["data"])
            ?? ""
        guard !body.isEmpty else {
            return nil
        }

        let isSystem = request == "broken"
        let username = isSystem ? "system" : username(in: payload)
            ?? "Fightcade"

        return .chatMessage(
            FightcadeChatMessage(
                channelName: channelName,
                username: username,
                body: body,
                kind: isSystem ? .system : .user
            )
        )
    }

    private func systemMessage(
        in payload: [String: Any],
        fallback: String,
        currentChannelName: String?
    ) -> FightcadeChatMessage {
        let channelName = stringValue(in: payload, keys: ["channelname", "channel", "gameid"])
            ?? currentChannelName
            ?? ""
        let username = username(in: payload)
            ?? "A player"

        return FightcadeChatMessage(
            channelName: channelName,
            username: "system",
            body: "\(username) \(fallback) \(channelName)",
            kind: .system
        )
    }

    private func channel(from dictionary: [String: Any]) -> FightcadeChannel? {
        guard let name = stringValue(in: dictionary, keys: ["channelname", "name", "id", "gameid"]),
              looksLikeChannel(dictionary) else {
            return nil
        }

        let title = stringValue(in: dictionary, keys: ["channelname", "name", "title", "gamename", "description", "longname"])
            ?? name

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

    private func channelArrays(in payload: [String: Any]) -> [[Any]] {
        if let channels = payload["channels"] as? [Any] {
            return [channels]
        }

        if let results = payload["results"] as? [Any] {
            return results.compactMap { result in
                (result as? [String: Any])?["channels"] as? [Any]
            }
        }

        return arrays(in: payload)
    }

    private func arrays(in payload: [String: Any]) -> [[Any]] {
        var found: [[Any]] = []

        for value in payload.values {
            if let array = value as? [Any] {
                found.append(array)
            } else if let dictionary = value as? [String: Any] {
                found.append(contentsOf: arrays(in: dictionary))
            }
        }

        return found
    }

    private func username(in payload: [String: Any]) -> String? {
        if let username = stringValue(in: payload, keys: ["username", "name"]) {
            return username
        }

        if let user = userDictionary(in: payload) {
            return stringValue(in: user, keys: ["name", "username", "id"])
        }

        return nil
    }

    private func userDictionary(in payload: [String: Any]) -> [String: Any]? {
        payload["user"] as? [String: Any]
    }

    private func user(from dictionary: [String: Any], streamsByPlayerName: [String: FightcadeSpectatorStream] = [:]) -> FightcadeChannelUser? {
        guard let name = stringValue(in: dictionary, keys: ["name", "username", "id"]), !name.isEmpty else {
            return nil
        }

        let rosterStream = streamsByPlayerName[normalizedUsername(name)]
        let userStream = stream(in: dictionary) ?? rosterStream
        let isPlaying = boolValue(in: dictionary, keys: ["playing"])
            || rosterStream != nil
            || (nestedStream(in: dictionary) != nil && dictionary["playing"] == nil)

        return FightcadeChannelUser(
            id: name,
            name: name,
            gravatarHash: stringValue(in: dictionary, keys: ["gravatar"]),
            countryCode: countryCode(in: dictionary),
            ping: intValue(in: dictionary, keys: ["ping"]),
            virtualPing: intValue(in: dictionary, keys: ["vping", "virtual_ping", "virtualPing"]),
            rank: intValue(in: dictionary, keys: ["rank"]),
            matchCount: intValue(in: dictionary, keys: ["matches", "match_count", "matchcount", "num_matches", "games_played"]),
            rankedSetting: intValue(in: dictionary, keys: ["ranked"]),
            region: stringValue(in: dictionary, keys: ["region"]),
            isAway: boolValue(in: dictionary, keys: ["away", "channel_away"]),
            isPlaying: isPlaying,
            isUsingWifi: boolValue(in: dictionary, keys: ["wlan"]),
            isUsingProxy: boolValue(in: dictionary, keys: ["proxy"]),
            preventsBadChallenges: boolValue(in: dictionary, keys: ["prevent_bad_challenges"]),
            preventsWifiChallenges: boolValue(in: dictionary, keys: ["prevent_wifi_challenges"]),
            stream: userStream
        )
    }

    private func countryCode(in dictionary: [String: Any]) -> String? {
        if let country = dictionary["country"] as? [String: Any] {
            return stringValue(in: country, keys: ["iso_code", "code"])
        }

        return stringValue(in: dictionary, keys: ["country", "country_code"])
    }

    private func errorMessage(in payload: [String: Any]) -> String {
        stringValue(in: payload, keys: ["error", "err", "msg", "message", "response"])
            ?? "Could not complete request."
    }

    private func dictionaries(in payload: [String: Any]) -> [[String: Any]] {
        var found: [[String: Any]] = []

        for value in payload.values {
            if let dictionary = value as? [String: Any] {
                found.append(dictionary)
                found.append(contentsOf: dictionaries(in: dictionary))
            }
        }

        return found
    }

    private func stringValue(in dictionary: [String: Any], keys: [String]) -> String? {
        for key in keys {
            if let value = dictionary[key] as? String {
                return value
            }

            if let number = dictionary[key] as? NSNumber {
                return number.stringValue
            }
        }

        return nil
    }

    private func intValue(in dictionary: [String: Any], keys: [String]) -> Int? {
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

    private func boolValue(in dictionary: [String: Any], keys: [String]) -> Bool {
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
    func uniquedByID() -> [FightcadeChannel] {
        var seen = Set<String>()
        var unique: [FightcadeChannel] = []

        for channel in self where seen.insert(channel.id).inserted {
            unique.append(channel)
        }

        return unique
    }
}
