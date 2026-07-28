import SwiftUI

struct ChallengeBanner: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        if !incomingChallenges.isEmpty {
            incomingStrip
        } else if !outgoingChallenges.isEmpty {
            outgoingStrip
        }
    }

    private var incomingChallenges: [FightcadeChallenge] {
        viewModel.incomingChallenges.filter { $0.channelName == channel.name }
    }

    private var outgoingChallenges: [FightcadeChallenge] {
        viewModel.outgoingChallenges.filter { $0.channelName == channel.name }
    }

    private var incomingStrip: some View {
        HStack(spacing: MacadeSpacing.small) {
            ChallengeStripBadge(
                icon: "bolt.horizontal.fill",
                value: "\(incomingChallenges.count)",
                accent: MacadeColor.warning
            )
            .help("Incoming challenges")

            ScrollView(.horizontal, showsIndicators: false) {
                LazyHStack(spacing: MacadeSpacing.xSmall) {
                    ForEach(incomingChallenges) { challenge in
                        ChallengeCard(
                            challenge: challenge,
                            user: viewModel.user(for: challenge),
                            accent: MacadeColor.warning,
                            primaryIcon: "checkmark",
                            primaryHelp: "Accept",
                            secondaryIcon: "xmark",
                            secondaryHelp: "Reject",
                            primaryAction: { viewModel.acceptIncomingChallenge(challenge) },
                            secondaryAction: { viewModel.rejectIncomingChallenge(challenge) },
                            isBusy: viewModel.isSendingChallenge
                        )
                    }
                }
                .padding(.trailing, MacadeSpacing.medium)
            }
        }
        .padding(.leading, MacadeSpacing.medium)
        .frame(height: 58)
        .background(stripBackground(accent: MacadeColor.warning))
        .overlay(alignment: .bottom) { divider }
    }

    private var outgoingStrip: some View {
        HStack(spacing: MacadeSpacing.small) {
            ChallengeStripBadge(
                icon: "paperplane.fill",
                value: "\(outgoingChallenges.count)",
                accent: MacadeColor.neonCyan
            )
            .help("Sent challenges")

            ScrollView(.horizontal, showsIndicators: false) {
                LazyHStack(spacing: MacadeSpacing.xSmall) {
                    ForEach(outgoingChallenges) { challenge in
                        ChallengeCard(
                            challenge: challenge,
                            user: viewModel.user(for: challenge),
                            accent: MacadeColor.neonCyan,
                            primaryIcon: "xmark",
                            primaryHelp: "Cancel",
                            secondaryIcon: nil,
                            secondaryHelp: nil,
                            primaryAction: { viewModel.cancelOutgoingChallenge(challenge) },
                            secondaryAction: nil,
                            isBusy: viewModel.isSendingChallenge
                        )
                    }
                }
                .padding(.trailing, MacadeSpacing.medium)
            }
        }
        .padding(.leading, MacadeSpacing.medium)
        .frame(height: 58)
        .background(stripBackground(accent: MacadeColor.neonCyan))
        .overlay(alignment: .bottom) { divider }
    }

    private func stripBackground(accent: Color) -> some View {
        LinearGradient(
            colors: [accent.opacity(0.14), MacadeColor.panel.opacity(0.38), .clear],
            startPoint: .leading,
            endPoint: .trailing
        )
    }

    private var divider: some View {
        Rectangle()
            .fill(MacadeColor.divider)
            .frame(height: 1)
    }
}

private struct ChallengeStripBadge: View {
    let icon: String
    let value: String
    let accent: Color

    var body: some View {
        HStack(spacing: 3) {
            Image(systemName: icon)
                .font(.system(size: 12, weight: .black))
            Text(value)
                .font(.system(size: 11, weight: .black, design: .monospaced))
        }
        .foregroundStyle(accent)
        .frame(width: 44, height: 30)
        .background(accent.opacity(0.13), in: Capsule())
        .overlay(
            Capsule()
                .stroke(accent.opacity(0.45), lineWidth: 1)
        )
    }
}

private struct ChallengeCard: View {
    let challenge: FightcadeChallenge
    let user: FightcadeChannelUser?
    let accent: Color
    let primaryIcon: String
    let primaryHelp: String
    let secondaryIcon: String?
    let secondaryHelp: String?
    let primaryAction: () -> Void
    let secondaryAction: (() -> Void)?
    let isBusy: Bool

    var body: some View {
        VStack(alignment: .leading, spacing: 3) {
            HStack(spacing: MacadeSpacing.xSmall) {
                Text(challenge.username)
                    .font(.system(size: 13, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.ink)
                    .lineLimit(1)
                    .minimumScaleFactor(0.85)
                    .layoutPriority(1)
                    .help(challenge.username)

                Text(challenge.ranked == 0 ? "U" : "R")
                    .font(.system(size: 9, weight: .black, design: .monospaced))
                    .foregroundStyle(accent)
                    .padding(.horizontal, 4)
                    .padding(.vertical, 1)
                    .background(accent.opacity(0.14), in: Capsule())
                    .help(challenge.ranked == 0 ? "Unranked" : "Ranked")
            }

            HStack(spacing: MacadeSpacing.xSmall) {
                stat(icon: "rosette", value: user?.displayRank ?? "--", help: "Rank")
                PingQualityIcon(user?.ping, size: 9)

                Spacer(minLength: MacadeSpacing.small)

                if let secondaryIcon, let secondaryHelp, let secondaryAction {
                    iconButton(secondaryIcon, help: secondaryHelp, action: secondaryAction)
                }

                iconButton(primaryIcon, help: primaryHelp, action: primaryAction, prominent: true)
            }
        }
        .padding(.horizontal, MacadeSpacing.xSmall)
        .frame(width: cardWidth, height: 44)
        .background(MacadeColor.panel.opacity(0.78), in: RoundedRectangle(cornerRadius: 10))
        .overlay(
            RoundedRectangle(cornerRadius: 10)
                .stroke(accent.opacity(0.38), lineWidth: 1)
        )
    }

    private var cardWidth: CGFloat {
        let nameWidth = CGFloat(challenge.username.count) * 8.5
        return min(340, max(232, nameWidth + 92))
    }

    private func stat(icon: String, value: String, help: String) -> some View {
        HStack(spacing: 3) {
            Image(systemName: icon)
                .font(.system(size: 9, weight: .bold))
            Text(value)
                .font(.system(size: 10, weight: .bold, design: .monospaced))
        }
        .foregroundStyle(MacadeColor.inkMuted)
        .help(help)
    }

    private func iconButton(
        _ icon: String,
        help: String,
        action: @escaping () -> Void,
        prominent: Bool = false
    ) -> some View {
        Button(action: action) {
            Image(systemName: icon)
                .font(.system(size: 10, weight: .black))
                .frame(width: 22, height: 22)
                .foregroundStyle(prominent ? MacadeColor.midnight : MacadeColor.inkMuted)
                .background(prominent ? accent.opacity(0.95) : MacadeColor.panel, in: Circle())
        }
        .buttonStyle(.plain)
        .disabled(isBusy)
        .help(help)
    }
}
