import Foundation
import Observation

@MainActor
@Observable
final class LoginViewModel {
    var username = ""
    var password = ""
    var isPasswordVisible = false
    var isSubmitting = false
    var errorMessage: String?
    var statusMessage: String?

    private let authenticationService: any AuthenticationServicing

    init(authenticationService: any AuthenticationServicing = FightcadeAuthenticationService()) {
        self.authenticationService = authenticationService
    }

    var canSubmit: Bool {
        !username.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
            && !password.isEmpty
            && !isSubmitting
    }

    func submit() async -> AuthSession? {
        let trimmedUsername = username.trimmingCharacters(in: .whitespacesAndNewlines)

        guard validate(username: trimmedUsername, password: password) else {
            return nil
        }

        errorMessage = nil
        statusMessage = "Connecting"
        isSubmitting = true
        defer { isSubmitting = false }

        do {
            let session = try await authenticationService.signIn(
                with: LoginCredentials(
                    username: trimmedUsername,
                    password: password
                )
            )
            statusMessage = nil
            return session
        } catch let error as AuthenticationError {
            errorMessage = error.localizedDescription
        } catch {
            errorMessage = "Could not complete login."
        }

        statusMessage = nil
        return nil
    }

    private func validate(username: String, password: String) -> Bool {
        if username.isEmpty {
            errorMessage = "Enter your Fightcade username."
            return false
        }

        if password.isEmpty {
            errorMessage = "Enter your Fightcade password."
            return false
        }

        return true
    }
}
