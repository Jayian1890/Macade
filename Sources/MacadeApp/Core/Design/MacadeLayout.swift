import Foundation

enum MacadeLayout {
    static let dividerWidth: CGFloat = 8
    static let dividerGripLength: CGFloat = 24
    static let resizeStep: CGFloat = 16
    static let sidebarCompact: CGFloat = 56
    static let sidebarDefault: CGFloat = 224
    static let sidebarMaximum: CGFloat = 340
    static let sidebarLabelThreshold: CGFloat = 160
    static let roomMinimum: CGFloat = 640
    static let chatMinimum: CGFloat = 360
    static let playersMinimum: CGFloat = 240
    static let playersDefault: CGFloat = 300
    static let playersMaximum: CGFloat = 480
    static let detailsMinimum: CGFloat = 140
    static let detailsDefault: CGFloat = 240
    static let detailsMaximum: CGFloat = 420
    static let rosterMinimumHeight: CGFloat = 160
    static let toolbarHeight: CGFloat = 48
    static let controlHeight: CGFloat = 30
    static let controlRadius: CGFloat = 8
    static let chatEntryMinimum: CGFloat = 140
    static let playerRowHeight: CGFloat = 36

    // Preserve the requested size while a smaller window temporarily constrains
    // it. Never let a fixed pane consume the flexible pane's minimum space.
    static func paneDimension(preferred: CGFloat, total: CGFloat, minimum: CGFloat,
                              maximum: CGFloat, flexibleMinimum: CGFloat) -> CGFloat {
        let available = max(0, total - dividerWidth)
        let upper = min(maximum, max(0, available - flexibleMinimum))
        let lower = min(minimum, upper)
        return min(max(preferred.isFinite ? preferred : minimum, lower), upper)
    }
}
