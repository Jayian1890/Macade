import SwiftUI
import AppKit

struct ChannelCard: View {
    let channel: FightcadeChannel
    let isSelected: Bool
    let isJoined: Bool
    let previewAction: () -> Void
    let openAction: () -> Void
    let favoriteAction: () -> Void
    let joinAction: () -> Void

    @State private var isHovering = false

    var body: some View {
        ZStack(alignment: .bottom) {
            preview.frame(maxWidth: .infinity, maxHeight: .infinity).clipped()
            LinearGradient(colors: [.clear, .black.opacity(0.28), .black.opacity(0.9)], startPoint: .top, endPoint: .bottom)
            content
            statsOverlay
            actionsOverlay
        }
        .frame(height: 118)
        .clipShape(RoundedRectangle(cornerRadius: 8))
        .overlay(RoundedRectangle(cornerRadius: 8).stroke(isSelected ? MacadeColor.neonCyan : MacadeColor.stroke, lineWidth: 1))
        .shadow(color: .black.opacity(0.28), radius: 8, x: 0, y: 5)
        .contentShape(RoundedRectangle(cornerRadius: 8))
        .onTapGesture(count: 2, perform: openAction)
        .onTapGesture(count: 1, perform: previewAction)
        .onHover { isHovering = $0 }
    }

    private var content: some View {
        VStack(alignment: .leading, spacing: 3) {
            Spacer(minLength: 0)

            Text(channel.title)
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(1)

            Text(channel.subtitle.uppercased())
                .font(.system(size: 10, weight: .bold, design: .rounded))
                .foregroundStyle(MacadeColor.inkMuted)
                .lineLimit(1)
        }
        .padding(8)
        .frame(maxWidth: .infinity, alignment: .leading)
    }

    private var statsOverlay: some View {
        HStack(spacing: 6) {
            Image(systemName: "person.fill")
            Text(channel.playerCountText)

            if let spectators = channel.spectatorCount, spectators > 0 {
                Image(systemName: "eye.fill")
                Text("\(spectators)")
            }

            if channel.isRanked {
                Text("R")
                    .font(.system(size: 10, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.warning)
            }
        }
        .font(.system(size: 10, weight: .black, design: .rounded))
        .foregroundStyle(MacadeColor.ink)
        .padding(.horizontal, 7)
        .frame(height: 22)
        .background(.black.opacity(0.68), in: Capsule())
        .overlay(Capsule().stroke(.white.opacity(0.22), lineWidth: 1))
        .padding(6)
        .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .topTrailing)
    }

    @ViewBuilder
    private var actionsOverlay: some View {
        if isHovering || isSelected {
            HStack(spacing: 6) {
                Button(isJoined ? "OPEN" : "JOIN", action: joinAction)
                    .buttonStyle(.borderedProminent)
                    .controlSize(.mini)

                Button(action: favoriteAction) {
                    Image(systemName: channel.isFavorite ? "star.fill" : "star")
                        .frame(width: 22, height: 22)
                }
                .buttonStyle(.plain)
                .foregroundStyle(channel.isFavorite ? MacadeColor.warning : MacadeColor.ink)
                .background(.black.opacity(0.68), in: Circle())
            }
            .padding(6)
            .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .topLeading)
            .transition(.opacity)
        }
    }

    private var preview: some View {
        FightcadeArtworkImage(url: channel.previewURL) {
            fallbackPreview
        }
    }

    private var fallbackPreview: some View {
        ZStack {
            LinearGradient(colors: [MacadeColor.arcadeBlue, MacadeColor.deepPlum], startPoint: .topLeading, endPoint: .bottomTrailing)
            Text(channel.name.prefix(3).uppercased())
                .font(.system(size: 28, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.ink.opacity(0.65))
        }
    }
}

struct FightcadeArtworkImage<Placeholder: View>: View {
    let url: URL?
    let placeholder: () -> Placeholder

    @State private var image: Image?
    @State private var failedURL: URL?

    init(url: URL?, @ViewBuilder placeholder: @escaping () -> Placeholder) {
        self.url = url
        self.placeholder = placeholder
    }

    var body: some View {
        Group {
            if let image {
                image
                    .resizable()
                    .scaledToFill()
            } else {
                placeholder()
            }
        }
        .task(id: url) {
            await loadImage()
        }
    }

    private func loadImage() async {
        guard let url, failedURL != url else {
            return
        }

        await MainActor.run {
            image = nil
        }

        do {
            var request = URLRequest(url: url, cachePolicy: .returnCacheDataElseLoad, timeoutInterval: 15)
            request.setValue(FightcadeEndpoint.userAgent, forHTTPHeaderField: "User-Agent")
            let (data, response) = try await URLSession.shared.data(for: request)

            guard let httpResponse = response as? HTTPURLResponse,
                  (200..<300).contains(httpResponse.statusCode),
                  let nsImage = NSImage(data: data) else {
                throw URLError(.badServerResponse)
            }

            await MainActor.run {
                image = Image(nsImage: nsImage)
                failedURL = nil
            }
        } catch {
            await MainActor.run {
                image = nil
                failedURL = url
            }
        }
    }
}

struct FightcadeEventCard: View {
    let event: FightcadeEvent

    var body: some View {
        ZStack(alignment: .bottomLeading) {
            FightcadeArtworkImage(url: event.previewURL) { fallbackPreview }
            LinearGradient(colors: [.black.opacity(0.12), .black.opacity(0.88)], startPoint: .top, endPoint: .bottom)
            content
            dateBadge
        }
        .frame(height: 118)
        .clipShape(RoundedRectangle(cornerRadius: 8))
        .overlay(RoundedRectangle(cornerRadius: 8).stroke(MacadeColor.stroke, lineWidth: 1))
        .contentShape(RoundedRectangle(cornerRadius: 8))
        .onTapGesture {
            if let link = event.link ?? event.stream {
                NSWorkspace.shared.open(link)
            }
        }
    }

    private var content: some View {
        VStack(alignment: .leading, spacing: 3) {
            Spacer(minLength: 0)
            Text(event.name)
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(2)

            Text([event.gameID, event.region].compactMap { $0 }.filter { !$0.isEmpty }.joined(separator: " · ").uppercased())
                .font(.system(size: 10, weight: .bold, design: .rounded))
                .foregroundStyle(MacadeColor.inkMuted)
                .lineLimit(1)
        }
        .padding(8)
        .frame(maxWidth: .infinity, alignment: .leading)
    }

    private var dateBadge: some View {
        Text(event.date, format: .dateTime.month(.abbreviated).day().hour().minute())
            .font(.system(size: 10, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.ink)
            .padding(.horizontal, 7)
            .frame(height: 22)
            .background(.black.opacity(0.68), in: Capsule())
            .overlay(Capsule().stroke(.white.opacity(0.22), lineWidth: 1))
            .padding(6)
            .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .topTrailing)
    }

    private var fallbackPreview: some View {
        ZStack {
            LinearGradient(colors: [MacadeColor.arcadeBlue, MacadeColor.deepPlum], startPoint: .topLeading, endPoint: .bottomTrailing)
            Text(event.gameID.prefix(3).uppercased())
                .font(.system(size: 28, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.ink.opacity(0.65))
        }
    }
}

struct ChannelListRow: View {
    let channel: FightcadeChannel
    let isSelected: Bool
    let isJoined: Bool
    let previewAction: () -> Void
    let openAction: () -> Void
    let favoriteAction: () -> Void
    let joinAction: () -> Void

    var body: some View {
        HStack(spacing: MacadeSpacing.medium) {
            Button(action: favoriteAction) {
                Image(systemName: channel.isFavorite ? "star.fill" : "star").frame(width: 24)
            }
            .buttonStyle(.plain)
            .foregroundStyle(channel.isFavorite ? MacadeColor.warning : MacadeColor.inkMuted)

            VStack(alignment: .leading, spacing: 2) {
                Text(channel.title).font(.system(size: 14, weight: .black, design: .rounded)).lineLimit(1)
                Text([channel.name, channel.subtitle].filter { !$0.isEmpty }.joined(separator: " · "))
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .lineLimit(1)
            }

            Spacer()
            Text(channel.playerCountText).frame(width: 36, alignment: .trailing)
            Text(channel.isRanked ? "R" : "-").frame(width: 24)
            Button(isJoined ? "OPEN" : "JOIN", action: joinAction).buttonStyle(.bordered).controlSize(.small)
        }
        .font(MacadeTypography.caption)
        .foregroundStyle(MacadeColor.ink)
        .padding(.horizontal, MacadeSpacing.medium)
        .frame(height: 48)
        .background(isSelected ? MacadeColor.rowSelected : MacadeColor.panel.opacity(0.62))
        .contentShape(Rectangle())
        .onTapGesture(count: 2, perform: openAction)
        .onTapGesture(count: 1, perform: previewAction)
    }
}
