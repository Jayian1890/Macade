import Foundation

struct FightcadeRecentMatchKey: Hashable, Sendable {
    let username: String
    let gameID: String

    init?(username: String, gameID: String) {
        let username = username.trimmingCharacters(in: .whitespacesAndNewlines).lowercased()
        let gameID = gameID.trimmingCharacters(in: .whitespacesAndNewlines).lowercased()
        guard !username.isEmpty, !gameID.isEmpty else {
            return nil
        }

        self.username = username
        self.gameID = gameID
    }
}

enum FightcadeRecentMatchState: Equatable, Sendable {
    case idle
    case loading
    case loaded([FightcadeRecentMatch])
    case failed(String)
}

extension AuthenticatedHomeViewModel {
    func recentMatchState(for user: FightcadeChannelUser, in channel: FightcadeChannel) -> FightcadeRecentMatchState {
        guard let key = recentMatchKey(for: user, in: channel) else {
            return .failed("No game id for this channel.")
        }

        return recentMatchStatesByKey[key] ?? .idle
    }

    func loadRecentMatchesIfNeeded(for user: FightcadeChannelUser, in channel: FightcadeChannel) async {
        switch recentMatchState(for: user, in: channel) {
        case .loading, .loaded:
            return
        case .idle, .failed:
            await reloadRecentMatches(for: user, in: channel)
        }
    }

    func reloadRecentMatches(for user: FightcadeChannelUser, in channel: FightcadeChannel) async {
        guard let gameID = channel.launchGameID,
              let key = recentMatchKey(for: user, in: channel) else {
            return
        }

        recentMatchStatesByKey[key] = .loading

        do {
            let matches = try await lobbyService.loadRecentMatches(for: user.name, gameID: gameID, limit: 3)
            guard !Task.isCancelled else { return }
            recentMatchStatesByKey[key] = .loaded(matches)
        } catch let error as FightcadeLobbyError {
            guard !Task.isCancelled else { return }
            recentMatchStatesByKey[key] = .failed(error.localizedDescription)
        } catch {
            guard !Task.isCancelled else { return }
            recentMatchStatesByKey[key] = .failed("Could not load recent matches.")
        }
    }

    func canOpenRecentMatchReplay(_ match: FightcadeRecentMatch) -> Bool {
        match.replayLink != nil && launcher.canLaunchFightcadeReplay(emulator: match.emulator)
    }

    func openRecentMatchReplay(_ match: FightcadeRecentMatch, in channel: FightcadeChannel) {
        guard match.gameID.compare(channel.launchGameID ?? "", options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame else {
            errorMessage = "Replay does not match the current channel."
            return
        }

        guard canOpenRecentMatchReplay(match), let link = match.replayLink else {
            errorMessage = match.hasReplay
                ? "Native replay support is not available for \(match.emulator)."
                : "Fightcade has no replay file for this match."
            return
        }

        openFightcadeReplay(link, in: channel)
    }

    private func recentMatchKey(for user: FightcadeChannelUser, in channel: FightcadeChannel) -> FightcadeRecentMatchKey? {
        guard let gameID = channel.launchGameID else {
            return nil
        }

        return FightcadeRecentMatchKey(username: user.name, gameID: gameID)
    }
}
