import SwiftUI

struct AuthenticatedHomeView: View {
    @State private var viewModel: AuthenticatedHomeViewModel
    @AppStorage("lobbySidebarWidth") private var lobbySidebarWidth = 184.0
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
                    .frame(width: lobbySidebarWidth)
                    .overlay(alignment: .trailing) {
                        SidebarResizeHandle(width: $lobbySidebarWidth, range: 148...280)
                    }

                if viewModel.isShowingChannelTV {
                    ChannelTVView(viewModel: viewModel)
                } else if viewModel.isShowingGameplay {
                    GameplayDetailView(viewModel: viewModel)
                } else if viewModel.isShowingChannelBrowser {
                    ChannelBrowserView(viewModel: viewModel)
                } else {
                    ChannelDetailView(viewModel: viewModel)
                }
            }
            .background(.black.opacity(0.22))
            .transition(.opacity)
        }
        .animation(.easeInOut(duration: 0.28), value: viewModel.isRestoringJoinedChannels)
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

private struct SidebarResizeHandle: View {
    @Binding var width: Double
    let range: ClosedRange<Double>
    @State private var startWidth: Double?

    var body: some View {
        Rectangle()
            .fill(.clear)
            .frame(width: 8)
            .contentShape(Rectangle())
            .gesture(
                DragGesture()
                    .onChanged { value in
                        let base = startWidth ?? width
                        startWidth = base
                        width = min(max(base + value.translation.width, range.lowerBound), range.upperBound)
                    }
                    .onEnded { _ in
                        startWidth = nil
                    }
            )
            .overlay {
                Rectangle()
                    .fill(MacadeColor.stroke.opacity(0.75))
                    .frame(width: 1)
            }
            .help("Resize sidebar")
    }
}

#Preview {
    AuthenticatedHomeView(
        session: AuthSession(username: "player-one", displayName: "player-one"),
        onSignOut: {}
    )
    .background(MacadeBackground())
}
