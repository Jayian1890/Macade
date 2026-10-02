import Foundation

struct FightcadeRuntimeManifest: Decodable {
    static let empty = FightcadeRuntimeManifest(emulators: [:])

    let emulators: [String: Emulator]

    func supportsQuark(emulator: String) -> Bool {
        supports(.fightcadeMatch, emulator: emulator)
            || supports(.fightcadeDirect, emulator: emulator)
            || supports(.fightcadeSpectate, emulator: emulator)
            || supports(.fightcadeTraining, emulator: emulator)
            || supports(.fightcadeReplay, emulator: emulator)
    }

    func supportsEmbedded(emulator: String) -> Bool {
        supports(.embedded, emulator: emulator)
    }

    func supports(_ capability: FightcadeRuntimeCapability, emulator: String) -> Bool {
        guard let emulator = manifestEmulator(for: emulator) else {
            return false
        }

        switch capability {
        case .embedded:
            return emulator.supportsEmbedded == true || emulator.supportsQuark
        case .fightcadeMatch:
            return emulator.supportsFightcadeMatch ?? emulator.supportsQuark
        case .fightcadeDirect:
            return emulator.supportsFightcadeDirect ?? emulator.supportsQuark
        case .fightcadeSpectate:
            return emulator.supportsFightcadeSpectate ?? emulator.supportsQuark
        case .fightcadeTraining:
            return emulator.supportsFightcadeTraining ?? emulator.supportsQuark
        case .fightcadeReplay:
            return emulator.supportsFightcadeReplay ?? emulator.supportsQuark
        }
    }

    private func manifestEmulator(for emulator: String) -> Emulator? {
        let normalized = FightcadeEmulatorID.normalized(emulator)
        return emulators[FightcadeEmulatorID.runtimeID(for: normalized)] ?? emulators[normalized]
    }

    struct Emulator: Decodable {
        let supportsQuark: Bool
        let supportsEmbedded: Bool?
        let supportsFightcadeMatch: Bool?
        let supportsFightcadeDirect: Bool?
        let supportsFightcadeSpectate: Bool?
        let supportsFightcadeTraining: Bool?
        let supportsFightcadeReplay: Bool?
    }
}

enum FightcadeRuntimeCapability: Hashable, Sendable {
    case embedded
    case fightcadeMatch
    case fightcadeDirect
    case fightcadeSpectate
    case fightcadeTraining
    case fightcadeReplay
}

enum FightcadeEmulatorID {
    static func normalized(_ emulator: String) -> String {
        emulator.trimmingCharacters(in: .whitespacesAndNewlines).lowercased()
    }

    static func runtimeID(for emulator: String) -> String {
        switch normalized(emulator) {
        case "fc1":
            "ggpofba"
        case "nulldc":
            "flycast"
        case let emulator:
            emulator
        }
    }
}

extension FightcadeEmbeddedLaunch {
    var requiresQuark: Bool {
        requiredRuntimeCapability != nil
    }

    var requiredRuntimeCapability: FightcadeRuntimeCapability? {
        switch mode {
        case .match:
            .fightcadeMatch
        case .direct:
            .fightcadeDirect
        case .spectate:
            .fightcadeSpectate
        case .replay:
            replayCapability
        case .singlePlayer, .test, .training:
            quarkArgumentCapability
        }
    }

    private var replayCapability: FightcadeRuntimeCapability {
        if arguments.contains(where: { $0.hasPrefix("quark:stream") }) {
            return .fightcadeSpectate
        }

        return .fightcadeReplay
    }

    private var quarkArgumentCapability: FightcadeRuntimeCapability? {
        guard let quarkArgument = arguments.first(where: { $0.hasPrefix("quark:") }) else {
            return nil
        }

        if quarkArgument.hasPrefix("quark:training") {
            return .fightcadeTraining
        }

        return .fightcadeMatch
    }
}
