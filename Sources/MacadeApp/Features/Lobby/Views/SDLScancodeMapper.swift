import AppKit

enum SDLScancodeMapper {
    static func binding(for event: NSEvent) -> MacadeKeyBinding? {
        guard scancode(for: event) != nil else { return nil }
        return MacadeKeyBinding(keyCode: event.keyCode, displayName: displayName(for: event))
    }

    static func scancode(for event: NSEvent) -> Int32? {
        if let special = specialScancodes[event.keyCode] {
            return special
        }

        guard let character = event.charactersIgnoringModifiers?.lowercased().first else {
            return nil
        }

        if let letter = character.asciiValue, letter >= 97, letter <= 122 {
            return Int32(letter - 93)
        }

        return characterScancodes[character]
    }

    static func displayName(for event: NSEvent) -> String {
        if let special = specialNames[event.keyCode] {
            return special
        }

        guard let character = event.charactersIgnoringModifiers?.uppercased().first else {
            return "Key \(event.keyCode)"
        }

        switch character {
        case " ": return "Space"
        case "\t": return "Tab"
        default: return String(character)
        }
    }

    private static let specialScancodes: [UInt16: Int32] = [
        36: 40,
        48: 43,
        49: 44,
        51: 42,
        53: 41,
        56: 225,
        57: 57,
        58: 226,
        59: 227,
        60: 229,
        61: 230,
        62: 231,
        96: 62,
        97: 63,
        98: 64,
        99: 60,
        100: 65,
        101: 66,
        103: 68,
        109: 67,
        111: 69,
        118: 61,
        120: 59,
        122: 58,
        123: 80,
        124: 79,
        125: 81,
        126: 82
    ]

    private static let specialNames: [UInt16: String] = [
        36: "Return",
        48: "Tab",
        49: "Space",
        51: "Delete",
        53: "Escape",
        56: "Left Shift",
        57: "Caps Lock",
        58: "Left Option",
        59: "Left Control",
        60: "Right Shift",
        61: "Right Option",
        62: "Right Control",
        96: "F5",
        97: "F6",
        98: "F7",
        99: "F3",
        100: "F8",
        101: "F9",
        103: "F11",
        109: "F10",
        111: "F12",
        118: "F4",
        120: "F2",
        122: "F1",
        123: "Left Arrow",
        124: "Right Arrow",
        125: "Down Arrow",
        126: "Up Arrow"
    ]

    private static let characterScancodes: [Character: Int32] = [
        "1": 30,
        "2": 31,
        "3": 32,
        "4": 33,
        "5": 34,
        "6": 35,
        "7": 36,
        "8": 37,
        "9": 38,
        "0": 39,
        "-": 45,
        "=": 46,
        "[": 47,
        "]": 48,
        "\\": 49,
        ";": 51,
        "'": 52,
        "`": 53,
        ",": 54,
        ".": 55,
        "/": 56
    ]
}
