import AppKit
import Foundation
import Observation

@MainActor
@Observable
final class MacadeUpdateController {
    static let shared = MacadeUpdateController()

    var status: MacadeUpdateStatus = .idle
    var isPresented = false

    private let updater: GitHubReleaseUpdater
    private let installer: MacadeUpdateInstaller
    private let defaults: UserDefaults
    private let currentVersion: String
    private var hasCheckedThisLaunch = false
    private var automaticUpdateTask: Task<Void, Never>?

    init(
        updater: GitHubReleaseUpdater = GitHubReleaseUpdater(),
        installer: MacadeUpdateInstaller = MacadeUpdateInstaller(),
        defaults: UserDefaults = .standard,
        currentVersion: String = Bundle.main.object(forInfoDictionaryKey: "CFBundleShortVersionString") as? String ?? "0.0.0"
    ) {
        self.updater = updater
        self.installer = installer
        self.defaults = defaults
        self.currentVersion = currentVersion
    }

    var currentVersionLabel: String { currentVersion }

    var availableUpdate: MacadeUpdate? {
        switch status {
        case .available(let update), .scheduled(let update, _), .downloading(let update), .downloaded(let update, _), .installing(let update): update
        default: nil
        }
    }

    func checkAutomatically() async {
        guard !hasCheckedThisLaunch else { return }
        hasCheckedThisLaunch = true
        guard shouldRunAutomaticCheck else { return }
        await checkForUpdates(presentWhenCurrent: false, presentFailures: false, respectDeferredUpdate: true)
    }

    func showAndCheck() {
        isPresented = true
        Task { await checkForUpdates(presentWhenCurrent: true, presentFailures: true, respectDeferredUpdate: false) }
    }

    func checkForUpdates(
        presentWhenCurrent: Bool = true,
        presentFailures: Bool = true,
        respectDeferredUpdate: Bool = false
    ) async {
        automaticUpdateTask?.cancel()
        status = .checking
        defaults.set(Date(), forKey: Keys.lastCheckDate)
        do {
            if let update = try await updater.latestUpdate(currentVersion: currentVersion) {
                guard !respectDeferredUpdate || !isDeferred(update) else {
                    status = .current
                    return
                }
                status = .available(update)
                isPresented = true
                scheduleAutomaticInstall(update)
            } else {
                status = .current
                if presentWhenCurrent { isPresented = true }
            }
        } catch {
            status = .failed(error.localizedDescription)
            if presentFailures { isPresented = true }
        }
    }

    func updateLater() {
        guard let update = availableUpdate else { return }
        automaticUpdateTask?.cancel()
        defaults.set(update.tagName, forKey: Keys.deferredTag)
        defaults.set(Date().addingTimeInterval(12 * 60 * 60), forKey: Keys.deferredUntil)
        status = .idle
        isPresented = false
    }

    func openReleasePage() {
        guard let url = availableUpdate?.htmlURL else { return }
        NSWorkspace.shared.open(url)
    }

    private func scheduleAutomaticInstall(_ update: MacadeUpdate) {
        automaticUpdateTask?.cancel()
        automaticUpdateTask = Task { @MainActor [weak self] in
            guard let self else { return }
            for seconds in stride(from: 15, through: 1, by: -1) {
                guard !Task.isCancelled else { return }
                status = .scheduled(update, secondsRemaining: seconds)
                try? await Task.sleep(for: .seconds(1))
            }
            await downloadAndInstall(update)
        }
    }

    private func downloadAndInstall(_ update: MacadeUpdate) async {
        guard !Task.isCancelled else { return }
        status = .downloading(update)
        do {
            let fileURL = try await updater.download(update)
            guard !Task.isCancelled else { return }
            status = .downloaded(update, fileURL)
            status = .installing(update)
            try await installer.installAndRelaunch(updateFileURL: fileURL)
        } catch {
            guard !Task.isCancelled else { return }
            status = .failed(error.localizedDescription)
            isPresented = true
        }
    }

    private func isDeferred(_ update: MacadeUpdate) -> Bool {
        guard defaults.string(forKey: Keys.deferredTag) == update.tagName,
              let deferredUntil = defaults.object(forKey: Keys.deferredUntil) as? Date else {
            return false
        }

        if Date() < deferredUntil {
            return true
        }

        defaults.removeObject(forKey: Keys.deferredTag)
        defaults.removeObject(forKey: Keys.deferredUntil)
        return false
    }

    private var shouldRunAutomaticCheck: Bool {
        if ProcessInfo.processInfo.environment["MACADE_DISABLE_UPDATE_CHECK"] == "1" {
            return false
        }
        guard let last = defaults.object(forKey: Keys.lastCheckDate) as? Date else {
            return true
        }
        return Date().timeIntervalSince(last) > 12 * 60 * 60
    }
}

private enum Keys {
    static let lastCheckDate = "MacadeUpdater.lastCheckDate"
    static let deferredTag = "MacadeUpdater.deferredTag"
    static let deferredUntil = "MacadeUpdater.deferredUntil"
}
