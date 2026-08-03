import SwiftUI

struct PlayerRecentMatchesView: View {
    let channel: FightcadeChannel
    let user: FightcadeChannelUser
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        VStack(alignment: .leading, spacing: 4) {
            header
            content
        }
        .padding(.top, 4)
        .task(id: taskID) {
            await viewModel.loadRecentMatchesIfNeeded(for: user, in: channel)
        }
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Image(systemName: "clock.arrow.circlepath")
                .font(.system(size: 10, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)

            Text("RECENT MATCHES")
                .font(.system(size: 9, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.inkMuted.opacity(0.72))

            Spacer()

            Button {
                Task { await viewModel.reloadRecentMatches(for: user, in: channel) }
            } label: {
                Image(systemName: "arrow.clockwise")
                    .font(.system(size: 9, weight: .black))
            }
            .buttonStyle(.plain)
            .foregroundStyle(MacadeColor.inkMuted)
            .help("Refresh recent matches")
        }
    }

    @ViewBuilder
    private var content: some View {
        switch viewModel.recentMatchState(for: user, in: channel) {
        case .idle, .loading:
            loadingRow
        case .loaded(let matches):
            if matches.isEmpty {
                Text("No recent matches in this channel.")
                    .font(.system(size: 11, weight: .semibold, design: .rounded))
                    .foregroundStyle(MacadeColor.inkMuted)
            } else {
                ForEach(Array(matches.prefix(3))) { match in
                    PlayerRecentMatchRow(
                        match: match,
                        username: user.name,
                        canOpenReplay: viewModel.canOpenRecentMatchReplay(match)
                    ) {
                        viewModel.openRecentMatchReplay(match, in: channel)
                    }
                }
            }
        case .failed(let message):
            Text(message)
                .font(.system(size: 11, weight: .semibold, design: .rounded))
                .foregroundStyle(MacadeColor.warning)
        }
    }

    private var loadingRow: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            ProgressView()
                .controlSize(.small)
                .tint(MacadeColor.neonCyan)

            Text("Loading current-channel history...")
                .font(.system(size: 11, weight: .semibold, design: .rounded))
                .foregroundStyle(MacadeColor.inkMuted)
        }
    }

    private var taskID: String {
        "\(user.name.lowercased())|\(channel.launchGameID ?? channel.id)"
    }
}

private struct PlayerRecentMatchRow: View {
    let match: FightcadeRecentMatch
    let username: String
    let canOpenReplay: Bool
    let openReplay: () -> Void

    var body: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Text(rowText)
                .font(.system(size: 10, weight: .bold, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(1)
                .truncationMode(.tail)

            Spacer(minLength: MacadeSpacing.xSmall)

            replayControl
        }
        .padding(.horizontal, 8)
        .padding(.vertical, 4)
        .background(MacadeColor.midnight.opacity(0.38), in: RoundedRectangle(cornerRadius: 10))
        .overlay(RoundedRectangle(cornerRadius: 10).stroke(MacadeColor.stroke.opacity(0.55), lineWidth: 1))
    }

    @ViewBuilder
    private var replayControl: some View {
        if canOpenReplay {
            Button(action: openReplay) {
                HStack(spacing: 4) {
                    Image(systemName: "play.fill")
                    Text("Replay")
                }
                .font(.system(size: 9, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.midnight)
                .padding(.horizontal, 7)
                .frame(height: 20)
                .background(MacadeColor.warning, in: Capsule())
            }
            .buttonStyle(.plain)
            .help("Open Fightcade replay")
        } else {
            Text(match.hasReplay ? "Unsupported" : "No replay")
                .font(.system(size: 9, weight: .black, design: .rounded))
                .foregroundStyle(match.hasReplay ? MacadeColor.warning : MacadeColor.inkMuted.opacity(0.72))
                .padding(.horizontal, 7)
                .frame(height: 20)
                .background(MacadeColor.panel.opacity(0.72), in: Capsule())
        }
    }

    private var title: String {
        guard let opponent = match.opponentName(for: username) else {
            return match.channelName.nonEmpty ?? match.gameID
        }

        if let score = match.scoreText(for: username) {
            return "vs \(opponent) · \(score)"
        }

        return "vs \(opponent)"
    }

    private var rowText: String {
        [title, formatText, durationText]
            .filter { !$0.isEmpty }
            .joined(separator: " · ")
    }

    private var metaText: String {
        [formatText, durationText, match.date.formatted(date: .abbreviated, time: .shortened)]
            .filter { !$0.isEmpty }
            .joined(separator: " · ")
    }

    private var formatText: String {
        match.ranked > 1 ? "FT\(match.ranked)" : "VS"
    }

    private var durationText: String {
        let totalSeconds = max(0, Int(match.duration.rounded()))
        let hours = totalSeconds / 3600
        let minutes = (totalSeconds / 60) % 60
        let seconds = totalSeconds % 60

        if hours > 0 {
            return String(format: "%d:%02d:%02d", hours, minutes, seconds)
        }

        return String(format: "%d:%02d", minutes, seconds)
    }
}
