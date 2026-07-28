import SwiftUI

struct MacadeTextField: View {
    let title: String
    @Binding var text: String
    let prompt: String

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
            Text(title)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)

            TextField(prompt, text: $text)
                .textFieldStyle(.plain)
                .font(MacadeTypography.body)
                .foregroundStyle(MacadeColor.ink)
                .autocorrectionDisabled()
                .padding(MacadeSpacing.medium)
                .background(MacadeColor.panel, in: RoundedRectangle(cornerRadius: 16))
                .overlay(
                    RoundedRectangle(cornerRadius: 16)
                        .stroke(MacadeColor.stroke, lineWidth: 1)
                )
        }
    }
}

struct MacadePasswordField: View {
    let title: String
    @Binding var password: String
    @Binding var isVisible: Bool

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
            Text(title)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)

            HStack {
                Group {
                    if isVisible {
                        TextField("Password", text: $password)
                    } else {
                        SecureField("Password", text: $password)
                    }
                }
                .textFieldStyle(.plain)
                .font(MacadeTypography.body)
                .foregroundStyle(MacadeColor.ink)
                .autocorrectionDisabled()

                Button {
                    isVisible.toggle()
                } label: {
                    Image(systemName: isVisible ? "eye.slash" : "eye")
                        .foregroundStyle(MacadeColor.inkMuted)
                }
                .buttonStyle(.plain)
            }
            .padding(MacadeSpacing.medium)
            .background(MacadeColor.panel, in: RoundedRectangle(cornerRadius: 16))
            .overlay(
                RoundedRectangle(cornerRadius: 16)
                    .stroke(MacadeColor.stroke, lineWidth: 1)
            )
        }
    }
}
