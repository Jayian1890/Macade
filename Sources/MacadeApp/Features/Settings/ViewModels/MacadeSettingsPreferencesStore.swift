import Foundation

struct MacadeSettingsPreferencesStore {
    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    var forceWiredConnectionStatus: Bool {
        get { userDefaults.bool(forKey: FightcadeConnectionStatusOverride.forceWiredDefaultsKey) }
        nonmutating set { userDefaults.set(newValue, forKey: FightcadeConnectionStatusOverride.forceWiredDefaultsKey) }
    }

    var automaticPortMappingEnabled: Bool {
        get { FightcadeNetplayPreferences(userDefaults: userDefaults).automaticPortMappingEnabled }
        nonmutating set { FightcadeNetplayPreferences(userDefaults: userDefaults).automaticPortMappingEnabled = newValue }
    }

    var lobbyDiagnosticsEnabled: Bool {
        get { diagnosticsSettings.isEnabled }
        nonmutating set { diagnosticsSettings.isEnabled = newValue }
    }

    var includeLobbyDiagnosticChatBodies: Bool {
        get { diagnosticsSettings.includesChatBodies }
        nonmutating set { diagnosticsSettings.includesChatBodies = newValue }
    }

    var chatTranslationPreferences: ChatTranslationPreferences {
        get { ChatTranslationPreferencesStore(userDefaults: userDefaults).load() }
        nonmutating set { ChatTranslationPreferencesStore(userDefaults: userDefaults).save(newValue) }
    }

    var controllerPreferences: MacadeControllerPreferences {
        get { MacadeControllerPreferencesStore(userDefaults: userDefaults).load() }
        nonmutating set { MacadeControllerPreferencesStore(userDefaults: userDefaults).save(newValue) }
    }

    var lobbyDiagnosticsLogPath: String {
        diagnosticsSettings.relativeLogPath
    }

    private var diagnosticsSettings: FightcadeLobbyDiagnosticsSettings {
        FightcadeLobbyDiagnosticsSettings(userDefaults: userDefaults)
    }
}
