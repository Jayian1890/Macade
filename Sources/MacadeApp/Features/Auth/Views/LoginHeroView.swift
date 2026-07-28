import SwiftUI

struct LoginHeroView: View {
    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.extraLarge) {
            brandLockup

            Spacer(minLength: MacadeSpacing.jumbo)

            Text("Sign in")
                .font(MacadeTypography.display)
                .foregroundStyle(MacadeColor.ink)

            Spacer(minLength: MacadeSpacing.large)
        }
        .padding(MacadeSpacing.extraLarge)
    }

    private var brandLockup: some View {
        HStack(spacing: MacadeSpacing.medium) {
            ZStack {
                RoundedRectangle(cornerRadius: 14)
                    .fill(MacadeColor.panelStrong)
                    .overlay(
                        RoundedRectangle(cornerRadius: 14)
                            .stroke(MacadeColor.stroke, lineWidth: 1)
                    )

                Text("M")
                    .font(.system(size: 24, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.neonCyan)
            }
            .frame(width: 48, height: 48)

            VStack(alignment: .leading, spacing: 2) {
                Text("Macade")
                    .font(MacadeTypography.title)
                    .foregroundStyle(MacadeColor.ink)

            }
        }
    }
}

#Preview {
    LoginHeroView()
        .background(MacadeBackground())
}
