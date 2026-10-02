import SwiftUI
@preconcurrency import Translation

struct ChannelDetailView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @Bindable var layout: LobbyLayoutViewModel
    @State private var selectedTab: ChannelLobbyTab = .chat

    var body: some View {
        if let channel = viewModel.selectedChannel {
            VStack(spacing: 0) {
                ChannelHeader(channel: channel, viewModel: viewModel)

                ChannelErrorBanner(viewModel: viewModel)

                MacadeResizableSplitView(
                    fixedSide: .trailing, dimension: $layout.playerListWidth,
                    minimum: MacadeLayout.playersMinimum, maximum: MacadeLayout.playersMaximum,
                    flexibleMinimum: MacadeLayout.chatMinimum,
                    defaultDimension: MacadeLayout.playersDefault, label: "players"
                ) {
                    VStack(spacing: 0) {
                        ChannelLobbyTabBar(selectedTab: $selectedTab)

                        switch selectedTab {
                        case .chat:
                            ChannelChatView(channel: channel, viewModel: viewModel, showsPreview: false)
                        case .info:
                            ChannelInfoPane(channel: channel, viewModel: viewModel)
                        case .resources:
                            ChannelResourcesPane(channel: channel, viewModel: viewModel)
                        }
                    }

                } trailing: {
                    PlayerListView(channel: channel, users: viewModel.selectedChannelUsers,
                                   viewModel: viewModel, layout: layout)
                }
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .background(.clear)
            .sheet(isPresented: $viewModel.isShowingFBNeoSettings) {
                FBNeoSettingsView()
            }
        } else {
            ContentUnavailableView("No Channel Selected", systemImage: "arcade.stick.console")
                .foregroundStyle(MacadeColor.inkMuted)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .background(.clear)
        }
    }
}

struct ChannelChatView: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let showsPreview: Bool
    let backgroundOpacity: Double
    @State private var challengeAnchors: [String: ChannelChallengeAnchor] = [:]
    private let topID = "channel-chat-top"
    private let bottomID = "channel-chat-bottom"

    init(
        channel: FightcadeChannel,
        viewModel: AuthenticatedHomeViewModel,
        showsPreview: Bool = true,
        backgroundOpacity: Double = 1
    ) {
        self.channel = channel
        self.viewModel = viewModel
        self.showsPreview = showsPreview
        self.backgroundOpacity = backgroundOpacity
    }

    var body: some View {
        let messages = channelMessages
        let users = channelUsers
        let challenges = channelChallenges
        let challengeRevision = channelChallengeRevision(challenges)
        let usersByName = users.reduce(into: [String: FightcadeChannelUser]()) { result, user in
            result[normalizedUsername(user.name)] = user
        }
        let mentionCandidates = users.map(\.name) + [viewModel.session.displayName, viewModel.session.username]

        VStack(spacing: 0) {
            ScrollViewReader { proxy in
                ScrollView {
                    LazyVStack(alignment: .leading, spacing: MacadeSpacing.small) {
                        Color.clear
                            .frame(height: 1)
                            .id(topID)

                        if showsPreview, let previewURL = channel.previewURL {
                            AsyncImage(url: previewURL) { image in
                                image
                                    .resizable()
                                    .scaledToFill()
                            } placeholder: {
                                Rectangle().fill(MacadeColor.panel)
                            }
                            .frame(height: 140)
                            .clipShape(RoundedRectangle(cornerRadius: 14))
                            .overlay(alignment: .bottomLeading) {
                                Text(channel.subtitle.uppercased())
                                    .font(MacadeTypography.caption)
                                    .foregroundStyle(MacadeColor.ink)
                                    .padding(10)
                                    .frame(maxWidth: .infinity, alignment: .leading)
                                    .background(MacadeColor.midnight.opacity(0.58))
                            }
                        }

                        challengeRows(anchoredTo: .top, from: challenges)

                        ForEach(messages) { message in
                            let chatUser = usersByName[normalizedUsername(message.username)]
                            ChatMessageRow(
                                message: message,
                                channel: channel,
                                chatUser: chatUser,
                                canChallengeFromChat: message.kind == .user && chatUser.map { viewModel.canChallenge($0, in: channel) } == true,
                                isChallengingFromChat: viewModel.isChallenging(message.username, in: channel),
                                mentionCandidates: mentionCandidates,
                                viewModel: viewModel
                            )
                                .id(message.id)

                            challengeRows(anchoredTo: .message(message.id), from: challenges)
                        }

                        Color.clear
                            .frame(height: 1)
                            .id(bottomID)
                    }
                    .padding(MacadeSpacing.medium)
                    .frame(maxWidth: .infinity, alignment: .leading)
                }
                .onAppear {
                    syncChallengeAnchors(messages: messages, challenges: challenges)
                    scrollToInitialPosition(proxy)
                }
                .onChange(of: messages.last?.id) { _, _ in
                    syncChallengeAnchors(messages: messages, challenges: challenges)
                    scrollAfterMessagesChanged(proxy)
                }
                .onChange(of: challengeRevision) { _, _ in
                    syncChallengeAnchors(messages: messages, challenges: challenges)
                    scrollAfterMessagesChanged(proxy)
                }
                .onChange(of: channel.id) { _, _ in
                    syncChallengeAnchors(messages: messages, challenges: challenges)
                    scrollToInitialPosition(proxy)
                }
            }

            ChatInput(channel: channel, viewModel: viewModel)

            ChatTranslationSessionHost(viewModel: viewModel)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background(chatBackground)
    }

    private func scrollToInitialPosition(_ proxy: ScrollViewProxy) {
        DispatchQueue.main.async {
            if shouldShowOnlyMOTD {
                proxy.scrollTo(topID, anchor: .top)
            } else {
                proxy.scrollTo(bottomID, anchor: .bottom)
            }
        }
    }

    private func scrollAfterMessagesChanged(_ proxy: ScrollViewProxy) {
        DispatchQueue.main.async {
            if shouldShowOnlyMOTD {
                proxy.scrollTo(topID, anchor: .top)
            } else {
                withAnimation(.smooth(duration: 0.14)) {
                    proxy.scrollTo(bottomID, anchor: .bottom)
                }
            }
        }
    }

    private var shouldShowOnlyMOTD: Bool {
        let messages = channelMessages
        return messages.count == 1 && messages.first?.kind == .motd
    }

    private var channelMessages: [FightcadeChatMessage] {
        (viewModel.chatMessagesByChannel[channel.name] ?? []).filter { !$0.isJoinLeaveSystemMessage && $0.kind != .motd }
    }

    private var channelUsers: [FightcadeChannelUser] {
        viewModel.usersByChannel[channel.name] ?? []
    }

    private var incomingChannelChallenges: [FightcadeChallenge] {
        viewModel.incomingChallenges.filter { challengeMatchesChannel($0) }
    }

    private var outgoingChannelChallenges: [FightcadeChallenge] {
        viewModel.outgoingChallenges.filter {
            challengeMatchesChannel($0) && !viewModel.isAutoMatchManagedChallenge($0)
        }
    }

    private var channelChallenges: [ChannelChallengeItem] {
        incomingChannelChallenges.map { ChannelChallengeItem(challenge: $0, mode: .incoming) }
            + outgoingChannelChallenges.map { ChannelChallengeItem(challenge: $0, mode: .outgoing) }
    }

    private func channelChallengeRevision(_ challenges: [ChannelChallengeItem]) -> String {
        challenges
            .map(\.id)
            .joined(separator: "|")
    }

    @ViewBuilder
    private func challengeRows(anchoredTo anchor: ChannelChallengeAnchor, from challenges: [ChannelChallengeItem]) -> some View {
        ForEach(challenges) { item in
            if challengeAnchors[item.id] == anchor {
                ChallengeChatRow(
                    challenge: item.challenge,
                    user: viewModel.user(for: item.challenge),
                    mode: item.mode,
                    isBusy: viewModel.isSendingChallenge,
                    canAccept: viewModel.canAcceptIncomingChallenge(item.challenge),
                    acceptAction: { viewModel.acceptIncomingChallenge(item.challenge) },
                    rejectAction: { viewModel.rejectIncomingChallenge(item.challenge) },
                    cancelAction: { viewModel.cancelOutgoingChallenge(item.challenge) }
                )
                .id(item.id)
            }
        }
    }

    private func syncChallengeAnchors(messages: [FightcadeChatMessage], challenges: [ChannelChallengeItem]) {
        let activeChallengeIDs = Set(challenges.map(\.id))
        let visibleMessageIDs = Set(messages.map(\.id))
        let defaultAnchor = messages.last.map { ChannelChallengeAnchor.message($0.id) } ?? .top
        var updatedAnchors = challengeAnchors.filter { activeChallengeIDs.contains($0.key) }

        for (challengeID, anchor) in updatedAnchors {
            if case .message(let messageID) = anchor, !visibleMessageIDs.contains(messageID) {
                updatedAnchors[challengeID] = .top
            }
        }

        for challenge in challenges where updatedAnchors[challenge.id] == nil {
            updatedAnchors[challenge.id] = defaultAnchor
        }

        if updatedAnchors != challengeAnchors {
            challengeAnchors = updatedAnchors
        }
    }

    private func challengeMatchesChannel(_ challenge: FightcadeChallenge) -> Bool {
        normalizedUsername(challenge.channelName) == normalizedUsername(channel.name)
            || normalizedUsername(challenge.channelName) == normalizedUsername(channel.id)
    }

    private func normalizedUsername(_ value: String) -> String {
        value.folding(options: [.caseInsensitive, .diacriticInsensitive], locale: nil).lowercased()
    }

    private var chatBackground: some View {
        ZStack {
            MacadeColor.midnight.opacity(0.42 * backgroundOpacity)
            LinearGradient(
                colors: [
                    MacadeColor.deepPlum.opacity(0.18 * backgroundOpacity),
                    .clear,
                    MacadeColor.midnight.opacity(0.25 * backgroundOpacity)
                ],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )
        }
    }
}

private enum ChannelChallengeAnchor: Equatable {
    case top
    case message(FightcadeChatMessage.ID)
}

private struct ChannelChallengeItem: Identifiable {
    let challenge: FightcadeChallenge
    let mode: ChallengeChatRow.Mode

    var id: String {
        "\(modeID)-challenge-\(challenge.id)"
    }

    private var modeID: String {
        switch mode {
        case .incoming:
            return "incoming"
        case .outgoing:
            return "outgoing"
        }
    }
}

private struct ChatTranslationSessionHost: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var configuration: TranslationSession.Configuration?
    @State private var activeSourceLanguageIdentifier: String?
    @State private var activeTargetLanguageIdentifier: String?

    var body: some View {
        Color.clear
            .frame(width: 0, height: 0)
            .onAppear(perform: activateIfNeeded)
            .onChange(of: viewModel.chatTranslation.requestRevision) { _, _ in
                activateIfNeeded()
            }
            .translationTask(configuration) { session in
                guard let sourceLanguageIdentifier = activeSourceLanguageIdentifier,
                      let targetLanguageIdentifier = activeTargetLanguageIdentifier else {
                    return
                }

                let requests = viewModel.chatTranslation.drainPendingRequests(
                    sourceLanguageIdentifier: sourceLanguageIdentifier,
                    targetLanguageIdentifier: targetLanguageIdentifier,
                    limit: 8
                )
                guard !requests.isEmpty else { return }

                do {
                    let batch = requests.map {
                        TranslationSession.Request(sourceText: $0.protectedBody, clientIdentifier: $0.id.uuidString)
                    }

                    var requestsByID = Dictionary(uniqueKeysWithValues: requests.map { ($0.id.uuidString, $0) })
                    for try await response in session.translate(batch: batch) {
                        guard let request = requestsByID.removeValue(forKey: response.clientIdentifier ?? "") else { continue }
                        let translatedBody = restoreTokens(in: response.targetText, placeholders: request.placeholders)

                        viewModel.chatTranslation.complete(ChatMessageTranslation(
                            messageID: request.id,
                            sourceLanguageIdentifier: response.sourceLanguage.languageCode?.identifier ?? request.sourceLanguageIdentifier,
                            targetLanguageIdentifier: response.targetLanguage.languageCode?.identifier ?? request.targetLanguageIdentifier,
                            translatedBody: translatedBody,
                            translatedAt: .now
                        ))
                    }
                } catch {
                    for request in requests {
                        viewModel.chatTranslation.fail(request, reason: error.localizedDescription)
                    }
                }

                activateIfNeeded()
            }
    }

    private func restoreTokens(in text: String, placeholders: [String: String]) -> String {
        placeholders.reduce(text) { result, entry in
            result.replacingOccurrences(of: entry.key, with: entry.value)
        }
    }

    private func activateIfNeeded() {
        guard viewModel.chatTranslation.preferences.isEnabled,
              let request = viewModel.chatTranslation.nextPendingRequest,
              let sourceLanguageIdentifier = request.sourceLanguageIdentifier else {
            return
        }

        let targetLanguageIdentifier = request.targetLanguageIdentifier
        let source = Locale.Language(identifier: sourceLanguageIdentifier)
        let target = Locale.Language(identifier: targetLanguageIdentifier)
        if activeSourceLanguageIdentifier == sourceLanguageIdentifier,
           activeTargetLanguageIdentifier == targetLanguageIdentifier {
            configuration?.invalidate()
        } else {
            activeSourceLanguageIdentifier = sourceLanguageIdentifier
            activeTargetLanguageIdentifier = targetLanguageIdentifier
            configuration = TranslationSession.Configuration(source: source, target: target)
        }
    }
}


private enum ChannelLobbyTab: String, CaseIterable, Identifiable {
    case chat
    case info
    case resources

    var id: String { rawValue }

    var title: String {
        switch self {
        case .chat: "Chat"
        case .info: "Info"
        case .resources: "Resources"
        }
    }
}

private struct ChannelLobbyTabBar: View {
    @Binding var selectedTab: ChannelLobbyTab

    var body: some View {
        HStack(spacing: 6) {
            ForEach(ChannelLobbyTab.allCases) { tab in
                Button {
                    selectedTab = tab
                } label: {
                    Text(tab.title)
                        .font(MacadeTypography.control)
                        .foregroundStyle(selectedTab == tab ? MacadeColor.midnight : MacadeColor.inkMuted)
                        .padding(.horizontal, 12)
                        .frame(height: 28)
                        .background(selectedTab == tab ? MacadeColor.neonCyan : MacadeColor.panel.opacity(0.7), in: Capsule())
                }
                .buttonStyle(.plain)
            }
            Spacer()
        }
        .padding(.horizontal, MacadeSpacing.medium)
        .frame(height: MacadeLayout.toolbarHeight)
        .background { MacadeFrostedFill(opacity: 0.35) }
        .overlay(alignment: .bottom) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }
}
