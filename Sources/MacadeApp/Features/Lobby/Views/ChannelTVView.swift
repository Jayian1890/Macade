import SwiftUI

struct ChannelTVView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        if let channel = viewModel.selectedChannel {
            VStack(spacing: 0) {
                if viewModel.selectedChannelTVSession == nil {
                    tvHeader(channel: channel)
                    ChannelErrorBanner(viewModel: viewModel)
                }

                if let session = viewModel.selectedChannelTVSession {
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
                        onMatchEnded: {},
                        onStop: viewModel.stopChannelTV
                    )
                } else {
                    waitingView(channel: channel)
                }
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .background(.black.opacity(0.82))
            .task(id: channel.id) {
                viewModel.ensureChannelTVRunning(for: channel)
            }
        } else {
            ContentUnavailableView("No Channel Selected", systemImage: "tv")
                .foregroundStyle(MacadeColor.inkMuted)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .background(.clear)
        }
    }

    private func tvHeader(channel: FightcadeChannel) -> some View {
        HStack(spacing: MacadeSpacing.small) {
            Image(systemName: "tv.fill")
                .font(.system(size: 13, weight: .black))
                .foregroundStyle(MacadeColor.warning)

            Text("TV")
                .font(.system(size: 12, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.warning)

            Text(channel.title)
                .font(.system(size: 13, weight: .black, design: .rounded))
                .foregroundStyle(MacadeColor.ink)
                .lineLimit(1)

            Spacer()

            Button("STOP") {
                viewModel.stopChannelTV()
            }
            .buttonStyle(.borderless)
            .font(.system(size: 11, weight: .black, design: .monospaced))
            .foregroundStyle(MacadeColor.inkMuted)
        }
        .padding(.horizontal, MacadeSpacing.medium)
        .frame(height: 40)
        .background(MacadeColor.sidebar.opacity(0.62))
        .overlay(alignment: .bottom) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }

    private func waitingView(channel: FightcadeChannel) -> some View {
        ZStack {
            LinearGradient(
                colors: [.black, MacadeColor.deepPlum.opacity(0.42), .black],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )

            VStack(spacing: MacadeSpacing.large) {
                Image(systemName: "dot.radiowaves.left.and.right")
                    .font(.system(size: 42, weight: .black))
                    .foregroundStyle(MacadeColor.warning)

                VStack(spacing: MacadeSpacing.small) {
                    Text(channel.title.uppercased())
                        .font(.system(size: 24, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)
                        .multilineTextAlignment(.center)

                    Text(viewModel.channelTVStatusText ?? "Finding spectatable matches...")
                        .font(.system(size: 13, weight: .bold, design: .monospaced))
                        .foregroundStyle(MacadeColor.inkMuted)
                        .multilineTextAlignment(.center)
                }

                ProgressView()
                    .controlSize(.small)
                    .tint(MacadeColor.warning)
            }
            .padding(28)
            .frame(maxWidth: 520)
            .background(.black.opacity(0.58), in: RoundedRectangle(cornerRadius: 20))
            .overlay(RoundedRectangle(cornerRadius: 20).stroke(MacadeColor.warning.opacity(0.38), lineWidth: 1))
            .shadow(color: MacadeColor.warning.opacity(0.16), radius: 28)
            .padding(24)
        }
    }
}
