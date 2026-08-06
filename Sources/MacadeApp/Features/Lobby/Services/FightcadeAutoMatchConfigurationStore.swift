import Foundation

protocol FightcadeAutoMatchConfigurationPersisting: Sendable {
    func configuration(for session: AuthSession, channelName: String) -> FightcadeAutoMatchConfiguration
    func saveConfiguration(_ configuration: FightcadeAutoMatchConfiguration, for session: AuthSession, channelName: String)
}

struct UserDefaultsFightcadeAutoMatchConfigurationStore: FightcadeAutoMatchConfigurationPersisting, @unchecked Sendable {
    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    func configuration(for session: AuthSession, channelName: String) -> FightcadeAutoMatchConfiguration {
        guard let data = userDefaults.data(forKey: key(session: session, channelName: channelName)),
              let configuration = try? JSONDecoder().decode(FightcadeAutoMatchConfiguration.self, from: data) else {
            return .default
        }

        return configuration
    }

    func saveConfiguration(_ configuration: FightcadeAutoMatchConfiguration, for session: AuthSession, channelName: String) {
        guard let data = try? JSONEncoder().encode(configuration) else {
            return
        }

        userDefaults.set(data, forKey: key(session: session, channelName: channelName))
    }

    private func key(session: AuthSession, channelName: String) -> String {
        "autoMatch.configuration.\(normalized(session.username)).\(normalized(channelName))"
    }

    private func normalized(_ value: String) -> String {
        value.folding(options: [.caseInsensitive, .diacriticInsensitive], locale: nil)
            .trimmingCharacters(in: .whitespacesAndNewlines)
            .lowercased()
    }
}
