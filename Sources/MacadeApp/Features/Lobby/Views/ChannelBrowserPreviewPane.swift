import SwiftUI

struct ChannelPreviewPane: View {
    let channel: FightcadeChannel
    let isJoined: Bool
    let favoriteAction: () -> Void
    let joinAction: () -> Void

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            AsyncImage(url: channel.previewURL) { phase in
                switch phase {
                case .success(let image):
                    image.resizable().scaledToFill()
                default:
                    Rectangle().fill(MacadeColor.panelStrong)
                }
            }
            .frame(height: 160)
            .clipShape(RoundedRectangle(cornerRadius: 14))

            Text(channel.title)
                .font(.system(size: 22, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(3)

            metadataRows

            HStack {
                Button(isJoined ? "Open Room" : "Join Room", action: joinAction)
                    .buttonStyle(.borderedProminent)

                Button(action: favoriteAction) {
                    Label(channel.isFavorite ? "Favorited" : "Favorite", systemImage: channel.isFavorite ? "star.fill" : "star")
                }
                .buttonStyle(.bordered)
            }

            Spacer()
        }
        .padding(MacadeSpacing.large)
        .background(MacadeColor.sidebar.opacity(0.64))
        .overlay(alignment: .leading) {
            Rectangle().fill(MacadeColor.stroke).frame(width: 1)
        }
    }

    private var metadataRows: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            PreviewMetadata(label: "ROM", value: channel.gameID ?? channel.name)
            PreviewMetadata(label: "System", value: channel.system ?? "Unknown")
            PreviewMetadata(label: "Emulator", value: channel.emulator ?? "Unknown")
            PreviewMetadata(label: "Players", value: channel.playerCountText)
            PreviewMetadata(label: "Spectators", value: channel.spectatorCount.map(String.init) ?? "0")
            PreviewMetadata(label: "Ranked", value: channel.isRanked ? "Yes" : "No")
        }
    }
}

private struct PreviewMetadata: View {
    let label: String
    let value: String

    var body: some View {
        HStack {
            Text(label.uppercased())
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
            Spacer()
            Text(value)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(1)
        }
    }
}
