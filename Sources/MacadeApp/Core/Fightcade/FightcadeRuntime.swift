import Foundation

struct FightcadeRuntime {
    private let fileManager: FileManager

    init(fileManager: FileManager = .default) {
        self.fileManager = fileManager
    }

    func root() throws -> URL {
        guard let bundledRuntime = bundledRoot() else {
            let expectedPath = MacadeResourceBundle.bundle.resourceURL?
                .appendingPathComponent("FightcadeRuntime")
                .path ?? "FightcadeRuntime"
            throw FightcadeLaunchError.missingRuntime([expectedPath])
        }

        return bundledRuntime
    }

    func bundledRoot() -> URL? {
        guard let bundledRuntime = MacadeResourceBundle.bundle.resourceURL?.appendingPathComponent("FightcadeRuntime"),
              directoryExists(bundledRuntime) else {
            return nil
        }

        return bundledRuntime
    }

    func romURL(emulator: String, gameID: String) throws -> URL {
        let game = try safePathComponent(gameID)
        return try romFileURL(emulator: emulator, fileName: "\(game).zip")
    }

    func existingROMURL(emulator: String, gameID: String) throws -> URL? {
        let candidates = try romCandidateURLs(emulator: emulator, gameID: gameID)
        return candidates.first { url in
            guard let attributes = try? fileManager.attributesOfItem(atPath: url.path),
                  let size = attributes[.size] as? NSNumber else {
                return false
            }

            return size.int64Value > 0
        }
    }

    func deleteROMs(emulator: String, gameID: String) throws -> [URL] {
        let candidates = try romCandidateURLs(emulator: emulator, gameID: gameID)
        var deleted: [URL] = []

        for url in candidates where fileManager.fileExists(atPath: url.path) {
            try fileManager.removeItem(at: url)
            deleted.append(url)
        }

        return deleted
    }

    func romCandidateURLs(emulator: String, gameID: String) throws -> [URL] {
        let directory = try romDirectory(emulator: emulator)
        return try romFileNameCandidates(emulator: emulator, gameID: gameID).map { fileName in
            directory.appendingPathComponent(fileName)
        }
    }

    func romDirectory(emulator: String) throws -> URL {
        let emulatorID = try safePathComponent(emulator.lowercased())
        let directory = try applicationSupportROMRoot()
            .appendingPathComponent(emulatorID)
        try fileManager.createDirectory(at: directory, withIntermediateDirectories: true)
        return directory
    }

    func romFileURL(emulator: String, fileName: String) throws -> URL {
        let file = try safeROMPathComponents(fileName).joined(separator: "/")
        return try romDirectory(emulator: emulator).appendingPathComponent(file)
    }

    func romRelativeURL(emulator: String, relativePath: String) throws -> URL {
        let relative = try safeROMPathComponents(relativePath).joined(separator: "/")
        return try romDirectory(emulator: emulator).appendingPathComponent(relative)
    }

    func safePathComponent(_ value: String) throws -> String {
        let allowed = CharacterSet.alphanumerics.union(CharacterSet(charactersIn: "-_."))
        let trimmed = value.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !trimmed.isEmpty,
              trimmed.rangeOfCharacter(from: allowed.inverted) == nil,
              trimmed != ".",
              trimmed != ".." else {
            throw FightcadeLaunchError.missingGame
        }

        return trimmed
    }

    private func applicationSupportROMRoot() throws -> URL {
        guard let supportURL = fileManager.urls(for: .applicationSupportDirectory, in: .userDomainMask).first else {
            throw FightcadeLaunchError.missingRuntime([])
        }

        return supportURL
            .appendingPathComponent("Macade")
            .appendingPathComponent("FightcadeRuntime")
            .appendingPathComponent("roms")
    }

    private func romFileNameCandidates(emulator: String, gameID: String) throws -> [String] {
        let normalizedEmulator = emulator.lowercased()
        var stems = [try safePathComponent(gameID)]
        let prefixes = ["\(normalizedEmulator)_", "snes_", "flycast_", "nulldc_"]

        for prefix in prefixes where gameID.lowercased().hasPrefix(prefix) {
            let stripped = String(gameID.dropFirst(prefix.count))
            if !stripped.isEmpty {
                stems.append(try safePathComponent(stripped))
            }
        }

        var fileNames: [String] = []
        for stem in stems {
            let name = stem.lowercased().hasSuffix(".zip") ? stem : "\(stem).zip"
            if !fileNames.contains(name) {
                fileNames.append(name)
            }
        }

        return fileNames
    }

    private func safeROMPathComponents(_ value: String) throws -> [String] {
        let components = value
            .replacingOccurrences(of: "\\", with: "/")
            .split(separator: "/")
            .map { String($0).trimmingCharacters(in: .whitespacesAndNewlines) }

        guard !components.isEmpty else {
            throw FightcadeLaunchError.missingGame
        }

        for component in components {
            guard !component.isEmpty,
                  component != ".",
                  component != "..",
                  component.rangeOfCharacter(from: CharacterSet(charactersIn: ":\0")) == nil else {
                throw FightcadeLaunchError.missingGame
            }
        }

        return components
    }

    private func directoryExists(_ url: URL) -> Bool {
        var isDirectory: ObjCBool = false
        return fileManager.fileExists(atPath: url.path, isDirectory: &isDirectory) && isDirectory.boolValue
    }
}
