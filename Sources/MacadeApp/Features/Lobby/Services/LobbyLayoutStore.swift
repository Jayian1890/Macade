import Foundation

struct LobbyLayoutStore {
    private let defaults: UserDefaults
    init(defaults: UserDefaults = .standard) { self.defaults = defaults }

    func dimension(for key: String, fallback: CGFloat, range: ClosedRange<CGFloat>) -> CGFloat {
        guard defaults.object(forKey: key) != nil else { return fallback }
        let value = CGFloat(defaults.double(forKey: key))
        guard value.isFinite else { return fallback }
        return min(max(value, range.lowerBound), range.upperBound)
    }

    func save(_ value: CGFloat, for key: String) { defaults.set(Double(value), forKey: key) }
}
