import SwiftUI

struct ChannelDetailView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        if let channel = viewModel.selectedChannel {
            VStack(spacing: 0) {
                ChannelHeader(channel: channel, viewModel: viewModel)

                ChannelErrorBanner(viewModel: viewModel)

                HStack(spacing: 0) {
                    if let session = viewModel.selectedEmulationSession {
                        EmbeddedEmulatorPanel(
                            session: session,
                            isChannelChatVisible: viewModel.isShowingChannelChat,
                            onToggleChannelChat: viewModel.toggleChannelChat,
                            onStop: viewModel.stopActiveEmulationSession
                        )

                        if viewModel.isShowingChannelChat {
                            ChannelChatView(channel: channel, viewModel: viewModel)
                                .frame(width: 360)
                                .transition(.move(edge: .trailing).combined(with: .opacity))
                        }
                    } else {
                        ChannelChatView(channel: channel, viewModel: viewModel)
                    }

                    PlayerListView(channel: channel, users: viewModel.selectedChannelUsers, viewModel: viewModel)
                }
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .background(.clear)
            .sheet(isPresented: $viewModel.isShowingFBNeoSettings) {
                FBNeoSettingsView()
            }
        } else {
            ContentUnavailableView("No Channel Selected", systemImage: "arcade.stick.console")
                .foregroundStyle(MacadeColor.inkMuted)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .background(.clear)
        }
    }
}

private struct ChannelChatView: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel
    private let bottomID = "channel-chat-bottom"

    var body: some View {
        VStack(spacing: 0) {
            ScrollViewReader { proxy in
                ScrollView {
                    LazyVStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                        if let previewURL = channel.previewURL {
                            AsyncImage(url: previewURL) { image in
                                image
                                    .resizable()
                                    .scaledToFill()
                            } placeholder: {
                                Rectangle().fill(MacadeColor.panel)
                            }
                            .frame(height: 140)
                            .clipShape(RoundedRectangle(cornerRadius: 14))
                            .overlay(alignment: .bottomLeading) {
                                Text(channel.subtitle.uppercased())
                                    .font(MacadeTypography.caption)
                                    .foregroundStyle(MacadeColor.ink)
                                    .padding(10)
                                    .frame(maxWidth: .infinity, alignment: .leading)
                                    .background(.black.opacity(0.58))
                            }
                        }

                        ForEach(viewModel.selectedChannelMessages) { message in
                            ChatMessageRow(message: message, channel: channel, viewModel: viewModel)
                                .id(message.id)
                        }

                        Color.clear
                            .frame(height: 1)
                            .id(bottomID)
                    }
                    .padding(MacadeSpacing.large)
                    .frame(maxWidth: .infinity, alignment: .leading)
                }
                .onAppear {
                    scrollToBottom(proxy)
                }
                .onChange(of: viewModel.selectedChannelMessages.count) { _, _ in
                    scrollToBottom(proxy)
                }
                .onChange(of: channel.id) { _, _ in
                    scrollToBottom(proxy)
                }
            }

            ChatInput(channel: channel, viewModel: viewModel)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
        .background(chatBackground)
    }

    private func scrollToBottom(_ proxy: ScrollViewProxy) {
        DispatchQueue.main.async {
            proxy.scrollTo(bottomID, anchor: .bottom)
        }
    }

    private var chatBackground: some View {
        ZStack {
            MacadeColor.midnight.opacity(0.42)
            LinearGradient(
                colors: [MacadeColor.deepPlum.opacity(0.18), .clear, .black.opacity(0.25)],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )
        }
    }
}

private struct ChatInput: View {
    let channel: FightcadeChannel
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @FocusState private var isChatFocused: Bool

    var body: some View {
        VStack(spacing: 0) {
            if !mentionSuggestions.isEmpty {
                MentionSuggestionStrip(
                    suggestions: mentionSuggestions,
                    selectedUserID: mentionSuggestions.first?.id
                ) { user in
                    viewModel.completeChatMention(user.name)
                }
            }

            HStack(spacing: MacadeSpacing.medium) {
                TextField("Message", text: $viewModel.chatDraft)
                    .textFieldStyle(.plain)
                    .font(.system(size: 16, weight: .regular, design: .rounded))
                    .focused($isChatFocused)
                    .disabled(!viewModel.joinedChannelIDs.contains(channel.id) || viewModel.isSendingChat)
                    .onSubmit(sendChatKeepingFocus)
                    .onKeyPress(.tab) {
                        guard let user = mentionSuggestions.first else {
                            return .ignored
                        }

                        viewModel.completeChatMention(user.name)
                        return .handled
                    }

                Button(action: sendChatKeepingFocus) {
                    Image(systemName: "paperplane.fill")
                        .frame(width: 28, height: 28)
                }
                    .buttonStyle(.plain)
                    .font(.system(size: 13, weight: .black, design: .rounded))
                    .foregroundStyle(viewModel.canSendChat ? MacadeColor.warning : MacadeColor.inkMuted)
                    .disabled(!viewModel.canSendChat)
                    .help("Send")
            }
            .padding(.horizontal, MacadeSpacing.medium)
            .frame(height: 50)
        }
        .onAppear {
            isChatFocused = true
        }
        .background(MacadeColor.sidebar.opacity(0.42))
        .overlay(alignment: .top) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }

    private var mentionSuggestions: [FightcadeChannelUser] {
        viewModel.chatMentionSuggestions(in: channel)
    }

    private func sendChatKeepingFocus() {
        viewModel.sendChat()
        DispatchQueue.main.async {
            isChatFocused = true
        }
    }
}

private struct MentionSuggestionStrip: View {
    let suggestions: [FightcadeChannelUser]
    let selectedUserID: FightcadeChannelUser.ID?
    let complete: (FightcadeChannelUser) -> Void

    var body: some View {
        ScrollView(.horizontal, showsIndicators: false) {
            HStack(spacing: MacadeSpacing.xSmall) {
                ForEach(suggestions) { user in
                    let isSelected = user.id == selectedUserID

                    Button {
                        complete(user)
                    } label: {
                        HStack(spacing: 6) {
                            PlayerAvatarView(
                                url: user.avatarURL,
                                fallbackName: user.name,
                                size: 18,
                                borderColor: MacadeColor.neonCyan
                            )

                            Text("@\(user.name)")
                                .font(.system(size: 12, weight: .black, design: .rounded))
                                .lineLimit(1)
                        }
                        .foregroundStyle(isSelected ? MacadeColor.midnight : MacadeColor.ink)
                        .padding(.horizontal, 8)
                        .frame(height: 28)
                        .background(isSelected ? MacadeColor.warning : MacadeColor.panel.opacity(0.92), in: Capsule())
                        .overlay(Capsule().stroke(isSelected ? .white.opacity(0.45) : .clear, lineWidth: 1))
                    }
                    .buttonStyle(.plain)
                }
            }
            .padding(.horizontal, MacadeSpacing.medium)
            .padding(.vertical, 6)
        }
    }
}
