import XCTest
@testable import Macade

final class FightcadeRuntimeRegressionTests: XCTestCase {
    func testSnes9xROMCandidatesCoverFightcadePrefixesAndLooseROMs() throws {
        let supportURL = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: supportURL) }
        let runtime = FightcadeRuntime(applicationSupportURL: supportURL)

        let candidates = try runtime.romCandidateURLs(emulator: "snes9x", gameID: "snes_16mj")

        XCTAssertEqual(candidates.map(\.lastPathComponent), [
            "snes_16mj.zip",
            "snes_16mj.sfc",
            "snes_16mj.smc",
            "16mj.zip",
            "16mj.sfc",
            "16mj.smc"
        ])
        XCTAssertTrue(candidates.allSatisfy { $0.path.contains("/Macade/FightcadeRuntime/roms/snes9x/") })
    }

    func testSnes9xExistingROMAcceptsStrippedDownloadedZip() throws {
        let supportURL = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: supportURL) }
        let runtime = FightcadeRuntime(applicationSupportURL: supportURL)
        let romURL = try runtime.romFileURL(emulator: "snes9x", fileName: "16mj.zip")
        try Data([0x01]).write(to: romURL)

        let found = try runtime.existingROMURL(emulator: "snes9x", gameID: "snes_16mj")

        XCTAssertEqual(found, romURL)
    }

    func testLegacyEmulatorAliasesResolveToNativeRuntimeIDs() throws {
        XCTAssertEqual(FightcadeEmulatorID.runtimeID(for: "FC1"), "ggpofba")
        XCTAssertEqual(FightcadeEmulatorID.runtimeID(for: "nulldc"), "flycast")

        let supportURL = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: supportURL) }
        let runtime = FightcadeRuntime(applicationSupportURL: supportURL)

        XCTAssertTrue(try runtime.romDirectory(emulator: "fc1").path.hasSuffix("/Macade/FightcadeRuntime/roms/ggpofba"))
        XCTAssertTrue(try runtime.romDirectory(emulator: "nulldc").path.hasSuffix("/Macade/FightcadeRuntime/roms/flycast"))
    }

    func testRuntimeManifestSeparatesEmbeddedAndQuarkSupport() throws {
        let data = Data(
            #"{"emulators":{"fbneo":{"supportsQuark":true},"snes9x":{"supportsQuark":false,"supportsEmbedded":true,"supportsFightcadeMatch":false},"flycast":{"supportsQuark":false,"supportsEmbedded":true,"supportsFightcadeMatch":false,"supportsFightcadeDirect":false,"supportsFightcadeSpectate":false,"supportsFightcadeTraining":false}}}"#.utf8
        )
        let manifest = try JSONDecoder().decode(FightcadeRuntimeManifest.self, from: data)

        XCTAssertTrue(manifest.supportsQuark(emulator: "fbneo"))
        XCTAssertTrue(manifest.supportsEmbedded(emulator: "fbneo"))
        XCTAssertFalse(manifest.supportsQuark(emulator: "snes9x"))
        XCTAssertTrue(manifest.supportsEmbedded(emulator: "snes9x"))
        XCTAssertFalse(manifest.supports(.fightcadeMatch, emulator: "snes9x"))
        XCTAssertTrue(manifest.supportsEmbedded(emulator: "flycast"))
        XCTAssertFalse(manifest.supports(.fightcadeMatch, emulator: "flycast"))
        XCTAssertFalse(manifest.supports(.fightcadeDirect, emulator: "flycast"))
        XCTAssertFalse(manifest.supports(.fightcadeTraining, emulator: "flycast"))
    }

    func testFlycastROMCandidatesCoverDiscAndArcadeContent() throws {
        let supportURL = temporaryDirectory()
        defer { try? FileManager.default.removeItem(at: supportURL) }
        let runtime = FightcadeRuntime(applicationSupportURL: supportURL)

        let candidates = try runtime.romCandidateURLs(emulator: "flycast", gameID: "flycast_dc_mvsc2")
            .map(\.lastPathComponent)

        XCTAssertTrue(candidates.contains("flycast_dc_mvsc2.chd"))
        XCTAssertTrue(candidates.contains("dc_mvsc2.gdi"))
        XCTAssertTrue(candidates.contains("dc_mvsc2.zip"))
    }

    func testFlycastLocalLaunchUsesResolvedROMPath() throws {
        let runtime = FightcadeRuntime()
        let romURL = URL(fileURLWithPath: "/tmp/mvsc2.chd")

        XCTAssertEqual(runtime.launchArguments(emulator: "flycast", arguments: ["flycast_dc_mvsc2"], expectedROM: romURL), [romURL.path])
        XCTAssertEqual(runtime.launchArguments(emulator: "flycast", arguments: ["quark:served,mvsc2,q,7000,2,0"], expectedROM: nil), ["quark:served,mvsc2,q,7000,2,0"])
        XCTAssertEqual(runtime.launchArguments(emulator: "snes9x", arguments: ["snes_smwu"], expectedROM: romURL), ["snes_smwu"])
    }

    func testEmbeddedLaunchRequiresQuarkOnlyForNetworkRoutesOrQuarkArguments() {
        XCTAssertFalse(FightcadeEmbeddedLaunch.test(channelID: "snes", emulator: "snes9x", gameID: "snes_16mj").requiresQuark)
        XCTAssertFalse(FightcadeEmbeddedLaunch.training(channelID: "snes", emulator: "snes9x", gameID: "snes_16mj").requiresQuark)
        XCTAssertTrue(FightcadeEmbeddedLaunch.direct(channelID: "snes", launch: FightcadeDirectLaunch(
            emulator: "snes9x",
            gameID: "snes_16mj",
            localPort: 6000,
            host: "203.0.113.20",
            remotePort: 6001,
            playerID: 0,
            delay: 2,
            ranked: 0
        )).requiresQuark)
        XCTAssertTrue(FightcadeEmbeddedLaunch.fightcadeTraining(channelID: "snes", launch: FightcadeTrainingLaunch(
            emulator: "snes9x",
            gameID: "snes_16mj",
            quarkID: "1234567890-42",
            playerID: 1,
            port: 7000,
            delay: 2
        )).requiresQuark)
    }

    func testPairPlayQuarkCommandsCoverBothPlayerSides() {
        let playerOne = makeMatch(playerID: 0, delay: 1, ranked: 0)
        let playerTwo = makeMatch(playerID: 1, delay: 3, ranked: 1)

        XCTAssertEqual(playerOne.quarkCommand, "quark:served,sfiii3n,1785013981484-4901.0,7000,1,0")
        XCTAssertEqual(playerTwo.quarkCommand, "quark:served,sfiii3n,1785013981484-4901.1,7000,3,1")

        let playerOnePlan = FightcadeGGPOServedHandshakePlan(match: playerOne)
        let playerTwoPlan = FightcadeGGPOServedHandshakePlan(match: playerTwo)

        XCTAssertEqual(playerOnePlan.quark, "1785013981484-4901.0")
        XCTAssertEqual(playerTwoPlan.quark, "1785013981484-4901.1")
        XCTAssertEqual(playerOnePlan.readyCommand, "C2,0,1,0")
        XCTAssertEqual(playerTwoPlan.readyCommand, "C2,1,3,1")
    }

    func testSpectatorQuarkCommandAlwaysUsesObserverSlotTwo() {
        let unsuffixed = FightcadeSpectateLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1785013981484-4901",
            port: 7001
        )
        let playerOne = FightcadeSpectateLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1785013981484-4901.0",
            port: 7001
        )
        let playerTwo = FightcadeSpectateLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1785013981484-4901.1",
            port: 7001
        )

        XCTAssertEqual(unsuffixed.quarkCommand, "quark:stream,sfiii3n,1785013981484-4901.2,7001")
        XCTAssertEqual(playerOne.quarkCommand, "quark:stream,sfiii3n,1785013981484-4901.2,7001")
        XCTAssertEqual(playerTwo.quarkCommand, "quark:stream,sfiii3n,1785013981484-4901.2,7001")
    }

    func testServedStartupBatchLocksFrameCountInputSizeAndZeroPayload() throws {
        let plan = FightcadeGGPOServedHandshakePlan(match: makeMatch(playerID: 1, delay: 2, ranked: 0))
        let batch = try XCTUnwrap(
            FightcadeGGPOServedCommandBuilder.startupCommands(plan: plan).first { $0.command == 17 }
        )
        var cursor = 0

        XCTAssertEqual(try readGGPOString(batch.payload, cursor: &cursor), "1785013981484-4901.1")
        XCTAssertEqual(try readUInt32(batch.payload, cursor: &cursor), 60)
        XCTAssertEqual(try readUInt32(batch.payload, cursor: &cursor), 10)

        let inputBytes = Data(batch.payload[cursor...])
        XCTAssertEqual(inputBytes.count, 600)
        XCTAssertEqual(inputBytes, Data(repeating: 0, count: 600))
    }

    func testServedStartupReadyCommandIncludesPairPlayDelayAndRankedFields() throws {
        let plan = FightcadeGGPOServedHandshakePlan(match: makeMatch(playerID: 0, delay: 4, ranked: 3))
        let ready = try XCTUnwrap(FightcadeGGPOServedCommandBuilder.startupCommands(plan: plan).last)
        var cursor = 0

        XCTAssertEqual(ready.sequence, 6)
        XCTAssertEqual(ready.command, 15)
        XCTAssertEqual(try readGGPOString(ready.payload, cursor: &cursor), "1785013981484-4901.0")
        XCTAssertEqual(try readGGPOString(ready.payload, cursor: &cursor), "C2,0,4,3")
        XCTAssertEqual(cursor, ready.payload.count)
    }

    func testMasterClientSuccessfulBoundFallbackKeepsLiveTransportOpenUntilSessionClose() async throws {
        let plan = FightcadeQuarkSessionPlan(match: makeMatch(playerID: 0, delay: 2, ranked: 0))
        let initial = CloseTrackingUDPTransport(receives: [
            (Data(plan.expectedOKPayload.utf8), plan.master),
            (Data([198, 51, 100, 7, 0x5c, 0x1b]), FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006))
        ])
        let restricted = CloseTrackingUDPTransport(receives: [
            (Data("0.456 _".utf8), FightcadeNetplayEndpoint(host: "198.51.100.7", port: plan.restrictedNATFallbackPort))
        ])
        let factory = CloseTrackingUDPTransportFactory(transports: [initial, restricted])
        let client = FightcadeMasterClient(
            transportFactory: factory,
            holePuncher: FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in }),
            fallbackRadius: 0
        )

        let session = try await client.establishProxySession(plan: plan)

        XCTAssertEqual(factory.bindPorts, [plan.localBindPort, plan.restrictedNATFallbackPort])
        XCTAssertEqual(initial.closeCount, 1)
        XCTAssertEqual(restricted.closeCount, 0)
        XCTAssertEqual(session.peer, FightcadeNetplayEndpoint(host: "198.51.100.7", port: plan.restrictedNATFallbackPort))
        XCTAssertEqual(String(data: restricted.sent.last?.0 ?? Data(), encoding: .utf8), "0.123 0.456 ok")

        session.close()
        XCTAssertEqual(restricted.closeCount, 1)
    }

    func testMasterClientBadMasterResponseSendsUsePortsAndClosesTransport() async {
        let plan = FightcadeQuarkSessionPlan(match: makeMatch(playerID: 0, delay: 2, ranked: 0))
        let transport = CloseTrackingUDPTransport(receives: [
            (Data("bad".utf8), plan.master)
        ])
        let factory = CloseTrackingUDPTransportFactory(transports: [transport])
        let client = FightcadeMasterClient(
            transportFactory: factory,
            holePuncher: FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in }),
            fallbackRadius: 0
        )

        await XCTAssertThrowsErrorAsync(try await client.establishProxySession(plan: plan)) { error in
            XCTAssertEqual(error as? FightcadeMasterClientError, .unexpectedMasterResponse)
        }

        XCTAssertEqual(transport.sent.compactMap { String(data: $0.0, encoding: .utf8) }, [
            plan.registrationPayload,
            plan.usePortsPayload
        ])
        XCTAssertEqual(transport.closeCount, 1)
    }

    func testPeerUDPControlMessagesUseLittleEndianAndSignedFields() {
        let inputPayload = Data(hex: "0302000000feffffff11000a430000")

        XCTAssertEqual(FightcadeGGPOPeerUDPPacket.parse(Data(hex: "02efbeadde")).kind, .syncReply(nonce: 0xdeadbeef))
        XCTAssertEqual(
            FightcadeGGPOPeerUDPPacket.parse(Data(hex: "04ff04030201")).kind,
            .qualityReport(frameAdvantage: -1, nonce: 0x01020304)
        )
        XCTAssertEqual(FightcadeGGPOPeerUDPPacket.parse(Data(hex: "0504030201")).kind, .qualityReply(nonce: 0x01020304))

        guard case let .input(input) = FightcadeGGPOPeerUDPPacket.parse(inputPayload).kind else {
            return XCTFail("Expected input packet")
        }
        XCTAssertEqual(input.startFrame, 2)
        XCTAssertEqual(input.ackFrame, -2)
        XCTAssertEqual(input.compressedBitCount, 17)
        XCTAssertEqual(input.inputSizeBytes, 10)
        XCTAssertEqual(input.inputBits, Data(hex: "430000"))
        XCTAssertEqual(input.encoded, inputPayload)
    }

    func testStreamedFrameBatchPreservesTrailingRollbackBytes() throws {
        var body = Data()
        body.appendBigEndianUInt32(2)
        body.appendBigEndianUInt32(3)
        body.append(Data([0x10, 0x11, 0x20, 0x21, 0x30, 0x31, 0xee, 0xff]))

        let event = try FightcadeGGPOEventBodyParser.parseStreamedFrameBatch(body)
        let record = try FightcadeGGPORawServerRecord(frame: FightcadeGGPOServerRecordFrame(code: -13, payload: body))

        XCTAssertEqual(event.frameSize, 2)
        XCTAssertEqual(event.frameCount, 3)
        XCTAssertEqual(event.frames, [Data([0x10, 0x11]), Data([0x20, 0x21]), Data([0x30, 0x31])])
        XCTAssertEqual(event.trailingData, Data([0xee, 0xff]))
        XCTAssertEqual(record.body, .streamedFrameBatch(event))
    }

    func testStreamedFrameBatchRejectsOverflowedRollbackFrameSizes() {
        var body = Data()
        body.appendBigEndianUInt32(UInt32.max)
        body.appendBigEndianUInt32(UInt32.max)

        XCTAssertThrowsError(try FightcadeGGPOEventBodyParser.parseStreamedFrameBatch(body)) { error in
            XCTAssertEqual(error as? FightcadeGGPOEventBodyParser.ParseError, .truncated)
        }
    }

    func testLiveStreamUpdateAcceptsNestedPairPlayersAndStringPortForSpectating() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "req": "quarkstats",
            "channelname": "sfiii3n",
            "gameid": "sfiii3n",
            "quark": [
                "players": [
                    ["name": "PlayerOne"],
                    ["username": "PlayerTwo"]
                ],
                "quarkid": "1785013981484-4901",
                "port": "7001"
            ]
        ]

        let event = parser.event(in: payload, currentChannelName: nil)

        guard case let .liveStreamUpdated(update) = event else {
            return XCTFail("Expected live stream update")
        }
        XCTAssertEqual(update.channelName, "sfiii3n")
        XCTAssertEqual(update.players, ["PlayerOne", "PlayerTwo"])
        XCTAssertEqual(update.stream, FightcadeSpectatorStream(gameID: nil, quarkID: "1785013981484-4901", port: 7001))
    }

    func testRosterQuarkStreamsMarkBothPairPlayersPlayingCaseInsensitively() {
        let parser = FightcadeLobbyPayloadParser()
        let payload: [String: Any] = [
            "gameid": "sfiii3n",
            "users": [
                ["name": "PlayerOne", "playing": false],
                ["name": "playertwo", "playing": false],
                ["name": "idle", "playing": false]
            ],
            "quarks": [
                [
                    "players": ["playerone", "PlayerTwo"],
                    "port": 7001,
                    "quarkid": "1785013981484-4901"
                ]
            ]
        ]

        let users = parser.users(in: payload)

        XCTAssertEqual(users[0].stream, FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785013981484-4901", port: 7001))
        XCTAssertEqual(users[1].stream, FightcadeSpectatorStream(gameID: "sfiii3n", quarkID: "1785013981484-4901", port: 7001))
        XCTAssertTrue(users[0].isPlaying)
        XCTAssertTrue(users[1].isPlaying)
        XCTAssertNil(users[2].stream)
        XCTAssertFalse(users[2].isPlaying)
    }

    private func makeMatch(playerID: Int, delay: Int, ranked: Int) -> FightcadeMatchLaunch {
        FightcadeMatchLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1785013981484-4901",
            playerID: playerID,
            port: 7000,
            delay: delay,
            ranked: ranked,
            token: nil
        )
    }

    private func readGGPOString(_ data: Data, cursor: inout Int) throws -> String {
        let length = Int(try readUInt32(data, cursor: &cursor))
        guard cursor + length <= data.count else { throw FightcadeGGPOEventBodyParser.ParseError.truncated }
        let bytes = data[cursor..<cursor + length]
        cursor += length
        guard let value = String(data: bytes, encoding: .utf8) else {
            throw FightcadeGGPOEventBodyParser.ParseError.invalidString
        }
        return value
    }

    private func readUInt32(_ data: Data, cursor: inout Int) throws -> UInt32 {
        guard cursor + 4 <= data.count else { throw FightcadeGGPOEventBodyParser.ParseError.truncated }
        let value = data[cursor..<cursor + 4].reduce(UInt32(0)) { partial, byte in
            (partial << 8) | UInt32(byte)
        }
        cursor += 4
        return value
    }

    private func temporaryDirectory() -> URL {
        FileManager.default.temporaryDirectory
            .appendingPathComponent("MacadeTests")
            .appendingPathComponent(UUID().uuidString)
    }
}

private final class CloseTrackingUDPTransport: FightcadeUDPTransporting, @unchecked Sendable {
    private var receives: [(Data, FightcadeNetplayEndpoint)]
    private(set) var sent: [(Data, FightcadeNetplayEndpoint)] = []
    private(set) var closeCount = 0

    init(receives: [(Data, FightcadeNetplayEndpoint)]) {
        self.receives = receives
    }

    func send(_ data: Data, to endpoint: FightcadeNetplayEndpoint) async throws {
        sent.append((data, endpoint))
    }

    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> (Data, FightcadeNetplayEndpoint) {
        guard !receives.isEmpty else { throw POSIXError(.ETIMEDOUT) }
        return receives.removeFirst()
    }

    func close() {
        closeCount += 1
    }
}

private final class CloseTrackingUDPTransportFactory: FightcadeUDPTransportFactory, @unchecked Sendable {
    private var transports: [CloseTrackingUDPTransport]
    private(set) var bindPorts: [Int?] = []

    init(transports: [CloseTrackingUDPTransport]) {
        self.transports = transports
    }

    func makeTransport(bindPort: Int?) throws -> any FightcadeUDPTransporting {
        bindPorts.append(bindPort)
        guard !transports.isEmpty else { throw POSIXError(.ENOTCONN) }
        return transports.removeFirst()
    }
}

private extension Data {
    init(hex: String) {
        var bytes: [UInt8] = []
        var index = hex.startIndex
        while index < hex.endIndex {
            let next = hex.index(index, offsetBy: 2)
            bytes.append(UInt8(hex[index..<next], radix: 16)!)
            index = next
        }
        self.init(bytes)
    }
}

private func XCTAssertThrowsErrorAsync(
    _ expression: @autoclosure () async throws -> some Any,
    _ handler: (Error) -> Void,
    file: StaticString = #filePath,
    line: UInt = #line
) async {
    do {
        _ = try await expression()
        XCTFail("Expected error", file: file, line: line)
    } catch {
        handler(error)
    }
}
