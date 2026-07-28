import Foundation

struct FightcadeUDPProxyConfiguration: Equatable, Sendable {
    let peer: FightcadeNetplayEndpoint
    let localEmulatorPort: Int
    let maximumPacketBytes: Int
    let pollTimeout: TimeInterval

    init(
        peer: FightcadeNetplayEndpoint,
        localEmulatorPort: Int,
        maximumPacketBytes: Int = 16_384,
        pollTimeout: TimeInterval = 0.01
    ) {
        self.peer = peer
        self.localEmulatorPort = localEmulatorPort
        self.maximumPacketBytes = maximumPacketBytes
        self.pollTimeout = pollTimeout
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
        if let localPacket = try? await localTransport.receive(
            maximumBytes: configuration.maximumPacketBytes,
            timeout: configuration.pollTimeout
        ) {
            if shouldForward(localPacket.0) {
                setEmulatorEndpoint(localPacket.1)
                try await peerTransport.send(localPacket.0, to: configuration.peer)
                result.forwardedLocalPackets += 1
                localForwardLogCount += 1
                logPacket(prefix: "local->peer", count: localForwardLogCount, bytes: localPacket.0.count, endpoint: localPacket.1)
            } else {
                localFilterLogCount += 1
                logPacket(prefix: "local filtered", count: localFilterLogCount, bytes: localPacket.0.count, endpoint: localPacket.1)
            }
        }

        if let peerPacket = try? await peerTransport.receive(
            maximumBytes: configuration.maximumPacketBytes,
            timeout: configuration.pollTimeout
        ) {
            if peerPacket.1.host == configuration.peer.host, shouldForward(peerPacket.0) {
                try await localTransport.send(peerPacket.0, to: currentEmulatorEndpoint())
                result.forwardedPeerPackets += 1
                peerForwardLogCount += 1
                logPacket(prefix: "peer->local", count: peerForwardLogCount, bytes: peerPacket.0.count, endpoint: peerPacket.1)
            } else {
                peerFilterLogCount += 1
                logPacket(prefix: "peer filtered", count: peerFilterLogCount, bytes: peerPacket.0.count, endpoint: peerPacket.1)
            }
        }
        return result
    }

    func close() {
        diagnostics?.write("proxy close localForwarded=\(localForwardLogCount) peerForwarded=\(peerForwardLogCount) localFiltered=\(localFilterLogCount) peerFiltered=\(peerFilterLogCount)")
        peerTransport.close()
        localTransport.close()
        diagnostics?.close()
    }

    private func setEmulatorEndpoint(_ endpoint: FightcadeNetplayEndpoint) {
        lock.withLock { emulatorEndpoint = endpoint }
    }

    private func currentEmulatorEndpoint() -> FightcadeNetplayEndpoint {
        lock.withLock { emulatorEndpoint }
    }

    private func shouldForward(_ data: Data) -> Bool {
        !data.isEmpty
            && !data.containsASCII(" ok")
            && !data.containsASCII(" _")
    }

    private func logPacket(prefix: String, count: Int, bytes: Int, endpoint: FightcadeNetplayEndpoint) {
        guard count <= 12 || count % 120 == 0 else { return }
        diagnostics?.write("\(prefix) count=\(count) bytes=\(bytes) endpoint=\(endpoint.host):\(endpoint.port)")
    }
}

private extension Data {
    func containsASCII(_ text: String) -> Bool {
        range(of: Data(text.utf8)) != nil
    }
}
