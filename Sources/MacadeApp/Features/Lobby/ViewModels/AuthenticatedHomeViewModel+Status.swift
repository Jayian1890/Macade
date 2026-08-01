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
}
