import Foundation

extension FightcadeLobbyService {
    func searchChannels(_ request: FightcadeChannelSearchRequest) async throws -> FightcadeChannelSearchResult {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        let payload = try await sendRequest(request.payload(), webSocket: webSocket)
        let channels = parser.channels(in: payload).markingFavorites(matching: favoriteChannelKeys)
        return FightcadeChannelSearchResult(
            channels: channels,
            page: request.page,
            hasMorePages: request.paginated && hasMoreChannels(in: payload, returnedChannelCount: channels.count)
        )
    }

    func loadChannelFilterOptions() async throws -> FightcadeChannelFilterOptions {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        let payload = try await sendRequest(["req": "filteroptions"], webSocket: webSocket)
        return FightcadeChannelFilterOptions(payload: payload)
    }

    func loadUpcomingEvents(limit: Int) async throws -> [FightcadeEvent] {
        var request = URLRequest(url: FightcadeEndpoint.publicAPIURL)
        request.httpMethod = "POST"
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.setValue("application/json, text/plain, */*", forHTTPHeaderField: "Accept")
        request.httpBody = try JSONSerialization.data(withJSONObject: [
            "req": "searchevents",
            "offset": 0,
            "limit": limit
        ])

        let (data, response) = try await session.data(for: request)
        guard let httpResponse = response as? HTTPURLResponse,
              (200..<300).contains(httpResponse.statusCode),
              let payload = try JSONSerialization.jsonObject(with: data) as? [String: Any] else {
            throw FightcadeLobbyError.unexpectedResponse("Could not load upcoming events.")
        }

        return FightcadeEvent.events(in: payload)
    }

    func setFavorite(_ isFavorite: Bool, for channel: FightcadeChannel) async throws {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        _ = try await sendRequest([
            "req": "favchannel",
            "channelname": channel.name,
            "fav": isFavorite
        ], webSocket: webSocket)

        if isFavorite {
            favoriteChannelKeys.formUnion(channel.favoriteMatchKeys)
        } else {
            favoriteChannelKeys.subtract(channel.favoriteMatchKeys)
        }
    }
}

private func hasMoreChannels(in payload: [String: Any], returnedChannelCount: Int) -> Bool {
    guard returnedChannelCount > 0,
          let totalChannels = intValue(in: payload, keys: ["totalChannels", "total_channels", "total"]) else {
        return false
    }

    let page = max((intValue(in: payload, keys: ["page"]) ?? 1) - 1, 0)
    let pageSize = intValue(in: payload, keys: ["count", "limit"]) ?? returnedChannelCount
    let offset = intValue(in: payload, keys: ["offset"]) ?? page * pageSize
    return offset + returnedChannelCount < totalChannels
}

private func intValue(in payload: [String: Any], keys: [String]) -> Int? {
    for key in keys {
        if let value = payload[key] as? Int { return value }
        if let number = payload[key] as? NSNumber { return number.intValue }
        if let string = payload[key] as? String, let value = Int(string) { return value }
    }

    return nil
}

private extension FightcadeEvent {
    static func events(in payload: [String: Any]) -> [FightcadeEvent] {
        let root = payload["results"] as? [String: Any]
        let values = root?["results"] as? [Any] ?? []
        return values.compactMap { value in
            guard let dictionary = value as? [String: Any],
                  let name = dictionary["name"] as? String,
                  let gameID = dictionary["gameid"] as? String,
                  let milliseconds = dictionary["date"] as? NSNumber else {
                return nil
            }

            return FightcadeEvent(
                name: name,
                author: dictionary["author"] as? String,
                date: Date(timeIntervalSince1970: milliseconds.doubleValue / 1000),
                gameID: gameID,
                imageURL: (dictionary["image"] as? String).flatMap(URL.init(string:)),
                link: (dictionary["link"] as? String).flatMap(URL.init(string:)),
                region: dictionary["region"] as? String,
                stream: (dictionary["stream"] as? String).flatMap(URL.init(string:))
            )
        }
    }
}

private extension FightcadeChannelFilterOptions {
    init(payload: [String: Any]) {
        self.init(
            systems: Self.optionValues(in: payload, keys: ["systems", "system", "platforms", "platform"]),
            genres: Self.optionValues(in: payload, keys: ["genres", "genre"]),
            years: Self.optionValues(in: payload, keys: ["years", "year"])
        )
    }

    static func optionValues(in payload: [String: Any], keys: [String]) -> [String] {
        var values = Set<String>()
        collectOptionValues(from: payload, matching: Set(keys.map { $0.lowercased() }), into: &values)
        return values.sorted { $0.localizedCaseInsensitiveCompare($1) == .orderedAscending }
    }

    static func collectOptionValues(from value: Any, matching keys: Set<String>, into values: inout Set<String>) {
        if let dictionary = value as? [String: Any] {
            for (key, child) in dictionary {
                if keys.contains(key.lowercased()) {
                    collectLeafValues(from: child, into: &values)
                } else {
                    collectOptionValues(from: child, matching: keys, into: &values)
                }
            }
            return
        }

        if let array = value as? [Any] {
            for item in array {
                collectOptionValues(from: item, matching: keys, into: &values)
            }
        }
    }

    static func collectLeafValues(from value: Any, into values: inout Set<String>) {
        if let string = value as? String, !string.isEmpty {
            values.insert(string)
            return
        }

        if let number = value as? NSNumber {
            values.insert(number.stringValue)
            return
        }

        if let dictionary = value as? [String: Any] {
            for key in ["name", "label", "value", "id"] {
                if let string = dictionary[key] as? String, !string.isEmpty {
                    values.insert(string)
                    return
                }
            }

            for child in dictionary.values {
                collectLeafValues(from: child, into: &values)
            }
            return
        }

        if let array = value as? [Any] {
            for item in array {
                collectLeafValues(from: item, into: &values)
            }
        }
    }
}
