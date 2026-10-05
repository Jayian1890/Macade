import SwiftUI
import AppKit

struct MacadeResizableSplitView<Leading: View, Trailing: View>: View {
    enum FixedSide { case leading, trailing }

    var axis: Axis = .horizontal
    var fixedSide: FixedSide = .leading
    @Binding var dimension: CGFloat
    let minimum: CGFloat
    let maximum: CGFloat
    let flexibleMinimum: CGFloat
    let defaultDimension: CGFloat
    let label: String
    @ViewBuilder var leading: () -> Leading
    @ViewBuilder var trailing: () -> Trailing
    @State private var dragStart: CGFloat?
    @State private var isHovering = false

    var body: some View {
        GeometryReader { proxy in
            let total = axis == .horizontal ? proxy.size.width : proxy.size.height
            let fixed = MacadeLayout.paneDimension(preferred: dimension, total: total,
                minimum: minimum, maximum: maximum, flexibleMinimum: flexibleMinimum)
            let flexible = max(0, total - MacadeLayout.dividerWidth - fixed)
            let layout = axis == .horizontal ? AnyLayout(HStackLayout(spacing: 0)) : AnyLayout(VStackLayout(spacing: 0))

            layout {
                pane(leading(), size: fixedSide == .leading ? fixed : flexible)
                divider(fixed: fixed, total: total)
                pane(trailing(), size: fixedSide == .trailing ? fixed : flexible)
            }
        }
    }

    private func pane<Content: View>(_ content: Content, size: CGFloat) -> some View {
        content
            .frame(width: axis == .horizontal ? size : nil,
                   height: axis == .vertical ? size : nil)
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .clipped()
    }

    private func divider(fixed: CGFloat, total: CGFloat) -> some View {
        ZStack {
            Rectangle().fill(MacadeColor.sidebar)
            Rectangle().fill(MacadeColor.divider)
                .frame(width: axis == .horizontal ? 1 : nil, height: axis == .vertical ? 1 : nil)
            Capsule().fill(isHovering || dragStart != nil ? MacadeColor.neonCyan : MacadeColor.inkMuted.opacity(0.45))
                .frame(width: axis == .horizontal ? 2 : MacadeLayout.dividerGripLength,
                       height: axis == .vertical ? 2 : MacadeLayout.dividerGripLength)
        }
        .frame(width: axis == .horizontal ? MacadeLayout.dividerWidth : nil,
               height: axis == .vertical ? MacadeLayout.dividerWidth : nil)
        .contentShape(Rectangle())
        .gesture(DragGesture(minimumDistance: 3, coordinateSpace: .global)
            .onChanged { value in
                let start = dragStart ?? fixed
                dragStart = start
                let movement = axis == .horizontal ? value.translation.width : value.translation.height
                resize(to: start + (fixedSide == .leading ? movement : -movement), total: total)
            }
            .onEnded { _ in dragStart = nil })
        .onTapGesture(count: 2) { resize(to: defaultDimension, total: total) }
        .onHover { hovering in
            guard hovering != isHovering else { return }
            isHovering = hovering
            if hovering { cursor.push() } else { NSCursor.pop() }
        }
        .onDisappear { if isHovering { NSCursor.pop(); isHovering = false } }
        .focusable()
        .focusEffectDisabled()
        .onKeyPress(.leftArrow) { adjust(-1, axis: .horizontal, fixed: fixed, total: total) }
        .onKeyPress(.rightArrow) { adjust(1, axis: .horizontal, fixed: fixed, total: total) }
        .onKeyPress(.upArrow) { adjust(-1, axis: .vertical, fixed: fixed, total: total) }
        .onKeyPress(.downArrow) { adjust(1, axis: .vertical, fixed: fixed, total: total) }
        .accessibilityElement()
        .accessibilityLabel("Resize \(label)")
        .accessibilityValue("\(Int(fixed)) points")
        .accessibilityAdjustableAction { direction in
            switch direction {
            case .increment: resize(to: fixed + MacadeLayout.resizeStep, total: total)
            case .decrement: resize(to: fixed - MacadeLayout.resizeStep, total: total)
            @unknown default: break
            }
        }
        .help("Drag to resize \(label). Double-click to reset.")
    }

    private var cursor: NSCursor { axis == .horizontal ? .resizeLeftRight : .resizeUpDown }

    private func resize(to value: CGFloat, total: CGFloat) {
        dimension = MacadeLayout.paneDimension(preferred: value, total: total,
            minimum: minimum, maximum: maximum, flexibleMinimum: flexibleMinimum)
    }

    private func adjust(_ direction: CGFloat, axis requestedAxis: Axis, fixed: CGFloat, total: CGFloat) -> KeyPress.Result {
        guard axis == requestedAxis else { return .ignored }
        let sign: CGFloat = fixedSide == .leading ? 1 : -1
        resize(to: fixed + direction * sign * MacadeLayout.resizeStep, total: total)
        return .handled
    }
}
