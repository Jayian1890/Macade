import Foundation

struct FightcadeFBNeoConfig {
    private let fileManager: FileManager

    init(fileManager: FileManager = .default) {
        self.fileManager = fileManager
    }

    func writeROMPaths(runtime: URL, romDirectory: URL) throws -> URL {
        let configURL = try configURL()
        let current = (try? String(contentsOf: configURL, encoding: .utf8)) ?? defaultConfig
        let desiredPaths = romPaths(runtime: runtime, romDirectory: romDirectory)
        var sawVideoSelection = false
        var seen = Set<Int>()
        var lines = current.split(separator: "\n", omittingEmptySubsequences: false).map(String.init)

        lines = lines.map { line in
            if line.hasPrefix("nVidSelect ") {
                sawVideoSelection = true
                return "nVidSelect 0"
            }

            guard let index = romPathIndex(in: line) else {
                return line
            }

            seen.insert(index)
            return "szAppRomPaths[\(index)] \(desiredPaths[index])"
        }

        if !sawVideoSelection {
            lines.insert("nVidSelect 0", at: 0)
        }

        if seen.count < 20 {
            lines.append("")
            lines.append("// Macade-managed FBNeo ROM search paths. (include trailing slash)")
            for index in 0..<20 where !seen.contains(index) {
                lines.append("szAppRomPaths[\(index)] \(desiredPaths[index])")
            }
        }

        try fileManager.createDirectory(at: configURL.deletingLastPathComponent(), withIntermediateDirectories: true)
        try lines.joined(separator: "\n").write(to: configURL, atomically: true, encoding: .utf8)
        return configURL
    }

    private func configURL() throws -> URL {
        guard let applicationSupport = fileManager.urls(for: .applicationSupportDirectory, in: .userDomainMask).first else {
            throw FightcadeLaunchError.couldNotLaunch("fbneo")
        }

        return applicationSupport
            .appendingPathComponent("fbneo")
            .appendingPathComponent("config")
            .appendingPathComponent("fbneo.ini")
    }

    private func romPaths(runtime: URL, romDirectory: URL) -> [String] {
        var paths = Array(repeating: "", count: 20)
        paths[0] = trailingSlash(romDirectory.path)
        paths[1] = trailingSlash(runtime.appendingPathComponent("roms").path)
        paths[2] = "roms/fbneo/"
        paths[3] = "roms/"
        return paths
    }

    private func trailingSlash(_ path: String) -> String {
        path.hasSuffix("/") ? path : "\(path)/"
    }

    private func romPathIndex(in line: String) -> Int? {
        guard line.hasPrefix("szAppRomPaths[") else {
            return nil
        }

        let afterPrefix = line.dropFirst("szAppRomPaths[".count)
        guard let closingBracket = afterPrefix.firstIndex(of: "]") else {
            return nil
        }

        return Int(afterPrefix[..<closingBracket]).flatMap { (0..<20).contains($0) ? $0 : nil }
    }

    private var defaultConfig: String {
        """
        // The application version this file was saved from
        nIniVersion 0x029744
        // video mode 0 = native SDL2 renderer for Macade's bundled runtime
        nVidSelect 0
        MacadeEmbeddedVideoScale 0
        bVidFullStretch 0
        nAutoFireRate 12
        bVidScanlines 0
        bDoGamma 0
        nGamma 1.250000
        nAudVolume 5000
        nAudSampleRate[0] 44100
        nAudDSPModule[0] 0
        nInterpolation 1
        nFMInterpolation 0
        EnableHiscores 0
        szAppSamplesPath support/samples/
        szAppHiscorePath support/hiscores/
        szAppEEPROMPath config/games/
        szAppHDDPath support/hdd/

        // The paths to search for rom zips. (include trailing slash)
        """
    }

    var defaultConfigLines: [String] {
        defaultConfig.split(separator: "\n", omittingEmptySubsequences: false).map(String.init)
    }
}
