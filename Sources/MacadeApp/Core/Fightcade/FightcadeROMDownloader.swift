import Foundation

@MainActor
protocol FightcadeROMDownloading {
    func downloadROM(emulator: String, system: String?, gameID: String) async throws -> URL
}

struct FightcadeROMDownloader: FightcadeROMDownloading {
    private static let defaultIndexURL = URL(string: "https://fightcade.download/fc2json.zip")!

    private let session: URLSession
    private let runtime: FightcadeRuntime
    private let fileManager: FileManager

    init(
        session: URLSession = .shared,
        runtime: FightcadeRuntime = FightcadeRuntime(),
        fileManager: FileManager = .default
    ) {
        self.session = session
        self.runtime = runtime
        self.fileManager = fileManager
    }

    func downloadROM(emulator: String, system: String?, gameID: String) async throws -> URL {
        let index = try await loadIndex()
        let entries = try index.entriesForDownload(emulator: emulator, system: system, gameID: gameID)
        var primaryDestination: URL?

        for entry in entries {
            let destination = try destination(for: entry, requestedEmulator: emulator)
            if entry.gameID == gameID {
                primaryDestination = destination.primary
            }

            if destination.isComplete(fileManager: fileManager) {
                continue
            }

            var lastError: Error?
            for mirror in entry.urls {
                do {
                    let downloaded = try await download(from: mirror)
                    try install(downloaded: downloaded, entry: entry, destination: destination)
                    lastError = nil
                    break
                } catch {
                    lastError = error
                }
            }

            if let lastError {
                throw lastError
            }
        }

        guard let primaryDestination else {
            throw FightcadeROMDownloadError.downloadFailed(gameID)
        }

        return primaryDestination
    }

    private func download(from url: URL) async throws -> URL {
        let (temporaryURL, response) = try await session.download(from: url)
        guard let httpResponse = response as? HTTPURLResponse,
              (200..<300).contains(httpResponse.statusCode) else {
            throw FightcadeROMDownloadError.downloadFailed(url.absoluteString)
        }

        let stagingURL = fileManager.temporaryDirectory
            .appendingPathComponent(UUID().uuidString)
            .appendingPathExtension("zip")
        try fileManager.moveItem(at: temporaryURL, to: stagingURL)
        return stagingURL
    }

    private func install(downloaded: URL, entry: FightcadeROMIndexEntry, destination: FightcadeROMDestination) throws {
        if entry.extractTargets.isEmpty {
            try fileManager.createDirectory(at: destination.primary.deletingLastPathComponent(), withIntermediateDirectories: true)
            if fileManager.fileExists(atPath: destination.primary.path) {
                try fileManager.removeItem(at: destination.primary)
            }
            try fileManager.moveItem(at: downloaded, to: destination.primary)
            return
        }

        defer { try? fileManager.removeItem(at: downloaded) }
        let archive = FightcadeZipArchive(data: try Data(contentsOf: downloaded))
        for target in destination.extracts {
            let data = try archive.fileData(named: target.source)
            try fileManager.createDirectory(at: target.destination.deletingLastPathComponent(), withIntermediateDirectories: true)
            try data.write(to: target.destination, options: .atomic)
        }
    }

    private func destination(for entry: FightcadeROMIndexEntry, requestedEmulator: String) throws -> FightcadeROMDestination {
        let emulator = entry.emulator ?? requestedEmulator
        if !entry.extractTargets.isEmpty {
            let extracts = try entry.extractTargets.map { target in
                FightcadeROMExtractDestination(
                    source: target.source,
                    destination: try runtime.romRelativeURL(
                        emulator: emulator,
                        relativePath: macadeROMRelativePath(target.destination, emulator: emulator)
                    )
                )
            }
            let outputs = extracts.map(\.destination)
            let primary: URL
            if let firstOutput = outputs.first {
                primary = firstOutput
            } else {
                primary = try runtime.romFileURL(emulator: emulator, fileName: entry.downloadFileName)
            }
            return FightcadeROMDestination(primary: primary, outputs: outputs, extracts: extracts)
        }

        let output = try runtime.romFileURL(emulator: emulator, fileName: entry.downloadFileName)
        return FightcadeROMDestination(primary: output, outputs: [output], extracts: [])
    }

    private func macadeROMRelativePath(_ path: String, emulator: String) -> String {
        var normalized = path.replacingOccurrences(of: "\\", with: "/")
        while normalized.hasPrefix("/") {
            normalized.removeFirst()
        }

        for prefix in ["roms/", "ROMs/", "Roms/", "\(emulator)/", "\(emulator.lowercased())/"] where normalized.hasPrefix(prefix) {
            normalized.removeFirst(prefix.count)
            break
        }

        return normalized
    }

    private func loadIndex() async throws -> FightcadeROMIndex {
        if let override = ProcessInfo.processInfo.environment["MACADE_ROM_INDEX_URL"],
           let url = URL(string: override),
           !override.isEmpty {
            return try await fetchIndex(from: url)
        }

        do {
            return try await fetchIndex(from: Self.defaultIndexURL)
        } catch {
            return try loadBundledIndex()
        }

    }

    private func fetchIndex(from url: URL) async throws -> FightcadeROMIndex {
        let (data, response) = try await session.data(from: url)
        guard let httpResponse = response as? HTTPURLResponse,
              (200..<300).contains(httpResponse.statusCode) else {
            throw FightcadeROMDownloadError.indexUnavailable
        }
        return try FightcadeROMIndex(data: data, sourceName: url.lastPathComponent)
    }

    private func loadBundledIndex() throws -> FightcadeROMIndex {
        guard let bundledURL = MacadeResourceBundle.bundle.url(forResource: "rom-index", withExtension: "json") else {
            throw FightcadeROMDownloadError.indexUnavailable
        }

        return try FightcadeROMIndex(data: Data(contentsOf: bundledURL), sourceName: bundledURL.lastPathComponent)
    }
}

private struct FightcadeROMDestination {
    let primary: URL
    let outputs: [URL]
    let extracts: [FightcadeROMExtractDestination]

    func isComplete(fileManager: FileManager) -> Bool {
        !outputs.isEmpty && outputs.allSatisfy { fileManager.fileExistsAndIsNotEmpty(at: $0) }
    }
}

private struct FightcadeROMExtractDestination {
    let source: String
    let destination: URL
}

private extension FileManager {
    func fileExistsAndIsNotEmpty(at url: URL) -> Bool {
        guard let attributes = try? attributesOfItem(atPath: url.path),
              let size = attributes[.size] as? NSNumber else {
            return false
        }

        return size.int64Value > 0
    }
}

struct FightcadeROMIndex: Sendable {
    private let entries: [FightcadeROMIndexEntry]

    init(data: Data, sourceName: String) throws {
        if sourceName.lowercased().hasSuffix(".zip") || data.starts(with: [0x50, 0x4b]) {
            self.entries = try FightcadeZipArchive(data: data).jsonFiles().flatMap { file in
                try Self.entries(
                    from: file.data,
                    emulatorHint: Self.emulatorHint(from: file.name),
                    systemHint: Self.systemHint(from: file.name)
                )
            }
        } else {
            self.entries = try Self.entries(from: data, emulatorHint: nil, systemHint: nil)
        }
    }

    func entriesForDownload(emulator: String, system: String?, gameID: String) throws -> [FightcadeROMIndexEntry] {
        var resolved: [FightcadeROMIndexEntry] = []
        var visiting = Set<String>()
        try collect(emulator: emulator, system: system, gameID: gameID, into: &resolved, visiting: &visiting)
        return resolved
    }

    private func collect(
        emulator: String,
        system: String?,
        gameID: String,
        into resolved: inout [FightcadeROMIndexEntry],
        visiting: inout Set<String>
    ) throws {
        guard visiting.insert(gameID).inserted else {
            return
        }

        let current = try entry(emulator: emulator, system: system, gameID: gameID)
        for requirement in current.requires {
            try collect(emulator: emulator, system: current.system ?? system, gameID: requirement, into: &resolved, visiting: &visiting)
        }

        if !resolved.contains(where: { $0.gameID == current.gameID }) {
            resolved.append(current)
        }
    }

    private func entry(emulator: String, system: String?, gameID: String) throws -> FightcadeROMIndexEntry {
        let emulatorID = emulator.lowercased()
        let candidates = entries.filter { $0.gameID == gameID && ($0.emulator == nil || $0.emulator == emulatorID) }
        if let systemMatch = candidates.first(where: { Self.systemMatches($0.system, requested: system) }) {
            return systemMatch
        }

        if let arcadeMatch = candidates.first(where: { $0.system == "arcade" }) {
            return arcadeMatch
        }

        if let exact = candidates.first {
            return exact
        }

        throw FightcadeROMDownloadError.missingIndexEntry(gameID)
    }

    private static func entries(from data: Data, emulatorHint: String?, systemHint: String?) throws -> [FightcadeROMIndexEntry] {
        let json = try JSONSerialization.jsonObject(with: data)
        return entries(from: json, emulatorHint: emulatorHint, systemHint: systemHint)
    }

    private static func entries(from json: Any, emulatorHint: String?, systemHint: String?) -> [FightcadeROMIndexEntry] {
        if let array = json as? [Any] {
            return array.compactMap { entry(from: $0, fallbackGameID: nil, emulatorHint: emulatorHint, systemHint: systemHint) }
        }

        guard let dictionary = json as? [String: Any] else {
            return []
        }

        for key in ["roms", "games", "files", "entries"] {
            if let nested = dictionary[key] {
                return entries(from: nested, emulatorHint: emulatorHint, systemHint: systemHint)
            }
        }

        return dictionary.compactMap { key, value in
            entry(from: value, fallbackGameID: key, emulatorHint: emulatorHint, systemHint: systemHint)
        }
    }

    private static func entry(
        from value: Any,
        fallbackGameID: String?,
        emulatorHint: String?,
        systemHint: String?
    ) -> FightcadeROMIndexEntry? {
        if let urlString = value as? String, let url = URL(string: urlString), let fallbackGameID {
            return FightcadeROMIndexEntry(
                gameID: fallbackGameID,
                emulator: emulatorHint,
                system: systemHint,
                urls: [url],
                requires: [],
                extractTargets: []
            )
        }

        if let mirrors = value as? [String], let fallbackGameID {
            let urls = mirrors.compactMap(URL.init(string:))
            return urls.isEmpty ? nil : FightcadeROMIndexEntry(
                gameID: fallbackGameID,
                emulator: emulatorHint,
                system: systemHint,
                urls: urls,
                requires: [],
                extractTargets: []
            )
        }

        guard let dictionary = value as? [String: Any] else {
            return nil
        }

        let gameID = string(in: dictionary, keys: ["gameid", "gameId", "game", "name", "id", "filename"])
            ?? fallbackGameID
        let emulator = string(in: dictionary, keys: ["emulator", "emu"])?.lowercased() ?? emulatorHint
        let system = canonicalSystem(string(in: dictionary, keys: ["system", "platform", "console"])) ?? systemHint
        let urls = urls(in: dictionary)
        let requires = strings(in: dictionary, keys: ["require", "requires", "dependencies", "parents"])
        let extractTargets = extractTargets(in: dictionary)

        guard let gameID, !urls.isEmpty else {
            return nil
        }

        return FightcadeROMIndexEntry(
            gameID: gameID.replacingOccurrences(of: ".zip", with: ""),
            emulator: emulator,
            system: system,
            urls: urls,
            requires: requires.map { $0.replacingOccurrences(of: ".zip", with: "") },
            extractTargets: extractTargets
        )
    }

    private static func emulatorHint(from fileName: String) -> String? {
        let lowercased = fileName.lowercased()
        if lowercased.hasPrefix("fbneo") { return "fbneo" }
        if lowercased.hasPrefix("flycast") { return "flycast" }
        if lowercased.hasPrefix("snes9x") { return "snes9x" }
        if lowercased.hasPrefix("fc1") { return "fc1" }
        if lowercased.hasPrefix("nulldc") { return "nulldc" }
        return nil
    }

    private static func systemHint(from fileName: String) -> String? {
        let lowercased = fileName.lowercased()
        if lowercased.hasPrefix("fbneo_roms") { return "arcade" }
        if lowercased.hasPrefix("fbneo_cv") { return "colecovision" }
        if lowercased.hasPrefix("fbneo_gg") { return "gamegear" }
        if lowercased.hasPrefix("fbneo_md") { return "megadrive" }
        if lowercased.hasPrefix("fbneo_msx") { return "msx" }
        if lowercased.hasPrefix("fbneo_nes") { return "nes" }
        if lowercased.hasPrefix("fbneo_pce") { return "pcengine" }
        if lowercased.hasPrefix("fbneo_sg1k") { return "sg1000" }
        if lowercased.hasPrefix("fbneo_sms") { return "mastersystem" }
        if lowercased.hasPrefix("fbneo_tg") { return "turbografx16" }
        if lowercased.hasPrefix("fc1") { return "arcade" }
        if lowercased.hasPrefix("flycast") || lowercased.hasPrefix("nulldc") { return "dreamcast" }
        if lowercased.hasPrefix("snes9x") { return "snes" }
        return nil
    }

    private static func systemMatches(_ indexed: String?, requested: String?) -> Bool {
        guard let indexed else { return false }
        return indexed == canonicalSystem(requested)
    }

    private static func canonicalSystem(_ value: String?) -> String? {
        guard let normalized = value.map(normalizedSystem), !normalized.isEmpty else { return nil }
        switch normalized {
        case "arcade", "fbneo", "fba", "finalburnneo": return "arcade"
        case "coleco", "colecovision", "cv": return "colecovision"
        case "gamegear", "gg", "segagamegear": return "gamegear"
        case "genesis", "megadrive", "md", "segagenesis", "segamegadrive": return "megadrive"
        case "msx": return "msx"
        case "nes", "famicom", "nintendoentertainmentsystem": return "nes"
        case "pcengine", "pce", "turbografx", "turbografx16", "tg16": return "pcengine"
        case "sg1000", "sg1k", "segasg1000": return "sg1000"
        case "mastersystem", "sms", "segamastersystem": return "mastersystem"
        case "dreamcast", "dc": return "dreamcast"
        case "snes", "supernintendo", "superfamicom", "supernintendoentertainmentsystem": return "snes"
        default: return normalized
        }
    }

    private static func normalizedSystem(_ value: String) -> String {
        value.lowercased().filter { $0.isLetter || $0.isNumber }
    }

    private static func urls(in dictionary: [String: Any]) -> [URL] {
        let keys = ["url", "download", "href", "link", "source", "mirror", "mirrors", "urls", "links"]
        return keys.flatMap { key -> [URL] in
            if let string = dictionary[key] as? String, let url = URL(string: string) {
                return [url]
            }

            if let strings = dictionary[key] as? [String] {
                return strings.compactMap(URL.init(string:))
            }

            return []
        }
    }

    private static func extractTargets(in dictionary: [String: Any]) -> [FightcadeROMExtractTarget] {
        let rawTargets = dictionary["extract_to"] as? [Any]
            ?? dictionary["extractTo"] as? [Any]
            ?? dictionary["extract"] as? [Any]
            ?? []

        return rawTargets.compactMap { rawTarget in
            guard let target = rawTarget as? [String: Any],
                  let source = string(in: target, keys: ["src", "source"]),
                  let destination = string(in: target, keys: ["dst", "destination", "dest"]) else {
                return nil
            }

            return FightcadeROMExtractTarget(source: source, destination: destination)
        }
    }

    private static func string(in dictionary: [String: Any], keys: [String]) -> String? {
        for key in keys {
            if let string = dictionary[key] as? String, !string.isEmpty {
                return string
            }
        }
        return nil
    }

    private static func strings(in dictionary: [String: Any], keys: [String]) -> [String] {
        keys.flatMap { key -> [String] in
            if let string = dictionary[key] as? String { return [string] }
            if let strings = dictionary[key] as? [String] { return strings }
            return []
        }
    }
}

struct FightcadeROMIndexEntry: Sendable {
    let gameID: String
    let emulator: String?
    let system: String?
    let urls: [URL]
    let requires: [String]
    let extractTargets: [FightcadeROMExtractTarget]

    var downloadFileName: String {
        guard let fileName = urls.first?.lastPathComponent, !fileName.isEmpty else {
            return "\(gameID).zip"
        }

        return fileName
    }
}

struct FightcadeROMExtractTarget: Sendable, Equatable {
    let source: String
    let destination: String
}

enum FightcadeROMDownloadError: LocalizedError, Equatable {
    case indexUnavailable
    case missingIndexEntry(String)
    case downloadFailed(String)
    case archiveEntryMissing(String)

    var errorDescription: String? {
        switch self {
        case .indexUnavailable:
            "ROM index unavailable. Set MACADE_ROM_INDEX_URL to a Fightcade JSON pack index."
        case .missingIndexEntry(let gameID):
            "No ROM download entry found for \(gameID)."
        case .downloadFailed(let value):
            "Could not download ROM from \(value)."
        case .archiveEntryMissing(let value):
            "Downloaded archive did not contain \(value)."
        }
    }
}
