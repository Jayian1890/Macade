# Emulator Verification Matrix

Macade must only enable runtime capabilities that are backed by executable evidence and successful native macOS verification. The bundled manifest is the app gate for these capabilities.

## Capability Fields

| Manifest field | Meaning |
| --- | --- |
| `supportsEmbedded` | Emulator can run a local ROM through Macade embedded video/input. |
| `supportsFightcadeMatch` | Emulator can join a Fightcade served match route. |
| `supportsFightcadeDirect` | Emulator can run a direct GGPO route. |
| `supportsFightcadeSpectate` | Emulator can receive a Fightcade spectator stream. |
| `supportsFightcadeTraining` | Emulator can run a Fightcade `quark:training` route. |
| `supportsQuark` | Legacy broad flag. Route fields are preferred; when route fields are absent, Macade treats this as support for all Fightcade quark routes. |

## Current Status

| Runtime ID | Embedded | Match | Direct | Spectate | Fightcade training | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `fbneo` | Enabled | Enabled | Enabled | Enabled | Enabled | Native GGPO parity is implemented and bundled in `macfbneo`. |
| `snes9x` | Enabled | Disabled | Disabled | Disabled | Disabled | Native runner exists, but route verification is not complete. No `quark:training` evidence exists. |
| `flycast` | Enabled | Disabled | Disabled | Disabled | Disabled | Bundled patched Flycast Dojo app supports local embedded launch. Fightcade routes remain disabled until Dojo route mapping is implemented and verified. |
| `ggpofba` | Disabled | Disabled | Disabled | Disabled | Disabled | Legacy FC1 runtime evidence exists in Windows package only. No native bundled executable. |

## Required Gates

All runtime work in this table must still satisfy `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build` after app changes.

### FBNeo

FBNeo is currently enabled. Any change touching FBNeo launch/runtime behavior must re-check the existing `docs/ggponet` evidence and verify that route behavior still matches the native GGPO mapping.

### Snes9x

Keep `snes9x` Fightcade route fields disabled until all relevant gates pass:

- Native Snes9x executable builds on macOS.
- Local ROM launch works with user-provided SNES ROMs.
- Embedded frame publishing works in the Macade gameplay panel.
- Embedded keyboard/controller input reaches Snes9x joypad state.
- Native audio playback works during local embedded launch.
- Direct GGPO session reaches synchronized input on loopback.
- Served Fightcade session matches the documented quark handshake behavior.
- Spectator stream receives match info, state, and input frames.
- Replay handling matches the observed `quark:replay` route.

Do not enable Snes9x Fightcade training unless new evidence shows `quark:training` support for Fightcade Snes9x.

### Flycast

Flycast enablement requires a separate Dojo integration plan rather than direct reuse of FBNeo/Snes9x quark command handling.

Required gates before any Flycast capability is enabled:

- Identify the matching Flycast Dojo source/version/commit for the extracted `flycast.exe` evidence. Current probe: `dojo-6.46` at `e8cf3115b3979f686185f587a2cf42e1fd19ede6`.
- Build a native macOS Flycast Dojo executable suitable for Macade bundling. Current probe: arm64 `Flycast Dojo.app` with no Homebrew dylib dependency and populated `Resources/data`.
- Preserve Dojo config keys needed by Fightcade routing: `Quark`, `ServerIP`, `ServerPort`, `GGPOPort`, `GGPORemotePort`, `GGPODelay`, `Spectating`, `Training`, `ReplayFilename`, and `NetplayMethod`. Current probe exposes `-config section:key=value` virtual config input.
- Implement local embedded launch with Macade video/input/audio integration. Current bundle publishes frames through the Macade embedded video bridge and routes Macade key events through Flycast's SDL keyboard path.
- Map Fightcade served/direct/spectate/training/replay inputs to Flycast Dojo configuration and command-line behavior from evidence.
- Verify Dreamcast and NAOMI ROM lookup, including extracted CHD directory layouts from `flycast_roms.json`.
- Verify local embedded launch with user-provided Dreamcast/NAOMI content.
- Verify at least one served match, one direct loopback route, one spectator stream, and any training/replay route before setting corresponding route fields to true.

### GGPOfba/FC1

`fc1` is a Fightcade channel/runtime alias for legacy `ggpofba`, not FBNeo. Do not route `fc1` channels through FBNeo unless new evidence proves Fightcade itself treats them as FBNeo-compatible.

Required gates before any `ggpofba` capability is enabled:

- Identify or create a native macOS legacy GGPOfba runtime from evidence.
- Verify the FC1 ROM naming and savestate behavior.
- Verify the observed `quark:served`, `quark:direct`, `quark:stream`, `quark:replay`, and `quark:synctest` paths.
- Decide whether Macade should ship this legacy runtime at all, given FB Alpha licensing and native runtime maintenance cost.
