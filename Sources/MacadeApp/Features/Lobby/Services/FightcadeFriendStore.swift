import Foundation

protocol FightcadeFriendPersisting: Sendable {
    func loadFriends(for session: AuthSession) async -> [FightcadeFriend]
    func saveFriends(_ friends: [FightcadeFriend], for session: AuthSession) async
}

actor FileFightcadeFriendStore: FightcadeFriendPersisting {
    private let rootURL: URL?
    private let fileManager: FileManager
    private let decoder = JSONDecoder()
    private let encoder = JSONEncoder()

    init(rootURL: URL? = nil, fileManager: FileManager = .default) {
        self.rootURL = rootURL
        self.fileManager = fileManager
        encoder.outputFormatting = [.prettyPrinted, .sortedKeys]
    }

    func loadFriends(for session: AuthSession) async -> [FightcadeFriend] {
        guard let fileURL = fileURL(for: session),
              let data = try? Data(contentsOf: fileURL),
              let friends = try? decoder.decode([FightcadeFriend].self, from: data) else {
            return []
        }

        return friends.uniquedAndSorted()
    }

    func saveFriends(_ friends: [FightcadeFriend], for session: AuthSession) async {
        guard let root = rootDirectoryURL(),
              let fileURL = fileURL(for: session),
              let data = try? encoder.encode(friends.uniquedAndSorted()) else {
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
        rootDirectoryURL()?.appendingPathComponent("friends-\(cacheKey(for: session)).json")
    }

    private func rootDirectoryURL() -> URL? {
        if let rootURL {
            return rootURL
        }

        return fileManager.urls(for: .applicationSupportDirectory, in: .userDomainMask).first?
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
                return UnicodeScalar(45)!
            }
        }

        let key = String(String.UnicodeScalarView(sanitized)).trimmingCharacters(in: CharacterSet(charactersIn: "-"))
        return key.isEmpty ? "anonymous" : key
    }
}

private extension Array where Element == FightcadeFriend {
    func uniquedAndSorted() -> [FightcadeFriend] {
        var seen = Set<String>()
        var result: [FightcadeFriend] = []

        for friend in self where !friend.username.isEmpty && seen.insert(friend.id).inserted {
            result.append(friend)
        }

        return result.sorted {
            $0.title.localizedCaseInsensitiveCompare($1.title) == .orderedAscending
        }
    }
}
