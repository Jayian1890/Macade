import SwiftUI

struct ChallengeSidebarSection: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        if !viewModel.incomingChallenges.isEmpty || !viewModel.outgoingChallenges.isEmpty {
            VStack(alignment: .leading, spacing: MacadeSpacing.small) {
                header

                if !viewModel.incomingChallenges.isEmpty {
                    challengeGroup(
                        title: "Incoming",
                        icon: "bolt.horizontal.fill",
                        accent: MacadeColor.warning,
                        challenges: viewModel.incomingChallenges,
                        mode: .incoming
                    )
                }

                if !viewModel.outgoingChallenges.isEmpty {
                    challengeGroup(
                        title: "Sent",
                        icon: "paperplane.fill",
                        accent: MacadeColor.neonCyan,
                        challenges: viewModel.outgoingChallenges,
                        mode: .outgoing
                    )
                }
            }
            .padding(MacadeSpacing.xSmall)
            .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 14))
            .overlay(
                RoundedRectangle(cornerRadius: 14)
                    .stroke(MacadeColor.warning.opacity(0.25), lineWidth: 1)
            )
        }
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Image(systemName: "bolt.circle.fill")
                .foregroundStyle(MacadeColor.warning)

            Text("Challenges")
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)

            Spacer()

            Text("\(viewModel.incomingChallenges.count + viewModel.outgoingChallenges.count)")
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.warning)
        }
        .padding(.horizontal, 2)
    }

    private func challengeGroup(
        title: String,
        icon: String,
        accent: Color,
        challenges: [FightcadeChallenge],
        mode: ChallengeSidebarCard.Mode
    ) -> some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
            HStack(spacing: 4) {
                Image(systemName: icon)
                Text(title.uppercased())
                Spacer()
                Text("\(challenges.count)")
            }
            .font(.system(size: 9, weight: .black, design: .monospaced))
            .foregroundStyle(accent)
            .padding(.horizontal, 2)

            ForEach(challenges) { challenge in
                ChallengeSidebarCard(
                    challenge: challenge,
                    user: viewModel.user(for: challenge),
                    accent: accent,
                    mode: mode,
                    isBusy: viewModel.isSendingChallenge,
                    openAction: { viewModel.openChallengeChannel(challenge) },
                    acceptAction: { viewModel.acceptIncomingChallenge(challenge) },
                    rejectAction: { viewModel.rejectIncomingChallenge(challenge) },
                    cancelAction: { viewModel.cancelOutgoingChallenge(challenge) }
                )
            }
        }
    }
}

private struct ChallengeSidebarCard: View {
    enum Mode {
        case incoming
        case outgoing
    }

    let challenge: FightcadeChallenge
    let user: FightcadeChannelUser?
    let accent: Color
    let mode: Mode
    let isBusy: Bool
    let openAction: () -> Void
    let acceptAction: () -> Void
    let rejectAction: () -> Void
    let cancelAction: () -> Void

    var body: some View {
        VStack(alignment: .leading, spacing: 6) {
            Button(action: openAction) {
                VStack(alignment: .leading, spacing: 2) {
                    HStack(spacing: 4) {
                        Text(user?.countryFlag ?? "")
                            .font(.system(size: 11))

                        Text(challenge.username)
                            .font(.system(size: 12, weight: .black, design: .rounded))
                            .foregroundStyle(MacadeColor.ink)
                            .lineLimit(1)

                        Spacer(minLength: 0)

                        Text(matchType)
                            .font(.system(size: 9, weight: .black, design: .monospaced))
                            .foregroundStyle(accent)
                    }

                    HStack(spacing: 5) {
                        Text(challenge.channelName)
                            .lineLimit(1)
                            .help(challenge.channelName)

                        Text("-")

                        Text(user?.displayRank ?? "--")
                    }
                    .font(.system(size: 10, weight: .bold, design: .rounded))
                    .foregroundStyle(MacadeColor.inkMuted)
                }
                .contentShape(Rectangle())
            }
            .buttonStyle(.plain)

            HStack(spacing: 6) {
                PingQualityIcon(user?.ping, size: 9)

                Spacer(minLength: 0)

                actionButtons
            }
        }
        .padding(MacadeSpacing.xSmall)
        .background(MacadeColor.sidebar.opacity(0.8), in: RoundedRectangle(cornerRadius: 10))
        .overlay(
            RoundedRectangle(cornerRadius: 10)
                .stroke(accent.opacity(0.38), lineWidth: 1)
        )
    }

    @ViewBuilder
    private var actionButtons: some View {
        switch mode {
        case .incoming:
            iconButton("xmark", help: "Reject", action: rejectAction)
            iconButton("checkmark", help: "Accept", action: acceptAction, prominent: true)
        case .outgoing:
            iconButton("xmark", help: "Cancel", action: cancelAction, prominent: true)
        }
    }

    private var matchType: String {
        challenge.ranked == 0 ? "UNR" : "FT\(challenge.ranked)"
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
