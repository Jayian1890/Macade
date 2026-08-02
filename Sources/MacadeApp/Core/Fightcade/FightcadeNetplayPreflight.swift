import Darwin
import Foundation

struct FightcadeNetplayPreflightReport: Equatable, Sendable {
    let warnings: [String]
}

struct FightcadeNetplayPreflight: Sendable {
    func run(plan: FightcadeQuarkSessionPlan, localProxyPort: Int) async -> FightcadeNetplayPreflightReport {
        var warnings: [String] = []
        if FightcadeConnectionStatus.current() == .wifi {
            warnings.append("Active route appears to use Wi-Fi; wired Ethernet usually improves GGPO reliability.")
        }
        if !tcpReachable(host: plan.master.host, port: plan.master.port) {
            warnings.append("Fightcade TCP match server was not reachable during preflight.")
        }
        if localProxyPort < 7001 || localProxyPort > 7009 {
            warnings.append("Local emulator proxy selected an unexpected UDP port: \(localProxyPort).")
        }
        if let networkWarning = networkExtensionWarning() {
            warnings.append(networkWarning)
        }
        return FightcadeNetplayPreflightReport(warnings: warnings)
    }

    private func tcpReachable(host: String, port: Int) -> Bool {
        var hints = addrinfo(ai_flags: AF_UNSPEC, ai_family: AF_INET, ai_socktype: SOCK_STREAM, ai_protocol: IPPROTO_TCP, ai_addrlen: 0, ai_canonname: nil, ai_addr: nil, ai_next: nil)
        var results: UnsafeMutablePointer<addrinfo>?
        guard getaddrinfo(host, String(port), &hints, &results) == 0, let results else { return false }
        defer { freeaddrinfo(results) }

        for item in sequence(first: results, next: { $0.pointee.ai_next }) {
            let fd = socket(item.pointee.ai_family, item.pointee.ai_socktype, item.pointee.ai_protocol)
            guard fd >= 0 else { continue }
            defer { close(fd) }
            setNonblocking(fd)
            let started = connect(fd, item.pointee.ai_addr, item.pointee.ai_addrlen)
            if started == 0 { return true }
            guard errno == EINPROGRESS else { continue }
            var pollDescriptor = pollfd(fd: fd, events: Int16(POLLOUT), revents: 0)
            guard poll(&pollDescriptor, 1, 2000) > 0 else { continue }
            var error: Int32 = 0
            var length = socklen_t(MemoryLayout<Int32>.size)
            if getsockopt(fd, SOL_SOCKET, SO_ERROR, &error, &length) == 0, error == 0 { return true }
        }
        return false
    }

    private func networkExtensionWarning() -> String? {
        guard let output = run("/usr/sbin/scutil", arguments: ["--nwi"]) else { return nil }
        let lowercased = output.lowercased()
        if lowercased.contains("utun") || lowercased.contains("ipsec") || lowercased.contains("ppp") {
            return "A VPN or network extension appears active; it can reduce peer-to-peer UDP success."
        }
        if lowercased.contains("private relay") {
            return "iCloud Private Relay-like routing appears active; direct UDP may be less reliable."
        }
        return nil
    }

    private func setNonblocking(_ fd: Int32) {
        let flags = fcntl(fd, F_GETFL, 0)
        if flags >= 0 { _ = fcntl(fd, F_SETFL, flags | O_NONBLOCK) }
    }

    private func run(_ executable: String, arguments: [String]) -> String? {
        let process = Process()
        let output = Pipe()
        process.executableURL = URL(fileURLWithPath: executable)
        process.arguments = arguments
        process.standardOutput = output
        process.standardError = Pipe()
        do {
            try process.run()
            process.waitUntilExit()
        } catch {
            return nil
        }
        guard process.terminationStatus == 0 else { return nil }
        return String(data: output.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8)
    }
}
