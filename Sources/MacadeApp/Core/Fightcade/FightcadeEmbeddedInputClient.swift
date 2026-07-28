import Darwin
import Foundation

final class FightcadeEmbeddedInputClient: @unchecked Sendable {
    let socketPath: String

    private let lock = NSLock()
    private var socketDescriptor: Int32 = -1
    private var diagnosticCount = 0

    init(socketPath: String) throws {
        self.socketPath = socketPath
        socketDescriptor = socket(AF_UNIX, SOCK_DGRAM, 0)
        guard socketDescriptor >= 0 else {
            throw FightcadeLaunchError.embeddedBridgeFailed("Could not create embedded input socket.")
        }
    }

    func sendKey(scancode: Int32, isPressed: Bool) {
        logDiagnosticIfNeeded(message: "key-start \(isPressed ? 1 : 0) \(scancode)", sent: 0)
        send("key \(isPressed ? 1 : 0) \(scancode)")
    }

    func beginChat() {
        send("chatBegin")
    }

    func updateChat(_ text: String) {
        send("chatUpdate \(Self.hexEncoded(text))")
    }

    func submitChat(_ text: String) {
        send("chatSubmit \(Self.hexEncoded(text))")
    }

    func cancelChat() {
        send("chatCancel")
    }

    func close() {
        lock.withLock {
            if socketDescriptor >= 0 {
                Darwin.close(socketDescriptor)
                socketDescriptor = -1
            }
            try? FileManager.default.removeItem(atPath: socketPath)
        }
    }

    deinit {
        close()
    }

    private func send(_ message: String) {
        guard let data = message.data(using: .utf8) else {
            logDiagnosticIfNeeded(message: message, detail: "data-encode-failed")
            return
        }

        lock.withLock {
            guard socketDescriptor >= 0 else {
                logDiagnosticIfNeeded(message: message, detail: "socket-closed")
                return
            }

            var address = sockaddr_un()
            address.sun_family = sa_family_t(AF_UNIX)
            let pathBytes = Array(socketPath.utf8CString)
            guard pathBytes.count <= MemoryLayout.size(ofValue: address.sun_path) else {
                logDiagnosticIfNeeded(message: message, detail: "path-too-long count=\(pathBytes.count)")
                return
            }

            guard let pathOffset = MemoryLayout.offset(of: \sockaddr_un.sun_path) else {
                logDiagnosticIfNeeded(message: message, detail: "path-offset-missing")
                return
            }

            let length = socklen_t(pathOffset + pathBytes.count)
            address.sun_len = UInt8(length)

            withUnsafeMutablePointer(to: &address.sun_path.0) { pointer in
                pathBytes.withUnsafeBufferPointer { buffer in
                    pointer.initialize(from: buffer.baseAddress!, count: buffer.count)
                }
            }

            data.withUnsafeBytes { buffer in
                guard let baseAddress = buffer.baseAddress else { return }
                withUnsafePointer(to: &address) { addressPointer in
                    addressPointer.withMemoryRebound(to: sockaddr.self, capacity: 1) { socketAddress in
                        let sent = sendto(socketDescriptor, baseAddress, buffer.count, 0, socketAddress, length)
                        logDiagnosticIfNeeded(message: message, sent: sent)
                    }
                }
            }
        }
    }

    private func logDiagnosticIfNeeded(message: String, sent: Int) {
        guard message.hasPrefix("key"), diagnosticCount < 80 else { return }
        diagnosticCount += 1

        let detail: String
        if sent >= 0 {
            detail = "sent=\(sent)"
        } else {
            detail = "sent=-1 errno=\(errno) \(String(cString: strerror(errno)))"
        }

        Self.appendDiagnostic("\(Date()) \(message) \(detail) socket=\(socketPath)\n")
    }

    private func logDiagnosticIfNeeded(message: String, detail: String) {
        guard message.hasPrefix("key"), diagnosticCount < 80 else { return }
        diagnosticCount += 1
        Self.appendDiagnostic("\(Date()) \(message) \(detail) socket=\(socketPath)\n")
    }

    private static func appendDiagnostic(_ line: String) {
        guard let logsURL = FileManager.default.urls(for: .libraryDirectory, in: .userDomainMask).first?
            .appendingPathComponent("Logs")
            .appendingPathComponent("Macade") else {
            return
        }

        try? FileManager.default.createDirectory(at: logsURL, withIntermediateDirectories: true)
        let url = logsURL.appendingPathComponent("fightcade-embedded-input-latest.log")
        guard let data = line.data(using: .utf8) else { return }

        if !FileManager.default.fileExists(atPath: url.path) {
            FileManager.default.createFile(atPath: url.path, contents: nil)
        }

        guard let handle = try? FileHandle(forWritingTo: url) else { return }
        defer { try? handle.close() }
        _ = try? handle.seekToEnd()
        try? handle.write(contentsOf: data)
    }

    private static func hexEncoded(_ text: String) -> String {
        let digits = Array("0123456789abcdef".utf8)
        var bytes: [UInt8] = []
        bytes.reserveCapacity(text.utf8.count * 2)

        for byte in text.utf8 {
            bytes.append(digits[Int(byte >> 4)])
            bytes.append(digits[Int(byte & 0x0F)])
        }

        return String(decoding: bytes, as: UTF8.self)
    }
}
