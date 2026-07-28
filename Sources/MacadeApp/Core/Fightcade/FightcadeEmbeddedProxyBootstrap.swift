import Foundation

struct FightcadeEmbeddedProxySetup: Sendable {
    let environment: [String: String]
    private let localProxy: FightcadeLocalProxyTransport
    private let plan: FightcadeQuarkSessionPlan
    private let diagnostics: FightcadeProxyDiagnostics?

    fileprivate init(
        environment: [String: String],
        localProxy: FightcadeLocalProxyTransport,
        plan: FightcadeQuarkSessionPlan,
        diagnostics: FightcadeProxyDiagnostics?
    ) {
        self.environment = environment
        self.localProxy = localProxy
        self.plan = plan
        self.diagnostics = diagnostics
    }

    func startTask() -> Task<Void, Never> {
        Task {
            diagnostics?.write("proxy task started localPort=\(localProxy.port) master=\(plan.master.host):\(plan.master.port)")
            do {
                let netplaySession = try await Task.detached {
                    try await FightcadeMasterClient().establishProxySession(plan: plan)
                }.value
                diagnostics?.write("master punch established peer=\(netplaySession.peer.host):\(netplaySession.peer.port)")
                let proxy = FightcadeUDPProxy(
                    peerTransport: netplaySession.transport,
                    localTransport: localProxy.transport,
                    configuration: FightcadeUDPProxyConfiguration(
                        peer: netplaySession.peer,
                        localEmulatorPort: plan.emulatorProxyPort
                    ),
                    diagnostics: diagnostics
                )
                await proxy.run()
            } catch {
                diagnostics?.write("proxy task failed before run error=\(error)")
                localProxy.transport.close()
                diagnostics?.close()
            }
        }
    }

    func close() {
        diagnostics?.write("proxy setup close requested")
        localProxy.transport.close()
        diagnostics?.close()
    }
}

struct FightcadeEmbeddedProxyBootstrap: Sendable {
    private static let proxyHost = "127.0.0.1"

    func makeProxy(for match: FightcadeMatchLaunch) throws -> FightcadeEmbeddedProxySetup {
        let diagnostics = FightcadeProxyDiagnostics.make(match: match)
        let localProxy = try makeLocalProxyTransport(diagnostics: diagnostics)
        let plan = FightcadeQuarkSessionPlan(match: match, emulatorProxyPort: localProxy.port)
        diagnostics?.write("proxy environment prepared host=\(Self.proxyHost) port=\(plan.emulatorProxyPort)")
        return FightcadeEmbeddedProxySetup(
            environment: [
                "MACADE_GGPO_PROXY_HOST": Self.proxyHost,
                "MACADE_GGPO_PROXY_PORT": String(plan.emulatorProxyPort),
                "MACADE_GGPO_TCP_REGISTER_PORT": String(plan.emulatorProxyPort)
            ],
            localProxy: localProxy,
            plan: plan,
            diagnostics: diagnostics
        )
    }

    private func makeLocalProxyTransport(diagnostics: FightcadeProxyDiagnostics?) throws -> FightcadeLocalProxyTransport {
        let factory = FightcadeBSDUDPTransportFactory()
        for port in 7001...7009 {
            if let transport = try? factory.makeTransport(bindPort: port) {
                diagnostics?.write("reserved local proxy UDP port=\(port)")
                return FightcadeLocalProxyTransport(port: port, transport: transport)
            }
            diagnostics?.write("local proxy UDP port unavailable port=\(port)")
        }
        diagnostics?.write("all local proxy UDP ports unavailable")
        throw POSIXError(.EADDRINUSE)
    }
}

private struct FightcadeLocalProxyTransport: Sendable {
    let port: Int
    let transport: any FightcadeUDPTransporting
}
