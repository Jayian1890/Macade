import Foundation

extension FightcadeLobbyPayloadParser {
    func liveStreamUpdate(in payload: [String: Any]) -> FightcadeLiveStreamUpdate? {
        let quark = payload["quark"] as? [String: Any] ?? payload
        guard let stream = stream(in: quark), !playerNames(in: quark).isEmpty else {
            return nil
        }

        return FightcadeLiveStreamUpdate(
            channelName: streamStringValue(in: quark, keys: ["channelname", "channel", "name"])
                ?? streamStringValue(in: payload, keys: ["channelname", "channel", "name"]),
            players: playerNames(in: quark),
            stream: stream
        )
    }

    func streamsByPlayerName(in payload: [String: Any]) -> [String: FightcadeSpectatorStream] {
        let fallbackGameID = streamStringValue(in: payload, keys: ["gameid", "gameId"])
        var streams: [String: FightcadeSpectatorStream] = [:]

        for quark in quarkDictionaries(in: payload) {
            guard let stream = directStream(in: quark, fallbackGameID: fallbackGameID) else {
                continue
            }

            for player in playerNames(in: quark) {
                streams[normalizedUsername(player)] = stream
            }
        }

        return streams
    }

    func stream(in dictionary: [String: Any]) -> FightcadeSpectatorStream? {
        if let stream = directStream(in: dictionary, fallbackGameID: nil) {
            return stream
        }

        return nestedStream(in: dictionary)
    }

    func nestedStream(in dictionary: [String: Any]) -> FightcadeSpectatorStream? {
        let fallbackGameID = streamStringValue(in: dictionary, keys: ["gameid", "gameId"])
        for key in ["game", "quark"] {
            if let nested = dictionary[key] as? [String: Any],
               let stream = directStream(in: nested, fallbackGameID: fallbackGameID) {
                return stream
            }
        }

        return nil
    }

    func normalizedUsername(_ value: String) -> String {
        value.folding(options: [.caseInsensitive, .diacriticInsensitive], locale: nil).lowercased()
    }
}

private extension FightcadeLobbyPayloadParser {
    func directStream(in dictionary: [String: Any], fallbackGameID: String?) -> FightcadeSpectatorStream? {
        guard let quarkID = streamStringValue(in: dictionary, keys: ["quarkid", "quarkId"]),
              let port = streamIntValue(in: dictionary, keys: ["port"]), port > 0 else {
            return nil
        }

        return FightcadeSpectatorStream(
            gameID: streamStringValue(in: dictionary, keys: ["gameid", "gameId"]) ?? fallbackGameID,
            quarkID: quarkID,
            port: port
        )
    }

    func quarkDictionaries(in payload: [String: Any]) -> [[String: Any]] {
        var quarks = (payload["quarks"] as? [Any])?.compactMap { $0 as? [String: Any] } ?? []
        if let quark = payload["quark"] as? [String: Any] {
            quarks.append(quark)
        }
        return quarks
    }

    func playerNames(in quark: [String: Any]) -> [String] {
        if let players = quark["players"] as? [String] {
            return players.filter { !$0.isEmpty }
        }

        if let players = quark["players"] as? [[String: Any]] {
            return players.compactMap { streamStringValue(in: $0, keys: ["name", "username", "id"]) }
        }

        return ["player1", "player2", "p1", "p2", "username", "name"].compactMap { key in
            quark[key] as? String
        }
    }

    func streamStringValue(in dictionary: [String: Any], keys: [String]) -> String? {
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

    func streamIntValue(in dictionary: [String: Any], keys: [String]) -> Int? {
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
        }

        return nil
    }
}
