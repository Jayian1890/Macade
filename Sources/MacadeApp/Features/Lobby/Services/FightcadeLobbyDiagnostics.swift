import Foundation

final class FightcadeLobbyDiagnostics: @unchecked Sendable {
    private let settings: FightcadeLobbyDiagnosticsSettings
    private let environment: [String: String]
    private let fileManager: FileManager
    private let lock = NSLock()
    private var fileHandle: FileHandle?

    init(
        settings: FightcadeLobbyDiagnosticsSettings = FightcadeLobbyDiagnosticsSettings(),
        environment: [String: String] = ProcessInfo.processInfo.environment,
        fileManager: FileManager = .default
    ) {
        self.settings = settings
        self.environment = environment
        self.fileManager = fileManager
    }

    func outgoing(_ payload: [String: Any]) {
        guard let includeChatBodies = loggingState(), shouldLog(payload) else {
            return
        }

        writePayload("OUT", payload, includeChatBodies: includeChatBodies)
    }

    func incoming(_ payload: [String: Any]) {
        guard let includeChatBodies = loggingState(), shouldLog(payload) else {
            return
        }

        writePayload("IN", payload, includeChatBodies: includeChatBodies)
    }

    func note(_ message: String) {
        guard loggingState() != nil else {
            return
        }

        writeLine("NOTE \(Self.timestamp()) \(message)")
    }

    private func shouldLog(_ payload: [String: Any]) -> Bool {
        let req = (payload["req"] as? String)?.lowercased()
        return req == "join"
            || req == "chat"
            || req == "broken"
            || req == "challenge"
            || req == "accept"
            || req == "reject"
            || req == "cancel"
            || req == "start"
            || req == "stplaying"
            || req == "stnoplaying"
            || req == "quarkstats"
            || payload["requestIdx"] != nil
    }

    private func writePayload(_ direction: String, _ payload: [String: Any], includeChatBodies: Bool) {
        let sanitized = sanitize(payload, includeChatBodies: includeChatBodies) as? [String: Any] ?? [:]
        let request = sanitized["req"] as? String ?? "unknown"
        let requestIdx = sanitized["requestIdx"].map { " requestIdx=\($0)" } ?? ""
        writeLine("\(direction) \(Self.timestamp()) req=\(request)\(requestIdx)")

        guard JSONSerialization.isValidJSONObject(sanitized),
              let data = try? JSONSerialization.data(withJSONObject: sanitized, options: [.prettyPrinted, .sortedKeys]),
              let text = String(data: data, encoding: .utf8) else {
            writeLine("<unserializable payload>")
            return
        }

        writeLine(text)
    }

    private func loggingState() -> Bool? {
        let enabledByEnvironment = environment["MACADE_LOBBY_DIAGNOSTICS"] == "1"
        guard settings.isEnabled || enabledByEnvironment else {
            closeLog()
            return nil
        }

        let includeChatBodies = settings.includesChatBodies
            || environment["MACADE_LOBBY_DIAGNOSTICS_INCLUDE_CHAT"] == "1"
        prepareLog(includeChatBodies: includeChatBodies)
        return includeChatBodies
    }

    private func prepareLog(includeChatBodies: Bool) {
        lock.withLock {
            guard fileHandle == nil, let logURL = settings.logURL(fileManager: fileManager) else {
                return
            }

            try? fileManager.createDirectory(at: logURL.deletingLastPathComponent(), withIntermediateDirectories: true)
            fileManager.createFile(atPath: logURL.path, contents: nil)
            fileHandle = try? FileHandle(forWritingTo: logURL)
            rawWrite("=== Macade Fightcade Lobby Diagnostics ===")
            rawWrite("timestamp: \(Self.timestamp())")
            rawWrite("include chat bodies: \(includeChatBodies)")
            rawWrite("log: \(logURL.path)")
        }
    }

    private func closeLog() {
        lock.withLock {
            try? fileHandle?.close()
            fileHandle = nil
        }
    }

    private func sanitize(_ value: Any, includeChatBodies: Bool) -> Any {
        if let dictionary = value as? [String: Any] {
            var sanitized: [String: Any] = [:]
            for (key, value) in dictionary {
                sanitized[key] = sanitize(value, key: key, includeChatBodies: includeChatBodies)
            }
            return sanitized
        }

        if let array = value as? [Any] {
            return array.map { sanitize($0, includeChatBodies: includeChatBodies) }
        }

        return value
    }

    private func sanitize(_ value: Any, key: String, includeChatBodies: Bool) -> Any {
        let normalizedKey = key.lowercased()
        if normalizedKey.contains("token") || normalizedKey == "cookie" || normalizedKey == "location" {
            return "<redacted>"
        }

        if !includeChatBodies, normalizedKey == "chat" || normalizedKey == "msg" || normalizedKey == "message" {
            let string = value as? String ?? ""
            return "<redacted length=\(string.count)>"
        }

        return sanitize(value, includeChatBodies: includeChatBodies)
    }

    private func writeLine(_ line: String) {
        guard let data = (line + "\n").data(using: .utf8) else {
            return
        }

        lock.withLock {
            rawWrite(data)
        }
    }

    private func rawWrite(_ line: String) {
        guard let data = (line + "\n").data(using: .utf8) else {
            return
        }

        rawWrite(data)
    }

    private func rawWrite(_ data: Data) {
        guard let fileHandle else {
            return
        }

        do {
            try fileHandle.seekToEnd()
            try fileHandle.write(contentsOf: data)
            try fileHandle.synchronize()
        } catch {
            return
        }
    }

    private static func timestamp() -> String {
        ISO8601DateFormatter().string(from: Date())
    }
}

struct FightcadeLobbyDiagnosticsSettings {
    private static let enabledKey = "FightcadeLobbyDiagnosticsEnabled"
    private static let includeChatBodiesKey = "FightcadeLobbyDiagnosticsIncludeChatBodies"

    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    var isEnabled: Bool {
        get { userDefaults.bool(forKey: Self.enabledKey) }
        nonmutating set {
            userDefaults.set(newValue, forKey: Self.enabledKey)
            if !newValue {
                includesChatBodies = false
            }
        }
    }

    var includesChatBodies: Bool {
        get { userDefaults.bool(forKey: Self.includeChatBodiesKey) }
        nonmutating set { userDefaults.set(newValue, forKey: Self.includeChatBodiesKey) }
    }

    var relativeLogPath: String {
        "~/Library/Logs/Macade/fightcade-lobby-latest.log"
    }

    func logURL(fileManager: FileManager = .default) -> URL? {
        fileManager.urls(for: .libraryDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Logs")
            .appendingPathComponent("Macade")
            .appendingPathComponent("fightcade-lobby-latest.log")
    }
}
