import Darwin
import Foundation

struct FightcadeNetplayEndpoint: Equatable, Sendable {
    let host: String
    let port: Int
}

struct FightcadeQuarkSessionPlan: Equatable, Sendable {
    static let masterHost = "ggpo.fightcade.com"

    let quark: String
    let master: FightcadeNetplayEndpoint
    let localBindPort: Int
    let emulatorProxyPort: Int
    let restrictedNATFallbackPort: Int
    let fixedFallbackPort: Int

    init(match: FightcadeMatchLaunch, localBindPort: Int = 6006, emulatorProxyPort: Int = 7001) {
        quark = "\(match.quarkID).\(match.playerID)"
        master = FightcadeNetplayEndpoint(host: Self.masterHost, port: match.port)
        self.localBindPort = localBindPort
        self.emulatorProxyPort = emulatorProxyPort
        restrictedNATFallbackPort = Self.restrictedNATFallbackPort(quark: quark)
        fixedFallbackPort = 6004
    }

    var registrationPayload: String { "\(quark)/\(emulatorProxyPort)" }
    var expectedOKPayload: String { "ok \(quark)" }
    var acknowledgePayload: String { "ok" }
    var usePortsPayload: String { "useports/\(quark)" }

    static func restrictedNATFallbackPort(quark: String) -> Int {
        let suffix = quark.split(separator: "-", maxSplits: 1).dropFirst().first?
            .split(separator: ".", maxSplits: 1).first
        guard let suffix, let port = Int("4" + suffix) else {
            return 26004
        }
        return port
    }
}

struct FightcadeMasterAddressParser {
    enum ParseError: Error, Equatable {
        case invalidByteCount(Int)
        case invalidAddress
    }

    static func parsePeerAddress(_ data: Data) throws -> FightcadeNetplayEndpoint {
        guard data.count == 6 else {
            throw ParseError.invalidByteCount(data.count)
        }

        let bytes = [UInt8](data)
        let host = "\(bytes[0]).\(bytes[1]).\(bytes[2]).\(bytes[3])"
        let port = Int(UInt16(bytes[4]) | UInt16(bytes[5]) << 8)
        guard port > 0 else {
            throw ParseError.invalidAddress
        }

        return FightcadeNetplayEndpoint(host: host, port: port)
    }

    static func targetAddress(data: Data, fallback: FightcadeNetplayEndpoint) -> FightcadeNetplayEndpoint {
        if String(data: data, encoding: .utf8)?.hasPrefix("0.") == true {
            return fallback
        }

        return (try? parsePeerAddress(data)) ?? fallback
    }
}

struct FightcadeHolePunchMessage: Equatable, Sendable {
    let localToken: String
    let remoteToken: String?
    let remoteKnowsLocalToken: Bool

    var payload: String {
        var parts = [localToken, remoteToken ?? "_"]
        if remoteToken != nil {
            parts.append("ok")
        }
        return parts.joined(separator: " ")
    }

    static func parse(_ data: Data) -> FightcadeHolePunchMessage? {
        guard let text = String(data: data, encoding: .utf8) else {
            return nil
        }

        let parts = text.split(separator: " ").map(String.init)
        guard parts.count == 2 || parts.count == 3,
              parts[0].hasPrefix("0."),
              parts[1] == "_" || parts[1].hasPrefix("0."),
              parts.count == 2 || parts[2] == "ok" else {
            return nil
        }

        return FightcadeHolePunchMessage(
            localToken: parts[0],
            remoteToken: parts[0],
            remoteKnowsLocalToken: parts.count == 3 && parts[1].hasPrefix("0.")
        )
    }

    static func isWireMessage(_ data: Data) -> Bool {
        parse(data) != nil
    }
}

struct FightcadeHolePunchResult: Equatable, Sendable {
    let punched: Bool
    let peer: FightcadeNetplayEndpoint
    let keepalivePayload: Data?

    init(punched: Bool, peer: FightcadeNetplayEndpoint, keepalivePayload: Data? = nil) {
        self.punched = punched
        self.peer = peer
        self.keepalivePayload = keepalivePayload
    }
}

struct FightcadeEstablishedNetplaySession: Sendable {
    let peer: FightcadeNetplayEndpoint
    let transport: any FightcadeUDPTransporting
    let keepalivePayload: Data?

    func close() {
        transport.close()
    }
}

struct FightcadeUDPHolePuncher: Sendable {
    private let tokenProvider: @Sendable () -> String
    private let sleeper: @Sendable (TimeInterval) async -> Void

    init(
        tokenProvider: @escaping @Sendable () -> String = { String(Double.random(in: 0..<1)) },
        sleeper: @escaping @Sendable (TimeInterval) async -> Void = { interval in
            try? await Task.sleep(for: .seconds(interval))
        }
    ) {
        self.tokenProvider = tokenProvider
        self.sleeper = sleeper
    }

    func punch(
        transport: any FightcadeUDPTransporting,
        peer: FightcadeNetplayEndpoint,
        attempts: Int,
        sleep: TimeInterval = 0.5
    ) async throws -> FightcadeHolePunchResult {
        let localToken = tokenProvider()
        var remoteToken: String?
        var remoteKnowsLocalToken = false
        var target = peer
        var lastPayload: Data?

        for _ in 0..<attempts {
            if remoteToken != nil && remoteKnowsLocalToken {
                break
            }

            if let received = try? await transport.receive(maximumBytes: 1024, timeout: 0.01) {
                if received.1.host == target.host,
                   received.1.port != target.port,
                   ![7000, 7001, 7002].contains(received.1.port) {
                    target = received.1
                }

                if let message = FightcadeHolePunchMessage.parse(received.0) {
                    remoteToken = message.remoteToken ?? remoteToken
                    remoteKnowsLocalToken = message.remoteKnowsLocalToken
                }
            }

            let payload = FightcadeHolePunchMessage(
                localToken: localToken,
                remoteToken: remoteToken,
                remoteKnowsLocalToken: remoteKnowsLocalToken
            ).payload
            lastPayload = Data(payload.utf8)
            try await transport.send(lastPayload ?? Data(), to: target)
            await sleeper(sleep)
        }

        return FightcadeHolePunchResult(punched: remoteToken != nil, peer: target, keepalivePayload: lastPayload)
    }
}

protocol FightcadeUDPTransporting: Sendable {
    func send(_ data: Data, to endpoint: FightcadeNetplayEndpoint) async throws
    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> (Data, FightcadeNetplayEndpoint)
    func close()
}

protocol FightcadeUDPTransportFactory: Sendable {
    func makeTransport(bindPort: Int?) throws -> any FightcadeUDPTransporting
}

struct FightcadeBSDUDPTransportFactory: FightcadeUDPTransportFactory {
    func makeTransport(bindPort: Int?) throws -> any FightcadeUDPTransporting {
        try FightcadeBSDUDPTransport(bindPort: bindPort)
    }
}

final class FightcadeBSDUDPTransport: FightcadeUDPTransporting, @unchecked Sendable {
    private let fd: Int32
    private let lock = NSLock()
    private var isClosed = false

    init(bindPort: Int?) throws {
        fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
        guard fd >= 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }

        var reuse: Int32 = 1
        setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, socklen_t(MemoryLayout<Int32>.size))

        if let bindPort {
            var addr = sockaddr_in()
            addr.sin_len = UInt8(MemoryLayout<sockaddr_in>.size)
            addr.sin_family = sa_family_t(AF_INET)
            addr.sin_port = in_port_t(bindPort).bigEndian
            addr.sin_addr = in_addr(s_addr: INADDR_ANY)
            let result = withUnsafePointer(to: &addr) {
                $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {
                    Darwin.bind(fd, $0, socklen_t(MemoryLayout<sockaddr_in>.size))
                }
            }
            guard result == 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
        }
    }

    deinit { close() }

    func send(_ data: Data, to endpoint: FightcadeNetplayEndpoint) async throws {
        var addr = try resolve(endpoint)
        let sent = data.withUnsafeBytes { bytes in
            withUnsafePointer(to: &addr) {
                $0.withMemoryRebound(to: sockaddr.self, capacity: 1) {
                    sendto(fd, bytes.baseAddress, data.count, 0, $0, socklen_t(MemoryLayout<sockaddr_in>.size))
                }
            }
        }

        guard sent == data.count else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
    }

    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> (Data, FightcadeNetplayEndpoint) {
        var descriptor = pollfd(fd: fd, events: Int16(POLLIN), revents: 0)
        let milliseconds = max(0, Int((timeout * 1000).rounded(.up)))
        guard poll(&descriptor, 1, Int32(milliseconds)) > 0 else {
            throw POSIXError(.ETIMEDOUT)
        }

        var storage = sockaddr_storage()
        var storageLength = socklen_t(MemoryLayout<sockaddr_storage>.size)
        var buffer = [UInt8](repeating: 0, count: maximumBytes)
        let count = buffer.withUnsafeMutableBytes { bytes in
            withUnsafeMutablePointer(to: &storage) { storagePointer in
                storagePointer.withMemoryRebound(to: sockaddr.self, capacity: 1) { sockaddrPointer in
                    recvfrom(fd, bytes.baseAddress, maximumBytes, 0, sockaddrPointer, &storageLength)
                }
            }
        }

        guard count >= 0 else { throw POSIXError(.init(rawValue: errno) ?? .EIO) }
        let endpoint = try endpoint(from: storage)
        return (Data(buffer.prefix(count)), endpoint)
    }

    func close() {
        lock.withLock {
            guard !isClosed else { return }
            Darwin.close(fd)
            isClosed = true
        }
    }

    private func resolve(_ endpoint: FightcadeNetplayEndpoint) throws -> sockaddr_in {
        var hints = addrinfo(
            ai_flags: AF_UNSPEC,
            ai_family: AF_INET,
            ai_socktype: SOCK_DGRAM,
            ai_protocol: IPPROTO_UDP,
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

    private func endpoint(from storage: sockaddr_storage) throws -> FightcadeNetplayEndpoint {
        guard Int32(storage.ss_family) == AF_INET else { throw POSIXError(.EAFNOSUPPORT) }
        var copy = storage
        let addr = withUnsafePointer(to: &copy) {
            $0.withMemoryRebound(to: sockaddr_in.self, capacity: 1) { $0.pointee }
        }
        var ip = addr.sin_addr
        var buffer = [CChar](repeating: 0, count: Int(INET_ADDRSTRLEN))
        guard inet_ntop(AF_INET, &ip, &buffer, socklen_t(INET_ADDRSTRLEN)) != nil else {
            throw POSIXError(.init(rawValue: errno) ?? .EIO)
        }
        let host = String(decoding: buffer.prefix { $0 != 0 }.map(UInt8.init(bitPattern:)), as: UTF8.self)
        return FightcadeNetplayEndpoint(host: host, port: Int(UInt16(bigEndian: addr.sin_port)))
    }
}
