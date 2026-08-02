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
    case scheduled(MacadeUpdate, secondsRemaining: Int)
    case downloading(MacadeUpdate)
    case downloaded(MacadeUpdate, URL)
    case installing(MacadeUpdate)
    case failed(String)
}

enum MacadeUpdaterError: LocalizedError {
    case invalidResponse
    case noInstallableAsset
    case checksumMismatch
    case unsupportedInstallAsset
    case installFailed

    var errorDescription: String? {
        switch self {
        case .invalidResponse:
            "GitHub returned an update response Macade could not read."
        case .noInstallableAsset:
            "The latest release does not include a macOS .dmg, .pkg, or .zip asset."
        case .checksumMismatch:
            "The downloaded update did not match its published SHA-256 checksum."
        case .unsupportedInstallAsset:
            "The downloaded update is not a supported macOS installer asset."
        case .installFailed:
            "Macade could not stage or launch the automatic update installer."
        }
    }
}
