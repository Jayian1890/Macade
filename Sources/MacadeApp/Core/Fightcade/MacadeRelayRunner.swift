import Foundation

@MainActor
enum MacadeRelayRunner {
    static func run(_ lane: MacadeRelayLane, using inputClient: FightcadeEmbeddedInputClient) async {
        let frames = lane.frames.filter { !$0.scancodes.isEmpty }
        guard !frames.isEmpty else { return }

        var pressedScancodes: [Int32] = []
        func releasePressedScancodes() {
            for scancode in pressedScancodes.reversed() {
                inputClient.sendKey(scancode: scancode, isPressed: false)
            }
            pressedScancodes.removeAll()
        }

        defer { releasePressedScancodes() }

        for frame in frames {
            if Task.isCancelled { return }
            let scancodes = frame.scancodes
            guard !scancodes.isEmpty else { continue }

            let staleScancodes = pressedScancodes.reversed().filter { !scancodes.contains($0) }
            for scancode in staleScancodes {
                inputClient.sendKey(scancode: scancode, isPressed: false)
                pressedScancodes.removeAll { $0 == scancode }
            }

            for scancode in scancodes where !pressedScancodes.contains(scancode) {
                inputClient.sendKey(scancode: scancode, isPressed: true)
                pressedScancodes.append(scancode)
            }

            do {
                try await Task.sleep(for: .milliseconds(frame.holdMilliseconds))
            } catch {
                return
            }

            if frame.gapMilliseconds > 0 {
                releasePressedScancodes()
            }

            do {
                try await Task.sleep(for: .milliseconds(frame.gapMilliseconds))
            } catch {
                return
            }
        }
    }
}
