import SwiftUI

struct MacadeBackground: View {
    var body: some View {
        ZStack {
            LinearGradient(
                colors: [
                    MacadeColor.midnight,
                    MacadeColor.deepPlum.opacity(0.92),
                    MacadeColor.arcadeBlue.opacity(0.62)
                ],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )

            RadialGradient(
                colors: [
                    MacadeColor.neonCyan.opacity(0.34),
                    .clear
                ],
                center: .topTrailing,
                startRadius: 40,
                endRadius: 520
            )

            RadialGradient(
                colors: [
                    MacadeColor.neonPink.opacity(0.27),
                    .clear
                ],
                center: .bottomLeading,
                startRadius: 20,
                endRadius: 460
            )
        }
        .ignoresSafeArea()
    }
}
