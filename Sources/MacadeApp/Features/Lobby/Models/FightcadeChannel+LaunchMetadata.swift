extension FightcadeChannel {
    var launchEmulator: String? {
        emulator?.nonEmpty ?? "fbneo"
    }

    var launchGameID: String? {
        gameID?.nonEmpty ?? name.nonEmpty
    }
}

extension String {
    var nonEmpty: String? {
        isEmpty ? nil : self
    }
}
