import CryptoKit
import Foundation

@MainActor
struct GitHubReleaseUpdater {
    var owner = "Jayian1890"
    var repository = "Macade"
    var session: URLSession = .shared
    var fileManager: FileManager = .default

    func latestUpdate(currentVersion: String) async throws -> MacadeUpdate? {
        let release = try await latestRelease()
        let version = release.tagName.trimmingVersionPrefix()
        guard version.isNewer(than: currentVersion) else {
            return nil
        }
        guard let asset = release.assets.first(where: { $0.isInstallableMacAsset }) else {
            throw MacadeUpdaterError.noInstallableAsset
        }
        let checksum = release.assets.first { $0.isChecksumFor(assetName: asset.name) }
        return MacadeUpdate(
            id: release.id.description,
            version: version,
            tagName: release.tagName,
            name: release.name.isEmpty ? release.tagName : release.name,
            body: release.body,
            publishedAt: release.publishedAt,
            htmlURL: release.htmlURL,
            asset: asset.updateAsset,
            checksumAsset: checksum?.updateAsset
        )
    }

    func download(_ update: MacadeUpdate) async throws -> URL {
        let directory = try updatesDirectory()
        let destination = directory.appendingPathComponent(update.asset.name)
        if fileManager.fileExists(atPath: destination.path) {
            try fileManager.removeItem(at: destination)
        }
        let (temporaryURL, response) = try await session.download(from: update.asset.downloadURL)
        guard (response as? HTTPURLResponse)?.isSuccessful == true else {
            throw MacadeUpdaterError.invalidResponse
        }
        try fileManager.moveItem(at: temporaryURL, to: destination)
        if let checksumAsset = update.checksumAsset {
            try await verifyChecksum(for: destination, checksumAsset: checksumAsset)
        }
        return destination
    }

    private func latestRelease() async throws -> GitHubRelease {
        let url = URL(string: "https://api.github.com/repos/\(owner)/\(repository)/releases/latest")!
        var request = URLRequest(url: url)
        request.setValue("application/vnd.github+json", forHTTPHeaderField: "Accept")
        request.setValue("Macade", forHTTPHeaderField: "User-Agent")
        let (data, response) = try await session.data(for: request)
        guard (response as? HTTPURLResponse)?.isSuccessful == true else {
            throw MacadeUpdaterError.invalidResponse
        }
        let decoder = JSONDecoder()
        decoder.dateDecodingStrategy = .iso8601
        return try decoder.decode(GitHubRelease.self, from: data)
    }

    private func verifyChecksum(for fileURL: URL, checksumAsset: MacadeUpdateAsset) async throws {
        let (data, response) = try await session.data(from: checksumAsset.downloadURL)
        guard (response as? HTTPURLResponse)?.isSuccessful == true,
              let text = String(data: data, encoding: .utf8),
              let expected = text.split(whereSeparator: { $0 == " " || $0 == "\n" || $0 == "\t" }).first else {
            throw MacadeUpdaterError.invalidResponse
        }
        let fileData = try Data(contentsOf: fileURL)
        let actual = SHA256.hash(data: fileData).map { String(format: "%02x", $0) }.joined()
        if actual.lowercased() != expected.lowercased() {
            throw MacadeUpdaterError.checksumMismatch
        }
    }

    private func updatesDirectory() throws -> URL {
        let root = try fileManager.url(
            for: .applicationSupportDirectory,
            in: .userDomainMask,
            appropriateFor: nil,
            create: true
        ).appendingPathComponent("Macade/Updates", isDirectory: true)
        try fileManager.createDirectory(at: root, withIntermediateDirectories: true)
        return root
    }
}

private struct GitHubRelease: Decodable {
    let id: Int
    let tagName: String
    let name: String
    let body: String
    let htmlURL: URL
    let publishedAt: Date?
    let assets: [GitHubReleaseAsset]

    enum CodingKeys: String, CodingKey {
        case id
        case tagName = "tag_name"
        case name
        case body
        case htmlURL = "html_url"
        case publishedAt = "published_at"
        case assets
    }
}

private struct GitHubReleaseAsset: Decodable {
    let name: String
    let browserDownloadURL: URL
    let size: Int

    var isInstallableMacAsset: Bool {
        let lower = name.lowercased()
        let isArchive = lower.hasSuffix(".dmg") || lower.hasSuffix(".pkg") || lower.hasSuffix(".zip")
        return isArchive && lower.contains("macade")
    }

    var updateAsset: MacadeUpdateAsset {
        MacadeUpdateAsset(name: name, downloadURL: browserDownloadURL, size: size)
    }

    func isChecksumFor(assetName: String) -> Bool {
        let lower = name.lowercased()
        let asset = assetName.lowercased()
        return lower == "\(asset).sha256" || lower == "\(asset).sha256.txt" || lower == "sha256sums.txt"
    }

    enum CodingKeys: String, CodingKey {
        case name
        case browserDownloadURL = "browser_download_url"
        case size
    }
}

private extension HTTPURLResponse {
    var isSuccessful: Bool { (200..<300).contains(statusCode) }
}

private extension String {
    func trimmingVersionPrefix() -> String {
        let trimmed = trimmingCharacters(in: .whitespacesAndNewlines)
        if trimmed.lowercased().hasPrefix("v") {
            return String(trimmed.dropFirst())
        }
        return trimmed
    }

    func isNewer(than other: String) -> Bool {
        compareVersion(to: other) == .orderedDescending
    }

    func compareVersion(to other: String) -> ComparisonResult {
        let lhs = versionParts
        let rhs = other.versionParts
        for index in 0..<max(lhs.count, rhs.count) {
            let left = index < lhs.count ? lhs[index] : 0
            let right = index < rhs.count ? rhs[index] : 0
            if left > right { return .orderedDescending }
            if left < right { return .orderedAscending }
        }
        return .orderedSame
    }

    var versionParts: [Int] {
        split(separator: ".").map { part in
            Int(part.prefix { $0.isNumber }) ?? 0
        }
    }
}
