import SwiftUI

enum MacadeTypography {
    static let display = Font.system(size: 44, weight: .black, design: .rounded)
    static let title = Font.system(size: 28, weight: .bold, design: .rounded)
    static let headline = Font.system(size: 16, weight: .semibold, design: .rounded)
    static let body = Font.system(size: 14, weight: .regular, design: .rounded)
    static let caption = Font.system(size: 12, weight: .medium, design: .monospaced)
    static let control = Font.system(size: 13, weight: .semibold)
    static let roomTitle = Font.system(size: 18, weight: .semibold)
    static let metadata = Font.system(size: 11, weight: .regular)
}
