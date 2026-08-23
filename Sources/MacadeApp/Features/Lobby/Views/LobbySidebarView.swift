import SwiftUI

struct LobbySidebarView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let onSignOut: () -> Void
    @AppStorage("lobbySidebarPinned") private var isPinned = false
    @State private var isHovering = false
    @State private var hoverTask: Task<Void, Never>?

    private var isExpanded: Bool { isPinned || isHovering }
    private var railWidth: CGFloat { isExpanded ? 220 : 56 }

    var body: some View {
        VStack(alignment: .leading, spacing: 0) {
            sidebarHeader
                .padding(.horizontal, isExpanded ? MacadeSpacing.small : 8)
                .padding(.top, MacadeSpacing.medium)

            ScrollView {
                VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                    filters
                    joinedSection
                    if isExpanded {
                        FriendsSidebarSection(viewModel: viewModel)
                    } else {
                        compactFriendsButton
                    }
                }
                .padding(.horizontal, isExpanded ? MacadeSpacing.small : 8)
                .padding(.vertical, MacadeSpacing.medium)
                .frame(maxWidth: .infinity, alignment: .leading)
            }
            .scrollIndicators(.hidden)
            .frame(maxWidth: .infinity, maxHeight: .infinity)

            VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
                statusFooter
                accountFooter
            }
            .padding(.horizontal, isExpanded ? MacadeSpacing.small : 8)
            .padding(.bottom, MacadeSpacing.medium)
        }
        .frame(width: railWidth, alignment: .leading)
        .frame(maxHeight: .infinity)
        .background { MacadeFrostedFill(opacity: 0.58) }
        .overlay(alignment: .trailing) {
            Rectangle()
                .fill(MacadeColor.stroke)
                .frame(width: 1)
        }
        .shadow(color: MacadeColor.neonCyan.opacity(isExpanded && !isPinned ? 0.16 : 0), radius: 18, x: 8)
        .animation(.smooth(duration: 0.2), value: isExpanded)
        .onHover { hovering in
            hoverTask?.cancel()
            hoverTask = Task { @MainActor in
                try? await Task.sleep(for: .milliseconds(hovering ? 140 : 120))
                guard !Task.isCancelled else { return }
                isHovering = hovering
            }
        }
        .onDisappear { hoverTask?.cancel() }
    }

    private var sidebarHeader: some View {
        Button {
            isPinned.toggle()
        } label: {
            HStack(spacing: MacadeSpacing.small) {
                Image(systemName: isPinned ? "rectangle.3.group.fill" : "rectangle.3.group")
                    .font(.system(size: 16, weight: .black))
                    .frame(width: 24, height: 24)
                    .foregroundStyle(MacadeColor.neonCyan)

                if isExpanded {
                    Text("Rooms")
                        .font(.system(size: 18, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)

                    Spacer(minLength: 0)

                    Image(systemName: isPinned ? "pin.fill" : "pin")
                        .font(.system(size: 11, weight: .black))
                        .foregroundStyle(isPinned ? MacadeColor.neonPink : MacadeColor.inkMuted)
                }
            }
            .frame(maxWidth: .infinity, alignment: .leading)
            .frame(height: 34)
        }
        .buttonStyle(.plain)
        .help(isPinned ? "Unpin rooms rail" : "Pin rooms rail")
    }

    private var filters: some View {
        VStack(spacing: MacadeSpacing.xSmall) {
            SidebarButton(
                icon: "magnifyingglass",
                title: "Browse",
                value: nil,
                isSelected: !viewModel.isShowingGameplay && viewModel.isShowingChannelBrowser && viewModel.browser.mode == .all,
                isCompact: !isExpanded
            ) {
                viewModel.showChannelBrowser()
            }

            SidebarButton(
                icon: "rosette",
                title: "Ranked",
                value: nil,
                isSelected: !viewModel.isShowingGameplay && viewModel.isShowingChannelBrowser && viewModel.browser.mode == .ranked,
                isCompact: !isExpanded
            ) {
                viewModel.showRankedChannels()
            }

            SidebarButton(
                icon: "star.fill",
                title: "Favorites",
                value: nil,
                isSelected: !viewModel.isShowingGameplay && viewModel.isShowingChannelBrowser && viewModel.browser.mode == .favorites,
                isCompact: !isExpanded
            ) {
                viewModel.showFavoriteChannels()
            }

            SidebarButton(
                icon: "gamecontroller.fill",
                title: "Gameplay",
                value: gameplayValue,
                isSelected: viewModel.isShowingGameplay,
                isCompact: !isExpanded
            ) {
                viewModel.showGameplay()
            }

            SidebarButton(
                icon: "tv.fill",
                title: "Fightcade TV",
                value: viewModel.channelTVSidebarValue,
                isSelected: viewModel.isShowingChannelTV,
                isDisabled: !viewModel.canStartFightcadeTV && !viewModel.isShowingChannelTV,
                isCompact: !isExpanded
            ) {
                viewModel.showFightcadeTV()
            }
            .help(viewModel.canStartFightcadeTV ? "Start Fightcade TV" : "Join a room before starting Fightcade TV")
        }
    }

    private var joinedSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            if isExpanded {
                HStack {
                    Image(systemName: "checkmark.circle")
                        .font(MacadeTypography.caption)
                        .foregroundStyle(MacadeColor.neonCyan)
                        .help("Joined rooms")

                    Spacer()
                }
            }

            if viewModel.joinedChannels.isEmpty {
                Image(systemName: "rectangle.stack.badge.plus")
                    .font(.system(size: isExpanded ? 18 : 14, weight: .black))
                    .foregroundStyle(MacadeColor.inkMuted.opacity(0.72))
                    .frame(maxWidth: .infinity, minHeight: isExpanded ? 42 : 34)
                    .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 12))
                    .help("Join a room from Browse")
            } else {
                VStack(spacing: MacadeSpacing.xSmall) {
                    ForEach(viewModel.joinedChannels) { channel in
                        SidebarChannelButton(
                            channel: channel,
                            isSelected: !viewModel.isShowingGameplay && !viewModel.isShowingChannelBrowser && !viewModel.isShowingChannelTV && viewModel.selectedChannelID == channel.id,
                            isLeaving: viewModel.isLeavingChannel,
                            isCompact: !isExpanded,
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

    private var compactFriendsButton: some View {
        let onlineCount = viewModel.friendRows.filter(\.isOnline).count
        return Button {
            isPinned = true
        } label: {
            ZStack(alignment: .topTrailing) {
                Image(systemName: "person.2.fill")
                    .font(.system(size: 14, weight: .black))
                    .frame(width: 40, height: 34)
                    .foregroundStyle(onlineCount > 0 ? MacadeColor.neonCyan : MacadeColor.inkMuted)
                    .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 10))

                if onlineCount > 0 {
                    Text("\(onlineCount)")
                        .font(.system(size: 8, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.midnight)
                        .padding(.horizontal, 4)
                        .frame(height: 12)
                        .background(MacadeColor.neonPink, in: Capsule())
                        .offset(x: 4, y: -4)
                }
            }
            .frame(maxWidth: .infinity)
        }
        .buttonStyle(.plain)
        .help("\(onlineCount) friends online")
    }

    private var statusFooter: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Image(systemName: "dot.radiowaves.left.and.right")
                .foregroundStyle(MacadeColor.neonCyan)
                .help(viewModel.statusText)

            if isExpanded {
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
        }
        .font(.system(size: 12, weight: .black))
        .padding(.horizontal, isExpanded ? MacadeSpacing.xSmall : 0)
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

            if isExpanded {
                Text(viewModel.session.displayName)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.ink)
                    .lineLimit(1)

                Spacer(minLength: 0)
            }

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
        .padding(.horizontal, isExpanded ? MacadeSpacing.xSmall : 0)
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
    var isDisabled = false
    var isCompact = false
    let action: () -> Void

    var body: some View {
        Button(action: action) {
            HStack(spacing: MacadeSpacing.xSmall) {
                Image(systemName: icon)
                    .frame(width: 16)

                if !isCompact {
                    Text(title)
                        .font(.system(size: 13, weight: .black, design: .rounded))

                    Spacer()

                    if let value {
                        Text(value)
                            .font(MacadeTypography.caption)
                            .foregroundStyle(isSelected ? MacadeColor.ink : MacadeColor.inkMuted)
                    }
                }
            }
            .foregroundStyle(isSelected ? MacadeColor.ink : MacadeColor.inkMuted)
            .padding(.horizontal, isCompact ? 0 : MacadeSpacing.small)
            .frame(maxWidth: .infinity, alignment: isCompact ? .center : .leading)
            .frame(height: 34)
            .background(isSelected ? MacadeColor.rowSelected : .clear, in: RoundedRectangle(cornerRadius: 10))
            .overlay(
                RoundedRectangle(cornerRadius: 10)
                    .stroke(isSelected ? MacadeColor.warning.opacity(0.7) : .clear, lineWidth: 1)
            )
        }
        .buttonStyle(.plain)
        .disabled(isDisabled)
        .help(title)
    }
}

private struct SidebarChannelButton: View {
    let channel: FightcadeChannel
    let isSelected: Bool
    let isLeaving: Bool
    var isCompact = false
    let leaveAction: () -> Void
    let action: () -> Void

    var body: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Button(action: action) {
                HStack(spacing: MacadeSpacing.xSmall) {
                    Circle()
                        .fill(isSelected ? MacadeColor.neonCyan : MacadeColor.inkMuted.opacity(0.45))
                        .frame(width: 8, height: 8)

                    if !isCompact {
                        Text(channel.title)
                            .font(.system(size: 13, weight: .black, design: .rounded))
                            .lineLimit(1)

                        Spacer(minLength: 0)
                    }
                }
                .frame(maxWidth: .infinity, alignment: isCompact ? .center : .leading)
            }
            .buttonStyle(.plain)
            .help(channel.title)

            if !isCompact {
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
        }
        .foregroundStyle(isSelected ? MacadeColor.ink : MacadeColor.inkMuted)
        .padding(.horizontal, isCompact ? 0 : MacadeSpacing.xSmall)
        .frame(height: 34)
        .background(isSelected ? MacadeColor.rowSelected : .clear, in: RoundedRectangle(cornerRadius: 10))
        .overlay(
            RoundedRectangle(cornerRadius: 10)
                .stroke(isSelected ? MacadeColor.neonCyan.opacity(0.7) : .clear, lineWidth: 1)
        )
    }
}
