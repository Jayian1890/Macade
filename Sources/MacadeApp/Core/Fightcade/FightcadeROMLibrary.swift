import Foundation

@MainActor
protocol FightcadeROMLibraryServicing {
    func deleteROMs(emulator: String, gameID: String) throws -> [URL]
}

struct FightcadeROMLibrary: FightcadeROMLibraryServicing {
    private let runtime: FightcadeRuntime

    init(runtime: FightcadeRuntime = FightcadeRuntime()) {
        self.runtime = runtime
    }

    func deleteROMs(emulator: String, gameID: String) throws -> [URL] {
        try runtime.deleteROMs(emulator: emulator, gameID: gameID)
    }
}
