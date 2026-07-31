import Foundation
import Observation

@MainActor
@Observable
final class AuthenticatedHomeViewModel {
    let session: AuthSession
    var dashboard: FightcadeDashboard?
    var selectedChannelID: FightcadeChannel.ID?
    var joinedChannelIDs = Set<FightcadeChannel.ID>()
    var chatDraft = ""
    var isLoading = false
    var isJoining = false
    var isLeavingChannel = false
    var isSendingChat = false
    var isLaunchingGame = false
    var isDownloadingROM = false
    var isDeletingROM = false
    var isShowingFBNeoSettings = false
    var errorMessage: String?
    var chatMessagesByChannel: [String: [FightcadeChatMessage]] = [:]
    var pendingSentMessages: [String: [(body: String, sentAt: Date)]] = [:]
    var usersByChannel: [String: [FightcadeChannelUser]] = [:]
    var incomingChallenges: [FightcadeChallenge] = []
    var outgoingChallenges: [FightcadeChallenge] = []
    var activeEmulationSession: FightcadeEmbeddedSession?
    var activeMatchOpponentUsername: String?
    var activeMatchOpponentChannelName: String?
    var browser = FightcadeChannelBrowserState()
    var upcomingEvents: [FightcadeEvent] = []
    var isShowingChannelChat = false
    var isSendingChallenge = false
    var isShowingChannelBrowser = true
    var isLobbyDiagnosticsEnabled: Bool {
        didSet {
            diagnosticsSettings.isEnabled = isLobbyDiagnosticsEnabled
            if !isLobbyDiagnosticsEnabled {
                includeLobbyDiagnosticChatBodies = false
            }
        }
    }
    var playerListFocusRequest: PlayerListFocusRequest?
    var chatTranslation = ChatTranslationStore(preferences: ChatTranslationPreferencesStore().load())
    var includeLobbyDiagnosticChatBodies: Bool {
        didSet {
            diagnosticsSettings.includesChatBodies = isLobbyDiagnosticsEnabled && includeLobbyDiagnosticChatBodies
        }
    }

    let lobbyService: any FightcadeLobbyServicing
    let romDownloader: any FightcadeROMDownloading
    let romLibrary: any FightcadeROMLibraryServicing
    let launcher: any FightcadeLaunching
    let joinedChannelStore: any JoinedChannelPersisting
    let channelCache: any FightcadeChannelCaching
    private let diagnosticsSettings: FightcadeLobbyDiagnosticsSettings
    private var eventTask: Task<Void, Never>?
    private var joiningChannelIDs = Set<FightcadeChannel.ID>()
    init(
        session: AuthSession,
        lobbyService: any FightcadeLobbyServicing = FightcadeLobbyService(),
        romDownloader: any FightcadeROMDownloading = FightcadeROMDownloader(),
        romLibrary: any FightcadeROMLibraryServicing = FightcadeROMLibrary(),
        launcher: any FightcadeLaunching = FightcadeLauncher(),
        joinedChannelStore: any JoinedChannelPersisting = UserDefaultsJoinedChannelStore(),
        channelCache: any FightcadeChannelCaching = FileFightcadeChannelCache(),
        diagnosticsSettings: FightcadeLobbyDiagnosticsSettings = FightcadeLobbyDiagnosticsSettings()
    ) {
        self.session = session
        self.lobbyService = lobbyService
        self.romDownloader = romDownloader
        self.romLibrary = romLibrary
        self.launcher = launcher
        self.joinedChannelStore = joinedChannelStore
        self.channelCache = channelCache
        self.diagnosticsSettings = diagnosticsSettings
        self.isLobbyDiagnosticsEnabled = diagnosticsSettings.isEnabled
        self.includeLobbyDiagnosticChatBodies = diagnosticsSettings.includesChatBodies
    }

    var lobbyDiagnosticsLogPath: String {
        diagnosticsSettings.relativeLogPath
    }

    var channels: [FightcadeChannel] {
        dashboard?.channels ?? []
    }

    var filteredChannels: [FightcadeChannel] {
        let filteredByMode: [FightcadeChannel]
        switch browser.mode {
        case .all:
            filteredByMode = channels
        case .ranked:
            filteredByMode = channels.filter(\.isRanked)
        case .favorites:
            filteredByMode = channels.filter(\.isFavorite)
        }

        let systemFiltered = filteredByMode.filter { channel in
            guard let system = browser.selectedSystem, !system.isEmpty else {
                return true
            }

            return channel.system?.localizedCaseInsensitiveCompare(system) == .orderedSame
        }

        let query = browser.query.trimmingCharacters(in: .whitespacesAndNewlines)
        guard !query.isEmpty else {
            return systemFiltered
        }

        return systemFiltered.filter { channel in
            channel.name.localizedCaseInsensitiveContains(query)
                || channel.title.localizedCaseInsensitiveContains(query)
                || channel.subtitle.localizedCaseInsensitiveContains(query)
        }
    }

    var selectedChannel: FightcadeChannel? {
        if let selectedChannelID,
           let channel = channels.first(where: { $0.id == selectedChannelID }) {
            return channel
        }

        return filteredChannels.first ?? channels.first
    }

    var joinedChannels: [FightcadeChannel] {
        channels.filter { joinedChannelIDs.contains($0.id) }
    }

    var selectedChannelMessages: [FightcadeChatMessage] {
        guard let channelName = selectedChannel?.name else {
            return []
        }

        return (chatMessagesByChannel[channelName] ?? []).filter { !$0.isJoinLeaveSystemMessage }
    }

    var selectedChannelUsers: [FightcadeChannelUser] {
        guard let channelName = selectedChannel?.name else {
            return []
        }

        return usersByChannel[channelName] ?? []
    }

    var popularChannels: [FightcadeChannel] { Array(channels.prefix(12)) }

    var hiddenGemChannels: [FightcadeChannel] {
        Array(channels
            .filter { channel in !popularChannels.contains(where: { $0.id == channel.id }) }
            .sorted { lhs, rhs in (lhs.playerCount ?? 0) < (rhs.playerCount ?? 0) }
            .prefix(12))
    }

    var favoriteChannels: [FightcadeChannel] { Array(channels.filter(\.isFavorite).prefix(12)) }

    var browserChannels: [FightcadeChannel] { browser.results.isEmpty ? filteredChannels : browser.results }

    var canSendChat: Bool {
        selectedChannel != nil
            && selectedChannel.map { joinedChannelIDs.contains($0.id) } == true
            && !chatDraft.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
    }

    var statusText: String {
        if isLoading {
            return "Syncing"
        }

        if !joinedChannelIDs.isEmpty {
            return "Joined · \(joinedChannelIDs.count)"
        }

        if let dashboard {
            return "Connected · \(dashboard.channels.count) channels"
        }

        return "Connected"
    }

    func loadDashboard() async {
        guard !isLoading else {
            return
        }

        isLoading = true
        errorMessage = nil
        startListeningForEvents()
        await loadCachedChannelsIfAvailable(replacingCurrentDashboard: false)
        defer { isLoading = false }

        do {
            let loadedDashboard = try await lobbyService.connect(for: session)
            applyDashboard(loadedDashboard, restoringJoinedChannels: true)
            saveChannelsToCache(loadedDashboard.channels)
            loadBrowserFilterOptions()
            loadUpcomingEvents()
        } catch let error as FightcadeLobbyError {
            errorMessage = error.localizedDescription
        } catch {
            errorMessage = "Could not load lobby."
        }
    }

    func refresh() {
        Task {
            do {
                await loadCachedChannelsIfAvailable(replacingCurrentDashboard: false)
                try await lobbyService.refreshChannels()
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not refresh channels."
            }
        }
    }

    func select(_ channel: FightcadeChannel) {
        selectedChannelID = channel.id
        isShowingChannelBrowser = false
        join(channel)
    }

    func openJoinedChannel(_ channel: FightcadeChannel) {
        selectedChannelID = channel.id
        isShowingChannelBrowser = false
    }

    func leave(_ channel: FightcadeChannel) {
        guard joinedChannelIDs.contains(channel.id), !isLeavingChannel else {
            return
        }

        isLeavingChannel = true
        errorMessage = nil

        Task {
            defer { isLeavingChannel = false }

            do {
                try await lobbyService.leave(channel: channel)
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not leave \(channel.name)."
            }
        }
    }

    func showChannelBrowser() {
        browser.mode = .all
        browser.query = ""
        browser.page = 1
        isShowingChannelBrowser = true
        scheduleBrowserSearch()
    }

    func showRankedChannels() {
        browser.mode = .ranked
        browser.query = ""
        browser.page = 1
        isShowingChannelBrowser = true
        scheduleBrowserSearch()
    }

    func showFavoriteChannels() {
        browser.mode = .favorites
        browser.query = ""
        browser.page = 1
        isShowingChannelBrowser = true
        scheduleBrowserSearch()
    }

    func disconnect() {
        activeEmulationSession?.stop()
        activeEmulationSession = nil
        FightcadeProcessRegistry.shared.terminateAll(reason: "authenticated session disconnect", graceSeconds: 1.0)
        saveJoinedChannels()
        eventTask?.cancel()
        eventTask = nil
        Task { await lobbyService.disconnect() }
    }

    func join(_ channel: FightcadeChannel, forcingServerJoin: Bool = false) {
        guard (forcingServerJoin || !joinedChannelIDs.contains(channel.id)),
              !joiningChannelIDs.contains(channel.id) else {
            return
        }

        joiningChannelIDs.insert(channel.id)
        isJoining = true
        errorMessage = nil

        Task {
            defer {
                joiningChannelIDs.remove(channel.id)
                isJoining = !joiningChannelIDs.isEmpty
            }

            do {
                try await lobbyService.join(channel: channel)
            } catch let error as FightcadeLobbyError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not join \(channel.name)."
            }
        }
    }

    private func startListeningForEvents() {
        guard eventTask == nil else {
            return
        }

        eventTask = Task { [weak self] in
            guard let self else { return }
            let stream = await lobbyService.eventStream()

            for await event in stream {
                handle(event)
            }
        }
    }

    private func handle(_ event: FightcadeLobbyEvent) {
        switch event {
        case .channelsUpdated(let channels):
            applyDashboard(FightcadeDashboard(
                connectedUsername: dashboard?.connectedUsername ?? session.displayName,
                welcomeMessage: dashboard?.welcomeMessage,
                channels: channels
            ), restoringJoinedChannels: false)
            saveChannelsToCache(channels)
        case .joinedChannel(let channelName):
            joinedChannelIDs.insert(channelName)
            saveJoinedChannels()
            if selectedChannelID == nil || isShowingChannelBrowser {
                selectedChannelID = channelName
                isShowingChannelBrowser = false
            }
        case .leftChannel(let channelName):
            joinedChannelIDs.remove(channelName)
            saveJoinedChannels()
            usersByChannel[channelName] = nil
            if selectedChannelID == channelName {
                if let nextChannel = joinedChannels.first {
                    selectedChannelID = nextChannel.id
                    isShowingChannelBrowser = false
                } else {
                    isShowingChannelBrowser = true
                }
            }
        case .usersUpdated(let channelName, let users):
            usersByChannel[channelName] = users.sorted(by: sortUsers)
        case .userJoined(let channelName, let user):
            var users = usersByChannel[channelName] ?? []
            users.removeAll { $0.id == user.id }
            users.append(user)
            usersByChannel[channelName] = users.sorted(by: sortUsers)
        case .userLeft(let channelName, let username):
            usersByChannel[channelName]?.removeAll { $0.id == username }
        case .userStatusUpdated(let update):
            applyUserStatusUpdate(update)
        case .liveStreamUpdated(let update):
            applyLiveStreamUpdate(update)
        case .chatMessage(let message):
            appendReceivedChatMessage(message)
        case .channelMotd(let motd):
            appendChannelMotd(motd)
        case .challengeReceived(let challenge):
            guard !isOutgoingChallengeEcho(challenge) else {
                break
            }

            playIncomingChallengeSound()
            rememberIncomingChallenge(challenge)
            appendSystemMessage("\(challenge.username) challenged you", channelName: challenge.channelName)
        case .challengeCanceled(let challenge):
            clearChallenge(challenge)
            appendSystemMessage("\(challenge.username) canceled the challenge", channelName: challenge.channelName)
        case .challengeRejected(let challenge):
            clearChallenge(challenge)
            appendSystemMessage("\(challenge.username) rejected the challenge", channelName: challenge.channelName)
        case .challengeAccepted(let challenge):
            rememberMatchOpponent(challenge)
            Task { await settleChallenges(afterAccepting: challenge) }
            appendSystemMessage("\(challenge.username) accepted the challenge", channelName: challenge.channelName)
        case .challengeRestricted(let warning):
            handleChallengeWarning(warning)
        case .matchStarted(let start):
            rememberMatchOpponent(for: start)
            clearChallenges()
            launchMatch(start)
        case .error(let message):
            errorMessage = message
        }
    }

    private func sortUsers(_ lhs: FightcadeChannelUser, _ rhs: FightcadeChannelUser) -> Bool {
        switch (lhs.ping, rhs.ping) {
        case let (left?, right?) where left != right:
            return left < right
        case (_?, nil):
            return true
        case (nil, _?):
            return false
        default:
            break
        }

        return lhs.name.localizedCaseInsensitiveCompare(rhs.name) == .orderedAscending
    }

    func launchGame(for channel: FightcadeChannel, mode: GameLaunchMode) {
        guard let emulator = channel.launchEmulator,
              let gameID = channel.launchGameID else {
            errorMessage = FightcadeLaunchError.missingGame.localizedDescription
            return
        }

        Task { @MainActor in
            isLaunchingGame = true
            defer { isLaunchingGame = false }

            do {
                switch mode {
                case .checkROM:
                    try await launcher.open(.checkROM(emulator: emulator, gameID: gameID))
                    appendSystemMessage("ROM found for \(gameID)", channelName: channel.name)
                case .test:
                    activeMatchOpponentUsername = nil
                    activeMatchOpponentChannelName = nil
                    activeEmulationSession?.stop()
                    activeEmulationSession = try await launcher.openEmbedded(
                        .test(channelID: channel.id, emulator: emulator, gameID: gameID)
                    )
                    appendSystemMessage("Launched \(emulator) for \(gameID)", channelName: channel.name)
                case .training:
                    activeMatchOpponentUsername = nil
                    activeMatchOpponentChannelName = nil
                    activeEmulationSession?.stop()
                    activeEmulationSession = try await launcher.openEmbedded(
                        .training(channelID: channel.id, emulator: emulator, gameID: gameID)
                    )
                    appendSystemMessage("Launched training for \(gameID)", channelName: channel.name)
                }
            } catch let error as FightcadeLaunchError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not launch game."
            }
        }
    }

    private func launchMatch(_ start: FightcadeMatchStart) {
        guard let channel = channels.first(where: { $0.name == start.channelName }),
              let emulator = channel.launchEmulator,
              let gameID = start.gameID?.nonEmpty ?? channel.launchGameID else {
            errorMessage = FightcadeLaunchError.missingGame.localizedDescription
            return
        }

        Task { @MainActor in
            isLaunchingGame = true
            defer { isLaunchingGame = false }

            do {
                let match = FightcadeMatchLaunch(
                    emulator: emulator,
                    gameID: gameID,
                    quarkID: start.quarkID,
                    playerID: start.playerID,
                    port: start.port,
                    delay: start.delay,
                    ranked: start.ranked,
                    token: start.token
                )
                activeEmulationSession?.stop()
                activeEmulationSession = try await launcher.openEmbedded(
                    .match(
                        channelID: channel.id,
                        match: match
                    )
                )
                appendSystemMessage("Launched match for \(gameID)", channelName: channel.name)
            } catch let error as FightcadeLaunchError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not launch game."
            }
        }
    }
}
