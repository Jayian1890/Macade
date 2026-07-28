import CryptoKit
import Foundation
import IOKit

protocol FightcadeUserStatusReporting: Sendable {
    func report(token: String) async throws
}

struct FightcadeUserStatusReporter: FightcadeUserStatusReporting {
    private let session: URLSession

    init(session: URLSession = .shared) {
        self.session = session
    }

    func report(token: String) async throws {
        let token = token.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !token.isEmpty else {
            return
        }

        let identity = FightcadeUserStatusIdentity.current()
        let status = FightcadeConnectionStatus.current().rawValue
        let payload = FightcadeUserStatusPayload(
            token: token,
            userStatus: status,
            uuid: identity.uuid,
            guid: identity.guid,
            huid: identity.huid
        )

        var request = URLRequest(url: FightcadeEndpoint.userStatusAPIURL)
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.httpMethod = "POST"
        request.setValue("fcade", forHTTPHeaderField: "User-Agent")
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.httpBody = try JSONSerialization.data(withJSONObject: payload.dictionary)

        let (_, response) = try await session.data(for: request)
        if let httpResponse = response as? HTTPURLResponse,
           !(200..<300).contains(httpResponse.statusCode) {
            throw FightcadeServiceError.unexpectedResponse("Could not report Fightcade launcher status.")
        }
    }
}

struct FightcadeUserStatusPayload: Equatable {
    static let version = 6

    let token: String
    let userStatus: String
    let uuid: String
    let guid: String
    let huid: String

    var dictionary: [String: Any] {
        [
            "req": "userstatus",
            "token": token,
            "userstatus": userStatus,
            "uuid": uuid,
            "guid": guid,
            "huid": huid,
            "version": Self.version,
            "hash": hash
        ]
    }

    var hash: String {
        FightcadeUserStatusHash.md5(
            "3jedoQ\(token)qmkq0\(uuid)dsnds\(guid)sec or\(Self.version)2jden3\(userStatus)llNjjha\(huid)"
        )
    }
}

enum FightcadeConnectionStatus: String {
    case wifi = "stwlan"
    case wired = "stcable"

    static func current(forceWired: Bool = FightcadeConnectionStatusOverride.forceWired) -> FightcadeConnectionStatus {
        if forceWired {
            return .wired
        }

        guard let interface = FightcadeCommandOutput.activeNetworkInterface(),
              FightcadeCommandOutput.interfaceIsWiFi(interface) else {
            return .wired
        }

        return .wifi
    }
}

enum FightcadeConnectionStatusOverride {
    static let forceWiredDefaultsKey = "FightcadeForceWiredConnectionStatus"

    static var forceWired: Bool {
        get { UserDefaults.standard.bool(forKey: forceWiredDefaultsKey) }
        set { UserDefaults.standard.set(newValue, forKey: forceWiredDefaultsKey) }
    }
}

struct FightcadeUserStatusIdentity: Equatable {
    private static let uuidDefaultsKey = "FightcadeUserStatusUUID"
    private static let huidPrefix = "0030613289.684"

    let uuid: String
    let guid: String
    let huid: String

    static func current(userDefaults: UserDefaults = .standard) -> FightcadeUserStatusIdentity {
        let uuid = persistedUUID(userDefaults: userDefaults)
        let platformUUID = platformValue("IOPlatformUUID")
        let serial = platformValue("IOPlatformSerialNumber")
        let guid = platformUUID.flatMap(hashedUUIDString) ?? uuid
        let huidSource = serial ?? platformUUID ?? uuid
        let huid = huidPrefix + FightcadeUserStatusHash.md5(huidSource).replacingOccurrences(of: "-", with: "")

        return FightcadeUserStatusIdentity(uuid: uuid, guid: guid, huid: huid)
    }

    private static func persistedUUID(userDefaults: UserDefaults) -> String {
        if let uuid = userDefaults.string(forKey: uuidDefaultsKey),
           UUID(uuidString: uuid) != nil {
            return uuid.lowercased()
        }

        let uuid = UUID().uuidString.lowercased()
        userDefaults.set(uuid, forKey: uuidDefaultsKey)
        return uuid
    }

    private static func platformValue(_ key: String) -> String? {
        let service = IOServiceGetMatchingService(kIOMainPortDefault, IOServiceMatching("IOPlatformExpertDevice"))
        guard service != IO_OBJECT_NULL else {
            return nil
        }

        defer { IOObjectRelease(service) }
        guard let value = IORegistryEntryCreateCFProperty(service, key as CFString, kCFAllocatorDefault, 0)?
            .takeRetainedValue() as? String else {
            return nil
        }

        let trimmed = value.trimmingCharacters(in: .whitespacesAndNewlines)
        return trimmed.isEmpty ? nil : trimmed
    }

    private static func hashedUUIDString(_ value: String) -> String? {
        guard let uuid = UUID(uuidString: value) else {
            return nil
        }

        let hex = FightcadeUserStatusHash.md5(uuid.uuidString.lowercased())
        let parts = [
            hex.prefix(8),
            hex.dropFirst(8).prefix(4),
            hex.dropFirst(12).prefix(4),
            hex.dropFirst(16).prefix(4),
            hex.dropFirst(20).prefix(12)
        ]
        return parts.map(String.init).joined(separator: "-")
    }
}

enum FightcadeUserStatusHash {
    static func md5(_ value: String) -> String {
        let digest = Insecure.MD5.hash(data: Data(value.utf8))
        return digest.map { String(format: "%02x", $0) }.joined()
    }
}

enum FightcadeCommandOutput {
    static func activeNetworkInterface() -> String? {
        let output = run("/sbin/route", arguments: ["-n", "get", "8.8.8.8"])
        return output?.split(separator: "\n").compactMap { line in
            let parts = line.split(separator: ":", maxSplits: 1).map { $0.trimmingCharacters(in: .whitespaces) }
            guard parts.count == 2, parts[0] == "interface" else {
                return nil
            }

            return parts[1]
        }.first
    }

    static func interfaceIsWiFi(_ interface: String) -> Bool {
        guard let output = run("/usr/sbin/networksetup", arguments: ["-listallhardwareports"]) else {
            return false
        }

        var hardwarePort: String?
        for line in output.split(separator: "\n").map(String.init) {
            if line.hasPrefix("Hardware Port: ") {
                hardwarePort = String(line.dropFirst("Hardware Port: ".count))
            } else if line == "Device: \(interface)" {
                return hardwarePort == "Wi-Fi"
            }
        }

        return false
    }

    private static func run(_ executable: String, arguments: [String]) -> String? {
        let process = Process()
        let output = Pipe()
        process.executableURL = URL(fileURLWithPath: executable)
        process.arguments = arguments
        process.standardOutput = output
        process.standardError = Pipe()

        do {
            try process.run()
            FightcadeProcessRegistry.shared.insert(process, label: URL(fileURLWithPath: executable).lastPathComponent)
            defer { FightcadeProcessRegistry.shared.remove(processID: process.processIdentifier) }
            process.waitUntilExit()
        } catch {
            return nil
        }

        guard process.terminationStatus == 0 else {
            return nil
        }

        let data = output.fileHandleForReading.readDataToEndOfFile()
        return String(data: data, encoding: .utf8)
    }
}
