import Foundation

extension FightcadeLobbyService {
    func makeWebSocket() -> URLSessionWebSocketTask {
        var request = URLRequest(url: FightcadeEndpoint.websocketURL)
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")
        return session.webSocketTask(with: request)
    }

    func autologin(cookie: String, location: String, webSocket: URLSessionWebSocketTask) async throws -> String? {
        try await send(
            [
                "req": "autologin",
                "cookie": cookie,
                "location": location,
                "requestIdx": -1
            ],
            webSocket: webSocket
        )

        for _ in 0..<FightcadeLobbyLimit.maximumMessagesPerRequest {
            let payload = try await receivePayload(from: webSocket)

            if let error = parser.loginError(in: payload) {
                throw error
            }

            if parser.hasLoggedInUser(in: payload) {
                favoriteChannelKeys = parser.favoriteChannelKeys(in: payload)
                return parser.launcherToken(in: payload)
            }
        }

        throw FightcadeLobbyError.loginExpired
    }

    func sendRequest(
        _ payload: [String: Any],
        webSocket: URLSessionWebSocketTask
    ) async throws -> [String: Any] {
        var request = payload
        let requestIdx = nextRequestIndex()
        request["requestIdx"] = requestIdx
        pendingRequestIDs.insert(requestIdx)

        do {
            try await send(request, webSocket: webSocket)
            return try await waitForResponse(requestIdx)
        } catch {
            pendingRequestIDs.remove(requestIdx)
            pendingResponses[requestIdx] = nil
            throw error
        }
    }

    func startReceiveLoop(for webSocket: URLSessionWebSocketTask) {
        receiveTask = Task { [weak self] in
            await self?.receiveLoop(webSocket: webSocket)
        }
    }

    func startHeartbeat(for webSocket: URLSessionWebSocketTask) {
        heartbeatTask?.cancel()
        heartbeatTask = Task { [weak self] in
            await self?.heartbeatLoop(webSocket: webSocket)
        }
    }

    func send(_ payload: [String: Any]) async throws {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        try await send(payload, webSocket: webSocket)
    }

    func closeExistingConnection() async throws {
        receiveTask?.cancel()
        receiveTask = nil
        heartbeatTask?.cancel()
        heartbeatTask = nil
        currentChannelName = nil
        joinedChannelNames.removeAll()
        canonicalChannelNames.removeAll()
        challengeIDsByChannel.removeAll()
        favoriteChannelKeys.removeAll()
        pendingRequestIDs.removeAll()
        pendingResponses.removeAll()
        rateLimitedUntil = nil
        nextSendAllowedAt = .distantPast
        webSocket?.cancel(with: .normalClosure, reason: nil)
        webSocket = nil
    }

    func mapServiceError(_ error: FightcadeServiceError) -> FightcadeLobbyError {
        switch error {
        case .networkUnavailable:
            .networkUnavailable
        case .unexpectedResponse(let message):
            .unexpectedResponse(message)
        }
    }

    func mapNetworkError(_ error: URLError) -> FightcadeLobbyError {
        switch error.code {
        case .notConnectedToInternet, .cannotFindHost, .cannotConnectToHost, .networkConnectionLost, .timedOut:
            .networkUnavailable
        default:
            .unexpectedResponse("Could not load lobby.")
        }
    }

    private func waitForResponse(_ requestIdx: Int) async throws -> [String: Any] {
        let deadline = Date().addingTimeInterval(FightcadeLobbyLimit.requestTimeoutSeconds)

        while Date() < deadline {
            if let payload = pendingResponses.removeValue(forKey: requestIdx) {
                pendingRequestIDs.remove(requestIdx)

                if parser.isRateLimitError(in: payload) {
                    noteRateLimited()
                }

                if let error = parser.responseError(in: payload) {
                    throw error
                }

                return payload
            }

            guard webSocket != nil else {
                throw FightcadeLobbyError.loginExpired
            }

            try await Task.sleep(for: .milliseconds(FightcadeLobbyLimit.pollMilliseconds))
        }

        pendingRequestIDs.remove(requestIdx)
        throw FightcadeLobbyError.unexpectedResponse("Request timed out.")
    }

    private func receiveLoop(webSocket: URLSessionWebSocketTask) async {
        while !Task.isCancelled {
            do {
                let payload = try await receivePayload(from: webSocket)
                if let requestIdx = parser.requestIndex(in: payload), pendingRequestIDs.contains(requestIdx) {
                    pendingResponses[requestIdx] = payload
                    continue
                }

                if parser.isRateLimitError(in: payload) {
                    noteRateLimited()
                }

                if let event = parser.event(in: payload, currentChannelName: currentChannelName) {
                    emit(event)
                }
            } catch {
                closeConnection(for: webSocket, emitting: "Connection closed.")
                return
            }
        }
    }

    private func heartbeatLoop(webSocket: URLSessionWebSocketTask) async {
        while !Task.isCancelled {
            do {
                try await Task.sleep(for: .seconds(FightcadeLobbyLimit.heartbeatIntervalSeconds))
                guard !Task.isCancelled else { return }
                try await sendPing(to: webSocket, timeout: .seconds(FightcadeLobbyLimit.heartbeatTimeoutSeconds))
            } catch is CancellationError {
                return
            } catch {
                closeConnection(for: webSocket, emitting: "Connection lost.")
                return
            }
        }
    }

    private func send(_ payload: [String: Any], webSocket: URLSessionWebSocketTask) async throws {
        try await reserveLobbySendSlot()

        let data = try JSONSerialization.data(withJSONObject: payload)
        guard let message = String(data: data, encoding: .utf8) else {
            throw FightcadeLobbyError.unexpectedResponse("Could not complete request.")
        }

        diagnostics.outgoing(payload)
        try await webSocket.send(.string(message))
    }

    private func reserveLobbySendSlot() async throws {
        let now = Date()
        if let rateLimitedUntil, rateLimitedUntil > now {
            throw FightcadeLobbyError.rateLimited
        }

        let sendAt = max(now, nextSendAllowedAt)
        nextSendAllowedAt = sendAt.addingTimeInterval(FightcadeLobbyLimit.minimumSendIntervalSeconds)

        let delay = sendAt.timeIntervalSince(now)
        if delay > 0 {
            try await Task.sleep(for: .milliseconds(Int(delay * 1000)))
        }

        if let rateLimitedUntil, rateLimitedUntil > Date() {
            throw FightcadeLobbyError.rateLimited
        }
    }

    private func noteRateLimited() {
        let until = Date().addingTimeInterval(FightcadeLobbyLimit.rateLimitCooldownSeconds)
        rateLimitedUntil = until
        if nextSendAllowedAt < until {
            nextSendAllowedAt = until
        }
        diagnostics.note("rate limited; suppressing lobby requests for \(Int(FightcadeLobbyLimit.rateLimitCooldownSeconds))s")
    }

    private func receivePayload(from webSocket: URLSessionWebSocketTask) async throws -> [String: Any] {
        let message = try await webSocket.receive()

        switch message {
        case .string(let text):
            guard let data = text.data(using: .utf8) else {
                throw FightcadeLobbyError.unexpectedResponse("Could not load lobby.")
            }
            let payload = try parser.decodeJSONObject(from: data)
            diagnostics.incoming(payload)
            return payload
        case .data(let data):
            let payload = try parser.decodeJSONObject(from: data)
            diagnostics.incoming(payload)
            return payload
        @unknown default:
            throw FightcadeLobbyError.unexpectedResponse("Could not load lobby.")
        }
    }

    private func sendPing(to webSocket: URLSessionWebSocketTask, timeout: Duration) async throws {
        try await withCheckedThrowingContinuation { continuation in
            let once = FightcadeLobbyContinuation(continuation)
            webSocket.sendPing { error in
                if let error {
                    once.resume(throwing: error)
                } else {
                    once.resume()
                }
            }

            Task.detached {
                do {
                    try await Task.sleep(for: timeout)
                    once.resume(throwing: FightcadeLobbyError.networkUnavailable)
                } catch {
                    once.resume(throwing: error)
                }
            }
        }
    }

    private func nextRequestIndex() -> Int {
        defer { requestIndex += 1 }
        return requestIndex
    }

    private func closeConnection(for socket: URLSessionWebSocketTask, emitting message: String) {
        guard webSocket === socket else {
            return
        }

        receiveTask?.cancel()
        receiveTask = nil
        heartbeatTask?.cancel()
        heartbeatTask = nil
        pendingRequestIDs.removeAll()
        pendingResponses.removeAll()
        rateLimitedUntil = nil
        nextSendAllowedAt = .distantPast
        socket.cancel(with: .normalClosure, reason: nil)
        webSocket = nil
        emit(.error(message))
    }
}

private enum FightcadeLobbyLimit {
    static let maximumMessagesPerRequest = 24
    static let requestTimeoutSeconds: Double = 12
    static let pollMilliseconds = 50
    static let minimumSendIntervalSeconds: TimeInterval = 0.75
    static let rateLimitCooldownSeconds: TimeInterval = 30
    static let heartbeatIntervalSeconds: Int64 = 45
    static let heartbeatTimeoutSeconds: Int64 = 10
}

private final class FightcadeLobbyContinuation: @unchecked Sendable {
    private let lock = NSLock()
    private var continuation: CheckedContinuation<Void, any Error>?

    init(_ continuation: CheckedContinuation<Void, any Error>) {
        self.continuation = continuation
    }

    func resume() {
        resume(with: .success(()))
    }

    func resume(throwing error: any Error) {
        resume(with: .failure(error))
    }

    private func resume(with result: Result<Void, any Error>) {
        let continuation = lock.withLock {
            let continuation = self.continuation
            self.continuation = nil
            return continuation
        }

        switch result {
        case .success:
            continuation?.resume()
        case .failure(let error):
            continuation?.resume(throwing: error)
        }
    }
}
