import Foundation

actor FightcadeLobbyService: FightcadeLobbyServicing {
    let session: URLSession
    private let bootstrapService: FightcadeBootstrapService
    private let userStatusReporter: any FightcadeUserStatusReporting
    let diagnostics = FightcadeLobbyDiagnostics()
    let parser = FightcadeLobbyPayloadParser()

    var webSocket: URLSessionWebSocketTask?
    var receiveTask: Task<Void, Never>?
    var heartbeatTask: Task<Void, Never>?
    private var eventContinuations: [UUID: AsyncStream<FightcadeLobbyEvent>.Continuation] = [:]
    var pendingRequestIDs = Set<Int>()
    var pendingResponses: [Int: [String: Any]] = [:]
    var joinedChannelNames = Set<String>()
    var canonicalChannelNames: [String: String] = [:]
    var currentChannelName: String?
    var challengeIDsByChannel: [String: Int] = [:]
    var favoriteChannelKeys = Set<String>()
    var requestIndex = 0
    var nextSendAllowedAt: Date = .distantPast
    var rateLimitedUntil: Date?

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
            startHeartbeat(for: socket)

            let welcomePayload = try? await sendRequest(
                ["req": "welcome"],
                webSocket: socket
            )

            let channelsPayload = try await sendRequest(
                ["req": "channels", "all": true],
                webSocket: socket
            )

            let browserSections = welcomePayload.map(parser.browserSections) ?? []
            let favoriteKeys = favoriteChannelKeys.union(browserSections.favoriteMatchKeys)
            favoriteChannelKeys = favoriteKeys

            let dashboard = FightcadeDashboard(
                connectedUsername: authSession.displayName,
                welcomeMessage: welcomePayload.flatMap(parser.welcomeMessage),
                channels: parser.channels(in: channelsPayload).markingFavorites(matching: favoriteKeys),
                browserSections: browserSections.markingFavorites(matching: favoriteKeys)
            )

            return dashboard
        } catch let error as FightcadeLobbyError {
            try? await closeExistingConnection()
            throw error
        } catch let error as FightcadeServiceError {
            try? await closeExistingConnection()
            throw mapServiceError(error)
        } catch let error as URLError {
            try? await closeExistingConnection()
            throw mapNetworkError(error)
        } catch {
            try? await closeExistingConnection()
            throw FightcadeLobbyError.unexpectedResponse("Could not load lobby.")
        }
    }

    func refreshChannels() async throws {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        let payload = try await sendRequest(["req": "channels", "all": true], webSocket: webSocket)
        emit(.channelsUpdated(parser.channels(in: payload).markingFavorites(matching: favoriteChannelKeys)))
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
        if let motd = parser.channelMotd(in: response, channelName: joinedChannelName) {
            emit(.channelMotd(motd))
        }
        emit(.usersUpdated(joinedChannelName, parser.users(in: response)))
        emit(.joinedChannel(joinedChannelName))
    }

    func leave(channel: FightcadeChannel) async throws {
        guard let webSocket else {
            throw FightcadeLobbyError.loginExpired
        }

        let channelName = canonicalChannelName(for: channel)
        _ = try await sendRequest([
            "req": "leave",
            "channelname": channelName
        ], webSocket: webSocket)

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

    func emit(_ event: FightcadeLobbyEvent) {
        for continuation in eventContinuations.values {
            continuation.yield(event)
        }
    }

    private func removeEventContinuation(_ id: UUID) {
        eventContinuations[id] = nil
    }

}

extension Array where Element == FightcadeChannel {
    func markingFavorites(matching favoriteKeys: Set<String>) -> [FightcadeChannel] {
        map { channel in
            channel.favoriteMatchKeys.isDisjoint(with: favoriteKeys) ? channel : channel.withFavorite(true)
        }
    }
}

private extension Array where Element == FightcadeWelcomeSection {
    var favoriteMatchKeys: Set<String> {
        reduce(into: Set<String>()) { keys, section in
            guard section.title.localizedCaseInsensitiveContains("favorite") else {
                return
            }

            for channel in section.channels {
                keys.formUnion(channel.favoriteMatchKeys)
            }
        }
    }

    func markingFavorites(matching favoriteKeys: Set<String>) -> [FightcadeWelcomeSection] {
        map { section in
            FightcadeWelcomeSection(
                title: section.title,
                channels: section.channels.markingFavorites(matching: favoriteKeys),
                categories: section.categories,
                events: section.events
            )
        }
    }
}
