import SwiftUI

struct WatchMatchRowState: Identifiable, Equatable {
    let rows: [PlayerListRowState]

    var id: String {
        rows.first?.user.stream?.quarkID ?? rows.map(\.id).joined(separator: ":")
    }

    var title: String {
        rows.map { $0.user.name }.joined(separator: " vs ")
    }

    var firstWatchableRow: PlayerListRowState? {
        rows.first { $0.isWatchable }
    }
}

struct WatchMatchRow: View {
    let match: WatchMatchRowState
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        HStack(spacing: 7) {
            ForEach(Array(match.rows.prefix(2).enumerated()), id: \.element.id) { index, row in
                if index > 0 {
                    Text("vs")
                        .font(.system(size: 11, weight: .black, design: .monospaced))
                        .foregroundStyle(MacadeColor.inkMuted)
                }

                playerLabel(row.user)
            }

            Spacer(minLength: 0)
        }
        .padding(.horizontal, MacadeSpacing.small)
        .frame(height: 40)
        .background(MacadeColor.panel.opacity(0.56), in: RoundedRectangle(cornerRadius: 12))
        .contentShape(Rectangle())
        .onTapGesture(perform: watch)
        .contextMenu {
            Button("Watch Match", action: watch)
                .disabled(match.firstWatchableRow == nil)
        }
    }

    private func playerLabel(_ user: FightcadeChannelUser) -> some View {
        HStack(spacing: 4) {
            Text(user.countryFlag)
                .font(.system(size: 12))

            Text(user.name)
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(1)

            if let rank = user.displayRank {
                Text("(\(rank))")
                    .font(.system(size: 10, weight: .black, design: .rounded))
                    .foregroundStyle(user.rankAccent)
            }
        }
        .layoutPriority(1)
    }

    private func watch() {
        if let row = match.firstWatchableRow {
            viewModel.spectate(row.user, in: channel)
        }
    }
}
