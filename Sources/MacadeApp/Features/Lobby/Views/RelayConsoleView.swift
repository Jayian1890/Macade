import SwiftUI

struct RelayConsoleView: View {
    @Environment(\.dismiss) private var dismiss

    let activeSession: FightcadeEmbeddedSession?

    @State private var profile = MacadeRelayProfileStore().load()
    @State private var savedProfile = MacadeRelayProfileStore().load()
    @State private var selectedKey: MacadeRelayKey = .equals
    @State private var isCapturingFrame = false
    @State private var isRecordingSequence = false
    @State private var recorder = RelayConsoleRecorder()
    @State private var statusMessage: String?
    @State private var testTask: Task<Void, Never>?
    @State private var controllerPreferences = MacadeControllerPreferencesStore().load()

    private let store = MacadeRelayProfileStore()

    var body: some View {
        HStack(spacing: 0) {
            laneList

            Divider()
                .overlay(MacadeColor.divider)

            VStack(spacing: 0) {
                ScrollView {
                    laneEditor
                        .padding(MacadeSpacing.large)
                        .frame(maxWidth: .infinity, alignment: .topLeading)
                }
                .scrollContentBackground(.hidden)

                footer
            }
        }
        .frame(width: 860, height: 660)
        .background(MacadeBackground())
        .foregroundStyle(MacadeColor.ink)
        .tint(MacadeColor.neonCyan)
        .preferredColorScheme(.dark)
        .colorScheme(.dark)
        .onAppear(perform: loadProfile)
        .onDisappear {
            testTask?.cancel()
            cancelSequenceRecording(updateStatus: false)
        }
    }

    private var laneList: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            VStack(alignment: .leading, spacing: 6) {
                Text("Relay")
                    .font(.system(size: 28, weight: .black, design: .rounded))
                Text("Embedded relay lanes")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
            }
            .padding(.horizontal, MacadeSpacing.medium)
            .padding(.top, MacadeSpacing.large)

            ForEach(profile.lanes) { lane in
                Button {
                    cancelSequenceRecording(updateStatus: false)
                    selectedKey = lane.key
                    isCapturingFrame = false
                } label: {
                    HStack(spacing: MacadeSpacing.small) {
                        Text(lane.key.label)
                            .font(.system(size: 18, weight: .black, design: .monospaced))
                            .frame(width: 34, height: 34)
                            .background(lane.isRunnable ? MacadeColor.warning : MacadeColor.panelStrong, in: RoundedRectangle(cornerRadius: 9))
                            .foregroundStyle(lane.isRunnable ? MacadeColor.midnight : MacadeColor.inkMuted)

                        VStack(alignment: .leading, spacing: 3) {
                            Text(lane.title)
                                .font(MacadeTypography.body)
                                .lineLimit(1)
                            Text(laneSummary(lane))
                                .font(MacadeTypography.caption)
                                .foregroundStyle(MacadeColor.inkMuted)
                        }

                        Spacer()
                    }
                    .padding(MacadeSpacing.small)
                    .background(selectedKey == lane.key ? MacadeColor.panelStrong : .clear, in: RoundedRectangle(cornerRadius: 14))
                    .overlay(RoundedRectangle(cornerRadius: 14).stroke(selectedKey == lane.key ? MacadeColor.neonCyan.opacity(0.5) : .clear, lineWidth: 1))
                }
                .buttonStyle(.plain)
            }

            Spacer()

            Text("Use the same hidden chat command to reopen this console. Lanes are fixed to top-row =, -, 0, 9, and 8.")
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
                .fixedSize(horizontal: false, vertical: true)
                .padding(MacadeSpacing.medium)
        }
        .padding(MacadeSpacing.medium)
        .frame(width: 260)
        .background(MacadeColor.sidebar.opacity(0.62))
    }

    private var laneEditor: some View {
        let lane = selectedLane

        return VStack(alignment: .leading, spacing: MacadeSpacing.large) {
            HStack(alignment: .top, spacing: MacadeSpacing.medium) {
                Text(lane.key.label)
                    .font(.system(size: 34, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.midnight)
                    .frame(width: 64, height: 64)
                    .background(MacadeColor.warning, in: RoundedRectangle(cornerRadius: 16))

                VStack(alignment: .leading, spacing: 6) {
                    Text("Relay Lane")
                        .font(MacadeTypography.title)
                    Text("This fixed top-row key runs the lane while embedded gameplay has focus. Empty lanes pass through to the emulator.")
                        .font(MacadeTypography.caption)
                        .foregroundStyle(MacadeColor.inkMuted)
                        .fixedSize(horizontal: false, vertical: true)
                }

                Spacer()

                Toggle("Enabled", isOn: binding(\.isEnabled))
                    .toggleStyle(.switch)
            }

            SettingsSection(title: "Lane", subtitle: "Name and test this fixed relay lane.") {
                TextField("Lane name", text: binding(\.title))
                    .textFieldStyle(.roundedBorder)

                HStack(spacing: MacadeSpacing.small) {
                    Button("Test Lane") { testSelectedLane() }
                        .disabled(activeSession?.isActive != true || !lane.isRunnable)

                    Button("Clear Lane") { clearSelectedLane() }
                        .foregroundStyle(MacadeColor.warning)
                        .disabled(lane.frames.isEmpty && !lane.isEnabled)
                }

                Text(activeSession?.isActive == true ? "Test sends directly to the active embedded emulator." : "Launch an embedded game to test relay output.")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
            }

            SettingsSection(title: "Frames", subtitle: "Record a full timeline, or capture one chord frame manually.") {
                HStack(spacing: MacadeSpacing.small) {
                    Button(isRecordingSequence ? "Stop Recording" : "Start Recording") {
                        if isRecordingSequence {
                            stopSequenceRecording()
                        } else {
                            startSequenceRecording()
                        }
                    }
                    .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))

                    Button("Cancel Recording") { cancelSequenceRecording() }
                        .disabled(!isRecordingSequence)

                    Button(isCapturingFrame ? "Capturing..." : "Capture Frame") {
                        controllerPreferences = MacadeControllerPreferencesStore().load()
                        isRecordingSequence = false
                        isCapturingFrame = true
                        statusMessage = "Hold one or more keys together, then release to add a frame."
                    }
                    .overlay {
                        RelayFrameCaptureView(
                            isActive: isCapturingFrame,
                            controllerPreferences: controllerPreferences,
                            onComplete: addCapturedFrame,
                            onCancel: cancelCapture
                        )
                        .allowsHitTesting(false)
                    }

                    Button("Cancel Capture") { cancelCapture() }
                        .disabled(!isCapturingFrame)
                }

                if isRecordingSequence {
                    RelaySequenceCaptureHint(isPassthroughEnabled: activeSession?.isActive == true)
                }

                if isCapturingFrame {
                    RelayCaptureHint()
                }

                if lane.frames.isEmpty {
                    ContentUnavailableView("No Frames", systemImage: "record.circle", description: Text("Record a timeline or capture one frame to build this lane."))
                        .foregroundStyle(MacadeColor.inkMuted)
                        .frame(maxWidth: .infinity, minHeight: 180)
                } else {
                    VStack(spacing: MacadeSpacing.small) {
                        ForEach(Array(lane.frames.enumerated()), id: \.element.id) { index, frame in
                            RelayFrameRow(
                                index: index,
                                frame: frame,
                                canMoveUp: index > 0,
                                canMoveDown: index < lane.frames.count - 1,
                                updateHold: updateFrame(index, update: { frame, value in frame.holdMilliseconds = value }),
                                updateGap: updateFrame(index, update: { frame, value in frame.gapMilliseconds = value }),
                                moveUp: { moveFrame(index, offset: -1) },
                                moveDown: { moveFrame(index, offset: 1) },
                                delete: { deleteFrame(index) }
                            )
                        }
                    }
                }
            }
        }
    }

    private var footer: some View {
        HStack(spacing: MacadeSpacing.medium) {
            if let statusMessage {
                Text(statusMessage)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .lineLimit(2)
            }

            Spacer()

            if hasUnsavedChanges {
                Text("Unsaved changes")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.warning)
            }

            Button("Reset All") { resetAll() }
                .buttonStyle(.borderless)
                .foregroundStyle(MacadeColor.warning)

            Button("Discard") { discardChanges() }
                .buttonStyle(.borderless)
                .foregroundStyle(MacadeColor.inkMuted)
                .disabled(!hasUnsavedChanges)

            Button("Save") { saveProfile() }
                .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
                .disabled(!hasUnsavedChanges)

            Button("Close") { dismiss() }
                .buttonStyle(.borderless)
                .foregroundStyle(MacadeColor.inkMuted)
        }
        .padding(MacadeSpacing.medium)
        .background(MacadeColor.sidebar.opacity(0.72))
        .overlay(alignment: .top) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }

    private var selectedLaneIndex: Int {
        profile.lanes.firstIndex { $0.key == selectedKey } ?? 0
    }

    private var selectedLane: MacadeRelayLane {
        profile.lanes[selectedLaneIndex]
    }

    private var hasUnsavedChanges: Bool {
        profile.normalized() != savedProfile.normalized()
    }

    private func binding<Value>(_ keyPath: WritableKeyPath<MacadeRelayLane, Value>) -> Binding<Value> {
        Binding(
            get: { selectedLane[keyPath: keyPath] },
            set: { value in updateSelectedLane { $0[keyPath: keyPath] = value } }
        )
    }

    private func loadProfile() {
        let loaded = store.load()
        profile = loaded
        savedProfile = loaded
        selectedKey = loaded.lanes.first?.key ?? .equals
    }

    private func saveProfile() {
        let normalized = profile.normalized()
        profile = normalized
        savedProfile = normalized
        store.save(normalized)
        statusMessage = "Relay saved."
    }

    private func discardChanges() {
        profile = savedProfile
        isCapturingFrame = false
        cancelSequenceRecording(updateStatus: false)
        statusMessage = nil
    }

    private func resetAll() {
        profile = .defaults
        selectedKey = .equals
        isCapturingFrame = false
        cancelSequenceRecording(updateStatus: false)
        statusMessage = "Relay reset. Save to apply."
    }

    private func updateSelectedLane(_ update: (inout MacadeRelayLane) -> Void) {
        guard profile.lanes.indices.contains(selectedLaneIndex) else { return }
        update(&profile.lanes[selectedLaneIndex])
    }

    private func clearSelectedLane() {
        updateSelectedLane { lane in
            lane.title = "Lane \(lane.key.label)"
            lane.isEnabled = false
            lane.frames = []
        }
        statusMessage = "Cleared lane \(selectedKey.label). Save to apply."
    }

    private func addCapturedFrame(_ nodes: [MacadeRelayNode]) {
        let uniqueNodes = unique(nodes: nodes)
        guard !uniqueNodes.isEmpty else { return }
        updateSelectedLane { lane in
            lane.isEnabled = true
            lane.frames.append(MacadeRelayFrame(nodes: uniqueNodes))
        }
        isCapturingFrame = false
        statusMessage = "Added \(uniqueNodes.map(\.label).joined(separator: " + "))."
    }

    private func startSequenceRecording() {
        controllerPreferences = MacadeControllerPreferencesStore().load()
        isCapturingFrame = false
        recorder.start(controllerPreferences: controllerPreferences, activeSession: activeSession) {
            isRecordingSequence = false
            statusMessage = "Recording cancelled."
        }
        isRecordingSequence = true
        statusMessage = activeSession?.isActive == true
            ? "Recording lane \(selectedKey.label). Inputs are also sent to the active embedded emulator."
            : "Recording lane \(selectedKey.label). Launch an embedded game to record while sending inputs."
    }

    private func stopSequenceRecording() {
        guard isRecordingSequence else { return }
        finishSequenceRecording(recorder.stop())
    }

    private func finishSequenceRecording(_ frames: [MacadeRelayFrame]) {
        isRecordingSequence = false
        guard !frames.isEmpty else {
            statusMessage = "No input recorded."
            return
        }

        let limitedFrames = Array(frames.prefix(MacadeRelayProfile.maximumFrames))
        updateSelectedLane { lane in
            lane.isEnabled = true
            lane.frames = limitedFrames
        }
        if frames.count > limitedFrames.count {
            statusMessage = "Recorded \(limitedFrames.count) frames; frame limit reached. Save to apply."
        } else {
            statusMessage = "Recorded \(limitedFrames.count) frame\(limitedFrames.count == 1 ? "" : "s") for lane \(selectedKey.label). Save to apply."
        }
    }

    private func cancelSequenceRecording(updateStatus: Bool = true) {
        guard isRecordingSequence || recorder.isActive else { return }
        recorder.cancel()
        isRecordingSequence = false
        if updateStatus {
            statusMessage = "Recording cancelled."
        }
    }

    private func cancelCapture() {
        isCapturingFrame = false
        statusMessage = nil
    }

    private func updateFrame(_ index: Int, update: @escaping (inout MacadeRelayFrame, Int) -> Void) -> (Int) -> Void {
        { value in
            updateSelectedLane { lane in
                guard lane.frames.indices.contains(index) else { return }
                update(&lane.frames[index], value)
            }
        }
    }

    private func moveFrame(_ index: Int, offset: Int) {
        updateSelectedLane { lane in
            let destination = index + offset
            guard lane.frames.indices.contains(index), lane.frames.indices.contains(destination) else { return }
            let frame = lane.frames.remove(at: index)
            lane.frames.insert(frame, at: destination)
        }
    }

    private func deleteFrame(_ index: Int) {
        updateSelectedLane { lane in
            guard lane.frames.indices.contains(index) else { return }
            lane.frames.remove(at: index)
        }
    }

    private func testSelectedLane() {
        guard let activeSession, activeSession.isActive else { return }
        let normalizedLane = MacadeRelayProfile(lanes: [selectedLane]).normalized().lane(for: selectedKey) ?? selectedLane
        guard normalizedLane.isRunnable else { return }

        testTask?.cancel()
        statusMessage = "Running \(normalizedLane.title)..."
        testTask = Task { @MainActor in
            await MacadeRelayRunner.run(normalizedLane, using: activeSession.inputClient)
            statusMessage = "Relay sent to embedded emulator."
        }
    }

    private func laneSummary(_ lane: MacadeRelayLane) -> String {
        if !lane.isRunnable {
            return lane.frames.isEmpty ? "Empty" : "Disabled"
        }
        return "\(lane.frames.count) frame\(lane.frames.count == 1 ? "" : "s")"
    }

    private func unique(nodes: [MacadeRelayNode]) -> [MacadeRelayNode] {
        var seen = Set<Int32>()
        return nodes.filter { seen.insert($0.scancode).inserted }
    }
}

#Preview {
    RelayConsoleView(activeSession: nil)
}
