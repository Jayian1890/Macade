import Foundation

struct EmbeddedVideoDisplayPolicy: Equatable, Sendable {
    let refreshRate: Int

    init(refreshRate: Int) {
        self.refreshRate = max(1, refreshRate)
    }

    var usesBurstBuffer: Bool { refreshRate <= 60 }
    var frameIntervalMilliseconds: Double { 1_000 / Double(refreshRate) }
}
