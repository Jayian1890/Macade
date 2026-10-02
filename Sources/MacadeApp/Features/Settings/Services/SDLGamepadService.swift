import Foundation
import Darwin

@MainActor
protocol GamepadServicing {
    func monitor() throws -> AsyncThrowingStream<GamepadSnapshot, any Error>
    func games() async throws -> [GamepadGame]
    func inputs(gameID: String) async throws -> [GamepadGameInput]
    func stop()
}

@MainActor
final class SDLGamepadService: GamepadServicing {
    private var process: Process?
    private var reader: Task<Void, Never>?

    func monitor() throws -> AsyncThrowingStream<GamepadSnapshot, any Error> {
        stop()
        let (child, pipe) = try launch(arguments: ["--macade-controllers"])
        process = child
        return AsyncThrowingStream { continuation in
            reader = Task.detached {
                var pending = Data()
                var buffer = [UInt8](repeating: 0, count: 16384)
                do {
                    // Foundation's read(upToCount:) can wait to fill the buffer.
                    // The helper emits only changed snapshots; a neutral pad (or
                    // no pad) must be visible after the first short JSON line.
                    while !Task.isCancelled {
                        let count = buffer.withUnsafeMutableBytes {
                            Darwin.read(pipe.fileHandleForReading.fileDescriptor, $0.baseAddress, $0.count)
                        }
                        if count == 0 { break }
                        if count < 0 {
                            if errno == EINTR { continue }
                            throw GamepadServiceError.discoveryStopped
                        }
                        pending.append(contentsOf: buffer.prefix(count))
                        guard pending.count < 1_048_576 else { throw GamepadServiceError.invalidResponse }
                        while let newline = pending.firstIndex(of: 10) {
                            let line = Data(pending[..<newline])
                            pending.removeSubrange(...newline)
                            continuation.yield(try JSONDecoder().decode(GamepadSnapshot.self, from: line))
                        }
                    }
                    child.waitUntilExit()
                    if !Task.isCancelled { throw GamepadServiceError.discoveryStopped }
                    continuation.finish()
                } catch {
                    continuation.finish(throwing: error)
                }
                try? pipe.fileHandleForReading.close()
            }
        }
    }

    func games() async throws -> [GamepadGame] {
        try await query(arguments: ["--macade-gamepad-games"])
    }

    func inputs(gameID: String) async throws -> [GamepadGameInput] {
        try await query(arguments: ["--macade-gamepad-inputs", gameID])
    }

    func stop() {
        reader?.cancel()
        reader = nil
        if let process, process.isRunning { process.terminate() }
        process = nil
    }

    private func query<T: Decodable & Sendable>(arguments: [String]) async throws -> T {
        let (child, pipe) = try launch(arguments: arguments)
        return try await Task.detached {
            let data = pipe.fileHandleForReading.readDataToEndOfFile()
            try? pipe.fileHandleForReading.close()
            child.waitUntilExit()
            guard child.terminationStatus == 0 else { throw GamepadServiceError.invalidResponse }
            return try JSONDecoder().decode(T.self, from: data)
        }.value
    }

    private func launch(arguments: [String]) throws -> (Process, Pipe) {
        let executable = try FightcadeRuntime().root().appendingPathComponent("emulators/fbneo/macfbneo")
        guard FileManager.default.isExecutableFile(atPath: executable.path) else {
            throw GamepadServiceError.missingRuntime
        }
        let child = Process()
        let pipe = Pipe()
        child.executableURL = executable
        child.arguments = arguments
        child.standardOutput = pipe
        child.standardError = FileHandle.nullDevice
        child.environment = ProcessInfo.processInfo.environment.merging([
            "SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS": "1"
        ]) { _, new in new }
        try child.run()
        // Closing the parent's writer lets EOF reach the reader when the helper exits.
        try? pipe.fileHandleForWriting.close()
        return (child, pipe)
    }
}

private enum GamepadServiceError: LocalizedError {
    case missingRuntime, invalidResponse, discoveryStopped
    var errorDescription: String? {
        switch self {
        case .missingRuntime: "The bundled FBNeo runtime is unavailable."
        case .invalidResponse: "FBNeo could not read controller or game input information."
        case .discoveryStopped: "Controller discovery stopped. Reopen Controllers to reconnect."
        }
    }
}
