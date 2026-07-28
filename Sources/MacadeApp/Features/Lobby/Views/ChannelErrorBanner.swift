import SwiftUI

struct ChannelErrorBanner: View {
    @Bindable var viewModel: AuthenticatedHomeViewModel

    var body: some View {
        if let errorMessage = viewModel.errorMessage {
            HStack(spacing: MacadeSpacing.small) {
                Image(systemName: "exclamationmark.triangle.fill")
                    .foregroundStyle(MacadeColor.warning)

                Text(errorMessage)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.ink)
                    .lineLimit(1)
                    .truncationMode(.middle)

                Spacer()

                Button("DISMISS") {
                    viewModel.errorMessage = nil
                }
                .buttonStyle(.plain)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
            }
            .padding(.horizontal, MacadeSpacing.large)
            .frame(minHeight: 40)
            .background(.ultraThinMaterial)
            .overlay(alignment: .top) {
                Rectangle()
                    .fill(MacadeColor.warning.opacity(0.5))
                    .frame(height: 1)
            }
            .overlay(alignment: .bottom) {
                Rectangle()
                    .fill(MacadeColor.divider)
                    .frame(height: 1)
            }
        }
    }
}
