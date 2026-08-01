import Darwin
import Foundation

struct FightcadeEmbeddedVideoFrame: Sendable {
    let width: Int
    let height: Int
    let pitch: Int
    let bytesPerPixel: Int
    let pixelFormat: UInt32
    let frameIndex: UInt64
    let spectatorCount: Int
    let overlayState: FightcadeEmbeddedOverlayState?
    let bytes: Data
}

struct FightcadeEmbeddedMappedVideoFrame {
    let width: Int
    let height: Int
    let pitch: Int
    let bytesPerPixel: Int
    let pixelFormat: UInt32
    let frameIndex: UInt64
    let spectatorCount: Int
    let overlayState: FightcadeEmbeddedOverlayState?
    let baseAddress: UnsafeRawPointer
    let byteCount: Int
}

enum FightcadeEmbeddedVideoFrameRead<Value> {
    case missing
    case duplicate
    case frame(Value)
}

struct FightcadeEmbeddedOverlayState: Equatable, Sendable {
    let isEnabled: Bool
    let connectionPhase: Int
    let isSpectator: Bool
    let ranked: Int
    let player: Int
    let spectators: Int
    let ping: Int
    let delay: Int
    let systemFrames: Int
    let chatFrames: Int
    let isChatInputActive: Bool
    let systemMessage: String
    let chatInput: String
    let chatLines: [ChatLine]
    let players: [Player]

    struct ChatLine: Equatable, Sendable, Identifiable {
        var id: String { "\(name):\(text)" }

        let name: String
        let text: String
    }

    struct Player: Equatable, Sendable, Identifiable {
        var id: String { name.isEmpty ? fallbackName : name }

        let name: String
        let country: String
        let rank: Int
        let score: Int
        let fallbackName: String

        var displayName: String {
            name.isEmpty ? fallbackName : name
        }
    }
}

struct FightcadeEmbeddedVideoSourceSize: Equatable, Sendable {
    let width: Int
    let height: Int
}

final class FightcadeEmbeddedVideoStream: @unchecked Sendable {
    static let byteCount = 128 * 1024 * 1024

    let fileURL: URL
    let byteCount: Int

    private let pointer: UnsafeMutableRawPointer
    private let descriptor: Int32
    private let lock = NSLock()
    private var isClosed = false

    init(fileURL: URL, byteCount: Int = FightcadeEmbeddedVideoStream.byteCount) throws {
        self.fileURL = fileURL
        self.byteCount = byteCount

        descriptor = Darwin.open(fileURL.path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)
        guard descriptor >= 0 else {
            throw FightcadeLaunchError.embeddedBridgeFailed("Could not create embedded video file.")
        }

        guard ftruncate(descriptor, off_t(byteCount)) == 0 else {
            Darwin.close(descriptor)
            throw FightcadeLaunchError.embeddedBridgeFailed("Could not size embedded video file.")
        }

        let mapped = mmap(nil, byteCount, PROT_READ | PROT_WRITE, MAP_SHARED, descriptor, 0)
        guard mapped != MAP_FAILED, let mapped else {
            Darwin.close(descriptor)
            throw FightcadeLaunchError.embeddedBridgeFailed("Could not map embedded video file.")
        }

        pointer = mapped
        initializeHeader()
    }

    func snapshot() -> FightcadeEmbeddedVideoFrame? {
        lock.withLock {
            guard !isClosed else { return nil }

            let magic = loadUInt32(Header.magic)
            let frameIndex = loadUInt64(Header.frameIndex)
            guard magic == Header.expectedMagic, frameIndex > 0 else {
                return nil
            }

            let width = Int(loadUInt32(Header.width))
            let height = Int(loadUInt32(Header.height))
            let pitch = Int(loadUInt32(Header.pitch))
            let bytesPerPixel = Int(loadUInt32(Header.bytesPerPixel))
            let pixelFormat = loadUInt32(Header.pixelFormat)
            let slotCapacity = Int(loadUInt32(Header.slotCapacity))
            let slotCount = max(1, Int(loadUInt32(Header.slotCount)))
            let writeSlot = Int(loadUInt32(Header.writeSlot)) % slotCount
            let spectatorCount = Int(loadUInt32(Header.spectatorCount))
            let overlayState = loadOverlayState()
            let byteLength = pitch * height

            guard width > 0,
                  height > 0,
                  pitch > 0,
                  bytesPerPixel > 0,
                  byteLength > 0,
                  byteLength <= slotCapacity else {
                return nil
            }

            let offset = Header.size + writeSlot * slotCapacity
            guard offset >= Header.size, offset + byteLength <= byteCount else {
                return nil
            }

            let source = pointer.advanced(by: offset)
            let bytes = Data(bytes: source, count: byteLength)
            return FightcadeEmbeddedVideoFrame(
                width: width,
                height: height,
                pitch: pitch,
                bytesPerPixel: bytesPerPixel,
                pixelFormat: pixelFormat,
                frameIndex: frameIndex,
                spectatorCount: spectatorCount,
                overlayState: overlayState,
                bytes: bytes
            )
        }
    }

    func overlaySnapshot() -> FightcadeEmbeddedOverlayState? {
        lock.withLock {
            guard !isClosed, loadUInt32(Header.magic) == Header.expectedMagic else { return nil }
            return loadOverlayState()
        }
    }

    func sourceSizeSnapshot() -> FightcadeEmbeddedVideoSourceSize? {
        lock.withLock {
            guard !isClosed, loadUInt32(Header.magic) == Header.expectedMagic else { return nil }
            let width = Int(loadUInt32(Header.width))
            let height = Int(loadUInt32(Header.height))
            guard width > 0, height > 0 else { return nil }
            return FightcadeEmbeddedVideoSourceSize(width: width, height: height)
        }
    }

    func withNextFrame<Value>(after lastFrameIndex: UInt64, _ body: (FightcadeEmbeddedMappedVideoFrame) -> Value) -> FightcadeEmbeddedVideoFrameRead<Value> {
        lock.withLock {
            guard !isClosed else { return .missing }

            let magic = loadUInt32(Header.magic)
            let frameIndex = loadUInt64(Header.frameIndex)
            guard magic == Header.expectedMagic, frameIndex > 0 else {
                return .missing
            }
            guard frameIndex != lastFrameIndex else {
                return .duplicate
            }

            let width = Int(loadUInt32(Header.width))
            let height = Int(loadUInt32(Header.height))
            let pitch = Int(loadUInt32(Header.pitch))
            let bytesPerPixel = Int(loadUInt32(Header.bytesPerPixel))
            let pixelFormat = loadUInt32(Header.pixelFormat)
            let slotCapacity = Int(loadUInt32(Header.slotCapacity))
            let slotCount = max(1, Int(loadUInt32(Header.slotCount)))
            let writeSlot = Int(loadUInt32(Header.writeSlot)) % slotCount
            let spectatorCount = Int(loadUInt32(Header.spectatorCount))
            let byteLength = pitch * height

            guard width > 0,
                  height > 0,
                  pitch > 0,
                  bytesPerPixel > 0,
                  byteLength > 0,
                  byteLength <= slotCapacity else {
                return .missing
            }

            let offset = Header.size + writeSlot * slotCapacity
            guard offset >= Header.size, offset + byteLength <= byteCount else {
                return .missing
            }

            let source = UnsafeRawPointer(pointer.advanced(by: offset))
            let frame = FightcadeEmbeddedMappedVideoFrame(
                width: width,
                height: height,
                pitch: pitch,
                bytesPerPixel: bytesPerPixel,
                pixelFormat: pixelFormat,
                frameIndex: frameIndex,
                spectatorCount: spectatorCount,
                overlayState: loadOverlayState(),
                baseAddress: source,
                byteCount: byteLength
            )
            return .frame(body(frame))
        }
    }

    func close(removingFile: Bool = true) {
        lock.withLock {
            guard !isClosed else { return }
            munmap(pointer, byteCount)
            Darwin.close(descriptor)
            isClosed = true
        }

        if removingFile {
            try? FileManager.default.removeItem(at: fileURL)
        }
    }

    deinit {
        close()
    }

    private func initializeHeader() {
        memset(pointer, 0, byteCount)
        storeUInt32(Header.expectedMagic, Header.magic)
        storeUInt32(1, Header.version)
        storeUInt32(UInt32(Header.size), Header.headerSize)
        storeUInt32(UInt32(Header.slotCountValue), Header.slotCount)
        storeUInt32(UInt32((byteCount - Header.size) / Header.slotCountValue), Header.slotCapacity)
    }

    private func loadOverlayState() -> FightcadeEmbeddedOverlayState? {
        guard loadUInt32(Header.overlayEnabled) != 0 else {
            return nil
        }

        let players = (0..<Header.overlayPlayerCount).map { index in
            let offset = Header.overlayPlayers + index * Header.overlayPlayerSize
            return FightcadeEmbeddedOverlayState.Player(
                name: loadString(offset + Header.overlayPlayerName, length: Header.overlayPlayerNameLength),
                country: loadString(offset + Header.overlayPlayerCountry, length: Header.overlayPlayerCountryLength),
                rank: Int(loadInt32(offset + Header.overlayPlayerRank)),
                score: Int(loadInt32(offset + Header.overlayPlayerScore)),
                fallbackName: "Player \(index + 1)"
            )
        }

        let chatLines: [FightcadeEmbeddedOverlayState.ChatLine] = (0..<Header.overlayChatLineCount).compactMap { index in
            let offset = Header.overlayChatLines + index * Header.overlayChatLineSize
            let name = loadString(offset + Header.overlayChatLineName, length: Header.overlayChatLineNameLength)
            let text = loadString(offset + Header.overlayChatLineText, length: Header.overlayChatLineTextLength)
            guard !text.isEmpty else { return nil }
            return FightcadeEmbeddedOverlayState.ChatLine(name: name.isEmpty ? "Player" : name, text: text)
        }

        return FightcadeEmbeddedOverlayState(
            isEnabled: true,
            connectionPhase: Int(loadUInt32(Header.overlayConnectionPhase)),
            isSpectator: loadUInt32(Header.overlaySpectator) != 0,
            ranked: Int(loadUInt32(Header.overlayRanked)),
            player: Int(loadUInt32(Header.overlayPlayer)),
            spectators: Int(loadUInt32(Header.overlaySpectators)),
            ping: Int(loadUInt32(Header.overlayPing)),
            delay: Int(loadUInt32(Header.overlayDelay)),
            systemFrames: Int(loadUInt32(Header.overlaySystemFrames)),
            chatFrames: Int(loadUInt32(Header.overlayChatFrames)),
            isChatInputActive: loadUInt32(Header.overlayChatInputActive) != 0,
            systemMessage: loadString(Header.overlaySystemMessage, length: Header.overlaySystemMessageLength),
            chatInput: loadString(Header.overlayChatInput, length: Header.overlayChatInputLength),
            chatLines: chatLines,
            players: players
        )
    }

    private func loadUInt32(_ offset: Int) -> UInt32 {
        pointer.load(fromByteOffset: offset, as: UInt32.self)
    }

    private func loadUInt64(_ offset: Int) -> UInt64 {
        pointer.load(fromByteOffset: offset, as: UInt64.self)
    }

    private func loadInt32(_ offset: Int) -> Int32 {
        pointer.load(fromByteOffset: offset, as: Int32.self)
    }

    private func loadString(_ offset: Int, length: Int) -> String {
        guard offset >= 0, length > 0, offset + length <= Header.size else {
            return ""
        }

        let source = pointer.advanced(by: offset).assumingMemoryBound(to: UInt8.self)
        let bytes = Array(UnsafeBufferPointer(start: source, count: length))
        let end = bytes.firstIndex(of: 0) ?? bytes.count
        guard end > 0 else { return "" }
        return String(decoding: bytes[..<end], as: UTF8.self)
    }

    private func storeUInt32(_ value: UInt32, _ offset: Int) {
        pointer.storeBytes(of: value, toByteOffset: offset, as: UInt32.self)
    }

    private enum Header {
        static let expectedMagic: UInt32 = 0x5644_434D
        static let size = 4096
        static let slotCountValue = 3

        static let magic = 0
        static let version = 4
        static let headerSize = 8
        static let slotCount = 12
        static let width = 16
        static let height = 20
        static let pitch = 24
        static let bytesPerPixel = 28
        static let pixelFormat = 32
        static let slotCapacity = 36
        static let writeSlot = 40
        static let status = 44
        static let frameIndex = 48
        static let spectatorCount = 56
        static let overlaySequence = 60

        static let overlay = 64
        static let overlayEnabled = overlay
        static let overlaySpectator = overlay + 4
        static let overlayRanked = overlay + 8
        static let overlayPlayer = overlay + 12
        static let overlaySpectators = overlay + 16
        static let overlayPing = overlay + 20
        static let overlayDelay = overlay + 24
        static let overlaySystemFrames = overlay + 28
        static let overlayChatFrames = overlay + 32
        static let overlayChatInputActive = overlay + 36
        static let overlaySystemMessage = overlay + 40
        static let overlaySystemMessageLength = 160
        static let overlayChatInput = overlay + 200
        static let overlayChatInputLength = 160
        static let overlayChatLines = overlay + 360
        static let overlayChatLineCount = 7
        static let overlayChatLineSize = 384
        static let overlayChatLineName = 0
        static let overlayChatLineNameLength = 128
        static let overlayChatLineText = 128
        static let overlayChatLineTextLength = 256
        static let overlayPlayers = overlayChatLines + overlayChatLineCount * overlayChatLineSize
        static let overlayPlayerCount = 2
        static let overlayPlayerSize = 152
        static let overlayPlayerName = 0
        static let overlayPlayerNameLength = 128
        static let overlayPlayerCountry = 128
        static let overlayPlayerCountryLength = 16
        static let overlayPlayerRank = 144
        static let overlayPlayerScore = 148
        static let overlayConnectionPhase = overlay + 3356
    }
}
