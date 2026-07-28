import SwiftUI

extension FightcadeChannelUser {
    var countryFlag: String {
        guard let countryCode = countryCode?.uppercased(), countryCode.count == 2 else {
            return "--"
        }

        return countryCode.unicodeScalars.compactMap { scalar in
            UnicodeScalar(127397 + scalar.value).map(String.init)
        }
        .joined()
    }

    var listStatusText: String {
        if isPlaying {
            return "play"
        }

        if isAway {
            return "away"
        }

        return "ready"
    }

    var statusAccent: Color {
        if isPlaying || isAway {
            return MacadeColor.warning
        }

        return MacadeColor.neonCyan
    }

    var rankAccent: Color {
        switch rank {
        case 1:
            MacadeColor.rankE
        case 2:
            MacadeColor.rankD
        case 3:
            MacadeColor.rankC
        case 4:
            MacadeColor.rankB
        case 5:
            MacadeColor.rankA
        case let value? where value >= 6:
            MacadeColor.rankS
        default:
            MacadeColor.inkMuted
        }
    }

    var statusSymbolName: String {
        if isPlaying {
            return "gamecontroller.fill"
        }

        if isAway {
            return "moon.zzz.fill"
        }

        return "checkmark.circle.fill"
    }

    var connectionSummary: String {
        if isUsingProxy {
            return "proxy"
        }

        return isUsingWifi ? "wifi" : "cable"
    }

    var connectionSymbolName: String {
        if isUsingProxy {
            return "shield.lefthalf.filled"
        }

        return isUsingWifi ? "wifi" : "link"
    }

    var connectionDetail: String {
        let base = isUsingWifi ? "Wi-Fi" : "Cable"
        return isUsingProxy ? "\(base), proxy" : base
    }

    var connectionAccent: Color {
        isUsingWifi || isUsingProxy ? MacadeColor.warning : MacadeColor.inkMuted
    }

    var challengeRestrictions: [String] {
        var restrictions: [String] = []
        if preventsBadChallenges {
            restrictions.append("connection quality")
        }

        if preventsWifiChallenges {
            restrictions.append("Wi-Fi")
        }

        return restrictions
    }

    func isCurrentUser(session: AuthSession) -> Bool {
        name.caseInsensitiveCompare(session.displayName) == .orderedSame
            || name.caseInsensitiveCompare(session.username) == .orderedSame
    }
}
