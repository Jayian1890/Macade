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
    var incomingChallenges: [FightcadeChallenge] = []
    var outgoingChallenges: [FightcadeChallenge] = []
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
        if savedJoinedChannelCount > 0 {
            restoringJoinedChannelCount = savedJoinedChannelCount
            isRestoringJoinedChannels = true
        }
        await loadFriendsIfNeeded()
        await startListeningForEvents()
        await loadCachedChannelsIfAvailable(replacingCurrentDashboard: false)
        defer { isLoading = false }

        do {
            let loadedDashboard = try await lobbyService.connect(for: session)
            let mergedChannels = channels.mergingLiveChannels(loadedDashboard.channels)
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
        } catch let error as FightcadeLobbyError {
            isRestoringJoinedChannels = false
            restoringJoinedChannelCount = 0
            errorMessage = error.localizedDescription
        } catch {
            isRestoringJoinedChannels = false
            restoringJoinedChannelCount = 0
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

    private func handle(_ event: FightcadeLobbyEvent) {
        switch event {
        case .channelsUpdated(let channels):
            let mergedChannels = mergeUpdatedChannels(channels)
            applyDashboard(FightcadeDashboard(
                connectedUsername: dashboard?.connectedUsername ?? session.displayName,
                welcomeMessage: dashboard?.welcomeMessage,
                channels: mergedChannels,
                browserSections: dashboard?.browserSections ?? []
            ), restoringJoinedChannels: false)
            saveChannelsToCache(mergedChannels)
        case .joinedChannel(let channelName):
            joinedChannelIDs.insert(channelName)
            saveJoinedChannels()
            let selectedChannelMissing = selectedChannelID.map { selectedID in
                !channels.contains { $0.id == selectedID }
            } ?? true
            if selectedChannelMissing || isShowingChannelBrowser {
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
                    isShowingGameplay = false
                } else {
                    isShowingChannelBrowser = true
                    isShowingGameplay = false
                }
            }
        case .usersUpdated(let channelName, let users):
            usersByChannel[channelName] = users.sorted(by: sortUsers)
            updateChannelPlayerCount(channelName: channelName, count: users.count)
        case .userJoined(let channelName, let user):
            var users = usersByChannel[channelName] ?? []
            users.removeAll { $0.id == user.id }
            users.append(user)
            usersByChannel[channelName] = users.sorted(by: sortUsers)
            updateChannelPlayerCount(channelName: channelName, count: users.count)
        case .userLeft(let channelName, let username):
            usersByChannel[channelName]?.removeAll { $0.id == username }
            updateChannelPlayerCount(channelName: channelName, count: usersByChannel[channelName]?.count ?? 0)
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

}
