import Observation
import SwiftUI

struct RootView: View {
    @State private var viewModel: RootViewModel
    @State private var updateController = MacadeUpdateController.shared
    private let authenticationService: any AuthenticationServicing

    init(authenticationService: any AuthenticationServicing = FightcadeAuthenticationService()) {
        _viewModel = State(initialValue: RootViewModel())
        self.authenticationService = authenticationService
    }

    var body: some View {
        Group {
            switch viewModel.state {
            case .authenticated(let session):
                AuthenticatedHomeView(session: session) {
                    viewModel.signOut(authenticationService: authenticationService)
                }
            case .restoring:
                StartupLoadingView(
                    title: viewModel.startupLoadingTitle,
                    detail: viewModel.startupLoadingDetail,
                    progress: viewModel.startupLoadingProgress,
                    details: viewModel.startupLoadingDetails
                )
            case .unauthenticated:
                LoginView(authenticationService: authenticationService) { session in
                    viewModel.completeAuthentication(with: session)
                }
            }
        }
        .background(MacadeBackground())
        .task {
            await viewModel.restoreSession(authenticationService: authenticationService)
        }
        .task {
            await updateController.checkAutomatically()
        }
        .sheet(isPresented: $updateController.isPresented) {
            MacadeUpdateSheet(controller: updateController)
        }
    }
}

private enum RootAuthenticationState: Equatable {
    case restoring
    case unauthenticated
    case authenticated(AuthSession)
}

@MainActor
@Observable
private final class RootViewModel {
    var state: RootAuthenticationState = .restoring
    var startupLoadingTitle = "Starting Macade"
    var startupLoadingDetail = "Checking for a saved Fightcade session."
    var startupLoadingProgress = 0.08
    var startupLoadingDetails = [
        "Loading local session state",
        "Preparing secure Fightcade restore"
    ]

    func restoreSession(authenticationService: any AuthenticationServicing) async {
        guard state == .restoring else {
            return
        }

        updateStartupLoading(
            title: "Restoring Session",
            detail: "Validating saved Fightcade credentials.",
            progress: 0.18,
            details: [
                "Reading stored session cookie",
                "Requesting current Fightcade login location"
            ]
        )

        do {
            if let session = try await authenticationService.restoreSession() {
                updateStartupLoading(
                    title: "Session Restored",
                    detail: "Opening lobby for \(session.displayName).",
                    progress: 0.32,
                    details: [
                        "Fightcade session accepted",
                        "Preparing lobby connection"
                    ]
                )
                completeAuthentication(with: session)
            } else {
                updateStartupLoading(
                    title: "Sign In Required",
                    detail: "No saved session was found.",
                    progress: 1,
                    details: ["Opening login screen"]
                )
                state = .unauthenticated
            }
        } catch {
            updateStartupLoading(
                title: "Session Restore Failed",
                detail: "Opening login screen so you can reconnect.",
                progress: 1,
                details: ["Saved session could not be restored"]
            )
            state = .unauthenticated
        }
    }

    func completeAuthentication(with session: AuthSession) {
        withAnimation(.smooth(duration: 0.2)) {
            state = .authenticated(session)
        }
    }

    func signOut(authenticationService: any AuthenticationServicing) {
        try? authenticationService.signOut()
        withAnimation(.smooth(duration: 0.2)) {
            state = .unauthenticated
        }
    }

    private func updateStartupLoading(title: String, detail: String, progress: Double, details: [String]) {
        startupLoadingTitle = title
        startupLoadingDetail = detail
        startupLoadingProgress = progress
        startupLoadingDetails = details
    }
}

struct StartupLoadingView: View {
    let title: String
    let detail: String
    let progress: Double
    let details: [String]

    var body: some View {
        ZStack {
            MacadeBackground()

            Color.black.opacity(0.38)
                .ignoresSafeArea()

            VStack(alignment: .leading, spacing: MacadeSpacing.large) {
                header
                progressSection
                detailsSection
            }
            .padding(MacadeSpacing.large)
            .frame(width: 460, alignment: .leading)
            .background(.ultraThinMaterial, in: RoundedRectangle(cornerRadius: 26))
            .overlay(
                RoundedRectangle(cornerRadius: 26)
                    .stroke(MacadeColor.neonCyan.opacity(0.38), lineWidth: 1)
            )
            .shadow(color: .black.opacity(0.36), radius: 34, x: 0, y: 22)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .contentShape(Rectangle())
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.medium) {
            ZStack {
                RoundedRectangle(cornerRadius: 14)
                    .fill(MacadeColor.rowSelected)

                Text("M")
                    .font(.system(size: 24, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.warning)
            }
            .frame(width: 48, height: 48)

            VStack(alignment: .leading, spacing: 4) {
                Text(title)
                    .font(.system(size: 24, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.ink)

                Text(detail)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .lineLimit(2)
            }
        }
    }

    private var progressSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
            HStack {
                Text("STARTUP")
                    .font(.system(size: 10, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.inkMuted.opacity(0.78))

                Spacer()

                Text(progressText)
                    .font(.system(size: 12, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.neonCyan)
            }

            ProgressView(value: clampedProgress, total: 1)
                .progressViewStyle(.linear)
                .tint(MacadeColor.neonCyan)
        }
    }

    private var detailsSection: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
            ForEach(Array(details.enumerated()), id: \.offset) { _, detail in
                Label(detail, systemImage: "dot.radiowaves.left.and.right")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .lineLimit(1)
            }
        }
        .padding(MacadeSpacing.medium)
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(MacadeColor.panel.opacity(0.68), in: RoundedRectangle(cornerRadius: 16))
    }

    private var clampedProgress: Double {
        min(max(progress, 0), 1)
    }

    private var progressText: String {
        "\(Int((clampedProgress * 100).rounded()))%"
    }
}

#Preview {
    RootView()
}
