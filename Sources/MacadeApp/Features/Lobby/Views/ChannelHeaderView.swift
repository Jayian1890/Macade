import SwiftUI

struct ChannelHeader: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel

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
                    .font(.system(size: 21, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.ink)
                    .lineLimit(1)

                Button {
                    viewModel.showChannelTV(for: channel)
                } label: {
                    Label("TV", systemImage: "tv.fill")
                }
                .buttonStyle(ChannelHeaderButtonStyle())
                .disabled(!viewModel.canStartChannelTV(in: channel) || viewModel.isLaunchingGame)
                .help("Start channel TV")

                if channel.isRanked {
                    Image(systemName: "rosette")
                        .font(.system(size: 12, weight: .black))
                        .foregroundStyle(MacadeColor.neonCyan)
                        .help("Ranked")
                }
            }

            Spacer()

            if !viewModel.selectedHasLocalROM {
                Button(action: viewModel.downloadSelectedROM) {
                    Label("ROM", systemImage: "arrow.down.circle")
                }
                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
                .disabled(viewModel.isLaunchingGame || viewModel.isDownloadingROM)
                .help("Download ROM")
            }

            if viewModel.selectedHasLocalROM {
                romTools
            }

            if let unavailable = viewModel.selectedLocalLaunchUnavailableText,
               viewModel.selectedHasLocalROM {
                Text(unavailable)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .lineLimit(1)
                    .frame(maxWidth: 180, alignment: .leading)
            }

            if viewModel.isJoining || viewModel.isLaunchingGame || viewModel.isDownloadingROM || viewModel.isDeletingROM {
                ProgressView()
                    .controlSize(.small)
            }
        }
        .padding(.horizontal, MacadeSpacing.medium)
        .frame(height: 48)
        .background(MacadeColor.sidebar.opacity(0.46))
        .overlay(alignment: .bottom) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }

    private var romTools: some View {
        Menu {
            Button("Check ROM", systemImage: "externaldrive", action: viewModel.checkROM)

            if viewModel.canLaunchSelectedGameLocally {
                Button("Test Launch", systemImage: "wrench.and.screwdriver", action: viewModel.launchTestGame)

                if channel.supportsTraining {
                    Button("Training", systemImage: "figure.run", action: viewModel.launchTraining)
                }
            }

            Button("FBNeo Settings", systemImage: "slider.horizontal.3", action: viewModel.showFBNeoSettings)

            Divider()

            Button("Delete ROM", systemImage: "trash", role: .destructive, action: viewModel.deleteSelectedROM)
                .disabled(viewModel.isDeletingROM)
        } label: {
            Image(systemName: "wrench.and.screwdriver")
                .font(.system(size: 13, weight: .black))
                .frame(width: 24, height: 24)
            .foregroundStyle(MacadeColor.ink)
            .padding(.horizontal, MacadeSpacing.medium)
            .frame(height: 36)
            .background(MacadeColor.panelStrong, in: RoundedRectangle(cornerRadius: 12))
            .overlay(
                RoundedRectangle(cornerRadius: 12)
                    .stroke(MacadeColor.neonCyan.opacity(0.55), lineWidth: 1)
            )
        }
        .buttonStyle(.plain)
        .disabled(viewModel.isLaunchingGame || viewModel.isDownloadingROM || viewModel.isDeletingROM)
        .help("Tools")
    }

}

struct ChannelHeaderButtonStyle: ButtonStyle {
    var isProminent = false

    func makeBody(configuration: Configuration) -> some View {
        configuration.label
            .font(.system(size: 13, weight: .black, design: .rounded))
            .foregroundStyle(isProminent ? MacadeColor.midnight : (configuration.isPressed ? MacadeColor.ink : MacadeColor.inkMuted))
            .padding(.horizontal, MacadeSpacing.medium)
            .frame(height: 36)
            .background(buttonBackground(isPressed: configuration.isPressed), in: RoundedRectangle(cornerRadius: 12))
            .overlay(
                RoundedRectangle(cornerRadius: 12)
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
