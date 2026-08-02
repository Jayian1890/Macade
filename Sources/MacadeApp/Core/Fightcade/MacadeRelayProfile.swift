import Foundation

extension Notification.Name {
    static let macadeRelayProfileDidChange = Notification.Name("macadeRelayProfileDidChange")
    static let macadeRelayConsoleRequested = Notification.Name("macadeRelayConsoleRequested")
}

enum MacadeRelayGate {
    static func matches(_ text: String) -> Bool {
        let command = text.trimmingCharacters(in: .whitespacesAndNewlines)
        return command.compare(Self.command, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
    }

    static func request() {
        NotificationCenter.default.post(name: .macadeRelayConsoleRequested, object: nil)
    }

    private static var command: String {
        String(decoding: [47, 108, 101, 101, 116], as: UTF8.self)
    }
}

enum MacadeRelayKey: String, CaseIterable, Codable, Identifiable, Sendable {
    case equals
    case minus
    case zero
    case nine
    case eight

    var id: String { rawValue }

    var label: String {
        switch self {
        case .equals: "="
        case .minus: "-"
        case .zero: "0"
        case .nine: "9"
        case .eight: "8"
        }
    }

    var keyCode: UInt16 {
        switch self {
        case .equals: 24
        case .minus: 27
        case .zero: 29
        case .nine: 25
        case .eight: 28
        }
    }

    static func match(_ keyCode: UInt16) -> MacadeRelayKey? {
        allCases.first { $0.keyCode == keyCode }
    }
}

struct MacadeRelayNode: Codable, Equatable, Identifiable, Sendable {
    var id: UUID
    var scancode: Int32
    var label: String

    init(id: UUID = UUID(), scancode: Int32, label: String) {
        self.id = id
        self.scancode = scancode
        self.label = label
    }
}

struct MacadeRelayFrame: Codable, Equatable, Identifiable, Sendable {
    var id: UUID
    var nodes: [MacadeRelayNode]
    var holdMilliseconds: Int
    var gapMilliseconds: Int

    init(
        id: UUID = UUID(),
        nodes: [MacadeRelayNode],
        holdMilliseconds: Int = MacadeRelayProfile.defaultHoldMilliseconds,
        gapMilliseconds: Int = MacadeRelayProfile.defaultGapMilliseconds
    ) {
        self.id = id
        self.nodes = nodes
        self.holdMilliseconds = holdMilliseconds
        self.gapMilliseconds = gapMilliseconds
    }

    var label: String {
        nodes.map(\.label).joined(separator: " + ")
    }

    var scancodes: [Int32] {
        nodes.map(\.scancode)
    }
}

struct MacadeRelayLane: Codable, Equatable, Identifiable, Sendable {
    var key: MacadeRelayKey
    var title: String
    var isEnabled: Bool
    var frames: [MacadeRelayFrame]

    var id: String { key.id }

    init(key: MacadeRelayKey, title: String? = nil, isEnabled: Bool = false, frames: [MacadeRelayFrame] = []) {
        self.key = key
        self.title = title ?? "Lane \(key.label)"
        self.isEnabled = isEnabled
        self.frames = frames
    }

    var isRunnable: Bool {
        isEnabled && frames.contains { !$0.nodes.isEmpty }
    }
}

struct MacadeRelayProfile: Codable, Equatable, Sendable {
    static let defaultHoldMilliseconds = 60
    static let defaultGapMilliseconds = 30
    static let holdRange = 1...2_000
    static let gapRange = 0...2_000
    static let maximumFrames = 2_048
    static let maximumNodesPerFrame = 8

    var lanes: [MacadeRelayLane]

    static let defaults = MacadeRelayProfile(
        lanes: MacadeRelayKey.allCases.map { MacadeRelayLane(key: $0) }
    )

    func lane(for key: MacadeRelayKey) -> MacadeRelayLane? {
        normalized().lanes.first { $0.key == key }
    }

    func normalized() -> MacadeRelayProfile {
        var existing: [MacadeRelayKey: MacadeRelayLane] = [:]
        for lane in lanes where existing[lane.key] == nil {
            existing[lane.key] = lane
        }
        return MacadeRelayProfile(lanes: MacadeRelayKey.allCases.map { key in
            var lane = existing[key] ?? MacadeRelayLane(key: key)
            lane.key = key
            lane.title = String(lane.title.trimmingCharacters(in: .whitespacesAndNewlines).prefix(48))
            if lane.title.isEmpty {
                lane.title = "Lane \(key.label)"
            }
            lane.frames = lane.frames.prefix(Self.maximumFrames).map(Self.normalizedFrame)
            return lane
        })
    }

    private static func normalizedFrame(_ frame: MacadeRelayFrame) -> MacadeRelayFrame {
        var normalized = frame
        normalized.holdMilliseconds = min(max(normalized.holdMilliseconds, holdRange.lowerBound), holdRange.upperBound)
        normalized.gapMilliseconds = min(max(normalized.gapMilliseconds, gapRange.lowerBound), gapRange.upperBound)

        var seenScancodes = Set<Int32>()
        normalized.nodes = normalized.nodes.compactMap { node in
            guard node.scancode >= 0, seenScancodes.insert(node.scancode).inserted else { return nil }
            let label = String(node.label.trimmingCharacters(in: .whitespacesAndNewlines).prefix(32))
            return MacadeRelayNode(id: node.id, scancode: node.scancode, label: label.isEmpty ? "Key \(node.scancode)" : label)
        }
        normalized.nodes = Array(normalized.nodes.prefix(maximumNodesPerFrame))
        return normalized
    }
}

struct MacadeRelayProfileStore {
    private static let defaultsKey = "MacadeRelayProfile.v1"
    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    func load() -> MacadeRelayProfile {
        guard let data = userDefaults.data(forKey: Self.defaultsKey),
              let profile = try? JSONDecoder().decode(MacadeRelayProfile.self, from: data) else {
            return .defaults
        }
        return profile.normalized()
    }

    func save(_ profile: MacadeRelayProfile) {
        let normalized = profile.normalized()
        guard let data = try? JSONEncoder().encode(normalized) else { return }
        userDefaults.set(data, forKey: Self.defaultsKey)
        NotificationCenter.default.post(name: .macadeRelayProfileDidChange, object: nil)
    }
}
