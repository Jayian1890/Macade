import SwiftUI

struct PlayerRow: View {
    let channel: FightcadeChannel
    let row: PlayerListRowState
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let isFocused: Bool
    let onSelect: () -> Void
    @State private var isHovering = false

    private var user: FightcadeChannelUser { row.user }

    var body: some View {
        HStack(spacing: MacadeSpacing.small) {
            Text(user.countryFlag)
                .font(.system(size: 13))
                .frame(width: 22)

            Text(user.name)
                .font(.system(size: 16, weight: .bold, design: .rounded))
                .foregroundStyle(nameColor)
                .lineLimit(1)
                .layoutPriority(1)

            Spacer()

            rankBadge(user.displayRank)
        }
        .padding(.horizontal, MacadeSpacing.small)
        .frame(height: 40)
        .background(rowBackground, in: RoundedRectangle(cornerRadius: 12))
        .overlay(RoundedRectangle(cornerRadius: 12).stroke(rowStroke, lineWidth: 1))
        .contentShape(Rectangle())
        .onHover { isHovering = $0 }
        .onTapGesture(perform: onSelect)
        .onTapGesture(count: 2) {
            if row.isWatchable {
                viewModel.spectate(user, in: channel)
            } else if row.isChallengeable {
                viewModel.challenge(user, in: channel)
            }
        }
        .contextMenu {
            Button("Watch Match") {
                viewModel.spectate(user, in: channel)
            }
            .disabled(!row.isWatchable)

            Menu("Challenge") {
                Button("Unranked") {
                    viewModel.challenge(user, in: channel, ranked: 0)
                }

                ForEach(FightcadeChallenge.rankedValues, id: \.self) { rounds in
                    Button("FT\(rounds)") {
                        viewModel.challenge(user, in: channel, ranked: rounds)
                    }
                }
            }
            .disabled(!row.isChallengeable)
        }
    }

    private var rowBackground: Color {
        if isFocused {
            return MacadeColor.panelStrong.opacity(0.82)
        }

        if isHovering {
            return MacadeColor.panel.opacity(row.isChallengeable || row.isWatchable ? 0.72 : 0.42)
        }

        return .clear
    }

    private var rowStroke: Color {
        guard isHovering || isFocused else {
            return .clear
        }

        if row.isChallengeable || row.isWatchable {
            return MacadeColor.neonCyan.opacity(0.28)
        }

        return MacadeColor.stroke.opacity(0.7)
    }

    private var nameColor: Color {
        if row.isChallenging {
            return MacadeColor.neonCyan
        }

        if row.isCurrentUser {
            return MacadeColor.warning
        }

        if user.isPlaying || user.isAway {
            return MacadeColor.inkMuted.opacity(0.58)
        }

        return row.isChallengeable || isFocused || isHovering ? MacadeColor.ink : MacadeColor.inkMuted
    }

    @ViewBuilder
    private func rankBadge(_ rank: String?) -> some View {
        if let rank {
            Text(rank)
                .font(.system(size: 11, weight: .black, design: .rounded))
                .foregroundStyle(user.rankAccent)
                .frame(minWidth: 20, minHeight: 17)
                .padding(.horizontal, 5)
                .background(user.rankAccent.opacity(0.12), in: Capsule())
                .help("Rank")
        }
    }
}
