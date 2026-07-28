import Foundation

enum FightcadeLaunchRoute: Sendable, Equatable {
    case play(emulator: String, gameID: String)
    case training(emulator: String, gameID: String)
    case fightcadeTraining(FightcadeTrainingLaunch)
    case checkROM(emulator: String, gameID: String)
    case match(FightcadeMatchLaunch)
    case direct(FightcadeDirectLaunch)
    case spectate(emulator: String, gameID: String, quarkID: String, port: Int)
    case endMatch
}

struct FightcadeMatchLaunch: Equatable, Sendable {
    let emulator: String
    let gameID: String
    let quarkID: String
    let playerID: Int
    let port: Int
    let delay: Int
    let ranked: Int
    let token: String?

    var quarkCommand: String {
        "quark:served,\(gameID),\(quarkID).\(playerID),\(port),\(delay),\(ranked)"
    }
}

struct FightcadeTrainingLaunch: Equatable, Sendable {
    let emulator: String
    let gameID: String
    let quarkID: String
    let playerID: Int
    let port: Int
    let delay: Int

    var quarkCommand: String {
        "quark:training,\(gameID),\(quarkID).\(playerID),\(port),\(delay)"
    }
}

struct FightcadeDirectLaunch: Equatable, Sendable {
    let emulator: String
    let gameID: String
    let localPort: Int
    let host: String
    let remotePort: Int
    let playerID: Int
    let delay: Int
    let ranked: Int

    var quarkCommand: String {
        "quark:direct,\(gameID),\(localPort),\(host),\(remotePort),\(playerID),\(delay),\(ranked)"
    }
}

struct FightcadeSpectateLaunch: Equatable, Sendable {
    let emulator: String
    let gameID: String
    let quarkID: String
    let port: Int

    var quarkCommand: String {
        "quark:stream,\(gameID),\(baseQuarkID).2,\(port)"
    }

    private var baseQuarkID: String {
        guard let dotIndex = quarkID.lastIndex(of: "."),
              quarkID[quarkID.index(after: dotIndex)...].allSatisfy(\.isNumber) else {
            return quarkID
        }

        return String(quarkID[..<dotIndex])
    }
}

struct FightcadeMatchStart: Equatable, Sendable {
    let channelName: String
    let gameID: String?
    let quarkID: String
    let playerID: Int
    let port: Int
    let ranked: Int
    let delay: Int
    let token: String?
}
