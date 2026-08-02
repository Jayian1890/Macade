import SwiftUI

struct MacadeUpdateSheet: View {
    @Bindable var controller: MacadeUpdateController

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.large) {
            header
            content
            footer
        }
        .padding(MacadeSpacing.large)
        .frame(width: 520)
        .frame(minHeight: 320)
        .background(MacadeBackground())
        .foregroundStyle(MacadeColor.ink)
        .tint(MacadeColor.neonCyan)
        .preferredColorScheme(.dark)
        .colorScheme(.dark)
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.medium) {
            Image(systemName: "arrow.triangle.2.circlepath.circle.fill")
                .font(.system(size: 34, weight: .bold))
                .foregroundStyle(MacadeColor.neonCyan)

            VStack(alignment: .leading, spacing: 4) {
                Text(title)
                    .font(.system(size: 24, weight: .black, design: .rounded))
                Text("Installed version: \(controller.currentVersionLabel)")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
            }

            Spacer()
        }
    }

    @ViewBuilder
    private var content: some View {
        switch controller.status {
        case .idle, .checking:
            checkingView
        case .current:
            messageView("Macade is up to date.", detail: "You already have the newest public release.")
        case .available(let update):
            updateView(update, detail: "Macade will download and install this update automatically.")
        case .scheduled(let update, let secondsRemaining):
            updateView(update, detail: "Automatic update starts in \(secondsRemaining) seconds. Choose Update Later to keep using this version for now.")
        case .downloading(let update):
            updateView(update, detail: "Downloading and verifying \(update.asset.name)...")
        case .downloaded(let update, let url):
            updateView(update, detail: "Downloaded \(url.lastPathComponent). Preparing automatic install and relaunch...")
        case .installing(let update):
            updateView(update, detail: "Installing Macade \(update.version) and relaunching...")
        case .failed(let message):
            messageView("Update check failed.", detail: message)
        }
    }

    private var checkingView: some View {
        HStack(spacing: MacadeSpacing.medium) {
            ProgressView()
                .controlSize(.regular)
            Text("Checking GitHub Releases...")
                .font(MacadeTypography.body)
                .foregroundStyle(MacadeColor.inkMuted)
        }
        .frame(maxWidth: .infinity, minHeight: 120, alignment: .center)
    }

    private func updateView(_ update: MacadeUpdate, detail: String) -> some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            messageView("Macade \(update.version) is available.", detail: detail)

            if !update.body.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty {
                ScrollView {
                    Text(update.body)
                        .font(MacadeTypography.caption)
                        .foregroundStyle(MacadeColor.inkMuted)
                        .textSelection(.enabled)
                        .frame(maxWidth: .infinity, alignment: .leading)
                        .padding(MacadeSpacing.medium)
                }
                .frame(maxHeight: 150)
                .background(MacadeColor.panel, in: RoundedRectangle(cornerRadius: 14))
                .overlay(RoundedRectangle(cornerRadius: 14).stroke(MacadeColor.stroke))
            }
        }
    }

    private func messageView(_ message: String, detail: String) -> some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            Text(message)
                .font(MacadeTypography.body)
            Text(detail)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
        }
        .frame(maxWidth: .infinity, minHeight: 90, alignment: .leading)
    }

    private var footer: some View {
        HStack(spacing: MacadeSpacing.medium) {
            if controller.availableUpdate != nil {
                Button("Release Notes") { controller.openReleasePage() }
                    .buttonStyle(.borderless)
                Button("Update Later") { controller.updateLater() }
                    .buttonStyle(.borderless)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .disabled(isInstalling)
            }

            Spacer()

            Button("Close") { controller.isPresented = false }
                .buttonStyle(.borderless)
                .foregroundStyle(MacadeColor.inkMuted)

            primaryButton
        }
    }

    @ViewBuilder
    private var primaryButton: some View {
        switch controller.status {
        case .available, .scheduled:
            Button("Updating Soon") {}
                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
                .disabled(true)
        case .downloaded, .installing:
            Button("Relaunching") {}
                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
                .disabled(true)
        case .failed, .current, .idle:
            Button("Check Again") { controller.showAndCheck() }
                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
        case .checking, .downloading:
            Button("Working...") {}
                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
                .disabled(true)
        }
    }

    private var title: String {
        switch controller.status {
        case .available, .scheduled, .downloading, .downloaded, .installing: "Update Available"
        case .failed: "Updater"
        default: "Check for Updates"
        }
    }

    private var isInstalling: Bool {
        if case .installing = controller.status { return true }
        return false
    }
}
