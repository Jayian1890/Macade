import Foundation

extension FightcadeLobbyPayloadParser {
    func challengeWarning(
        in payload: [String: Any],
        request: String?,
        currentChannelName: String?
    ) -> FightcadeChallengeWarning? {
        let failedStatus = responseError(in: payload)
        guard let message = warningMessage(in: payload) ?? failedStatus?.localizedDescription else {
            return nil
        }

        let challengeRequest = request == "challenge" || request == "accept"
        let systemWarning = request == "broken" && looksLikeChallengeWarning(message)
        guard (challengeRequest && (failedStatus != nil || looksLikeChallengeWarning(message))) || systemWarning else {
            return nil
        }

        return FightcadeChallengeWarning(
            username: warningUsername(in: payload),
            channelName: channelName(in: payload) ?? currentChannelName,
            challengeID: warningIntValue(in: payload, keys: ["challengeid", "challengeId", "id"]),
            message: message
        )
    }

    private func warningMessage(in payload: [String: Any]) -> String? {
        let keys = ["error", "err", "msg", "message", "response", "reason", "warning", "chat", "text", "data"]
        guard let message = warningStringValue(in: payload, keys: keys)?.trimmingCharacters(in: .whitespacesAndNewlines),
              !message.isEmpty else {
            return nil
        }

        return message
    }

    private func warningUsername(in payload: [String: Any]) -> String? {
        if let username = warningStringValue(in: payload, keys: ["username", "name"]) {
            return username
        }

        if let user = payload["user"] as? [String: Any] {
            return warningStringValue(in: user, keys: ["name", "username", "id"])
        }

        return nil
    }

    private func looksLikeChallengeWarning(_ message: String) -> Bool {
        let normalized = message.lowercased()
        let words = ["challenge", "invite", "restrict", "cannot", "can't", "cant", "ping", "latency", "wifi", "wi-fi", "region", "location", "country", "distance"]
        return words.contains { normalized.contains($0) }
    }

    private func warningStringValue(in dictionary: [String: Any], keys: [String]) -> String? {
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

    private func warningIntValue(in dictionary: [String: Any], keys: [String]) -> Int? {
        for key in keys {
            if let value = dictionary[key] as? Int {
                return value
            }

            if let number = dictionary[key] as? NSNumber {
                return number.intValue
            }
        }

        return nil
    }
}
