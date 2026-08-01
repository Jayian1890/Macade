import SwiftUI

struct FriendsSidebarSection: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            header
            addField
            rows
        }
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Image(systemName: "person.2.fill")
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.warning)

            Text("Friends")
                .font(.system(size: 12, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.inkMuted)

            Spacer()

            Text(onlineCountText)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted.opacity(0.78))
                .help("Friends actively online in joined room rosters")
        }
    }

    private var onlineCountText: String {
        let rows = viewModel.friendRows
        let onlineCount = rows.filter(\.isOnline).count
        return "\(onlineCount)/\(rows.count) online"
    }

    private var addField: some View {
        HStack(spacing: 5) {
            TextField("Add username", text: $viewModel.friendDraft)
                .textFieldStyle(.plain)
                .font(.system(size: 12, weight: .bold, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .onSubmit(viewModel.addFriendFromDraft)

            Button(action: viewModel.addFriendFromDraft) {
                Image(systemName: "plus")
                    .font(.system(size: 10, weight: .black))
                    .frame(width: 20, height: 20)
                    .foregroundStyle(viewModel.canAddFriendFromDraft ? MacadeColor.midnight : MacadeColor.inkMuted)
                    .background(viewModel.canAddFriendFromDraft ? MacadeColor.warning : MacadeColor.panel, in: Circle())
            }
            .buttonStyle(.plain)
            .disabled(!viewModel.canAddFriendFromDraft)
            .help("Add friend")
        }
        .padding(.horizontal, MacadeSpacing.xSmall)
        .frame(height: 30)
        .background(MacadeColor.panel.opacity(0.58), in: RoundedRectangle(cornerRadius: 10))
    }

    @ViewBuilder
    private var rows: some View {
        let rows = viewModel.friendRows
        if rows.isEmpty {
            Text("Add players from chat or the player list.")
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted.opacity(0.72))
                .padding(MacadeSpacing.small)
                .frame(maxWidth: .infinity, alignment: .leading)
                .background(MacadeColor.panel.opacity(0.38), in: RoundedRectangle(cornerRadius: 12))
        } else {
            VStack(spacing: 4) {
                ForEach(rows) { row in
                    FriendSidebarRow(row: row, viewModel: viewModel)
                }
            }
        }
    }
}

private struct FriendSidebarRow: View {
    let row: FightcadeFriendRowState
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var isHovering = false

    var body: some View {
        HStack(spacing: 6) {
            Circle()
                .fill(statusColor)
                .frame(width: 8, height: 8)
                .help(row.onlineHelpText)

            VStack(alignment: .leading, spacing: 1) {
                Text(row.title)
                    .font(.system(size: 12, weight: .black, design: .rounded))
                    .foregroundStyle(row.isOnline ? MacadeColor.ink : MacadeColor.inkMuted)
                    .lineLimit(1)

                Text(row.statusText)
                    .font(.system(size: 9, weight: .bold, design: .rounded))
                    .foregroundStyle(MacadeColor.inkMuted.opacity(0.76))
                    .lineLimit(1)
            }

            Spacer(minLength: 0)

            onlineBadge
            actionButtons
        }
        .padding(.horizontal, MacadeSpacing.xSmall)
        .frame(height: 38)
        .background(rowBackground, in: RoundedRectangle(cornerRadius: 10))
        .overlay(RoundedRectangle(cornerRadius: 10).stroke(rowStroke, lineWidth: 1))
        .contentShape(Rectangle())
        .onHover { isHovering = $0 }
        .onTapGesture { viewModel.openFriend(row) }
        .contextMenu { menuItems }
    }

    private var actionButtons: some View {
        HStack(spacing: 3) {
            if row.isWatchable {
                iconButton("eye.fill", help: "Watch match") {
                    viewModel.spectateFriend(row)
                }
            }

            if row.isChallengeable || row.isChallenging {
                iconButton(row.isChallenging ? "paperplane.fill" : "bolt.fill", help: row.isChallenging ? "Challenge sent" : "Challenge") {
                    viewModel.challengeFriend(row)
                }
                .disabled(row.isChallenging)
            }
        }
    }

    private var onlineBadge: some View {
        Text(row.onlineStateText)
            .font(.system(size: 8, weight: .black, design: .rounded))
            .foregroundStyle(row.isOnline ? MacadeColor.midnight : MacadeColor.inkMuted)
            .padding(.horizontal, 5)
            .frame(height: 17)
            .background(row.isOnline ? statusColor : MacadeColor.panel.opacity(0.8), in: Capsule())
            .help(row.onlineHelpText)
    }

    private func iconButton(_ systemName: String, help: String, action: @escaping () -> Void) -> some View {
        Button(action: action) {
            Image(systemName: systemName)
                .font(.system(size: 10, weight: .black))
                .frame(width: 20, height: 20)
                .foregroundStyle(MacadeColor.midnight)
                .background(MacadeColor.neonCyan, in: Circle())
        }
        .buttonStyle(.plain)
        .help(help)
    }

    @ViewBuilder
    private var menuItems: some View {
        Button("Show in Room") {
            viewModel.openFriend(row)
        }
        .disabled(row.user == nil || row.channel == nil)

        Button("Watch Match") {
            viewModel.spectateFriend(row)
        }
        .disabled(!row.isWatchable)

        Menu("Challenge") {
            Button("Unranked") {
                viewModel.challengeFriend(row, ranked: 0)
            }

            ForEach(FightcadeChallenge.rankedValues, id: \.self) { rounds in
                Button("FT\(rounds)") {
                    viewModel.challengeFriend(row, ranked: rounds)
                }
            }
        }
        .disabled(!row.isChallengeable)

        Divider()

        Button("Remove Friend") {
            viewModel.removeFriend(row.friend)
        }
    }

    private var statusColor: Color {
        guard let user = row.user else {
            return MacadeColor.inkMuted.opacity(0.38)
        }

        return user.isPlaying || user.isAway ? MacadeColor.warning : MacadeColor.neonCyan
    }

    private var rowBackground: Color {
        if isHovering {
            return MacadeColor.panel.opacity(0.74)
        }

        return row.isOnline ? MacadeColor.panel.opacity(0.46) : .clear
    }

    private var rowStroke: Color {
        isHovering ? MacadeColor.warning.opacity(0.34) : .clear
    }
}
