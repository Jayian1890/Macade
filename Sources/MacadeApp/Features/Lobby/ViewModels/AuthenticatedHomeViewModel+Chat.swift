import Foundation

import AppKit
import UserNotifications

private let channelChatScrollbackLimit = 500

struct PlayerListFocusRequest: Equatable {
    let id = UUID()
    let channelName: String
    let username: String
}

extension AuthenticatedHomeViewModel {
    func sendChat() {
        guard let channel = selectedChannel else {
            return
        }

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
        chatMessagesByChannel[message.channelName] = limitedScrollback(messages)
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
