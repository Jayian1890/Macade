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
    var isRestoringJoinedChannels = false
    var restoringJoinedChannelCount = 0
    var isShowingStartupLoading = true
    var startupLoadingTitle = "Opening Lobby"
    var startupLoadingDetail = "Preparing your Fightcade session."
    var startupLoadingProgress = 0.34
    var startupLoadingDetails = [
        "Session restored",
        "Preparing lobby connection"
    ]
    var isLeavingChannel = false
    var isSendingChat = false
    var isLaunchingGame = false
    var isDownloadingROM = false
    var isDeletingROM = false
    var isShowingFBNeoSettings = false
    var isShowingRelayConsole = false
    var errorMessage: String?
    var chatMessagesByChannel: [String: [FightcadeChatMessage]] = [:]
    var pendingSentMessages: [String: [(body: String, sentAt: Date)]] = [:]
    var detectedChatLanguageIdentifiersByChannel: [String: Set<String>] = [:]
    var usersByChannel: [String: [FightcadeChannelUser]] = [:]
    var recentMatchStatesByKey: [FightcadeRecentMatchKey: FightcadeRecentMatchState] = [:]
    var incomingChallenges: [FightcadeChallenge] = []
    var outgoingChallenges: [FightcadeChallenge] = []
    var autoMatchStatesByChannel: [String: FightcadeAutoMatchState] = [:]
    var activeEmulationSession: FightcadeEmbeddedSession?
    var activeMatchOpponentUsername: String?
    var activeMatchOpponentChannelName: String?
    var friends: [FightcadeFriend] = []
    var friendDraft = ""
    var browser = FightcadeChannelBrowserState()
    var upcomingEvents: [FightcadeEvent] = []
    var isShowingChannelChat = false
    var isShowingChannelTV = false
    var channelTVStatusText: String?
    var channelTVTask: Task<Void, Never>?
    var channelTVCurrentStreamID: String?
    var channelTVBlockedStreamIDs = Set<String>()
    var isSendingChallenge = false
    var isShowingChannelBrowser = true
    var isShowingGameplay = false
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
    let friendStore: any FightcadeFriendPersisting
    private let diagnosticsSettings: FightcadeLobbyDiagnosticsSettings
    private var eventTask: Task<Void, Never>?
    var channelRefreshTask: Task<Void, Never>?
    var autoMatchTasksByChannel: [String: Task<Void, Never>] = [:]
    private var joiningChannelIDs = Set<FightcadeChannel.ID>()
    private var restoringJoinedChannelIDs = Set<FightcadeChannel.ID>()
    var hasLoadedFriends = false
    init(
        session: AuthSession,
        lobbyService: any FightcadeLobbyServicing = FightcadeLobbyService(),
        romDownloader: any FightcadeROMDownloading = FightcadeROMDownloader(),
        romLibrary: any FightcadeROMLibraryServicing = FightcadeROMLibrary(),
        launcher: any FightcadeLaunching = FightcadeLauncher(),
        joinedChannelStore: any JoinedChannelPersisting = UserDefaultsJoinedChannelStore(),
        channelCache: any FightcadeChannelCaching = FileFightcadeChannelCache(),
        friendStore: any FightcadeFriendPersisting = FileFightcadeFriendStore(),
        diagnosticsSettings: FightcadeLobbyDiagnosticsSettings = FightcadeLobbyDiagnosticsSettings()
    ) {
        self.session = session
        self.lobbyService = lobbyService
        self.romDownloader = romDownloader
        self.romLibrary = romLibrary
        self.launcher = launcher
        self.joinedChannelStore = joinedChannelStore
        self.channelCache = channelCache
        self.friendStore = friendStore
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
            return systemFiltered.sortedByUserCountDescending()
        }

        let queryFiltered = systemFiltered.filter { channel in
            channel.name.localizedCaseInsensitiveContains(query)
                || channel.title.localizedCaseInsensitiveContains(query)
                || channel.subtitle.localizedCaseInsensitiveContains(query)
        }
        return queryFiltered.sortedByUserCountDescending()
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

    var browserChannels: [FightcadeChannel] { filteredChannels }

    var canSendChat: Bool {
        selectedChannel.map { canSendChat(to: $0) } == true
    }

    func loadDashboard() async {
        guard !isLoading else {
            return
        }

        isLoading = true
        errorMessage = nil
        let savedJoinedChannelCount = joinedChannelStore.joinedChannelIDs(for: session).count
        updateStartupLoading(
            title: "Opening Lobby",
            detail: "Loading local profile for \(session.displayName).",
            progress: 0.38,
            details: startupDetails(savedJoinedChannelCount: savedJoinedChannelCount, current: "Loading friends and saved rooms")
        )
        if savedJoinedChannelCount > 0 {
            restoringJoinedChannelCount = savedJoinedChannelCount
            isRestoringJoinedChannels = true
        }
        await loadFriendsIfNeeded()
        updateStartupLoading(
            title: "Opening Lobby",
            detail: "Starting lobby event stream.",
            progress: 0.46,
            details: startupDetails(savedJoinedChannelCount: savedJoinedChannelCount, current: "Loaded friends")
        )
        await startListeningForEvents()
        updateStartupLoading(
            title: "Loading Channels",
            detail: "Checking cached channel data while Fightcade connects.",
            progress: 0.54,
            details: startupDetails(savedJoinedChannelCount: savedJoinedChannelCount, current: "Event stream ready")
        )
        await loadCachedChannelsIfAvailable(replacingCurrentDashboard: false)
        updateStartupLoading(
            title: "Connecting to Fightcade",
            detail: "Opening the encrypted lobby socket.",
            progress: 0.62,
            details: startupDetails(savedJoinedChannelCount: savedJoinedChannelCount, current: "Authenticating lobby connection")
        )
        defer {
            isLoading = false
            completeStartupLoadingIfReady()
        }

        do {
            let loadedDashboard = try await lobbyService.connect(for: session)
            let mergedChannels = channels.mergingLiveChannels(loadedDashboard.channels)
            updateStartupLoading(
                title: "Syncing Channels",
                detail: "Received \(loadedDashboard.channels.count) active Fightcade channels.",
                progress: 0.78,
                details: startupDetails(savedJoinedChannelCount: savedJoinedChannelCount, current: "Merging live channel list")
            )
            applyDashboard(
                FightcadeDashboard(
                    connectedUsername: loadedDashboard.connectedUsername,
                    welcomeMessage: loadedDashboard.welcomeMessage,
                    channels: mergedChannels,
                    browserSections: loadedDashboard.browserSections,
                    loadedAt: loadedDashboard.loadedAt
                ),
                restoringJoinedChannels: true
            )
            saveChannelsToCache(mergedChannels)
            loadUpcomingEvents()
            startChannelRefreshLoop()
            if isRestoringJoinedChannels {
                updateRestoredChannelStartupProgress()
            } else {
                finishStartupLoading()
            }
        } catch let error as FightcadeLobbyError {
            isRestoringJoinedChannels = false
            restoringJoinedChannelCount = 0
            errorMessage = error.localizedDescription
            finishStartupLoading()
        } catch {
            isRestoringJoinedChannels = false
            restoringJoinedChannelCount = 0
            errorMessage = "Could not load lobby."
            finishStartupLoading()
        }
    }

    private func updateRestoredChannelStartupProgress() {
        guard isShowingStartupLoading, restoringJoinedChannelCount > 0 else {
            return
        }

        let remainingCount = restoringJoinedChannelIDs.count
        let restoredCount = max(0, restoringJoinedChannelCount - remainingCount)
        let restoredFraction = Double(restoredCount) / Double(max(restoringJoinedChannelCount, 1))
        updateStartupLoading(
            title: "Rejoining Rooms",
            detail: "Rejoined \(restoredCount) of \(restoringJoinedChannelCount) saved rooms.",
            progress: 0.84 + min(restoredFraction, 1) * 0.12,
            details: [
                "Restoring saved room membership",
                "\(remainingCount) room\(remainingCount == 1 ? "" : "s") remaining",
                "Loading current player lists as rooms respond"
            ]
        )
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
        stopChannelTVSession(stoppingSession: true)
        selectedChannelID = channel.id
        isShowingChannelBrowser = false
        isShowingGameplay = false
        join(channel)
    }

    func openJoinedChannel(_ channel: FightcadeChannel) {
        stopChannelTVSession(stoppingSession: true)
        selectedChannelID = channel.id
        isShowingChannelBrowser = false
        isShowingGameplay = false
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
        stopChannelTVSession(stoppingSession: true)
        browser.mode = .all
        browser.query = ""
        browser.selectedSystem = nil
        isShowingChannelBrowser = true
        isShowingGameplay = false
    }

    func showRankedChannels() {
        stopChannelTVSession(stoppingSession: true)
        browser.mode = .ranked
        browser.query = ""
        browser.selectedSystem = nil
        isShowingChannelBrowser = true
        isShowingGameplay = false
    }

    func showFavoriteChannels() {
        stopChannelTVSession(stoppingSession: true)
        browser.mode = .favorites
        browser.query = ""
        browser.selectedSystem = nil
        isShowingChannelBrowser = true
        isShowingGameplay = false
    }

    func showGameplay() {
        guard activeEmulationSession != nil else {
            return
        }

        isShowingChannelBrowser = false
        isShowingGameplay = true
    }

    func disconnect() {
        stopAllAutoMatch(cancelsOutstandingChallenges: true)
        stopChannelTVSession(stoppingSession: false)
        activeEmulationSession?.stop()
        activeEmulationSession = nil
        FightcadeProcessRegistry.shared.terminateAll(reason: "authenticated session disconnect", graceSeconds: 1.0)
        saveJoinedChannels()
        eventTask?.cancel()
        eventTask = nil
        channelRefreshTask?.cancel()
        channelRefreshTask = nil
        Task { await lobbyService.disconnect() }
    }

    func join(_ channel: FightcadeChannel, forcingServerJoin: Bool = false, restoringSavedChannel: Bool = false) {
        rememberChannel(channel)

        guard (forcingServerJoin || !joinedChannelIDs.contains(channel.id)),
              !joiningChannelIDs.contains(channel.id) else {
            return
        }

        joiningChannelIDs.insert(channel.id)
        if restoringSavedChannel {
            restoringJoinedChannelIDs.insert(channel.id)
            isRestoringJoinedChannels = true
        }
        isJoining = true
        errorMessage = nil

        Task {
            defer {
                joiningChannelIDs.remove(channel.id)
                restoringJoinedChannelIDs.remove(channel.id)
                isJoining = !joiningChannelIDs.isEmpty
                isRestoringJoinedChannels = !restoringJoinedChannelIDs.isEmpty
                updateRestoredChannelStartupProgress()
                completeStartupLoadingIfReady()
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

    func rememberChannel(_ channel: FightcadeChannel) {
        guard let dashboard,
              !dashboard.channels.contains(where: { $0.id == channel.id }) else {
            return
        }

        let channels = dashboard.channels + [channel]
        applyDashboard(FightcadeDashboard(
            connectedUsername: dashboard.connectedUsername,
            welcomeMessage: dashboard.welcomeMessage,
            channels: channels,
            browserSections: dashboard.browserSections,
            loadedAt: dashboard.loadedAt
        ), restoringJoinedChannels: false)
        saveChannelsToCache(channels)
    }

    private func startListeningForEvents() async {
        guard eventTask == nil else {
            return
        }

        let stream = await lobbyService.eventStream()
        eventTask = Task { [weak self] in
            guard let self else { return }
            for await event in stream {
                handle(event)
            }
        }
    }

}
