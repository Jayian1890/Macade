import Foundation

extension Notification.Name {
    static let fightcadeFBNeoSettingsDidChange = Notification.Name("fightcadeFBNeoSettingsDidChange")
}

struct FightcadeFBNeoSettings: Equatable, Sendable {
    static let supportedSampleRates = [44_100, 48_000, 96_000]
    static let supportedInterpolationModes = [0, 1, 3]
    static let defaultSamplesPath = "support/samples/"
    static let defaultHiscorePath = "support/hiscores/"
    static let defaultEEPROMPath = "config/games/"
    static let defaultHDDPath = "support/hdd/"

    var stretchToWindow: Bool
    var scanlines: Bool
    var softwareGamma: Bool
    var gamma: Double
    var volume: Int
    var sampleRate: Int
    var dspFilter: Bool
    var pcmInterpolation: Int
    var fmInterpolation: Int
    var hiscores: Bool
    var autoFireRate: Int
    var samplesPath: String
    var hiscorePath: String
    var eepromPath: String
    var hddPath: String
    var controllerMappings: String

    static let defaults = FightcadeFBNeoSettings(
        stretchToWindow: false,
        scanlines: false,
        softwareGamma: false,
        gamma: 1.25,
        volume: 50,
        sampleRate: 44_100,
        dspFilter: false,
        pcmInterpolation: 1,
        fmInterpolation: 0,
        hiscores: false,
        autoFireRate: 12,
        samplesPath: defaultSamplesPath,
        hiscorePath: defaultHiscorePath,
        eepromPath: defaultEEPROMPath,
        hddPath: defaultHDDPath,
        controllerMappings: ""
    )

    func normalized() -> FightcadeFBNeoSettings {
        var copy = self
        copy.gamma = max(0.5, min(2.0, gamma))
        copy.volume = max(0, min(100, volume))
        if !Self.supportedSampleRates.contains(sampleRate) {
            copy.sampleRate = Self.defaults.sampleRate
        }
        if !Self.supportedInterpolationModes.contains(pcmInterpolation) {
            copy.pcmInterpolation = Self.defaults.pcmInterpolation
        }
        if !Self.supportedInterpolationModes.contains(fmInterpolation) {
            copy.fmInterpolation = Self.defaults.fmInterpolation
        }
        copy.autoFireRate = max(1, min(30, autoFireRate))
        copy.samplesPath = Self.normalizedPath(samplesPath, fallback: Self.defaultSamplesPath)
        copy.hiscorePath = Self.normalizedPath(hiscorePath, fallback: Self.defaultHiscorePath)
        copy.eepromPath = Self.normalizedPath(eepromPath, fallback: Self.defaultEEPROMPath)
        copy.hddPath = Self.normalizedPath(hddPath, fallback: Self.defaultHDDPath)
        return copy
    }

    private static func normalizedPath(_ path: String, fallback: String) -> String {
        let trimmed = path.trimmingCharacters(in: .whitespacesAndNewlines)
        let clean = trimmed.isEmpty ? fallback : trimmed
        return clean.hasSuffix("/") ? clean : "\(clean)/"
    }
}

protocol FightcadeFBNeoSettingsPersisting {
    func load() throws -> FightcadeFBNeoSettings
    func save(_ settings: FightcadeFBNeoSettings) throws
    func loadControllerMappings() throws -> String
    func configurationFileURL() throws -> URL
    func controllerDatabaseURL() throws -> URL
}

struct FightcadeFBNeoSettingsStore: FightcadeFBNeoSettingsPersisting {
    private let fileManager: FileManager
    private let configDirectory: URL?

    init(fileManager: FileManager = .default, configDirectory: URL? = nil) {
        self.fileManager = fileManager
        self.configDirectory = configDirectory
    }

    func load() throws -> FightcadeFBNeoSettings {
        let values = try loadConfigValues()
        var settings = FightcadeFBNeoSettings.defaults
        settings.stretchToWindow = boolValue(values["bVidFullStretch"]) ?? settings.stretchToWindow
        settings.scanlines = boolValue(values["bVidScanlines"]) ?? settings.scanlines
        settings.softwareGamma = boolValue(values["bDoGamma"]) ?? settings.softwareGamma
        settings.gamma = doubleValue(values["nGamma"]) ?? settings.gamma
        settings.volume = clampedVolume(from: intValue(values["nAudVolume"]) ?? settings.volume * 100)
        settings.sampleRate = intValue(values["nAudSampleRate[0]"]) ?? settings.sampleRate
        settings.dspFilter = boolValue(values["nAudDSPModule[0]"]) ?? settings.dspFilter
        settings.pcmInterpolation = intValue(values["nInterpolation"]) ?? settings.pcmInterpolation
        settings.fmInterpolation = intValue(values["nFMInterpolation"]) ?? settings.fmInterpolation
        settings.hiscores = boolValue(values["EnableHiscores"]) ?? settings.hiscores
        settings.autoFireRate = intValue(values["nAutoFireRate"]) ?? settings.autoFireRate
        settings.samplesPath = values["szAppSamplesPath"] ?? settings.samplesPath
        settings.hiscorePath = values["szAppHiscorePath"] ?? settings.hiscorePath
        settings.eepromPath = values["szAppEEPROMPath"] ?? settings.eepromPath
        settings.hddPath = values["szAppHDDPath"] ?? settings.hddPath
        settings.controllerMappings = try loadControllerMappings()
        return settings.normalized()
    }

    func save(_ settings: FightcadeFBNeoSettings) throws {
        let settings = settings.normalized()
        let values: [String: String] = [
            "nVidSelect": "0",
            "bVidFullStretch": boolString(settings.stretchToWindow),
            "bVidScanlines": boolString(settings.scanlines),
            "bDoGamma": boolString(settings.softwareGamma),
            "nGamma": String(format: "%.6f", settings.gamma),
            "nAudVolume": "\(max(0, min(100, settings.volume)) * 100)",
            "nAudSampleRate[0]": "\(settings.sampleRate)",
            "nAudDSPModule[0]": boolString(settings.dspFilter),
            "nInterpolation": "\(settings.pcmInterpolation)",
            "nFMInterpolation": "\(settings.fmInterpolation)",
            "EnableHiscores": boolString(settings.hiscores),
            "nAutoFireRate": "\(settings.autoFireRate)",
            "szAppSamplesPath": settings.samplesPath,
            "szAppHiscorePath": settings.hiscorePath,
            "szAppEEPROMPath": settings.eepromPath,
            "szAppHDDPath": settings.hddPath
        ]
        let configURL = try configURL()
        var lines = (try? String(contentsOf: configURL, encoding: .utf8))?
            .split(separator: "\n", omittingEmptySubsequences: false)
            .map(String.init) ?? defaultConfigLines
        var seen = Set<String>()

        lines = lines.map { line in
            guard let key = key(in: line), let value = values[key] else {
                return line
            }

            seen.insert(key)
            return "\(key) \(value)"
        }

        for key in values.keys.sorted() where !seen.contains(key) {
            lines.append("\(key) \(values[key] ?? "")")
        }

        try fileManager.createDirectory(at: configURL.deletingLastPathComponent(), withIntermediateDirectories: true)
        try lines.joined(separator: "\n").write(to: configURL, atomically: true, encoding: .utf8)
        try saveControllerMappings(settings.controllerMappings)
    }

    func loadControllerMappings() throws -> String {
        let url = try controllerDatabaseURL()
        return (try? String(contentsOf: url, encoding: .utf8)) ?? ""
    }

    func configurationFileURL() throws -> URL {
        try configURL()
    }

    func controllerDatabaseURL() throws -> URL {
        try configURL().deletingLastPathComponent().appendingPathComponent("gamecontrollerdb.txt")
    }

    private func saveControllerMappings(_ mappings: String) throws {
        let cleaned = mappings
            .split(separator: "\n", omittingEmptySubsequences: false)
            .map { String($0).trimmingCharacters(in: .whitespacesAndNewlines) }
            .filter { !$0.isEmpty }
            .joined(separator: "\n")
        let url = try controllerDatabaseURL()
        try fileManager.createDirectory(at: url.deletingLastPathComponent(), withIntermediateDirectories: true)
        try cleaned.write(to: url, atomically: true, encoding: .utf8)
    }

    private func loadConfigValues() throws -> [String: String] {
        let configURL = try configURL()
        guard let contents = try? String(contentsOf: configURL, encoding: .utf8) else {
            return [:]
        }

        var values: [String: String] = [:]
        for line in contents.split(separator: "\n", omittingEmptySubsequences: false).map(String.init) {
            guard let key = key(in: line) else { continue }
            values[key] = value(in: line)
        }
        return values
    }

    private func configURL() throws -> URL {
        if let configDirectory {
            return configDirectory.appendingPathComponent("fbneo.ini")
        }

        guard let applicationSupport = fileManager.urls(for: .applicationSupportDirectory, in: .userDomainMask).first else {
            throw FightcadeLaunchError.couldNotLaunch("fbneo")
        }

        return applicationSupport.appendingPathComponent("fbneo/config/fbneo.ini")
    }

    private func key(in line: String) -> String? {
        let trimmed = line.trimmingCharacters(in: .whitespaces)
        guard !trimmed.isEmpty, !trimmed.hasPrefix("//") else {
            return nil
        }
        return trimmed.split(separator: " ", maxSplits: 1).first.map(String.init)
    }

    private func value(in line: String) -> String {
        let trimmed = line.trimmingCharacters(in: .whitespaces)
        guard let space = trimmed.firstIndex(where: { $0 == " " || $0 == "\t" }) else {
            return ""
        }
        return String(trimmed[space...]).trimmingCharacters(in: .whitespaces)
    }

    private func intValue(_ value: String?) -> Int? {
        guard let value else { return nil }
        let normalized = value.lowercased()
        if normalized.hasPrefix("0x") {
            return Int(normalized.dropFirst(2), radix: 16)
        }
        return Int(value)
    }

    private func doubleValue(_ value: String?) -> Double? {
        value.flatMap(Double.init)
    }

    private func boolValue(_ value: String?) -> Bool? {
        intValue(value).map { $0 != 0 }
    }

    private func boolString(_ value: Bool) -> String {
        value ? "1" : "0"
    }

    private func clampedVolume(from rawValue: Int) -> Int {
        max(0, min(100, rawValue / 100))
    }

    private var defaultConfigLines: [String] {
        FightcadeFBNeoConfig().defaultConfigLines
    }
}
