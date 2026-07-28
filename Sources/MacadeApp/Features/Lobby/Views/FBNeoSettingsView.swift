import SwiftUI

struct FBNeoSettingsView: View {
    var body: some View {
        MacadeSettingsView(initialSection: .emulator, showsCancelButton: true)
    }
}

#Preview {
    FBNeoSettingsView()
}
