struct FightcadeChatMentionSegment: Equatable, Sendable {
    let text: String
    let isMention: Bool
    let isCurrentUser: Bool
}

enum FightcadeChatMention {
    static func suggestions(
        in draft: String,
        users: [FightcadeChannelUser],
        limit: Int = 6
    ) -> [FightcadeChannelUser] {
        guard let query = activeQuery(in: draft) else {
            return []
        }

        let uniqueUsers = users.reduce(into: [String: FightcadeChannelUser]()) { result, user in
            guard !user.name.isEmpty else { return }
            result[user.name.lowercased()] = user
        }.values

        return Array(uniqueUsers)
            .filter { user in
                query.isEmpty || user.name.localizedCaseInsensitiveContains(query)
            }
            .sorted { (lhs: FightcadeChannelUser, rhs: FightcadeChannelUser) in
                let leftPrefix = !query.isEmpty && hasCaseInsensitivePrefix(lhs.name, query)
                let rightPrefix = !query.isEmpty && hasCaseInsensitivePrefix(rhs.name, query)
                if leftPrefix != rightPrefix {
                    return leftPrefix
                }
                return lhs.name.localizedCaseInsensitiveCompare(rhs.name) == .orderedAscending
            }
            .prefix(limit)
            .map { $0 }
    }

    static func complete(_ draft: String, with username: String) -> String {
        guard activeQuery(in: draft) != nil,
              let atIndex = draft.lastIndex(of: "@") else {
            return draft
        }

        return String(draft[..<atIndex]) + "@" + username + " "
    }

    static func containsMention(in text: String, candidates: [String]) -> Bool {
        segments(in: text, candidates: candidates, currentUserAliases: candidates).contains { $0.isMention }
    }

    static func segments(
        in text: String,
        candidates: [String],
        currentUserAliases: [String]
    ) -> [FightcadeChatMentionSegment] {
        let names = normalizedCandidates(candidates)
        guard !names.isEmpty else {
            return [FightcadeChatMentionSegment(text: text, isMention: false, isCurrentUser: false)]
        }

        var segments: [FightcadeChatMentionSegment] = []
        var cursor = text.startIndex
        var plainStart = cursor

        while cursor < text.endIndex {
            guard text[cursor] == "@", isMentionStart(text, at: cursor),
                  let match = mentionMatch(in: text, at: cursor, candidates: names) else {
                cursor = text.index(after: cursor)
                continue
            }

            if plainStart < cursor {
                segments.append(FightcadeChatMentionSegment(
                    text: String(text[plainStart..<cursor]),
                    isMention: false,
                    isCurrentUser: false
                ))
            }

            let end = text.index(cursor, offsetBy: match.count + 1)
            segments.append(FightcadeChatMentionSegment(
                text: String(text[cursor..<end]),
                isMention: true,
                isCurrentUser: containsName(match, in: currentUserAliases)
            ))

            cursor = end
            plainStart = cursor
        }

        if plainStart < text.endIndex {
            segments.append(FightcadeChatMentionSegment(
                text: String(text[plainStart..<text.endIndex]),
                isMention: false,
                isCurrentUser: false
            ))
        }

        return segments.isEmpty
            ? [FightcadeChatMentionSegment(text: text, isMention: false, isCurrentUser: false)]
            : segments
    }

    private static func activeQuery(in draft: String) -> String? {
        guard let atIndex = draft.lastIndex(of: "@") else {
            return nil
        }

        let queryStart = draft.index(after: atIndex)
        let query = draft[queryStart...]
        guard !query.contains(where: { $0.isWhitespace || $0.isNewline }) else {
            return nil
        }

        return String(query)
    }

    private static func normalizedCandidates(_ candidates: [String]) -> [String] {
        Array(Set(candidates.map { $0.trimmingCharacters(in: .whitespacesAndNewlines) }))
            .filter { !$0.isEmpty }
            .sorted { $0.count > $1.count }
    }

    private static func mentionMatch(in text: String, at atIndex: String.Index, candidates: [String]) -> String? {
        let start = text.index(after: atIndex)
        for candidate in candidates {
            guard let end = text.index(start, offsetBy: candidate.count, limitedBy: text.endIndex) else {
                continue
            }

            let value = String(text[start..<end])
            guard value.compare(candidate, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame,
                  end == text.endIndex || isMentionEnd(text[end]) else {
                continue
            }

            return candidate
        }

        return nil
    }

    private static func isMentionStart(_ text: String, at index: String.Index) -> Bool {
        guard index > text.startIndex else {
            return true
        }

        return isMentionEnd(text[text.index(before: index)])
    }

    private static func isMentionEnd(_ character: Character) -> Bool {
        character.isWhitespace || character.isNewline || ",;:!?()[]{}<>\"'".contains(character)
    }

    private static func containsName(_ name: String, in names: [String]) -> Bool {
        names.contains {
            name.compare($0, options: [.caseInsensitive, .diacriticInsensitive]) == .orderedSame
        }
    }

    private static func hasCaseInsensitivePrefix(_ value: String, _ prefix: String) -> Bool {
        value.range(of: prefix, options: [.caseInsensitive, .diacriticInsensitive, .anchored]) != nil
    }
}
