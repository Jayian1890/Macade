import SwiftUI

struct AuthenticatedHomeView: View {
    @State private var viewModel: AuthenticatedHomeViewModel
    private let onSignOut: () -> Void

    init(
        session: AuthSession,
        lobbyService: any FightcadeLobbyServicing = FightcadeLobbyService(),
        launcher: any FightcadeLaunching = FightcadeLauncher(),
        onSignOut: @escaping () -> Void
    ) {
        _viewModel = State(initialValue: AuthenticatedHomeViewModel(session: session, lobbyService: lobbyService, launcher: launcher))
        self.onSignOut = onSignOut
    }

    var body: some View {
        ZStack {
            MacadeBackground()

            HStack(spacing: 0) {
                LobbySidebarView(viewModel: viewModel, onSignOut: signOut)

                if viewModel.isShowingChannelBrowser {
                    ChannelBrowserView(viewModel: viewModel)
                } else {
                    ChannelDetailView(viewModel: viewModel)
                }
            }
            .background(.black.opacity(0.22))
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .task {
            await viewModel.loadDashboard()
        }
    }

    private func signOut() {
        viewModel.disconnect()
        onSignOut()
    }
}

#Preview {
    AuthenticatedHomeView(
        session: AuthSession(username: "player-one", displayName: "player-one"),
        onSignOut: {}
    )
    .background(MacadeBackground())
}
