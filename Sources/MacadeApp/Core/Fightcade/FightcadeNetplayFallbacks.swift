import Foundation

struct FightcadePortFallbacks {
    static func normalNATCandidates(around port: Int, radius: Int = 512) -> [Int] {
        guard radius > 0 else { return [] }
        return (1...radius).flatMap { offset in
            [wrappedPort(port + offset), wrappedPort(port - offset)]
        }
    }

    static func prioritizedCandidates(
        observedPort: Int,
        basePort: Int,
        plan: FightcadeQuarkSessionPlan,
        radius: Int = 512,
        includeBasePort: Bool
    ) -> [Int] {
        var ports: [Int] = []
        appendUnique(observedPort, to: &ports)
        if includeBasePort { appendUnique(basePort, to: &ports) }
        [6000, 6004, plan.restrictedNATFallbackPort, plan.fixedFallbackPort].forEach { appendUnique($0, to: &ports) }
        normalNATCandidates(around: basePort, radius: radius).forEach { appendUnique($0, to: &ports) }
        return ports.filter { $0 > 0 && $0 <= 65535 }
    }

    private static func appendUnique(_ port: Int, to ports: inout [Int]) {
        guard !ports.contains(port) else { return }
        ports.append(wrappedPort(port))
    }

    private static func wrappedPort(_ port: Int) -> Int {
        if port < 1 { return 65535 + port }
        if port > 65535 { return port - 65535 }
        return port
    }
}
