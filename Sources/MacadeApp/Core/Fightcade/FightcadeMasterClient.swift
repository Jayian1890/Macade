import Foundation

struct FightcadeMasterClient: Sendable {
    private let transportFactory: any FightcadeUDPTransportFactory
    private let holePuncher: FightcadeUDPHolePuncher
    private let fallbackRadius: Int
    private let diagnostics: FightcadeProxyDiagnostics?

    init(
        transportFactory: any FightcadeUDPTransportFactory = FightcadeBSDUDPTransportFactory(),
        holePuncher: FightcadeUDPHolePuncher = FightcadeUDPHolePuncher(),
        fallbackRadius: Int = 512,
        diagnostics: FightcadeProxyDiagnostics? = nil
    ) {
        self.transportFactory = transportFactory
        self.holePuncher = holePuncher
        self.fallbackRadius = fallbackRadius
        self.diagnostics = diagnostics
    }

    func establish(plan: FightcadeQuarkSessionPlan) async throws -> FightcadeHolePunchResult {
        let session = try await establishProxySession(plan: plan)
        defer { session.close() }
        return FightcadeHolePunchResult(punched: true, peer: session.peer, keepalivePayload: session.keepalivePayload)
    }

    func establishProxySession(plan: FightcadeQuarkSessionPlan) async throws -> FightcadeEstablishedNetplaySession {
        let transport = try makeInitialTransport(plan: plan)
        var shouldCloseOriginalTransport = true
        defer { if shouldCloseOriginalTransport { transport.close() } }

        diagnostics?.write("master register payload=\(plan.registrationPayload) endpoint=\(plan.master.host):\(plan.master.port)")
        try await transport.send(Data(plan.registrationPayload.utf8), to: plan.master)
        let (okData, _) = try await transport.receive(maximumBytes: plan.expectedOKPayload.utf8.count, timeout: 10)
        guard String(data: okData, encoding: .utf8) == plan.expectedOKPayload else {
            diagnostics?.write("master unexpected response=\(String(data: okData, encoding: .utf8) ?? "<binary>")")
            try await transport.send(Data(plan.usePortsPayload.utf8), to: plan.master)
            throw FightcadeMasterClientError.unexpectedMasterResponse
        }

        diagnostics?.write("master ok received")
        try await transport.send(Data(plan.acknowledgePayload.utf8), to: plan.master)
        let (peerData, fallback) = try await transport.receive(maximumBytes: 6, timeout: 25)
        let target = FightcadeMasterAddressParser.targetAddress(data: peerData, fallback: fallback)
        diagnostics?.write("master peer target=\(target.host):\(target.port) fallback=\(fallback.host):\(fallback.port)")
        let result = try await establishPeerPunch(transport: transport, target: target, plan: plan)
        if !result.punched {
            diagnostics?.write("peer punch failed; sending useports")
            try await transport.send(Data(plan.usePortsPayload.utf8), to: plan.master)
            result.transport.close()
            throw FightcadeMasterClientError.udpPunchFailed
        }

        if !result.usesOriginalTransport {
            transport.close()
            shouldCloseOriginalTransport = false
        }

        shouldCloseOriginalTransport = false
        diagnostics?.write("peer punch established endpoint=\(result.peer.host):\(result.peer.port)")
        return FightcadeEstablishedNetplaySession(
            peer: result.peer,
            transport: result.transport,
            keepalivePayload: result.keepalivePayload
        )
    }

    private func makeInitialTransport(plan: FightcadeQuarkSessionPlan) throws -> any FightcadeUDPTransporting {
        do {
            diagnostics?.write("trying initial UDP bind port=\(plan.localBindPort)")
            return try transportFactory.makeTransport(bindPort: plan.localBindPort)
        } catch {
            diagnostics?.write("initial UDP bind failed; using ephemeral port error=\(error)")
            return try transportFactory.makeTransport(bindPort: nil)
        }
    }

    private func establishPeerPunch(
        transport: any FightcadeUDPTransporting,
        target: FightcadeNetplayEndpoint,
        plan: FightcadeQuarkSessionPlan
    ) async throws -> FightcadeLiveHolePunchResult {
        var result = try await holePuncher.punch(transport: transport, peer: target, attempts: 8)
        if result.punched {
            return FightcadeLiveHolePunchResult(result: result, transport: transport, usesOriginalTransport: true)
        }

        result = try await punchFallbackCandidates(
            transport: transport,
            current: result,
            basePort: target.port,
            plan: plan,
            includeBasePort: false
        )
        if result.punched {
            return FightcadeLiveHolePunchResult(result: result, transport: transport, usesOriginalTransport: true)
        }

        if let fallback = try await punchBoundFallback(port: plan.restrictedNATFallbackPort, current: result, basePort: target.port, plan: plan) {
            return fallback
        }

        if let fallback = try await punchBoundFallback(port: plan.fixedFallbackPort, current: result, basePort: target.port, plan: plan) {
            return fallback
        }

        return FightcadeLiveHolePunchResult(result: result, transport: transport, usesOriginalTransport: true)
    }

    private func punchFallbackCandidates(
        transport: any FightcadeUDPTransporting,
        current: FightcadeHolePunchResult,
        basePort: Int,
        plan: FightcadeQuarkSessionPlan,
        includeBasePort: Bool
    ) async throws -> FightcadeHolePunchResult {
        guard fallbackRadius > 0 else { return current }
        var result = current
        let candidates = FightcadePortFallbacks.prioritizedCandidates(
            observedPort: current.peer.port,
            basePort: basePort,
            plan: plan,
            radius: fallbackRadius,
            includeBasePort: includeBasePort
        )
        diagnostics?.write("fallback candidates count=\(candidates.count) first=\(candidates.prefix(8).map(String.init).joined(separator: ","))")
        for port in candidates {
            result = try await holePuncher.punch(
                transport: transport,
                peer: FightcadeNetplayEndpoint(host: result.peer.host, port: port),
                attempts: 1,
                sleep: 0
            )
            if result.punched { break }
        }
        return result
    }

    private func punchBoundFallback(
        port: Int,
        current: FightcadeHolePunchResult,
        basePort: Int,
        plan: FightcadeQuarkSessionPlan
    ) async throws -> FightcadeLiveHolePunchResult? {
        guard let transport = try? transportFactory.makeTransport(bindPort: port) else {
            diagnostics?.write("bound fallback unavailable port=\(port)")
            return nil
        }
        var shouldCloseTransport = true
        defer { if shouldCloseTransport { transport.close() } }

        var result = try await holePuncher.punch(
            transport: transport,
            peer: FightcadeNetplayEndpoint(host: current.peer.host, port: port),
            attempts: 6
        )
        if result.punched {
            shouldCloseTransport = false
            return FightcadeLiveHolePunchResult(result: result, transport: transport, usesOriginalTransport: false)
        }

        result = try await punchFallbackCandidates(
            transport: transport,
            current: result,
            basePort: basePort,
            plan: plan,
            includeBasePort: true
        )
        if result.punched {
            shouldCloseTransport = false
            return FightcadeLiveHolePunchResult(result: result, transport: transport, usesOriginalTransport: false)
        }
        return nil
    }
}

private struct FightcadeLiveHolePunchResult: Sendable {
    let punched: Bool
    let peer: FightcadeNetplayEndpoint
    let transport: any FightcadeUDPTransporting
    let usesOriginalTransport: Bool
    let keepalivePayload: Data?

    init(result: FightcadeHolePunchResult, transport: any FightcadeUDPTransporting, usesOriginalTransport: Bool) {
        punched = result.punched
        peer = result.peer
        self.transport = transport
        self.usesOriginalTransport = usesOriginalTransport
        keepalivePayload = result.keepalivePayload
    }
}

enum FightcadeMasterClientError: Error, Equatable {
    case unexpectedMasterResponse
    case udpPunchFailed
}
