import SwiftUI

struct ChannelTVView: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var readySessionID: UUID?

    var body: some View {
        if let channel = viewModel.channelTVCurrentChannel {
            VStack(spacing: 0) {
                if viewModel.selectedChannelTVSession == nil {
                    tvHeader(channel: channel)
                    ChannelErrorBanner(viewModel: viewModel)
                }

                if let session = viewModel.selectedChannelTVSession {
                    tvSessionPanel(session: session, channel: channel)
                } else {
                    staticScreen(channel: channel)
                }
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .background(.black.opacity(0.82))
            .overlay(alignment: .bottom) {
                ChannelTVControlDeck(viewModel: viewModel)
                    .padding(.horizontal, MacadeSpacing.medium)
                    .padding(.bottom, MacadeSpacing.medium)
            }
            .task(id: channel.id) {
                viewModel.ensureChannelTVRunning(for: channel)
            }
        } else {
            ContentUnavailableView("No Joined Channels", systemImage: "tv")
                .foregroundStyle(MacadeColor.inkMuted)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .background(.clear)
        }
    }

    private func tvSessionPanel(session: FightcadeEmbeddedSession, channel: FightcadeChannel) -> some View {
        EmbeddedEmulatorPanel(
            session: session,
            isChannelChatVisible: viewModel.isShowingChannelChat,
            channelChatOverlay: AnyView(ChannelChatView(
                channel: channel,
                viewModel: viewModel,
                showsPreview: false,
                backgroundOpacity: 0.5
            )),
            videoOverlay: shouldShowStatic(for: session) ? AnyView(staticScreen(channel: channel).allowsHitTesting(false)) : nil,
            onToggleChannelChat: viewModel.toggleChannelChat,
            onMatchEnded: {},
            onStop: viewModel.stopChannelTV
        )
        .task(id: session.id) {
            await waitForTVVideoReady(session)
        }
    }

    private func tvHeader(channel: FightcadeChannel) -> some View {
        HStack(spacing: MacadeSpacing.small) {
            Image(systemName: "tv.fill")
                .font(.system(size: 13, weight: .black))
                .foregroundStyle(MacadeColor.warning)

            Text("FIGHTCADE TV")
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

    private func staticScreen(channel: FightcadeChannel) -> some View {
        ChannelTVStaticScreen(
            channel: channel,
            channelPositionText: viewModel.channelTVChannelPositionText,
            statusText: viewModel.channelTVStatusText ?? "Finding spectatable matches..."
        )
    }

    private func shouldShowStatic(for session: FightcadeEmbeddedSession) -> Bool {
        readySessionID != session.id
    }

    private func waitForTVVideoReady(_ session: FightcadeEmbeddedSession) async {
        readySessionID = nil
        while !Task.isCancelled, session.isActive {
            switch session.videoStream.withNextFrame(after: 0, { _ in true }) {
            case .frame:
                readySessionID = session.id
                return
            case .duplicate, .missing:
                break
            }

            try? await Task.sleep(for: .milliseconds(120))
        }
    }
}

private struct ChannelTVControlDeck: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel
    @State private var settings = FightcadeFBNeoSettings.defaults
    @State private var settingsStatus: String?

    private let settingsStore = FightcadeFBNeoSettingsStore()

    var body: some View {
        ViewThatFits(in: .horizontal) {
            controlsLayout(axis: .horizontal)
            controlsLayout(axis: .vertical)
        }
        .padding(.horizontal, MacadeSpacing.small)
        .padding(.vertical, MacadeSpacing.xSmall)
        .background(.black.opacity(0.72), in: RoundedRectangle(cornerRadius: 18))
        .overlay(RoundedRectangle(cornerRadius: 18).stroke(MacadeColor.warning.opacity(0.32), lineWidth: 1))
        .shadow(color: .black.opacity(0.35), radius: 18)
        .onAppear(perform: reloadSettings)
        .onReceive(NotificationCenter.default.publisher(for: .fightcadeFBNeoSettingsDidChange)) { _ in
            reloadSettings()
        }
    }

    @ViewBuilder
    private func controlsLayout(axis: Axis) -> some View {
        if axis == .horizontal {
            HStack(spacing: MacadeSpacing.small) {
                channelTuner
                divider
                matchTuner
                Spacer(minLength: MacadeSpacing.small)
                volumeControl
                stopButton
            }
        } else {
            VStack(alignment: .leading, spacing: MacadeSpacing.xSmall) {
                channelTuner
                matchTuner
                HStack(spacing: MacadeSpacing.small) {
                    volumeControl
                    Spacer(minLength: MacadeSpacing.small)
                    stopButton
                }
            }
        }
    }

    private var channelTuner: some View {
        tuner(
            label: "CH",
            value: viewModel.channelTVChannelPositionText ?? "--",
            detail: viewModel.channelTVCurrentChannel?.title ?? "No joined rooms",
            canTune: viewModel.canTuneFightcadeTVChannel,
            previous: viewModel.showPreviousFightcadeTVChannel,
            next: viewModel.showNextFightcadeTVChannel
        )
    }

    private var matchTuner: some View {
        tuner(
            label: "MATCH",
            value: viewModel.channelTVMatchPositionText ?? "--",
            detail: viewModel.channelTVCurrentMatchTitle ?? "No spectatable matches",
            canTune: viewModel.canTuneFightcadeTVMatch,
            previous: viewModel.showPreviousFightcadeTVMatch,
            next: viewModel.showNextFightcadeTVMatch
        )
    }

    private func tuner(
        label: String,
        value: String,
        detail: String,
        canTune: Bool,
        previous: @escaping () -> Void,
        next: @escaping () -> Void
    ) -> some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Button(action: previous) {
                Image(systemName: "chevron.left")
                    .frame(width: 24, height: 24)
            }
            .buttonStyle(.plain)
            .disabled(!canTune)

            VStack(alignment: .leading, spacing: 1) {
                Text("\(label) \(value)")
                    .font(.system(size: 10, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.warning)
                Text(detail)
                    .font(.system(size: 11, weight: .black, design: .rounded))
                    .foregroundStyle(MacadeColor.ink)
                    .lineLimit(1)
            }
            .frame(width: label == "CH" ? 150 : 170, alignment: .leading)

            Button(action: next) {
                Image(systemName: "chevron.right")
                    .frame(width: 24, height: 24)
            }
            .buttonStyle(.plain)
            .disabled(!canTune)
        }
        .foregroundStyle(MacadeColor.inkMuted)
    }

    private var volumeControl: some View {
        HStack(spacing: MacadeSpacing.xSmall) {
            Button {
                saveVolume(settings.volume == 0 ? 50 : 0)
            } label: {
                Image(systemName: settings.volume == 0 ? "speaker.slash.fill" : "speaker.wave.2.fill")
                    .frame(width: 24, height: 24)
            }
            .buttonStyle(.plain)

            Slider(
                value: Binding(
                    get: { Double(settings.volume) },
                    set: { saveVolume(Int($0.rounded())) }
                ),
                in: 0...100,
                step: 5
            )
            .frame(width: 110)

            Text("\(settings.volume)%")
                .font(.system(size: 10, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.inkMuted)
                .frame(width: 34, alignment: .trailing)
        }
        .help(settingsStatus ?? "Fightcade TV volume")
    }

    private var stopButton: some View {
        Button {
            viewModel.stopChannelTV()
        } label: {
            Label("Stop", systemImage: "stop.fill")
                .font(.system(size: 11, weight: .black, design: .monospaced))
        }
        .buttonStyle(.plain)
        .foregroundStyle(MacadeColor.inkMuted)
        .frame(height: 28)
        .padding(.horizontal, MacadeSpacing.xSmall)
        .background(MacadeColor.panel.opacity(0.76), in: Capsule())
    }

    private var divider: some View {
        Rectangle()
            .fill(MacadeColor.divider.opacity(0.7))
            .frame(width: 1, height: 28)
    }

    private func saveVolume(_ value: Int) {
        var next = settings
        next.volume = max(0, min(100, value))
        next = next.normalized()

        do {
            try settingsStore.save(next)
            settings = next
            viewModel.selectedChannelTVSession?.inputClient.setVolume(next.volume)
            settingsStatus = nil
            NotificationCenter.default.post(name: .fightcadeFBNeoSettingsDidChange, object: nil)
        } catch {
            settingsStatus = "Save failed: \(error.localizedDescription)"
        }
    }

    private func reloadSettings() {
        do {
            settings = try settingsStore.load()
            settingsStatus = nil
        } catch {
            settings = FightcadeFBNeoSettings.defaults
            settingsStatus = "Using default settings"
        }
    }
}

private struct ChannelTVStaticScreen: View {
    let channel: FightcadeChannel
    let channelPositionText: String?
    let statusText: String

    var body: some View {
        ZStack {
            Color.black
            ChannelTVStaticNoise()
            scanlines

            LinearGradient(
                colors: [.black.opacity(0.28), MacadeColor.deepPlum.opacity(0.28), .black.opacity(0.42)],
                startPoint: .topLeading,
                endPoint: .bottomTrailing
            )

            VStack(spacing: MacadeSpacing.medium) {
                Text("FIGHTCADE TV")
                    .font(.system(size: 13, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.warning)
                    .tracking(3)

                VStack(spacing: MacadeSpacing.xSmall) {
                    Text("TUNING")
                        .font(.system(size: 42, weight: .black, design: .monospaced))
                        .foregroundStyle(.white)
                        .shadow(color: MacadeColor.neonCyan.opacity(0.45), radius: 7)

                    Text(channel.title.uppercased())
                        .font(.system(size: 18, weight: .black, design: .rounded))
                        .foregroundStyle(MacadeColor.ink)
                        .multilineTextAlignment(.center)
                        .lineLimit(2)
                }

                Text(statusText.uppercased())
                    .font(.system(size: 11, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.inkMuted)
                    .multilineTextAlignment(.center)
                    .lineLimit(2)

                if let channelPositionText {
                    Text("CH \(channelPositionText)")
                        .font(.system(size: 12, weight: .black, design: .monospaced))
                        .foregroundStyle(MacadeColor.neonCyan)
                        .padding(.horizontal, 12)
                        .frame(height: 26)
                        .background(.black.opacity(0.56), in: Capsule())
                        .overlay(Capsule().stroke(MacadeColor.neonCyan.opacity(0.32), lineWidth: 1))
                }
            }
            .padding(28)
            .frame(maxWidth: 560)
            .background(.black.opacity(0.62), in: RoundedRectangle(cornerRadius: 22))
            .overlay(RoundedRectangle(cornerRadius: 22).stroke(.white.opacity(0.18), lineWidth: 1))
            .shadow(color: MacadeColor.warning.opacity(0.14), radius: 32)
            .padding(24)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
    }

    private var scanlines: some View {
        VStack(spacing: 2) {
            ForEach(0..<80, id: \.self) { _ in
                Rectangle()
                    .fill(.black.opacity(0.22))
                    .frame(height: 1)
                Spacer(minLength: 1)
            }
        }
        .allowsHitTesting(false)
    }
}

private struct ChannelTVStaticNoise: View {
    var body: some View {
        TimelineView(.animation) { timeline in
            Canvas { context, size in
                let blockSize = CGFloat(5)
                let columns = max(1, Int(size.width / blockSize))
                let rows = max(1, Int(size.height / blockSize))
                let tick = Int(timeline.date.timeIntervalSinceReferenceDate * 18)

                for row in 0..<rows {
                    for column in 0..<columns {
                        let value = abs((row * 73 + column * 151 + tick * 199) % 255)
                        let white = 0.12 + Double(value) / 255.0 * 0.7
                        let opacity = 0.16 + Double((value + tick) % 35) / 100.0
                        let rect = CGRect(
                            x: CGFloat(column) * blockSize,
                            y: CGFloat(row) * blockSize,
                            width: blockSize + 1,
                            height: blockSize + 1
                        )
                        context.fill(Path(rect), with: .color(Color(.sRGB, white: white, opacity: opacity)))
                    }
                }

                for line in stride(from: 0, to: Int(size.height), by: 37) {
                    let rect = CGRect(x: 0, y: CGFloat((line + tick * 3) % max(1, Int(size.height))), width: size.width, height: 2)
                    context.fill(Path(rect), with: .color(.white.opacity(0.22)))
                }
            }
        }
    }
}
