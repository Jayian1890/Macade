import SwiftUI

struct CategoryStrip: View {
    let channels: [FightcadeChannel]
    let favoriteCount: Int
    let onSelectPopular: () -> Void
    let onSelectFavorites: () -> Void
    let onSelectSystem: (String) -> Void

    var systems: [String] {
        Array(Set(channels.compactMap(\.system).filter { !$0.isEmpty }))
            .sorted()
            .prefix(4)
            .map { $0 }
    }

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            SectionTitle("BROWSE CATEGORIES")

            LazyVGrid(columns: [GridItem(.adaptive(minimum: 150), spacing: 10)], spacing: 10) {
                CategoryTile(
                    title: "Popular",
                    subtitle: "Active rooms",
                    icon: "flame.fill",
                    imageURL: channels.first?.previewURL,
                    action: onSelectPopular
                )

                CategoryTile(
                    title: "My Favorites",
                    subtitle: favoriteCount == 1 ? "1 saved" : "\(favoriteCount) saved",
                    icon: "star.fill",
                    imageURL: channels.first(where: \.isFavorite)?.previewURL,
                    action: onSelectFavorites
                )

                ForEach(systems, id: \.self) { system in
                    CategoryTile(
                        title: system,
                        subtitle: "System",
                        icon: "rectangle.3.group",
                        imageURL: channels.first { $0.system == system }?.previewURL
                    ) {
                        onSelectSystem(system)
                    }
                }
            }
        }
    }
}

private struct CategoryTile: View {
    let title: String
    let subtitle: String
    let icon: String
    let imageURL: URL?
    let action: () -> Void

    var body: some View {
        Button(action: action) {
            ZStack(alignment: .bottomLeading) {
                FightcadeArtworkImage(url: imageURL) {
                    categoryGradient
                }

                LinearGradient(
                    colors: [.black.opacity(0.12), .black.opacity(0.82)],
                    startPoint: .top,
                    endPoint: .bottom
                )

                HStack(spacing: MacadeSpacing.small) {
                    Image(systemName: icon)
                        .font(.system(size: 16, weight: .black))
                        .frame(width: 28, height: 28)
                        .foregroundStyle(MacadeColor.warning)
                        .background(.black.opacity(0.46), in: Circle())

                    VStack(alignment: .leading, spacing: 2) {
                        Text(title.uppercased())
                            .font(.system(size: 13, weight: .black, design: .rounded))
                            .foregroundStyle(MacadeColor.ink)
                            .lineLimit(1)

                        Text(subtitle.uppercased())
                            .font(.system(size: 10, weight: .bold, design: .rounded))
                            .foregroundStyle(MacadeColor.inkMuted)
                            .lineLimit(1)
                    }

                    Spacer(minLength: 0)
                }
                .padding(.horizontal, MacadeSpacing.small)
            }
            .frame(height: 56)
            .clipShape(RoundedRectangle(cornerRadius: 8))
            .overlay(RoundedRectangle(cornerRadius: 8).stroke(MacadeColor.stroke, lineWidth: 1))
        }
        .buttonStyle(.plain)
    }

    private var categoryGradient: LinearGradient {
        LinearGradient(colors: [.black.opacity(0.84), MacadeColor.panelStrong], startPoint: .topLeading, endPoint: .bottomTrailing)
    }
}
