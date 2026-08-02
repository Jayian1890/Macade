import Foundation

struct FightcadeNetplayPreferences {
    static let automaticPortMappingDefaultsKey = "FightcadeAutomaticPortMappingEnabled"

    private let userDefaults: UserDefaults

    init(userDefaults: UserDefaults = .standard) {
        self.userDefaults = userDefaults
    }

    var automaticPortMappingEnabled: Bool {
        get { userDefaults.bool(forKey: Self.automaticPortMappingDefaultsKey) }
        nonmutating set { userDefaults.set(newValue, forKey: Self.automaticPortMappingDefaultsKey) }
    }
}
