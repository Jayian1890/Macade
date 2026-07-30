import Foundation

extension FightcadeLobbyPayloadParser {
    func channelMotd(in payload: [String: Any], channelName: String) -> FightcadeChannelMotd? {
        let body = payload["motd"] as? String ?? ""
        let events = (payload["events"] as? [Any] ?? []).compactMap { value -> FightcadeEvent? in
            guard let dictionary = value as? [String: Any] else {
                return nil
            }

            return event(from: dictionary)
        }

        guard !body.isEmpty || !events.isEmpty else {
            return nil
        }

        return FightcadeChannelMotd(channelName: channelName, body: body, events: events)
    }

    private func event(from dictionary: [String: Any]) -> FightcadeEvent? {
        guard let name = dictionary["name"] as? String,
              let gameID = dictionary["gameid"] as? String,
              let date = eventDate(from: dictionary["date"]) else {
            return nil
        }

        return FightcadeEvent(
            name: name,
            author: dictionary["author"] as? String,
            date: date,
            gameID: gameID,
            imageURL: (dictionary["image"] as? String).flatMap(URL.init(string:)),
            link: (dictionary["link"] as? String).flatMap(URL.init(string:)),
            region: dictionary["region"] as? String,
            stream: (dictionary["stream"] as? String).flatMap(URL.init(string:))
        )
    }

    private func eventDate(from value: Any?) -> Date? {
        if let milliseconds = value as? NSNumber {
            return Date(timeIntervalSince1970: milliseconds.doubleValue / 1000)
        }

        if let milliseconds = value as? Double {
            return Date(timeIntervalSince1970: milliseconds / 1000)
        }

        if let milliseconds = value as? String, let value = Double(milliseconds) {
            return Date(timeIntervalSince1970: value / 1000)
        }

        return nil
    }
}
