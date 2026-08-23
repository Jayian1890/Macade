import SwiftUI

struct MacadeFrostedFill: View {
    var opacity: Double = 0.52

    var body: some View {
        ZStack {
            Rectangle()
                .fill(.ultraThinMaterial)
            Rectangle()
                .fill(MacadeColor.midnight.opacity(opacity))
        }
    }
}

struct MacadePanel<Content: View>: View {
    var cornerRadius: CGFloat = 16
    var accent: Color = MacadeColor.neonCyan
    @ViewBuilder var content: Content

    init(
        cornerRadius: CGFloat = 16,
        accent: Color = MacadeColor.neonCyan,
        @ViewBuilder content: () -> Content
    ) {
        self.cornerRadius = cornerRadius
        self.accent = accent
        self.content = content()
    }

    var body: some View {
        content
            .background {
                ZStack {
                    RoundedRectangle(cornerRadius: cornerRadius, style: .continuous)
                        .fill(.ultraThinMaterial)
                    RoundedRectangle(cornerRadius: cornerRadius, style: .continuous)
                        .fill(MacadeColor.midnight.opacity(0.48))
                }
            }
            .overlay(
                RoundedRectangle(cornerRadius: cornerRadius, style: .continuous)
                    .strokeBorder(
                        LinearGradient(
                            colors: [accent.opacity(0.55), MacadeColor.neonPink.opacity(0.28)],
                            startPoint: .topLeading,
                            endPoint: .bottomTrailing
                        ),
                        lineWidth: 1
                    )
            )
            .clipShape(RoundedRectangle(cornerRadius: cornerRadius, style: .continuous))
    }
}
