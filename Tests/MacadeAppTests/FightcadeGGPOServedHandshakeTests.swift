import XCTest
@testable import MacadeApp

final class FightcadeGGPOServedHandshakeTests: XCTestCase {
    func testServedHandshakePlanUsesCaptureBackedDefaults() {
        let plan = makePlan()

        XCTAssertEqual(plan.endpoint, FightcadeNetplayEndpoint(host: "ggpo.fightcade.com", port: 7000))
        XCTAssertEqual(plan.quark, "1234567890-42.1")
        XCTAssertEqual(plan.localTCPBindPort, 6004)
        XCTAssertEqual(plan.registrationValue, 6000)
        XCTAssertEqual(plan.versionMarker, "V14")
        XCTAssertEqual(plan.readyCommand, "C2,1,2,0")
    }

    func testStartupCommandsMatchObservedCommandOrderAndShapes() {
        let commands = FightcadeGGPOServedCommandBuilder.startupCommands(plan: makePlan())

        XCTAssertEqual(commands.map(\.sequence), [1, 2, 3, 4, 5, 6])
        XCTAssertEqual(commands.map(\.command), [0, 11, 12, 15, 17, 15])
        XCTAssertEqual(commands[1].payload, Data(hex: "0000000f313233343536373839302d34322e3100001770"))
        XCTAssertEqual(commands[2].payload, Data(hex: "0000000f313233343536373839302d34322e31"))
        XCTAssertEqual(commands[3].payload, Data(hex: "0000000f313233343536373839302d34322e3100000003563134"))
        XCTAssertEqual(commands[4].payload.prefix(27), Data(hex: "0000000f313233343536373839302d34322e310000003c0000000a"))
        XCTAssertEqual(commands[4].payload.count, 627)
        XCTAssertEqual(commands[5].payload, Data(hex: "0000000f313233343536373839302d34322e310000000843322c312c322c30"))
    }

    func testServedHandshakeClientSendsStartupCommandsAndCollectsServerRecords() async throws {
        let response = Data.concatenate([
            serverRecord(code: 1, body: Data([0, 0, 0, 0])),
            serverRecord(code: -7, body: endpointNoticeBody(host: "127.0.0.1", value1: 7001, value2: 0)),
            serverRecord(code: -10, body: Data([0, 0, 0, 1])),
            serverRecord(code: -8, body: commandMessageBody("match.1", "Command", "2,1,1,0")),
        ])
        let transport = ScriptedServedTCPTransport(receives: [Data(response.prefix(11)), Data(response.dropFirst(11))])
        let client = FightcadeGGPOServedHandshakeClient(transport: transport)

        let result = try await client.runStartup(plan: makePlan(), timeout: 1)

        XCTAssertEqual(transport.sent, FightcadeGGPOServedCommandBuilder.startupCommands(plan: makePlan()).map(\.encoded))
        XCTAssertEqual(result.endpointNotice, .init(host: "127.0.0.1", value1: 7001, value2: 0))
        XCTAssertTrue(result.receivedReadyCommandEcho)
    }

    func testServedHandshakeClientFailsWithoutReadyCommandEcho() async {
        let transport = ScriptedServedTCPTransport(receives: [serverRecord(code: 1, body: Data([0, 0, 0, 0]))])
        let client = FightcadeGGPOServedHandshakeClient(transport: transport)

        await XCTAssertThrowsErrorAsync(try await client.runStartup(plan: makePlan(), timeout: 1)) { error in
            XCTAssertEqual(error as? FightcadeGGPOServedHandshakeError, .missingReadyCommandEcho)
        }
    }

    func testPeerUDPPacketParserClassifiesHolePunchAndBinaryFamilies() {
        let firstInputPacket = Data(hex: "0301000000ffffffff0b000ae330")
        let packets = [
            FightcadeGGPOPeerUDPPacket.parse(Data("0.123 _".utf8)),
            FightcadeGGPOPeerUDPPacket.parse(Data(hex: "017d7d0000")),
            FightcadeGGPOPeerUDPPacket.parse(firstInputPacket),
            FightcadeGGPOPeerUDPPacket.parse(Data(hex: "040c0c47b400")),
            FightcadeGGPOPeerUDPPacket.parse(Data(hex: "050c47b400")),
        ]

        let summary = FightcadeGGPOPeerUDPPacketSummary.summarize(packets)

        XCTAssertEqual(summary.holePunchPacketCount, 1)
        XCTAssertEqual(summary.binaryTypeCounts, [1: 1, 3: 1, 4: 1, 5: 1])
        XCTAssertEqual(summary.payloadLengthCounts, [5: 2, 14: 1, 6: 1])
        XCTAssertEqual(packets[1].kind, .syncRequest(nonce: 32125))
        XCTAssertEqual(packets[2].kind, .input(.init(
            startFrame: 1,
            ackFrame: -1,
            compressedBitCount: 11,
            inputSizeBytes: 10,
            inputBits: Data(hex: "e330")
        )))
        if case let .input(input) = packets[2].kind {
            XCTAssertEqual(input.expectedBitPayloadByteCount, 2)
            XCTAssertEqual(input.encoded, firstInputPacket)
        } else {
            XCTFail("Expected input packet")
        }
        XCTAssertEqual(packets[3].kind, .qualityReport(frameAdvantage: 12, nonce: 11814668))
        XCTAssertEqual(packets[4].kind, .qualityReply(nonce: 11814668))
    }

    func testPeerUDPInputPacketValidatesCompressedPayloadLength() {
        let oneByteInput = FightcadeGGPOPeerUDPPacket.parse(Data(hex: "03030000000400000005000ae0"))
        let threeByteInput = FightcadeGGPOPeerUDPPacket.parse(Data(hex: "03020000000500000011000a430000"))
        let truncatedInput = FightcadeGGPOPeerUDPPacket.parse(Data(hex: "03020000000500000011000a4300"))

        if case let .input(input) = oneByteInput.kind {
            XCTAssertEqual(input.compressedBitCount, 5)
            XCTAssertEqual(input.expectedBitPayloadByteCount, 1)
            XCTAssertEqual(input.encoded, oneByteInput.rawPayload)
        } else {
            XCTFail("Expected one-byte input packet")
        }

        if case let .input(input) = threeByteInput.kind {
            XCTAssertEqual(input.compressedBitCount, 17)
            XCTAssertEqual(input.expectedBitPayloadByteCount, 3)
            XCTAssertEqual(input.encoded, threeByteInput.rawPayload)
        } else {
            XCTFail("Expected three-byte input packet")
        }

        XCTAssertEqual(truncatedInput.kind, .binary(type: 3, payloadLength: 14))
    }

    private func makePlan() -> FightcadeGGPOServedHandshakePlan {
        FightcadeGGPOServedHandshakePlan(match: FightcadeMatchLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1234567890-42",
            playerID: 1,
            port: 7000,
            delay: 2,
            ranked: 0,
            token: nil
        ))
    }
}

private final class ScriptedServedTCPTransport: FightcadeGGPOTCPTransporting, @unchecked Sendable {
    private var receives: [Data]
    private(set) var sent: [Data] = []

    init(receives: [Data]) {
        self.receives = receives
    }

    func send(_ data: Data) async throws {
        sent.append(data)
    }

    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> Data {
        guard !receives.isEmpty else { throw POSIXError(.ETIMEDOUT) }
        return receives.removeFirst()
    }

    func close() {}
}

private func serverRecord(code: Int32, body: Data) -> Data {
    var data = Data()
    data.appendBigEndianUInt32(UInt32(body.count + 4))
    data.appendBigEndianUInt32(UInt32(bitPattern: code))
    data.append(body)
    return data
}

private func endpointNoticeBody(host: String, value1: UInt32, value2: UInt32) -> Data {
    var data = Data()
    data.appendGGPOString(host)
    data.appendBigEndianUInt32(value1)
    data.appendBigEndianUInt32(value2)
    return data
}

private func commandMessageBody(_ first: String, _ second: String, _ third: String) -> Data {
    var data = Data()
    data.appendGGPOString(first)
    data.appendGGPOString(second)
    data.appendGGPOString(third)
    return data
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

    static func concatenate(_ values: [Data]) -> Data {
        values.reduce(into: Data()) { result, value in result.append(value) }
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
