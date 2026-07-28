import Foundation

import Foundation

protocol JoinedChannelPersisting {
    func joinedChannelIDs(for session: AuthSession) -> [FightcadeChannel.ID]
    func saveJoinedChannelIDs(_ ids: [FightcadeChannel.ID], for session: AuthSession)
}

struct UserDefaultsJoinedChannelStore: JoinedChannelPersisting {
    private static let keyPrefix = "JoinedFightcadeChannels"
    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    func joinedChannelIDs(for session: AuthSession) -> [FightcadeChannel.ID] {
        userDefaults.stringArray(forKey: key(for: session)) ?? []
    }

    func saveJoinedChannelIDs(_ ids: [FightcadeChannel.ID], for session: AuthSession) {
        userDefaults.set(ids.uniqued(), forKey: key(for: session))
    }

    private func key(for session: AuthSession) -> String {
        let username = session.username
            .trimmingCharacters(in: .whitespacesAndNewlines)
            .lowercased()
        return "\(Self.keyPrefix).\(username)"
    }
}

private extension Array where Element == String {
    func uniqued() -> [String] {
        var seen = Set<String>()
        var result: [String] = []

        for value in self where seen.insert(value).inserted {
            result.append(value)
        }

        return result
    }
}

protocol FightcadeChannelCaching: Sendable {
    func loadChannels(for session: AuthSession) async -> [FightcadeChannel]
    func saveChannels(_ channels: [FightcadeChannel], for session: AuthSession) async
}

actor FileFightcadeChannelCache: FightcadeChannelCaching {
    private let rootURL: URL?
    private let fileManager: FileManager
    private let decoder = JSONDecoder()
    private let encoder = JSONEncoder()

    init(rootURL: URL? = nil, fileManager: FileManager = .default) {
        self.rootURL = rootURL
        self.fileManager = fileManager
    }

    func loadChannels(for session: AuthSession) async -> [FightcadeChannel] {
        guard let fileURL = fileURL(for: session),
              let data = try? Data(contentsOf: fileURL),
              let channels = try? decoder.decode([FightcadeChannel].self, from: data) else {
            return []
        }

        return channels
    }

    func saveChannels(_ channels: [FightcadeChannel], for session: AuthSession) async {
        guard !channels.isEmpty,
              let root = cacheRootURL(),
              let fileURL = fileURL(for: session),
              let data = try? encoder.encode(channels) else {
            return
        }

        do {
            try fileManager.createDirectory(at: root, withIntermediateDirectories: true)
            try data.write(to: fileURL, options: .atomic)
        } catch {
            return
        }
    }

    private func fileURL(for session: AuthSession) -> URL? {
        cacheRootURL()?.appendingPathComponent("channels-\(cacheKey(for: session)).json")
    }

    private func cacheRootURL() -> URL? {
        if let rootURL {
            return rootURL
        }

        return fileManager.urls(for: .cachesDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Macade", isDirectory: true)
            .appendingPathComponent("Lobby", isDirectory: true)
    }

    private func cacheKey(for session: AuthSession) -> String {
        let username = session.username.trimmingCharacters(in: .whitespacesAndNewlines).lowercased()
        let fallback = session.displayName.trimmingCharacters(in: .whitespacesAndNewlines).lowercased()
        let source = username.isEmpty ? fallback : username
        let sanitized = source.unicodeScalars.map { scalar -> UnicodeScalar in
            switch scalar.value {
            case 45, 48...57, 95, 97...122:
                return scalar
            default:
                return "-"
            }
        }

        let key = String(String.UnicodeScalarView(sanitized)).trimmingCharacters(in: CharacterSet(charactersIn: "-"))
        return key.isEmpty ? "anonymous" : key
    }
}
