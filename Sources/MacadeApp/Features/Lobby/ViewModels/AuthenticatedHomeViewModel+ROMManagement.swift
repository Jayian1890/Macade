extension AuthenticatedHomeViewModel {
    func showFBNeoSettings() {
        isShowingFBNeoSettings = true
    }

    func deleteSelectedROM() {
        guard let channel = selectedChannel,
              let emulator = channel.launchEmulator,
              let gameID = channel.launchGameID else {
            errorMessage = FightcadeLaunchError.missingGame.localizedDescription
            return
        }

        isDeletingROM = true
        errorMessage = nil

        Task { @MainActor in
            defer { isDeletingROM = false }

            do {
                let deleted = try romLibrary.deleteROMs(emulator: emulator, gameID: gameID)
                if deleted.isEmpty {
                    errorMessage = "No local ROM files found for \(gameID)."
                } else {
                    appendSystemMessage("Deleted \(deleted.count) ROM file\(deleted.count == 1 ? "" : "s") for \(gameID)", channelName: channel.name)
                }
            } catch let error as FightcadeLaunchError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not delete ROM files."
            }
        }
    }
}
