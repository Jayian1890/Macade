import SwiftUI

struct PingQualityIcon: View {
    let ping: Int?
    let size: CGFloat

    init(_ ping: Int?, size: CGFloat = 11) {
        self.ping = ping
        self.size = size
    }

    var body: some View {
        Image(systemName: symbolName)
            .font(.system(size: size, weight: .black))
            .foregroundStyle(color)
            .frame(width: size + 9, height: size + 9)
            .help(helpText)
    }

    private var symbolName: String {
        guard let ping else {
            return "questionmark.circle.fill"
        }

        switch ping {
        case ..<90:
            return "network"
        case ..<150:
            return "network.badge.shield.half.filled"
        default:
            return "exclamationmark.triangle.fill"
        }
    }

    private var color: Color {
        guard let ping else {
            return MacadeColor.inkMuted.opacity(0.58)
        }

        switch ping {
        case ..<90:
            return MacadeColor.neonCyan
        case ..<150:
            return MacadeColor.warning
        default:
            return .red
        }
    }

    private var helpText: String {
        guard let ping else {
            return "Ping unavailable"
        }

        return "Ping \(ping) ms"
    }
}
