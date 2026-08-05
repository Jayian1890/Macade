import SwiftUI

struct MacadeAboutView: View {
    @Environment(\.dismiss) private var dismiss
    private let metadata = MacadeAboutMetadata.current

    var body: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.large) {
            header
            summary
            links
            footer
        }
        .padding(MacadeSpacing.large)
        .frame(width: 540)
        .background(MacadeBackground())
        .foregroundStyle(MacadeColor.ink)
        .tint(MacadeColor.neonCyan)
        .preferredColorScheme(.dark)
        .colorScheme(.dark)
    }

    private var header: some View {
        HStack(spacing: MacadeSpacing.medium) {
            MacadeAboutIconView()

            VStack(alignment: .leading, spacing: 4) {
                Text("Macade")
                    .font(.system(size: 34, weight: .black, design: .rounded))
                Text(metadata.versionText)
                    .font(MacadeTypography.caption)
                    .foregroundStyle(MacadeColor.inkMuted)
                    .textSelection(.enabled)
            }

            Spacer()
        }
    }

    private var summary: some View {
        VStack(alignment: .leading, spacing: MacadeSpacing.small) {
            Text("Fightcade for macOS, rebuilt as a native Mac app.")
                .font(MacadeTypography.headline)
            Text("Macade provides a native SwiftUI interface for Fightcade-compatible lobbies, chat, spectating, and embedded FBNeo gameplay. It is independent software, is not affiliated with Fightcade, and does not include copyrighted game ROMs.")
                .font(MacadeTypography.body)
                .foregroundStyle(MacadeColor.inkMuted)
                .fixedSize(horizontal: false, vertical: true)
        }
    }

    private var links: some View {
        HStack(spacing: MacadeSpacing.small) {
            Link(destination: MacadeProjectLink.repository) {
                Label("GitHub Project", systemImage: "arrow.up.right.square")
            }
            .buttonStyle(ChannelHeaderButtonStyle(isProminent: true))
            .help("Open the Macade project on GitHub")

            Link(destination: MacadeProjectLink.releases) {
                Label("Releases", systemImage: "shippingbox")
            }
            .buttonStyle(ChannelHeaderButtonStyle())
            .help("Open the latest Macade releases")

            Link(destination: MacadeProjectLink.license) {
                Label("License", systemImage: "doc.text")
            }
            .buttonStyle(ChannelHeaderButtonStyle())
            .help("Open the Macade license")
        }
    }

    private var footer: some View {
        HStack(alignment: .center, spacing: MacadeSpacing.medium) {
            Text(metadata.copyright)
                .font(MacadeTypography.caption)
                .foregroundStyle(MacadeColor.inkMuted)
                .lineLimit(2)
                .textSelection(.enabled)

            Spacer()

            Button("Close") { dismiss() }
                .buttonStyle(.borderless)
                .foregroundStyle(MacadeColor.inkMuted)
        }
    }
}

private struct MacadeAboutIconView: View {
    var body: some View {
        Group {
            if let image = NSApplication.shared.applicationIconImage {
                Image(nsImage: image)
                    .resizable()
            } else {
                Image(systemName: "gamecontroller.fill")
                    .resizable()
                    .symbolRenderingMode(.hierarchical)
                    .foregroundStyle(MacadeColor.warning)
                    .padding(MacadeSpacing.medium)
            }
        }
        .aspectRatio(contentMode: .fit)
        .frame(width: 72, height: 72)
        .background(MacadeColor.panelStrong, in: RoundedRectangle(cornerRadius: 18))
        .clipShape(RoundedRectangle(cornerRadius: 18))
        .shadow(color: MacadeColor.neonCyan.opacity(0.22), radius: 18)
    }
}

private struct MacadeAboutMetadata {
    let versionText: String
    let copyright: String

    static var current: MacadeAboutMetadata {
        let bundle = Bundle.main
        let version = bundle.object(forInfoDictionaryKey: "CFBundleShortVersionString") as? String
        let build = bundle.object(forInfoDictionaryKey: "CFBundleVersion") as? String

        return MacadeAboutMetadata(
            versionText: versionText(version: version, build: build),
            copyright: bundle.object(forInfoDictionaryKey: "NSHumanReadableCopyright") as? String ?? "Copyright (c) 2026 Macade."
        )
    }

    private static func versionText(version: String?, build: String?) -> String {
        guard let version, !version.isEmpty else { return "Development build" }
        guard let build, !build.isEmpty else { return "Version \(version)" }
        return "Version \(version) (build \(build))"
    }
}

private enum MacadeProjectLink {
    static let repository = URL(string: "https://github.com/Jayian1890/Macade")!
    static let releases = URL(string: "https://github.com/Jayian1890/Macade/releases/latest")!
    static let license = URL(string: "https://github.com/Jayian1890/Macade/blob/main/LICENSE")!
}
