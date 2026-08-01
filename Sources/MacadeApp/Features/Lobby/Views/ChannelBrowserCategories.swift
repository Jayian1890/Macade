import SwiftUI

struct CategoryStrip: View {
    let title: String
    let categories: [String]
    let channels: [FightcadeChannel]
    let favoriteCount: Int
    let onSelectCategory: (String) -> Void

    init(
        title: String = "BROWSE CATEGORIES",
        categories: [String] = [],
        channels: [FightcadeChannel],
        favoriteCount: Int,
        onSelectCategory: @escaping (String) -> Void
    ) {
        self.title = title
        self.categories = categories
        self.channels = channels
        self.favoriteCount = favoriteCount
        self.onSelectCategory = onSelectCategory
    }

    var systems: [String] {
        Array(Set(channels.compactMap(\.system).filter { !$0.isEmpty }))
            .sorted()
            .prefix(4)
            .map { $0 }
    }

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            SectionTitle(title)

            LazyVGrid(columns: [GridItem(.adaptive(minimum: 150), spacing: 10)], spacing: 10) {
                ForEach(displayCategories, id: \.self) { category in
                    CategoryTile(
                        title: category,
                        subtitle: subtitle(for: category),
                        icon: icon(for: category),
                        imageURL: imageURL(for: category)
                    ) {
                        onSelectCategory(category)
                    }
                }
            }
        }
    }

    private var displayCategories: [String] {
        categories.isEmpty ? ["Popular", "My Favorites"] + systems : categories
    }

    private func subtitle(for category: String) -> String {
        switch category.normalizedBrowserCategory {
        case "popular":
            return "Active rooms"
        case "my favorites", "favorites":
            return favoriteCount == 1 ? "1 saved" : "\(favoriteCount) saved"
        default:
            return "Browse"
        }
    }

    private func icon(for category: String) -> String {
        switch category.normalizedBrowserCategory {
        case "popular":
            return "flame.fill"
        case "my favorites", "favorites":
            return "star.fill"
        default:
            return "rectangle.3.group"
        }
    }

    private func imageURL(for category: String) -> URL? {
        switch category.normalizedBrowserCategory {
        case "popular":
            return channels.first?.previewURL
        case "my favorites", "favorites":
            return channels.first(where: \.isFavorite)?.previewURL
        default:
            return channels.first { channel in
                channel.system?.normalizedBrowserCategory == category.normalizedBrowserCategory
                    || channel.title.localizedCaseInsensitiveContains(category)
            }?.previewURL
        }
    }
}

private struct CategoryTile: View {
    let title: String
    let subtitle: String
    let icon: String
    let imageURL: URL?
    let action: () -> Void

    private let tileHeight: CGFloat = 56

    var body: some View {
        Button(action: action) {
            ZStack {
                FightcadeArtworkImage(url: imageURL, fallbackURLs: fallbackURLs) {
                    categoryGradient
                }
                .frame(maxWidth: .infinity)
                .frame(height: tileHeight)
                .clipped()

                LinearGradient(
                    colors: [.black.opacity(0.20), .black.opacity(0.88)],
                    startPoint: .top,
                    endPoint: .bottom
                )
                .frame(maxWidth: .infinity)
                .frame(height: tileHeight)

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
                            .shadow(color: .black.opacity(0.65), radius: 2, x: 0, y: 1)

                        Text(subtitle.uppercased())
                            .font(.system(size: 10, weight: .bold, design: .rounded))
                            .foregroundStyle(MacadeColor.inkMuted)
                            .lineLimit(1)
                            .shadow(color: .black.opacity(0.65), radius: 2, x: 0, y: 1)
                    }

                    Spacer(minLength: 0)
                }
                .padding(.horizontal, MacadeSpacing.small)
                .frame(maxWidth: .infinity)
                .frame(height: tileHeight, alignment: .center)
            }
            .frame(height: tileHeight)
            .contentShape(RoundedRectangle(cornerRadius: 8))
            .clipShape(RoundedRectangle(cornerRadius: 8))
            .overlay(RoundedRectangle(cornerRadius: 8).stroke(MacadeColor.stroke, lineWidth: 1))
        }
        .buttonStyle(.plain)
    }

    private var categoryGradient: LinearGradient {
        LinearGradient(colors: [.black.opacity(0.84), MacadeColor.panelStrong], startPoint: .topLeading, endPoint: .bottomTrailing)
    }

    private var fallbackURLs: [URL?] {
        imageURL == nil ? [] : [FightcadeChannel.unsupportedPreviewURL]
    }
}

extension String {
    var normalizedBrowserCategory: String {
        trimmingCharacters(in: .whitespacesAndNewlines)
            .normalizedFightcadeFavoriteKey
    }
}
