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
    private let defaults: UserDefaults
    private let currentVersion: String
    private var hasCheckedThisLaunch = false

    init(
        updater: GitHubReleaseUpdater = GitHubReleaseUpdater(),
        defaults: UserDefaults = .standard,
        currentVersion: String = Bundle.main.object(forInfoDictionaryKey: "CFBundleShortVersionString") as? String ?? "0.0.0"
    ) {
        self.updater = updater
        self.defaults = defaults
        self.currentVersion = currentVersion
    }

    var currentVersionLabel: String { currentVersion }

    var availableUpdate: MacadeUpdate? {
        switch status {
        case .available(let update), .downloading(let update), .downloaded(let update, _): update
        default: nil
        }
    }

    func checkAutomatically() async {
        guard !hasCheckedThisLaunch else { return }
        hasCheckedThisLaunch = true
        guard shouldRunAutomaticCheck else { return }
        await checkForUpdates(presentWhenCurrent: false, presentFailures: false)
    }

    func showAndCheck() {
        isPresented = true
        Task { await checkForUpdates(presentWhenCurrent: true, presentFailures: true) }
    }

    func checkForUpdates(presentWhenCurrent: Bool = true, presentFailures: Bool = true) async {
        status = .checking
        defaults.set(Date(), forKey: Keys.lastCheckDate)
        do {
            if let update = try await updater.latestUpdate(currentVersion: currentVersion) {
                guard update.tagName != defaults.string(forKey: Keys.skippedTag) else {
                    status = .current
                    return
                }
                status = .available(update)
                isPresented = true
            } else {
                status = .current
                if presentWhenCurrent { isPresented = true }
            }
        } catch {
            status = .failed(error.localizedDescription)
            if presentFailures { isPresented = true }
        }
    }

    func downloadAvailableUpdate() {
        guard let update = availableUpdate else { return }
        status = .downloading(update)
        Task {
            do {
                let fileURL = try await updater.download(update)
                status = .downloaded(update, fileURL)
            } catch {
                status = .failed(error.localizedDescription)
            }
        }
    }

    func openDownloadedUpdate() {
        guard case .downloaded(_, let fileURL) = status else { return }
        NSWorkspace.shared.activateFileViewerSelecting([fileURL])
        NSWorkspace.shared.open(fileURL)
    }

    func openReleasePage() {
        guard let url = availableUpdate?.htmlURL else { return }
        NSWorkspace.shared.open(url)
    }

    func skipAvailableUpdate() {
        guard let update = availableUpdate else { return }
        defaults.set(update.tagName, forKey: Keys.skippedTag)
        status = .idle
        isPresented = false
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
    static let skippedTag = "MacadeUpdater.skippedTag"
}
