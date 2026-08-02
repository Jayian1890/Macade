import SwiftUI

struct SectionTitle: View {
    let title: String

    init(_ title: String) {
        self.title = title
    }

    var body: some View {
        Text(title)
            .font(.system(size: 24, weight: .black, design: .rounded))
            .foregroundStyle(MacadeColor.ink)
    }
}
