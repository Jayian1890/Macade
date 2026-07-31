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
                ProgressView()
                    .controlSize(.regular)
                    .frame(maxWidth: .infinity, maxHeight: .infinity)
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

    func restoreSession(authenticationService: any AuthenticationServicing) async {
        guard state == .restoring else {
            return
        }

        do {
            if let session = try await authenticationService.restoreSession() {
                completeAuthentication(with: session)
            } else {
                state = .unauthenticated
            }
        } catch {
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
}

#Preview {
    RootView()
}
