# Channel Chat Auto-Translation Plan

## Goal

Translate incoming channel chat messages into the current user's native language without changing Fightcade protocol behavior or sending translated text back to Fightcade.

The default target language should be the user's first preferred macOS language, with an explicit in-app override.

## Research Findings

- Current chat ingestion is centralized in `AuthenticatedHomeViewModel+Chat.swift` through `appendReceivedChatMessage`, `appendSystemMessage`, and private `append(_:)`.
- Current chat rendering is centralized in `ChatMessageRow.swift`, where message bodies are rendered with mention styling and text selection.
- Current chat storage is bounded per channel by `channelChatScrollbackLimit`, so translation cache pruning can use the same message IDs to avoid unbounded memory growth.
- Settings persistence is currently `UserDefaults` backed via `MacadeSettingsPreferencesStore`, with privacy-sensitive switches already exposed under settings.
- The macOS SDK includes `Translation.framework` on macOS. Its Swift interface exposes `LanguageAvailability`, `TranslationSession.Configuration`, async `TranslationSession.translate(_:)`, batch translation, and `prepareTranslation()` on macOS 15+.
- Apple `TranslationSession` is session-oriented on macOS 15. Plan for a SwiftUI-hosted translation session bridge instead of trying to instantiate sessions directly in the view model.
- The macOS SDK includes `NaturalLanguage.framework`, which can be used for local language detection before translation.
- DeepL and Google Cloud Translation both provide REST APIs for translation and language detection, but they require network calls and credentials. They are better as optional later providers, not the default.

## Recommended Direction

Use Apple's Translation framework as the first implementation because it is native, privacy-preserving relative to third-party APIs, and fits Macade's native macOS direction.

Do not implement a server-side or bundled third-party translation backend for v1. If remote fallback is added later, make it explicit, opt-in, provider-backed, and clearly disclose that chat text leaves the machine.

## User Experience

- Add a setting: `Translate channel chat automatically`.
- Default: off, to avoid surprise processing or language model downloads.
- Add `Target language`: default `System language`, with supported language choices populated from `LanguageAvailability.supportedLanguages`.
- In chat rows, show translated text below the original message.
- Display mode options for later polish:
  - `Original + translation`, recommended default.
  - `Translation + original collapsed`.
  - `Translation only`, optional later.
- Show a subtle source-language label when available, e.g. `Translated from Japanese`.
- Add per-row fallback text only on hover or context menu for failures; avoid noisy inline errors.

## Architecture

### Models

Add shared translation models under `Sources/MacadeApp/Core/Translation/`:

- `ChatTranslationPreferences`
  - `isEnabled: Bool`
  - `targetLanguageIdentifier: String?`
  - `displayMode: ChatTranslationDisplayMode`
  - `provider: ChatTranslationProviderKind`
- `ChatMessageTranslation`
  - `messageID: UUID`
  - `sourceLanguageIdentifier: String?`
  - `targetLanguageIdentifier: String`
  - `translatedBody: String`
  - `provider: ChatTranslationProviderKind`
  - `translatedAt: Date`
- `ChatTranslationState`
  - `.pending`
  - `.translated(ChatMessageTranslation)`
  - `.failed(String)`

### Services

Add a protocol boundary:

```swift
protocol ChatTranslating: Sendable {
    func translationAvailability(for text: String, targetLanguage: Locale.Language) async -> ChatTranslationAvailability
    func translate(_ request: ChatTranslationRequest) async throws -> ChatMessageTranslation
}
```

Implement v1 provider:

- `AppleChatTranslationService`
  - Uses `LanguageAvailability` for support checks.
  - Uses a SwiftUI-hosted `TranslationSession` to perform translations.
  - Uses batch translation when multiple messages arrive close together.

Do not put translation calls in `ChatMessageRow`.

### SwiftUI Session Bridge

Because Apple's translation APIs are session-oriented on macOS 15, add a small host view near `ChannelChatView`:

- `ChatTranslationSessionHost`
  - Owns `TranslationSession.Configuration`.
  - Watches pending translation requests from the view model.
  - Runs `.translationTask(configuration)` and fulfills pending requests with the provided session.
  - Updates view-model translation state on the main actor.

This keeps the view model responsible for state and keeps the SwiftUI-specific session lifetime out of service consumers.

### View Model State

Add to `AuthenticatedHomeViewModel`:

- `chatTranslationPreferences`
- `chatTranslationsByMessageID: [FightcadeChatMessage.ID: ChatTranslationState]`
- `pendingChatTranslationRequests: [ChatTranslationRequest]`

On received user messages:

- Skip translation if auto-translation is disabled.
- Skip local/current-user messages.
- Skip MOTD initially.
- Skip empty, URL-only, emoji-only, or very short messages.
- Detect likely source language locally.
- Skip if source language matches target language.
- Enqueue translation request.

When pruning chat scrollback:

- Remove translation states whose message IDs are no longer retained.
- Keep memory bounded with the same chat retention policy.

### Rendering

Update `ChatMessageRow` to read translation state for `message.id`:

- Existing `mentionText` remains the original body renderer.
- Add `translatedText` below original body when available.
- Use subdued style, smaller caption label, and normal selectable text.
- Keep mention detection and notifications based on original text to avoid translation artifacts.

### Text Protection

Before translation, preserve non-natural-language tokens:

- Replace URLs, `@mentions`, and Fightcade-ish command fragments with placeholders.
- Translate placeholder-safe text.
- Restore placeholders after translation.

On macOS 26.4+, consider using Translation framework skip-translation attributes for AttributedString. Keep placeholder logic for macOS 15 compatibility.

## Privacy And Settings

- Store translation preferences in `UserDefaults` through `MacadeSettingsPreferencesStore`.
- Add settings under `Privacy & Diagnostics` or `General` with clear copy:
  - Apple native translation may require language model downloads.
  - Remote providers, if later enabled, send chat text to the selected provider.
- Do not log translated or original chat text unless existing diagnostics chat-body logging is explicitly enabled.

## Provider Strategy

### V1: Apple Native

Pros:

- Native macOS integration.
- No app-owned API key.
- Best privacy posture.
- Works well with current macOS 15+ deployment target.

Risks:

- Language pair availability depends on installed/supported Apple language assets.
- Session lifecycle must be hosted in SwiftUI.
- First-use downloads or preparation can add latency.

### Later: Optional Remote Provider

Add only if Apple native coverage or quality is insufficient.

Potential providers:

- DeepL: `POST /v2/translate`, supports target language and returns detected source language.
- Google Cloud Translation: v3 `translateText` and `detectLanguage` REST endpoints.
- LibreTranslate/self-hosted: useful for development or user-managed servers, but not a production default.

Remote provider requirements:

- User opt-in.
- User-provided endpoint/API key or clearly owned Macade service terms.
- Rate limiting and character quotas.
- Explicit privacy warning.
- No silent fallback from native to remote.

## Performance Plan

- Debounce translation batches for 150-300 ms to catch bursts.
- Limit concurrent translation tasks per channel.
- Cache translations by message ID while the message is retained.
- Optionally add short-lived content hash cache for repeated messages.
- Skip translation for messages over a safe length cap, e.g. 500 chars, matching outbound chat trimming.
- Cancel pending translation work when leaving a channel or disabling translation.

## Error Handling

- Unsupported language pair: mark unavailable and avoid retry loops.
- Missing language asset: show one non-intrusive channel notice or settings status.
- Network/provider errors for remote providers: back off and do not block chat rendering.
- Translation failure must never prevent receiving, rendering, or sending chat.

## Implementation Steps

1. Add translation preference models and persistence.
2. Add settings UI for enabling translation and selecting target language.
3. Add translation state to `AuthenticatedHomeViewModel` and enqueue requests from `appendReceivedChatMessage`.
4. Add scrollback-aware pruning for `chatTranslationsByMessageID`.
5. Add `ChatTranslationSessionHost` near `ChannelChatView` to own Apple `TranslationSession` lifecycle.
6. Implement `AppleChatTranslationService` with language availability checks and batch translation.
7. Render translated text in `ChatMessageRow` below the original message.
8. Add placeholder protection for URLs and mentions.
9. Add unit-level tests for preference persistence, enqueue/skip rules, placeholder restoration, and scrollback pruning.
10. Verify with `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build`.

## Open Questions

- Should MOTD translation be included after user-message translation works, or remain out of scope?
- Should translated text replace the original by default, or always show both for moderation/context?
- Should target language be purely system-derived, or should setup ask the user once?
- Should direct messages, challenge banners, and system messages be translated later?
