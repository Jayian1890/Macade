import Foundation

struct FightcadeAutoMatchConfiguration: Equatable, Sendable {
    static let `default` = FightcadeAutoMatchConfiguration()

    let maxChallengesPerAttempt: Int
    let acceptanceTimeoutSeconds: Int
    let rankTolerance: Int
    let maximumPing: Int

    init(
        maxChallengesPerAttempt: Int = 2,
        acceptanceTimeoutSeconds: Int = 15,
        rankTolerance: Int = 1,
        maximumPing: Int = 150
    ) {
        self.maxChallengesPerAttempt = max(1, maxChallengesPerAttempt)
        self.acceptanceTimeoutSeconds = max(1, acceptanceTimeoutSeconds)
        self.rankTolerance = max(0, rankTolerance)
        self.maximumPing = max(1, maximumPing)
    }
}

enum FightcadeAutoMatchStatus: Equatable, Sendable {
    case idle
    case searching
    case waiting(usernames: [String])
    case noEligiblePlayers
    case currentUserUnavailable
    case missingCurrentUserRank
    case paused(String)
}

struct FightcadeAutoMatchState: Equatable, Sendable {
    var isEnabled = false
    var rotationIndex = 0
    var activeChallengeIDs = Set<String>()
    var status = FightcadeAutoMatchStatus.idle
}

struct FightcadeAutoMatchAttempt: Equatable, Sendable {
    let users: [FightcadeChannelUser]
    let nextRotationIndex: Int
    let status: FightcadeAutoMatchStatus
}

struct FightcadeAutoMatchPlanner: Sendable {
    let configuration: FightcadeAutoMatchConfiguration

    init(configuration: FightcadeAutoMatchConfiguration = .default) {
        self.configuration = configuration
    }

    func attempt(
        users: [FightcadeChannelUser],
        session: AuthSession,
        blockedUsernames: Set<String>,
        rotationIndex: Int
    ) -> FightcadeAutoMatchAttempt {
        let sessionUsernames = [session.username, session.displayName]
            .map(normalizedUsername)
            .filter { !$0.isEmpty }
        guard let currentUser = users.first(where: { sessionUsernames.contains(normalizedUsername($0.name)) }) else {
            return FightcadeAutoMatchAttempt(users: [], nextRotationIndex: 0, status: .currentUserUnavailable)
        }

        guard let currentRank = currentUser.rank, currentRank > 0 else {
            return FightcadeAutoMatchAttempt(users: [], nextRotationIndex: 0, status: .missingCurrentUserRank)
        }

        let normalizedBlockedUsernames = Set(blockedUsernames.map(normalizedUsername))
        let currentCountry = normalizedCountryCode(currentUser.countryCode)
        let candidates = users.filter { user in
            isEligible(
                user,
                currentRank: currentRank,
                currentCountry: currentCountry,
                sessionUsernames: sessionUsernames,
                blockedUsernames: normalizedBlockedUsernames
            )
        }
        .sorted { lhs, rhs in
            sortCandidates(lhs, rhs, currentRank: currentRank)
        }

        guard !candidates.isEmpty else {
            return FightcadeAutoMatchAttempt(users: [], nextRotationIndex: 0, status: .noEligiblePlayers)
        }

        let start = ((rotationIndex % candidates.count) + candidates.count) % candidates.count
        let rotated = Array(candidates[start...]) + Array(candidates[..<start])
        let selected = Array(rotated.prefix(configuration.maxChallengesPerAttempt))
        let nextIndex = (start + selected.count) % candidates.count
        return FightcadeAutoMatchAttempt(users: selected, nextRotationIndex: nextIndex, status: .searching)
    }

    private func isEligible(
        _ user: FightcadeChannelUser,
        currentRank: Int,
        currentCountry: String?,
        sessionUsernames: [String],
        blockedUsernames: Set<String>
    ) -> Bool {
        let username = normalizedUsername(user.name)
        guard !sessionUsernames.contains(username),
              !blockedUsernames.contains(username),
              !user.isAway,
              !user.isPlaying,
              let rank = user.rank,
              rank > 0,
              abs(rank - currentRank) <= configuration.rankTolerance else {
            return false
        }

        let sameCountry = currentCountry != nil && normalizedCountryCode(user.countryCode) == currentCountry
        let lowPing = user.matchmakingPing.map { $0 < configuration.maximumPing } ?? false
        return sameCountry || lowPing
    }

    private func sortCandidates(
        _ lhs: FightcadeChannelUser,
        _ rhs: FightcadeChannelUser,
        currentRank: Int
    ) -> Bool {
        let leftRankDelta = abs((lhs.rank ?? 0) - currentRank)
        let rightRankDelta = abs((rhs.rank ?? 0) - currentRank)
        if leftRankDelta != rightRankDelta {
            return leftRankDelta < rightRankDelta
        }

        switch (lhs.matchmakingPing, rhs.matchmakingPing) {
        case let (left?, right?) where left != right:
            return left < right
        case (_?, nil):
            return true
        case (nil, _?):
            return false
        default:
            return lhs.name.localizedCaseInsensitiveCompare(rhs.name) == .orderedAscending
        }
    }

    private func normalizedUsername(_ username: String) -> String {
        username.folding(options: [.caseInsensitive, .diacriticInsensitive], locale: nil)
            .trimmingCharacters(in: .whitespacesAndNewlines)
            .lowercased()
    }

    private func normalizedCountryCode(_ countryCode: String?) -> String? {
        let code = countryCode?.trimmingCharacters(in: .whitespacesAndNewlines).uppercased()
        return code?.isEmpty == false ? code : nil
    }
}

extension FightcadeChannelUser {
    var matchmakingPing: Int? {
        ping ?? virtualPing
    }
}
