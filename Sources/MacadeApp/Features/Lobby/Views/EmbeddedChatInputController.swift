import AppKit

@MainActor
final class EmbeddedChatInputController {
    private static let maxUTF8Bytes = 128

    private var isActive = false
    private var text = ""
    private var suppressedKeyUps: Set<UInt16> = []

    var active: Bool { isActive }

    func begin(session: FightcadeEmbeddedSession?) {
        isActive = true
        text = ""
        suppressedKeyUps.removeAll()
        session?.inputClient.beginChat()
    }

    func cancel(session: FightcadeEmbeddedSession?) {
        session?.inputClient.cancelChat()
        reset()
        suppressedKeyUps.removeAll()
    }

    func keyDown(with event: NSEvent, session: FightcadeEmbeddedSession?) -> Bool {
        if isActive {
            suppressedKeyUps.insert(event.keyCode)
            handleActiveKeyDown(event, session: session)
            return true
        }

        guard shouldStartChat(event) else {
            return false
        }

        suppressedKeyUps.insert(event.keyCode)
        begin(session: session)
        return true
    }

    func keyUp(with event: NSEvent) -> Bool {
        suppressedKeyUps.remove(event.keyCode) != nil
    }

    private func handleActiveKeyDown(_ event: NSEvent, session: FightcadeEmbeddedSession?) {
        switch event.keyCode {
        case 36:
            session?.inputClient.submitChat(text)
            reset()
        case 53:
            session?.inputClient.cancelChat()
            reset()
        case 51:
            if !text.isEmpty {
                text.removeLast()
                session?.inputClient.updateChat(text)
            }
        default:
            appendPrintableCharacters(from: event)
            session?.inputClient.updateChat(text)
        }
    }

    private func reset() {
        isActive = false
        text = ""
    }

    private func shouldStartChat(_ event: NSEvent) -> Bool {
        guard event.modifierFlags.intersection([.command, .control, .option]).isEmpty else {
            return false
        }

        return event.charactersIgnoringModifiers?.lowercased() == "t"
    }

    private func appendPrintableCharacters(from event: NSEvent) {
        guard let characters = event.characters else { return }

        for scalar in characters.unicodeScalars where !CharacterSet.controlCharacters.contains(scalar) {
            let next = text + String(scalar)
            guard next.utf8.count <= Self.maxUTF8Bytes else { return }
            text = next
        }
    }
}
