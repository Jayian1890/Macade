import Foundation
import Darwin

struct FightcadeGGPOServedHandshakePlan: Equatable, Sendable {
    let endpoint: FightcadeNetplayEndpoint
    let quark: String
    let playerID: Int
    let delay: Int
    let ranked: Int
    let localTCPBindPort: Int
    let registrationValue: UInt32
    let versionMarker: String

    init(
        match: FightcadeMatchLaunch,
        localTCPBindPort: Int = 6004,
        registrationValue: UInt32 = 6000,
        versionMarker: String = "V14"
    ) {
        endpoint = FightcadeNetplayEndpoint(host: FightcadeQuarkSessionPlan.masterHost, port: match.port)
        quark = "\(match.quarkID).\(match.playerID)"
        playerID = match.playerID
        delay = match.delay
        ranked = match.ranked
        self.localTCPBindPort = localTCPBindPort
        self.registrationValue = registrationValue
        self.versionMarker = versionMarker
    }

    var readyCommand: String { "C2,\(playerID),\(delay),\(ranked)" }
}

struct FightcadeGGPOServedCommandBuilder {
    static func registration(sequence: UInt32, quark: String, value: UInt32) -> FightcadeGGPOCommandFrame {
        var payload = Data()
        payload.appendGGPOString(quark)
        payload.appendBigEndianUInt32(value)
        return FightcadeGGPOCommandFrame(sequence: sequence, command: 11, payload: payload)
    }

    static func join(sequence: UInt32, quark: String) -> FightcadeGGPOCommandFrame {
        var payload = Data()
        payload.appendGGPOString(quark)
        return FightcadeGGPOCommandFrame(sequence: sequence, command: 12, payload: payload)
    }

    static func marker(sequence: UInt32, quark: String, value: String) -> FightcadeGGPOCommandFrame {
        var payload = Data()
        payload.appendGGPOString(quark)
        payload.appendGGPOString(value)
        return FightcadeGGPOCommandFrame(sequence: sequence, command: 15, payload: payload)
    }

    static func startupFrameBatch(
        sequence: UInt32,
        quark: String,
        frameCount: UInt32 = 60,
        inputSize: UInt32 = 10
    ) -> FightcadeGGPOCommandFrame {
        var payload = Data()
        payload.appendGGPOString(quark)
        payload.appendBigEndianUInt32(frameCount)
        payload.appendBigEndianUInt32(inputSize)
        payload.append(Data(repeating: 0, count: Int(frameCount * inputSize)))
        return FightcadeGGPOCommandFrame(sequence: sequence, command: 17, payload: payload)
    }

    static func startupCommands(plan: FightcadeGGPOServedHandshakePlan) -> [FightcadeGGPOCommandFrame] {
        [
            .initialNegotiation(sequence: 1),
            registration(sequence: 2, quark: plan.quark, value: plan.registrationValue),
            join(sequence: 3, quark: plan.quark),
            marker(sequence: 4, quark: plan.quark, value: plan.versionMarker),
            startupFrameBatch(sequence: 5, quark: plan.quark),
            marker(sequence: 6, quark: plan.quark, value: plan.readyCommand),
        ]
    }
}

struct FightcadeGGPOServedHandshakeResult: Equatable, Sendable {
    let records: [FightcadeGGPORawServerRecord]

    var endpointNotice: FightcadeGGPOEndpointNoticeRecord? {
        records.compactMap { record in
            if case let .endpointNotice(notice) = record.body { return notice }
            return nil
        }.last
    }

    var receivedReadyCommandEcho: Bool {
        records.contains { record in
            if case let .commandMessage(message) = record.body {
                return message.string2 == "Command"
            }
            return false
        }
    }
}

enum FightcadeGGPOServedHandshakeError: Error, Equatable {
    case noServerRecords
    case missingReadyCommandEcho
}

struct FightcadeGGPOServedHandshakeClient: Sendable {
    private let transport: any FightcadeGGPOTCPTransporting

    init(transport: any FightcadeGGPOTCPTransporting) {
        self.transport = transport
    }

    func runStartup(
        plan: FightcadeGGPOServedHandshakePlan,
        timeout: TimeInterval = 10,
        maximumRecords: Int = 32
    ) async throws -> FightcadeGGPOServedHandshakeResult {
        for command in FightcadeGGPOServedCommandBuilder.startupCommands(plan: plan) {
            try await transport.send(command.encoded)
        }

        let records = try await receiveRecords(timeout: timeout, maximumRecords: maximumRecords)
        guard !records.isEmpty else { throw FightcadeGGPOServedHandshakeError.noServerRecords }
        let result = FightcadeGGPOServedHandshakeResult(records: records)
        guard result.receivedReadyCommandEcho else {
            throw FightcadeGGPOServedHandshakeError.missingReadyCommandEcho
        }
        return result
    }

    func receiveRecords(timeout: TimeInterval, maximumRecords: Int) async throws -> [FightcadeGGPORawServerRecord] {
        var decoder = FightcadeGGPOServerRecordFrameDecoder()
        var records: [FightcadeGGPORawServerRecord] = []
        while records.count < maximumRecords {
            do {
                decoder.append(try await transport.receive(maximumBytes: 4096, timeout: timeout))
            } catch {
                if records.isEmpty { throw error }
                return records
            }
            while let frame = try decoder.nextFrame() {
                records.append(try FightcadeGGPORawServerRecord(frame: frame))
                if records.count == maximumRecords { break }
            }
            if records.contains(where: { record in
                if case let .commandMessage(message) = record.body { return message.string2 == "Command" }
                return false
            }) {
                break
            }
        }
        return records
    }

    func close() {
        transport.close()
    }
}

struct FightcadeBoundBSDTCPTransportFactory: Sendable {
    func makeTransport(
        endpoint: FightcadeNetplayEndpoint,
        localBindPort: Int?
    ) throws -> any FightcadeGGPOTCPTransporting {
        let fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
        guard fd >= 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }

        do {
            if let localBindPort {
                try bind(fd: fd, port: localBindPort)
            }
            var remote = try resolve(endpoint, socketType: SOCK_STREAM, protocolType: IPPROTO_TCP)
            let connected = withUnsafePointer(to: &remote) {
                $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {
                    Darwin.connect(fd, $0, socklen_t(MemoryLayout<sockaddr_in>.size))
                }
            }
            guard connected == 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
            return FightcadeBSDTCPTransport(connectedFileDescriptor: fd)
        } catch {
            Darwin.close(fd)
            throw error
        }
    }

    private func bind(fd: Int32, port: Int) throws {
        var reuse: Int32 = 1
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, socklen_t(MemoryLayout<Int32>.size))

        var addr = sockaddr_in()
        addr.sin_len = UInt8(MemoryLayout<sockaddr_in>.size)
        addr.sin_family = sa_family_t(AF_INET)
        addr.sin_port = in_port_t(port).bigEndian
        addr.sin_addr = in_addr(s_addr: INADDR_ANY)
        let result = withUnsafePointer(to: &addr) {
            $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {
                Darwin.bind(fd, $0, socklen_t(MemoryLayout<sockaddr_in>.size))
            }
        }
        guard result == 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
    }

    private func resolve(
        _ endpoint: FightcadeNetplayEndpoint,
        socketType: Int32,
        protocolType: Int32
    ) throws -> sockaddr_in {
        var hints = addrinfo(
            ai_flags: AF_UNSPEC,
            ai_family: AF_INET,
            ai_socktype: socketType,
            ai_protocol: protocolType,
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

extension Data {
    mutating func appendGGPOString(_ value: String) {
        appendBigEndianUInt32(UInt32(value.utf8.count))
        append(Data(value.utf8))
    }
}
