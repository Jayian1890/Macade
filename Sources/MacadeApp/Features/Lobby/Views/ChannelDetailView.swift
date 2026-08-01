import SwiftUI
@preconcurrency import Translation

struct ChannelDetailView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        if let channel = viewModel.selectedChannel {
            VStack(spacing: 0) {
                ChannelHeader(channel: channel, viewModel: viewModel)

                ChannelErrorBanner(viewModel: viewModel)

                HStack(spacing: 0) {
                    if let session = viewModel.selectedEmulationSession {
                        EmbeddedEmulatorPanel(
                            session: session,
                            isChannelChatVisible: viewModel.isShowingChannelChat,
                            channelChatOverlay: AnyView(ChannelChatView(
                                channel: channel,
                                viewModel: viewModel,
                                showsPreview: false,
                                backgroundOpacity: 0.5
                            )),
                            onToggleChannelChat: viewModel.toggleChannelChat,
                            onMatchEnded: viewModel.finishActiveMatchSession,
                            onStop: viewModel.stopActiveEmulationSession
                        )
                    } else {
                        ChannelChatView(channel: channel, viewModel: viewModel)
                    }

                    PlayerListView(channel: channel, users: viewModel.selectedChannelUsers, viewModel: viewModel)
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

private struct ChannelChatView: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let showsPreview: Bool
    let backgroundOpacity: Double
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
        let messages = viewModel.selectedChannelMessages
        let users = viewModel.selectedChannelUsers
        let usersByName = users.reduce(into: [String: FightcadeChannelUser]()) { result, user in
            result[normalizedUsername(user.name)] = user
        }
        let mentionCandidates = users.map(\.name) + [viewModel.session.displayName, viewModel.session.username]

        VStack(spacing: 0) {
            ScrollViewReader { proxy in
                ScrollView {
                    LazyVStack(alignment: .leading, spacing: MacadeSpacing.medium) {
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
                                    .background(.black.opacity(0.58))
                            }
                        }

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
                        }

                        Color.clear
                            .frame(height: 1)
                            .id(bottomID)
                    }
                    .padding(MacadeSpacing.large)
                    .frame(maxWidth: .infinity, alignment: .leading)
                }
                .onAppear {
                    scrollToInitialPosition(proxy)
                }
                .onChange(of: viewModel.selectedChannelMessages.last?.id) { _, _ in
                    scrollAfterMessagesChanged(proxy)
                }
                .onChange(of: channel.id) { _, _ in
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
        let messages = viewModel.selectedChannelMessages
        return messages.count == 1 && messages.first?.kind == .motd
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
                    .black.opacity(0.25 * backgroundOpacity)
                ],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )
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
