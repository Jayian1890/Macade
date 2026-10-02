import Foundation

struct MacadeGamepadControl: Codable, Hashable, Sendable {
    var kind: String
    var index: Int
    var direction: Int

    var isValid: Bool {
        guard (0...255).contains(index) else { return false }
        switch kind {
        case "b", "x": return direction == 0
        case "a": return direction == -1 || direction == 1
        case "h": return [1, 2, 4, 8].contains(direction)
        default: return false
        }
    }

    var title: String {
        switch kind {
        case "b": "Button \(index + 1)"
        case "a": "Axis \(index + 1) \(direction < 0 ? "−" : "+")"
        case "x": "Axis \(index + 1)"
        case "h": "D-pad \(index + 1) \([1: "Up", 2: "Right", 4: "Down", 8: "Left"][direction] ?? "")"
        default: "Unbound"
        }
    }
}

struct MacadeGamepadBinding: Codable, Equatable, Sendable {
    var deviceID: String
    var gameID: String
    var inputIndex: Int
    var inputInfo: String
    var player: Int
    // nil is an explicit clear; no record means use FBNeo's saved/default binding.
    var control: MacadeGamepadControl?
}

struct MacadeGamepadPreferences: Codable, Equatable, Sendable {
    var version = 1
    var bindings: [MacadeGamepadBinding] = []

    func normalized() -> Self {
        guard version == 1 else { return Self() }
        var result = Self()
        for binding in bindings.prefix(4096) {
            guard Self.safeToken(binding.deviceID), Self.safeToken(binding.gameID),
                  !binding.inputInfo.isEmpty, binding.inputInfo.count <= 512,
                  binding.inputInfo.allSatisfy({ $0.isHexDigit }),
                  (0..<4096).contains(binding.inputIndex), (1...4).contains(binding.player),
                  binding.control?.isValid != false else { continue }
            result.bindings.removeAll { $0.gameID == binding.gameID && $0.inputIndex == binding.inputIndex }
            result.bindings.append(binding)
        }
        return result
    }

    mutating func set(_ binding: MacadeGamepadBinding) -> Bool {
        let conflict = bindings.contains {
            $0.deviceID == binding.deviceID && $0.gameID == binding.gameID && $0.player == binding.player
                && $0.inputIndex != binding.inputIndex && binding.control != nil && $0.control == binding.control
        }
        for index in bindings.indices where bindings[index].deviceID == binding.deviceID
            && bindings[index].gameID == binding.gameID && bindings[index].player == binding.player
            && bindings[index].inputIndex != binding.inputIndex && binding.control != nil
            && bindings[index].control == binding.control {
            bindings[index].control = nil
        }
        bindings.removeAll { $0.gameID == binding.gameID && $0.inputIndex == binding.inputIndex }
        bindings.append(binding)
        self = normalized()
        return conflict
    }

    var runtimeProjection: String {
        let rows = normalized().bindings.sorted {
            ($0.gameID, $0.inputIndex) < ($1.gameID, $1.inputIndex)
        }.map { binding in
            let control = binding.control
            return "\(binding.deviceID) \(binding.gameID) \(binding.inputIndex) \(binding.player) \(binding.inputInfo) \(control?.kind ?? "-") \(control?.index ?? 0) \(control?.direction ?? 0)"
        }
        return (["MACADE_GAMEPADS 1"] + rows).joined(separator: "\n") + "\n"
    }

    private static func safeToken(_ value: String) -> Bool {
        !value.isEmpty && value.count <= 256 && value.utf8.allSatisfy {
            (48...57).contains($0) || (65...90).contains($0) || (97...122).contains($0)
                || [45, 46, 58, 95].contains($0)
        }
    }
}

struct MacadeGamepadPreferencesStore {
    private let userDefaults: UserDefaults
    private let key = "MacadeGamepadPreferences"

    init(userDefaults: UserDefaults = .standard) { self.userDefaults = userDefaults }

    func load() -> MacadeGamepadPreferences {
        guard let data = userDefaults.data(forKey: key),
              let preferences = try? JSONDecoder().decode(MacadeGamepadPreferences.self, from: data) else {
            return MacadeGamepadPreferences()
        }
        return preferences.normalized()
    }

    func save(_ preferences: MacadeGamepadPreferences) throws {
        userDefaults.set(try JSONEncoder().encode(preferences.normalized()), forKey: key)
    }

    func writeRuntimeProjection(in directory: URL) throws -> URL {
        let url = directory.appendingPathComponent("macade-gamepads-v1.txt")
        try load().runtimeProjection.write(to: url, atomically: true, encoding: .utf8)
        return url
    }
}
