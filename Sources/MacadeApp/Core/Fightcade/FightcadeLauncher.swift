import Foundation
import Darwin
import AppKit

@MainActor
protocol FightcadeLaunching: Sendable {
    func canLaunchLocalGame(emulator: String) -> Bool
    func canLaunchFightcadeRoute(_ capability: FightcadeRuntimeCapability, emulator: String) -> Bool
    func canLaunchFightcadeReplay(emulator: String) -> Bool
    func hasLocalROM(emulator: String, gameID: String) -> Bool
    func open(_ route: FightcadeLaunchRoute) async throws
    func openEmbedded(_ launch: FightcadeEmbeddedLaunch) async throws -> FightcadeEmbeddedSession
}

extension FightcadeLaunching {
    func canLaunchFightcadeReplay(emulator: String) -> Bool {
        canLaunchFightcadeRoute(.fightcadeReplay, emulator: emulator)
    }

    func canLaunchFightcadeGame(
        _ capability: FightcadeRuntimeCapability,
        emulator: String,
        gameID: String
    ) -> Bool {
        canLaunchFightcadeRoute(capability, emulator: emulator)
            && hasLocalROM(emulator: emulator, gameID: gameID)
    }
}

struct FightcadeLauncher: FightcadeLaunching {
    let runtime: FightcadeRuntime
    let fileManager: FileManager
    let processRegistry: FightcadeProcessRegistry
    let netplayPreparer: any FightcadeEmbeddedNetplayPreparing

    init(
        runtime: FightcadeRuntime = FightcadeRuntime(),
        fileManager: FileManager = .default,
        processRegistry: FightcadeProcessRegistry = .shared,
        netplayPreparer: any FightcadeEmbeddedNetplayPreparing = FightcadeEmbeddedProxyBootstrap()
    ) {
        self.runtime = runtime
        self.fileManager = fileManager
        self.processRegistry = processRegistry
        self.netplayPreparer = netplayPreparer
    }

    func canLaunchLocalGame(emulator: String) -> Bool {
        guard let runtimeRoot = try? runtime.root(),
              runtimeManifest(in: runtimeRoot).supportsEmbedded(emulator: emulator),
              (try? emulatorExecutable(emulator: emulator, runtime: runtimeRoot)) != nil else {
            return false
        }

        return true
    }

    func canLaunchFightcadeReplay(emulator: String) -> Bool {
        canLaunchFightcadeRoute(.fightcadeReplay, emulator: emulator)
    }

    func canLaunchFightcadeRoute(_ capability: FightcadeRuntimeCapability, emulator: String) -> Bool {
        guard let runtimeRoot = try? runtime.root(),
              runtimeManifest(in: runtimeRoot).supports(capability, emulator: emulator),
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
            guard manifest.supports(.fightcadeTraining, emulator: training.emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(training.emulator) training. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }
            let romURL = try ensureROMExists(emulator: training.emulator, gameID: training.gameID)

            try launch(
                emulator: training.emulator,
                arguments: [training.quarkCommand],
                runtime: runtimeRoot,
                expectedROM: romURL
            )

        case .match(let match):
            guard manifest.supports(.fightcadeMatch, emulator: match.emulator) else {
                FightcadeNetplayLaunchDiagnostics(fileManager: fileManager).writeUnsupportedAttempt(
                    match: match,
                    runtime: runtimeRoot,
                    reason: "Runtime manifest does not declare native Fightcade quark/GGPO support."
                )

                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(match.emulator) netplay. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }
            let romURL = try ensureROMExists(emulator: match.emulator, gameID: match.gameID)

            try launch(
                emulator: match.emulator,
                arguments: [match.quarkCommand],
                runtime: runtimeRoot,
                expectedROM: romURL
            )

        case .direct(let direct):
            guard manifest.supports(.fightcadeDirect, emulator: direct.emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(direct.emulator) direct play. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }
            let romURL = try ensureROMExists(emulator: direct.emulator, gameID: direct.gameID)

            try launch(
                emulator: direct.emulator,
                arguments: [direct.quarkCommand],
                runtime: runtimeRoot,
                expectedROM: romURL
            )

        case .spectate(let emulator, let gameID, let quarkID, let port):
            guard manifest.supports(.fightcadeSpectate, emulator: emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "native \(emulator) spectating. The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }
            let romURL = try ensureROMExists(emulator: emulator, gameID: gameID)

            try launch(
                emulator: emulator,
                arguments: [FightcadeSpectateLaunch(emulator: emulator, gameID: gameID, quarkID: quarkID, port: port).quarkCommand],
                runtime: runtimeRoot,
                expectedROM: romURL
            )

        case .endMatch:
            throw FightcadeLaunchError.unsupportedNativeRoute("force-ending emulator processes")
        }
    }

    func runtimeManifest(in runtime: URL) -> FightcadeRuntimeManifest {
        let manifestURL = runtime.appendingPathComponent("manifest.json")
        guard let data = try? Data(contentsOf: manifestURL),
              let manifest = try? JSONDecoder().decode(FightcadeRuntimeManifest.self, from: data) else {
            return .empty
        }

        return manifest
    }

    @discardableResult
    func ensureROMExists(emulator: String, gameID: String) throws -> URL {
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
    func launchProcess(
        emulator: String,
        arguments: [String],
        runtime: URL,
        expectedROM: URL?,
        launchLog: FightcadeLaunchLog,
        additionalEnvironment: [String: String],
        embeddedSession: FightcadeEmbeddedSession?
    ) throws -> Process {
        let executable = try emulatorExecutable(emulator: emulator, runtime: runtime)
        let processArguments = self.runtime.launchArguments(emulator: emulator, arguments: arguments, expectedROM: expectedROM)
        let romDirectory = try self.runtime.romDirectory(emulator: emulator)
        let dataDirectory = try self.runtime.dataDirectory(emulator: emulator)
        let configURL = try configureEmulator(emulator: emulator, runtime: runtime, romDirectory: romDirectory)
        let process = Process()
        process.executableURL = executable
        process.arguments = processArguments
        process.currentDirectoryURL = runtime
        process.standardOutput = launchLog.fileHandle
        process.standardError = launchLog.fileHandle
        var baseEnvironment = ProcessInfo.processInfo.environment
        baseEnvironment.removeValue(forKey: "__CFBundleIdentifier")
        let environment = baseEnvironment.merging([
            "MACADE_FIGHTCADE_RUNTIME": runtime.path,
            "MACADE_EMULATOR_DATA_DIR": dataDirectory.path,
            "MACADE_ROM_DIR": romDirectory.path,
            "FBNEO_ROM_DIR": romDirectory.path,
            "ROMPATH": romDirectory.path,
            "SDL_MAC_BACKGROUND_APP": "0",
            "SDL_RENDER_DRIVER": "software",
            "SDL_VIDEODRIVER": "cocoa"
        ]) { _, new in new }
        .merging(additionalEnvironment) { _, new in new }
        .merging(try controllerEnvironment(emulator: emulator)) { _, new in new }
        process.environment = environment
        launchLog.write(FightcadeLaunchDiagnostics(fileManager: fileManager).header(
            emulator: emulator,
            arguments: processArguments,
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

    func makeEmbeddedResources(emulator: String) throws -> FightcadeEmbeddedResources {
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

    private func controllerEnvironment(emulator: String) throws -> [String: String] {
        guard FightcadeEmulatorID.runtimeID(for: emulator) == "fbneo" else { return [:] }
        let directory = try runtime.dataDirectory(emulator: emulator)
        let projection = try MacadeGamepadPreferencesStore().writeRuntimeProjection(in: directory)
        var environment = [
            "MACADE_GAMEPAD_PROFILE_PATH": projection.path,
            "SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS": "1"
        ]
        if let mappings = try? FightcadeFBNeoSettingsStore(fileManager: fileManager).loadControllerMappings(),
           !mappings.isEmpty { environment["SDL_GAMECONTROLLERCONFIG"] = mappings }
        return environment
    }

    private func emulatorExecutable(emulator: String, runtime: URL) throws -> URL {
        let normalized = FightcadeEmulatorID.runtimeID(for: emulator)
        let relativePaths: [String]

        switch normalized {
        case "fbneo":
            relativePaths = [
                "emulators/fbneo/macfbneo",
                "emulators/fbneo/fbneo",
                "emulator/fbneo/macfbneo",
                "emulator/fbneo/fbneo"
            ]
        case "flycast":
            relativePaths = [
                "emulators/flycast/Flycast Dojo.app/Contents/MacOS/Flycast Dojo",
                "emulators/flycast/flycast",
                "emulator/flycast/Flycast Dojo.app/Contents/MacOS/Flycast Dojo",
                "emulator/flycast/flycast"
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
        let processIDs = ["macfbneo", "fcadefbneo"].flatMap(runningProcessIDs(named:)).filter { !managedProcessIDs.contains($0) && !isControllerHelper($0) }
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

    private func isControllerHelper(_ processID: pid_t) -> Bool {
        let process = Process()
        let output = Pipe()
        process.executableURL = URL(fileURLWithPath: "/bin/ps")
        process.arguments = ["-p", String(processID), "-o", "args="]
        process.standardOutput = output
        process.standardError = FileHandle.nullDevice
        guard (try? process.run()) != nil else { return false }
        let data = output.fileHandleForReading.readDataToEndOfFile()
        process.waitUntilExit()
        return String(data: data, encoding: .utf8)?.contains(" --macade-controllers") == true
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
