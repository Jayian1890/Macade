import Foundation

extension FightcadeLobbyService {
    func searchChannels(matching query: String) async throws -> [FightcadeChannel] {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        let request = FightcadeChannelSearchRequest(query: query)
        guard request.hasQuery else { return [] }

        let payload = try await sendRequest(request.payload(), webSocket: webSocket)
        return parser.channels(in: payload).markingFavorites(matching: favoriteChannelKeys)
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

private enum FightcadeLobbySearchLimit {
    static let resultLimit = 50
}

private struct FightcadeChannelSearchRequest {
    let query: String

    var trimmedQuery: String {
        query.trimmingCharacters(in: .whitespacesAndNewlines)
    }

    var hasQuery: Bool {
        !trimmedQuery.isEmpty
    }

    func payload() -> [String: Any] {
        [
            "req": "channels",
            "paginated": true,
            "page": 1,
            "count": FightcadeLobbySearchLimit.resultLimit,
            "limit": FightcadeLobbySearchLimit.resultLimit,
            "offset": 0,
            "filter": trimmedQuery
        ]
    }
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
