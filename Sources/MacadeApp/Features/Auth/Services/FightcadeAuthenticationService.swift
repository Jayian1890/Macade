import Foundation

struct FightcadeAuthenticationService: AuthenticationServicing {
    private let session: URLSession
    private let bootstrapService: FightcadeBootstrapService

    init(session: URLSession = .shared) {
        self.session = session
        self.bootstrapService = FightcadeBootstrapService(session: session)
    }

    func signIn(with credentials: LoginCredentials) async throws -> AuthSession {
        do {
            let location = try await bootstrapService.requestEncryptedLocation()
            let outcome = try await authenticate(credentials: credentials, location: location)
            guard let cookie = outcome.cookie, !cookie.isEmpty else {
                throw AuthenticationError.unexpectedResponse("Could not open lobby.")
            }

            return AuthSession(
                username: outcome.username,
                displayName: outcome.displayName,
                sessionCookie: cookie,
                launcherToken: outcome.launcherToken
            )
            .stored()
        } catch let error as AuthenticationError {
            throw error
        } catch let error as FightcadeServiceError {
            throw mapServiceError(error)
        } catch let error as URLError {
            throw mapNetworkError(error)
        } catch {
            throw AuthenticationError.unexpectedResponse("Could not complete login.")
        }
    }

    func restoreSession() async throws -> AuthSession? {
        guard let cookie = FightcadeSessionDefaults.cookie else {
            return nil
        }

        do {
            let location = try await bootstrapService.requestEncryptedLocation()
            let outcome = try await authenticate(cookie: cookie, location: location)
            return AuthSession(
                username: outcome.username,
                displayName: outcome.displayName,
                sessionCookie: outcome.cookie ?? cookie,
                launcherToken: outcome.launcherToken
            )
            .stored()
        } catch let error as AuthenticationError {
            if error == .invalidCredentials {
                FightcadeSessionDefaults.clear()
            }

            throw error
        } catch let error as FightcadeServiceError {
            throw mapServiceError(error)
        } catch let error as URLError {
            throw mapNetworkError(error)
        } catch {
            throw AuthenticationError.unexpectedResponse("Could not complete login.")
        }
    }

    func signOut() throws {
        FightcadeSessionDefaults.clear()
    }

    private func authenticate(credentials: LoginCredentials, location: String) async throws -> FightcadeLoginOutcome {
        var request = URLRequest(url: FightcadeEndpoint.websocketURL)
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")

        let webSocket = session.webSocketTask(with: request)
        webSocket.resume()
        defer { webSocket.cancel(with: .normalClosure, reason: nil) }

        let loginRequest: [String: Any] = [
            "req": "login",
            "username": credentials.username,
            "userpass": credentials.password,
            "location": location,
            "requestIdx": -1
        ]
        let data = try JSONSerialization.data(withJSONObject: loginRequest)
        guard let message = String(data: data, encoding: .utf8) else {
            throw AuthenticationError.unexpectedResponse("Could not complete login.")
        }

        try await webSocket.send(.string(message))
        return try await receiveLoginOutcome(from: webSocket)
    }

    private func authenticate(cookie: String, location: String) async throws -> FightcadeLoginOutcome {
        var request = URLRequest(url: FightcadeEndpoint.websocketURL)
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")

        let webSocket = session.webSocketTask(with: request)
        webSocket.resume()
        defer { webSocket.cancel(with: .normalClosure, reason: nil) }

        let autologinRequest: [String: Any] = [
            "req": "autologin",
            "cookie": cookie,
            "location": location,
            "requestIdx": -1
        ]
        let data = try JSONSerialization.data(withJSONObject: autologinRequest)
        guard let message = String(data: data, encoding: .utf8) else {
            throw AuthenticationError.unexpectedResponse("Could not complete login.")
        }

        try await webSocket.send(.string(message))
        return try await receiveLoginOutcome(from: webSocket)
    }

    private func receiveLoginOutcome(from webSocket: URLSessionWebSocketTask) async throws -> FightcadeLoginOutcome {
        for _ in 0..<FightcadeAuthenticationLimit.maximumLoginMessages {
            let message = try await webSocket.receive()
            let payload: [String: Any]

            switch message {
            case .string(let text):
                guard let data = text.data(using: .utf8) else {
                    continue
                }
                payload = try decodeJSONObject(from: data)
            case .data(let data):
                payload = try decodeJSONObject(from: data)
            @unknown default:
                continue
            }

            if let error = loginError(in: payload) {
                throw error
            }

            if let outcome = loginOutcome(in: payload) {
                return outcome
            }
        }

        throw AuthenticationError.unexpectedResponse("Could not complete login.")
    }

    private func decodeJSONObject(from data: Data) throws -> [String: Any] {
        guard let payload = try JSONSerialization.jsonObject(with: data) as? [String: Any] else {
            throw AuthenticationError.unexpectedResponse("Could not complete login.")
        }

        return payload
    }

    private func loginOutcome(in payload: [String: Any]) -> FightcadeLoginOutcome? {
        let candidates = nestedDictionaries(in: payload) + [payload]

        for candidate in candidates {
            guard let username = stringValue(in: candidate, keys: ["name", "username", "user"]),
                  !username.isEmpty else {
                continue
            }

            let displayName = stringValue(in: candidate, keys: ["displayName", "display_name", "nick", "name", "username"])
                ?? username
            let cookie = stringValue(in: payload, keys: ["cookie", "fcic"])
                ?? stringValue(in: candidate, keys: ["cookie", "fcic"])
            let launcherToken = stringValue(in: candidate, keys: ["token"])
                ?? stringValue(in: payload, keys: ["token"])

            return FightcadeLoginOutcome(username: username, displayName: displayName, cookie: cookie, launcherToken: launcherToken)
        }

        return nil
    }

    private func nestedDictionaries(in payload: [String: Any]) -> [[String: Any]] {
        var dictionaries: [[String: Any]] = []

        for key in ["user", "player", "account", "result", "data"] {
            if let dictionary = payload[key] as? [String: Any] {
                dictionaries.append(dictionary)

                if let user = dictionary["user"] as? [String: Any] {
                    dictionaries.append(user)
                }
            }
        }

        return dictionaries
    }

    private func loginError(in payload: [String: Any]) -> AuthenticationError? {
        let status = stringValue(in: payload, keys: ["res", "result", "status"])
        let message = stringValue(in: payload, keys: ["error", "err", "msg", "message"])

        if let status, ["KO", "ERROR", "FAIL", "FAILED"].contains(status.uppercased()) {
            return mapLoginMessage(message)
        }

        if let message {
            let normalized = message.lowercased()
            if normalized.contains("invalid")
                || normalized.contains("password")
                || normalized.contains("credential")
                || normalized.contains("login") {
                return .invalidCredentials
            }
        }

        return nil
    }

    private func mapLoginMessage(_ message: String?) -> AuthenticationError {
        guard let message else {
            return .invalidCredentials
        }

        let normalized = message.lowercased()
        if normalized.contains("invalid")
            || normalized.contains("password")
            || normalized.contains("credential") {
            return .invalidCredentials
        }

        return .unexpectedResponse(message)
    }

    private func mapNetworkError(_ error: URLError) -> AuthenticationError {
        switch error.code {
        case .notConnectedToInternet, .cannotFindHost, .cannotConnectToHost, .networkConnectionLost, .timedOut:
            .networkUnavailable
        default:
            .unexpectedResponse("Could not complete login.")
        }
    }

    private func mapServiceError(_ error: FightcadeServiceError) -> AuthenticationError {
        switch error {
        case .networkUnavailable:
            .networkUnavailable
        case .unexpectedResponse(let message):
            .unexpectedResponse(message)
        }
    }

    private func stringValue(in dictionary: [String: Any], keys: [String]) -> String? {
        for key in keys {
            if let value = dictionary[key] as? String {
                return value
            }

            if let number = dictionary[key] as? NSNumber {
                return number.stringValue
            }
        }

        return nil
    }
}

private struct FightcadeLoginOutcome: Sendable {
    let username: String
    let displayName: String
    let cookie: String?
    let launcherToken: String?
}

private enum FightcadeAuthenticationLimit {
    static let maximumLoginMessages = 12
}

private enum FightcadeSessionDefaults {
    private static let cookieKey = "FightcadeSessionCookie"

    static var cookie: String? {
        UserDefaults.standard.string(forKey: cookieKey)
    }

    static func store(cookie: String) {
        UserDefaults.standard.set(cookie, forKey: cookieKey)
    }

    static func clear() {
        UserDefaults.standard.removeObject(forKey: cookieKey)
    }
}

private extension AuthSession {
    func stored() -> AuthSession {
        if let sessionCookie, !sessionCookie.isEmpty {
            FightcadeSessionDefaults.store(cookie: sessionCookie)
        }

        return self
    }
}
