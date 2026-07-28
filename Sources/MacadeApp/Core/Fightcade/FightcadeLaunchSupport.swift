import Darwin
import Foundation

struct FightcadeLaunchDiagnostics {
    private let fileManager: FileManager

    init(fileManager: FileManager) {
        self.fileManager = fileManager
    }

    func header(
        emulator: String,
        arguments: [String],
        runtime: URL,
        executable: URL,
        romDirectory: URL,
        configURL: URL?,
        expectedROM: URL?,
        environment: [String: String]
    ) -> String {
        let emulatorDirectory = executable.deletingLastPathComponent()
        let libraryDirectory = emulatorDirectory.appendingPathComponent("lib")
        let command = ([executable.path] + arguments).map(shellQuoted).joined(separator: " ")
        let dylibs = [
            "libSDL-1.2.0.dylib",
            "libSDL2-2.0.0.dylib",
            "libSDL3.dylib"
        ].map { fileDescription(libraryDirectory.appendingPathComponent($0)) }.joined(separator: "\n")

        var lines = [
            "=== Macade Emulator Launch ===",
            "timestamp: \(Self.timestamp())",
            "bundle: \(Bundle.main.bundleIdentifier ?? "unknown")",
            "macOS: \(ProcessInfo.processInfo.operatingSystemVersionString)",
            "host: \(ProcessInfo.processInfo.hostName)",
            "macade pid: \(ProcessInfo.processInfo.processIdentifier)",
            "emulator: \(emulator)",
            "command: \(command)",
            "runtime: \(runtime.path)",
            "working directory: \(runtime.path)",
            "executable: \(fileDescription(executable))",
            "emulator directory: \(fileDescription(emulatorDirectory))",
            "library directory: \(fileDescription(libraryDirectory))",
            "SDL dylibs:",
            dylibs,
            "ROM directory: \(fileDescription(romDirectory))"
        ]

        if let configURL {
            lines.append("emulator config: \(fileDescription(configURL))")
            lines.append("emulator config ROM paths:")
            lines.append(contentsOf: configROMPathLines(configURL).map { "  \($0)" })
        }

        if let expectedROM {
            lines.append("expected ROM: \(fileDescription(expectedROM))")
        }

        lines.append("ROM directory entries:")
        lines.append(contentsOf: directoryListing(romDirectory, limit: 80).map { "  \($0)" })
        lines.append("emulator directory entries:")
        lines.append(contentsOf: directoryListing(emulatorDirectory, limit: 80).map { "  \($0)" })
        lines.append("selected environment:")
        lines.append(contentsOf: filteredEnvironment(environment).map { "  \($0.key)=\($0.value)" })
        lines.append("=== Child Process Output ===")
        return lines.joined(separator: "\n") + "\n"
    }

    nonisolated static func footer(process: Process) -> String {
        """

        === Emulator Terminated ===
        timestamp: \(timestamp())
        pid: \(process.processIdentifier)
        termination reason: \(terminationReason(process.terminationReason))
        termination status: \(process.terminationStatus)
        === End Macade Emulator Log ===
        """
    }

    private func fileDescription(_ url: URL) -> String {
        guard let attributes = try? fileManager.attributesOfItem(atPath: url.path) else {
            return "missing path=\(url.path)"
        }

        let type = (attributes[.type] as? FileAttributeType)?.rawValue ?? "unknown"
        let size = (attributes[.size] as? NSNumber)?.int64Value ?? 0
        let permissions = (attributes[.posixPermissions] as? NSNumber).map { String(format: "%03o", $0.intValue) } ?? "unknown"
        let modified = (attributes[.modificationDate] as? Date).map { Self.timestamp($0) } ?? "unknown"
        let executable = fileManager.isExecutableFile(atPath: url.path)
        return "path=\(url.path) type=\(type) size=\(size) permissions=\(permissions) executable=\(executable) modified=\(modified)"
    }

    private func directoryListing(_ url: URL, limit: Int) -> [String] {
        guard let contents = try? fileManager.contentsOfDirectory(
            at: url,
            includingPropertiesForKeys: [.isDirectoryKey, .fileSizeKey],
            options: [.skipsHiddenFiles]
        ) else {
            return ["<unable to read>"]
        }

        let entries = contents.sorted { $0.lastPathComponent.localizedStandardCompare($1.lastPathComponent) == .orderedAscending }
        var lines = entries.prefix(limit).map { entry -> String in
            let values = try? entry.resourceValues(forKeys: [.isDirectoryKey, .fileSizeKey])
            let suffix = values?.isDirectory == true ? "/" : ""
            let size = values?.fileSize.map(String.init) ?? "unknown"
            return "\(entry.lastPathComponent)\(suffix) size=\(size)"
        }

        if entries.count > limit {
            lines.append("... \(entries.count - limit) more entries")
        }

        return lines.isEmpty ? ["<empty>"] : lines
    }

    private func configROMPathLines(_ url: URL) -> [String] {
        guard let text = try? String(contentsOf: url, encoding: .utf8) else {
            return ["<unable to read>"]
        }

        let lines = text.split(separator: "\n", omittingEmptySubsequences: false)
            .map(String.init)
            .filter { $0.hasPrefix("szAppRomPaths[") }
        return lines.isEmpty ? ["<none>"] : lines
    }

    private func filteredEnvironment(_ environment: [String: String]) -> [(key: String, value: String)] {
        let exactKeys: Set<String> = [
            "DYLD_PRINT_LIBRARIES",
            "DYLD_PRINT_RPATHS",
            "FBNEO_ROM_DIR",
            "HOME",
            "MACADE_EMBEDDED_HIDE_WINDOW",
            "MACADE_EMBEDDED_INPUT_SOCKET",
            "MACADE_EMBEDDED_SESSION_ID",
            "MACADE_EMBEDDED_VIDEO_BYTES",
            "MACADE_EMBEDDED_VIDEO_PATH",
            "MACADE_FIGHTCADE_RUNTIME",
            "MACADE_ROM_DIR",
            "PATH",
            "ROMPATH",
            "SHELL",
            "USER",
            "__CFBundleIdentifier"
        ]
        let prefixes = ["SDL_", "SDL2_", "SDL3_"]

        return environment
            .filter { key, _ in exactKeys.contains(key) || prefixes.contains { key.hasPrefix($0) } }
            .map { ($0.key, $0.value) }
            .sorted { $0.key < $1.key }
    }

    private func shellQuoted(_ value: String) -> String {
        "'\(value.replacingOccurrences(of: "'", with: "'\\''"))'"
    }

    nonisolated private static func terminationReason(_ reason: Process.TerminationReason) -> String {
        switch reason {
        case .exit:
            "exit"
        case .uncaughtSignal:
            "uncaughtSignal"
        @unknown default:
            "unknown"
        }
    }

    nonisolated private static func timestamp() -> String {
        timestamp(Date())
    }

    nonisolated private static func timestamp(_ date: Date) -> String {
        ISO8601DateFormatter().string(from: date)
    }
}

final class FightcadeProcessRegistry: @unchecked Sendable {
    static let shared = FightcadeProcessRegistry()

    private let lock = NSLock()
    private var launchedProcesses: [Int32: Entry] = [:]
    private var isTerminating = false

    private struct Entry {
        let process: Process
        let log: FightcadeLaunchLog?
        let label: String
    }

    func insert(_ process: Process, log: FightcadeLaunchLog? = nil, label: String? = nil) {
        var shouldTerminateImmediately = false
        lock.withLock {
            if isTerminating {
                shouldTerminateImmediately = true
                return
            }

            launchedProcesses[process.processIdentifier] = Entry(
                process: process,
                log: log,
                label: label ?? process.executableURL?.lastPathComponent ?? "process"
            )
        }

        if shouldTerminateImmediately, process.isRunning {
            log?.write("Macade process gate rejected late launch pid=\(process.processIdentifier) reason=termination in progress\n")
            process.terminate()
        }
    }

    func remove(processID: Int32) {
        _ = lock.withLock {
            launchedProcesses.removeValue(forKey: processID)
        }
    }

    func terminateAll(
        reason: String,
        graceSeconds: TimeInterval = 1.5,
        rejectFutureLaunches: Bool = false
    ) {
        let entries = lock.withLock {
            if rejectFutureLaunches {
                isTerminating = true
            }
            return Array(launchedProcesses.values)
        }
        guard !entries.isEmpty else {
            return
        }

        for entry in entries where entry.process.isRunning {
            entry.log?.write("Macade process gate terminating pid=\(entry.process.processIdentifier) label=\(entry.label) reason=\(reason)\n")
            entry.process.terminate()
        }

        waitForExit(entries, graceSeconds: graceSeconds)

        for entry in entries where entry.process.isRunning {
            let processID = entry.process.processIdentifier
            entry.log?.write("Macade process gate force killing pid=\(processID) label=\(entry.label) reason=\(reason)\n")
            Darwin.kill(processID, SIGKILL)
        }

        waitForExit(entries, graceSeconds: 0.25)

        lock.withLock {
            launchedProcesses = launchedProcesses.filter { _, entry in entry.process.isRunning }
        }
    }

    private func waitForExit(_ entries: [Entry], graceSeconds: TimeInterval) {
        guard graceSeconds > 0 else {
            return
        }

        let deadline = Date().addingTimeInterval(graceSeconds)
        while Date() < deadline {
            if entries.allSatisfy({ !$0.process.isRunning }) {
                return
            }
            Thread.sleep(forTimeInterval: 0.05)
        }
    }
}

final class FightcadeLaunchLog: @unchecked Sendable {
    let url: URL
    let fileHandle: FileHandle

    private let lock = NSLock()
    private var closed = false

    init(url: URL, fileHandle: FileHandle) {
        self.url = url
        self.fileHandle = fileHandle
    }

    func write(_ message: String) {
        guard let data = message.data(using: .utf8) else {
            return
        }

        lock.withLock {
            guard !closed else {
                return
            }

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
            guard !closed else {
                return
            }

            try? fileHandle.synchronize()
            try? fileHandle.close()
            closed = true
        }
    }
}

struct FightcadeNetplayLaunchDiagnostics {
    private let fileManager: FileManager

    init(fileManager: FileManager) {
        self.fileManager = fileManager
    }

    func writeUnsupportedAttempt(match: FightcadeMatchLaunch, runtime: URL, reason: String) {
        guard let log = makeLog() else {
            return
        }

        let plan = FightcadeQuarkSessionPlan(match: match)
        let proxyConfiguration = FightcadeUDPProxyConfiguration(
            peer: FightcadeNetplayEndpoint(host: "<pending master handshake>", port: 0),
            localEmulatorPort: plan.emulatorProxyPort
        )
        defer { log.close() }
        log.write(
            """
            === Macade FBNeo Netplay Launch Attempt ===
            timestamp: \(Self.timestamp())
            result: unsupported
            reason: \(reason)
            emulator: \(match.emulator)
            gameID: \(match.gameID)
            quarkID: \(match.quarkID)
            playerID: \(match.playerID)
            port: \(match.port)
            delay: \(match.delay)
            ranked: \(match.ranked)
            token: \(match.token?.isEmpty == false ? "<redacted>" : "<none>")
            quark command: \(match.quarkCommand)
            master host: \(plan.master.host)
            master port: \(plan.master.port)
            master registration payload: \(plan.registrationPayload)
            master expected ok: \(plan.expectedOKPayload)
            master ack payload: \(plan.acknowledgePayload)
            master useports diagnostic payload: \(plan.usePortsPayload)
            local UDP bind port: \(plan.localBindPort)
            local emulator proxy port: \(plan.emulatorProxyPort)
            proxy initial emulator endpoint: \(proxyConfiguration.initialEmulatorEndpoint.host):\(proxyConfiguration.initialEmulatorEndpoint.port)
            proxy max packet bytes: \(proxyConfiguration.maximumPacketBytes)
            proxy filters: hole-punch token packets containing " ok" or " _"
            normal NAT fallback scan radius: 512
            restricted NAT fallback port: \(plan.restrictedNATFallbackPort)
            fixed fallback port: \(plan.fixedFallbackPort)
            runtime: \(runtime.path)
            manifest: \(runtime.appendingPathComponent("manifest.json").path)
            supportsQuark required: true
            native FBNeo netplay mode: UDP type 3 input required; useports continues with open-port UDP mode, not TCP frame relay.
            === End Macade FBNeo Netplay Launch Attempt ===
            """
        )
    }

    private func makeLog() -> FightcadeLaunchLog? {
        guard let logsURL = fileManager.urls(for: .libraryDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Logs")
            .appendingPathComponent("Macade") else {
            return nil
        }

        do {
            try fileManager.createDirectory(at: logsURL, withIntermediateDirectories: true)
            let logURL = logsURL.appendingPathComponent("fbneo-netplay-latest.log")
            if fileManager.fileExists(atPath: logURL.path) {
                try fileManager.removeItem(at: logURL)
            }
            fileManager.createFile(atPath: logURL.path, contents: nil)
            return try FightcadeLaunchLog(url: logURL, fileHandle: FileHandle(forWritingTo: logURL))
        } catch {
            return nil
        }
    }

    private static func timestamp() -> String {
        ISO8601DateFormatter().string(from: Date())
    }
}
