import SwiftUI

struct LobbySidebarView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let onSignOut: () -> Void

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            sidebarHeader
            filters
            ChallengeSidebarSection(viewModel: viewModel)
            joinedSection
            FriendsSidebarSection(viewModel: viewModel)
            Spacer(minLength: MacadeSpacing.medium)
            statusFooter
            accountFooter
        }
        .padding(.horizontal, MacadeSpacing.small)
        .padding(.vertical, MacadeSpacing.medium)
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background(MacadeColor.sidebar.opacity(0.72))
        .overlay(alignment: .trailing) {
            Rectangle()
                .fill(MacadeColor.stroke)
                .frame(width: 1)
        }
    }

    private var sidebarHeader: some View {
        HStack(spacing: MacadeSpacing.small) {
            Image(systemName: "rectangle.3.group")
                .font(.system(size: 16, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)

            Text("Rooms")
                .font(.system(size: 18, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
        }
    }

    private var filters: some View {
        VStack(spacing: MacadeSpacing.xSmall) {
            SidebarButton(
                icon: "magnifyingglass",
                title: "Browse",
                value: nil,
                isSelected: !viewModel.isShowingGameplay && viewModel.isShowingChannelBrowser && viewModel.browser.mode == .all
            ) {
                viewModel.showChannelBrowser()
            }

            SidebarButton(
                icon: "rosette",
                title: "Ranked",
                value: nil,
                isSelected: !viewModel.isShowingGameplay && viewModel.isShowingChannelBrowser && viewModel.browser.mode == .ranked
            ) {
                viewModel.showRankedChannels()
            }

            SidebarButton(
                icon: "star.fill",
                title: "Favorites",
                value: nil,
                isSelected: !viewModel.isShowingGameplay && viewModel.isShowingChannelBrowser && viewModel.browser.mode == .favorites
            ) {
                viewModel.showFavoriteChannels()
            }

            SidebarButton(
                icon: "gamecontroller.fill",
                title: "Gameplay",
                value: gameplayValue,
                isSelected: viewModel.isShowingGameplay
            ) {
                viewModel.showGameplay()
            }
        }
    }

    private var joinedSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            HStack {
                Image(systemName: "checkmark.circle")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.neonCyan)
                    .help("Joined rooms")

                Spacer()
            }

            if viewModel.joinedChannels.isEmpty {
                Image(systemName: "rectangle.stack.badge.plus")
                    .font(.system(size: 18, weight: .black))
                    .foregroundStyle(MacadeColor.inkMuted.opacity(0.72))
                    .frame(maxWidth: .infinity, minHeight: 42)
                    .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 12))
                    .help("Join a room from Browse")
            } else {
                VStack(spacing: MacadeSpacing.xSmall) {
                    ForEach(viewModel.joinedChannels) { channel in
                        SidebarChannelButton(
                            channel: channel,
                            isSelected: !viewModel.isShowingGameplay && !viewModel.isShowingChannelBrowser && viewModel.selectedChannelID == channel.id,
                            isLeaving: viewModel.isLeavingChannel,
                            leaveAction: {
                                viewModel.leave(channel)
                            }
                        ) {
                            viewModel.openJoinedChannel(channel)
                        }
                    }
                }
            }
        }
    }

    private var statusFooter: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Image(systemName: "dot.radiowaves.left.and.right")
                .foregroundStyle(MacadeColor.neonCyan)
                .help(viewModel.statusText)

            Spacer()

            iconToggle(
                systemName: "waveform.path.ecg",
                isOn: $viewModel.isLobbyDiagnosticsEnabled,
                activeColor: MacadeColor.warning,
                help: viewModel.lobbyDiagnosticsLogPath
            )

            if viewModel.isLobbyDiagnosticsEnabled {
                iconToggle(
                    systemName: "text.bubble",
                    isOn: $viewModel.includeLobbyDiagnosticChatBodies,
                    activeColor: MacadeColor.warning,
                    help: "Log chat text"
                )
            }
        }
        .font(.system(size: 12, weight: .black))
        .padding(.horizontal, MacadeSpacing.xSmall)
        .frame(height: 34)
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 12))
    }

    private var accountFooter: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            PlayerAvatarView(
                url: currentUser?.avatarURL,
                fallbackName: viewModel.session.displayName,
                size: 24,
                borderColor: currentUser == nil ? MacadeColor.stroke : MacadeColor.warning
            )

            Text(viewModel.session.displayName)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(1)

            Spacer(minLength: 0)

            Button(action: onSignOut) {
                Image(systemName: "rectangle.portrait.and.arrow.right")
                    .font(.system(size: 12, weight: .black))
                    .frame(width: 24, height: 24)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .background(MacadeColor.panel, in: Circle())
            }
            .buttonStyle(.plain)
            .help("Sign out")
        }
        .padding(.horizontal, MacadeSpacing.xSmall)
        .frame(height: 34)
        .frame(maxWidth: .infinity, alignment: .leading)
    }

    private func iconToggle(
        systemName: String,
        isOn: Binding<Bool>,
        activeColor: Color,
        help: String
    ) -> some View {
        Button {
            isOn.wrappedValue.toggle()
        } label: {
            Image(systemName: systemName)
                .frame(width: 24, height: 24)
                .foregroundStyle(isOn.wrappedValue ? MacadeColor.midnight : MacadeColor.inkMuted)
                .background(isOn.wrappedValue ? activeColor : MacadeColor.panel, in: Circle())
        }
        .buttonStyle(.plain)
        .help(help)
    }

    private var gameplayValue: String? {
        guard let session = viewModel.activeEmulationSession else {
            return nil
        }

        return session.isActive ? "live" : "done"
    }

    private var currentUser: FightcadeChannelUser? {
        viewModel.selectedChannelUsers.first { $0.isCurrentUser(session: viewModel.session) }
    }
}

private struct SidebarButton: View {
    let icon: String
    let title: String
    let value: String?
    let isSelected: Bool
    let action: () -> Void

    var body: some View {
        Button(action: action) {
            HStack(spacing: MacadeSpacing.xSmall) {
                Image(systemName: icon)
                    .frame(width: 16)

                Text(title)
                    .font(.system(size: 13, weight: .black, design: .rounded))

                Spacer()

                if let value {
                    Text(value)
                        .font(MacadeTypography.caption)
                        .foregroundStyle(isSelected ? MacadeColor.ink : MacadeColor.inkMuted)
                }
            }
            .foregroundStyle(isSelected ? MacadeColor.ink : MacadeColor.inkMuted)
            .padding(.horizontal, MacadeSpacing.small)
            .frame(height: 34)
            .background(isSelected ? MacadeColor.rowSelected : .clear, in: RoundedRectangle(cornerRadius: 10))
            .overlay(
                RoundedRectangle(cornerRadius: 10)
                    .stroke(isSelected ? MacadeColor.warning.opacity(0.7) : .clear, lineWidth: 1)
            )
        }
        .buttonStyle(.plain)
    }
}

private struct SidebarChannelButton: View {
    let channel: FightcadeChannel
    let isSelected: Bool
    let isLeaving: Bool
    let leaveAction: () -> Void
    let action: () -> Void

    var body: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Button(action: action) {
                HStack(spacing: MacadeSpacing.xSmall) {
                    Circle()
                        .fill(isSelected ? MacadeColor.neonCyan : MacadeColor.inkMuted.opacity(0.45))
                        .frame(width: 8, height: 8)

                    Text(channel.title)
                        .font(.system(size: 13, weight: .black, design: .rounded))
                        .lineLimit(1)

                    Spacer(minLength: 0)
                }
            }
            .buttonStyle(.plain)

            Button(action: leaveAction) {
                Image(systemName: "xmark")
                    .font(.system(size: 11, weight: .black))
                    .frame(width: 22, height: 22)
                    .foregroundStyle(MacadeColor.inkMuted.opacity(0.78))
                    .background(MacadeColor.panel.opacity(0.65), in: Circle())
            }
            .buttonStyle(.plain)
            .disabled(isLeaving)
            .help("Leave \(channel.title)")
        }
        .foregroundStyle(isSelected ? MacadeColor.ink : MacadeColor.inkMuted)
        .padding(.leading, MacadeSpacing.xSmall)
        .padding(.trailing, MacadeSpacing.xSmall)
        .frame(height: 34)
        .background(isSelected ? MacadeColor.rowSelected : .clear, in: RoundedRectangle(cornerRadius: 10))
        .overlay(
            RoundedRectangle(cornerRadius: 10)
                .stroke(isSelected ? MacadeColor.neonCyan.opacity(0.7) : .clear, lineWidth: 1)
        )
    }
}
