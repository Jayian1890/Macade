import SwiftUI

struct GameplayDetailView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        if let session = viewModel.activeEmulationSession,
           let channel = viewModel.activeEmulationChannel {
            EmbeddedEmulatorPanel(
                session: session,
                isChannelChatVisible: viewModel.isShowingChannelChat,
                channelChatOverlay: AnyView(ChannelChatView(
                    channel: channel,
                    viewModel: viewModel,
                    showsPreview: false,
                    backgroundOpacity: 0.5
                )),
                onToggleChannelChat: viewModel.toggleChannelChat,
                onMatchEnded: viewModel.finishActiveMatchSession,
                onStop: viewModel.stopActiveEmulationSession
            )
            .frame(maxWidth: .infinity, maxHeight: .infinity)
        } else {
            ContentUnavailableView("No Active Gameplay", systemImage: "gamecontroller")
                .foregroundStyle(MacadeColor.inkMuted)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .background(.clear)
        }
    }
}
