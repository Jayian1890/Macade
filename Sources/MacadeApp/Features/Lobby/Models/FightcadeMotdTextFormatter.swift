import SwiftUI

struct FightcadeMotdLine: Identifiable, Equatable {
    let id: Int
    let content: AttributedString
    let isHeading: Bool
}

enum FightcadeMotdTextFormatter {
    static func lines(in body: String) -> [FightcadeMotdLine] {
        body.split(separator: "\n", omittingEmptySubsequences: false)
            .enumerated()
            .map { offset, line in
                let text = String(line)
                return FightcadeMotdLine(
                    id: offset,
                    content: attributedLine(text),
                    isHeading: isHeading(text)
                )
            }
    }

    private static func isHeading(_ line: String) -> Bool {
        let trimmed = line.trimmingCharacters(in: .whitespacesAndNewlines)
        return trimmed.count > 2 && trimmed.first == "`" && trimmed.last == "`"
    }

    private static func attributedLine(_ line: String) -> AttributedString {
        var output = AttributedString()
        var index = line.startIndex

        while index < line.endIndex {
            if let urlRange = urlRange(in: line, from: index), urlRange.lowerBound == index {
                append(String(line[urlRange]), to: &output, style: .link)
                index = urlRange.upperBound
                continue
            }

            if let markdown = markdownRange(in: line, from: index), markdown.range.lowerBound == index {
                append(String(line[markdown.innerRange]), to: &output, style: markdown.style)
                index = markdown.range.upperBound
                continue
            }

            let nextIndex = line.index(after: index)
            append(String(line[index..<nextIndex]), to: &output, style: .regular)
            index = nextIndex
        }

        if output.characters.isEmpty {
            append(" ", to: &output, style: .regular)
        }

        return output
    }

    private static func append(_ text: String, to output: inout AttributedString, style: Style) {
        var piece = AttributedString(text)
        piece.foregroundColor = style.foregroundColor
        piece.font = style.font

        if style == .link, let url = URL(string: text) {
            piece.link = url
            piece.underlineStyle = Text.LineStyle(pattern: .solid)
        }

        if style == .strike {
            piece.strikethroughStyle = Text.LineStyle(pattern: .solid)
        }

        output += piece
    }

    private static func urlRange(in line: String, from start: String.Index) -> Range<String.Index>? {
        for prefix in ["https://", "http://"] {
            guard line[start...].hasPrefix(prefix) else {
                continue
            }

            var end = start
            while end < line.endIndex, !line[end].isWhitespace {
                end = line.index(after: end)
            }
            return start..<end
        }

        return nil
    }

    private static func markdownRange(in line: String, from start: String.Index) -> (range: Range<String.Index>, innerRange: Range<String.Index>, style: Style)? {
        guard let style = Style(marker: line[start]) else {
            return nil
        }

        let innerStart = line.index(after: start)
        guard innerStart < line.endIndex, !line[innerStart].isWhitespace else {
            return nil
        }

        var end = innerStart
        while end < line.endIndex {
            if line[end] == style.marker {
                let beforeEnd = line.index(before: end)
                guard !line[beforeEnd].isWhitespace else {
                    return nil
                }

                return (start..<line.index(after: end), innerStart..<end, style)
            }

            end = line.index(after: end)
        }

        return nil
    }

    private enum Style: Equatable {
        case regular
        case bold
        case italic
        case strike
        case highlight
        case link

        init?(marker: Character) {
            switch marker {
            case "*": self = .bold
            case "_": self = .italic
            case "~": self = .strike
            case "`": self = .highlight
            default: return nil
            }
        }

        var marker: Character {
            switch self {
            case .bold: "*"
            case .italic: "_"
            case .strike: "~"
            case .highlight: "`"
            case .regular, .link: "\0"
            }
        }

        var foregroundColor: Color {
            switch self {
            case .highlight:
                MacadeColor.warning
            case .link:
                MacadeColor.neonCyan
            default:
                MacadeColor.ink
            }
        }

        var font: Font {
            switch self {
            case .bold, .highlight, .link:
                .system(size: 14, weight: .black, design: .rounded)
            case .italic:
                .system(size: 14, weight: .medium, design: .serif).italic()
            default:
                .system(size: 14, weight: .medium, design: .rounded)
            }
        }
    }
}
