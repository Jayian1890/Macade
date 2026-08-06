import XCTest
import Darwin
@testable import Macade

final class FightcadeGGPOProtocolTests: XCTestCase {
    func testCommandFrameEncodesLengthSequenceCommandAndPayloadAsBigEndianUInt32() {
        let frame = FightcadeGGPOCommandFrame(
            sequence: 3,
            command: 20,
            payload: Data([0xaa, 0xbb])
        )

        XCTAssertEqual(frame.encoded, Data([
            0x00, 0x00, 0x00, 0x0a,
            0x00, 0x00, 0x00, 0x03,
            0x00, 0x00, 0x00, 0x14,
            0xaa, 0xbb
        ]))
    }

    func testInitialNegotiationMatchesRetDecCommandShape() {
        let frame = FightcadeGGPOCommandFrame.initialNegotiation()

        XCTAssertEqual(frame.sequence, 1)
        XCTAssertEqual(frame.command, 0)
        XCTAssertEqual(frame.encoded, Data([
            0x00, 0x00, 0x00, 0x14,
            0x00, 0x00, 0x00, 0x01,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x1d,
            0x00, 0x00, 0x00, 0x01
        ]))
    }

    func testTCPFrameDecoderWaitsForCompleteFrame() throws {
        let encoded = FightcadeGGPOCommandFrame(
            sequence: 9,
            command: 8,
            payload: Data([1, 2, 3])
        ).encoded
        var decoder = FightcadeGGPOTCPFrameDecoder()

        decoder.append(Data(encoded.prefix(6)))
        XCTAssertNil(try decoder.nextFrame())

        decoder.append(Data(encoded.dropFirst(6)))
        XCTAssertEqual(
            try decoder.nextFrame(),
            FightcadeGGPOTCPFrame(sequence: 9, command: 8, payload: Data([1, 2, 3]))
        )
        XCTAssertNil(try decoder.nextFrame())
    }

    func testTCPFrameDecoderRejectsInvalidLength() {
        var decoder = FightcadeGGPOTCPFrameDecoder()
        decoder.append(Data([0, 0, 0, 7, 0, 0, 0, 1, 0, 0, 0, 0]))

        XCTAssertThrowsError(try decoder.nextFrame()) { error in
            XCTAssertEqual(error as? FightcadeGGPOTCPFrameDecoder.DecodeError, .invalidLength(7))
        }
    }

    func testServerRecordDecoderReadsPositiveResponse() throws {
        var decoder = FightcadeGGPOServerRecordFrameDecoder()
        decoder.append(Data(hex: "000000080000000100000000"))

        let frame = try decoder.nextFrame()
        let record = try XCTUnwrap(frame).mapRawServerRecord()

        XCTAssertEqual(record.code, 1)
        XCTAssertEqual(record.body, .positiveResponse(sequence: 1, payload: Data([0, 0, 0, 0])))
    }

    func testServerRecordDecoderReadsSignedEndpointNoticeAcrossFragments() throws {
        let encoded = Data(hex: "00000019fffffff9000000093132372e302e302e3100001b5900000000")
        var decoder = FightcadeGGPOServerRecordFrameDecoder()

        decoder.append(Data(encoded.prefix(9)))
        XCTAssertNil(try decoder.nextFrame())

        decoder.append(Data(encoded.dropFirst(9)))
        let frame = try decoder.nextFrame()
        let record = try XCTUnwrap(frame).mapRawServerRecord()

        XCTAssertEqual(record.code, -7)
        XCTAssertEqual(record.body, .endpointNotice(.init(host: "127.0.0.1", value1: 7001, value2: 0)))
    }

    func testRawServerRecordParsesIntegerSignalAndCommandMessage() throws {
        let integerRecord = try FightcadeGGPOServerRecordFrame(
            code: -10,
            payload: Data([0, 0, 0, 1])
        ).mapRawServerRecord()
        var commandPayload = Data()
        commandPayload.appendLengthPrefixedString("match.1")
        commandPayload.appendLengthPrefixedString("Command")
        commandPayload.appendLengthPrefixedString("2,1,1,0")
        let commandRecord = try FightcadeGGPOServerRecordFrame(
            code: -8,
            payload: commandPayload
        ).mapRawServerRecord()

        XCTAssertEqual(integerRecord.body, .integerSignal(.init(value: 1)))
        XCTAssertEqual(commandRecord.body, .commandMessage(.init(
            string1: "match.1",
            string2: "Command",
            string3: "2,1,1,0"
        )))
    }

    func testRawServerRecordParsesGameBufferAndStreamedFrameBatch() throws {
        let gameBufferRecord = try FightcadeGGPOServerRecordFrame(
            code: -12,
            payload: Data([0, 0, 0, 4, 0x78, 0x01, 0xaa, 0xbb])
        ).mapRawServerRecord()
        let streamedBatchRecord = try FightcadeGGPOServerRecordFrame(
            code: -13,
            payload: Data([0, 0, 0, 2, 0, 0, 0, 2, 0xaa, 0xbb, 0xcc, 0xdd])
        ).mapRawServerRecord()

        XCTAssertEqual(gameBufferRecord.body, .gameBuffer(.init(value: 4, blob: Data([0x78, 0x01, 0xaa, 0xbb]))))
        XCTAssertEqual(streamedBatchRecord.body, .streamedFrameBatch(.init(
            frameSize: 2,
            frameCount: 2,
            frames: [Data([0xaa, 0xbb]), Data([0xcc, 0xdd])],
            trailingData: Data()
        )))
    }

    func testServerRecordDecoderRejectsInvalidLength() {
        var decoder = FightcadeGGPOServerRecordFrameDecoder()
        decoder.append(Data([0, 0, 0, 3, 0, 0, 0, 1]))

        XCTAssertThrowsError(try decoder.nextFrame()) { error in
            XCTAssertEqual(error as? FightcadeGGPOServerRecordFrameDecoder.DecodeError, .invalidLength(3))
        }
    }

    func testHandshakeClientSendsInitialNegotiationFrame() async throws {
        let transport = ScriptedTCPTransport(receives: [])
        let client = FightcadeGGPOHandshakeClient(transport: transport)

        try await client.sendInitialNegotiation()

        XCTAssertEqual(transport.sent, [FightcadeGGPOCommandFrame.initialNegotiation().encoded])
    }

    func testHandshakeClientReceivesFrameAcrossFragments() async throws {
        let encoded = FightcadeGGPOCommandFrame(
            sequence: 2,
            command: 16,
            payload: Data([0, 0, 0, 1])
        ).encoded
        let transport = ScriptedTCPTransport(receives: [Data(encoded.prefix(5)), Data(encoded.dropFirst(5))])
        let client = FightcadeGGPOHandshakeClient(transport: transport)

        let frame = try await client.receiveFrame()

        XCTAssertEqual(frame, FightcadeGGPOTCPFrame(sequence: 2, command: 16, payload: Data([0, 0, 0, 1])))
    }

    func testBSDTCPTransportSendsAndReceivesOverConnectedSocketPair() async throws {
        var descriptors = [Int32](repeating: -1, count: 2)
        XCTAssertEqual(socketpair(AF_UNIX, SOCK_STREAM, 0, &descriptors), 0)
        let clientTransport = FightcadeBSDTCPTransport(connectedFileDescriptor: descriptors[0])
        let peerTransport = FightcadeBSDTCPTransport(connectedFileDescriptor: descriptors[1])
        let client = FightcadeGGPOHandshakeClient(transport: clientTransport)
        defer {
            client.close()
            peerTransport.close()
        }

        try await client.sendInitialNegotiation()
        let received = try await peerTransport.receive(maximumBytes: 64, timeout: 1)
        XCTAssertEqual(received, FightcadeGGPOCommandFrame.initialNegotiation().encoded)

        let response = FightcadeGGPOCommandFrame(sequence: 2, command: 16, payload: Data([0, 0, 0, 1])).encoded
        try await peerTransport.send(response)
        let frame = try await client.receiveFrame(timeout: 1)
        XCTAssertEqual(frame, FightcadeGGPOTCPFrame(sequence: 2, command: 16, payload: Data([0, 0, 0, 1])))
    }

    func testMatchStartEventBodyParserReadsStringAndTwoBigEndianIntegers() throws {
        var body = Data()
        body.appendBigEndianUInt32(7)
        body.append(Data("sfiii3n".utf8))
        body.appendBigEndianUInt32(7000)
        body.appendBigEndianUInt32(1)

        let event = try FightcadeGGPOEventBodyParser.parseMatchStart(body)

        XCTAssertEqual(event, FightcadeGGPOMatchStartEvent(match: "sfiii3n", value1: 7000, value2: 1))
    }

    func testMatchStartEventBodyParserRejectsTruncatedData() {
        var body = Data()
        body.appendBigEndianUInt32(8)
        body.append(Data("sf".utf8))

        XCTAssertThrowsError(try FightcadeGGPOEventBodyParser.parseMatchStart(body)) { error in
            XCTAssertEqual(error as? FightcadeGGPOEventBodyParser.ParseError, .truncated)
        }
    }

    func testServerEventWrapsMatchStartFrame() throws {
        var body = Data()
        body.appendLengthPrefixedString("sfiii3n")
        body.appendBigEndianUInt32(7000)
        body.appendBigEndianUInt32(1)
        let frame = FightcadeGGPOTCPFrame(sequence: 4, command: 8, payload: body)

        let event = try FightcadeGGPOServerEvent(frame: frame)

        XCTAssertEqual(event.sequence, 4)
        XCTAssertEqual(event.id, 8)
        XCTAssertEqual(event.body, .matchStart(.init(match: "sfiii3n", value1: 7000, value2: 1)))
    }

    func testServerEventParsesStringTripletWithIntegerEvent() throws {
        var body = Data()
        body.appendLengthPrefixedString("player1")
        body.appendLengthPrefixedString("player2")
        body.appendLengthPrefixedString("sfiii3n")
        body.appendBigEndianUInt32(2)
        let frame = FightcadeGGPOTCPFrame(sequence: 5, command: 11, payload: body)

        let event = try FightcadeGGPOServerEvent(frame: frame)

        XCTAssertEqual(
            event.body,
            .stringTripletWithInteger(.init(string1: "player1", string2: "player2", string3: "sfiii3n", value: 2))
        )
    }

    func testServerEventParsesStringTripletEvent() throws {
        var body = Data()
        body.appendLengthPrefixedString("first")
        body.appendLengthPrefixedString("second")
        body.appendLengthPrefixedString("third")
        let frame = FightcadeGGPOTCPFrame(sequence: 6, command: 12, payload: body)

        let event = try FightcadeGGPOServerEvent(frame: frame)

        XCTAssertEqual(event.body, .stringTriplet(.init(string1: "first", string2: "second", string3: "third")))
    }

    func testServerEventParsesStreamedFrameBatchEvent() throws {
        var body = Data()
        body.appendBigEndianUInt32(3)
        body.appendBigEndianUInt32(2)
        body.append(Data([1, 2, 3, 4, 5, 6, 9]))
        let frame = FightcadeGGPOTCPFrame(sequence: 7, command: 14, payload: body)

        let event = try FightcadeGGPOServerEvent(frame: frame)

        XCTAssertEqual(
            event.body,
            .streamedFrameBatch(.init(
                frameSize: 3,
                frameCount: 2,
                frames: [Data([1, 2, 3]), Data([4, 5, 6])],
                trailingData: Data([9])
            ))
        )
    }

    func testStreamedFrameBatchParserRejectsTruncatedFrames() {
        var body = Data()
        body.appendBigEndianUInt32(4)
        body.appendBigEndianUInt32(2)
        body.append(Data([1, 2, 3]))

        XCTAssertThrowsError(try FightcadeGGPOEventBodyParser.parseStreamedFrameBatch(body)) { error in
            XCTAssertEqual(error as? FightcadeGGPOEventBodyParser.ParseError, .truncated)
        }
    }

    func testServerEventParsesBlobAndIntegerEvents() throws {
        var blobBody = Data()
        blobBody.appendBigEndianUInt32(123)
        blobBody.append(Data([0xaa, 0xbb]))
        let blobEvent = try FightcadeGGPOServerEvent(
            frame: FightcadeGGPOTCPFrame(sequence: 8, command: 15, payload: blobBody)
        )

        var integerBody = Data()
        integerBody.appendBigEndianUInt32(42)
        let integerEvent = try FightcadeGGPOServerEvent(
            frame: FightcadeGGPOTCPFrame(sequence: 9, command: 16, payload: integerBody)
        )

        XCTAssertEqual(blobEvent.body, .blob(.init(value: 123, blob: Data([0xaa, 0xbb]))))
        XCTAssertEqual(integerEvent.body, .integer(.init(value: 42)))
    }

    func testServerEventPreservesRawBodiesForNoFieldAndUnknownEvents() throws {
        let disconnect = try FightcadeGGPOServerEvent(
            frame: FightcadeGGPOTCPFrame(sequence: 10, command: 10, payload: Data([1]))
        )
        let event17 = try FightcadeGGPOServerEvent(
            frame: FightcadeGGPOTCPFrame(sequence: 11, command: 17, payload: Data([2]))
        )
        let unknown = try FightcadeGGPOServerEvent(
            frame: FightcadeGGPOTCPFrame(sequence: 12, command: 99, payload: Data([3]))
        )

        XCTAssertEqual(disconnect.body, .disconnect(rawBody: Data([1])))
        XCTAssertEqual(event17.body, .event17(rawBody: Data([2])))
        XCTAssertEqual(unknown.body, .unknown(rawBody: Data([3])))
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

    mutating func appendLengthPrefixedString(_ value: String) {
        appendBigEndianUInt32(UInt32(value.utf8.count))
        append(Data(value.utf8))
    }
}

private extension FightcadeGGPOServerRecordFrame {
    func mapRawServerRecord() throws -> FightcadeGGPORawServerRecord {
        try FightcadeGGPORawServerRecord(frame: self)
    }
}

private final class ScriptedTCPTransport: FightcadeGGPOTCPTransporting, @unchecked Sendable {
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
