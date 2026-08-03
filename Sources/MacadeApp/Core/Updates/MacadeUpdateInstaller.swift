import AppKit
import Darwin
import Foundation

@MainActor
struct MacadeUpdateInstaller {
    var fileManager: FileManager = .default

    func installAndRelaunch(updateFileURL: URL, installedAppURL: URL = Bundle.main.bundleURL) async throws {
        let stagingRoot = try stagingDirectory()
        let payloadURL = try await preparedPayload(from: updateFileURL, stagingRoot: stagingRoot)
        let scriptURL = try writeInstallerScript(to: stagingRoot)
        let mode = updateFileURL.pathExtension.lowercased() == "pkg" ? "pkg" : "app"

        let process = Process()
        process.executableURL = URL(fileURLWithPath: "/usr/bin/nohup")
        process.arguments = [
            "/bin/sh",
            scriptURL.path,
            mode,
            installedAppURL.path,
            payloadURL.path,
            String(ProcessInfo.processInfo.processIdentifier),
            stagingRoot.path
        ]
        let nullInput = try FileHandle(forReadingFrom: URL(fileURLWithPath: "/dev/null"))
        let nullOutput = try FileHandle(forWritingTo: URL(fileURLWithPath: "/dev/null"))
        process.standardInput = nullInput
        process.standardOutput = nullOutput
        process.standardError = nullOutput
        try process.run()
        requestApplicationExit()
    }

    private func requestApplicationExit() {
        ProcessInfo.processInfo.enableSuddenTermination()
        NSApplication.shared.terminate(nil)
        DispatchQueue.main.asyncAfter(deadline: .now() + 1) {
            exit(EXIT_SUCCESS)
        }
    }

    private func preparedPayload(from updateFileURL: URL, stagingRoot: URL) async throws -> URL {
        switch updateFileURL.pathExtension.lowercased() {
        case "zip":
            return try prepareZip(updateFileURL, stagingRoot: stagingRoot)
        case "dmg":
            return try prepareDiskImage(updateFileURL, stagingRoot: stagingRoot)
        case "pkg":
            return updateFileURL
        default:
            throw MacadeUpdaterError.unsupportedInstallAsset
        }
    }

    private func prepareZip(_ fileURL: URL, stagingRoot: URL) throws -> URL {
        let extractURL = stagingRoot.appendingPathComponent("Extracted", isDirectory: true)
        try fileManager.createDirectory(at: extractURL, withIntermediateDirectories: true)
        try run(URL(fileURLWithPath: "/usr/bin/ditto"), arguments: ["-x", "-k", fileURL.path, extractURL.path])
        return try stageApplication(from: extractURL, stagingRoot: stagingRoot)
    }

    private func prepareDiskImage(_ fileURL: URL, stagingRoot: URL) throws -> URL {
        let mountURL = stagingRoot.appendingPathComponent("Mount", isDirectory: true)
        try fileManager.createDirectory(at: mountURL, withIntermediateDirectories: true)
        try run(URL(fileURLWithPath: "/usr/bin/hdiutil"), arguments: [
            "attach", fileURL.path, "-mountpoint", mountURL.path, "-nobrowse", "-readonly", "-quiet"
        ])
        defer { try? run(URL(fileURLWithPath: "/usr/bin/hdiutil"), arguments: ["detach", mountURL.path, "-quiet"]) }
        return try stageApplication(from: mountURL, stagingRoot: stagingRoot)
    }

    private func stageApplication(from rootURL: URL, stagingRoot: URL) throws -> URL {
        guard let appURL = findApplication(in: rootURL) else {
            throw MacadeUpdaterError.noInstallableAsset
        }

        let stagedURL = stagingRoot.appendingPathComponent("Macade.app", isDirectory: true)
        try? fileManager.removeItem(at: stagedURL)
        try run(URL(fileURLWithPath: "/usr/bin/ditto"), arguments: [appURL.path, stagedURL.path])
        return stagedURL
    }

    private func findApplication(in rootURL: URL) -> URL? {
        guard let enumerator = fileManager.enumerator(
            at: rootURL,
            includingPropertiesForKeys: [.isDirectoryKey],
            options: [.skipsHiddenFiles]
        ) else {
            return nil
        }

        for case let url as URL in enumerator where url.pathExtension == "app" {
            if url.lastPathComponent.caseInsensitiveCompare("Macade.app") == .orderedSame {
                return url
            }
        }
        return nil
    }

    private func stagingDirectory() throws -> URL {
        let root = try fileManager.url(
            for: .applicationSupportDirectory,
            in: .userDomainMask,
            appropriateFor: nil,
            create: true
        )
        .appendingPathComponent("Macade/Updates/Staged", isDirectory: true)
        .appendingPathComponent(UUID().uuidString, isDirectory: true)
        try fileManager.createDirectory(at: root, withIntermediateDirectories: true)
        return root
    }

    private func writeInstallerScript(to stagingRoot: URL) throws -> URL {
        let scriptURL = stagingRoot.appendingPathComponent("install-update.sh")
        try scriptText.write(to: scriptURL, atomically: true, encoding: .utf8)
        return scriptURL
    }

    private func run(_ executableURL: URL, arguments: [String]) throws {
        let process = Process()
        process.executableURL = executableURL
        process.arguments = arguments
        try process.run()
        process.waitUntilExit()
        guard process.terminationStatus == 0 else {
            throw MacadeUpdaterError.installFailed
        }
    }

    private var scriptText: String {
        """
        #!/bin/sh
        set -eu

        mode="$1"
        current_app="$2"
        payload="$3"
        parent_pid="$4"
        staging="$5"
        log="$staging/install.log"
        exec >> "$log" 2>&1

        waits=0
        while kill -0 "$parent_pid" 2>/dev/null && [ "$waits" -lt 120 ]; do
          sleep 0.5
          waits=$((waits + 1))
        done

        if [ "$mode" = "pkg" ]; then
          /usr/sbin/installer -pkg "$payload" -target CurrentUserHomeDirectory || /usr/sbin/installer -pkg "$payload" -target /
        else
          backup="$current_app.old"
          restore_backup() {
            if [ -d "$backup" ] && [ ! -d "$current_app" ]; then
              mv "$backup" "$current_app"
            fi
          }
          trap restore_backup EXIT
          rm -rf "$backup"
          if [ -d "$current_app" ]; then
            mv "$current_app" "$backup"
          fi
          /usr/bin/ditto "$payload" "$current_app"
          /usr/bin/xattr -dr com.apple.quarantine "$current_app" 2>/dev/null || true
          trap - EXIT
          rm -rf "$backup"
        fi

        /usr/bin/open "$current_app" || /usr/bin/open -a Macade
        (sleep 5; rm -rf "$staging") &
        exit 0
        """
    }
}
