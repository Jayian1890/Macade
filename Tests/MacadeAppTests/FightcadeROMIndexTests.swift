import Foundation
import XCTest
@testable import MacadeApp

final class FightcadeROMIndexTests: XCTestCase {
    func testZipIndexPrefersArcadeWhenSystemIsUnknown() throws {
        let index = try FightcadeROMIndex(data: makeZip(), sourceName: "fc2json.zip")

        let entries = try index.entriesForDownload(emulator: "fbneo", system: nil, gameID: "pacman")

        XCTAssertEqual(entries.map(\.gameID), ["pacman"])
        XCTAssertEqual(entries.first?.urls.first?.absoluteString, "https://example.invalid/arcade-pacman.zip")
    }

    func testZipIndexUsesRequestedSystemWhenAvailable() throws {
        let index = try FightcadeROMIndex(data: makeZip(), sourceName: "fc2json.zip")

        let entries = try index.entriesForDownload(emulator: "fbneo", system: "Genesis", gameID: "pacman")

        XCTAssertEqual(entries.map(\.gameID), ["pacman"])
        XCTAssertEqual(entries.first?.urls.first?.absoluteString, "https://example.invalid/md-pacman.zip")
    }

    func testZipIndexKeepsDependencyResolutionInSameSystemScope() throws {
        let index = try FightcadeROMIndex(data: makeZip(), sourceName: "fc2json.zip")

        let entries = try index.entriesForDownload(emulator: "fbneo", system: "Arcade", gameID: "sfiii3n")

        XCTAssertEqual(entries.map(\.gameID), ["sfiii3", "sfiii3n"])
        XCTAssertEqual(entries.map { $0.urls.first?.absoluteString }, [
            "https://example.invalid/arcade-sfiii3.zip",
            "https://example.invalid/arcade-sfiii3n.zip"
        ])
    }

    func testIndexUsesFightcadeDownloadFilename() throws {
        let index = try FightcadeROMIndex(
            data: Data(#"{"snes_16mj":{"download":"https://example.invalid/snes9x/16mj.zip"}}"#.utf8),
            sourceName: "snes9x_roms.json"
        )

        let entries = try index.entriesForDownload(emulator: "snes9x", system: "SNES", gameID: "snes_16mj")

        XCTAssertEqual(entries.first?.downloadFileName, "16mj.zip")
    }

    func testIndexParsesFightcadeExtractTargets() throws {
        let index = try FightcadeROMIndex(
            data: Data(#"{"flycast_chd":{"download":"https://example.invalid/chd.zip","extract_to":[{"src":"game/file.chd","dst":"roms/Game/file.chd"}]}}"#.utf8),
            sourceName: "flycast_roms.json"
        )

        let entries = try index.entriesForDownload(emulator: "flycast", system: "Dreamcast", gameID: "flycast_chd")

        XCTAssertEqual(entries.first?.extractTargets, [
            FightcadeROMExtractTarget(source: "game/file.chd", destination: "roms/Game/file.chd")
        ])
    }

    private func makeZip() -> Data {
        makeStoredZip(files: [
            (
                "fbneo_cv_roms.json",
                Data(#"{"pacman":{"download":"https://example.invalid/cv-pacman.zip"}}"#.utf8)
            ),
            (
                "fbneo_md_roms.json",
                Data(#"{"pacman":{"download":"https://example.invalid/md-pacman.zip"}}"#.utf8)
            ),
            (
                "fbneo_roms.json",
                Data(#"{"pacman":{"download":"https://example.invalid/arcade-pacman.zip"},"sfiii3":{"download":"https://example.invalid/arcade-sfiii3.zip"},"sfiii3n":{"download":"https://example.invalid/arcade-sfiii3n.zip","require":["sfiii3"]}}"#.utf8)
            )
        ])
    }

    private func makeStoredZip(files: [(name: String, data: Data)]) -> Data {
        var archive = Data()
        var centralDirectory = Data()

        for file in files {
            let localHeaderOffset = archive.count
            let name = Data(file.name.utf8)
            archive.appendUInt32(0x04034b50)
            archive.appendUInt16(20)
            archive.appendUInt16(0)
            archive.appendUInt16(0)
            archive.appendUInt16(0)
            archive.appendUInt16(0)
            archive.appendUInt32(0)
            archive.appendUInt32(UInt32(file.data.count))
            archive.appendUInt32(UInt32(file.data.count))
            archive.appendUInt16(UInt16(name.count))
            archive.appendUInt16(0)
            archive.append(name)
            archive.append(file.data)

            centralDirectory.appendUInt32(0x02014b50)
            centralDirectory.appendUInt16(20)
            centralDirectory.appendUInt16(20)
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt32(0)
            centralDirectory.appendUInt32(UInt32(file.data.count))
            centralDirectory.appendUInt32(UInt32(file.data.count))
            centralDirectory.appendUInt16(UInt16(name.count))
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt16(0)
            centralDirectory.appendUInt32(0)
            centralDirectory.appendUInt32(UInt32(localHeaderOffset))
            centralDirectory.append(name)
        }

        let centralDirectoryOffset = archive.count
        archive.append(centralDirectory)
        archive.appendUInt32(0x06054b50)
        archive.appendUInt16(0)
        archive.appendUInt16(0)
        archive.appendUInt16(UInt16(files.count))
        archive.appendUInt16(UInt16(files.count))
        archive.appendUInt32(UInt32(centralDirectory.count))
        archive.appendUInt32(UInt32(centralDirectoryOffset))
        archive.appendUInt16(0)
        return archive
    }
}

private extension Data {
    mutating func appendUInt16(_ value: UInt16) {
        append(UInt8(value & 0xff))
        append(UInt8((value >> 8) & 0xff))
    }

    mutating func appendUInt32(_ value: UInt32) {
        appendUInt16(UInt16(value & 0xffff))
        appendUInt16(UInt16((value >> 16) & 0xffff))
    }
}
