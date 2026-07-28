import Foundation
import Darwin

struct FightcadeGGPOCommandFrame: Equatable, Sendable {
    let sequence: UInt32
    let command: UInt32
    let payload: Data

    var encoded: Data {
        var data = Data()
        data.appendBigEndianUInt32(UInt32(payload.count + 8))
        data.appendBigEndianUInt32(sequence)
        data.appendBigEndianUInt32(command)
        data.append(payload)
        return data
    }

    static func initialNegotiation(sequence: UInt32 = 1) -> FightcadeGGPOCommandFrame {
        var payload = Data()
        payload.appendBigEndianUInt32(0)
        payload.appendBigEndianUInt32(29)
        payload.appendBigEndianUInt32(1)
        return FightcadeGGPOCommandFrame(sequence: sequence, command: 0, payload: payload)
    }
}

struct FightcadeGGPOTCPFrame: Equatable, Sendable {
    let sequence: UInt32
    let command: UInt32
    let payload: Data
}

struct FightcadeGGPOTCPFrameDecoder {
    enum DecodeError: Error, Equatable {
        case invalidLength(UInt32)
    }

    private var buffer = Data()

    mutating func append(_ data: Data) {
        buffer.append(data)
    }

    mutating func nextFrame() throws -> FightcadeGGPOTCPFrame? {
        guard buffer.count >= 4 else { return nil }
        let length = buffer.readBigEndianUInt32(at: 0)
        guard length >= 8 else { throw DecodeError.invalidLength(length) }
        let totalLength = Int(length) + 4
        guard buffer.count >= totalLength else { return nil }

        let sequence = buffer.readBigEndianUInt32(at: 4)
        let command = buffer.readBigEndianUInt32(at: 8)
        let payload = Data(buffer[12..<totalLength])
        buffer.removeSubrange(0..<totalLength)
        return FightcadeGGPOTCPFrame(sequence: sequence, command: command, payload: payload)
    }
}

struct FightcadeGGPOServerRecordFrame: Equatable, Sendable {
    let code: Int32
    let payload: Data
}

struct FightcadeGGPOServerRecordFrameDecoder {
    enum DecodeError: Error, Equatable {
        case invalidLength(UInt32)
    }

    private var buffer = Data()

    mutating func append(_ data: Data) {
        buffer.append(data)
    }

    mutating func nextFrame() throws -> FightcadeGGPOServerRecordFrame? {
        guard buffer.count >= 4 else { return nil }
        let length = buffer.readBigEndianUInt32(at: 0)
        guard length >= 4 else { throw DecodeError.invalidLength(length) }
        let totalLength = Int(length) + 4
        guard buffer.count >= totalLength else { return nil }

        let code = buffer.readBigEndianInt32(at: 4)
        let payload = Data(buffer[8..<totalLength])
        buffer.removeSubrange(0..<totalLength)
        return FightcadeGGPOServerRecordFrame(code: code, payload: payload)
    }
}

enum FightcadeGGPORawServerRecordCode: Int32, CaseIterable, Sendable {
    case streamedFrameBatch = -13
    case gameBuffer = -12
    case emptySignal = -11
    case integerSignal = -10
    case endpointNotice = -7
    case commandMessage = -8
}

struct FightcadeGGPOEndpointNoticeRecord: Equatable, Sendable {
    let host: String
    let value1: UInt32
    let value2: UInt32
}

enum FightcadeGGPORawServerRecordBody: Equatable, Sendable {
    case positiveResponse(sequence: Int32, payload: Data)
    case streamedFrameBatch(FightcadeGGPOStreamedFrameBatchEvent)
    case gameBuffer(FightcadeGGPOBlobEvent)
    case emptySignal(rawBody: Data)
    case integerSignal(FightcadeGGPOSingleIntegerEvent)
    case endpointNotice(FightcadeGGPOEndpointNoticeRecord)
    case commandMessage(FightcadeGGPOStringTripletEvent)
    case unknown(rawBody: Data)
}

struct FightcadeGGPORawServerRecord: Equatable, Sendable {
    let code: Int32
    let body: FightcadeGGPORawServerRecordBody

    init(frame: FightcadeGGPOServerRecordFrame) throws {
        code = frame.code
        switch FightcadeGGPORawServerRecordCode(rawValue: frame.code) {
        case .streamedFrameBatch:
            body = .streamedFrameBatch(try FightcadeGGPOEventBodyParser.parseStreamedFrameBatch(frame.payload))
        case .gameBuffer:
            body = .gameBuffer(try FightcadeGGPOEventBodyParser.parseBlob(frame.payload))
        case .emptySignal:
            body = .emptySignal(rawBody: frame.payload)
        case .integerSignal:
            body = .integerSignal(try FightcadeGGPOEventBodyParser.parseSingleInteger(frame.payload))
        case .endpointNotice:
            body = .endpointNotice(try FightcadeGGPOEventBodyParser.parseEndpointNotice(frame.payload))
        case .commandMessage:
            body = .commandMessage(try FightcadeGGPOEventBodyParser.parseStringTriplet(frame.payload))
        case nil where frame.code >= 0:
            body = .positiveResponse(sequence: frame.code, payload: frame.payload)
        case nil:
            body = .unknown(rawBody: frame.payload)
        }
    }
}

protocol FightcadeGGPOTCPTransporting: Sendable {
    func send(_ data: Data) async throws
    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> Data
    func close()
}

protocol FightcadeGGPOTCPTransportFactory: Sendable {
    func makeTransport(endpoint: FightcadeNetplayEndpoint) throws -> any FightcadeGGPOTCPTransporting
}

struct FightcadeBSDTCPTransportFactory: FightcadeGGPOTCPTransportFactory {
    func makeTransport(endpoint: FightcadeNetplayEndpoint) throws -> any FightcadeGGPOTCPTransporting {
        try FightcadeBSDTCPTransport(endpoint: endpoint)
    }
}

final class FightcadeBSDTCPTransport: FightcadeGGPOTCPTransporting, @unchecked Sendable {
    private let fd: Int32
    private let lock = NSLock()
    private var isClosed = false

    init(endpoint: FightcadeNetplayEndpoint) throws {
        fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
        guard fd >= 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
        var addr = try Self.resolve(endpoint)
        let connected = withUnsafePointer(to: &addr) {
            $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {
                Darwin.connect(fd, $0, socklen_t(MemoryLayout<sockaddr_in>.size))
            }
        }
        guard connected == 0 else {
            let error = POSIXError(.init(rawValue: errno) ?? .EIO)
            Darwin.close(fd)
            throw error
        }
    }

    init(connectedFileDescriptor fd: Int32) {
        self.fd = fd
    }

    deinit { close() }

    func send(_ data: Data) async throws {
        var sentCount = 0
        while sentCount < data.count {
            let sent = data.withUnsafeBytes { bytes in
                Darwin.send(fd, bytes.baseAddress?.advanced(by: sentCount), data.count - sentCount, 0)
            }
            guard sent > 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
            sentCount += sent
        }
    }

    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> Data {
        var tv = timeval(
            tv_sec: Int(timeout),
            tv_usec: suseconds_t((timeout.truncatingRemainder(dividingBy: 1)) * 1_000_000)
        )
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, socklen_t(MemoryLayout<timeval>.size))
        var buffer = [UInt8](repeating: 0, count: maximumBytes)
        let count = buffer.withUnsafeMutableBytes { bytes in
            recv(fd, bytes.baseAddress, maximumBytes, 0)
        }
        guard count > 0 else { throw POSIXError(.init(rawValue: errno) ?? .ECONNRESET) }
        return Data(buffer.prefix(count))
    }

    func close() {
        lock.withLock {
            guard !isClosed else { return }
            Darwin.close(fd)
            isClosed = true
        }
    }

    private static func resolve(_ endpoint: FightcadeNetplayEndpoint) throws -> sockaddr_in {
        var hints = addrinfo(
            ai_flags: AF_UNSPEC,
            ai_family: AF_INET,
            ai_socktype: SOCK_STREAM,
            ai_protocol: IPPROTO_TCP,
            ai_addrlen: 0,
            ai_canonname: nil,
            ai_addr: nil,
            ai_next: nil
        )
        var result: UnsafeMutablePointer<addrinfo>?
        let status = getaddrinfo(endpoint.host, String(endpoint.port), &hints, &result)
        guard status == 0, let result else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
        defer { freeaddrinfo(result) }
        return result.pointee.ai_addr.withMemoryRebound(to: sockaddr_in.self, capacity: 1) { $0.pointee }
    }
}

struct FightcadeGGPOHandshakeClient: Sendable {
    private let transport: any FightcadeGGPOTCPTransporting

    init(transport: any FightcadeGGPOTCPTransporting) {
        self.transport = transport
    }

    func sendInitialNegotiation(sequence: UInt32 = 1) async throws {
        try await transport.send(FightcadeGGPOCommandFrame.initialNegotiation(sequence: sequence).encoded)
    }

    func receiveFrame(maximumBytes: Int = 4096, timeout: TimeInterval = 10) async throws -> FightcadeGGPOTCPFrame {
        var decoder = FightcadeGGPOTCPFrameDecoder()
        while true {
            decoder.append(try await transport.receive(maximumBytes: maximumBytes, timeout: timeout))
            if let frame = try decoder.nextFrame() {
                return frame
            }
        }
    }

    func close() {
        transport.close()
    }
}

struct FightcadeGGPOMatchStartEvent: Equatable, Sendable {
    static let eventID: UInt32 = 8

    let match: String
    let value1: UInt32
    let value2: UInt32
}

enum FightcadeGGPOServerEventID: UInt32, CaseIterable, Sendable {
    case matchStart = 8
    case disconnect = 10
    case stringTripletWithInteger = 11
    case stringTriplet = 12
    case streamedFrameBatch = 14
    case blob = 15
    case integer = 16
    case event17 = 17
}

struct FightcadeGGPOStringTripletIntegerEvent: Equatable, Sendable {
    let string1: String
    let string2: String
    let string3: String
    let value: UInt32
}

struct FightcadeGGPOStringTripletEvent: Equatable, Sendable {
    let string1: String
    let string2: String
    let string3: String
}

struct FightcadeGGPOStreamedFrameBatchEvent: Equatable, Sendable {
    let frameSize: UInt32
    let frameCount: UInt32
    let frames: [Data]
    let trailingData: Data
}

struct FightcadeGGPOBlobEvent: Equatable, Sendable {
    let value: UInt32
    let blob: Data
}

struct FightcadeGGPOSingleIntegerEvent: Equatable, Sendable {
    let value: UInt32
}

enum FightcadeGGPOEventBody: Equatable, Sendable {
    case matchStart(FightcadeGGPOMatchStartEvent)
    case disconnect(rawBody: Data)
    case stringTripletWithInteger(FightcadeGGPOStringTripletIntegerEvent)
    case stringTriplet(FightcadeGGPOStringTripletEvent)
    case streamedFrameBatch(FightcadeGGPOStreamedFrameBatchEvent)
    case blob(FightcadeGGPOBlobEvent)
    case integer(FightcadeGGPOSingleIntegerEvent)
    case event17(rawBody: Data)
    case unknown(rawBody: Data)
}

struct FightcadeGGPOServerEvent: Equatable, Sendable {
    let sequence: UInt32
    let id: UInt32
    let body: FightcadeGGPOEventBody

    init(frame: FightcadeGGPOTCPFrame) throws {
        sequence = frame.sequence
        id = frame.command
        switch FightcadeGGPOServerEventID(rawValue: frame.command) {
        case .matchStart:
            body = .matchStart(try FightcadeGGPOEventBodyParser.parseMatchStart(frame.payload))
        case .disconnect:
            body = .disconnect(rawBody: frame.payload)
        case .stringTripletWithInteger:
            body = .stringTripletWithInteger(
                try FightcadeGGPOEventBodyParser.parseStringTripletInteger(frame.payload)
            )
        case .stringTriplet:
            body = .stringTriplet(try FightcadeGGPOEventBodyParser.parseStringTriplet(frame.payload))
        case .streamedFrameBatch:
            body = .streamedFrameBatch(try FightcadeGGPOEventBodyParser.parseStreamedFrameBatch(frame.payload))
        case .blob:
            body = .blob(try FightcadeGGPOEventBodyParser.parseBlob(frame.payload))
        case .integer:
            body = .integer(try FightcadeGGPOEventBodyParser.parseSingleInteger(frame.payload))
        case .event17:
            body = .event17(rawBody: frame.payload)
        case nil:
            body = .unknown(rawBody: frame.payload)
        }
    }
}

struct FightcadeGGPOEventBodyParser {
    enum ParseError: Error, Equatable {
        case truncated
        case invalidString
    }

    static func parseMatchStart(_ body: Data) throws -> FightcadeGGPOMatchStartEvent {
        var cursor = 0
        let match = try readString(from: body, cursor: &cursor)
        let value1 = try readUInt32(from: body, cursor: &cursor)
        let value2 = try readUInt32(from: body, cursor: &cursor)
        return FightcadeGGPOMatchStartEvent(match: match, value1: value1, value2: value2)
    }

    static func parseStringTripletInteger(_ body: Data) throws -> FightcadeGGPOStringTripletIntegerEvent {
        var cursor = 0
        return FightcadeGGPOStringTripletIntegerEvent(
            string1: try readString(from: body, cursor: &cursor),
            string2: try readString(from: body, cursor: &cursor),
            string3: try readString(from: body, cursor: &cursor),
            value: try readUInt32(from: body, cursor: &cursor)
        )
    }

    static func parseStringTriplet(_ body: Data) throws -> FightcadeGGPOStringTripletEvent {
        var cursor = 0
        return FightcadeGGPOStringTripletEvent(
            string1: try readString(from: body, cursor: &cursor),
            string2: try readString(from: body, cursor: &cursor),
            string3: try readString(from: body, cursor: &cursor)
        )
    }

    static func parseStreamedFrameBatch(_ body: Data) throws -> FightcadeGGPOStreamedFrameBatchEvent {
        var cursor = 0
        let frameSize = try readUInt32(from: body, cursor: &cursor)
        let frameCount = try readUInt32(from: body, cursor: &cursor)
        let size = Int(frameSize)
        let count = Int(frameCount)
        guard size == 0 || count <= Int.max / size else { throw ParseError.truncated }
        let byteCount = size * count
        guard cursor + byteCount <= body.count else { throw ParseError.truncated }

        let frames = (0..<count).map { index in
            let start = cursor + index * size
            return Data(body[start..<start + size])
        }
        cursor += byteCount
        return FightcadeGGPOStreamedFrameBatchEvent(
            frameSize: frameSize,
            frameCount: frameCount,
            frames: frames,
            trailingData: Data(body[cursor...])
        )
    }

    static func parseBlob(_ body: Data) throws -> FightcadeGGPOBlobEvent {
        var cursor = 0
        let value = try readUInt32(from: body, cursor: &cursor)
        return FightcadeGGPOBlobEvent(value: value, blob: Data(body[cursor...]))
    }

    static func parseSingleInteger(_ body: Data) throws -> FightcadeGGPOSingleIntegerEvent {
        var cursor = 0
        return FightcadeGGPOSingleIntegerEvent(value: try readUInt32(from: body, cursor: &cursor))
    }

    static func parseEndpointNotice(_ body: Data) throws -> FightcadeGGPOEndpointNoticeRecord {
        var cursor = 0
        return FightcadeGGPOEndpointNoticeRecord(
            host: try readString(from: body, cursor: &cursor),
            value1: try readUInt32(from: body, cursor: &cursor),
            value2: try readUInt32(from: body, cursor: &cursor)
        )
    }

    static func readUInt32(from data: Data, cursor: inout Int) throws -> UInt32 {
        guard cursor + 4 <= data.count else { throw ParseError.truncated }
        let value = data[cursor..<cursor + 4].reduce(UInt32(0)) { partial, byte in
            (partial << 8) | UInt32(byte)
        }
        cursor += 4
        return value
    }

    static func readString(from data: Data, cursor: inout Int) throws -> String {
        let length = Int(try readUInt32(from: data, cursor: &cursor))
        guard cursor + length <= data.count else { throw ParseError.truncated }
        let stringData = data[cursor..<cursor + length]
        cursor += length
        guard let value = String(data: stringData, encoding: .utf8) else {
            throw ParseError.invalidString
        }
        return value
    }
}

extension Data {
    mutating func appendBigEndianUInt32(_ value: UInt32) {
        append(UInt8((value >> 24) & 0xff))
        append(UInt8((value >> 16) & 0xff))
        append(UInt8((value >> 8) & 0xff))
        append(UInt8(value & 0xff))
    }

    func readBigEndianUInt32(at offset: Int) -> UInt32 {
        self[offset..<offset + 4].reduce(UInt32(0)) { partial, byte in
            (partial << 8) | UInt32(byte)
        }
    }

    func readBigEndianInt32(at offset: Int) -> Int32 {
        Int32(bitPattern: readBigEndianUInt32(at: offset))
    }
}
