import SwiftUI

struct PlayerAvatarView: View {
    let url: URL?
    let fallbackName: String
    let size: CGFloat
    var borderColor: Color = MacadeColor.stroke

    init(
        user: FightcadeChannelUser,
        size: CGFloat,
        borderColor: Color = MacadeColor.stroke
    ) {
        self.url = user.avatarURL
        self.fallbackName = user.name
        self.size = size
        self.borderColor = borderColor
    }

    init(
        url: URL?,
        fallbackName: String,
        size: CGFloat,
        borderColor: Color = MacadeColor.stroke
    ) {
        self.url = url
        self.fallbackName = fallbackName
        self.size = size
        self.borderColor = borderColor
    }

    var body: some View {
        ZStack {
            fallback

            if let url {
                AsyncImage(url: url, transaction: Transaction(animation: .smooth(duration: 0.18))) { phase in
                    switch phase {
                    case .success(let image):
                        image
                            .resizable()
                            .scaledToFill()
                    case .empty:
                        ProgressView()
                            .controlSize(.small)
                            .tint(MacadeColor.inkMuted)
                    case .failure:
                        fallback
                    @unknown default:
                        fallback
                    }
                }
            }
        }
        .frame(width: size, height: size)
        .clipShape(Circle())
        .overlay(Circle().stroke(borderColor.opacity(0.72), lineWidth: 1))
        .background(Circle().fill(MacadeColor.panel.opacity(0.65)))
        .accessibilityLabel("Avatar for \(fallbackName)")
    }

    private var fallback: some View {
        ZStack {
            LinearGradient(
                colors: [MacadeColor.neonCyan.opacity(0.28), MacadeColor.neonPink.opacity(0.24)],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )

            Text(initials)
                .font(.system(size: max(9, size * 0.34), weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
        }
    }

    private var initials: String {
        let parts = fallbackName
            .split { !$0.isLetter && !$0.isNumber }
            .prefix(2)
            .compactMap(\.first)

        let value = String(parts).uppercased()
        return value.isEmpty ? "?" : value
    }
}

struct PlayerDetailPane: View {
    let channel: FightcadeChannel
    let user: FightcadeChannelUser
    @Bindable var viewModel: AuthenticatedHomeViewModel
    let isChallengeable: Bool
    let isChallenging: Bool
    let isCurrentUser: Bool
    @Binding var isMinimized: Bool

    var body: some View {
        VStack(alignment: .leading, spacing: 6) {
            header

            if !isMinimized {
                LazyVGrid(columns: detailColumns, alignment: .leading, spacing: 6) {
                    ForEach(detailItems) { item in
                        detailChip(item)
                    }
                }

                PlayerRecentMatchesView(channel: channel, user: user, viewModel: viewModel)
            }
        }
        .padding(MacadeSpacing.small)
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(MacadeColor.panel.opacity(0.96), in: RoundedRectangle(cornerRadius: 14))
        .overlay(
            RoundedRectangle(cornerRadius: 14)
                .stroke(MacadeColor.neonCyan.opacity(0.34), lineWidth: 1)
        )
    }

    private var detailColumns: [GridItem] {
        [
            GridItem(.flexible(minimum: 82), spacing: 6),
            GridItem(.flexible(minimum: 82), spacing: 6)
        ]
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.small) {
            PlayerAvatarView(user: user, size: 42, borderColor: headerAccent)

            VStack(alignment: .leading, spacing: 6) {
                HStack(spacing: MacadeSpacing.xSmall) {
                    Text(user.name)
                        .font(.system(size: 15, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)
                        .lineLimit(1)

                    if isCurrentUser {
                        Text("YOU")
                            .font(.system(size: 9, weight: .black, design: .rounded))
                            .foregroundStyle(MacadeColor.midnight)
                            .padding(.horizontal, 5)
                            .padding(.vertical, 2)
                            .background(MacadeColor.warning, in: Capsule())
                    }
                }

                Text(statusText)
                    .font(.system(size: 11, weight: .bold, design: .rounded))
                    .foregroundStyle(user.statusAccent)
                    .lineLimit(1)
            }

            Spacer()

            Button {
                isMinimized.toggle()
            } label: {
                Image(systemName: isMinimized ? "chevron.up" : "chevron.down")
                    .frame(width: 20, height: 20)
            }
            .buttonStyle(.plain)
            .font(.system(size: 10, weight: .black))
            .foregroundStyle(MacadeColor.inkMuted)
            .help(isMinimized ? "Show" : "Hide")
        }
    }

    private func detailChip(_ item: DetailItem) -> some View {
        HStack(alignment: .center, spacing: MacadeSpacing.xSmall) {
            Image(systemName: item.icon)
                .font(.system(size: 10, weight: .black))
                .frame(width: 13)
                .help(item.help)

            VStack(alignment: .leading, spacing: 1) {
                Text(item.label.uppercased())
                    .font(.system(size: 9, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.inkMuted.opacity(0.66))

                Text(item.value)
                    .font(.system(size: 11, weight: .semibold, design: .rounded))
                    .foregroundStyle(item.accent)
                    .lineLimit(1)
                    .minimumScaleFactor(0.88)
            }
            .frame(maxWidth: .infinity, alignment: .leading)
        }
        .padding(.horizontal, 8)
        .frame(maxWidth: .infinity, minHeight: 38, alignment: .leading)
        .background(MacadeColor.midnight.opacity(0.34), in: RoundedRectangle(cornerRadius: 10))
        .overlay(RoundedRectangle(cornerRadius: 10).stroke(MacadeColor.stroke.opacity(0.52), lineWidth: 1))
        .foregroundStyle(item.accent)
        .help(item.value)
    }

    private var detailItems: [DetailItem] {
        [
            DetailItem(icon: user.statusSymbolName, label: "Status", value: statusText, help: "Status", accent: user.statusAccent),
            DetailItem(icon: "rosette", label: "Rank", value: user.displayRank ?? "Unranked", help: "Rank", accent: user.rankAccent),
            DetailItem(icon: user.connectionSymbolName, label: "Connection", value: connectionText, help: "Connection", accent: user.connectionAccent),
            DetailItem(icon: challengeIcon, label: "Challenge", value: challengeText, help: "Challenge", accent: challengeAccent)
        ]
    }

    private var headerAccent: Color {
        if isCurrentUser {
            return MacadeColor.warning
        }

        if isChallengeable || isChallenging {
            return MacadeColor.neonCyan
        }

        return user.statusAccent
    }

    private var statusText: String {
        "\(user.countryFlag) \(user.listStatusText.capitalized)"
    }

    private var connectionText: String {
        if let ping = user.ping {
            return "\(user.connectionDetail) · \(ping)ms"
        }

        return user.connectionDetail
    }

    private var challengeText: String {
        if isCurrentUser {
            return "You"
        }

        if isChallenging {
            return "Sent"
        }

        if isChallengeable {
            return "Available"
        }

        return "Unavailable"
    }

    private var challengeIcon: String {
        if isChallenging {
            return "paperplane.fill"
        }

        if isChallengeable {
            return "bolt.horizontal.fill"
        }

        return isCurrentUser ? "person.crop.circle.fill" : "slash.circle"
    }

    private var challengeAccent: Color {
        if isCurrentUser {
            return MacadeColor.warning
        }

        if isChallenging || isChallengeable {
            return MacadeColor.neonCyan
        }

        return MacadeColor.inkMuted
    }

    private struct DetailItem: Identifiable {
        var id: String { "\(icon):\(label):\(value):\(help)" }

        let icon: String
        let label: String
        let value: String
        let help: String
        var accent: Color = MacadeColor.inkMuted
    }
}
