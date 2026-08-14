import Foundation

enum FightcadeMasterConnectionOutcome: Sendable {
    case proxied(FightcadeEstablishedNetplaySession)
    case nativeUsePorts(FightcadeNativeUsePortsReason)
}

enum FightcadeNativeUsePortsReason: String, Equatable, Sendable {
    case localTransportUnavailable
    case registrationSendFailed
    case masterResponseTimeout
    case unexpectedMasterResponse
    case acknowledgeFailed
    case peerAddressTimeout
    case peerAddressFailed
    case udpPunchFailed
}

struct FightcadeMasterClient: Sendable {
    private let transportFactory: any FightcadeUDPTransportFactory
    private let holePuncher: FightcadeUDPHolePuncher
    private let diagnostics: FightcadeProxyDiagnostics?

    init(
        transportFactory: any FightcadeUDPTransportFactory = FightcadeBSDUDPTransportFactory(),
        holePuncher: FightcadeUDPHolePuncher = FightcadeUDPHolePuncher(),
        diagnostics: FightcadeProxyDiagnostics? = nil
    ) {
        self.transportFactory = transportFactory
        self.holePuncher = holePuncher
        self.diagnostics = diagnostics
    }

    func establishProxySession(plan: FightcadeQuarkSessionPlan) async throws -> FightcadeMasterConnectionOutcome {
        let transport: any FightcadeUDPTransporting
        do {
            transport = try makeInitialTransport(plan: plan)
        } catch {
            diagnostics?.write("initial UDP transport unavailable; selecting native useports error=\(error)")
            return .nativeUsePorts(.localTransportUnavailable)
        }

        var shouldCloseOriginalTransport = true
        defer { if shouldCloseOriginalTransport { transport.close() } }

        let registration = try await register(transport: transport, plan: plan)
        guard case .registered = registration else {
            let reason = registration.usePortsReason ?? .unexpectedMasterResponse
            await sendUsePorts(transport: transport, plan: plan, reason: reason)
            return .nativeUsePorts(reason)
        }

        diagnostics?.write("master ok received")
        do {
            try await transport.send(Data(plan.acknowledgePayload.utf8), to: plan.master)
        } catch is CancellationError {
            throw CancellationError()
        } catch {
            diagnostics?.write("master acknowledge failed error=\(error)")
            await sendUsePorts(transport: transport, plan: plan, reason: .acknowledgeFailed)
            return .nativeUsePorts(.acknowledgeFailed)
        }

        let peerData: Data
        let source: FightcadeNetplayEndpoint
        do {
            (peerData, source) = try await transport.receive(maximumBytes: 6, timeout: 25)
        } catch is CancellationError {
            throw CancellationError()
        } catch {
            let reason: FightcadeNativeUsePortsReason = isTimeout(error) ? .peerAddressTimeout : .peerAddressFailed
            diagnostics?.write("master peer address unavailable reason=\(reason.rawValue) error=\(error)")
            await sendUsePorts(transport: transport, plan: plan, reason: reason)
            return .nativeUsePorts(reason)
        }

        let target = FightcadeMasterAddressParser.targetAddress(data: peerData, fallback: source)
        let ignoredEndpoint = target == source ? nil : source
        diagnostics?.write("master peer target=\(target.host):\(target.port) source=\(source.host):\(source.port)")
        let result = try await establishPeerPunch(
            transport: transport,
            target: target,
            ignoredEndpoint: ignoredEndpoint,
            plan: plan
        )
        guard result.punched else {
            diagnostics?.write("peer punch failed; selecting native useports")
            await sendUsePorts(transport: transport, plan: plan, reason: .udpPunchFailed)
            return .nativeUsePorts(.udpPunchFailed)
        }

        if !result.usesOriginalTransport {
            transport.close()
        }
        shouldCloseOriginalTransport = false
        diagnostics?.write("peer punch established endpoint=\(result.peer.host):\(result.peer.port)")
        return .proxied(FightcadeEstablishedNetplaySession(
            peer: result.peer,
            transport: result.transport,
            keepalivePayload: result.keepalivePayload
        ))
    }

    private func register(
        transport: any FightcadeUDPTransporting,
        plan: FightcadeQuarkSessionPlan
    ) async throws -> FightcadeMasterRegistrationResult {
        for attempt in 1...2 {
            try Task.checkCancellation()
            diagnostics?.write(
                "master register attempt=\(attempt) payload=\(plan.registrationPayload) endpoint=\(plan.master.host):\(plan.master.port)"
            )
            do {
                try await transport.send(Data(plan.registrationPayload.utf8), to: plan.master)
            } catch is CancellationError {
                throw CancellationError()
            } catch {
                diagnostics?.write("master registration send failed error=\(error)")
                return .usePorts(.registrationSendFailed)
            }

            do {
                let (data, _) = try await transport.receive(
                    maximumBytes: plan.expectedOKPayload.utf8.count,
                    timeout: 10
                )
                guard String(data: data, encoding: .utf8) == plan.expectedOKPayload else {
                    diagnostics?.write("master unexpected response=\(String(data: data, encoding: .utf8) ?? "<binary>")")
                    return .usePorts(.unexpectedMasterResponse)
                }
                return .registered
            } catch is CancellationError {
                throw CancellationError()
            } catch where attempt == 1 && isTimeout(error) {
                diagnostics?.write("master response timed out; retrying registration")
            } catch {
                diagnostics?.write("master response failed error=\(error)")
                return .usePorts(isTimeout(error) ? .masterResponseTimeout : .unexpectedMasterResponse)
            }
        }
        return .usePorts(.masterResponseTimeout)
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
        ignoredEndpoint: FightcadeNetplayEndpoint?,
        plan: FightcadeQuarkSessionPlan
    ) async throws -> FightcadeLiveHolePunchResult {
        let direct = try await holePuncher.punch(
            transport: transport,
            peer: target,
            attempts: 10,
            ignoredEndpoint: ignoredEndpoint
        )
        if direct.punched {
            return FightcadeLiveHolePunchResult(result: direct, transport: transport, usesOriginalTransport: true)
        }

        guard let fallbackTransport = try? transportFactory.makeTransport(bindPort: plan.fixedFallbackPort) else {
            diagnostics?.write("fresh socket fallback unavailable localPort=\(plan.fixedFallbackPort)")
            return FightcadeLiveHolePunchResult(result: direct, transport: transport, usesOriginalTransport: true)
        }
        var shouldCloseFallback = true
        defer { if shouldCloseFallback { fallbackTransport.close() } }

        diagnostics?.write("trying fresh socket fallback localPort=\(plan.fixedFallbackPort) remotePort=\(plan.fixedFallbackPort)")
        let fallback = try await holePuncher.punch(
            transport: fallbackTransport,
            peer: FightcadeNetplayEndpoint(host: direct.peer.host, port: plan.fixedFallbackPort),
            attempts: 10,
            ignoredEndpoint: ignoredEndpoint
        )
        guard fallback.punched else {
            return FightcadeLiveHolePunchResult(result: fallback, transport: transport, usesOriginalTransport: true)
        }

        shouldCloseFallback = false
        return FightcadeLiveHolePunchResult(result: fallback, transport: fallbackTransport, usesOriginalTransport: false)
    }

    private func sendUsePorts(
        transport: any FightcadeUDPTransporting,
        plan: FightcadeQuarkSessionPlan,
        reason: FightcadeNativeUsePortsReason
    ) async {
        guard !Task.isCancelled else { return }
        diagnostics?.write("master useports reason=\(reason.rawValue) payload=\(plan.usePortsPayload)")
        do {
            try await transport.send(Data(plan.usePortsPayload.utf8), to: plan.master)
        } catch {
            diagnostics?.write("master useports send failed error=\(error)")
        }
    }

    private func isTimeout(_ error: Error) -> Bool {
        (error as? POSIXError)?.code == .ETIMEDOUT
    }
}

private enum FightcadeMasterRegistrationResult {
    case registered
    case usePorts(FightcadeNativeUsePortsReason)

    var usePortsReason: FightcadeNativeUsePortsReason? {
        if case .usePorts(let reason) = self { return reason }
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
