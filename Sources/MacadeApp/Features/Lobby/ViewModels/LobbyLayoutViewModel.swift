import Foundation
import Observation

@MainActor
@Observable
final class LobbyLayoutViewModel {
    var sidebarWidth: CGFloat {
        didSet {
            store.save(sidebarWidth, for: Self.sidebarKey)
            if isSidebarPinned { expandedSidebarWidth = sidebarWidth }
        }
    }
    var playerListWidth: CGFloat { didSet { store.save(playerListWidth, for: Self.playersKey) } }
    var playerDetailsHeight: CGFloat { didSet { store.save(playerDetailsHeight, for: Self.detailsKey) } }
    private var expandedSidebarWidth: CGFloat
    private(set) var isSidebarHovering = false
    @ObservationIgnored private var sidebarHoverTask: Task<Void, Never>?
    private let store: LobbyLayoutStore
    private static let sidebarKey = "lobbySidebarWidth"
    private static let playersKey = "playerListSidebarWidth"
    private static let detailsKey = "playerDetailsHeight"

    init(store: LobbyLayoutStore = LobbyLayoutStore()) {
        self.store = store
        expandedSidebarWidth = MacadeLayout.sidebarDefault
        sidebarWidth = store.dimension(for: Self.sidebarKey, fallback: MacadeLayout.sidebarDefault,
            range: MacadeLayout.sidebarCompact...MacadeLayout.sidebarMaximum)
        playerListWidth = store.dimension(for: Self.playersKey, fallback: MacadeLayout.playersDefault,
            range: MacadeLayout.playersMinimum...MacadeLayout.playersMaximum)
        playerDetailsHeight = store.dimension(for: Self.detailsKey, fallback: MacadeLayout.detailsDefault,
            range: MacadeLayout.detailsMinimum...MacadeLayout.detailsMaximum)
        expandedSidebarWidth = max(sidebarWidth, MacadeLayout.sidebarDefault)
    }

    var isSidebarPinned: Bool { sidebarWidth >= MacadeLayout.sidebarLabelThreshold }
    var isSidebarExpanded: Bool { isSidebarPinned || isSidebarHovering }
    var displayedSidebarWidth: CGFloat {
        isSidebarHovering && !isSidebarPinned ? expandedSidebarWidth : sidebarWidth
    }

    func updateSidebarHover(_ hovering: Bool) {
        sidebarHoverTask?.cancel()
        sidebarHoverTask = Task { @MainActor [weak self] in
            try? await Task.sleep(for: .milliseconds(hovering ? 140 : 120))
            guard !Task.isCancelled else { return }
            self?.isSidebarHovering = hovering
        }
    }

    func endSidebarHover() {
        sidebarHoverTask?.cancel()
        sidebarHoverTask = nil
        isSidebarHovering = false
    }

    func toggleSidebar() {
        if isSidebarPinned {
            expandedSidebarWidth = sidebarWidth
            sidebarWidth = MacadeLayout.sidebarCompact
        } else {
            sidebarWidth = expandedSidebarWidth
        }
    }

    func expandSidebar() {
        if !isSidebarPinned { sidebarWidth = expandedSidebarWidth }
    }
}
