import AppKit
import SwiftUI

struct ControllerSettingsSection: View {
    @Bindable var viewModel: MacadeSettingsViewModel
    @State private var capturingAction: ControllerAction?

    private let columns = [GridItem(.adaptive(minimum: 250), spacing: MacadeSpacing.medium)]

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.large) {
            SettingsSection(
                title: "Controllers",
                subtitle: "Map Macade's embedded keyboard controls and provide SDL mappings for gamepads. Save before launching FBNeo."
            ) {
                LazyVGrid(columns: columns, alignment: .leading, spacing: MacadeSpacing.medium) {
                    ControllerSummaryCard(
                        symbolName: "keyboard",
                        title: "Keyboard Remap",
                        detail: "Choose the physical keys you want to press. Macade translates them to FBNeo's Fightcade-compatible defaults."
                    )
                    ControllerSummaryCard(
                        symbolName: "gamecontroller.fill",
                        title: "Gamepad Support",
                        detail: "Most controllers work automatically. Add SDL database lines only when a pad is detected incorrectly."
                    )
                    ControllerSummaryCard(
                        symbolName: "arrow.counterclockwise.circle.fill",
                        title: "Fast Recovery",
                        detail: "Reset one action or restore the whole arcade layout without touching emulator video/audio settings."
                    )
                }
            }

            SettingsSection(title: "Keyboard Bindings", subtitle: "Click Set, press a key, then save. Duplicate keys are moved to the newest action.") {
                VStack(alignment: .leading, spacing: MacadeSpacing.medium) {
                    ControllerActionGroup(
                        title: "Movement",
                        actions: [.up, .left, .down, .right],
                        preferences: viewModel.controllerPreferences,
                        capturingAction: $capturingAction,
                        setBinding: viewModel.setControllerBinding,
                        resetBinding: viewModel.resetControllerBinding
                    )

                    ControllerActionGroup(
                        title: "Arcade Buttons",
                        actions: [.button1, .button2, .button3, .button4, .button5, .button6],
                        preferences: viewModel.controllerPreferences,
                        capturingAction: $capturingAction,
                        setBinding: viewModel.setControllerBinding,
                        resetBinding: viewModel.resetControllerBinding
                    )

                    ControllerActionGroup(
                        title: "System",
                        actions: [.start, .coin],
                        preferences: viewModel.controllerPreferences,
                        capturingAction: $capturingAction,
                        setBinding: viewModel.setControllerBinding,
                        resetBinding: viewModel.resetControllerBinding
                    )

                    HStack {
                        Button("Reset All Keyboard Bindings") {
                            capturingAction = nil
                            viewModel.resetControllerBindings()
                        }
                        .foregroundStyle(MacadeColor.warning)

                        Spacer()

                        if capturingAction != nil {
                            Button("Cancel Capture") { capturingAction = nil }
                                .buttonStyle(.borderless)
                        }
                    }
                }
            }

            SettingsSection(title: "Gamepad Database", subtitle: "Advanced SDL controller mappings. Leave empty unless a controller is misidentified.") {
                Text("Paste one SDL gamecontrollerdb line per controller. Macade passes this to FBNeo with SDL_GAMECONTROLLERCONFIG when a game starts.")
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)

                TextEditor(text: $viewModel.fbneoSettings.controllerMappings)
                    .font(.system(size: 12, weight: .regular, design: .monospaced))
                    .foregroundStyle(MacadeColor.ink)
                    .frame(minHeight: 150)
                    .scrollContentBackground(.hidden)
                    .background(MacadeColor.panel.opacity(0.55), in: RoundedRectangle(cornerRadius: 10))
                    .overlay(RoundedRectangle(cornerRadius: 10).stroke(MacadeColor.stroke, lineWidth: 1))

                HStack {
                    Button("Paste From Clipboard") {
                        if let text = NSPasteboard.general.string(forType: .string), !text.isEmpty {
                            viewModel.fbneoSettings.controllerMappings = text
                        }
                    }

                    Button("Clear Controller Mappings") {
                        viewModel.clearControllerMappings()
                    }
                    .foregroundStyle(MacadeColor.warning)
                    .disabled(viewModel.fbneoSettings.controllerMappings.isEmpty)
                }
            }
        }
    }
}

private struct ControllerSummaryCard: View {
    let symbolName: String
    let title: String
    let detail: String

    var body: some View {
        HStack(alignment: .top, spacing: MacadeSpacing.medium) {
            Image(systemName: symbolName)
                .font(.system(size: 20, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)
                .frame(width: 32, height: 32)
                .background(MacadeColor.neonCyan.opacity(0.12), in: RoundedRectangle(cornerRadius: 9))

            VStack(alignment: .leading, spacing: 4) {
                Text(title)
                    .font(MacadeTypography.headline)
                Text(detail)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .fixedSize(horizontal: false, vertical: true)
            }
        }
        .padding(MacadeSpacing.medium)
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(MacadeColor.panelStrong.opacity(0.62), in: RoundedRectangle(cornerRadius: 14))
    }
}

private struct ControllerActionGroup: View {
    let title: String
    let actions: [ControllerAction]
    let preferences: MacadeControllerPreferences
    @Binding var capturingAction: ControllerAction?
    let setBinding: (MacadeKeyBinding, ControllerAction) -> Void
    let resetBinding: (ControllerAction) -> Void

    private let columns = [GridItem(.adaptive(minimum: 230), spacing: MacadeSpacing.small)]

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            Text(title.uppercased())
                .font(.system(size: 11, weight: .black, design: .monospaced))
                .foregroundStyle(MacadeColor.neonCyan)
                .tracking(1.5)

            LazyVGrid(columns: columns, alignment: .leading, spacing: MacadeSpacing.small) {
                ForEach(actions) { action in
                    ControllerBindingRow(
                        action: action,
                        binding: preferences.bindings[action.id] ?? action.defaultBinding,
                        isCapturing: capturingAction == action,
                        beginCapture: { capturingAction = action },
                        reset: { resetBinding(action) },
                        capture: { binding in
                            setBinding(binding, action)
                            capturingAction = nil
                        }
                    )
                }
            }
        }
    }
}

private struct ControllerBindingRow: View {
    let action: ControllerAction
    let binding: MacadeKeyBinding
    let isCapturing: Bool
    let beginCapture: () -> Void
    let reset: () -> Void
    let capture: (MacadeKeyBinding) -> Void

    var body: some View {
        HStack(spacing: MacadeSpacing.small) {
            Image(systemName: action.symbolName)
                .font(.system(size: 15, weight: .black))
                .foregroundStyle(MacadeColor.neonCyan)
                .frame(width: 24)

            VStack(alignment: .leading, spacing: 2) {
                Text(action.title)
                    .font(MacadeTypography.body)
                Text(action.subtitle)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
            }

            Spacer(minLength: MacadeSpacing.small)

            Button(isCapturing ? "Press key..." : binding.displayName) {
                beginCapture()
            }
            .buttonStyle(.borderless)
            .font(.system(size: 12, weight: .black, design: .monospaced))
            .foregroundStyle(isCapturing ? MacadeColor.warning : MacadeColor.ink)
            .padding(.horizontal, 10)
            .padding(.vertical, 6)
            .background(MacadeColor.sidebar.opacity(0.86), in: RoundedRectangle(cornerRadius: 8))
            .overlay(KeyCaptureView(isActive: isCapturing, onCapture: capture).allowsHitTesting(false))

            Button(action: reset) {
                Image(systemName: "arrow.uturn.backward")
                    .frame(width: 20, height: 20)
            }
            .buttonStyle(.borderless)
            .foregroundStyle(binding == action.defaultBinding ? MacadeColor.inkMuted.opacity(0.45) : MacadeColor.warning)
            .help("Reset \(action.title)")
            .disabled(binding == action.defaultBinding)
        }
        .padding(MacadeSpacing.small)
        .background(MacadeColor.panel.opacity(0.46), in: RoundedRectangle(cornerRadius: 12))
        .overlay(RoundedRectangle(cornerRadius: 12).stroke(isCapturing ? MacadeColor.warning : MacadeColor.stroke, lineWidth: 1))
    }
}

private struct KeyCaptureView: NSViewRepresentable {
    let isActive: Bool
    let onCapture: (MacadeKeyBinding) -> Void

    func makeNSView(context: Context) -> CaptureNSView {
        CaptureNSView()
    }

    func updateNSView(_ nsView: CaptureNSView, context: Context) {
        nsView.isActive = isActive
        nsView.onCapture = onCapture
        if isActive {
            DispatchQueue.main.async { nsView.window?.makeFirstResponder(nsView) }
        }
    }

    final class CaptureNSView: NSView {
        var isActive = false
        var onCapture: ((MacadeKeyBinding) -> Void)?

        override var acceptsFirstResponder: Bool { true }

        override func keyDown(with event: NSEvent) {
            guard isActive, let binding = SDLScancodeMapper.binding(for: event) else {
                super.keyDown(with: event)
                return
            }
            onCapture?(binding)
        }
    }
}
