import SwiftUI

struct ChannelInfoPane: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        ScrollView {
            VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                banner

                metadata

                if let motd {
                    FightcadeMotdMessageRow(message: motd, showsEvents: false)
                } else {
                    Text("No channel info yet.")
                        .font(MacadeTypography.body)
                        .foregroundStyle(MacadeColor.inkMuted)
                        .padding(MacadeSpacing.medium)
                        .frame(maxWidth: .infinity, alignment: .leading)
                        .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 14))
                }
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

    @ViewBuilder
    private var banner: some View {
        if let previewURL = channel.previewURL {
            AsyncImage(url: previewURL) { image in
                image
                    .resizable()
                    .scaledToFill()
            } placeholder: {
                Rectangle().fill(MacadeColor.panel)
            }
            .frame(height: 220)
            .clipShape(RoundedRectangle(cornerRadius: 18, style: .continuous))
            .overlay(alignment: .bottomLeading) {
                VStack(alignment: .leading, spacing: 4) {
                    Text(channel.title)
                        .font(.system(size: 22, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)
                    Text(channel.subtitle.uppercased())
                        .font(MacadeTypography.caption)
                        .foregroundStyle(MacadeColor.inkMuted)
                }
                .padding(14)
                .frame(maxWidth: .infinity, alignment: .leading)
                .background(MacadeColor.midnight.opacity(0.62))
            }
        }
    }

    private var metadata: some View {
        HStack(spacing: MacadeSpacing.small) {
            infoChip(channel.system ?? "Unknown", icon: "cpu")
            infoChip(channel.emulator ?? "Emulator", icon: "arcade.stick")
            infoChip("\(channel.playerCountText) playing", icon: "person.2.fill")
            if let spectators = channel.spectatorCount {
                infoChip("\(spectators) watching", icon: "eye.fill")
            }
            if channel.isRanked {
                infoChip("Ranked", icon: "rosette")
            }
        }
    }

    private func infoChip(_ text: String, icon: String) -> some View {
        Label(text, systemImage: icon)
            .font(.system(size: 11, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.inkMuted)
            .padding(.horizontal, 10)
            .frame(height: 28)
            .background(MacadeColor.panel.opacity(0.72), in: Capsule())
    }
}

@MainActor
enum ChannelLobbyContent {
    static func motdMessage(from viewModel: AuthenticatedHomeViewModel, channel: FightcadeChannel) -> FightcadeChatMessage? {
        (viewModel.chatMessagesByChannel[channel.name] ?? []).first { $0.kind == .motd }
    }
}
