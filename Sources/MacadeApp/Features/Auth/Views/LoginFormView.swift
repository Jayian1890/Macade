import SwiftUI

struct LoginFormView: View {
    @Bindable var viewModel: LoginViewModel
    let onAuthenticated: (AuthSession) -> Void

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            header

            VStack(spacing: MacadeSpacing.medium) {
                MacadeTextField(
                    title: "Username",
                    text: $viewModel.username,
                    prompt: "Fightcade username"
                )

                MacadePasswordField(
                    title: "Password",
                    password: $viewModel.password,
                    isVisible: $viewModel.isPasswordVisible
                )
            }
            .disabled(viewModel.isSubmitting)

            if let statusMessage = viewModel.statusMessage {
                Label(statusMessage, systemImage: "network")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.neonCyan)
            }

            if let errorMessage = viewModel.errorMessage {
                Text(errorMessage)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.warning)
                    .padding(MacadeSpacing.medium)
                    .frame(maxWidth: .infinity, alignment: .leading)
                    .background(MacadeColor.warning.opacity(0.12), in: RoundedRectangle(cornerRadius: 14))
            }

            Button(action: submit) {
                HStack(spacing: MacadeSpacing.small) {
                    if viewModel.isSubmitting {
                        ProgressView()
                            .controlSize(.small)
                    }

                    Text(viewModel.isSubmitting ? "Connecting" : "Connect")
                        .font(MacadeTypography.headline)
                }
                .frame(maxWidth: .infinity)
                .padding(.vertical, MacadeSpacing.medium)
            }
            .buttonStyle(MacadePrimaryButtonStyle())
            .disabled(!viewModel.canSubmit)
            .keyboardShortcut(.return, modifiers: [])
        }
        .onSubmit(submit)
        .padding(MacadeSpacing.large)
        .background(.ultraThinMaterial, in: RoundedRectangle(cornerRadius: 22))
        .overlay(
            RoundedRectangle(cornerRadius: 22)
                .stroke(MacadeColor.stroke, lineWidth: 1)
        )
        .shadow(color: .black.opacity(0.32), radius: 30, x: 0, y: 20)
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.medium) {
            ZStack {
                RoundedRectangle(cornerRadius: 12)
                    .fill(MacadeColor.rowSelected)

                Text("M")
                    .font(.system(size: 22, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.warning)
            }
            .frame(width: 44, height: 44)

            VStack(alignment: .leading, spacing: 2) {
                Text("Macade")
                    .font(MacadeTypography.title)
                    .foregroundStyle(MacadeColor.ink)
            }
        }
        .padding(.bottom, MacadeSpacing.small)
    }

    private func submit() {
        Task {
            if let session = await viewModel.submit() {
                onAuthenticated(session)
            }
        }
    }
}

#Preview {
    LoginFormView(viewModel: LoginViewModel()) { _ in }
        .frame(width: 420)
        .padding()
        .background(MacadeBackground())
}
