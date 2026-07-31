import SwiftUI

@MainActor
final class MacadeAppDelegate: NSObject, NSApplicationDelegate {
    func applicationDidFinishLaunching(_ notification: Notification) {
        ProcessInfo.processInfo.disableSuddenTermination()
        NSApplication.shared.appearance = NSAppearance(named: .darkAqua)
        configureApplicationIcon()
    }

    func applicationShouldTerminate(_ sender: NSApplication) -> NSApplication.TerminateReply {
        FightcadeProcessRegistry.shared.terminateAll(
            reason: "application should terminate",
            rejectFutureLaunches: true
        )
        return .terminateNow
    }

    func applicationShouldTerminateAfterLastWindowClosed(_ sender: NSApplication) -> Bool {
        true
    }

    func applicationWillTerminate(_ notification: Notification) {
        FightcadeProcessRegistry.shared.terminateAll(
            reason: "application terminating",
            rejectFutureLaunches: true
        )
    }

    private func configureApplicationIcon() {
        if let icon = NSImage(named: "AppIcon") {
            NSApplication.shared.applicationIconImage = icon
            return
        }

        guard let iconURL = MacadeResourceBundle.bundle.url(
            forResource: "icon_1024",
            withExtension: "png",
            subdirectory: "Assets.xcassets/AppIcon.appiconset"
        ), let icon = NSImage(contentsOf: iconURL) else {
            return
        }

        NSApplication.shared.applicationIconImage = icon
    }
}

@main
struct MacadeApp: App {
    @NSApplicationDelegateAdaptor(MacadeAppDelegate.self) private var appDelegate

    var body: some Scene {
        WindowGroup {
            RootView()
                .frame(minWidth: 980, minHeight: 640)
                .preferredColorScheme(.dark)
                .tint(MacadeColor.warning)
        }
        .windowStyle(.hiddenTitleBar)
        .defaultSize(width: 1120, height: 720)
        .commands {
            CommandGroup(after: .appInfo) {
                Button("Check for Updates...") {
                    MacadeUpdateController.shared.showAndCheck()
                }
                .keyboardShortcut("u", modifiers: [.command])
            }
        }

        Settings {
            MacadeSettingsView()
        }
    }
}
