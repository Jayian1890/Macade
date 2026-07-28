import Foundation
import Observation

@MainActor
@Observable
final class MacadeSettingsViewModel {
    enum Section: String, CaseIterable, Identifiable {
        case general
        case connection
        case emulator
        case controllers
        case diagnostics
        case advanced

        var id: String { rawValue }

        var title: String {
            switch self {
            case .general: "General"
            case .connection: "Connection"
            case .emulator: "Emulator"
            case .controllers: "Controllers"
            case .diagnostics: "Privacy & Diagnostics"
            case .advanced: "Advanced"
            }
        }

        var symbolName: String {
            switch self {
            case .general: "gearshape"
            case .connection: "network"
            case .emulator: "arcade.stick.console"
            case .controllers: "gamecontroller"
            case .diagnostics: "lock.shield"
            case .advanced: "slider.horizontal.3"
            }
        }
    }

    var selectedSection: Section
    var fbneoSettings = FightcadeFBNeoSettings.defaults
    var forceWiredConnectionStatus = false
    var lobbyDiagnosticsEnabled = false {
        didSet {
            if !lobbyDiagnosticsEnabled {
                includeLobbyDiagnosticChatBodies = false
            }
        }
    }
    var includeLobbyDiagnosticChatBodies = false
    var statusMessage: String?
    var isLoaded = false

    private let fbneoStore: any FightcadeFBNeoSettingsPersisting
    private let preferencesStore: MacadeSettingsPreferencesStore
    private var savedFBNeoSettings = FightcadeFBNeoSettings.defaults
    private var savedForceWiredConnectionStatus = false
    private var savedLobbyDiagnosticsEnabled = false
    private var savedIncludeLobbyDiagnosticChatBodies = false

    init(
        selectedSection: Section = .general,
        fbneoStore: any FightcadeFBNeoSettingsPersisting = FightcadeFBNeoSettingsStore(),
        preferencesStore: MacadeSettingsPreferencesStore = MacadeSettingsPreferencesStore()
    ) {
        self.selectedSection = selectedSection
        self.fbneoStore = fbneoStore
        self.preferencesStore = preferencesStore
    }

    var hasUnsavedChanges: Bool {
        fbneoSettings.normalized() != savedFBNeoSettings.normalized()
            || forceWiredConnectionStatus != savedForceWiredConnectionStatus
            || lobbyDiagnosticsEnabled != savedLobbyDiagnosticsEnabled
            || includeLobbyDiagnosticChatBodies != savedIncludeLobbyDiagnosticChatBodies
    }

    var lobbyDiagnosticsLogPath: String {
        preferencesStore.lobbyDiagnosticsLogPath
    }

    var fbneoConfigurationPath: String {
        (try? fbneoStore.configurationFileURL().path) ?? "Unavailable"
    }

    var controllerDatabasePath: String {
        (try? fbneoStore.controllerDatabaseURL().path) ?? "Unavailable"
    }

    func load() {
        do {
            fbneoSettings = try fbneoStore.load()
            statusMessage = nil
        } catch {
            fbneoSettings = .defaults
            statusMessage = "Using default emulator settings."
        }

        forceWiredConnectionStatus = preferencesStore.forceWiredConnectionStatus
        lobbyDiagnosticsEnabled = preferencesStore.lobbyDiagnosticsEnabled
        includeLobbyDiagnosticChatBodies = preferencesStore.includeLobbyDiagnosticChatBodies
        markSaved()
        isLoaded = true
    }

    func save() {
        do {
            fbneoSettings = fbneoSettings.normalized()
            try fbneoStore.save(fbneoSettings)
            preferencesStore.forceWiredConnectionStatus = forceWiredConnectionStatus
            preferencesStore.lobbyDiagnosticsEnabled = lobbyDiagnosticsEnabled
            preferencesStore.includeLobbyDiagnosticChatBodies = lobbyDiagnosticsEnabled && includeLobbyDiagnosticChatBodies
            includeLobbyDiagnosticChatBodies = preferencesStore.includeLobbyDiagnosticChatBodies
            markSaved()
            statusMessage = "Settings saved."
        } catch {
            statusMessage = "Settings could not be saved. Check folder permissions."
        }
    }

    func discardChanges() {
        fbneoSettings = savedFBNeoSettings
        forceWiredConnectionStatus = savedForceWiredConnectionStatus
        lobbyDiagnosticsEnabled = savedLobbyDiagnosticsEnabled
        includeLobbyDiagnosticChatBodies = savedIncludeLobbyDiagnosticChatBodies
        statusMessage = nil
    }

    func resetEmulatorSettings() {
        fbneoSettings = .defaults
        statusMessage = "Emulator settings reset. Save to apply."
    }

    func clearControllerMappings() {
        fbneoSettings.controllerMappings = ""
        statusMessage = "Controller mappings cleared. Save to apply."
    }

    private func markSaved() {
        savedFBNeoSettings = fbneoSettings.normalized()
        savedForceWiredConnectionStatus = forceWiredConnectionStatus
        savedLobbyDiagnosticsEnabled = lobbyDiagnosticsEnabled
        savedIncludeLobbyDiagnosticChatBodies = includeLobbyDiagnosticChatBodies
    }
}
