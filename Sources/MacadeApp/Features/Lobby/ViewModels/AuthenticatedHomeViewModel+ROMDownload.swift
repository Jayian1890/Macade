import Foundation

extension AuthenticatedHomeViewModel {
    func downloadSelectedROM() {
        guard let channel = selectedChannel,
              let emulator = channel.launchEmulator,
              let gameID = channel.launchGameID else {
            errorMessage = FightcadeLaunchError.missingGame.localizedDescription
            return
        }

        isDownloadingROM = true
        errorMessage = nil

        Task {
            defer { isDownloadingROM = false }

            do {
                let url = try await romDownloader.downloadROM(emulator: emulator, system: channel.system, gameID: gameID)
                appendSystemMessage("Downloaded ROM to \(url.lastPathComponent)", channelName: channel.name)
            } catch let error as FightcadeROMDownloadError {
                errorMessage = error.localizedDescription
            } catch {
                errorMessage = "Could not download ROM."
            }
        }
    }
}
