import SwiftUI

struct ChannelResourcesPane: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        ScrollView {
            VStack(alignment: .leading, spacing: MacadeSpacing.large) {
                romSection
                toolsSection
                eventsSection
            }
            .padding(MacadeSpacing.large)
            .frame(maxWidth: .infinity, alignment: .leading)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background { MacadeFrostedFill(opacity: 0.42) }
    }

    private var motd: FightcadeChatMessage? {
        ChannelLobbyContent.motdMessage(from: viewModel, channel: channel)
    }

    private var romSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            sectionTitle("ROM", icon: "opticaldisc")

            if viewModel.selectedHasLocalROM {
                Text("This game is ready to launch locally.")
                    .font(MacadeTypography.body)
                    .foregroundStyle(MacadeColor.inkMuted)

                if let unavailable = viewModel.selectedLocalLaunchUnavailableText {
                    Text(unavailable)
                        .font(MacadeTypography.caption)
                        .foregroundStyle(MacadeColor.warning)
                }
            } else {
                Text("Download the ROM to challenge, train, and test launch from Macade.")
                    .font(MacadeTypography.body)
                    .foregroundStyle(MacadeColor.inkMuted)

                Button(action: viewModel.downloadSelectedROM) {
                    Label("Download ROM", systemImage: "arrow.down.circle")
                }
                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
                .disabled(viewModel.isLaunchingGame || viewModel.isDownloadingROM)
            }
        }
        .padding(MacadeSpacing.medium)
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(MacadeColor.panel.opacity(0.48), in: RoundedRectangle(cornerRadius: 16))
    }

    private var toolsSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            sectionTitle("Tools", icon: "wrench.and.screwdriver")

            HStack(spacing: MacadeSpacing.small) {
                if viewModel.selectedHasLocalROM {
                    Button("Check ROM", systemImage: "externaldrive", action: viewModel.checkROM)
                        .buttonStyle(ChannelHeaderButtonStyle())
                        .disabled(viewModel.isLaunchingGame || viewModel.isDownloadingROM || viewModel.isDeletingROM)

                    if viewModel.canLaunchSelectedGameLocally {
                        Button("Test Launch", systemImage: "wrench.and.screwdriver", action: viewModel.launchTestGame)
                            .buttonStyle(ChannelHeaderButtonStyle())
                            .disabled(viewModel.isLaunchingGame || viewModel.isDownloadingROM)

                        if channel.supportsTraining {
                            Button("Training", systemImage: "figure.run", action: viewModel.launchTraining)
                                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
                                .disabled(viewModel.isLaunchingGame)
                        }
                    }

                    Button("FBNeo Settings", systemImage: "slider.horizontal.3", action: viewModel.showFBNeoSettings)
                        .buttonStyle(ChannelHeaderButtonStyle())

                    Button("Delete ROM", systemImage: "trash", role: .destructive, action: viewModel.deleteSelectedROM)
                        .buttonStyle(ChannelHeaderButtonStyle())
                        .disabled(viewModel.isDeletingROM)
                } else {
                    Text("ROM tools unlock after the game is downloaded.")
                        .font(MacadeTypography.caption)
                        .foregroundStyle(MacadeColor.inkMuted)
                }
            }

            if viewModel.isJoining || viewModel.isLaunchingGame || viewModel.isDownloadingROM || viewModel.isDeletingROM {
                ProgressView()
                    .controlSize(.small)
            }
        }
        .padding(MacadeSpacing.medium)
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(MacadeColor.panel.opacity(0.48), in: RoundedRectangle(cornerRadius: 16))
    }

    @ViewBuilder
    private var eventsSection: some View {
        if let motd, !motd.events.isEmpty {
            VStack(alignment: .leading, spacing: MacadeSpacing.small) {
                sectionTitle("Events", icon: "calendar")

                LazyVGrid(columns: [GridItem(.adaptive(minimum: 204), spacing: 12)], alignment: .leading, spacing: 12) {
                    ForEach(motd.events) { event in
                        FightcadeMotdEventCard(event: event)
                    }
                }
            }
        }
    }

    private func sectionTitle(_ title: String, icon: String) -> some View {
        Label(title, systemImage: icon)
            .font(.system(size: 13, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.neonCyan)
    }
}
