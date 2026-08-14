import Foundation

enum FightcadeEmbeddedNetplayPreparation: Sendable {
    case proxied(FightcadeEmbeddedProxySetup)
    case nativeUsePorts(FightcadeNativeUsePortsReason)

    var environment: [String: String] {
        guard case .proxied(let setup) = self else { return [:] }
        return setup.environment
    }
}

protocol FightcadeEmbeddedNetplayPreparing: Sendable {
    func prepare(for match: FightcadeMatchLaunch) async throws -> FightcadeEmbeddedNetplayPreparation
}

struct FightcadeEmbeddedProxySetup: Sendable {
    let environment: [String: String]
    private let localProxy: FightcadeLocalProxyTransport
    private let netplaySession: FightcadeEstablishedNetplaySession
    private let plan: FightcadeQuarkSessionPlan
    private let diagnostics: FightcadeProxyDiagnostics?

    fileprivate init(
        localProxy: FightcadeLocalProxyTransport,
        netplaySession: FightcadeEstablishedNetplaySession,
        plan: FightcadeQuarkSessionPlan,
        diagnostics: FightcadeProxyDiagnostics?
    ) {
        environment = [
            "MACADE_GGPO_PROXY_HOST": "127.0.0.1",
            "MACADE_GGPO_PROXY_PORT": String(plan.emulatorProxyPort),
            "MACADE_GGPO_TCP_REGISTER_PORT": String(plan.emulatorProxyPort)
        ]
        self.localProxy = localProxy
        self.netplaySession = netplaySession
        self.plan = plan
        self.diagnostics = diagnostics
    }

    func startTask(
        onFailure: (@MainActor @Sendable (String) -> Void)? = nil
    ) -> Task<Void, Never> {
        Task {
            defer { close() }
            diagnostics?.write("proxy task started localPort=\(localProxy.port) peer=\(netplaySession.peer.host):\(netplaySession.peer.port)")
            let proxy = FightcadeUDPProxy(
                peerTransport: netplaySession.transport,
                localTransport: localProxy.transport,
                configuration: FightcadeUDPProxyConfiguration(
                    peer: netplaySession.peer,
                    localEmulatorPort: plan.emulatorProxyPort,
                    keepalivePayload: netplaySession.keepalivePayload
                ),
                diagnostics: diagnostics
            )
            let result = await withTaskCancellationHandler {
                await proxy.run()
            } onCancel: {
                proxy.close()
            }
            if case .transportFailure(let message) = result, !Task.isCancelled {
                await onFailure?("Peer connection failed: \(message)")
            }
        }
    }

    func close() {
        diagnostics?.write("proxy setup close requested")
        netplaySession.close()
        localProxy.transport.close()
        diagnostics?.close()
    }
}

struct FightcadeEmbeddedProxyBootstrap: FightcadeEmbeddedNetplayPreparing {
    private let transportFactory: any FightcadeUDPTransportFactory

    init(transportFactory: any FightcadeUDPTransportFactory = FightcadeBSDUDPTransportFactory()) {
        self.transportFactory = transportFactory
    }

    func prepare(for match: FightcadeMatchLaunch) async throws -> FightcadeEmbeddedNetplayPreparation {
        let diagnostics = FightcadeProxyDiagnostics.make(match: match)
        let localProxy: FightcadeLocalProxyTransport
        do {
            localProxy = try makeLocalProxyTransport(diagnostics: diagnostics)
        } catch {
            diagnostics?.write("local proxy unavailable; selecting native useports error=\(error)")
            diagnostics?.close()
            return .nativeUsePorts(.localTransportUnavailable)
        }

        let plan = FightcadeQuarkSessionPlan(match: match, emulatorProxyPort: localProxy.port)
        await runPreflight(plan: plan, localProxyPort: localProxy.port, diagnostics: diagnostics)
        do {
            let outcome = try await FightcadeMasterClient(
                transportFactory: transportFactory,
                diagnostics: diagnostics
            ).establishProxySession(plan: plan)
            switch outcome {
            case .proxied(let netplaySession):
                diagnostics?.write("proxy route prepared host=127.0.0.1 port=\(plan.emulatorProxyPort)")
                return .proxied(FightcadeEmbeddedProxySetup(
                    localProxy: localProxy,
                    netplaySession: netplaySession,
                    plan: plan,
                    diagnostics: diagnostics
                ))
            case .nativeUsePorts(let reason):
                diagnostics?.write("native useports route prepared reason=\(reason.rawValue)")
                localProxy.transport.close()
                diagnostics?.close()
                return .nativeUsePorts(reason)
            }
        } catch is CancellationError {
            localProxy.transport.close()
            diagnostics?.close()
            throw CancellationError()
        } catch {
            diagnostics?.write("proxy preparation failed; selecting native useports error=\(error)")
            localProxy.transport.close()
            diagnostics?.close()
            return .nativeUsePorts(.udpPunchFailed)
        }
    }

    private func makeLocalProxyTransport(diagnostics: FightcadeProxyDiagnostics?) throws -> FightcadeLocalProxyTransport {
        for port in 7001...7009 {
            if let transport = try? transportFactory.makeTransport(bindPort: port) {
                diagnostics?.write("reserved local proxy UDP port=\(port)")
                return FightcadeLocalProxyTransport(port: port, transport: transport)
            }
            diagnostics?.write("local proxy UDP port unavailable port=\(port)")
        }
        throw POSIXError(.EADDRINUSE)
    }

    private func runPreflight(
        plan: FightcadeQuarkSessionPlan,
        localProxyPort: Int,
        diagnostics: FightcadeProxyDiagnostics?
    ) async {
        let report = await FightcadeNetplayPreflight().run(plan: plan, localProxyPort: localProxyPort)
        diagnostics?.write("preflight status=\(report.warnings.isEmpty ? "ok" : "warnings")")
        report.warnings.forEach { diagnostics?.write("preflight warning=\($0)") }
        guard FightcadeNetplayPreferences().automaticPortMappingEnabled else {
            diagnostics?.write("port mapping skipped; setting disabled")
            return
        }
        for result in await FightcadePortMappingService().mapUDP(ports: [plan.localBindPort, plan.fixedFallbackPort, 6000]) {
            diagnostics?.write("port mapping \(result.protocolName) port=\(result.port) mapped=\(result.mapped) message=\(result.message)")
        }
    }
}

private struct FightcadeLocalProxyTransport: Sendable {
    let port: Int
    let transport: any FightcadeUDPTransporting
}
