import SwiftUI

struct ChatMessageRow: View {
    let message: FightcadeChatMessage
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var isHoveringName = false

    var body: some View {
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
                        .contentShape(Rectangle())
                        .onTapGesture(count: 2, perform: challengeFromChat)
                        .onHover { isHoveringName = $0 }
                        .help(nameHelp)
                        .contextMenu {
                            Button("Challenge Unranked", action: challengeFromChat)
                                .disabled(!canChallengeFromChat)
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

                Text(message.body)
                    .font(.system(size: 15, weight: message.kind == .system ? .semibold : .medium, design: .rounded))
                    .foregroundStyle(message.kind == .system ? MacadeColor.inkMuted.opacity(0.86) : MacadeColor.ink)
                    .lineLimit(nil)
                    .fixedSize(horizontal: false, vertical: true)
                    .textSelection(.enabled)
            }
            .frame(maxWidth: .infinity, alignment: .leading)
        }
        .frame(maxWidth: .infinity, alignment: .leading)
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

    private var canChallengeFromChat: Bool {
        message.kind == .user && viewModel.canChallenge(message.username, in: channel)
    }

    private var chatUser: FightcadeChannelUser? {
        viewModel.user(named: message.username, in: channel)
    }

    private var nameHelp: String {
        canChallengeFromChat ? "Double-click to challenge unranked" : "Chat author"
    }

    private var nameColor: Color {
        switch message.kind {
        case .local:
            MacadeColor.warning
        case .system:
            MacadeColor.inkMuted
        case .user:
            canChallengeFromChat || isHoveringName ? MacadeColor.neonCyan : MacadeColor.inkMuted
        }
    }

    private var avatarBorderColor: Color {
        switch message.kind {
        case .local:
            MacadeColor.warning
        case .system:
            MacadeColor.inkMuted
        case .user:
            canChallengeFromChat || isHoveringName ? MacadeColor.neonCyan : MacadeColor.stroke
        }
    }

    private func challengeFromChat() {
        guard canChallengeFromChat else {
            return
        }

        viewModel.challenge(message.username, in: channel)
    }
}
