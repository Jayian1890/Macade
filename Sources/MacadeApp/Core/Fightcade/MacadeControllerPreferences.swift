import Foundation

extension Notification.Name {
    static let macadeControllerPreferencesDidChange = Notification.Name("macadeControllerPreferencesDidChange")
}

struct MacadeKeyBinding: Codable, Equatable, Sendable {
    let keyCode: UInt16
    let displayName: String
}

struct MacadeControllerPreferences: Codable, Equatable, Sendable {
    var bindings: [ControllerAction.ID: MacadeKeyBinding]

    static let defaults = MacadeControllerPreferences(
        bindings: Dictionary(uniqueKeysWithValues: ControllerAction.allCases.map { ($0.id, $0.defaultBinding) })
    )

    func normalized() -> MacadeControllerPreferences {
        var copy = self
        let validIDs = Set(ControllerAction.allCases.map(\.id))
        copy.bindings = bindings.filter { validIDs.contains($0.key) }
        for action in ControllerAction.allCases where copy.bindings[action.id] == nil {
            copy.bindings[action.id] = action.defaultBinding
        }
        return copy
    }

    func targetScancode(for keyCode: UInt16) -> Int32? {
        controllerAction(for: keyCode)?.defaultSDLScancode
    }

    func controllerAction(for keyCode: UInt16) -> ControllerAction? {
        for action in ControllerAction.allCases where bindings[action.id]?.keyCode == keyCode {
            return action
        }
        return nil
    }
}

enum ControllerAction: String, CaseIterable, Identifiable, Codable, Sendable {
    case up
    case down
    case left
    case right
    case button1
    case button2
    case button3
    case button4
    case button5
    case button6
    case start
    case coin

    var id: String { rawValue }

    var title: String {
        switch self {
        case .up: "Up"
        case .down: "Down"
        case .left: "Left"
        case .right: "Right"
        case .button1: "Button 1"
        case .button2: "Button 2"
        case .button3: "Button 3"
        case .button4: "Button 4"
        case .button5: "Button 5"
        case .button6: "Button 6"
        case .start: "Start"
        case .coin: "Coin"
        }
    }

    var subtitle: String {
        switch self {
        case .up, .down, .left, .right: "Movement"
        case .button1, .button2, .button3: "Light / primary row"
        case .button4, .button5, .button6: "Heavy / secondary row"
        case .start: "Player 1 start"
        case .coin: "Insert credit"
        }
    }

    var symbolName: String {
        switch self {
        case .up: "arrow.up"
        case .down: "arrow.down"
        case .left: "arrow.left"
        case .right: "arrow.right"
        case .button1: "circle.grid.cross.left.filled"
        case .button2: "circle.grid.cross.up.filled"
        case .button3: "circle.grid.cross.right.filled"
        case .button4: "circle.grid.cross.left.filled"
        case .button5: "circle.grid.cross.down.filled"
        case .button6: "circle.grid.cross.right.filled"
        case .start: "play.fill"
        case .coin: "creditcard.fill"
        }
    }

    var defaultBinding: MacadeKeyBinding {
        MacadeKeyBinding(keyCode: defaultMacKeyCode, displayName: defaultDisplayName)
    }

    var defaultDisplayName: String {
        switch self {
        case .up: "Up Arrow"
        case .down: "Down Arrow"
        case .left: "Left Arrow"
        case .right: "Right Arrow"
        case .button1: "Z"
        case .button2: "X"
        case .button3: "C"
        case .button4: "A"
        case .button5: "S"
        case .button6: "D"
        case .start: "1"
        case .coin: "5"
        }
    }

    var defaultMacKeyCode: UInt16 {
        switch self {
        case .up: 126
        case .down: 125
        case .left: 123
        case .right: 124
        case .button1: 6
        case .button2: 7
        case .button3: 8
        case .button4: 0
        case .button5: 1
        case .button6: 2
        case .start: 18
        case .coin: 23
        }
    }

    var defaultSDLScancode: Int32 {
        switch self {
        case .up: 82
        case .down: 81
        case .left: 80
        case .right: 79
        case .button1: 29
        case .button2: 27
        case .button3: 6
        case .button4: 4
        case .button5: 22
        case .button6: 7
        case .start: 30
        case .coin: 34
        }
    }
}

struct MacadeControllerPreferencesStore {
    private static let defaultsKey = "MacadeControllerPreferences"
    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    func load() -> MacadeControllerPreferences {
        guard let data = userDefaults.data(forKey: Self.defaultsKey),
              let preferences = try? JSONDecoder().decode(MacadeControllerPreferences.self, from: data) else {
            return .defaults
        }
        return preferences.normalized()
    }

    func save(_ preferences: MacadeControllerPreferences) {
        let normalized = preferences.normalized()
        guard let data = try? JSONEncoder().encode(normalized) else { return }
        userDefaults.set(data, forKey: Self.defaultsKey)
        NotificationCenter.default.post(name: .macadeControllerPreferencesDidChange, object: nil)
    }
}
