import Foundation
import NaturalLanguage

private let chatTranslationMaximumCharacters = 500

enum ChatTranslationRequestBuildResult: Sendable {
    case request(ChatTranslationRequest)
    case failed(ChatTranslationRequest, String)
    case skipped
}

struct ChatTranslationRequestBuilder {
    static func build(
        id: FightcadeChatMessage.ID,
        channelName: String,
        body: String,
        targetLanguageIdentifier: String
    ) async -> ChatTranslationRequestBuildResult {
        await Task.detached(priority: .utility) {
            buildSynchronously(
                id: id,
                channelName: channelName,
                body: body,
                targetLanguageIdentifier: targetLanguageIdentifier
            )
        }.value
    }

    static func detectLanguage(in body: String) async -> String? {
        await Task.detached(priority: .utility) {
            let body = body.trimmingCharacters(in: .whitespacesAndNewlines)
            guard shouldTranslateChatBody(body) else { return nil }
            return detectedLanguageIdentifier(in: body)
        }.value
    }

    private static func buildSynchronously(
        id: FightcadeChatMessage.ID,
        channelName: String,
        body: String,
        targetLanguageIdentifier: String
    ) -> ChatTranslationRequestBuildResult {
        let body = body.trimmingCharacters(in: .whitespacesAndNewlines)
        guard shouldTranslateChatBody(body) else { return .skipped }

        guard let source = detectedLanguageIdentifier(in: body) else {
            return .failed(
                ChatTranslationRequest(
                    id: id,
                    channelName: channelName,
                    sourceBody: body,
                    protectedBody: body,
                    placeholders: [:],
                    sourceLanguageIdentifier: nil,
                    targetLanguageIdentifier: targetLanguageIdentifier
                ),
                "Could not identify source language."
            )
        }

        if ChatTranslationPreferences.languageFamily(source) == ChatTranslationPreferences.languageFamily(targetLanguageIdentifier) {
            return .skipped
        }

        let protected = protectChatTranslationTokens(in: body)
        return .request(ChatTranslationRequest(
            id: id,
            channelName: channelName,
            sourceBody: body,
            protectedBody: protected.text,
            placeholders: protected.placeholders,
            sourceLanguageIdentifier: source,
            targetLanguageIdentifier: targetLanguageIdentifier
        ))
    }

    private static func shouldTranslateChatBody(_ body: String) -> Bool {
        guard body.count >= 3, body.count <= chatTranslationMaximumCharacters else { return false }
        if body.range(of: #"^https?://\S+$"#, options: .regularExpression) != nil { return false }
        return body.contains { $0.isLetter }
    }

    private static func detectedLanguageIdentifier(in body: String) -> String? {
        let recognizer = NLLanguageRecognizer()
        recognizer.processString(body)
        let language = recognizer.dominantLanguage
        guard language != .undetermined else { return nil }
        return language?.rawValue
    }

    private static func protectChatTranslationTokens(in body: String) -> (text: String, placeholders: [String: String]) {
        var text = body
        var placeholders: [String: String] = [:]
        var index = 0
        let patterns = [#"https?://\S+"#, #"@[A-Za-z0-9_\-]+"#]

        for pattern in patterns {
            guard let regex = try? NSRegularExpression(pattern: pattern) else { continue }
            let matches = regex.matches(in: text, range: NSRange(text.startIndex..., in: text)).reversed()

            for match in matches {
                guard let range = Range(match.range, in: text) else { continue }
                let token = "__MACADE_TOKEN_\(index)__"
                placeholders[token] = String(text[range])
                text.replaceSubrange(range, with: token)
                index += 1
            }
        }

        return (text, placeholders)
    }
}
