import SwiftUI
@preconcurrency import Translation

struct ChatInput: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel

    @FocusState private var isChatFocused: Bool
    @State private var inputPreferences = ChatInputTranslationPreferencesStore().load()
    @State private var outgoingConfiguration: TranslationSession.Configuration?
    @State private var outgoingRequest: ChatTranslationRequest?
    @State private var outgoingSourceLanguageIdentifier: String?
    @State private var outgoingTargetLanguageIdentifier: String?
    @State private var isTranslatingDraft = false
    @State private var translationStatus: String?

    var body: some View {
        VStack(spacing: 0) {
            if !mentionSuggestions.isEmpty {
                MentionSuggestionStrip(suggestions: mentionSuggestions, selectedUserID: mentionSuggestions.first?.id) { user in
                    viewModel.completeChatMention(user.name)
                }
            }

            HStack(spacing: MacadeSpacing.medium) {
                TextField(isTranslatingDraft ? "Translating..." : "Message", text: $viewModel.chatDraft)
                    .textFieldStyle(.plain)
                    .font(.system(size: 16, weight: .regular, design: .rounded))
                    .focused($isChatFocused)
                    .disabled(!viewModel.joinedChannelIDs.contains(channel.id) || isTranslatingDraft)
                    .onSubmit(sendChatKeepingFocus)
                    .onKeyPress(.tab) {
                        guard let user = mentionSuggestions.first else { return .ignored }
                        viewModel.completeChatMention(user.name)
                        return .handled
                    }

                inputTranslationTargetMenu
                outputTranslationTargetMenu

                Button(action: sendChatKeepingFocus) {
                    Image(systemName: isTranslatingDraft ? "arrow.triangle.2.circlepath" : "paperplane.fill")
                        .frame(width: 28, height: 28)
                }
                .buttonStyle(.plain)
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(canSendChat && !isTranslatingDraft ? MacadeColor.warning : MacadeColor.inkMuted)
                .disabled(!canSendChat || isTranslatingDraft)
                .help(translationStatus ?? "Send")
            }
            .padding(.horizontal, MacadeSpacing.medium)
            .frame(height: 50)
        }
        .onAppear { isChatFocused = true }
        .onChange(of: viewModel.chatDraft) { _, draft in
            guard !isTranslatingDraft else { return }
            _ = viewModel.handleLocalChatCommand(draft, in: channel)
        }
        .translationTask(outgoingConfiguration) { session in
            await translateAndSendPendingDraft(with: session)
        }
        .background(MacadeColor.sidebar.opacity(0.42))
        .overlay(alignment: .top) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }

    private var mentionSuggestions: [FightcadeChannelUser] {
        viewModel.chatMentionSuggestions(in: channel)
    }

    private var canSendChat: Bool {
        viewModel.canSendChat(to: channel)
    }

    private var detectedTranslationTargetChoices: [(id: String, name: String)] {
        viewModel.chatTranslationTargetChoices(in: channel)
    }

    private var selectedInputTargetIdentifier: String? {
        inputPreferences.isEnabled ? inputPreferences.targetLanguageIdentifier : nil
    }

    private var selectedOutputTargetIdentifier: String? {
        guard viewModel.chatTranslation.preferences.isEnabled else { return nil }
        return viewModel.chatTranslation.preferences.targetLanguageIdentifier
    }

    private var inputTranslationTargetMenu: some View {
        translationMenu(
            title: selectedInputTargetIdentifier.map { "Input to \(viewModel.chatTranslationLanguageName(for: $0))" } ?? "Input to",
            selectedIdentifier: selectedInputTargetIdentifier,
            choices: detectedTranslationTargetChoices,
            emptyTitle: "No detected languages",
            help: "Translate your message before sending",
            setTarget: setInputTranslationTarget
        )
    }

    private var outputTranslationTargetMenu: some View {
        translationMenu(
            title: selectedOutputTargetIdentifier.map { "Output to \(viewModel.chatTranslationLanguageName(for: $0))" } ?? "Output to",
            selectedIdentifier: selectedOutputTargetIdentifier,
            choices: outputTranslationTargetChoices,
            emptyTitle: "No output languages",
            help: "Translate incoming messages to your selected language",
            setTarget: setOutputTranslationTarget
        )
    }

    private var outputTranslationTargetChoices: [(id: String, name: String)] {
        let native = nativeLanguageIdentifier
        let detected = detectedTranslationTargetChoices.filter {
            ChatTranslationPreferences.languageFamily($0.id) != ChatTranslationPreferences.languageFamily(native)
        }
        return [(id: native, name: "Native: \(viewModel.chatTranslationLanguageName(for: native))")] + detected
    }

    private var nativeLanguageIdentifier: String {
        Locale.preferredLanguages.first?.nonEmpty ?? "en"
    }

    private func translationMenu(
        title: String,
        selectedIdentifier: String?,
        choices: [(id: String, name: String)],
        emptyTitle: String,
        help: String,
        setTarget: @escaping (String?) -> Void
    ) -> some View {
        Menu {
            Button("Off") { setTarget(nil) }

            Divider()

            if choices.isEmpty {
                Button(emptyTitle) { }
                    .disabled(true)
            } else {
                ForEach(choices, id: \.id) { language in
                    Button { setTarget(language.id) } label: {
                        if selectedIdentifier == language.id {
                            Label(language.name, systemImage: "checkmark")
                        } else {
                            Text(language.name)
                        }
                    }
                }
            }
        } label: {
            Text(title)
                .font(.system(size: 11, weight: .black, design: .rounded))
                .foregroundStyle(selectedIdentifier == nil ? MacadeColor.inkMuted : MacadeColor.neonCyan)
                .lineLimit(1)
                .padding(.horizontal, 8)
                .frame(height: 28)
                .background(MacadeColor.panel.opacity(0.92), in: Capsule())
        }
        .menuStyle(.borderlessButton)
        .help(help)
    }

    private func setInputTranslationTarget(_ identifier: String?) {
        inputPreferences = ChatInputTranslationPreferences(isEnabled: identifier != nil, targetLanguageIdentifier: identifier)
        ChatInputTranslationPreferencesStore().save(inputPreferences)
        refocusChat()
    }

    private func setOutputTranslationTarget(_ identifier: String?) {
        viewModel.setChatTranslationTarget(identifier, in: channel)
        refocusChat()
    }

    private func sendChatKeepingFocus() {
        guard !isTranslatingDraft else { return }
        let body = String(viewModel.chatDraft.trimmingCharacters(in: .whitespacesAndNewlines).prefix(500))
        guard !body.isEmpty else { return }
        if viewModel.handleLocalChatCommand(body, in: channel) {
            refocusChat()
            return
        }
        guard let target = selectedInputTargetIdentifier else {
            viewModel.sendChat(to: channel)
            refocusChat()
            return
        }

        isTranslatingDraft = true
        translationStatus = "Translating message..."
        Task { @MainActor in
            let result = await ChatTranslationRequestBuilder.build(
                id: UUID(),
                channelName: channel.name,
                body: body,
                targetLanguageIdentifier: target
            )
            handleOutgoingBuildResult(result, originalBody: body)
        }
    }

    private func handleOutgoingBuildResult(_ result: ChatTranslationRequestBuildResult, originalBody: String) {
        switch result {
        case .request(let request):
            startOutgoingTranslation(request)
        case .failed, .skipped:
            sendBody(originalBody)
        }
    }

    private func startOutgoingTranslation(_ request: ChatTranslationRequest) {
        guard let sourceIdentifier = request.sourceLanguageIdentifier else {
            sendBody(request.sourceBody)
            return
        }

        outgoingRequest = request
        let targetIdentifier = request.targetLanguageIdentifier
        let source = Locale.Language(identifier: sourceIdentifier)
        let target = Locale.Language(identifier: targetIdentifier)
        if outgoingSourceLanguageIdentifier == sourceIdentifier,
           outgoingTargetLanguageIdentifier == targetIdentifier {
            outgoingConfiguration?.invalidate()
        } else {
            outgoingSourceLanguageIdentifier = sourceIdentifier
            outgoingTargetLanguageIdentifier = targetIdentifier
            outgoingConfiguration = TranslationSession.Configuration(source: source, target: target)
        }
    }

    private func translateAndSendPendingDraft(with session: TranslationSession) async {
        guard let request = outgoingRequest else { return }
        defer {
            outgoingRequest = nil
            isTranslatingDraft = false
            refocusChat()
        }

        do {
            let batch = [TranslationSession.Request(sourceText: request.protectedBody, clientIdentifier: request.id.uuidString)]
            for try await response in session.translate(batch: batch) {
                let translated = restoreTokens(in: response.targetText, placeholders: request.placeholders)
                sendBody(translated)
                translationStatus = nil
                return
            }
            sendBody(request.sourceBody)
        } catch {
            translationStatus = "Translation failed: sent original"
            sendBody(request.sourceBody)
        }
    }

    private func sendBody(_ body: String) {
        viewModel.chatDraft = body
        viewModel.sendChat(to: channel)
    }

    private func restoreTokens(in text: String, placeholders: [String: String]) -> String {
        placeholders.reduce(text) { result, entry in
            result.replacingOccurrences(of: entry.key, with: entry.value)
        }
    }

    private func refocusChat() {
        DispatchQueue.main.async { isChatFocused = true }
    }
}

private struct ChatInputTranslationPreferences: Equatable, Sendable {
    var isEnabled = false
    var targetLanguageIdentifier: String?
}

private struct ChatInputTranslationPreferencesStore {
    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    func load() -> ChatInputTranslationPreferences {
        ChatInputTranslationPreferences(
            isEnabled: userDefaults.bool(forKey: Self.enabledKey),
            targetLanguageIdentifier: userDefaults.string(forKey: Self.targetLanguageKey)
        )
    }

    func save(_ preferences: ChatInputTranslationPreferences) {
        userDefaults.set(preferences.isEnabled, forKey: Self.enabledKey)
        if let target = preferences.targetLanguageIdentifier?.nonEmpty {
            userDefaults.set(target, forKey: Self.targetLanguageKey)
        } else {
            userDefaults.removeObject(forKey: Self.targetLanguageKey)
        }
    }

    private static let enabledKey = "chatInputTranslation.enabled"
    private static let targetLanguageKey = "chatInputTranslation.targetLanguage"
}

private struct MentionSuggestionStrip: View {
    let suggestions: [FightcadeChannelUser]
    let selectedUserID: FightcadeChannelUser.ID?
    let complete: (FightcadeChannelUser) -> Void

    var body: some View {
        ScrollView(.horizontal, showsIndicators: false) {
            HStack(spacing: MacadeSpacing.xSmall) {
                ForEach(suggestions) { user in
                    let isSelected = user.id == selectedUserID

                    Button { complete(user) } label: {
                        HStack(spacing: 6) {
                            PlayerAvatarView(
                                url: user.avatarURL,
                                fallbackName: user.name,
                                size: 18,
                                borderColor: MacadeColor.neonCyan
                            )

                            Text("@\(user.name)")
                                .font(.system(size: 12, weight: .black, design: .rounded))
                                .lineLimit(1)
                        }
                        .foregroundStyle(isSelected ? MacadeColor.midnight : MacadeColor.ink)
                        .padding(.horizontal, 8)
                        .frame(height: 28)
                        .background(isSelected ? MacadeColor.warning : MacadeColor.panel.opacity(0.92), in: Capsule())
                        .overlay(Capsule().stroke(isSelected ? .white.opacity(0.45) : .clear, lineWidth: 1))
                    }
                    .buttonStyle(.plain)
                }
            }
            .padding(.horizontal, MacadeSpacing.medium)
            .padding(.vertical, 6)
        }
    }
}
