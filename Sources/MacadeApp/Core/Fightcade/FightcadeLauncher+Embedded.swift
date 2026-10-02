import AppKit

extension FightcadeLauncher {
    func openEmbedded(_ launch: FightcadeEmbeddedLaunch) async throws -> FightcadeEmbeddedSession {
        let runtimeRoot = try runtime.root()
        let manifest = runtimeManifest(in: runtimeRoot)
        if let capability = launch.requiredRuntimeCapability {
            guard manifest.supports(capability, emulator: launch.emulator) else {
                throw FightcadeLaunchError.unsupportedNativeRoute(
                    "embedded native \(launch.emulator) \(launch.mode.rawValue.lowercased()). The runtime emulator must implement Fightcade quark/GGPO support."
                )
            }
        } else if !manifest.supportsEmbedded(emulator: launch.emulator) {
            throw FightcadeLaunchError.unsupportedNativeRoute(
                "embedded native \(launch.emulator) local launch. The runtime emulator must implement Macade embedded video/input support."
            )
        }

        if FightcadeEmulatorID.runtimeID(for: launch.emulator) == "fbneo" {
            UserDefaults.standard.set(launch.gameID, forKey: "MacadeLastFBNeoGame")
        }
        let expectedROM = try ensureROMExists(emulator: launch.emulator, gameID: launch.gameID)
        let netplayPreparation = try await prepareNetplay(for: launch)
        let resources = try makeEmbeddedResources(emulator: launch.emulator)
        let session = FightcadeEmbeddedSession(
            id: resources.id,
            channelID: launch.channelID,
            mode: launch.mode,
            emulator: launch.emulator,
            gameID: launch.gameID,
            title: launch.title,
            logURL: resources.logURL,
            videoStream: resources.videoStream,
            inputClient: resources.inputClient
        )

        var embeddedEnvironment = [
            "MACADE_EMBEDDED_SESSION_ID": resources.id.uuidString,
            "MACADE_EMBEDDED_VIDEO_PATH": resources.videoStream.fileURL.path,
            "MACADE_EMBEDDED_VIDEO_BYTES": String(resources.videoStream.byteCount),
            "MACADE_EMBEDDED_INPUT_SOCKET": resources.inputClient.socketPath,
            "MACADE_EMBEDDED_HIDE_WINDOW": "1",
            "MACADE_SINGLE_PLAYER_INPUT": launch.restrictsGamepadToPlayerOne ? "1" : "0",
            "SDL_MAC_BACKGROUND_APP": "1"
        ]
        if launch.mode == .match {
            embeddedEnvironment["quark.log"] = "1"
            embeddedEnvironment["quark.log.timestamps"] = "1"
            embeddedEnvironment["MACADE_QUARK_LOG_DIR"] = resources.launchLog.url.deletingLastPathComponent().path
        }
        embeddedEnvironment.merge(netplayPreparation?.environment ?? [:]) { _, new in new }

        do {
            let process = try launchProcess(
                emulator: launch.emulator,
                arguments: launch.arguments,
                runtime: runtimeRoot,
                expectedROM: expectedROM,
                launchLog: resources.launchLog,
                additionalEnvironment: embeddedEnvironment,
                embeddedSession: session
            )
            session.attach(process: process)
            if case .some(.proxied(let setup)) = netplayPreparation {
                session.attachProxyTask(setup.startTask { [weak session] message in
                    session?.failAndTerminate(message)
                })
            }
            NSApp.activate(ignoringOtherApps: true)
            return session
        } catch {
            close(netplayPreparation)
            session.markFailed(error.localizedDescription)
            throw error
        }
    }

    private func prepareNetplay(for launch: FightcadeEmbeddedLaunch) async throws -> FightcadeEmbeddedNetplayPreparation? {
        guard launch.mode == .match else { return nil }
        guard let match = launch.match else {
            throw FightcadeLaunchError.embeddedBridgeFailed("Missing Fightcade match metadata for embedded netplay.")
        }
        return try await netplayPreparer.prepare(for: match)
    }

    private func close(_ preparation: FightcadeEmbeddedNetplayPreparation?) {
        guard case .some(.proxied(let setup)) = preparation else { return }
        setup.close()
    }
}
