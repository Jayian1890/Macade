import Foundation
import XCTest
@testable import MacadeApp

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
        XCTAssertEqual(plan.restrictedNATFallbackPort, 442)
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
        XCTAssertEqual(FightcadeHolePunchMessage.parse(Data("0.456 0.123 ok".utf8))?.remoteKnowsLocalToken, true)
    }

    func testNormalNATFallbackCandidatesTryPlusThenMinusPorts() {
        XCTAssertEqual(
            FightcadePortFallbacks.normalNATCandidates(around: 7000, radius: 3),
            [7001, 6999, 7002, 6998, 7003, 6997]
        )
    }

    func testHolePuncherSendsTokenExchangeAndUpdatesSymmetricPort() async throws {
        let transport = ScriptedUDPTransport(receives: [
            (Data("0.456 _".utf8), FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200))
        ])
        let puncher = FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in })

        let result = try await puncher.punch(
            transport: transport,
            peer: FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6006),
            attempts: 1,
            sleep: 0
        )

        XCTAssertEqual(result, FightcadeHolePunchResult(punched: true, peer: FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)))
        XCTAssertEqual(transport.sent.map(\.0).map { String(data: $0, encoding: .utf8) }, ["0.123 0.456 ok"])
        XCTAssertEqual(transport.sent.map(\.1), [FightcadeNetplayEndpoint(host: "198.51.100.7", port: 6200)])
    }

    func testMasterClientSendsUsePortsAndFailsWhenPunchingFails() async throws {
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
        let factory = ScriptedUDPTransportFactory(transport: transport)
        let client = FightcadeMasterClient(
            transportFactory: factory,
            holePuncher: FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in }),
            fallbackRadius: 0
        )

        do {
            _ = try await client.establish(plan: plan)
            XCTFail("Expected UDP punch failure")
        } catch {
            XCTAssertEqual(error as? FightcadeMasterClientError, .udpPunchFailed)
        }

        let expectedPayloads = [plan.registrationPayload, plan.acknowledgePayload]
            + Array(repeating: "0.123 _", count: 20)
            + [plan.usePortsPayload]
        XCTAssertEqual(transport.sent.map(\.0).compactMap { String(data: $0, encoding: .utf8) }, expectedPayloads)
    }

    func testMasterClientTriesBoundFallbackPortsBeforeUsePorts() async throws {
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
        let restricted = ScriptedUDPTransport(receives: [])
        let fixed = ScriptedUDPTransport(receives: [])
        let factory = QueueingUDPTransportFactory(transports: [initial, restricted, fixed])
        let client = FightcadeMasterClient(
            transportFactory: factory,
            holePuncher: FightcadeUDPHolePuncher(tokenProvider: { "0.123" }, sleeper: { _ in }),
            fallbackRadius: 1
        )

        do {
            _ = try await client.establish(plan: plan)
            XCTFail("Expected UDP punch failure")
        } catch {
            XCTAssertEqual(error as? FightcadeMasterClientError, .udpPunchFailed)
        }

        XCTAssertEqual(factory.bindPorts, [plan.localBindPort, plan.restrictedNATFallbackPort, plan.fixedFallbackPort])
        XCTAssertEqual(initial.sent.map(\.1).suffix(3), [
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7005),
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7003),
            plan.master
        ])
        XCTAssertEqual(String(data: initial.sent.last?.0 ?? Data(), encoding: .utf8), plan.usePortsPayload)
        XCTAssertEqual(restricted.sent.map(\.1).suffix(3), [
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7004),
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7005),
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7003)
        ])
        XCTAssertEqual(fixed.sent.map(\.1).suffix(3), [
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7004),
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7005),
            FightcadeNetplayEndpoint(host: "198.51.100.7", port: 7003)
        ])
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
}

private final class ScriptedUDPTransport: FightcadeUDPTransporting, @unchecked Sendable {
    private var receives: [(Data, FightcadeNetplayEndpoint)]
    private(set) var sent: [(Data, FightcadeNetplayEndpoint)] = []

    init(receives: [(Data, FightcadeNetplayEndpoint)]) {
        self.receives = receives
    }

    func send(_ data: Data, to endpoint: FightcadeNetplayEndpoint) async throws {
        sent.append((data, endpoint))
    }

    func receive(maximumBytes: Int, timeout: TimeInterval) async throws -> (Data, FightcadeNetplayEndpoint) {
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
