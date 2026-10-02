import SwiftUI

struct ChannelHeader: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var isShowingAutoMatchSettings = false

    var body: some View {
        HStack(spacing: MacadeSpacing.medium) {
            Button {
                viewModel.showChannelBrowser()
            } label: {
                Image(systemName: "chevron.left")
                    .font(.system(size: 15, weight: .black))
                    .frame(width: 30, height: 30)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .background(MacadeColor.panel.opacity(0.72), in: Circle())
            }
            .buttonStyle(.plain)
            .help("Browse rooms")

            HStack(spacing: MacadeSpacing.small) {
                Text(channel.title)
                    .font(MacadeTypography.roomTitle)
                    .foregroundStyle(MacadeColor.ink)
                    .lineLimit(1)
                    .truncationMode(.tail)
                    .help(channel.title)

                if channel.isRanked {
                    Image(systemName: "rosette")
                        .font(.system(size: 12, weight: .black))
                        .foregroundStyle(MacadeColor.neonCyan)
                        .help("Ranked")
                }
            }

            Spacer(minLength: MacadeSpacing.small)

            singlePlayerButton
            autoMatchButton
            autoMatchOutcomePill
            autoMatchSettingsButton

            if viewModel.isJoining || viewModel.isLaunchingGame || viewModel.isDownloadingROM || viewModel.isDeletingROM {
                ProgressView()
                    .controlSize(.small)
            }

        }
        .padding(.horizontal, MacadeSpacing.medium)
        .frame(height: MacadeLayout.toolbarHeight)
        .background(MacadeColor.sidebar.opacity(0.46))
        .overlay(alignment: .bottom) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }

    private var singlePlayerButton: some View {
        let unavailable = viewModel.singlePlayerUnavailableReason(for: channel)
        return Button {
            viewModel.launchSinglePlayer(in: channel)
        } label: {
            Label("Single Player", systemImage: "person.fill")
                .fixedSize()
        }
        .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
        .disabled(unavailable != nil)
        .help(unavailable ?? "Play this game locally")
    }

    private var autoMatchButton: some View {
        Button {
            viewModel.toggleAutoMatch(for: channel)
        } label: {
            Label("Auto", systemImage: viewModel.isAutoMatching(in: channel) ? "bolt.fill" : "bolt")
        }
        .buttonStyle(ChannelHeaderButtonStyle(isProminent: viewModel.isAutoMatching(in: channel)))
        .disabled(!viewModel.canToggleAutoMatch(for: channel))
        .help(viewModel.autoMatchHelpText(for: channel))
    }

    @ViewBuilder
    private var autoMatchOutcomePill: some View {
        if let text = viewModel.autoMatchOutcomeText(for: channel) {
            Text(text)
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
                .padding(.horizontal, MacadeSpacing.small)
                .frame(height: 28)
                .background(MacadeColor.panel, in: Capsule())
                .overlay(Capsule().stroke(MacadeColor.stroke, lineWidth: 1))
                .help("Invited · Accepted · Rejected · Failed")
        }
    }

    private var autoMatchSettingsButton: some View {
        Button {
            isShowingAutoMatchSettings = true
        } label: {
            Image(systemName: "slider.horizontal.3")
                .font(.system(size: 13, weight: .black))
                .frame(width: 24, height: 24)
        }
        .buttonStyle(ChannelHeaderButtonStyle())
        .disabled(!viewModel.canToggleAutoMatch(for: channel))
        .help("Auto match settings")
        .popover(isPresented: $isShowingAutoMatchSettings, arrowEdge: .bottom) {
            AutoMatchSettingsView(channel: channel, viewModel: viewModel)
        }
    }
}

struct ChannelHeaderButtonStyle: ButtonStyle {
    var isProminent = false

    func makeBody(configuration: Configuration) -> some View {
        configuration.label
            .font(MacadeTypography.control)
            .foregroundStyle(isProminent ? MacadeColor.midnight : (configuration.isPressed ? MacadeColor.ink : MacadeColor.inkMuted))
            .padding(.horizontal, MacadeSpacing.small)
            .frame(height: MacadeLayout.controlHeight)
            .background(buttonBackground(isPressed: configuration.isPressed), in: RoundedRectangle(cornerRadius: MacadeLayout.controlRadius))
            .overlay(
                RoundedRectangle(cornerRadius: MacadeLayout.controlRadius)
                    .stroke(isProminent ? .clear : MacadeColor.stroke, lineWidth: 1)
            )
    }

    private func buttonBackground(isPressed: Bool) -> Color {
        if isProminent {
            return MacadeColor.warning.opacity(isPressed ? 0.72 : 0.95)
        }

        return MacadeColor.panel
    }
}
