import Foundation

struct FightcadeUDPProxyConfiguration: Equatable, Sendable {
    let peer: FightcadeNetplayEndpoint
    let localEmulatorPort: Int
    let maximumPacketBytes: Int
    let pollTimeout: TimeInterval
    let maxPacketsPerStep: Int
    let keepalivePayload: Data?
    let keepaliveInterval: TimeInterval

    init(
        peer: FightcadeNetplayEndpoint,
        localEmulatorPort: Int,
        maximumPacketBytes: Int = 16_384,
        pollTimeout: TimeInterval = 0.01,
        maxPacketsPerStep: Int = 64,
        keepalivePayload: Data? = nil,
        keepaliveInterval: TimeInterval = 0.5
    ) {
        self.peer = peer
        self.localEmulatorPort = localEmulatorPort
        self.maximumPacketBytes = maximumPacketBytes
        self.pollTimeout = pollTimeout
        self.maxPacketsPerStep = maxPacketsPerStep
        self.keepalivePayload = keepalivePayload
        self.keepaliveInterval = keepaliveInterval
    }

    var initialEmulatorEndpoint: FightcadeNetplayEndpoint {
        FightcadeNetplayEndpoint(host: "127.0.0.1", port: localEmulatorPort)
    }
}

struct FightcadeUDPProxyStepResult: Equatable, Sendable {
    var forwardedLocalPackets = 0
    var forwardedPeerPackets = 0
}

final class FightcadeUDPProxy: @unchecked Sendable {
    private let peerTransport: any FightcadeUDPTransporting
    private let localTransport: any FightcadeUDPTransporting
    private let configuration: FightcadeUDPProxyConfiguration
    private let diagnostics: FightcadeProxyDiagnostics?
    private let lock = NSLock()
    private var emulatorEndpoint: FightcadeNetplayEndpoint
    private var localForwardLogCount = 0
    private var peerForwardLogCount = 0
    private var localFilterLogCount = 0
    private var peerFilterLogCount = 0
    private var keepaliveLogCount = 0
    private var localPacketTypeCounts: [String: Int] = [:]
    private var peerPacketTypeCounts: [String: Int] = [:]
    private var sawLocalGGPO = false
    private var sawPeerGGPO = false
    private var keepaliveStopped = false
    private var lastKeepaliveSentAt: Date?

    init(
        peerTransport: any FightcadeUDPTransporting,
        localTransport: any FightcadeUDPTransporting,
        configuration: FightcadeUDPProxyConfiguration,
        diagnostics: FightcadeProxyDiagnostics? = nil
    ) {
        self.peerTransport = peerTransport
        self.localTransport = localTransport
        self.configuration = configuration
        self.diagnostics = diagnostics
        emulatorEndpoint = configuration.initialEmulatorEndpoint
    }

    func run(maxConsecutiveFailures: Int = 4) async {
        diagnostics?.write("proxy run start peer=\(configuration.peer.host):\(configuration.peer.port) localPort=\(configuration.localEmulatorPort)")
        var failures = 0
        while !Task.isCancelled {
            do {
                _ = try await step()
                failures = 0
            } catch {
                failures += 1
                diagnostics?.write("proxy step failed failures=\(failures) error=\(error)")
                if failures >= maxConsecutiveFailures {
                    diagnostics?.write("proxy closing after repeated failures")
                    close()
                    return
                }
            }
        }
        diagnostics?.write("proxy task cancelled")
        close()
    }

    func step() async throws -> FightcadeUDPProxyStepResult {
        var result = FightcadeUDPProxyStepResult()
        result.forwardedLocalPackets += try await drainLocalPackets()
        result.forwardedPeerPackets += try await drainPeerPackets()
        try await sendKeepaliveIfNeeded()
        return result
    }

    func close() {
        diagnostics?.write("proxy close localForwarded=\(localForwardLogCount) peerForwarded=\(peerForwardLogCount) localFiltered=\(localFilterLogCount) peerFiltered=\(peerFilterLogCount) keepalives=\(keepaliveLogCount) localTypes=\(localPacketTypeCounts) peerTypes=\(peerPacketTypeCounts)")
        peerTransport.close()
        localTransport.close()
        diagnostics?.close()
    }

    private func drainLocalPackets() async throws -> Int {
        var forwarded = 0
        for index in 0..<configuration.maxPacketsPerStep {
            guard let packet = try? await localTransport.receive(
                maximumBytes: configuration.maximumPacketBytes,
                timeout: index == 0 ? configuration.pollTimeout : 0
            ) else { break }

            if shouldForward(packet.0) {
                setEmulatorEndpoint(packet.1)
                recordPacket(packet.0, fromPeer: false)
                try await peerTransport.send(packet.0, to: configuration.peer)
                forwarded += 1
                localForwardLogCount += 1
                logPacket(prefix: "local->peer", count: localForwardLogCount, bytes: packet.0.count, endpoint: packet.1)
            } else {
                localFilterLogCount += 1
                logPacket(prefix: "local filtered", count: localFilterLogCount, bytes: packet.0.count, endpoint: packet.1)
            }
        }
        return forwarded
    }

    private func drainPeerPackets() async throws -> Int {
        var forwarded = 0
        for index in 0..<configuration.maxPacketsPerStep {
            guard let packet = try? await peerTransport.receive(
                maximumBytes: configuration.maximumPacketBytes,
                timeout: index == 0 ? configuration.pollTimeout : 0
            ) else { break }

            if packet.1.host == configuration.peer.host, shouldForward(packet.0) {
                recordPacket(packet.0, fromPeer: true)
                try await localTransport.send(packet.0, to: currentEmulatorEndpoint())
                forwarded += 1
                peerForwardLogCount += 1
                logPacket(prefix: "peer->local", count: peerForwardLogCount, bytes: packet.0.count, endpoint: packet.1)
            } else {
                peerFilterLogCount += 1
                logPacket(prefix: "peer filtered", count: peerFilterLogCount, bytes: packet.0.count, endpoint: packet.1)
            }
        }
        return forwarded
    }

    private func sendKeepaliveIfNeeded() async throws {
        guard let payload = configuration.keepalivePayload, !keepaliveStopped else { return }
        if sawLocalGGPO && sawPeerGGPO {
            keepaliveStopped = true
            diagnostics?.write("proxy keepalive stopped after bidirectional GGPO traffic")
            return
        }
        let now = Date()
        if let lastKeepaliveSentAt, now.timeIntervalSince(lastKeepaliveSentAt) < configuration.keepaliveInterval {
            return
        }
        try await peerTransport.send(payload, to: configuration.peer)
        lastKeepaliveSentAt = now
        keepaliveLogCount += 1
        logPacket(prefix: "keepalive->peer", count: keepaliveLogCount, bytes: payload.count, endpoint: configuration.peer)
    }

    private func setEmulatorEndpoint(_ endpoint: FightcadeNetplayEndpoint) {
        lock.withLock { emulatorEndpoint = endpoint }
    }

    private func currentEmulatorEndpoint() -> FightcadeNetplayEndpoint {
        lock.withLock { emulatorEndpoint }
    }

    private func shouldForward(_ data: Data) -> Bool {
        !data.isEmpty && !FightcadeHolePunchMessage.isWireMessage(data)
    }

    private func recordPacket(_ data: Data, fromPeer: Bool) {
        let type = packetTypeName(data)
        if fromPeer {
            peerPacketTypeCounts[type, default: 0] += 1
            sawPeerGGPO = sawPeerGGPO || type != "binary" && type != "hole-punch"
        } else {
            localPacketTypeCounts[type, default: 0] += 1
            sawLocalGGPO = sawLocalGGPO || type != "binary" && type != "hole-punch"
        }
    }

    private func packetTypeName(_ data: Data) -> String {
        switch FightcadeGGPOPeerUDPPacket.parse(data).kind {
        case .holePunch:
            "hole-punch"
        case .syncRequest:
            "sync-request"
        case .syncReply:
            "sync-reply"
        case .input:
            "input"
        case .qualityReport:
            "quality-report"
        case .qualityReply:
            "quality-reply"
        case .binary:
            "binary"
        }
    }

    private func logPacket(prefix: String, count: Int, bytes: Int, endpoint: FightcadeNetplayEndpoint) {
        guard count <= 12 || count % 120 == 0 else { return }
        diagnostics?.write("\(prefix) count=\(count) bytes=\(bytes) endpoint=\(endpoint.host):\(endpoint.port)")
    }
}
