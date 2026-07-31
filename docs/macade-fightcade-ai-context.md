# Macade Fightcade AI Context

This file is the working source of truth for Macade tasks touching Fightcade,
FBNeo, GGPO, quark routes, netplay, emulator launch/runtime behavior, packet
captures, or related docs.

## Current Direction

Macade targets a native macOS SwiftUI app with a native macOS FBNeo runtime.
Do not use the official macOS Fightcade DMG as implementation authority, and do
not model Macade runtime assumptions after the Linux Fightcade client.

Fightcade protocol behavior should be matched from current web protocol
evidence, captured runtime behavior, packet captures, and the Windows
Fightcade GGPO binaries documented under `docs/ggponet/`.

## GGPO Boundary

The original `ggponet.dll` is a Windows PE DLL and is not directly linkable
from native macOS Mach-O code. Treat it as behavioral authority, not as a
runtime dependency.

Macade uses `Sources/FightcadeFBNeo/src/ggpomac/` as the native macOS package
facade for the `ggponet.dll` export surface. Public consumers should include
`ggpomac.h`; implementation currently remains in
`Sources/FightcadeFBNeo/src/macade/macade_ggpo_*.cpp` while runtime coupling is
reduced incrementally.

## Decompilation Authority

`docs/ggponet/README.md` records the decompiled binary set. The current primary
authority for Fightcade GGPO networking is the Windows `ggponet.dll` export and
function documentation under `docs/ggponet/ggponet/`.

`docs/ggponet/key-function-map.md` lists the important exported functions and
backend protocol bodies to compare against native behavior.

## Native Runtime Constraints

Keep networking, rollback, savestate, and Fightcade protocol code outside of
SwiftUI views. Prefer protocol boundaries at app integration points and keep
UI-facing Swift types on the main actor when they mutate presentation state.

Session persistence must not use Keychain access patterns that can trigger a
macOS credential prompt during normal app launch, login, restore, or sign-out.

## Verification

Use `xcodebuild -project Macade.xcodeproj -scheme Macade -destination
'platform=macOS' build` for app verification. Use the FBNeo make command from
`AGENTS.md` when changing the native FBNeo runtime.
