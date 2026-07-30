import SwiftUI

struct ChatMessageRow: View {
    let message: FightcadeChatMessage
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var isHoveringName = false

    var body: some View {
        if message.kind == .motd {
            FightcadeMotdMessageRow(message: message)
        } else {
            chatRow
        }
    }

    private var chatRow: some View {
        HStack(alignment: .top, spacing: MacadeSpacing.small) {
            Text(message.sentAt.formatted(date: .omitted, time: .shortened))
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted.opacity(0.62))
                .frame(width: 54, alignment: .leading)

            PlayerAvatarView(
                url: chatUser?.avatarURL,
                fallbackName: message.username,
                size: 28,
                borderColor: avatarBorderColor
            )

            VStack(alignment: .leading, spacing: 4) {
                HStack(spacing: MacadeSpacing.xSmall) {
                    Text(message.username)
                        .font(.system(size: 15, weight: .black, design: .rounded))
                        .foregroundStyle(nameColor)
                        .lineLimit(1)
                        .padding(.horizontal, 7)
                        .frame(height: 22)
                        .background(chatNameBackground, in: Capsule())
                        .overlay(Capsule().stroke(chatNameStroke, lineWidth: 1))
                        .contentShape(Rectangle())
                        .onTapGesture(perform: focusChatUser)
                        .onTapGesture(count: 2, perform: challengeFromChat)
                        .onHover { isHoveringName = $0 }
                        .help(nameHelp)
                        .contextMenu {
                            challengeMenu
                        }

                    if let rank = chatUser?.displayRank, message.kind != .system {
                        Text(rank)
                            .font(.system(size: 9, weight: .black, design: .rounded))
                            .foregroundStyle(MacadeColor.warning)
                            .padding(.horizontal, 5)
                            .padding(.vertical, 1)
                            .background(MacadeColor.warning.opacity(0.12), in: Capsule())
                    }

                    challengeControl
                }

                mentionText
                    .font(.system(size: 15, weight: message.kind == .system ? .semibold : .medium, design: .rounded))
                    .lineLimit(nil)
                    .fixedSize(horizontal: false, vertical: true)
                    .textSelection(.enabled)
            }
            .frame(maxWidth: .infinity, alignment: .leading)
        }
        .padding(.horizontal, mentionsCurrentUser ? 6 : 0)
        .padding(.vertical, mentionsCurrentUser ? 4 : 0)
        .background(mentionsCurrentUser ? MacadeColor.warning.opacity(0.12) : .clear, in: RoundedRectangle(cornerRadius: 10))
        .frame(maxWidth: .infinity, alignment: .leading)
    }

    private var mentionText: Text {
        let segments = FightcadeChatMention.segments(
            in: message.body,
            candidates: mentionCandidates,
            currentUserAliases: currentUserAliases
        )

        return segments.reduce(Text("")) { result, segment in
            result + styledText(for: segment)
        }
    }

    @ViewBuilder
    private var challengeControl: some View {
        if viewModel.isChallenging(message.username, in: channel) {
            Image(systemName: "paperplane.fill")
                .font(.system(size: 10, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)
                .frame(width: 18, height: 18)
                .background(MacadeColor.neonCyan.opacity(0.15), in: Circle())
                .help("Sent")
        } else if canChallengeFromChat {
            Button(action: challengeFromChat) {
                Image(systemName: "bolt.fill")
                    .font(.system(size: 10, weight: .black))
                    .foregroundStyle(isHoveringName ? MacadeColor.midnight : MacadeColor.warning)
                    .frame(width: 18, height: 18)
                    .background(MacadeColor.warning.opacity(isHoveringName ? 0.95 : 0.18), in: Circle())
            }
            .buttonStyle(.plain)
            .help("Challenge unranked")
        }
    }

    @ViewBuilder
    private var challengeMenu: some View {
        Menu("Challenge") {
            Button("Unranked", action: challengeFromChat)

            ForEach(FightcadeChallenge.rankedValues, id: \.self) { rounds in
                Button("FT\(rounds)") {
                    challengeFromChat(ranked: rounds)
                }
            }
        }
        .disabled(!canChallengeFromChat)
    }

    private var canChallengeFromChat: Bool {
        message.kind == .user && viewModel.canChallenge(message.username, in: channel)
    }

    private var chatUser: FightcadeChannelUser? {
        viewModel.user(named: message.username, in: channel)
    }

    private var mentionCandidates: [String] {
        viewModel.selectedChannelUsers.map(\.name) + currentUserAliases
    }

    private var currentUserAliases: [String] {
        [viewModel.session.displayName, viewModel.session.username]
    }

    private var mentionsCurrentUser: Bool {
        viewModel.messageMentionsCurrentUser(message)
    }

    private var nameHelp: String {
        canChallengeFromChat ? "Click to show in player list. Double-click to challenge unranked" : "Click to show in player list"
    }

    private var nameColor: Color {
        switch message.kind {
        case .local:
            MacadeColor.warning
        case .system:
            MacadeColor.inkMuted
        case .user:
            canChallengeFromChat || isHoveringName ? MacadeColor.neonCyan : MacadeColor.inkMuted
        case .motd:
            MacadeColor.warning
        }
    }

    private var chatNameBackground: Color {
        guard canChallengeFromChat || isHoveringName else {
            return .clear
        }

        return MacadeColor.neonCyan.opacity(isHoveringName ? 0.18 : 0.08)
    }

    private var chatNameStroke: Color {
        isHoveringName && canChallengeFromChat ? MacadeColor.neonCyan.opacity(0.38) : .clear
    }

    private var avatarBorderColor: Color {
        switch message.kind {
        case .local:
            MacadeColor.warning
        case .system:
            MacadeColor.inkMuted
        case .user:
            canChallengeFromChat || isHoveringName ? MacadeColor.neonCyan : MacadeColor.stroke
        case .motd:
            MacadeColor.warning
        }
    }

    private func challengeFromChat() {
        challengeFromChat(ranked: 0)
    }

    private func focusChatUser() {
        guard message.kind == .user || message.kind == .local else {
            return
        }

        viewModel.focusChatUser(message.username, in: channel)
    }

    private func challengeFromChat(ranked: Int) {
        guard canChallengeFromChat else {
            return
        }

        viewModel.challenge(message.username, in: channel, ranked: ranked)
    }

    private func styledText(for segment: FightcadeChatMentionSegment) -> Text {
        guard segment.isMention else {
            return Text(segment.text)
                .foregroundColor(message.kind == .system ? MacadeColor.inkMuted.opacity(0.86) : MacadeColor.ink)
        }

        return Text(segment.text)
            .fontWeight(.black)
            .foregroundColor(segment.isCurrentUser ? MacadeColor.warning : MacadeColor.neonCyan)
    }
}

private struct FightcadeMotdMessageRow: View {
    let message: FightcadeChatMessage

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            VStack(alignment: .leading, spacing: 5) {
                ForEach(FightcadeMotdTextFormatter.lines(in: message.body)) { line in
                    Text(line.content)
                        .lineLimit(nil)
                        .fixedSize(horizontal: false, vertical: true)
                        .textSelection(.enabled)
                }
            }

            if !message.events.isEmpty {
                Text("EVENTS")
                    .font(.system(size: 13, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.warning)
                    .padding(.top, 2)

                LazyVGrid(columns: [GridItem(.adaptive(minimum: 168), spacing: 10)], spacing: 10) {
                    ForEach(message.events) { event in
                        FightcadeMotdEventCard(event: event)
                    }
                }
            }
        }
        .padding(MacadeSpacing.medium)
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(MacadeColor.panel.opacity(0.64), in: RoundedRectangle(cornerRadius: 14))
        .overlay(RoundedRectangle(cornerRadius: 14).stroke(MacadeColor.warning.opacity(0.16), lineWidth: 1))
    }
}

private struct FightcadeMotdEventCard: View {
    let event: FightcadeEvent
    @Environment(\.openURL) private var openURL

    var body: some View {
        VStack(alignment: .leading, spacing: 7) {
            FightcadeArtworkImage(url: event.previewURL) { fallbackPreview }
                .frame(height: 76)
                .clipShape(RoundedRectangle(cornerRadius: 9))

            Text(event.name)
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(2)

            Text(eventDateText)
                .font(.system(size: 10, weight: .bold, design: .rounded))
                .foregroundStyle(MacadeColor.inkMuted)
                .lineLimit(2)

            HStack(spacing: 6) {
                eventButton("Info", url: event.link)
                eventButton("Stream", url: event.stream)
            }
        }
        .padding(8)
        .background(MacadeColor.row.opacity(0.72), in: RoundedRectangle(cornerRadius: 12))
        .overlay(RoundedRectangle(cornerRadius: 12).stroke(MacadeColor.stroke, lineWidth: 1))
    }

    private var eventDateText: String {
        let date = event.date.formatted(date: .abbreviated, time: .shortened)
        guard let region = event.region, !region.isEmpty else {
            return date
        }

        return "\(date) - \(region)"
    }

    @ViewBuilder
    private func eventButton(_ title: String, url: URL?) -> some View {
        if let url {
            Button(title) {
                openURL(url)
            }
            .buttonStyle(.plain)
            .font(.system(size: 10, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.midnight)
            .padding(.horizontal, 8)
            .frame(height: 22)
            .background(MacadeColor.warning, in: Capsule())
        }
    }

    private var fallbackPreview: some View {
        ZStack {
            LinearGradient(colors: [MacadeColor.arcadeBlue, MacadeColor.deepPlum], startPoint: .topLeading, endPoint: .bottomTrailing)
            Text(event.gameID.prefix(3).uppercased())
                .font(.system(size: 20, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.ink.opacity(0.65))
        }
    }
}
