import Darwin
import Foundation

struct FightcadePortMappingResult: Equatable, Sendable {
    let port: Int
    let protocolName: String
    let mapped: Bool
    let message: String
}

struct FightcadePortMappingService: Sendable {
    func mapUDP(ports: [Int], lifetime: UInt32 = 3600) async -> [FightcadePortMappingResult] {
        let uniquePorts = Array(Set(ports)).sorted()
        guard let gateway = defaultGateway() else {
            return uniquePorts.map { FightcadePortMappingResult(port: $0, protocolName: "gateway", mapped: false, message: "No default gateway found.") }
        }
        let localAddress = localIPv4Address(gateway: gateway) ?? "0.0.0.0"
        let upnpDevice = await discoverUPnPDevice(localAddress: localAddress)
        var results: [FightcadePortMappingResult] = []
        for port in uniquePorts {
            if mapPCP(port: port, gateway: gateway, localAddress: localAddress, lifetime: lifetime) {
                results.append(.init(port: port, protocolName: "PCP", mapped: true, message: "Mapped UDP port with PCP."))
            } else if mapNATPMP(port: port, gateway: gateway, lifetime: lifetime) {
                results.append(.init(port: port, protocolName: "NAT-PMP", mapped: true, message: "Mapped UDP port with NAT-PMP."))
            } else if let upnpDevice, await mapUPnP(port: port, localAddress: localAddress, device: upnpDevice, lifetime: lifetime) {
                results.append(.init(port: port, protocolName: "UPnP", mapped: true, message: "Mapped UDP port with UPnP IGD."))
            } else {
                results.append(.init(port: port, protocolName: "PCP/NAT-PMP/UPnP", mapped: false, message: "Router did not accept an automatic UDP mapping."))
            }
        }
        return results
    }

    private func mapPCP(port: Int, gateway: String, localAddress: String, lifetime: UInt32) -> Bool {
        var request = Data([2, 1, 0, 0])
        request.appendBigEndianUInt32(lifetime)
        request.append(ipv4MappedAddress(localAddress))
        request.append(randomBytes(count: 12))
        request.append(17)
        request.append(contentsOf: [0, 0, 0])
        request.appendBigEndianUInt16(UInt16(port))
        request.appendBigEndianUInt16(UInt16(port))
        request.append(Data(repeating: 0, count: 16))
        guard let response = udpRequest(request, host: gateway, port: 5351, timeout: 1.5), response.count >= 24 else { return false }
        return response[0] == 2 && response[1] == 0x81 && response[3] == 0
    }

    private func mapNATPMP(port: Int, gateway: String, lifetime: UInt32) -> Bool {
        var request = Data([0, 1, 0, 0])
        request.appendBigEndianUInt16(UInt16(port))
        request.appendBigEndianUInt16(UInt16(port))
        request.appendBigEndianUInt32(lifetime)
        guard let response = udpRequest(request, host: gateway, port: 5351, timeout: 1.5), response.count >= 16 else { return false }
        return response[0] == 0 && response[1] == 129 && response[2] == 0 && response[3] == 0
    }

    private func discoverUPnPDevice(localAddress: String) async -> UPnPDevice? {
        let search = "M-SEARCH * HTTP/1.1\r\nHOST:239.255.255.250:1900\r\nMAN:\"ssdp:discover\"\r\nMX:1\r\nST:urn:schemas-upnp-org:device:InternetGatewayDevice:1\r\n\r\n"
        guard let response = udpRequest(Data(search.utf8), host: "239.255.255.250", port: 1900, timeout: 2),
              let text = String(data: response, encoding: .utf8),
              let location = headerValue("location", in: text),
              let locationURL = URL(string: location) else { return nil }
        do {
            let configuration = URLSessionConfiguration.ephemeral
            configuration.timeoutIntervalForRequest = 2
            let (data, _) = try await URLSession(configuration: configuration).data(from: locationURL)
            guard let xml = String(data: data, encoding: .utf8) else { return nil }
            return parseUPnPDevice(xml: xml, locationURL: locationURL, localAddress: localAddress)
        } catch {
            return nil
        }
    }

    private func mapUPnP(port: Int, localAddress: String, device: UPnPDevice, lifetime: UInt32) async -> Bool {
        let body = """
        <?xml version="1.0"?>
        <s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/" s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/"><s:Body><u:AddPortMapping xmlns:u="\(device.serviceType)"><NewRemoteHost></NewRemoteHost><NewExternalPort>\(port)</NewExternalPort><NewProtocol>UDP</NewProtocol><NewInternalPort>\(port)</NewInternalPort><NewInternalClient>\(localAddress)</NewInternalClient><NewEnabled>1</NewEnabled><NewPortMappingDescription>Macade GGPO</NewPortMappingDescription><NewLeaseDuration>\(lifetime)</NewLeaseDuration></u:AddPortMapping></s:Body></s:Envelope>
        """
        var request = URLRequest(url: device.controlURL)
        request.httpMethod = "POST"
        request.timeoutInterval = 2
        request.setValue("text/xml; charset=\"utf-8\"", forHTTPHeaderField: "Content-Type")
        request.setValue("\"\(device.serviceType)#AddPortMapping\"", forHTTPHeaderField: "SOAPAction")
        request.httpBody = Data(body.utf8)
        do {
            let (_, response) = try await URLSession.shared.data(for: request)
            return (response as? HTTPURLResponse)?.statusCode == 200
        } catch {
            return false
        }
    }

    private func parseUPnPDevice(xml: String, locationURL: URL, localAddress: String) -> UPnPDevice? {
        for service in xml.components(separatedBy: "<service>") where service.contains("WANIPConnection") || service.contains("WANPPPConnection") {
            guard let type = xmlValue("serviceType", in: service), let control = xmlValue("controlURL", in: service) else { continue }
            if let url = URL(string: control, relativeTo: locationURL)?.absoluteURL {
                return UPnPDevice(controlURL: url, serviceType: type)
            }
        }
        return nil
    }

    private func udpRequest(_ data: Data, host: String, port: Int, timeout: TimeInterval) -> Data? {
        let fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
        guard fd >= 0 else { return nil }
        defer { close(fd) }
        var tv = timeval(tv_sec: Int(timeout), tv_usec: suseconds_t((timeout.truncatingRemainder(dividingBy: 1)) * 1_000_000))
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, socklen_t(MemoryLayout<timeval>.size))
        guard var addr = sockaddr(host: host, port: port) else { return nil }
        let sent = data.withUnsafeBytes { bytes in
            withUnsafePointer(to: &addr) { pointer in
                pointer.withMemoryRebound(to: Darwin.sockaddr.self, capacity: 1) {
                    sendto(fd, bytes.baseAddress, data.count, 0, $0, socklen_t(MemoryLayout<sockaddr_in>.size))
                }
            }
        }
        guard sent == data.count else { return nil }
        var buffer = [UInt8](repeating: 0, count: 4096)
        let count = recv(fd, &buffer, buffer.count, 0)
        guard count > 0 else { return nil }
        return Data(buffer.prefix(count))
    }

    private func defaultGateway() -> String? {
        guard let output = run("/sbin/route", arguments: ["-n", "get", "default"]) else { return nil }
        for line in output.split(separator: "\n") {
            let parts = line.split(separator: ":", maxSplits: 1).map { $0.trimmingCharacters(in: .whitespaces) }
            if parts.count == 2, parts[0] == "gateway" { return parts[1] }
        }
        return nil
    }

    private func localIPv4Address(gateway: String) -> String? {
        let fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
        guard fd >= 0 else { return nil }
        defer { close(fd) }
        guard var remote = sockaddr(host: gateway, port: 80) else { return nil }
        let connected = withUnsafePointer(to: &remote) {
            $0.withMemoryRebound(to: Darwin.sockaddr.self, capacity: 1) { connect(fd, $0, socklen_t(MemoryLayout<sockaddr_in>.size)) }
        }
        guard connected == 0 else { return nil }
        var local = sockaddr_in()
        var length = socklen_t(MemoryLayout<sockaddr_in>.size)
        let status = withUnsafeMutablePointer(to: &local) {
            $0.withMemoryRebound(to: Darwin.sockaddr.self, capacity: 1) { getsockname(fd, $0, &length) }
        }
        guard status == 0 else { return nil }
        return ipString(local.sin_addr)
    }

    private func sockaddr(host: String, port: Int) -> sockaddr_in? {
        var addr = sockaddr_in()
        addr.sin_len = UInt8(MemoryLayout<sockaddr_in>.size)
        addr.sin_family = sa_family_t(AF_INET)
        addr.sin_port = in_port_t(port).bigEndian
        guard inet_pton(AF_INET, host, &addr.sin_addr) == 1 else { return nil }
        return addr
    }

    private func ipString(_ address: in_addr) -> String? {
        var copy = address
        var buffer = [CChar](repeating: 0, count: Int(INET_ADDRSTRLEN))
        guard inet_ntop(AF_INET, &copy, &buffer, socklen_t(INET_ADDRSTRLEN)) != nil else { return nil }
        return String(decoding: buffer.prefix { $0 != 0 }.map(UInt8.init(bitPattern:)), as: UTF8.self)
    }

    private func ipv4MappedAddress(_ address: String) -> Data {
        var data = Data(repeating: 0, count: 10) + Data([0xff, 0xff])
        let octets = address.split(separator: ".").compactMap { UInt8($0) }
        if octets.count == 4 {
            data.append(contentsOf: octets)
        } else {
            data.append(Data(repeating: 0, count: 4))
        }
        return data
    }

    private func randomBytes(count: Int) -> Data {
        Data((0..<count).map { _ in UInt8.random(in: .min ... .max) })
    }

    private func headerValue(_ name: String, in response: String) -> String? {
        for line in response.split(separator: "\n") {
            let parts = line.split(separator: ":", maxSplits: 1).map { $0.trimmingCharacters(in: .whitespacesAndNewlines) }
            if parts.count == 2, parts[0].lowercased() == name { return parts[1] }
        }
        return nil
    }

    private func xmlValue(_ name: String, in xml: String) -> String? {
        guard let start = xml.range(of: "<\(name)>")?.upperBound,
              let end = xml.range(of: "</\(name)>", range: start..<xml.endIndex)?.lowerBound else { return nil }
        return String(xml[start..<end]).trimmingCharacters(in: .whitespacesAndNewlines)
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

private struct UPnPDevice {
    let controlURL: URL
    let serviceType: String
}

private extension Data {
    mutating func appendBigEndianUInt16(_ value: UInt16) {
        append(UInt8((value >> 8) & 0xff))
        append(UInt8(value & 0xff))
    }

}
