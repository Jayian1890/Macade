import Foundation

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

        append(normalizedChatMessage(message))
    }

    private func append(_ message: FightcadeChatMessage) {
        chatMessagesByChannel[message.channelName, default: []].append(message)
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
}
