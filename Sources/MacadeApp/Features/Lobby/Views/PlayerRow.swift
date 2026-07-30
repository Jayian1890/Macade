import SwiftUI

struct PlayerRow: View {
    let channel: FightcadeChannel
    let row: PlayerListRowState
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let isFocused: Bool
    let onSelect: () -> Void

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
        .background(isFocused ? MacadeColor.panel.opacity(0.82) : .clear, in: RoundedRectangle(cornerRadius: 12))
        .contentShape(Rectangle())
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
                    viewModel.challenge(user, in: channel)
                }

                ForEach(3...20, id: \.self) { rounds in
                    Button("FT\(rounds)") {
                        viewModel.challenge(user, in: channel, ranked: rounds)
                    }
                }
            }
            .disabled(!row.isChallengeable)
        }
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

        return row.isChallengeable || isFocused ? MacadeColor.ink : MacadeColor.inkMuted
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
