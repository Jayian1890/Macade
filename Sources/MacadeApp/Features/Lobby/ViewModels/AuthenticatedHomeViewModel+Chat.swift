import Foundation

import AppKit
import UserNotifications

private let channelChatScrollbackLimit = 500

struct ChatTranslationPreferences: Equatable, Sendable {
    var isEnabled = false
    var targetLanguageIdentifier: String?

    var resolvedTargetLanguageIdentifier: String {
        targetLanguageIdentifier?.nonEmpty ?? Locale.preferredLanguages.first ?? "en"
    }

    var resolvedTargetLanguage: Locale.Language {
        Locale.Language(identifier: resolvedTargetLanguageIdentifier)
    }

    static func languageFamily(_ identifier: String) -> String {
        identifier
            .replacingOccurrences(of: "_", with: "-")
            .split(separator: "-")
            .first
            .map(String.init) ?? identifier
    }
}

struct ChatMessageTranslation: Equatable, Sendable {
    let messageID: FightcadeChatMessage.ID
    let sourceLanguageIdentifier: String?
    let targetLanguageIdentifier: String
    let translatedBody: String
    let translatedAt: Date
}

enum ChatTranslationState: Equatable, Sendable {
    case pending
    case translated(ChatMessageTranslation)
    case failed(String)
}

struct ChatTranslationRequest: Identifiable, Equatable, Sendable {
    let id: UUID
    let channelName: String
    let sourceBody: String
    let protectedBody: String
    let placeholders: [String: String]
    let sourceLanguageIdentifier: String?
    let targetLanguageIdentifier: String
}

@MainActor
@Observable
final class ChatTranslationStore {
    var preferences: ChatTranslationPreferences
    var translationsByMessageID: [FightcadeChatMessage.ID: ChatTranslationState] = [:]
    var pendingRequests: [ChatTranslationRequest] = []
    var requestRevision = 0

    init(preferences: ChatTranslationPreferences) {
        self.preferences = preferences
    }

    func enqueue(_ request: ChatTranslationRequest) {
        if case .pending = translationsByMessageID[request.id] { return }
        if case .translated(let translation) = translationsByMessageID[request.id],
           ChatTranslationPreferences.languageFamily(translation.targetLanguageIdentifier) == ChatTranslationPreferences.languageFamily(request.targetLanguageIdentifier) {
            return
        }

        translationsByMessageID[request.id] = .pending
        pendingRequests.append(request)
        requestRevision += 1
    }

    func drainPendingRequests() -> [ChatTranslationRequest] {
        let requests = pendingRequests
        pendingRequests.removeAll()
        return requests
    }

    func drainPendingRequests(sourceLanguageIdentifier: String, targetLanguageIdentifier: String, limit: Int) -> [ChatTranslationRequest] {
        let sourceFamily = ChatTranslationPreferences.languageFamily(sourceLanguageIdentifier)
        let targetFamily = ChatTranslationPreferences.languageFamily(targetLanguageIdentifier)
        let requests = pendingRequests.filter {
            $0.sourceLanguageIdentifier.map(ChatTranslationPreferences.languageFamily) == sourceFamily
                && ChatTranslationPreferences.languageFamily($0.targetLanguageIdentifier) == targetFamily
        }.prefix(limit)
        pendingRequests.removeAll { request in
            requests.contains { $0.id == request.id }
        }
        return Array(requests)
    }

    func drainPendingRequests(targetLanguageIdentifier: String, limit: Int) -> [ChatTranslationRequest] {
        let targetFamily = ChatTranslationPreferences.languageFamily(targetLanguageIdentifier)
        let requests = pendingRequests.filter {
            ChatTranslationPreferences.languageFamily($0.targetLanguageIdentifier) == targetFamily
        }.prefix(limit)
        pendingRequests.removeAll { request in
            requests.contains { $0.id == request.id }
        }
        return Array(requests)
    }

    func complete(_ translation: ChatMessageTranslation) {
        translationsByMessageID[translation.messageID] = .translated(translation)
    }

    func fail(_ request: ChatTranslationRequest, reason: String) {
        translationsByMessageID[request.id] = .failed(reason)
    }

    func clearPendingRequests() {
        pendingRequests.removeAll()
        translationsByMessageID = translationsByMessageID.filter {
            if case .pending = $0.value { return false }
            return true
        }
        requestRevision += 1
    }

    func prune(retaining retainedMessageIDs: Set<FightcadeChatMessage.ID>) {
        translationsByMessageID = translationsByMessageID.filter { retainedMessageIDs.contains($0.key) }
        pendingRequests.removeAll { !retainedMessageIDs.contains($0.id) }
    }

    var nextPendingRequest: ChatTranslationRequest? {
        pendingRequests.first
    }
}

struct ChatTranslationPreferencesStore {
    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    func load() -> ChatTranslationPreferences {
        ChatTranslationPreferences(
            isEnabled: userDefaults.bool(forKey: Self.enabledKey),
            targetLanguageIdentifier: userDefaults.string(forKey: Self.targetLanguageKey)
        )
    }

    func save(_ preferences: ChatTranslationPreferences) {
        userDefaults.set(preferences.isEnabled, forKey: Self.enabledKey)

        if let target = preferences.targetLanguageIdentifier?.nonEmpty {
            userDefaults.set(target, forKey: Self.targetLanguageKey)
        } else {
            userDefaults.removeObject(forKey: Self.targetLanguageKey)
        }
    }

    private static let enabledKey = "chatTranslation.enabled"
    private static let targetLanguageKey = "chatTranslation.targetLanguage"
}

struct PlayerListFocusRequest: Equatable {
    let id = UUID()
    let channelName: String
    let username: String
}

extension AuthenticatedHomeViewModel {
    func canSendChat(to channel: FightcadeChannel) -> Bool {
        joinedChannelIDs.contains(channel.id)
            && !chatDraft.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
    }

    func sendChat() {
        guard let channel = selectedChannel else {
            return
        }

        sendChat(to: channel)
    }

    func sendChat(to channel: FightcadeChannel) {
        let message = String(chatDraft.trimmingCharacters(in: .whitespacesAndNewlines).prefix(500))
        guard !message.isEmpty else {
            return
        }

        trackPendingSentMessage(message, channelName: channel.name)
        append(
            FightcadeChatMessage(
                channelName: channel.name,
                username: session.displayName,
                body: message,
                kind: .local
            )
        )
        chatDraft = ""
        isSendingChat = true

        Task {
            defer { isSendingChat = false }

            do {
                try await lobbyService.sendChat(message, to: channel, from: session.displayName)
            } catch let error as FightcadeLobbyError {
                clearPendingSentMessage(message, channelName: channel.name)
                errorMessage = error.localizedDescription
            } catch {
                clearPendingSentMessage(message, channelName: channel.name)
                errorMessage = "Could not send message."
            }
        }
    }

    func appendSystemMessage(_ body: String, channelName: String) {
        append(
            FightcadeChatMessage(
                channelName: channelName,
                username: "system",
                body: body,
                kind: .system
            )
        )
    }

    func appendReceivedChatMessage(_ message: FightcadeChatMessage) {
        if message.kind == .user,
           isCurrentUser(message.username),
           hasPendingSentMessage(message.body, channelName: message.channelName) {
            return
        }

        let normalized = normalizedChatMessage(message)
        append(normalized)
        detectChatLanguageIfNeeded(for: normalized)
        enqueueChatTranslationIfNeeded(for: normalized)

        if normalized.kind == .user,
           !isCurrentUser(normalized.username),
           mentionsCurrentUser(normalized.body) {
            FightcadeMentionNotifier.notify(message: normalized)
        }
    }

    func appendChannelMotd(_ motd: FightcadeChannelMotd) {
        chatMessagesByChannel[motd.channelName]?.removeAll { $0.kind == .motd }
        append(
            FightcadeChatMessage(
                channelName: motd.channelName,
                username: "motd",
                body: motd.body,
                kind: .motd,
                events: motd.events
            )
        )
    }

    func chatMentionSuggestions(in channel: FightcadeChannel) -> [FightcadeChannelUser] {
        FightcadeChatMention.suggestions(
            in: chatDraft,
            users: usersByChannel[channel.name] ?? []
        )
    }

    func completeChatMention(_ username: String) {
        chatDraft = FightcadeChatMention.complete(chatDraft, with: username)
    }

    func messageMentionsCurrentUser(_ message: FightcadeChatMessage) -> Bool {
        message.kind == .user && mentionsCurrentUser(message.body)
    }

    func focusChatUser(_ username: String, in channel: FightcadeChannel) {
        guard user(named: username, in: channel) != nil else {
            return
        }

        requestPlayerListFocus(username: username, channelName: channel.name, selectChannel: true)
    }

    func requestPlayerListFocus(username: String, channelName: String, selectChannel: Bool = false) {
        if selectChannel {
            selectedChannelID = channelName
            isShowingChannelBrowser = false
            isShowingGameplay = false
        }

        playerListFocusRequest = PlayerListFocusRequest(channelName: channelName, username: username)
    }

    func clearPlayerListFocusRequest(_ request: PlayerListFocusRequest? = nil) {
        guard request == nil || playerListFocusRequest == request else {
            return
        }

        playerListFocusRequest = nil
    }

    private func append(_ message: FightcadeChatMessage) {
        var messages = chatMessagesByChannel[message.channelName] ?? []
        messages.append(message)
        let limitedMessages = limitedScrollback(messages)
        chatMessagesByChannel[message.channelName] = limitedMessages
        chatTranslation.prune(retaining: Set(limitedMessages.map(\.id)))
    }

    private func limitedScrollback(_ messages: [FightcadeChatMessage]) -> [FightcadeChatMessage] {
        let recentMessageIDs = Set(messages
            .filter { $0.kind != .motd }
            .suffix(channelChatScrollbackLimit)
            .map(\.id))
        let motdID = messages.last(where: { $0.kind == .motd })?.id

        return messages.filter { message in
            message.id == motdID || recentMessageIDs.contains(message.id)
        }
    }

    private func normalizedChatMessage(_ message: FightcadeChatMessage) -> FightcadeChatMessage {
        guard message.kind == .user, isCurrentUser(message.username) else {
            return message
        }

        return FightcadeChatMessage(
            id: message.id,
            channelName: message.channelName,
            username: message.username,
            body: message.body,
            kind: .local,
            sentAt: message.sentAt
        )
    }

    private func enqueueChatTranslationIfNeeded(for message: FightcadeChatMessage) {
        chatTranslation.preferences = ChatTranslationPreferencesStore().load()
        let preferences = chatTranslation.preferences
        guard preferences.isEnabled,
              message.kind == .user,
              !isCurrentUser(message.username) else {
            return
        }

        let target = preferences.resolvedTargetLanguageIdentifier
        let messageID = message.id
        let channelName = message.channelName
        let body = message.body

        Task { [weak self] in
            let result = await ChatTranslationRequestBuilder.build(
                id: messageID,
                channelName: channelName,
                body: body,
                targetLanguageIdentifier: target
            )

            guard let self else { return }
            switch result {
            case .request(let request):
                chatTranslation.enqueue(request)
            case .failed(let request, let reason):
                chatTranslation.fail(request, reason: reason)
            case .skipped:
                break
            }
        }
    }

    private func detectChatLanguageIfNeeded(for message: FightcadeChatMessage) {
        guard message.kind == .user, !isCurrentUser(message.username) else { return }

        let channelName = message.channelName
        let body = message.body
        Task { [weak self] in
            guard let languageIdentifier = await ChatTranslationRequestBuilder.detectLanguage(in: body) else { return }
            self?.recordDetectedChatLanguage(languageIdentifier, channelName: channelName)
        }
    }

    private func recordDetectedChatLanguage(_ identifier: String, channelName: String) {
        let languageFamily = ChatTranslationPreferences.languageFamily(identifier)
        var identifiers = detectedChatLanguageIdentifiersByChannel[channelName] ?? []
        identifiers = identifiers.filter { ChatTranslationPreferences.languageFamily($0) != languageFamily }
        identifiers.insert(languageFamily)
        detectedChatLanguageIdentifiersByChannel[channelName] = identifiers
    }

    func chatTranslationTargetChoices(in channel: FightcadeChannel) -> [(id: String, name: String)] {
        (detectedChatLanguageIdentifiersByChannel[channel.name] ?? [])
            .map { (id: $0, name: chatTranslationLanguageName(for: $0)) }
            .sorted { $0.name.localizedStandardCompare($1.name) == .orderedAscending }
    }

    func setChatTranslationTarget(_ identifier: String?, in channel: FightcadeChannel) {
        let preferences = ChatTranslationPreferences(
            isEnabled: identifier != nil,
            targetLanguageIdentifier: identifier
        )
        ChatTranslationPreferencesStore().save(preferences)
        chatTranslation.preferences = preferences

        guard preferences.isEnabled else {
            chatTranslation.clearPendingRequests()
            return
        }

        for message in chatMessagesByChannel[channel.name] ?? [] {
            enqueueChatTranslationIfNeeded(for: message)
        }
    }

    func chatTranslationLanguageName(for identifier: String) -> String {
        let normalized = identifier.replacingOccurrences(of: "_", with: "-")
        let family = ChatTranslationPreferences.languageFamily(normalized)
        let locale = Locale.current
        let name = locale.localizedString(forIdentifier: normalized)
            ?? locale.localizedString(forLanguageCode: family)
            ?? normalized.uppercased()
        return name.capitalized
    }

    private func trackPendingSentMessage(_ body: String, channelName: String) {
        prunePendingSentMessages(channelName: channelName)
        pendingSentMessages[channelName, default: []].append((body: body, sentAt: .now))
    }

    private func clearPendingSentMessage(_ body: String, channelName: String) {
        pendingSentMessages[channelName]?.removeAll { $0.body == body }
    }

    private func hasPendingSentMessage(_ body: String, channelName: String) -> Bool {
        prunePendingSentMessages(channelName: channelName)
        return pendingSentMessages[channelName]?.contains { $0.body == body } == true
    }

    private func prunePendingSentMessages(channelName: String) {
        let cutoff = Date().addingTimeInterval(-8)
        pendingSentMessages[channelName]?.removeAll { $0.sentAt < cutoff }
    }

    private func isCurrentUser(_ username: String) -> Bool {
        username.compare(session.displayName, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
            || username.compare(session.username, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
    }

    private func mentionsCurrentUser(_ body: String) -> Bool {
        FightcadeChatMention.containsMention(in: body, candidates: [session.displayName, session.username])
    }
}

private enum FightcadeMentionNotifier {
    static func notify(message: FightcadeChatMessage) {
        if NSSound(named: "Ping")?.play() != true {
            NSSound.beep()
        }

        Task {
            let center = UNUserNotificationCenter.current()
            let settings = await center.notificationSettings()
            let isAuthorized: Bool

            switch settings.authorizationStatus {
            case .authorized, .provisional, .ephemeral:
                isAuthorized = true
            case .notDetermined:
                isAuthorized = (try? await center.requestAuthorization(options: [.alert, .sound])) == true
            case .denied:
                isAuthorized = false
            @unknown default:
                isAuthorized = false
            }

            guard isAuthorized else {
                return
            }

            let content = UNMutableNotificationContent()
            content.title = "Mention from \(message.username)"
            content.subtitle = message.channelName
            content.body = message.body
            content.sound = .default

            let request = UNNotificationRequest(
                identifier: "macade-mention-\(message.id.uuidString)",
                content: content,
                trigger: nil
            )

            try? await center.add(request)
        }
    }
}
