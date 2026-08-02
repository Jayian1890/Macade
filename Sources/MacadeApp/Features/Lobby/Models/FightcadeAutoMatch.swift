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
    case allEligiblePlayersTried
    case currentUserUnavailable
    case missingCurrentUserRank
    case paused(String)
}

struct FightcadeAutoMatchState: Equatable, Sendable {
    var isEnabled = false
    var activeChallengeIDs = Set<String>()
    var challengedUsernames = Set<String>()
    var status = FightcadeAutoMatchStatus.idle
}

struct FightcadeAutoMatchAttempt: Equatable, Sendable {
    let users: [FightcadeChannelUser]
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
        activeChallengeUsernames: Set<String>,
        challengedUsernames: Set<String>
    ) -> FightcadeAutoMatchAttempt {
        let sessionUsernames = [session.username, session.displayName]
            .map(normalizedUsername)
            .filter { !$0.isEmpty }
        guard let currentUser = users.first(where: { sessionUsernames.contains(normalizedUsername($0.name)) }) else {
            return FightcadeAutoMatchAttempt(users: [], status: .currentUserUnavailable)
        }

        guard let currentRank = currentUser.rank, currentRank > 0 else {
            return FightcadeAutoMatchAttempt(users: [], status: .missingCurrentUserRank)
        }

        let normalizedActiveChallengeUsernames = Set(activeChallengeUsernames.map(normalizedUsername))
        let normalizedChallengedUsernames = Set(challengedUsernames.map(normalizedUsername))
        let currentCountry = normalizedCountryCode(currentUser.countryCode)
        let candidates = users.filter { user in
            isEligible(
                user,
                currentRank: currentRank,
                currentCountry: currentCountry,
                sessionUsernames: sessionUsernames,
                activeChallengeUsernames: normalizedActiveChallengeUsernames
            )
        }

        guard !candidates.isEmpty else {
            return FightcadeAutoMatchAttempt(users: [], status: .noEligiblePlayers)
        }

        let untriedCandidates = candidates.filter {
            !normalizedChallengedUsernames.contains(normalizedUsername($0.name))
        }
        guard !untriedCandidates.isEmpty else {
            return FightcadeAutoMatchAttempt(users: [], status: .allEligiblePlayersTried)
        }

        let selected = Array(untriedCandidates.shuffled().prefix(configuration.maxChallengesPerAttempt))
        return FightcadeAutoMatchAttempt(users: selected, status: .searching)
    }

    private func isEligible(
        _ user: FightcadeChannelUser,
        currentRank: Int,
        currentCountry: String?,
        sessionUsernames: [String],
        activeChallengeUsernames: Set<String>
    ) -> Bool {
        let username = normalizedUsername(user.name)
        guard !sessionUsernames.contains(username),
              !activeChallengeUsernames.contains(username),
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
