import SwiftUI

struct AuthenticatedHomeView: View {
    @State private var viewModel: AuthenticatedHomeViewModel
    @State private var layout = LobbyLayoutViewModel()
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
        @Bindable var viewModel = viewModel
        @Bindable var layout = layout

        ZStack {
            MacadeBackground()

            MacadeResizableSplitView(
                dimension: Binding(get: { layout.displayedSidebarWidth }, set: { layout.sidebarWidth = $0 }),
                minimum: MacadeLayout.sidebarCompact,
                maximum: MacadeLayout.sidebarMaximum,
                flexibleMinimum: MacadeLayout.roomMinimum,
                defaultDimension: MacadeLayout.sidebarDefault,
                label: "rooms"
            ) {
                LobbySidebarView(viewModel: viewModel, layout: layout, onSignOut: signOut)
            } trailing: {
                Group {
                    if viewModel.isShowingChannelTV {
                        ChannelTVView(viewModel: viewModel)
                    } else if viewModel.isShowingGameplay {
                        GameplayDetailView(viewModel: viewModel)
                    } else if viewModel.isShowingChannelBrowser {
                        ChannelBrowserView(viewModel: viewModel)
                    } else {
                        ChannelDetailView(viewModel: viewModel, layout: layout)
                    }
                }
                .background(MacadeColor.midnight.opacity(0.22))
            }
            .transition(.opacity)

            if viewModel.isShowingStartupLoading {
                StartupLoadingView(
                    title: viewModel.startupLoadingTitle,
                    detail: viewModel.startupLoadingDetail,
                    progress: viewModel.startupLoadingProgress,
                    details: viewModel.startupLoadingDetails
                )
                .zIndex(10)
                .transition(.opacity)
            }
        }
        .animation(.easeInOut(duration: 0.28), value: viewModel.isRestoringJoinedChannels)
        .animation(.smooth(duration: 0.2), value: viewModel.isShowingStartupLoading)
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .task {
            await viewModel.loadDashboard()
        }
        .onReceive(NotificationCenter.default.publisher(for: .macadeRelayConsoleRequested)) { _ in
            viewModel.isShowingRelayConsole = true
        }
        .sheet(isPresented: $viewModel.isShowingRelayConsole) {
            RelayConsoleView(activeSession: viewModel.activeEmulationSession)
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
