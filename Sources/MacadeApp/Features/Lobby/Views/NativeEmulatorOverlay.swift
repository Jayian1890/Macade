import SwiftUI

struct NativeEmulatorOverlay: View {
    let state: FightcadeEmbeddedOverlayState

    var body: some View {
        GeometryReader { proxy in
            ZStack {
                scoreLayer(size: proxy.size)
                spectatorLayer(size: proxy.size)
                chatLayer(size: proxy.size)
            }
            .frame(width: proxy.size.width, height: proxy.size.height)
        }
        .allowsHitTesting(false)
    }

    private func scoreLayer(size: CGSize) -> some View {
        let rowHeight: CGFloat = 24
        let horizontalPadding: CGFloat = 10
        let contentWidth = max(0, size.width - horizontalPadding * 2)
        let centerWidth = min(max(contentWidth * 0.22, 104), 164)
        let sideWidth = max(0, (contentWidth - centerWidth) / 2)
        let leftPlayer = player(at: 0)
        let rightPlayer = player(at: 1)

        return HStack(spacing: 0) {
            playerScoreSide(
                player: leftPlayer,
                isLocalPlayer: !state.isSpectator && state.player == 0,
                nameFirst: true
            )
                .frame(width: sideWidth, alignment: .trailing)

            HStack(spacing: 8) {
                scoreSeparator
                Text(centerText)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .frame(maxWidth: .infinity)
                scoreSeparator
            }
            .frame(width: centerWidth)

            playerScoreSide(
                player: rightPlayer,
                isLocalPlayer: !state.isSpectator && state.player == 1,
                nameFirst: false
            )
                .frame(width: sideWidth, alignment: .leading)
        }
        .font(.system(size: 12, weight: .black, design: .monospaced))
        .foregroundStyle(.white)
        .lineLimit(1)
        .minimumScaleFactor(0.72)
        .padding(.horizontal, horizontalPadding)
        .frame(width: size.width, height: rowHeight)
        .background(.black.opacity(0.8), in: Rectangle())
        .position(x: size.width / 2, y: rowHeight / 2)
    }

    @ViewBuilder
    private func spectatorLayer(size: CGSize) -> some View {
        if state.isSpectator, spectatorDisplayCount > 0 {
            Text("Spectators \(spectatorDisplayCount)")
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
                .padding(.horizontal, 10)
                .frame(height: 22)
                .background(.black.opacity(0.78), in: Capsule())
                .position(x: size.width / 2, y: max(18, size.height - 18))
        }
    }

    @ViewBuilder
    private func chatLayer(size: CGSize) -> some View {
        if state.isChatInputActive || state.chatFrames > 0, !chatRows.isEmpty {
            VStack(alignment: .leading, spacing: 3) {
                ForEach(chatRows) { row in
                    Text(row.text)
                        .font(.system(size: 10, weight: .bold, design: .monospaced))
                        .foregroundStyle(row.isInput ? .white : MacadeColor.warning.opacity(0.92))
                        .lineLimit(1)
                }
            }
            .padding(.horizontal, 8)
            .padding(.vertical, 6)
            .frame(width: min(360, max(120, size.width - 16)), alignment: .leading)
            .background(.black.opacity(0.82), in: RoundedRectangle(cornerRadius: 8))
            .position(
                x: min(360, max(120, size.width - 16)) / 2 + 8,
                y: max(20, size.height - chatHeight / 2 - 8)
            )
        }
    }

    private var centerText: String {
        if state.isSpectator {
            return "spectating"
        }

        return state.ranked > 1 ? "FT\(state.ranked)" : "VS"
    }

    private var scoreSeparator: some View {
        Text("|")
            .foregroundStyle(MacadeColor.stroke)
    }

    @ViewBuilder
    private func playerScoreSide(
        player: FightcadeEmbeddedOverlayState.Player,
        isLocalPlayer: Bool,
        nameFirst: Bool
    ) -> some View {
        HStack(spacing: 8) {
            if nameFirst {
                playerIdentity(player, isLocalPlayer: isLocalPlayer, alignment: .trailing)
                scoreSeparator
                scoreText(player.score)
            } else {
                scoreText(player.score)
                scoreSeparator
                playerIdentity(player, isLocalPlayer: isLocalPlayer, alignment: .leading)
            }
        }
    }

    private func playerIdentity(
        _ player: FightcadeEmbeddedOverlayState.Player,
        isLocalPlayer: Bool,
        alignment: Alignment
    ) -> some View {
        HStack(spacing: 5) {
            if let rank = rankLabel(for: player.rank) {
                rankBadge(rank, color: rankAccent(for: player.rank))
            }

            Text(playerDisplayName(player, isLocalPlayer: isLocalPlayer))
                .foregroundStyle(rankAccent(for: player.rank))
        }
        .frame(maxWidth: .infinity, alignment: alignment)
    }

    private func rankBadge(_ rank: String, color: Color) -> some View {
        Text(rank)
            .font(.system(size: 9, weight: .black, design: .monospaced))
            .foregroundStyle(color)
            .frame(minWidth: 15)
            .frame(height: 15)
            .background(color.opacity(0.14), in: RoundedRectangle(cornerRadius: 3, style: .continuous))
    }

    private func scoreText(_ score: Int) -> some View {
        Text("\(score)")
            .foregroundStyle(MacadeColor.neonCyan)
            .frame(minWidth: 16)
    }

    private var spectatorDisplayCount: Int {
        max(0, state.spectators - 1)
    }

    private var chatRows: [OverlayChatRow] {
        var rows = state.chatLines.reversed().map { line in
            OverlayChatRow(text: "\(line.name): \(line.text)", isInput: false)
        }

        if state.isChatInputActive {
            rows.append(OverlayChatRow(text: "> \(state.chatInput)_", isInput: true))
        }

        return rows
    }

    private var chatHeight: CGFloat {
        CGFloat(chatRows.count * 13 + 12)
    }

    private func player(at index: Int) -> FightcadeEmbeddedOverlayState.Player {
        guard state.players.indices.contains(index) else {
            return FightcadeEmbeddedOverlayState.Player(
                name: "",
                country: "",
                rank: -1,
                score: 0,
                fallbackName: "Player \(index + 1)"
            )
        }

        return state.players[index]
    }

    private func playerDisplayName(_ player: FightcadeEmbeddedOverlayState.Player, isLocalPlayer: Bool) -> String {
        "\(player.displayName)\(isLocalPlayer ? " *" : "")"
    }

    private func rankLabel(for rank: Int) -> String? {
        guard rank > 0 else {
            return nil
        }

        switch rank {
        case 1:
            return "E"
        case 2:
            return "D"
        case 3:
            return "C"
        case 4:
            return "B"
        case 5:
            return "A"
        case 6:
            return "S"
        default:
            return "\(rank)"
        }
    }

    private func rankAccent(for rank: Int) -> Color {
        switch rank {
        case 1:
            return MacadeColor.rankE
        case 2:
            return MacadeColor.rankD
        case 3:
            return MacadeColor.rankC
        case 4:
            return MacadeColor.rankB
        case 5:
            return MacadeColor.rankA
        case let value where value >= 6:
            return MacadeColor.rankS
        default:
            return .white
        }
    }

    private struct OverlayChatRow: Identifiable {
        let id = UUID()
        let text: String
        let isInput: Bool
    }
}
