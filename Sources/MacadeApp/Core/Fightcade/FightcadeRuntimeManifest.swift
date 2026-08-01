import Foundation

struct FightcadeRuntimeManifest: Decodable {
    static let empty = FightcadeRuntimeManifest(emulators: [:])

    let emulators: [String: Emulator]

    func supportsQuark(emulator: String) -> Bool {
        emulators[emulator.lowercased()]?.supportsQuark == true
    }

    func supportsEmbedded(emulator: String) -> Bool {
        guard let emulator = emulators[emulator.lowercased()] else {
            return false
        }

        return emulator.supportsQuark || emulator.supportsEmbedded == true
    }

    struct Emulator: Decodable {
        let supportsQuark: Bool
        let supportsEmbedded: Bool?
    }
}

extension FightcadeEmbeddedLaunch {
    var requiresQuark: Bool {
        switch mode {
        case .match, .direct, .spectate:
            true
        case .test, .training:
            arguments.contains { $0.hasPrefix("quark:") }
        }
    }
}
