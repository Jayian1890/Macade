import Foundation
import Darwin
import AppKit

@MainActor
protocol FightcadeLaunching: Sendable {
    func canLaunchLocalGame(emulator: String) -> Bool
    func hasLocalROM(emulator: String, gameID: String) -> Bool
    func open(_ route: FightcadeLaunchRoute) async throws
    func openEmbedded(_ launch: FightcadeEmbeddedLaunch) async throws -> FightcadeEmbeddedSession
}

struct FightcadeLauncher: FightcadeLaunching {
    private let runtime: FightcadeRuntime
    private let fileManager: FileManager
    private let processRegistry: FightcadeProcessRegistry

    init(
        runtime: FightcadeRuntime = FightcadeRuntime(),
        fileManager: FileManager = .default,
        processRegistry: FightcadeProcessRegistry = .shared
    ) {
        self.runtime = runtime
        self.fileManager = fileManager
        self.processRegistry = processRegistry
    }

    func canLaunchLocalGame(emulator: String) -> Bool {
        guard let runtimeRoot = try? runtime.root(),
              (try? emulatorExecutable(emulator: emulator, runtime: runtimeRoot)) != nil else {
            return false
        }

        return true
    }

    func hasLocalROM(emulator: String, gameID: String) -> Bool {
        (try? runtime.existingROMURL(emulator: emulator, gameID: gameID)) != nil
    }

    func open(_ route: FightcadeLaunchRoute) async throws {
        let runtimeRoot = try runtime.root()
        let manifest = runtimeManifest(in: runtimeRoot)

        switch route {
        case .checkROM(let emulator, let gameID):
            try ensureROMExists(emulator: emulator, gameID: gameID)

        case .play(let emulator, let gameID):
            let romURL = try ensureROMExists(emulator: emulator, gameID: gameID)
            try launch(emulator: emulator, arguments: [gameID], runtime: runtimeRoot, expectedROM: romURL)

        case .training(let emulator, let gameID):
            let romURL = try ensureROMExists(emulator: emulator, gameID: gameID)
            try launch(emulator: emulator, arguments: [FightcadeLocalTrainingLaunch(emulator: emulator, gameID: gameID).command], runtime: runtimeRoot, expectedROM: romURL)

        case .fightcadeTraining(let training):
            guard manifest.supportsQuark(emulator: training.emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(training.emulator) training. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }

            try launch(
                emulator: training.emulator,
                arguments: [training.quarkCommand],
                runtime: runtimeRoot,
                expectedROM: nil
            )

        case .match(let match):
            guard manifest.supportsQuark(emulator: match.emulator) else {
                FightcadeNetplayLaunchDiagnostics(fileManager: fileManager).writeUnsupportedAttempt(
                    match: match,
                    runtime: runtimeRoot,
                    reason: "Runtime manifest does not declare native Fightcade quark/GGPO support."
                )

                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(match.emulator) netplay. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }

            try launch(
                emulator: match.emulator,
                arguments: [match.quarkCommand],
                runtime: runtimeRoot,
                expectedROM: nil
            )

        case .direct(let direct):
            guard manifest.supportsQuark(emulator: direct.emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(direct.emulator) direct play. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }

            try launch(
                emulator: direct.emulator,
                arguments: [direct.quarkCommand],
                runtime: runtimeRoot,
                expectedROM: nil
            )

        case .spectate(let emulator, let gameID, let quarkID, let port):
            guard manifest.supportsQuark(emulator: emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(emulator) spectating. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }

            try launch(
                emulator: emulator,
                arguments: [FightcadeSpectateLaunch(emulator: emulator, gameID: gameID, quarkID: quarkID, port: port).quarkCommand],
                runtime: runtimeRoot,
                expectedROM: nil
            )

        case .endMatch:
            throw FightcadeLaunchError.unsupportedNativeRoute("force-ending emulator processes")
        }
    }

    func openEmbedded(_ launch: FightcadeEmbeddedLaunch) async throws -> FightcadeEmbeddedSession {
        let runtimeRoot = try runtime.root()
        let manifest = runtimeManifest(in: runtimeRoot)
        if launch.requiresQuark {
            guard manifest.supportsQuark(emulator: launch.emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "embedded native \(launch.emulator) \(launch.mode.rawValue.lowercased()). The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }
        } else if !manifest.supportsEmbedded(emulator: launch.emulator) {
            throw FightcadeLaunchError.unsupportedNativeRoute(
                "embedded native \(launch.emulator) local launch. The runtime emulator must implement Macade embedded video/input support."
            )
        }
        let expectedROM: URL? = switch launch.mode {
        case .test, .training:
            try ensureROMExists(emulator: launch.emulator, gameID: launch.gameID)
        case .direct, .match, .spectate:
            nil
        }

        let resources = try makeEmbeddedResources(emulator: launch.emulator)
        let session = FightcadeEmbeddedSession(
            id: resources.id,
            channelID: launch.channelID,
            mode: launch.mode,
            emulator: launch.emulator,
            gameID: launch.gameID,
            title: launch.title,
            logURL: resources.logURL,
            videoStream: resources.videoStream,
            inputClient: resources.inputClient
        )

        var embeddedEnvironment = [
            "MACADE_EMBEDDED_SESSION_ID": resources.id.uuidString,
            "MACADE_EMBEDDED_VIDEO_PATH": resources.videoStream.fileURL.path,
            "MACADE_EMBEDDED_VIDEO_BYTES": String(resources.videoStream.byteCount),
            "MACADE_EMBEDDED_INPUT_SOCKET": resources.inputClient.socketPath,
            "MACADE_EMBEDDED_HIDE_WINDOW": "1",
            "SDL_MAC_BACKGROUND_APP": "1"
        ]
        if launch.mode == .match {
            embeddedEnvironment["quark.log"] = "1"
            embeddedEnvironment["quark.log.timestamps"] = "1"
            embeddedEnvironment["MACADE_QUARK_LOG_DIR"] = resources.launchLog.url.deletingLastPathComponent().path
        }

        do {
            let process = try launchProcess(
                emulator: launch.emulator,
                arguments: launch.arguments,
                runtime: runtimeRoot,
                expectedROM: expectedROM,
                launchLog: resources.launchLog,
                additionalEnvironment: embeddedEnvironment,
                embeddedSession: session
            )
            session.attach(process: process)
            NSApp.activate(ignoringOtherApps: true)
            return session
        } catch {
            session.markFailed(error.localizedDescription)
            throw error
        }
    }

    private func runtimeManifest(in runtime: URL) -> FightcadeRuntimeManifest {
        let manifestURL = runtime.appendingPathComponent("manifest.json")
        guard let data = try? Data(contentsOf: manifestURL),
              let manifest = try? JSONDecoder().decode(FightcadeRuntimeManifest.self, from: data) else {
            return .empty
        }

        return manifest
    }

    @discardableResult
    private func ensureROMExists(emulator: String, gameID: String) throws -> URL {
        guard let romURL = try runtime.existingROMURL(emulator: emulator, gameID: gameID) else {
            let candidates = try runtime.romCandidateURLs(emulator: emulator, gameID: gameID).map(\.path)
            throw FightcadeLaunchError.missingROM(gameID: gameID, emulator: emulator, searchedPaths: candidates)
        }

        return romURL
    }

    private func launch(emulator: String, arguments: [String], runtime: URL, expectedROM: URL?) throws {
        let launchLog = try makeLaunchLog(emulator: emulator)
        _ = try launchProcess(
            emulator: emulator,
            arguments: arguments,
            runtime: runtime,
            expectedROM: expectedROM,
            launchLog: launchLog,
            additionalEnvironment: [:],
            embeddedSession: nil
        )
    }

    @discardableResult
    private func launchProcess(
        emulator: String,
        arguments: [String],
        runtime: URL,
        expectedROM: URL?,
        launchLog: FightcadeLaunchLog,
        additionalEnvironment: [String: String],
        embeddedSession: FightcadeEmbeddedSession?
    ) throws -> Process {
        let executable = try emulatorExecutable(emulator: emulator, runtime: runtime)
        let romDirectory = try self.runtime.romDirectory(emulator: emulator)
        let configURL = try configureEmulator(emulator: emulator, runtime: runtime, romDirectory: romDirectory)
        let process = Process()
        process.executableURL = executable
        process.arguments = arguments
        process.currentDirectoryURL = runtime
        process.standardOutput = launchLog.fileHandle
        process.standardError = launchLog.fileHandle
        var baseEnvironment = ProcessInfo.processInfo.environment
        baseEnvironment.removeValue(forKey: "__CFBundleIdentifier")
        let environment = baseEnvironment.merging([
            "MACADE_FIGHTCADE_RUNTIME": runtime.path,
            "MACADE_ROM_DIR": romDirectory.path,
            "FBNEO_ROM_DIR": romDirectory.path,
            "ROMPATH": romDirectory.path,
            "SDL_MAC_BACKGROUND_APP": "0",
            "SDL_RENDER_DRIVER": "software",
            "SDL_VIDEODRIVER": "cocoa"
        ]) { _, new in new }
        .merging(additionalEnvironment) { _, new in new }
        .merging(controllerEnvironment(emulator: emulator)) { _, new in new }
        process.environment = environment
        launchLog.write(FightcadeLaunchDiagnostics(fileManager: fileManager).header(
            emulator: emulator,
            arguments: arguments,
            runtime: runtime,
            executable: executable,
            romDirectory: romDirectory,
            configURL: configURL,
            expectedROM: expectedROM,
            environment: environment
        ))

        let registry = processRegistry
        process.terminationHandler = { process in
            launchLog.write(FightcadeLaunchDiagnostics.footer(process: process))
            launchLog.close()
            registry.remove(processID: process.processIdentifier)
            if let embeddedSession {
                let status = process.terminationStatus
                Task { @MainActor in
                    embeddedSession.markTerminated(status: status)
                }
            }
        }

        do {
            enforceSingleFBNeoProcess(executable: executable, launchLog: launchLog, keepManagedProcesses: embeddedSession?.mode == .match || embeddedSession?.mode == .direct)
            try process.run()
            processRegistry.insert(process, log: launchLog)
            launchLog.write("Process started: pid=\(process.processIdentifier)\n")
            if !process.isRunning {
                processRegistry.remove(processID: process.processIdentifier)
            }
            return process
        } catch {
            launchLog.write("Launch failed before process start: \(error.localizedDescription)\n")
            launchLog.close()
            throw FightcadeLaunchError.couldNotLaunch(executable.path)
        }
    }

    private func configureEmulator(emulator: String, runtime: URL, romDirectory: URL) throws -> URL? {
        switch emulator.lowercased() {
        case "fbneo":
            try FightcadeFBNeoConfig(fileManager: fileManager).writeROMPaths(runtime: runtime, romDirectory: romDirectory)
        default:
            nil
        }
    }

    private func makeLaunchLog(emulator: String) throws -> FightcadeLaunchLog {
        guard let logsURL = fileManager.urls(for: .libraryDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Logs")
            .appendingPathComponent("Macade") else {
            throw FightcadeLaunchError.couldNotLaunch(emulator)
        }

        try fileManager.createDirectory(at: logsURL, withIntermediateDirectories: true)
        let logURL = logsURL.appendingPathComponent("\(emulator)-\(Self.logTimestamp()).log")
        let latestURL = logsURL.appendingPathComponent("\(emulator)-latest.log")
        fileManager.createFile(atPath: logURL.path, contents: nil)
        try? fileManager.removeItem(at: latestURL)
        try? fileManager.createSymbolicLink(at: latestURL, withDestinationURL: logURL)
        return try FightcadeLaunchLog(url: logURL, fileHandle: FileHandle(forWritingTo: logURL))
    }

    private static func logTimestamp() -> String {
        let formatter = DateFormatter()
        formatter.locale = Locale(identifier: "en_US_POSIX")
        formatter.timeZone = TimeZone(secondsFromGMT: 0)
        formatter.dateFormat = "yyyyMMdd-HHmmss"
        return formatter.string(from: Date())
    }

    private func makeEmbeddedResources(emulator: String) throws -> FightcadeEmbeddedResources {
        guard let applicationSupport = fileManager.urls(for: .applicationSupportDirectory, in: .userDomainMask).first else {
            throw FightcadeLaunchError.embeddedBridgeFailed("Could not locate Application Support.")
        }

        let id = UUID()
        let directory = applicationSupport
            .appendingPathComponent("Macade")
            .appendingPathComponent("EmbeddedEmulator")
            .appendingPathComponent(id.uuidString)
        try fileManager.createDirectory(at: directory, withIntermediateDirectories: true)

        let inputSocketURL = URL(fileURLWithPath: "/tmp")
            .appendingPathComponent("macade-\(id.uuidString)-input.sock")
        try? fileManager.removeItem(at: inputSocketURL)

        let videoStream = try FightcadeEmbeddedVideoStream(fileURL: directory.appendingPathComponent("video.mcade"))
        let inputClient = try FightcadeEmbeddedInputClient(socketPath: inputSocketURL.path)
        let launchLog = try makeLaunchLog(emulator: "\(emulator)-embedded")
        return FightcadeEmbeddedResources(
            id: id,
            videoStream: videoStream,
            inputClient: inputClient,
            launchLog: launchLog,
            logURL: launchLog.url
        )
    }

    private func controllerEnvironment(emulator: String) -> [String: String] {
        guard emulator.lowercased() == "fbneo",
              let mappings = try? FightcadeFBNeoSettingsStore(fileManager: fileManager).loadControllerMappings(),
              !mappings.isEmpty else {
            return [:]
        }

        return ["SDL_GAMECONTROLLERCONFIG": mappings]
    }

    private func emulatorExecutable(emulator: String, runtime: URL) throws -> URL {
        let normalized = emulator.lowercased()
        let relativePaths: [String]

        switch normalized {
        case "fbneo":
            relativePaths = [
                "emulators/fbneo/macfbneo",
                "emulators/fbneo/fbneo",
                "emulator/fbneo/macfbneo",
                "emulator/fbneo/fbneo"
            ]
        default:
            relativePaths = [
                "emulators/\(normalized)/\(normalized)",
                "emulator/\(normalized)/\(normalized)"
            ]
        }

        let candidates = relativePaths.map { runtime.appendingPathComponent($0) }

        guard let executable = candidates.first(where: executableExists) else {
            throw FightcadeLaunchError.missingEmulator(emulator: emulator, searchedPaths: candidates.map(\.path))
        }

        return executable
    }

    private func enforceSingleFBNeoProcess(executable: URL, launchLog: FightcadeLaunchLog, keepManagedProcesses: Bool) {
        guard executable.lastPathComponent == "macfbneo" else { return }
        if !keepManagedProcesses {
            processRegistry.terminateAll(reason: "single macfbneo launch", graceSeconds: 0.75)
        }

        let managedProcessIDs = keepManagedProcesses ? processRegistry.processIDs() : []
        let processIDs = ["macfbneo", "fcadefbneo"].flatMap(runningProcessIDs(named:)).filter { !managedProcessIDs.contains($0) }
        guard !processIDs.isEmpty else { return }

        for processID in processIDs {
            launchLog.write("Macade process gate terminating existing FBNeo runtime pid=\(processID) before launch\n")
            kill(processID, SIGTERM)
        }

        waitForExit(processIDs, graceSeconds: 0.75)

        for processID in processIDs where kill(processID, 0) == 0 {
            launchLog.write("Macade process gate force killing existing FBNeo runtime pid=\(processID) before launch\n")
            kill(processID, SIGKILL)
        }

        waitForExit(processIDs, graceSeconds: 0.25)
    }

    private func runningProcessIDs(named name: String) -> [pid_t] {
        let process = Process()
        let output = Pipe()
        process.executableURL = URL(fileURLWithPath: "/usr/bin/pgrep")
        process.arguments = ["-x", name]
        process.standardOutput = output
        process.standardError = Pipe()

        do {
            try process.run()
            process.waitUntilExit()
        } catch {
            return []
        }

        let data = output.fileHandleForReading.readDataToEndOfFile()
        guard let text = String(data: data, encoding: .utf8) else { return [] }
        return text.split(whereSeparator: \.isNewline).compactMap { pid_t(String($0)) }
    }

    private func waitForExit(_ processIDs: [pid_t], graceSeconds: TimeInterval) {
        let deadline = Date().addingTimeInterval(graceSeconds)
        while Date() < deadline {
            if processIDs.allSatisfy({ kill($0, 0) != 0 }) { return }
            Thread.sleep(forTimeInterval: 0.05)
        }
    }

    private func executableExists(_ url: URL) -> Bool {
        fileManager.fileExists(atPath: url.path) && fileManager.isExecutableFile(atPath: url.path)
    }
}

private struct FightcadeEmbeddedResources {
    let id: UUID
    let videoStream: FightcadeEmbeddedVideoStream
    let inputClient: FightcadeEmbeddedInputClient
    let launchLog: FightcadeLaunchLog
    let logURL: URL
}

enum FightcadeLaunchError: LocalizedError, Equatable {
    case missingGame
    case missingRuntime([String])
    case missingEmulator(emulator: String, searchedPaths: [String])
    case missingROM(gameID: String, emulator: String, searchedPaths: [String])
    case unsupportedNativeRoute(String)
    case embeddedBridgeFailed(String)
    case couldNotLaunch(String)

    var errorDescription: String? {
        switch self {
        case .missingGame:
            "This channel is missing Fightcade launch metadata."
        case .missingRuntime(let paths):
            "Missing Macade Fightcade runtime. Expected FightcadeRuntime at: \(paths.joined(separator: ", "))"
        case .missingEmulator(let emulator, _):
            "Native \(emulator) runtime is not bundled. Restore the bundled FightcadeRuntime resources."
        case .missingROM(let gameID, let emulator, let searchedPaths):
            "Missing ROM for \(gameID) on \(emulator). Searched: \(searchedPaths.joined(separator: ", "))"
        case .unsupportedNativeRoute(let route):
            "Native launcher does not implement \(route) yet."
        case .embeddedBridgeFailed(let message):
            message
        case .couldNotLaunch(let path):
            "Could not launch emulator executable at \(path)."
        }
    }
}
