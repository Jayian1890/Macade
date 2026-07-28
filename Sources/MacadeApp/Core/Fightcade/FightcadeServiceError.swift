import Foundation

enum FightcadeServiceError: LocalizedError, Equatable {
    case networkUnavailable
    case unexpectedResponse(String)

    var errorDescription: String? {
        switch self {
        case .networkUnavailable:
            "Could not connect."
        case .unexpectedResponse(let message):
            message
        }
    }
}
