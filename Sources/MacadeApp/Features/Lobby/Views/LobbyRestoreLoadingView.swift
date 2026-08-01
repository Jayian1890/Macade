import SwiftUI

struct LobbyRestoreLoadingView: View {
    let channelCount: Int
    @State private var isAnimating = false

    var body: some View {
        ZStack {
            Rectangle()
                .fill(.black.opacity(0.46))
                .ignoresSafeArea()

            VStack(spacing: MacadeSpacing.large) {
                orbitalLoader

                VStack(spacing: MacadeSpacing.xSmall) {
                    Text("Rejoining Rooms")
                        .font(.system(size: 26, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)

                    Text(subtitle)
                        .font(.system(size: 13, weight: .bold, design: .monospaced))
                        .foregroundStyle(MacadeColor.inkMuted)
                        .multilineTextAlignment(.center)
                }

                loadingRail
            }
            .padding(.horizontal, MacadeSpacing.extraLarge)
            .padding(.vertical, MacadeSpacing.jumbo)
            .frame(width: 420)
            .background(cardBackground, in: RoundedRectangle(cornerRadius: 32, style: .continuous))
            .overlay(cardStroke, in: RoundedRectangle(cornerRadius: 32, style: .continuous))
            .shadow(color: MacadeColor.neonCyan.opacity(0.20), radius: 42, y: 18)
        }
        .onAppear { isAnimating = true }
    }

    private var subtitle: String {
        let roomText = channelCount == 1 ? "room" : "rooms"
        return "Restoring your saved lobby stack · \(max(channelCount, 1)) \(roomText)"
    }

    private var orbitalLoader: some View {
        ZStack {
            Circle()
                .stroke(MacadeColor.panelStrong, lineWidth: 12)
                .frame(width: 118, height: 118)

            Circle()
                .trim(from: 0.05, to: 0.62)
                .stroke(loaderGradient, style: StrokeStyle(lineWidth: 12, lineCap: .round))
                .frame(width: 118, height: 118)
                .rotationEffect(.degrees(isAnimating ? 360 : 0))

            Circle()
                .trim(from: 0.12, to: 0.36)
                .stroke(MacadeColor.warning.opacity(0.86), style: StrokeStyle(lineWidth: 4, lineCap: .round))
                .frame(width: 84, height: 84)
                .rotationEffect(.degrees(isAnimating ? -360 : 0))

            Image(systemName: "rectangle.3.group.bubble.left.fill")
                .font(.system(size: 30, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)
                .shadow(color: MacadeColor.neonCyan.opacity(0.65), radius: 18)
        }
        .animation(.linear(duration: 1.35).repeatForever(autoreverses: false), value: isAnimating)
    }

    private var loadingRail: some View {
        HStack(spacing: 8) {
            ForEach(0..<9, id: \.self) { index in
                Capsule()
                    .fill(index.isMultiple(of: 3) ? MacadeColor.warning : MacadeColor.neonCyan)
                    .frame(width: 22, height: 5)
                    .opacity(isAnimating ? railOpacity(for: index) : 0.22)
                    .scaleEffect(x: isAnimating ? railScale(for: index) : 0.6, y: 1)
            }
        }
        .animation(.easeInOut(duration: 0.9).repeatForever(autoreverses: true), value: isAnimating)
    }

    private var cardBackground: some ShapeStyle {
        LinearGradient(
            colors: [
                MacadeColor.chrome.opacity(0.96),
                MacadeColor.deepPlum.opacity(0.86),
                MacadeColor.arcadeBlue.opacity(0.74)
            ],
            startPoint: .topLeading,
            endPoint: .bottomTrailing
        )
    }

    private var cardStroke: some ShapeStyle {
        LinearGradient(
            colors: [MacadeColor.neonCyan.opacity(0.86), MacadeColor.neonPink.opacity(0.52), MacadeColor.warning.opacity(0.42)],
            startPoint: .topLeading,
            endPoint: .bottomTrailing
        )
    }

    private var loaderGradient: AngularGradient {
        AngularGradient(colors: [.clear, MacadeColor.neonCyan, MacadeColor.neonPink, .clear], center: .center)
    }

    private func railOpacity(for index: Int) -> Double {
        0.28 + Double((index + 2) % 5) * 0.14
    }

    private func railScale(for index: Int) -> CGFloat {
        0.72 + CGFloat((index + 1) % 4) * 0.18
    }
}
