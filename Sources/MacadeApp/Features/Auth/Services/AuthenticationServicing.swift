import Foundation

protocol AuthenticationServicing: Sendable {
    func signIn(with credentials: LoginCredentials) async throws -> AuthSession
    func restoreSession() async throws -> AuthSession?
    func signOut() throws
}

enum AuthenticationError: LocalizedError, Equatable {
    case invalidCredentials
    case networkUnavailable
    case sessionStorageFailed
    case unexpectedResponse(String)

    var errorDescription: String? {
        switch self {
        case .invalidCredentials:
            "The username or password was not accepted."
        case .networkUnavailable:
            "Could not reach login."
        case .sessionStorageFailed:
            "Could not save session."
        case .unexpectedResponse(let message):
            message
        }
    }
}
