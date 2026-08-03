import Foundation

extension FightcadeLobbyService {
    func loadRecentMatches(for username: String, gameID: String, limit: Int) async throws -> [FightcadeRecentMatch] {
        let username = username.trimmingCharacters(in: .whitespacesAndNewlines)
        let gameID = gameID.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !username.isEmpty, !gameID.isEmpty else {
            return []
        }

        var request = URLRequest(url: FightcadeEndpoint.publicAPIURL)
        request.httpMethod = "POST"
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.setValue("application/json, text/plain, */*", forHTTPHeaderField: "Accept")
        request.httpBody = try JSONSerialization.data(withJSONObject: [
            "req": "searchquarks",
            "username": username,
            "gameid": gameID,
            "offset": 0,
            "limit": max(1, min(limit, 15))
        ])

        let (data, response) = try await session.data(for: request)
        guard let httpResponse = response as? HTTPURLResponse,
              (200..<300).contains(httpResponse.statusCode) else {
            throw FightcadeLobbyError.unexpectedResponse("Could not load recent matches.")
        }

        let decoded = try JSONDecoder().decode(FightcadeRecentMatchSearchResponse.self, from: data)
        guard decoded.response?.uppercased() != "KO" else {
            throw FightcadeLobbyError.unexpectedResponse("Could not load recent matches.")
        }

        return decoded.matches.filter {
            $0.gameID.compare(gameID, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
        }
    }
}
