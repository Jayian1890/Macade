import Foundation

final class FightcadeProxyDiagnostics: @unchecked Sendable {
    private let lock = NSLock()
    private let fileHandle: FileHandle
    private var closed = false

    init(fileHandle: FileHandle) {
        self.fileHandle = fileHandle
    }

    static func make(match: FightcadeMatchLaunch, fileManager: FileManager = .default) -> FightcadeProxyDiagnostics? {
        guard let logsURL = fileManager.urls(for: .libraryDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Logs")
            .appendingPathComponent("Macade") else {
            return nil
        }

        do {
            try fileManager.createDirectory(at: logsURL, withIntermediateDirectories: true)
            let latestURL = logsURL.appendingPathComponent("fightcade-netplay-proxy-latest.log")
            if fileManager.fileExists(atPath: latestURL.path) {
                try fileManager.removeItem(at: latestURL)
            }
            fileManager.createFile(atPath: latestURL.path, contents: nil)
            let handle = try FileHandle(forWritingTo: latestURL)
            let diagnostics = FightcadeProxyDiagnostics(fileHandle: handle)
            diagnostics.write("=== Fightcade Netplay Proxy ===")
            diagnostics.write("timestamp=\(Self.timestamp())")
            diagnostics.write("game=\(match.gameID) quark=\(match.quarkID).\(match.playerID) port=\(match.port) delay=\(match.delay) ranked=\(match.ranked)")
            return diagnostics
        } catch {
            return nil
        }
    }

    func write(_ message: String) {
        lock.withLock {
            guard !closed else { return }
            let line = "\(Self.timestamp()) \(message)\n"
            guard let data = line.data(using: .utf8) else { return }
            do {
                try fileHandle.seekToEnd()
                try fileHandle.write(contentsOf: data)
                try fileHandle.synchronize()
            } catch {
                closed = true
            }
        }
    }

    func close() {
        lock.withLock {
            guard !closed else { return }
            try? fileHandle.synchronize()
            try? fileHandle.close()
            closed = true
        }
    }

    private static func timestamp() -> String {
        ISO8601DateFormatter().string(from: Date())
    }
}
