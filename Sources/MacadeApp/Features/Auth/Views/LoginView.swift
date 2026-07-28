import SwiftUI

struct LoginView: View {
    @State private var viewModel: LoginViewModel
    private let onAuthenticated: (AuthSession) -> Void

    init(
        authenticationService: any AuthenticationServicing = FightcadeAuthenticationService(),
        onAuthenticated: @escaping (AuthSession) -> Void
    ) {
        _viewModel = State(
            initialValue: LoginViewModel(authenticationService: authenticationService)
        )
        self.onAuthenticated = onAuthenticated
    }

    var body: some View {
        VStack {
            LoginFormView(viewModel: viewModel) { session in
                onAuthenticated(session)
            }
            .frame(width: 380)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
    }
}

#Preview {
    LoginView { _ in }
        .background(MacadeBackground())
}
