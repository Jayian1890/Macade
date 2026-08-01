import SwiftUI

struct LobbyRestoreLoadingView: View {
    let channelCount: Int
    @State private var isAnimating = false

    var body: some View {
        ZStack {
            fullScreenBackground

            VStack(spacing: MacadeSpacing.extraLarge) {
                header

                orbitalLoader

                VStack(spacing: MacadeSpacing.xSmall) {
                    Text("Rejoining Rooms")
                        .font(.system(size: 34, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)

                    Text(subtitle)
                        .font(.system(size: 13, weight: .bold, design: .monospaced))
                        .foregroundStyle(MacadeColor.inkMuted)
                        .multilineTextAlignment(.center)
                }

                loadingRail
            }
            .padding(MacadeSpacing.jumbo)
            .frame(maxWidth: 560)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .onAppear { isAnimating = true }
    }

    private var subtitle: String {
        let roomText = channelCount == 1 ? "room" : "rooms"
        return "Restoring your saved lobby stack · \(max(channelCount, 1)) \(roomText)"
    }

    private var header: some View {
        VStack(spacing: MacadeSpacing.xSmall) {
            Text("MACADE")
                .font(.system(size: 14, weight: .heavy, design: .monospaced))
                .tracking(5)
                .foregroundStyle(MacadeColor.neonCyan)

            Text("Loading Fightcade Lobby")
                .font(.system(size: 13, weight: .bold, design: .monospaced))
                .foregroundStyle(MacadeColor.inkMuted)
        }
    }

    private var fullScreenBackground: some View {
        ZStack {
            MacadeBackground()

            RadialGradient(
                colors: [MacadeColor.neonCyan.opacity(0.22), .clear],
                center: .topLeading,
                startRadius: 20,
                endRadius: 520
            )

            RadialGradient(
                colors: [MacadeColor.neonPink.opacity(0.16), .clear],
                center: .bottomTrailing,
                startRadius: 40,
                endRadius: 620
            )
        }
        .ignoresSafeArea()
    }

    private var orbitalLoader: some View {
        ZStack {
            Circle()
                .stroke(MacadeColor.panelStrong, lineWidth: 12)
                .frame(width: 136, height: 136)

            Circle()
                .trim(from: 0.05, to: 0.62)
                .stroke(loaderGradient, style: StrokeStyle(lineWidth: 12, lineCap: .round))
                .frame(width: 136, height: 136)
                .rotationEffect(.degrees(isAnimating ? 360 : 0))

            Circle()
                .trim(from: 0.12, to: 0.36)
                .stroke(MacadeColor.warning.opacity(0.86), style: StrokeStyle(lineWidth: 4, lineCap: .round))
                .frame(width: 96, height: 96)
                .rotationEffect(.degrees(isAnimating ? -360 : 0))

            Image(systemName: "rectangle.3.group.bubble.left.fill")
                .font(.system(size: 34, weight: .black))
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
