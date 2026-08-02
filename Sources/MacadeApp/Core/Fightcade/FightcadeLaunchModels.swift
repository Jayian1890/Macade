import Foundation

struct FightcadeEmbeddedResources {
    let id: UUID
    let videoStream: FightcadeEmbeddedVideoStream
    let inputClient: FightcadeEmbeddedInputClient
    let launchLog: FightcadeLaunchLog
    let logURL: URL
}

enum FightcadeLaunchError: LocalizedError, Equatable {
    case missingGame
    case missingRuntime([String])
    case missingEmulator(emulator: String, searchedPaths: [String])
    case missingROM(gameID: String, emulator: String, searchedPaths: [String])
    case unsupportedNativeRoute(String)
    case embeddedBridgeFailed(String)
    case couldNotLaunch(String)

    var errorDescription: String? {
        switch self {
        case .missingGame:
            "This channel is missing Fightcade launch metadata."
        case .missingRuntime(let paths):
            "Missing Macade Fightcade runtime. Expected FightcadeRuntime at: \(paths.joined(separator: ", "))"
        case .missingEmulator(let emulator, _):
            "Native \(emulator) runtime is not bundled. Restore the bundled FightcadeRuntime resources."
        case .missingROM(let gameID, let emulator, let searchedPaths):
            "Missing ROM for \(gameID) on \(emulator). Searched: \(searchedPaths.joined(separator: ", "))"
        case .unsupportedNativeRoute(let route):
            "Native launcher does not implement \(route) yet."
        case .embeddedBridgeFailed(let message):
            message
        case .couldNotLaunch(let path):
            "Could not launch emulator executable at \(path)."
        }
    }
}
