import Foundation
import XCTest
@testable import Macade

final class FightcadeNetplaySessionTests: XCTestCase {
    func testQuarkSessionPlanBuildsMasterPayloads() {
        let match = FightcadeMatchLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1234567890-42",
            playerID: 1,
            port: 7000,
            delay: 2,
            ranked: 0,
            token: "secret"
        )

        let plan = FightcadeQuarkSessionPlan(match: match)

        XCTAssertEqual(plan.master, FightcadeNetplayEndpoint(host: "ggpo.fightcade.com", port: 7000))
        XCTAssertEqual(plan.quark, "1234567890-42.1")
        XCTAssertEqual(plan.registrationPayload, "1234567890-42.1/7001")
        XCTAssertEqual(plan.expectedOKPayload, "ok 1234567890-42.1")
        XCTAssertEqual(plan.acknowledgePayload, "ok")
        XCTAssertEqual(plan.usePortsPayload, "useports/1234567890-42.1")
        XCTAssertEqual(plan.localBindPort, 6006)
        XCTAssertEqual(plan.fixedFallbackPort, 6004)
    }

    func testMasterAddressParserUsesWindowsNativeLittleEndianPort() throws {
        let data = Data([192, 0, 2, 24, 0x5c, 0x1b])

        let endpoint = try FightcadeMasterAddressParser.parsePeerAddress(data)

        XCTAssertEqual(endpoint, FightcadeNetplayEndpoint(host: "192.0.2.24", port: 7004))
    }

    func testMasterAddressParserFallsBackWhenDataStartsWithZeroDot() {
        let fallback = FightcadeNetplayEndpoint(host: "203.0.113.9", port: 6006)

        let endpoint = FightcadeMasterAddressParser.targetAddress(data: Data("0.".utf8), fallback: fallback)

        XCTAssertEqual(endpoint, fallback)
    }

    func testHolePunchPayloadMatchesFightcadeTokenExchange() {
        let initial = FightcadeHolePunchMessage(localToken: "0.123", remoteToken: nil, remoteKnowsLocalToken: false)
        let acknowledged = FightcadeHolePunchMessage(localToken: "0.123", remoteToken: "0.456", remoteKnowsLocalToken: true)

        XCTAssertEqual(initial.payload, "0.123 _")
        XCTAssertEqual(acknowledged.payload, "0.123 0.456 ok")
        XCTAssertEqual(FightcadeHolePunchMessage.parse(Data("0.456 _".utf8))?.remoteToken, "0.456")
        let parsed = FightcadeHolePunchMessage.parse(Data("0.456 0.123 ok".utf8))
        XCTAssertEqual(parsed?.remoteKnowsLocalToken, true)
        XCTAssertEqual(parsed?.acknowledgedToken, "0.123")
    }

    func testHolePuncherRejectsAcknowledgmentForAnotherToken() async throws {
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006)
        let transport = ScriptedUDPTransport(receives: [
            (Data("0.456 0.999 ok".utf8), peer)
        ])
        let puncher = FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in })

        let result = try await puncher.punch(transport: transport, peer: peer, attempts: 1, sleep: 0)

        XCTAssertFalse(result.punched)
        XCTAssertNil(result.keepalivePayload)
        XCTAssertEqual(transport.sent.map(\.0), [Data("0.123 0.456 ok".utf8)])
    }

    func testHolePuncherIgnoresMasterPacketsDuringPeerExchange() async throws {
        let master = FightcadeNetplayEndpoint(host: "203.0.113.1", port: 7000)
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006)
        let transport = ScriptedUDPTransport(receives: [
            (Data("0.456 0.123 ok".utf8), master),
            (Data("0.456 0.123 ok".utf8), peer)
        ])
        let puncher = FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in })

        let result = try await puncher.punch(
            transport: transport,
            peer: peer,
            attempts: 2,
            sleep: 0,
            ignoredEndpoint: master
        )

        XCTAssertTrue(result.punched)
        XCTAssertEqual(result.peer, peer)
        XCTAssertEqual(transport.sent.map(\.0), [
            Data("0.123 _".utf8),
            Data("0.123 0.456 ok".utf8)
        ])
    }

    func testHolePuncherSendsTokenExchangeAndUpdatesSymmetricPort() async throws {
        let transport = ScriptedUDPTransport(receives: [
            (Data("0.456 _".utf8), FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)),
            (Data("0.456 0.123 ok".utf8), FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200))
        ])
        let puncher = FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in })

        let result = try await puncher.punch(
            transport: transport,
            peer: FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006),
            attempts: 2,
            sleep: 0
        )

        XCTAssertEqual(result, FightcadeHolePunchResult(
            punched: true,
            peer: FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200),
            keepalivePayload: Data("0.123 0.456 ok".utf8)
        ))
        XCTAssertEqual(transport.sent.map(\.0).map { String(data: $0, encoding: .utf8) }, [
            "0.123 0.456 ok",
            "0.123 0.456 ok"
        ])
        XCTAssertEqual(transport.sent.map(\.1), Array(
            repeating: FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200),
            count: 2
        ))
    }

    func testMasterClientSendsUsePortsAndSelectsNativeRouteWhenPunchingFails() async throws {
        let match = FightcadeMatchLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1234567890-42",
            playerID: 0,
            port: 7000,
            delay: 2,
            ranked: 0,
            token: nil
        )
        let plan = FightcadeQuarkSessionPlan(match: match)
        let transport = ScriptedUDPTransport(receives: [
            (Data(plan.expectedOKPayload.utf8), plan.master),
            (Data([203, 0, 113, 8, 0x76, 0x17]), FightcadeNetplayEndpoint(host: "203.0.113.8", port: 6006))
        ])
        let fixed = ScriptedUDPTransport(receives: [])
        let factory = QueueingUDPTransportFactory(transports: [transport, fixed])
        let client = FightcadeMasterClient(
            transportFactory: factory,
            holePuncher: FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in })
        )

        let outcome = try await client.establishProxySession(plan: plan)
        guard case .nativeUsePorts(let reason) = outcome else {
            return XCTFail("Expected native useports route")
        }
        XCTAssertEqual(reason, .udpPunchFailed)

        let expectedPayloads = [plan.registrationPayload, plan.acknowledgePayload]
            + Array(repeating: "0.123 _", count: 10)
            + [plan.usePortsPayload]
        XCTAssertEqual(transport.sent.map(\.0).compactMap { String(data: $0, encoding: .utf8) }, expectedPayloads)
        XCTAssertEqual(fixed.sent.map(\.0).compactMap { String(data: $0, encoding: .utf8) }, Array(repeating: "0.123 _", count: 10))
        XCTAssertEqual(factory.bindPorts, [plan.localBindPort, plan.fixedFallbackPort])
    }

    func testMasterClientRetriesRegistrationOnceAfterTimeout() async throws {
        let plan = FightcadeQuarkSessionPlan(match: makeMatch(quarkID: "1234567890-42"))
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006)
        let transport = ScriptedUDPTransport(
            receives: [
                (Data(plan.expectedOKPayload.utf8), plan.master),
                (Data([198, 51, 100, 7, 0x76, 0x17]), plan.master),
                (Data("0.456 _".utf8), peer),
                (Data("0.456 0.123 ok".utf8), peer)
            ],
            timeoutReceiveCalls: [1]
        )
        let client = FightcadeMasterClient(
            transportFactory: ScriptedUDPTransportFactory(transport: transport),
            holePuncher: FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in })
        )

        let outcome = try await client.establishProxySession(plan: plan)
        guard case .proxied(let session) = outcome else {
            return XCTFail("Expected proxied session")
        }
        defer { session.close() }

        XCTAssertEqual(transport.sent.prefix(2).map(\.0), [
            Data(plan.registrationPayload.utf8),
            Data(plan.registrationPayload.utf8)
        ])
        XCTAssertEqual(session.peer, peer)
    }

    func testMasterClientFreshSocketFallbackUsesLocalAndRemotePort6004() async throws {
        let match = FightcadeMatchLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: "1234567890-6042",
            playerID: 0,
            port: 7000,
            delay: 2,
            ranked: 0,
            token: nil
        )
        let plan = FightcadeQuarkSessionPlan(match: match)
        let initial = ScriptedUDPTransport(receives: [
            (Data(plan.expectedOKPayload.utf8), plan.master),
            (Data([198, 51, 100, 7, 0x5c, 0x1b]), FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006))
        ])
        let fixed = ScriptedUDPTransport(receives: [])
        let factory = QueueingUDPTransportFactory(transports: [initial, fixed])
        let client = FightcadeMasterClient(
            transportFactory: factory,
            holePuncher: FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in })
        )

        let outcome = try await client.establishProxySession(plan: plan)
        guard case .nativeUsePorts(let reason) = outcome else {
            return XCTFail("Expected native useports route")
        }
        XCTAssertEqual(reason, .udpPunchFailed)

        XCTAssertEqual(factory.bindPorts, [plan.localBindPort, plan.fixedFallbackPort])
        XCTAssertEqual(initial.sent.map(\.1).suffix(1), [plan.master])
        XCTAssertEqual(String(data: initial.sent.last?.0 ?? Data(), encoding: .utf8), plan.usePortsPayload)
        XCTAssertEqual(fixed.sent.count, 10)
        XCTAssertTrue(fixed.sent.allSatisfy {
            $0.1 == FightcadeNetplayEndpoint(host: "198.51.100.7", port: plan.fixedFallbackPort)
        })
    }

    func testUDPProxyForwardsLocalAndPeerPackets() async throws {
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)
        let emulator = FightcadeNetplayEndpoint(host: "127.0.0.1", port: 41000)
        let peerTransport = ScriptedUDPTransport(receives: [
            (Data([5, 6, 7, 8]), peer)
        ])
        let localTransport = ScriptedUDPTransport(receives: [
            (Data([1, 2, 3, 4]), emulator)
        ])
        let proxy = FightcadeUDPProxy(
            peerTransport: peerTransport,
            localTransport: localTransport,
            configuration: FightcadeUDPProxyConfiguration(peer: peer, localEmulatorPort: 7001)
        )

        let result = try await proxy.step()

        XCTAssertEqual(result, FightcadeUDPProxyStepResult(forwardedLocalPackets: 1, forwardedPeerPackets: 1))
        XCTAssertEqual(peerTransport.sent.map(\.0), [Data([1, 2, 3, 4])])
        XCTAssertEqual(peerTransport.sent.map(\.1), [peer])
        XCTAssertEqual(localTransport.sent.map(\.0), [Data([5, 6, 7, 8])])
        XCTAssertEqual(localTransport.sent.map(\.1), [emulator])
    }

    func testUDPProxyUsesNativeGGPOPortBeforeLearningEmulatorSourcePort() async throws {
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)
        let peerTransport = ScriptedUDPTransport(receives: [
            (Data(hex: "02efbeadde"), peer)
        ])
        let localTransport = ScriptedUDPTransport(receives: [])
        let proxy = FightcadeUDPProxy(
            peerTransport: peerTransport,
            localTransport: localTransport,
            configuration: FightcadeUDPProxyConfiguration(peer: peer, localEmulatorPort: 7001)
        )

        let result = try await proxy.step()

        XCTAssertEqual(result.forwardedPeerPackets, 1)
        XCTAssertEqual(localTransport.sent.map(\.1), [FightcadeNetplayEndpoint(host: "127.0.0.1", port: 6000)])
    }

    func testUDPProxyFiltersPunchTokenPacketsAndUnexpectedPeerHost() async throws {
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)
        let peerTransport = ScriptedUDPTransport(receives: [
            (Data([9, 9, 9, 9]), FightcadeNetplayEndpoint(host: "203.0.113.10", port: 6200))
        ])
        let localTransport = ScriptedUDPTransport(receives: [
            (Data("0.123 _".utf8), FightcadeNetplayEndpoint(host: "127.0.0.1", port: 41000))
        ])
        let proxy = FightcadeUDPProxy(
            peerTransport: peerTransport,
            localTransport: localTransport,
            configuration: FightcadeUDPProxyConfiguration(peer: peer, localEmulatorPort: 7001)
        )

        let result = try await proxy.step()

        XCTAssertEqual(result, FightcadeUDPProxyStepResult())
        XCTAssertTrue(peerTransport.sent.isEmpty)
        XCTAssertTrue(localTransport.sent.isEmpty)
    }

    func testUDPProxyForwardsBinaryPacketsContainingHolePunchTextBytes() async throws {
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)
        let packet = Data([1, 0x20, 0x6f, 0x6b, 0])
        let peerTransport = ScriptedUDPTransport(receives: [])
        let localTransport = ScriptedUDPTransport(receives: [
            (packet, FightcadeNetplayEndpoint(host: "127.0.0.1", port: 41000))
        ])
        let proxy = FightcadeUDPProxy(
            peerTransport: peerTransport,
            localTransport: localTransport,
            configuration: FightcadeUDPProxyConfiguration(peer: peer, localEmulatorPort: 7001)
        )

        let result = try await proxy.step()

        XCTAssertEqual(result.forwardedLocalPackets, 1)
        XCTAssertEqual(peerTransport.sent.map(\.0), [packet])
    }

    func testUDPProxyDrainsBurstsAndStopsKeepaliveAfterGGPOTraffic() async throws {
        let peer = FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)
        let emulator = FightcadeNetplayEndpoint(host: "127.0.0.1", port: 41000)
        let peerTransport = ScriptedUDPTransport(receives: [
            (Data(hex: "02efbeadde"), peer),
            (Data(hex: "0504030201"), peer)
        ])
        let localTransport = ScriptedUDPTransport(receives: [
            (Data(hex: "017d7d0000"), emulator),
            (Data(hex: "040c0c47b400"), emulator)
        ])
        let proxy = FightcadeUDPProxy(
            peerTransport: peerTransport,
            localTransport: localTransport,
            configuration: FightcadeUDPProxyConfiguration(
                peer: peer,
                localEmulatorPort: 7001,
                keepalivePayload: Data("0.123 0.456 ok".utf8)
            )
        )

        let result = try await proxy.step()

        XCTAssertEqual(result, FightcadeUDPProxyStepResult(forwardedLocalPackets: 2, forwardedPeerPackets: 2))
        XCTAssertEqual(peerTransport.sent.count, 2)
        XCTAssertEqual(localTransport.sent.count, 2)
    }

    private func makeMatch(quarkID: String) -> FightcadeMatchLaunch {
        FightcadeMatchLaunch(
            emulator: "fbneo",
            gameID: "sfiii3n",
            quarkID: quarkID,
            playerID: 0,
            port: 7000,
            delay: 2,
            ranked: 0,
            token: nil
        )
    }
}

private final class ScriptedUDPTransport: FightcadeUDPTransporting, @unchecked Sendable {
    private var receives: [(Data, FightcadeNetplayEndpoint)]
    private let timeoutReceiveCalls: Set<Int>
    private var receiveCallCount = 0
    private(set) var sent: [(Data, FightcadeNetplayEndpoint)] = []

    init(
        receives: [(Data, FightcadeNetplayEndpoint)],
        timeoutReceiveCalls: Set<Int> = []
    ) {
        self.receives = receives
        self.timeoutReceiveCalls = timeoutReceiveCalls
    }

    func send(_ data: Data, to endpoint: FightcadeNetplayEndpoint) async throws {
        sent.append((data, endpoint))
    }

    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> (Data, FightcadeNetplayEndpoint) {
        receiveCallCount += 1
        if timeoutReceiveCalls.contains(receiveCallCount) {
            throw POSIXError(.ETIMEDOUT)
        }
        guard !receives.isEmpty else {
            throw POSIXError(.ETIMEDOUT)
        }
        return receives.removeFirst()
    }

    func close() {}
}

private struct ScriptedUDPTransportFactory: FightcadeUDPTransportFactory {
    let transport: ScriptedUDPTransport

    func makeTransport(bindPort: Int?) throws -> any FightcadeUDPTransporting {
        transport
    }
}

private final class QueueingUDPTransportFactory: FightcadeUDPTransportFactory, @unchecked Sendable {
    private var transports: [ScriptedUDPTransport]
    private(set) var bindPorts: [Int?] = []

    init(transports: [ScriptedUDPTransport]) {
        self.transports = transports
    }

    func makeTransport(bindPort: Int?) throws -> any FightcadeUDPTransporting {
        bindPorts.append(bindPort)
        guard !transports.isEmpty else { throw POSIXError(.ENOTCONN) }
        return transports.removeFirst()
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
}
