import Foundation

struct FightcadeGGPOPeerUDPPacket: Equatable, Sendable {
    enum Kind: Equatable, Sendable {
        case holePunch(FightcadeHolePunchMessage)
        case syncRequest(nonce: UInt32)
        case syncReply(nonce: UInt32)
        case input(FightcadeGGPOPeerUDPInputPacket)
        case qualityReport(frameAdvantage: Int8, nonce: UInt32)
        case qualityReply(nonce: UInt32)
        case binary(type: UInt8, payloadLength: Int)
    }

    let kind: Kind
    let rawPayload: Data

    static func parse(_ data: Data) -> FightcadeGGPOPeerUDPPacket {
        if let message = FightcadeHolePunchMessage.parse(data) {
            return FightcadeGGPOPeerUDPPacket(kind: .holePunch(message), rawPayload: data)
        }

        if let parsed = parseKnownBinary(data) {
            return FightcadeGGPOPeerUDPPacket(kind: parsed, rawPayload: data)
        }

        return FightcadeGGPOPeerUDPPacket(
            kind: .binary(type: data.first ?? 0, payloadLength: data.count),
            rawPayload: data
        )
    }

    private static func parseKnownBinary(_ data: Data) -> Kind? {
        switch data.first {
        case 1 where data.count == 5:
            return .syncRequest(nonce: data.readLittleEndianUInt32(at: 1))
        case 2 where data.count == 5:
            return .syncReply(nonce: data.readLittleEndianUInt32(at: 1))
        case 3 where data.count >= 12:
            let packet = FightcadeGGPOPeerUDPInputPacket(
                startFrame: data.readLittleEndianUInt32(at: 1),
                ackFrame: data.readLittleEndianInt32(at: 5),
                compressedBitCount: data.readLittleEndianUInt16(at: 9),
                inputSizeBytes: data[11],
                inputBits: Data(data.dropFirst(12))
            )
            guard packet.hasExpectedBitPayloadLength else { return nil }
            return .input(packet)
        case 4 where data.count == 6:
            return .qualityReport(frameAdvantage: Int8(bitPattern: data[1]), nonce: data.readLittleEndianUInt32(at: 2))
        case 5 where data.count == 5:
            return .qualityReply(nonce: data.readLittleEndianUInt32(at: 1))
        default:
            return nil
        }
    }
}

struct FightcadeGGPOPeerUDPInputPacket: Equatable, Sendable {
    let startFrame: UInt32
    let ackFrame: Int32
    let compressedBitCount: UInt16
    let inputSizeBytes: UInt8
    let inputBits: Data

    var expectedBitPayloadByteCount: Int {
        Int(compressedBitCount + 7) / 8
    }

    var hasExpectedBitPayloadLength: Bool {
        inputBits.count == expectedBitPayloadByteCount
    }

    var encoded: Data {
        var data = Data([3])
        data.appendLittleEndianUInt32(startFrame)
        data.appendLittleEndianUInt32(UInt32(bitPattern: ackFrame))
        data.appendLittleEndianUInt16(compressedBitCount)
        data.append(inputSizeBytes)
        data.append(inputBits)
        return data
    }
}

struct FightcadeGGPOPeerUDPPacketSummary: Equatable, Sendable {
    let binaryTypeCounts: [UInt8: Int]
    let payloadLengthCounts: [Int: Int]
    let holePunchPacketCount: Int

    static func summarize(_ packets: [FightcadeGGPOPeerUDPPacket]) -> FightcadeGGPOPeerUDPPacketSummary {
        var binaryTypeCounts: [UInt8: Int] = [:]
        var payloadLengthCounts: [Int: Int] = [:]
        var holePunchPacketCount = 0

        for packet in packets {
            switch packet.kind {
            case .holePunch:
                holePunchPacketCount += 1
            case .syncRequest:
                binaryTypeCounts[1, default: 0] += 1
                payloadLengthCounts[packet.rawPayload.count, default: 0] += 1
            case .syncReply:
                binaryTypeCounts[2, default: 0] += 1
                payloadLengthCounts[packet.rawPayload.count, default: 0] += 1
            case .input:
                binaryTypeCounts[3, default: 0] += 1
                payloadLengthCounts[packet.rawPayload.count, default: 0] += 1
            case .qualityReport:
                binaryTypeCounts[4, default: 0] += 1
                payloadLengthCounts[packet.rawPayload.count, default: 0] += 1
            case .qualityReply:
                binaryTypeCounts[5, default: 0] += 1
                payloadLengthCounts[packet.rawPayload.count, default: 0] += 1
            case let .binary(type, payloadLength):
                binaryTypeCounts[type, default: 0] += 1
                payloadLengthCounts[payloadLength, default: 0] += 1
            }
        }

        return FightcadeGGPOPeerUDPPacketSummary(
            binaryTypeCounts: binaryTypeCounts,
            payloadLengthCounts: payloadLengthCounts,
            holePunchPacketCount: holePunchPacketCount
        )
    }
}

private extension Data {
    mutating func appendLittleEndianUInt16(_ value: UInt16) {
        append(UInt8(value & 0xff))
        append(UInt8((value >> 8) & 0xff))
    }

    mutating func appendLittleEndianUInt32(_ value: UInt32) {
        append(UInt8(value & 0xff))
        append(UInt8((value >> 8) & 0xff))
        append(UInt8((value >> 16) & 0xff))
        append(UInt8((value >> 24) & 0xff))
    }

    func readLittleEndianUInt16(at offset: Int) -> UInt16 {
        UInt16(self[offset]) | UInt16(self[offset + 1]) << 8
    }

    func readLittleEndianUInt32(at offset: Int) -> UInt32 {
        UInt32(self[offset])
            | UInt32(self[offset + 1]) << 8
            | UInt32(self[offset + 2]) << 16
            | UInt32(self[offset + 3]) << 24
    }

    func readLittleEndianInt32(at offset: Int) -> Int32 {
        Int32(bitPattern: readLittleEndianUInt32(at: offset))
    }
}
