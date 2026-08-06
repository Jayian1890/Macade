import SwiftUI

struct ChallengeSidebarSection: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        let incomingChallenges = viewModel.incomingChallenges
        let outgoingChallenges = viewModel.outgoingChallenges.filter { !viewModel.isAutoMatchManagedChallenge($0) }

        if !incomingChallenges.isEmpty || !outgoingChallenges.isEmpty {
            VStack(alignment: .leading, spacing: MacadeSpacing.small) {
                header(totalCount: incomingChallenges.count + outgoingChallenges.count)

                if !incomingChallenges.isEmpty {
                    challengeGroup(
                        title: "Incoming",
                        icon: "bolt.horizontal.fill",
                        accent: MacadeColor.warning,
                        challenges: incomingChallenges,
                        mode: .incoming
                    )
                }

                if !outgoingChallenges.isEmpty {
                    challengeGroup(
                        title: "Sent",
                        icon: "paperplane.fill",
                        accent: MacadeColor.neonCyan,
                        challenges: outgoingChallenges,
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

    private func header(totalCount: Int) -> some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Image(systemName: "bolt.circle.fill")
                .foregroundStyle(MacadeColor.warning)

            Text("Challenges")
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)

            Spacer()

            Text("\(totalCount)")
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
                        Text(challenge.username)
                            .font(.system(size: 12, weight: .black, design: .rounded))
                            .foregroundStyle(MacadeColor.ink)
                            .lineLimit(1)
                    }

                    HStack(spacing: 5) {
                        PingQualityIcon(user?.ping, size: 9)

                        Text(compactUserDetail)
                            .lineLimit(1)
                    }
                    .font(.system(size: 10, weight: .bold, design: .rounded))
                    .foregroundStyle(MacadeColor.inkMuted)
                }
                .contentShape(Rectangle())
            }
            .buttonStyle(.plain)

            HStack(spacing: 6) {
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

    private var compactUserDetail: String {
        let country = user?.countryFlag.nonEmpty ?? "--"
        let ping = user?.ping.map { "\($0)ms" } ?? "--ms"
        let rank = user?.displayRank ?? "--"
        return "\(country) · \(ping) · \(rank)"
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

struct ChallengeChatRow: View {
    enum Mode {
        case incoming
        case outgoing
    }

    let challenge: FightcadeChallenge
    let user: FightcadeChannelUser?
    let mode: Mode
    let isBusy: Bool
    let acceptAction: () -> Void
    let rejectAction: () -> Void
    let cancelAction: () -> Void

    var body: some View {
        HStack(alignment: .top, spacing: MacadeSpacing.small) {
            Text("now")
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted.opacity(0.62))
                .frame(width: 54, alignment: .leading)

            Image(systemName: mode == .incoming ? "bolt.circle.fill" : "paperplane.circle.fill")
                .font(.system(size: 28, weight: .black))
                .foregroundStyle(accent)
                .frame(width: 28, height: 28)

            VStack(alignment: .leading, spacing: 7) {
                Text(messageText)
                    .font(.system(size: 15, weight: .semibold, design: .rounded))
                    .foregroundStyle(MacadeColor.ink)
                    .textSelection(.enabled)

                HStack(spacing: MacadeSpacing.xSmall) {
                    PingQualityIcon(user?.ping, size: 10)

                    Text(userDetail)
                        .font(MacadeTypography.caption)
                        .foregroundStyle(MacadeColor.inkMuted)

                    Spacer(minLength: MacadeSpacing.small)

                    actionButtons
                }
            }
            .padding(MacadeSpacing.small)
            .frame(maxWidth: .infinity, alignment: .leading)
            .background(MacadeColor.panel.opacity(0.68), in: RoundedRectangle(cornerRadius: 14))
            .overlay(RoundedRectangle(cornerRadius: 14).stroke(accent.opacity(0.34), lineWidth: 1))
        }
        .frame(maxWidth: .infinity, alignment: .leading)
    }

    @ViewBuilder
    private var actionButtons: some View {
        switch mode {
        case .incoming:
            Button("Decline", action: rejectAction)
                .buttonStyle(.borderless)
                .disabled(isBusy)
            Button("Accept", action: acceptAction)
                .buttonStyle(.borderedProminent)
                .tint(MacadeColor.warning)
                .disabled(isBusy)
        case .outgoing:
            Button("Cancel", action: cancelAction)
                .buttonStyle(.borderless)
                .disabled(isBusy)
        }
    }

    private var accent: Color {
        mode == .incoming ? MacadeColor.warning : MacadeColor.neonCyan
    }

    private var messageText: String {
        switch mode {
        case .incoming:
            "\(challenge.username) challenged you."
        case .outgoing:
            "Challenge sent to \(challenge.username)."
        }
    }

    private var userDetail: String {
        let country = user?.countryFlag.nonEmpty ?? "--"
        let ping = user?.ping.map { "\($0)ms" } ?? "--ms"
        let rank = user?.displayRank ?? "Unranked"
        return "\(country) · \(ping) · Rank \(rank)"
    }
}
