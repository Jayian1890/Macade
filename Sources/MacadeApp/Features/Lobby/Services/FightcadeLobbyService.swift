import Foundation

actor FightcadeLobbyService: FightcadeLobbyServicing {
    let session: URLSession
    private let bootstrapService: FightcadeBootstrapService
    private let userStatusReporter: any FightcadeUserStatusReporting
    private let diagnostics = FightcadeLobbyDiagnostics()
    let parser = FightcadeLobbyPayloadParser()

    var webSocket: URLSessionWebSocketTask?
    private var receiveTask: Task<Void, Never>?
    private var eventContinuations: [UUID: AsyncStream<FightcadeLobbyEvent>.Continuation] = [:]
    private var pendingRequestIDs = Set<Int>()
    private var pendingResponses: [Int: [String: Any]] = [:]
    private var joinedChannelNames = Set<String>()
    private var canonicalChannelNames: [String: String] = [:]
    private var currentChannelName: String?
    private var challengeIDsByChannel: [String: Int] = [:]
    private var requestIndex = 0
    private var nextSendAllowedAt: Date = .distantPast
    private var rateLimitedUntil: Date?

    init(
        session: URLSession = .shared,
        userStatusReporter: (any FightcadeUserStatusReporting)? = nil
    ) {
        self.session = session
        self.bootstrapService = FightcadeBootstrapService(session: session)
        self.userStatusReporter = userStatusReporter ?? FightcadeUserStatusReporter(session: session)
    }

    func eventStream() -> AsyncStream<FightcadeLobbyEvent> {
        let id = UUID()
        return AsyncStream { continuation in
            eventContinuations[id] = continuation
            continuation.onTermination = { [weak self] _ in
                Task { await self?.removeEventContinuation(id) }
            }
        }
    }

    func connect(for authSession: AuthSession) async throws -> FightcadeDashboard {
        do {
            try await closeExistingConnection()

            let cookie = authSession.sessionCookie
            guard let cookie, !cookie.isEmpty else {
                throw FightcadeLobbyError.missingSessionCookie
            }

            let location = try await bootstrapService.requestEncryptedLocation()
            let socket = makeWebSocket()
            webSocket = socket
            socket.resume()

            let launcherToken = try await autologin(cookie: cookie, location: location, webSocket: socket)
                ?? authSession.launcherToken
            if let token = launcherToken {
                try? await userStatusReporter.report(token: token)
                diagnostics.note("reported launcher userstatus tokenPresent=true")
            } else {
                diagnostics.note("skipped launcher userstatus tokenPresent=false")
            }

            startReceiveLoop(for: socket)

            let welcomePayload = try? await sendRequest(
                ["req": "welcome"],
                webSocket: socket
            )

            let channelsPayload = try await sendRequest(
                ["req": "channels", "all": true],
                webSocket: socket
            )

            let dashboard = FightcadeDashboard(
                connectedUsername: authSession.displayName,
                welcomeMessage: welcomePayload.flatMap(parser.welcomeMessage),
                channels: parser.channels(in: channelsPayload)
            )

            return dashboard
        } catch let error as FightcadeLobbyError {
            throw error
        } catch let error as FightcadeServiceError {
            throw mapServiceError(error)
        } catch let error as URLError {
            throw mapNetworkError(error)
        } catch {
            throw FightcadeLobbyError.unexpectedResponse("Could not load lobby.")
        }
    }

    func refreshChannels() async throws {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        let payload = try await sendRequest(["req": "channels", "all": true], webSocket: webSocket)
        emit(.channelsUpdated(parser.channels(in: payload)))
    }

    func join(channel: FightcadeChannel) async throws {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        if let canonicalName = canonicalChannelNames[channel.name], joinedChannelNames.contains(canonicalName) {
            currentChannelName = canonicalName
            return
        }

        let response = try await sendRequest(joinPayload(for: channel.name), webSocket: webSocket)

        let joinedChannelName = parser.channelName(in: response) ?? channel.name
        diagnostics.note("joined requested=\(channel.name) canonical=\(joinedChannelName)")
        joinedChannelNames.insert(joinedChannelName)
        canonicalChannelNames[channel.name] = joinedChannelName
        canonicalChannelNames[joinedChannelName] = joinedChannelName
        currentChannelName = joinedChannelName
        emit(.usersUpdated(joinedChannelName, parser.users(in: response)))
        emit(.joinedChannel(joinedChannelName))
    }

    func leave(channel: FightcadeChannel) async throws {
        let channelName = canonicalChannelName(for: channel)
        guard joinedChannelNames.contains(channelName) else {
            return
        }

        try await send([
            "req": "leave",
            "channelname": channelName,
            "requestIdx": -1
        ])

        joinedChannelNames.remove(channelName)
        canonicalChannelNames[channel.name] = nil
        canonicalChannelNames[channelName] = nil
        if currentChannelName == channelName {
            currentChannelName = joinedChannelNames.first
        }
        emit(.leftChannel(channelName))
    }

    func sendChat(_ message: String, to channel: FightcadeChannel, from _: String) async throws {
        let trimmedMessage = message.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !trimmedMessage.isEmpty else {
            return
        }

        if canonicalChannelNames[channel.name] == nil {
            try await join(channel: channel)
        }

        let channelName = canonicalChannelName(for: channel)
        currentChannelName = channelName

        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        _ = try await sendRequest([
            "req": "chat",
            "channelname": channelName,
            "chat": trimmedMessage
        ], webSocket: webSocket)
    }

    func challenge(
        _ user: FightcadeChannelUser,
        in channel: FightcadeChannel,
        ranked: Int
    ) async throws -> FightcadeChallenge {
        if canonicalChannelNames[channel.name] == nil {
            try await join(channel: channel)
        }

        let channelName = canonicalChannelName(for: channel)

        let challengeID = nextChallengeID(for: channelName)
        let challenge = FightcadeChallenge(
            username: user.name,
            channelName: channelName,
            challengeID: challengeID,
            ranked: ranked
        )

        try await sendChallengeRequest("challenge", challenge: challenge)
        return challenge
    }

    func acceptChallenge(_ challenge: FightcadeChallenge) async throws {
        try await sendChallengeRequest("accept", challenge: challenge)
    }

    func rejectChallenge(_ challenge: FightcadeChallenge) async throws {
        try await sendChallengeRequest("reject", challenge: challenge)
    }

    func cancelChallenge(_ challenge: FightcadeChallenge) async throws {
        try await sendChallengeRequest("cancel", challenge: challenge)
    }

    func disconnect() async {
        try? await closeExistingConnection()
    }

    private func sendChallengeRequest(_ request: String, challenge: FightcadeChallenge) async throws {
        var payload: [String: Any] = [
            "req": request,
            "username": challenge.username,
            "channelname": challenge.channelName,
            "challengeid": challenge.challengeID
        ]

        if request == "challenge" || request == "accept" {
            payload["ranked"] = challenge.ranked
        }

        try await send(payload)
    }

    private func makeWebSocket() -> URLSessionWebSocketTask {
        var request = URLRequest(url: FightcadeEndpoint.websocketURL)
        request.timeoutInterval = FightcadeEndpoint.timeout
        request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")
        return session.webSocketTask(with: request)
    }

    private func autologin(cookie: String, location: String, webSocket: URLSessionWebSocketTask) async throws -> String? {
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

    private func startReceiveLoop(for webSocket: URLSessionWebSocketTask) {
        receiveTask = Task { [weak self] in
            await self?.receiveLoop(webSocket: webSocket)
        }
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
                emit(.error("Connection closed."))
                return
            }
        }
    }

    private func send(_ payload: [String: Any]) async throws {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        try await send(payload, webSocket: webSocket)
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

    private func nextRequestIndex() -> Int {
        defer { requestIndex += 1 }
        return requestIndex
    }

    private func nextChallengeID(for channelName: String) -> Int {
        let nextID = (challengeIDsByChannel[channelName] ?? 0) + 1
        challengeIDsByChannel[channelName] = nextID
        return nextID
    }

    private func joinPayload(for channelName: String) -> [String: Any] {
        [
            "req": "join",
            "channelname": channelName,
            "status": "available",
            "away": false,
            "idx": -1
        ]
    }

    private func canonicalChannelName(for channel: FightcadeChannel) -> String {
        canonicalChannelNames[channel.name] ?? channel.name
    }

    private func emit(_ event: FightcadeLobbyEvent) {
        for continuation in eventContinuations.values {
            continuation.yield(event)
        }
    }

    private func removeEventContinuation(_ id: UUID) {
        eventContinuations[id] = nil
    }

    private func closeExistingConnection() async throws {
        receiveTask?.cancel()
        receiveTask = nil
        currentChannelName = nil
        joinedChannelNames.removeAll()
        canonicalChannelNames.removeAll()
        challengeIDsByChannel.removeAll()
        pendingRequestIDs.removeAll()
        pendingResponses.removeAll()
        rateLimitedUntil = nil
        nextSendAllowedAt = .distantPast
        webSocket?.cancel(with: .normalClosure, reason: nil)
        webSocket = nil
    }

    private func mapServiceError(_ error: FightcadeServiceError) -> FightcadeLobbyError {
        switch error {
        case .networkUnavailable:
            .networkUnavailable
        case .unexpectedResponse(let message):
            .unexpectedResponse(message)
        }
    }

    private func mapNetworkError(_ error: URLError) -> FightcadeLobbyError {
        switch error.code {
        case .notConnectedToInternet, .cannotFindHost, .cannotConnectToHost, .networkConnectionLost, .timedOut:
            .networkUnavailable
        default:
            .unexpectedResponse("Could not load lobby.")
        }
    }
}

private enum FightcadeLobbyLimit {
    static let maximumMessagesPerRequest = 24
    static let requestTimeoutSeconds: Double = 12
    static let pollMilliseconds = 50
    static let minimumSendIntervalSeconds: TimeInterval = 0.75
    static let rateLimitCooldownSeconds: TimeInterval = 30
}
