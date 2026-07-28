import XCTest
@testable import MacadeApp

final class FightcadeFBNeoSettingsStoreTests: XCTestCase {
    func testSaveAndLoadRoundTripsSupportedSettings() throws {
        let directory = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        let store = FightcadeFBNeoSettingsStore(configDirectory: directory)
        var settings = FightcadeFBNeoSettings.defaults
        settings.stretchToWindow = true
        settings.scanlines = true
        settings.softwareGamma = true
        settings.gamma = 1.5
        settings.volume = 55
        settings.sampleRate = 48_000
        settings.dspFilter = true
        settings.pcmInterpolation = 3
        settings.fmInterpolation = 1
        settings.hiscores = true
        settings.autoFireRate = 20
        settings.samplesPath = "custom/samples"
        settings.hiscorePath = "custom/hiscores"
        settings.eepromPath = "custom/saves"
        settings.hddPath = "custom/hdd"
        settings.controllerMappings = "  mapping-one  \n\n mapping-two\n"

        try store.save(settings)

        var expected = settings.normalized()
        expected.controllerMappings = "mapping-one\nmapping-two"
        XCTAssertEqual(try store.load(), expected)
    }

    func testSavePreservesUnknownConfigLines() throws {
        let directory = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        let configURL = directory.appendingPathComponent("fbneo.ini")
        try """
        // user comment
        nUnrelatedSetting keep-me
        nAudVolume 10000
        """.write(to: configURL, atomically: true, encoding: .utf8)
        let store = FightcadeFBNeoSettingsStore(configDirectory: directory)
        var settings = FightcadeFBNeoSettings.defaults
        settings.volume = 35

        try store.save(settings)

        let contents = try String(contentsOf: configURL, encoding: .utf8)
        XCTAssertTrue(contents.contains("// user comment"))
        XCTAssertTrue(contents.contains("nUnrelatedSetting keep-me"))
        XCTAssertTrue(contents.contains("nAudVolume 3500"))
    }

    func testSaveWritesFBNeoSupportFolderKeys() throws {
        let directory = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        let store = FightcadeFBNeoSettingsStore(configDirectory: directory)
        var settings = FightcadeFBNeoSettings.defaults
        settings.samplesPath = "support/custom-samples"
        settings.hiscorePath = "support/custom-hiscores"
        settings.eepromPath = "config/custom-games"
        settings.hddPath = "support/custom-hdd"

        try store.save(settings)

        let contents = try String(contentsOf: directory.appendingPathComponent("fbneo.ini"), encoding: .utf8)
        XCTAssertTrue(contents.contains("szAppSamplesPath support/custom-samples/"))
        XCTAssertTrue(contents.contains("szAppHiscorePath support/custom-hiscores/"))
        XCTAssertTrue(contents.contains("szAppEEPROMPath config/custom-games/"))
        XCTAssertTrue(contents.contains("szAppHDDPath support/custom-hdd/"))
    }

    func testLoadNormalizesOutOfRangeValues() throws {
        let directory = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: directory) }
        try FileManager.default.createDirectory(at: directory, withIntermediateDirectories: true)
        try """
        nGamma 9.000000
        nAudVolume 25000
        nAudSampleRate[0] 12345
        nInterpolation 9
        nFMInterpolation -1
        nAutoFireRate 99
        szAppSamplesPath
        szAppHiscorePath custom/hiscores
        szAppEEPROMPath custom/saves
        szAppHDDPath custom/hdd
        """.write(to: directory.appendingPathComponent("fbneo.ini"), atomically: true, encoding: .utf8)
        let settings = try FightcadeFBNeoSettingsStore(configDirectory: directory).load()

        XCTAssertEqual(settings.gamma, 2.0)
        XCTAssertEqual(settings.volume, 100)
        XCTAssertEqual(settings.sampleRate, FightcadeFBNeoSettings.defaults.sampleRate)
        XCTAssertEqual(settings.pcmInterpolation, FightcadeFBNeoSettings.defaults.pcmInterpolation)
        XCTAssertEqual(settings.fmInterpolation, FightcadeFBNeoSettings.defaults.fmInterpolation)
        XCTAssertEqual(settings.autoFireRate, 30)
        XCTAssertEqual(settings.samplesPath, FightcadeFBNeoSettings.defaultSamplesPath)
        XCTAssertEqual(settings.hiscorePath, "custom/hiscores/")
        XCTAssertEqual(settings.eepromPath, "custom/saves/")
        XCTAssertEqual(settings.hddPath, "custom/hdd/")
    }

    private func temporaryDirectory() -> URL {
        FileManager.default.temporaryDirectory
            .appendingPathComponent("MacadeSettingsTests")
            .appendingPathComponent(UUID().uuidString)
    }
}
