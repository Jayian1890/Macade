import Foundation

struct GamepadDevice: Decodable, Equatable, Identifiable, Sendable {
    let id: String
    let name: String
    let hasSerial: Bool
    let controls: [MacadeGamepadControl]
    let axes: [Int]
    let initialAxes: [Int]

    var restingControls: Set<MacadeGamepadControl> {
        Set(initialAxes.enumerated().compactMap { index, value in
            value <= -30000 ? MacadeGamepadControl(kind: "a", index: index, direction: -1) : nil
        })
    }
}
struct GamepadSnapshot: Decodable, Sendable {
    let devices: [GamepadDevice]
}
struct GamepadGame: Decodable, Identifiable, Sendable {
    let id: String
    let title: String
}
struct GamepadGameInput: Decodable, Identifiable, Sendable {
    let index: Int
    let title: String
    let info: String
    let player: Int
    let analog: Bool
    var id: Int { index }
}
