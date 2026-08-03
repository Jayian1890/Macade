extension AuthenticatedHomeViewModel {
    var statusText: String {
        if isRestoringJoinedChannels {
            return "Rejoining · \(restoringJoinedChannelCount)"
        }

        if isLoading {
            return "Syncing"
        }

        if !joinedChannelIDs.isEmpty {
            return "Joined · \(joinedChannelIDs.count)"
        }

        if let dashboard {
            return "Connected · \(dashboard.channels.count) channels"
        }

        return "Connected"
    }

    func updateStartupLoading(title: String, detail: String, progress: Double, details: [String]) {
        guard isShowingStartupLoading else {
            return
        }

        startupLoadingTitle = title
        startupLoadingDetail = detail
        startupLoadingProgress = progress
        startupLoadingDetails = details
    }

    func completeStartupLoadingIfReady() {
        guard isShowingStartupLoading, !isLoading, !isRestoringJoinedChannels else {
            return
        }

        finishStartupLoading()
    }

    func finishStartupLoading() {
        startupLoadingProgress = 1
        isShowingStartupLoading = false
    }

    func startupDetails(savedJoinedChannelCount: Int, current: String) -> [String] {
        var details = [current, "Fightcade session restored"]
        if savedJoinedChannelCount > 0 {
            details.append("\(savedJoinedChannelCount) saved room\(savedJoinedChannelCount == 1 ? "" : "s") queued")
        } else {
            details.append("No saved rooms to rejoin")
        }
        return details
    }
}
