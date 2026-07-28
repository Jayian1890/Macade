import SwiftUI

struct SectionTitle: View {
    let title: String

    init(_ title: String) {
        self.title = title
    }

    var body: some View {
        Text(title)
            .font(.system(size: 24, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.ink)
    }
}

struct FilterChip: View {
    let title: String
    let action: () -> Void

    var body: some View {
        Button(action: action) {
            HStack(spacing: 4) {
                Text(title)
                Image(systemName: "xmark")
            }
            .font(MacadeTypography.caption)
            .padding(.horizontal, 8)
            .frame(height: 22)
            .background(MacadeColor.panel, in: Capsule())
        }
        .buttonStyle(.plain)
        .foregroundStyle(MacadeColor.ink)
    }
}

struct FilterOptionButtonStyle: ButtonStyle {
    let isSelected: Bool

    func makeBody(configuration: Configuration) -> some View {
        configuration.label
            .font(MacadeTypography.caption)
            .lineLimit(1)
            .padding(.horizontal, 8)
            .frame(height: 28)
            .frame(maxWidth: .infinity)
            .foregroundStyle(isSelected ? MacadeColor.midnight : MacadeColor.ink)
            .background(isSelected ? MacadeColor.warning : MacadeColor.panel, in: Capsule())
            .opacity(configuration.isPressed ? 0.72 : 1)
    }
}
