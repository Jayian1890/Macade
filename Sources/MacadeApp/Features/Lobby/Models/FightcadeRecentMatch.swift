import Foundation

struct FightcadeRecentMatch: Identifiable, Decodable, Equatable, Sendable {
    let quarkID: String
    let channelName: String
    let date: Date
    let duration: TimeInterval
    let emulator: String
    let gameID: String
    let numMatches: Int
    let players: [FightcadeRecentMatchPlayer]
    let ranked: Int
    let replayFile: String?

    var id: String { "\(emulator):\(gameID):\(quarkID)" }

    var hasReplay: Bool {
        replayFile?.nonEmpty != nil
    }

    var replayLink: FightcadeReplayLink? {
        guard hasReplay,
              let url = URL(string: "https://replay.fightcade.com/\(emulator)/\(gameID)/\(quarkID)") else {
            return nil
        }

        return FightcadeReplayLink(url: url, emulator: emulator, gameID: gameID, replayID: quarkID)
    }

    func opponentName(for username: String) -> String? {
        players.first { !$0.matches(username) }?.name
    }

    func scoreText(for username: String) -> String? {
        guard players.count == 2,
              let firstScore = players[0].score,
              let secondScore = players[1].score else {
            return nil
        }

        if players[1].matches(username) {
            return "\(secondScore)-\(firstScore)"
        }

        return "\(firstScore)-\(secondScore)"
    }

    private enum CodingKeys: String, CodingKey {
        case quarkID = "quarkid"
        case channelName = "channelname"
        case date
        case duration
        case emulator
        case gameID = "gameid"
        case numMatches = "num_matches"
        case players
        case ranked
        case replayFile = "replay_file"
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        quarkID = try container.decode(String.self, forKey: .quarkID)
        channelName = try container.decodeIfPresent(String.self, forKey: .channelName) ?? ""
        let milliseconds = try container.decode(FlexibleDouble.self, forKey: .date).value
        date = Date(timeIntervalSince1970: milliseconds / 1000)
        duration = try container.decodeIfPresent(FlexibleDouble.self, forKey: .duration)?.value ?? 0
        emulator = try container.decode(String.self, forKey: .emulator)
        gameID = try container.decode(String.self, forKey: .gameID)
        numMatches = try container.decodeIfPresent(FlexibleInt.self, forKey: .numMatches)?.value ?? 0
        players = try container.decodeIfPresent([FightcadeRecentMatchPlayer].self, forKey: .players) ?? []
        ranked = try container.decodeIfPresent(FlexibleInt.self, forKey: .ranked)?.value ?? 0
        replayFile = try container.decodeIfPresent(String.self, forKey: .replayFile)?.nonEmpty
    }
}

struct FightcadeRecentMatchPlayer: Decodable, Equatable, Sendable {
    let name: String
    let countryCode: String?
    let rank: Int?
    let score: Int?

    func matches(_ username: String) -> Bool {
        name.compare(username, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
    }

    private enum CodingKeys: String, CodingKey {
        case name
        case countryCode = "country"
        case rank
        case score
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        name = try container.decode(String.self, forKey: .name)
        countryCode = try container.decodeIfPresent(String.self, forKey: .countryCode)?.nonEmpty
        rank = try container.decodeIfPresent(FlexibleInt.self, forKey: .rank)?.value
        score = try container.decodeIfPresent(FlexibleInt.self, forKey: .score)?.value
    }
}

struct FightcadeRecentMatchSearchResponse: Decodable, Equatable, Sendable {
    let results: FightcadeRecentMatchSearchPage
    let response: String?

    var matches: [FightcadeRecentMatch] { results.results }

    private enum CodingKeys: String, CodingKey {
        case results
        case response = "res"
    }
}

struct FightcadeRecentMatchSearchPage: Decodable, Equatable, Sendable {
    let results: [FightcadeRecentMatch]
    let count: Int

    private enum CodingKeys: String, CodingKey {
        case results
        case count
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        let decodedResults = try container.decodeIfPresent([LossyRecentMatch].self, forKey: .results) ?? []
        results = decodedResults.compactMap(\.value)
        count = try container.decodeIfPresent(FlexibleInt.self, forKey: .count)?.value ?? results.count
    }
}

private struct LossyRecentMatch: Decodable {
    let value: FightcadeRecentMatch?

    init(from decoder: Decoder) throws {
        value = try? FightcadeRecentMatch(from: decoder)
    }
}

private struct FlexibleInt: Decodable, Equatable, Sendable {
    let value: Int

    init(from decoder: Decoder) throws {
        let container = try decoder.singleValueContainer()
        if let value = try? container.decode(Int.self) {
            self.value = value
        } else if let value = try? container.decode(Double.self) {
            self.value = Int(value)
        } else {
            let string = try container.decode(String.self)
            value = Int(string) ?? 0
        }
    }
}

private struct FlexibleDouble: Decodable, Equatable, Sendable {
    let value: Double

    init(from decoder: Decoder) throws {
        let container = try decoder.singleValueContainer()
        if let value = try? container.decode(Double.self) {
            self.value = value
        } else if let value = try? container.decode(Int.self) {
            self.value = Double(value)
        } else {
            let string = try container.decode(String.self)
            value = Double(string) ?? 0
        }
    }
}
