import Foundation

struct MacadeUpdate: Identifiable, Equatable {
    let id: String
    let version: String
    let tagName: String
    let name: String
    let body: String
    let publishedAt: Date?
    let htmlURL: URL
    let asset: MacadeUpdateAsset
    let checksumAsset: MacadeUpdateAsset?
}

struct MacadeUpdateAsset: Equatable {
    let name: String
    let downloadURL: URL
    let size: Int
}

enum MacadeUpdateStatus: Equatable {
    case idle
    case checking
    case current
    case available(MacadeUpdate)
    case downloading(MacadeUpdate)
    case downloaded(MacadeUpdate, URL)
    case failed(String)
}

enum MacadeUpdaterError: LocalizedError {
    case invalidResponse
    case noInstallableAsset
    case checksumMismatch

    var errorDescription: String? {
        switch self {
        case .invalidResponse:
            "GitHub returned an update response Macade could not read."
        case .noInstallableAsset:
            "The latest release does not include a macOS .dmg, .pkg, or .zip asset."
        case .checksumMismatch:
            "The downloaded update did not match its published SHA-256 checksum."
        }
    }
}
