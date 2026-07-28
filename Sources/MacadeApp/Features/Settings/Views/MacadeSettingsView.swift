import AppKit
import SwiftUI

struct MacadeSettingsView: View {
    @Environment(\.dismiss) private var dismiss
    @State private var viewModel: MacadeSettingsViewModel
    private let showsCancelButton: Bool

    init(
        initialSection: MacadeSettingsViewModel.Section = .general,
        showsCancelButton: Bool = false
    ) {
        _viewModel = State(initialValue: MacadeSettingsViewModel(selectedSection: initialSection))
        self.showsCancelButton = showsCancelButton
    }

    var body: some View {
        @Bindable var viewModel = viewModel

        HStack(spacing: 0) {
            sidebar(selection: $viewModel.selectedSection)

            Divider()
                .overlay(MacadeColor.divider)

            VStack(spacing: 0) {
                ScrollView {
                    content(for: viewModel.selectedSection)
                        .padding(MacadeSpacing.large)
                        .frame(maxWidth: .infinity, alignment: .topLeading)
                }
                .scrollContentBackground(.hidden)

                footer
            }
        }
        .frame(width: 760, height: 620)
        .background(MacadeBackground())
        .foregroundStyle(MacadeColor.ink)
        .tint(MacadeColor.neonCyan)
        .preferredColorScheme(.dark)
        .colorScheme(.dark)
        .task {
            if !viewModel.isLoaded {
                viewModel.load()
            }
        }
    }

    private func sidebar(selection: Binding<MacadeSettingsViewModel.Section>) -> some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            Text("Settings")
                .font(.system(size: 26, weight: .black, design: .rounded))
                .padding(.horizontal, MacadeSpacing.medium)
                .padding(.top, MacadeSpacing.large)

            ForEach(MacadeSettingsViewModel.Section.allCases) { section in
                Button {
                    selection.wrappedValue = section
                } label: {
                    HStack(spacing: MacadeSpacing.small) {
                        Image(systemName: section.symbolName)
                            .frame(width: 18)
                        Text(section.title)
                        Spacer()
                    }
                    .font(MacadeTypography.body)
                    .foregroundStyle(selection.wrappedValue == section ? MacadeColor.ink : MacadeColor.inkMuted)
                    .padding(.horizontal, MacadeSpacing.medium)
                    .padding(.vertical, MacadeSpacing.small)
                    .background(
                        selection.wrappedValue == section ? MacadeColor.panelStrong : .clear,
                        in: RoundedRectangle(cornerRadius: 12)
                    )
                }
                .buttonStyle(.plain)
            }

            Spacer()
        }
        .padding(MacadeSpacing.medium)
        .frame(width: 220)
        .background(MacadeColor.sidebar.opacity(0.62))
    }

    @ViewBuilder
    private func content(for section: MacadeSettingsViewModel.Section) -> some View {
        switch section {
        case .general:
            GeneralSettingsSection(viewModel: viewModel)
        case .connection:
            ConnectionSettingsSection(viewModel: viewModel)
        case .emulator:
            EmulatorSettingsSection(viewModel: viewModel)
        case .controllers:
            ControllerSettingsSection(viewModel: viewModel)
        case .diagnostics:
            DiagnosticsSettingsSection(viewModel: viewModel)
        case .advanced:
            AdvancedSettingsSection(viewModel: viewModel)
        }
    }

    private var footer: some View {
        HStack(spacing: MacadeSpacing.medium) {
            if let statusMessage = viewModel.statusMessage {
                Text(statusMessage)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .lineLimit(2)
            }

            Spacer()

            if viewModel.hasUnsavedChanges {
                Text("Unsaved changes")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.warning)
            }

            if showsCancelButton {
                Button("Cancel") {
                    viewModel.discardChanges()
                    dismiss()
                }
                .buttonStyle(.borderless)
                .foregroundStyle(MacadeColor.inkMuted)
            } else {
                Button("Discard") {
                    viewModel.discardChanges()
                }
                .buttonStyle(.borderless)
                .foregroundStyle(MacadeColor.inkMuted)
                .disabled(!viewModel.hasUnsavedChanges)
            }

            Button("Save") {
                viewModel.save()
            }
            .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
            .disabled(!viewModel.isLoaded || !viewModel.hasUnsavedChanges)
        }
        .padding(MacadeSpacing.medium)
        .background(MacadeColor.sidebar.opacity(0.72))
        .overlay(alignment: .top) {
            Rectangle()
                .fill(MacadeColor.divider)
                .frame(height: 1)
        }
    }
}

private struct GeneralSettingsSection: View {
    let viewModel: MacadeSettingsViewModel

    var body: some View {
        SettingsSection(title: "General", subtitle: "Macade keeps Fightcade compatibility while using a native macOS interface.") {
            SettingsInfoRow(title: "Emulator settings", detail: "Video, audio, gameplay, and controller changes are applied the next time FBNeo starts.")
            SettingsInfoRow(title: "Runtime", detail: "Macade uses its bundled native FBNeo runtime and writes user settings to Application Support.")
            SettingsInfoRow(title: "Privacy", detail: "Diagnostics are off by default. Chat text is never logged unless you enable it.")
        }
    }
}

private struct ConnectionSettingsSection: View {
    @Bindable var viewModel: MacadeSettingsViewModel

    var body: some View {
        SettingsSection(title: "Connection", subtitle: "Control how Macade reports your network type to Fightcade.") {
            Toggle("Report this Mac as using Ethernet", isOn: $viewModel.forceWiredConnectionStatus)
            Text("Use this only when Fightcade incorrectly detects Wi-Fi. This applies to the next lobby status update or reconnect.")
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
        }
    }
}

private struct EmulatorSettingsSection: View {
    @Bindable var viewModel: MacadeSettingsViewModel

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.large) {
            SettingsSection(title: "Video", subtitle: "Applies the next time FBNeo starts.") {
                Toggle("Stretch game image to fit the window", isOn: $viewModel.fbneoSettings.stretchToWindow)
                Toggle("Show scanlines", isOn: $viewModel.fbneoSettings.scanlines)
                Toggle("Use software brightness correction", isOn: $viewModel.fbneoSettings.softwareGamma)
                SettingsSliderRow(
                    title: "Brightness correction",
                    valueText: viewModel.fbneoSettings.gamma.formatted(.number.precision(.fractionLength(2))),
                    value: $viewModel.fbneoSettings.gamma,
                    range: 0.5...2.0,
                    step: 0.05
                )
            }

            SettingsSection(title: "Audio", subtitle: "Higher sample rates can use more CPU on older Macs.") {
                SettingsSliderRow(
                    title: "Volume",
                    valueText: "\(viewModel.fbneoSettings.volume)%",
                    value: Binding(
                        get: { Double(viewModel.fbneoSettings.volume) },
                        set: { viewModel.fbneoSettings.volume = Int($0.rounded()) }
                    ),
                    range: 0...100,
                    step: 5
                )

                Picker("Sample rate", selection: $viewModel.fbneoSettings.sampleRate) {
                    Text("44.1 kHz").tag(44_100)
                    Text("48 kHz").tag(48_000)
                    Text("96 kHz").tag(96_000)
                }

                Toggle("Smooth older audio filters", isOn: $viewModel.fbneoSettings.dspFilter)

                Picker("PCM audio smoothing", selection: $viewModel.fbneoSettings.pcmInterpolation) {
                    Text("Off").tag(0)
                    Text("Standard").tag(1)
                    Text("High").tag(3)
                }

                Picker("FM audio smoothing", selection: $viewModel.fbneoSettings.fmInterpolation) {
                    Text("Off").tag(0)
                    Text("Standard").tag(1)
                    Text("High").tag(3)
                }
            }

            SettingsSection(title: "Gameplay", subtitle: "Local emulator preferences only. Online match rules still come from Fightcade.") {
                Toggle("Save high scores", isOn: $viewModel.fbneoSettings.hiscores)
                Stepper(value: $viewModel.fbneoSettings.autoFireRate, in: 1...30) {
                    Text("Auto-fire speed: \(viewModel.fbneoSettings.autoFireRate)")
                }

                Button("Reset Emulator Settings") {
                    viewModel.resetEmulatorSettings()
                }
                .foregroundStyle(MacadeColor.warning)
            }

            SettingsSection(title: "Emulator Folders", subtitle: "FBNeo reads these locations when it starts. Relative paths are inside the runtime folder.") {
                SettingsPathRow(
                    title: "Sample audio folder",
                    help: "Extra audio samples used by some arcade games.",
                    text: $viewModel.fbneoSettings.samplesPath
                )
                SettingsPathRow(
                    title: "High score folder",
                    help: "Where supported games save high score files.",
                    text: $viewModel.fbneoSettings.hiscorePath
                )
                SettingsPathRow(
                    title: "Save data folder",
                    help: "EEPROM and NVRAM files used by games that save machine state.",
                    text: $viewModel.fbneoSettings.eepromPath
                )
                SettingsPathRow(
                    title: "Hard drive image folder",
                    help: "Disk image files required by a small number of arcade systems.",
                    text: $viewModel.fbneoSettings.hddPath
                )
            }
        }
    }
}

private struct ControllerSettingsSection: View {
    @Bindable var viewModel: MacadeSettingsViewModel

    var body: some View {
        SettingsSection(title: "Controllers", subtitle: "Add controller mappings only if a gamepad is not detected correctly.") {
            Text("Paste controller database lines from a trusted mapping source. Macade sends them to FBNeo when a game starts.")
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)

            TextEditor(text: $viewModel.fbneoSettings.controllerMappings)
                .font(.system(size: 12, weight: .regular, design: .monospaced))
                .foregroundStyle(MacadeColor.ink)
                .frame(minHeight: 180)
                .scrollContentBackground(.hidden)
                .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 10))

            Button("Clear Controller Mappings") {
                viewModel.clearControllerMappings()
            }
            .foregroundStyle(MacadeColor.warning)
            .disabled(viewModel.fbneoSettings.controllerMappings.isEmpty)
        }
    }
}

private struct DiagnosticsSettingsSection: View {
    @Bindable var viewModel: MacadeSettingsViewModel

    var body: some View {
        SettingsSection(title: "Privacy & Diagnostics", subtitle: "Use these when troubleshooting connection or lobby problems.") {
            Toggle("Save lobby diagnostic logs", isOn: $viewModel.lobbyDiagnosticsEnabled)

            if viewModel.lobbyDiagnosticsEnabled {
                Toggle("Include chat text in diagnostic logs", isOn: $viewModel.includeLobbyDiagnosticChatBodies)
                Text("Chat logging can include private messages and room conversations. Leave it off unless you are actively debugging a chat issue.")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.warning)
            }

            SettingsInfoRow(title: "Lobby log", detail: viewModel.lobbyDiagnosticsLogPath)
        }
    }
}

private struct AdvancedSettingsSection: View {
    let viewModel: MacadeSettingsViewModel

    var body: some View {
        SettingsSection(title: "Advanced", subtitle: "Useful for support. These paths are shown for transparency and are not required for normal play.") {
            SettingsInfoRow(title: "FBNeo settings file", detail: viewModel.fbneoConfigurationPath)
            SettingsInfoRow(title: "Controller mapping file", detail: viewModel.controllerDatabasePath)

            HStack {
                Button("Reveal Settings File") {
                    reveal(path: viewModel.fbneoConfigurationPath)
                }
                Button("Reveal Controller File") {
                    reveal(path: viewModel.controllerDatabasePath)
                }
            }
        }
    }

    private func reveal(path: String) {
        guard path != "Unavailable" else { return }
        NSWorkspace.shared.activateFileViewerSelecting([URL(fileURLWithPath: path)])
    }
}

private struct SettingsSection<Content: View>: View {
    let title: String
    let subtitle: String
    @ViewBuilder let content: Content

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
            VStack(alignment: .leading, spacing: 4) {
                Text(title)
                    .font(MacadeTypography.title)
                Text(subtitle)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
            }

            VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                content
            }
            .padding(MacadeSpacing.medium)
            .frame(maxWidth: .infinity, alignment: .leading)
            .background(MacadeColor.panel.opacity(0.58), in: RoundedRectangle(cornerRadius: 16))
            .overlay(
                RoundedRectangle(cornerRadius: 16)
                    .stroke(MacadeColor.stroke, lineWidth: 1)
            )
        }
    }
}

private struct SettingsInfoRow: View {
    let title: String
    let detail: String

    var body: some View {
        VStack(alignment: .leading, spacing: 4) {
            Text(title)
                .font(MacadeTypography.headline)
            Text(detail)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
                .textSelection(.enabled)
        }
    }
}

private struct SettingsPathRow: View {
    let title: String
    let help: String
    @Binding var text: String

    var body: some View {
        VStack(alignment: .leading, spacing: 6) {
            Text(title)
                .font(MacadeTypography.headline)
            TextField(title, text: $text)
                .textFieldStyle(.roundedBorder)
                .font(.system(size: 12, weight: .regular, design: .monospaced))
            Text(help)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
        }
    }
}

private struct SettingsSliderRow: View {
    let title: String
    let valueText: String
    @Binding var value: Double
    let range: ClosedRange<Double>
    let step: Double

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            HStack {
                Text(title)
                Spacer()
                Text(valueText)
                    .foregroundStyle(MacadeColor.inkMuted)
            }
            Slider(value: $value, in: range, step: step)
        }
    }
}

#Preview {
    MacadeSettingsView()
}
