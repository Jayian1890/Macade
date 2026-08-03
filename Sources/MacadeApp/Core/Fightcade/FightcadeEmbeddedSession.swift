import Foundation
import Darwin
import IOKit.pwr_mgt
import Observation

@MainActor
@Observable
final class FightcadeEmbeddedSession {
    enum Mode: String, Sendable {
        case test = "Test"
        case training = "Training"
        case direct = "Direct"
        case match = "Match"
        case spectate = "Spectate"
        case replay = "Replay"
    }

    enum Status: Equatable, Sendable {
        case launching
        case running(processID: Int32)
        case stopping
        case terminated(status: Int32)
        case failed(String)
    }

    let id: UUID
    let channelID: FightcadeChannel.ID
    let mode: Mode
    let emulator: String
    let gameID: String
    let title: String
    let logURL: URL
    let videoStream: FightcadeEmbeddedVideoStream
    let inputClient: FightcadeEmbeddedInputClient

    private var process: Process?
    private var proxyTask: Task<Void, Never>?
    private var forceKillTask: Task<Void, Never>?
    private var sleepAssertion: FightcadeEmbeddedSleepAssertion?
    var status: Status = .launching
    var overlayState: FightcadeEmbeddedOverlayState?
    var videoAspectRatio = 4.0 / 3.0

    init(
        id: UUID,
        channelID: FightcadeChannel.ID,
        mode: Mode,
        emulator: String,
        gameID: String,
        title: String,
        logURL: URL,
        videoStream: FightcadeEmbeddedVideoStream,
        inputClient: FightcadeEmbeddedInputClient
    ) {
        self.id = id
        self.channelID = channelID
        self.mode = mode
        self.emulator = emulator
        self.gameID = gameID
        self.title = title
        self.logURL = logURL
        self.videoStream = videoStream
        self.inputClient = inputClient
    }

    var statusText: String {
        switch status {
        case .launching:
            "Launching"
        case .running(let processID):
            "Running · pid \(processID)"
        case .stopping:
            "Stopping"
        case .terminated(let status):
            "Exited · status \(status)"
        case .failed(let message):
            message
        }
    }

    var isActive: Bool {
        switch status {
        case .launching, .running:
            true
        case .stopping, .terminated, .failed:
            false
        }
    }

    func attach(process: Process, proxyTask: Task<Void, Never>? = nil) {
        self.process = process
        self.proxyTask = proxyTask
        sleepAssertion = FightcadeEmbeddedSleepAssertion(reason: "Macade is running \(emulator.uppercased()) for \(gameID)")
        status = .running(processID: process.processIdentifier)
    }

    func markTerminated(status terminationStatus: Int32) {
        status = .terminated(status: terminationStatus)
        process = nil
        sleepAssertion?.release()
        sleepAssertion = nil
        forceKillTask?.cancel()
        forceKillTask = nil
        proxyTask?.cancel()
        proxyTask = nil
        videoStream.close()
        inputClient.close()
    }

    func markFailed(_ message: String) {
        status = .failed(message)
        process = nil
        sleepAssertion?.release()
        sleepAssertion = nil
        forceKillTask?.cancel()
        forceKillTask = nil
        proxyTask?.cancel()
        proxyTask = nil
        videoStream.close()
        inputClient.close()
    }

    func stop() {
        guard let process, process.isRunning else {
            sleepAssertion?.release()
            sleepAssertion = nil
            forceKillTask?.cancel()
            forceKillTask = nil
            proxyTask?.cancel()
            proxyTask = nil
            videoStream.close()
            inputClient.close()
            return
        }

        status = .stopping
        proxyTask?.cancel()
        proxyTask = nil
        process.terminate()
        let processID = process.processIdentifier
        forceKillTask?.cancel()
        forceKillTask = Task { @MainActor [weak self] in
            try? await Task.sleep(for: .seconds(1))
            guard !Task.isCancelled,
                  self?.process?.processIdentifier == processID,
                  self?.process?.isRunning == true else { return }
            kill(processID, SIGKILL)
        }
    }
}

private final class FightcadeEmbeddedSleepAssertion {
    private var systemAssertionID: IOPMAssertionID = 0
    private var displayAssertionID: IOPMAssertionID = 0

    init(reason: String) {
        acquire(kIOPMAssertionTypePreventUserIdleSystemSleep as CFString, id: &systemAssertionID, reason: reason)
        acquire(kIOPMAssertionTypePreventUserIdleDisplaySleep as CFString, id: &displayAssertionID, reason: reason)
    }

    deinit {
        release()
    }

    func release() {
        release(id: &systemAssertionID)
        release(id: &displayAssertionID)
    }

    private func acquire(_ type: CFString, id: inout IOPMAssertionID, reason: String) {
        let result = IOPMAssertionCreateWithName(
            type,
            IOPMAssertionLevel(kIOPMAssertionLevelOn),
            reason as CFString,
            &id
        )
        if result != kIOReturnSuccess {
            id = 0
        }
    }

    private func release(id: inout IOPMAssertionID) {
        guard id != 0 else { return }
        IOPMAssertionRelease(id)
        id = 0
    }
}

struct FightcadeEmbeddedLaunch: Sendable, Equatable {
    let channelID: FightcadeChannel.ID
    let mode: FightcadeEmbeddedSession.Mode
    let emulator: String
    let gameID: String
    let arguments: [String]
    let title: String
    let match: FightcadeMatchLaunch?

    static func test(channelID: FightcadeChannel.ID, emulator: String, gameID: String) -> FightcadeEmbeddedLaunch {
        FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .test,
            emulator: emulator,
            gameID: gameID,
            arguments: [gameID],
            title: "Test · \(gameID)",
            match: nil
        )
    }

    static func training(channelID: FightcadeChannel.ID, emulator: String, gameID: String) -> FightcadeEmbeddedLaunch {
        FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .training,
            emulator: emulator,
            gameID: gameID,
            arguments: [FightcadeLocalTrainingLaunch(emulator: emulator, gameID: gameID).command],
            title: "Training · \(gameID)",
            match: nil
        )
    }

    static func match(channelID: FightcadeChannel.ID, match: FightcadeMatchLaunch) -> FightcadeEmbeddedLaunch {
        FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .match,
            emulator: match.emulator,
            gameID: match.gameID,
            arguments: [match.quarkCommand],
            title: "Match · \(match.gameID)",
            match: match
        )
    }

    static func fightcadeTraining(channelID: FightcadeChannel.ID, launch: FightcadeTrainingLaunch) -> FightcadeEmbeddedLaunch {
        FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .training,
            emulator: launch.emulator,
            gameID: launch.gameID,
            arguments: [launch.quarkCommand],
            title: "Training · \(launch.gameID)",
            match: nil
        )
    }

    static func direct(channelID: FightcadeChannel.ID, launch: FightcadeDirectLaunch) -> FightcadeEmbeddedLaunch {
        FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .direct,
            emulator: launch.emulator,
            gameID: launch.gameID,
            arguments: [launch.quarkCommand],
            title: "Direct · \(launch.gameID)",
            match: nil
        )
    }

    static func spectate(
        channelID: FightcadeChannel.ID,
        emulator: String,
        gameID: String,
        quarkID: String,
        port: Int
    ) -> FightcadeEmbeddedLaunch {
        let launch = FightcadeSpectateLaunch(emulator: emulator, gameID: gameID, quarkID: quarkID, port: port)
        return FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .spectate,
            emulator: emulator,
            gameID: gameID,
            arguments: [launch.quarkCommand],
            title: "Spectating · \(gameID)",
            match: nil
        )
    }

    static func replay(channelID: FightcadeChannel.ID, launch: FightcadeReplayLaunch) -> FightcadeEmbeddedLaunch {
        FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .replay,
            emulator: launch.emulator,
            gameID: launch.gameID,
            arguments: [launch.quarkCommand],
            title: "Replay · \(launch.gameID)",
            match: nil
        )
    }

    static func replayStream(channelID: FightcadeChannel.ID, launch: FightcadeReplayStreamLaunch) -> FightcadeEmbeddedLaunch {
        FightcadeEmbeddedLaunch(
            channelID: channelID,
            mode: .replay,
            emulator: launch.emulator,
            gameID: launch.gameID,
            arguments: [launch.quarkCommand],
            title: "Replay · \(launch.gameID)",
            match: nil
        )
    }
}
