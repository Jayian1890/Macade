import SwiftUI

protocol RelayCaptureResponder: AnyObject {}

struct RelayCaptureHint: View {
    var body: some View {
        Text("Capture frame: hold every key that should fire together, then release. Press Escape to cancel.")
            .font(MacadeTypography.caption)
            .foregroundStyle(MacadeColor.warning)
            .padding(MacadeSpacing.small)
            .frame(maxWidth: .infinity, alignment: .leading)
            .background(MacadeColor.warning.opacity(0.12), in: RoundedRectangle(cornerRadius: 10))
    }
}

struct RelaySequenceCaptureHint: View {
    let isPassthroughEnabled: Bool

    var body: some View {
        Text(isPassthroughEnabled
            ? "Recording: play the full lane now. Holds and waits are timed; inputs are sent to the active emulator. Press Stop Recording when done."
            : "Recording: play the full lane now. Holds and waits are timed. Press Stop Recording when done.")
            .font(MacadeTypography.caption)
            .foregroundStyle(MacadeColor.warning)
            .padding(MacadeSpacing.small)
            .frame(maxWidth: .infinity, alignment: .leading)
            .background(MacadeColor.warning.opacity(0.12), in: RoundedRectangle(cornerRadius: 10))
    }
}

struct RelayFrameRow: View {
    let index: Int
    let frame: MacadeRelayFrame
    let canMoveUp: Bool
    let canMoveDown: Bool
    let updateHold: (Int) -> Void
    let updateGap: (Int) -> Void
    let moveUp: () -> Void
    let moveDown: () -> Void
    let delete: () -> Void

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            HStack(spacing: MacadeSpacing.small) {
                Text("\(index + 1)")
                    .font(.system(size: 13, weight: .black, design: .monospaced))
                    .foregroundStyle(MacadeColor.neonCyan)
                    .frame(width: 24, height: 24)
                    .background(MacadeColor.neonCyan.opacity(0.12), in: RoundedRectangle(cornerRadius: 7))

                Text(frame.label.nonEmpty ?? "Empty frame")
                    .font(MacadeTypography.headline)
                    .lineLimit(1)

                Spacer()

                Button(action: moveUp) { Image(systemName: "chevron.up") }
                    .disabled(!canMoveUp)
                Button(action: moveDown) { Image(systemName: "chevron.down") }
                    .disabled(!canMoveDown)
                Button(role: .destructive, action: delete) { Image(systemName: "trash") }
            }
            .buttonStyle(.borderless)

            HStack(spacing: MacadeSpacing.large) {
                Stepper("Hold \(frame.holdMilliseconds) ms", value: holdBinding, in: MacadeRelayProfile.holdRange, step: 10)
                Stepper("Gap \(frame.gapMilliseconds) ms", value: gapBinding, in: MacadeRelayProfile.gapRange, step: 10)
            }
            .font(MacadeTypography.caption)
            .foregroundStyle(MacadeColor.inkMuted)
        }
        .padding(MacadeSpacing.small)
        .background(MacadeColor.panel.opacity(0.54), in: RoundedRectangle(cornerRadius: 12))
        .overlay(RoundedRectangle(cornerRadius: 12).stroke(MacadeColor.stroke, lineWidth: 1))
    }

    private var holdBinding: Binding<Int> {
        Binding(get: { frame.holdMilliseconds }, set: { updateHold($0) })
    }

    private var gapBinding: Binding<Int> {
        Binding(get: { frame.gapMilliseconds }, set: { updateGap($0) })
    }
}

struct RelayFrameCaptureView: NSViewRepresentable {
    let isActive: Bool
    let controllerPreferences: MacadeControllerPreferences
    let onComplete: ([MacadeRelayNode]) -> Void
    let onCancel: () -> Void

    func makeNSView(context: Context) -> CaptureNSView {
        CaptureNSView()
    }

    func updateNSView(_ nsView: CaptureNSView, context: Context) {
        nsView.isActive = isActive
        nsView.controllerPreferences = controllerPreferences
        nsView.onComplete = onComplete
        nsView.onCancel = onCancel
        if isActive {
            DispatchQueue.main.async { nsView.window?.makeFirstResponder(nsView) }
        }
    }

    final class CaptureNSView: NSView, RelayCaptureResponder {
        var isActive = false {
            didSet {
                if isActive != oldValue {
                    capturedNodes.removeAll()
                    pressedKeyCodes.removeAll()
                }
            }
        }
        var controllerPreferences = MacadeControllerPreferences.defaults
        var onComplete: (([MacadeRelayNode]) -> Void)?
        var onCancel: (() -> Void)?

        private var capturedNodes: [MacadeRelayNode] = []
        private var pressedKeyCodes = Set<UInt16>()

        override var acceptsFirstResponder: Bool { true }

        override func keyDown(with event: NSEvent) {
            guard isActive else {
                super.keyDown(with: event)
                return
            }

            if event.keyCode == 53 {
                cancel()
                return
            }

            guard !event.isARepeat else { return }
            pressedKeyCodes.insert(event.keyCode)
            guard let node = RelayInputMapper.node(for: event, controllerPreferences: controllerPreferences),
                  !capturedNodes.contains(where: { $0.scancode == node.scancode }) else {
                return
            }
            capturedNodes.append(node)
        }

        override func keyUp(with event: NSEvent) {
            guard isActive else {
                super.keyUp(with: event)
                return
            }

            pressedKeyCodes.remove(event.keyCode)
            if pressedKeyCodes.isEmpty, !capturedNodes.isEmpty {
                let nodes = capturedNodes
                capturedNodes.removeAll()
                onComplete?(nodes)
            }
        }

        private func cancel() {
            capturedNodes.removeAll()
            pressedKeyCodes.removeAll()
            onCancel?()
        }
    }
}

enum RelayInputMapper {
    static func node(for event: NSEvent, controllerPreferences: MacadeControllerPreferences) -> MacadeRelayNode? {
        if let action = controllerPreferences.controllerAction(for: event.keyCode) {
            return MacadeRelayNode(scancode: action.defaultSDLScancode, label: action.title)
        }

        guard let scancode = SDLScancodeMapper.scancode(for: event) else {
            return nil
        }
        return MacadeRelayNode(scancode: scancode, label: SDLScancodeMapper.displayName(for: event))
    }
}
