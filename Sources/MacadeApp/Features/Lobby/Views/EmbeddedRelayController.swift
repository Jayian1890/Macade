import AppKit

@MainActor
final class EmbeddedRelayController {
    private let profileStore = MacadeRelayProfileStore()
    private var profile = MacadeRelayProfileStore().load()
    private var suppressedKeyUps = Set<UInt16>()
    private var workItem: Task<Void, Never>?
    private var observer: NSObjectProtocol?

    init() {
        observer = NotificationCenter.default.addObserver(
            forName: .macadeRelayProfileDidChange,
            object: nil,
            queue: .main
        ) { [weak self] _ in
            Task { @MainActor in
                self?.profile = self?.profileStore.load() ?? .defaults
            }
        }
    }

    isolated deinit {
        if let observer {
            NotificationCenter.default.removeObserver(observer)
        }
    }

    func reset() {
        workItem?.cancel()
        workItem = nil
        suppressedKeyUps.removeAll()
        profile = profileStore.load()
    }

    @discardableResult
    func keyDown(with event: NSEvent, session: FightcadeEmbeddedSession) -> Bool {
        guard let key = MacadeRelayKey.match(event.keyCode) else {
            return false
        }

        guard let lane = profile.lane(for: key), lane.isRunnable else {
            return false
        }

        if suppressedKeyUps.contains(event.keyCode) || event.isARepeat {
            return true
        }

        suppressedKeyUps.insert(event.keyCode)
        workItem?.cancel()
        workItem = Task { @MainActor in
            await MacadeRelayRunner.run(lane, using: session.inputClient)
        }
        return true
    }

    @discardableResult
    func keyUp(with event: NSEvent) -> Bool {
        suppressedKeyUps.remove(event.keyCode) != nil
    }
}
