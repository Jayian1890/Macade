# AGENTS.md

## Project Rules

- Build Macade as a native macOS SwiftUI application using Swift 6 language mode.
- Keep all source files under 500 lines. Split files by feature, layer, or responsibility before they grow large.
- Maintain separation of concerns: views render UI, view models own presentation state, services perform external work, models carry data.
- Do not put networking, persistence, or Fightcade protocol code directly in SwiftUI views.
- Never write mock code, fake services, sample-only implementations, or placeholder behavior that pretends to work. Production code only.
- Prefer protocols at integration boundaries, especially auth, session, websocket, launcher, and persistence layers.
- Keep feature code under `Sources/MacadeApp/Features/<FeatureName>/` and shared foundations under `Sources/MacadeApp/Core/`.
- Keep visual design tokens in `Core/Design`; do not scatter hard-coded colors, typography, or spacing across screens.
- Use async/await for asynchronous work and keep UI-facing types `@MainActor` where they mutate view state.
- Never use Keychain access patterns that can trigger the macOS credential prompt shown as "wants to use your confidential information stored in ... in your keychain." Session persistence must not require users to enter the login keychain password during normal app launch, login, restore, or sign-out. Prefer non-prompting storage attributes such as app-accessible generic password items, or remove persistence rather than shipping a flow that displays that system prompt.
- Do not introduce a replacement matchmaking backend. Macade targets Fightcade compatibility.
- Treat Fightcade protocol research as implementation context and keep related notes under `docs/`.
- Before any task that touches Fightcade, FBNeo, GGPO, quark routes, netplay, emulator launch/runtime behavior, packet captures, or related docs, read `docs/macade-fightcade-ai-context.md` first and treat it as the single source of truth.
- After any task in those areas, update `docs/macade-fightcade-ai-context.md` or explicitly verify that it still matches the changed behavior/evidence.
- Do not use the official macOS Fightcade DMG as implementation authority; it is considered outdated and broken for Macade's current native runtime work.
- Do not model Macade protocol behavior, user agents, or runtime assumptions after the Linux Fightcade client. Macade is native macOS and should use macOS-native assumptions unless current Fightcade web protocol evidence says otherwise.
- Always use `xcodebuild` for build verification. Do not use `swift build` unless the user explicitly asks for SwiftPM-only verification.

## Current Commands

- Build: `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build`
- FBNeo build: `cd Sources/FightcadeFBNeo && make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl`
- Run: `swift run Macade`

## Structure

- `Package.swift`: Swift Package manifest for the macOS SwiftUI executable.
- `Sources/MacadeApp/App`: app entry, root routing, and authenticated shell.
- `Sources/MacadeApp/Core/Design`: shared design tokens and reusable styling.
- `Sources/MacadeApp/Features/Auth`: login models, services, view models, and views.
- `Sources/FightcadeFBNeo`: vendored, modified Fightcade FBNeo runtime source.
- `docs`: Fightcade protocol and integration research.
