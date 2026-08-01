# Native Snes9x Runtime Integration

This document records the current Snes9x evidence and the implementation boundary for Macade's native runtime work.

## Evidence

Current local evidence comes from the Windows Fightcade runtime extracted at:

- `.reverse-engineering/downloads/fightcade-windows-extracted/emulator/snes9x/fcadesnes9x.exe`
- `.reverse-engineering/downloads/fightcade-windows-extracted/emulator/snes9x/ggponet.dll`
- `.reverse-engineering/downloads/fightcade-windows-extracted/emulator/snes9x/fcadesnes9x.default.conf`

Observed executable strings identify the runtime as `fcadesnes9x 1.60-2` and show standard Snes9x ROM loading:

- `usage: fcadesnes9x [options] <ROM image filename>`
- `ROM image can be compressed with zip, gzip, JMA, or compress.`
- default ROM directory evidence: `.\Roms`
- default save-state/SRAM directory evidence: `.\Saves`

Observed Fightcade command strings in the executable are:

- `quark:served`
- `quark:served,%[^,],%[^,],%d,%d`
- `quark:direct`
- `quark:direct,%[^,],%d,%[^,],%d,%d,%d`
- `quark:stream`
- `quark:stream,%[^,],%[^,],%d`
- `quark:replay`

Observed GGPO symbols in the Snes9x runtime evidence include:

- `ggpo_start_session`
- `ggpo_client_connect`
- `ggpo_start_streaming`
- `ggpo_start_replay`
- `ggpo_synchronize_input`
- `ggpo_advance_frame`
- `ggpo_idle`
- `ggpo_get_stats`
- `ggpo_set_frame_delay`

No `quark:training` string was observed in `fcadesnes9x.exe`. Macade must not enable Fightcade training for Snes9x until newer evidence proves that route.

Public source evidence is available from `https://github.com/fightcadeorg/fightcade-snes9x` and is currently cloned at:

- `.reverse-engineering/sources/fightcade-snes9x`
- commit `d56c95d81449f823164ef3cb62a218329c75ccce`

The source matches the observed Windows version strings:

- `src/snes9x.h` defines `VERSION "1.60"` and `FCVERSION "2"`.
- `src/snes9x.cpp` prints `fcadesnes9x VERSION-FCVERSION`.

The upstream Snes9x license in `src/LICENSE` permits non-commercial source and binary distribution. Do not vendor or redistribute the Snes9x runtime as part of Macade until Macade's distribution model is confirmed to satisfy that license.

## Source Portability Findings

The Fightcade GGPO/quark implementation is only wired into the Win32 frontend:

- `src/win32/ggpo/ggpo.cpp` owns the quark parser, GGPO callbacks, state save/load, chat, stats, and `bNetRollback`.
- `src/win32/wsnes9x.cpp` detects `quark:` ROM arguments, calls `QuarkInit`, synchronizes `joypads[8]` through `QuarkGetInput`, calls `S9xMainLoop`, calls `QuarkIncrementFrame`, and idles GGPO between frames.
- No equivalent quark/GGPO hooks were found in `src/unix`, `src/macosx`, `src/gtk`, or `src/libretro`.

The upstream macOS target is a full Cocoa app target. The upstream Unix target is X11-based. Neither is a good initial Macade runtime surface because Macade needs a headless/native embedded executable, not an upstream GUI frontend.

The smallest viable native runtime surface is a Macade-specific runner around the existing libretro frontend:

- `src/libretro/libretro.cpp` already exposes `retro_load_game`, `retro_run`, `retro_serialize`, `retro_unserialize`, `retro_set_video_refresh`, and `retro_set_input_state`.
- The libretro video callback receives the rendered SNES frame and can publish to Macade's embedded shared-memory video stream.
- The libretro input callback can return local embedded input or synchronized GGPO input using the verified Fightcade joypad bit layout.
- This avoids porting the upstream Cocoa app or requiring X11 on macOS.

A probe build of the libretro target on macOS reached the final link step but failed with:

```text
Undefined symbols for architecture arm64:
  "_bNetRollback", referenced from:
      S9xEndScreenRefresh() in lto.o
```

This is expected from the Fightcade source split: `src/gfx.cpp` references `extern bool bNetRollback`, but only `src/win32/ggpo/ggpo.cpp` defines it. A native quark module must define and toggle `bNetRollback` around rollback frame advancement, matching the Win32 behavior.

## Native Runner Map

Implement the first production Snes9x runtime as `Sources/FightcadeSnes9x` only after the license gate above is accepted. The minimal runner should contain:

- imported Fightcade Snes9x core at the verified commit, with local patches kept small and auditable;
- a `build-macade.sh` that produces `fcadesnes9x` and copies it into `Sources/MacadeApp/Resources/FightcadeRuntime/emulators/snes9x/`;
- a Macade embedded bridge equivalent to the FBNeo bridge for `MACADE_EMBEDDED_VIDEO_PATH`, `MACADE_EMBEDDED_VIDEO_BYTES`, `MACADE_EMBEDDED_INPUT_SOCKET`, and `MACADE_EMBEDDED_HIDE_WINDOW`;
- a native Snes9x quark module based on `src/win32/ggpo/ggpo.cpp`, backed by `Sources/FightcadeFBNeo/src/dep/ggponet-native` headers and sources;
- a small executable entry point that initializes libretro callbacks, loads a local ROM or starts a quark session, runs the frame/idling loop, and exits cleanly.

Current implementation status:

- `Sources/FightcadeSnes9x/upstream` vendors the verified source commit.
- `Sources/FightcadeSnes9x/macade_runner.cpp` hosts the libretro core for Macade embedded local launch.
- `Sources/FightcadeSnes9x/macade_audio.cpp` plays libretro stereo PCM through macOS `AudioToolbox` because this headless runner does not have FBNeo's SDL audio stack.
- `Sources/FightcadeSnes9x/macade_quark.cpp` wires the runner to Macade's native GGPO implementation for Snes9x quark commands.
- `Sources/FightcadeSnes9x/build-macade.sh` builds `Sources/FightcadeSnes9x/build/snes9x`.
- `Sources/MacadeApp/Resources/FightcadeRuntime/emulators/snes9x/snes9x` is the packaged executable path.
- The runner supports `game-id`, `macade:training,game-id`, and direct ROM path arguments.
- The runner parses `quark:served`, `quark:direct`, `quark:stream`, and `quark:replay`, creates native GGPO sessions, loads ROMs from the GGPO begin-game callback, saves/restores Snes9x state with the `GGPO` four-int header shape, and packs SNES joypad bits through `ggpo_synchronize_input`.
- The runner explicitly rejects `quark:training` because current Snes9x evidence does not show that route.
- The vendored libretro makefile is patched to include bundled zip support through `loadzip.cpp`, `unzip/ioapi.c`, `unzip/unzip.c`, `UNZIP_SUPPORT`, and system zlib.
- `manifest.json` declares `snes9x.supportsEmbedded = true` and keeps `snes9x.supportsQuark = false` until direct/served/stream/replay sessions are verified against Fightcade behavior.

Port the Win32 quark hooks to the libretro runner as follows:

| Win32 hook | Native runner equivalent |
| --- | --- |
| `QuarkInit(const TCHAR *)` | Parse `quark:served`, `quark:direct`, `quark:stream`, and `quark:replay` from `argv[1]`; tolerate Macade's optional ranked trailing field without requiring it. |
| `ggpo_begin_game_callback` | Resolve `<game>.zip` from `MACADE_ROM_DIR` or Macade's Snes9x ROM directory, then call `retro_load_game`. |
| `ggpo_advance_frame_callback` | Set `bNetRollback = true`, run exactly one `retro_run` frame without publishing embedded video, then reset `bNetRollback`. |
| `ggpo_save_game_state_callback` | Use `S9xFreezeSize` and `S9xFreezeGameMem`; preserve the Windows Snes9x `GGPO` header shape of four `int` values. |
| `ggpo_load_game_state_callback` | Validate the `GGPO` header and restore with `S9xUnfreezeGameMem`. |
| `QuarkGetInput` | Call `ggpo_synchronize_input` into an 8-element joypad buffer with element size 4, matching Win32 `QuarkGetInput(joypads, 4, 8)`. |
| `QuarkIncrementFrame` | Call `ggpo_advance_frame` after each emulated frame; publish stats to the Macade overlay when available. |
| `QuarkRunIdle` | Pump embedded input/chat, then call `ggpo_idle`. |

The verified Fightcade Snes9x joypad bit layout is:

| Libretro joypad id | SNES button | Fightcade bit |
| --- | --- | --- |
| `0` | B | `0x0040` |
| `1` | Y | `0x0080` |
| `2` | Select | `0x8000` |
| `3` | Start | `0x4000` |
| `4` | Up | `0x0020` |
| `5` | Down | `0x0010` |
| `6` | Left | `0x2000` |
| `7` | Right | `0x1000` |
| `8` | A | `0x0800` |
| `9` | X | `0x0400` |
| `10` | L | `0x0200` |
| `11` | R | `0x0100` |

For local embedded launch, the runner should derive the same bitfield from Macade's embedded input socket and answer libretro input callbacks from that bitfield. For quark sessions, the runner should answer libretro input callbacks from the latest `ggpo_synchronize_input` buffer.

## Current Macade Boundary

Macade now has a native Snes9x runner for local embedded launch:

- ROM storage under `Application Support/Macade/FightcadeRuntime/roms/snes9x`.
- ROM lookup for Fightcade-style `snes9x_` and `snes_` channel prefixes.
- Packaged runtime slot under `Resources/FightcadeRuntime/emulators/snes9x`.
- Runtime manifest entry that enables embedded local launch and keeps `supportsQuark` disabled until native GGPO integration is implemented and verified.

Macade must not mark Snes9x as quark-capable until the native executable's GGPO bridge is verified with direct/served/stream/replay sessions.

## Native Runtime Requirements

A production native Snes9x runtime must implement:

- local ROM loading from `MACADE_ROM_DIR` or absolute file paths resolved by Macade;
- Macade embedded video publishing through `MACADE_EMBEDDED_VIDEO_PATH` and `MACADE_EMBEDDED_VIDEO_BYTES`;
- Macade embedded input through `MACADE_EMBEDDED_INPUT_SOCKET`;
- native audio playback from libretro's signed 16-bit stereo PCM callbacks;
- save-state, load-state, log-state, free-buffer, advance-frame, and event callbacks for native `ggponet`;
- synchronized SNES joypad input packing with verified byte layout;
- spectator streaming state restore and per-frame input replay;
- `quark:served`, `quark:direct`, `quark:stream`, and replay handling matching the verified command shapes;
- optional tolerance for Macade's ranked trailing field on served/direct commands, while preserving compatibility with the observed Windows Snes9x command forms.

## Verification Gates

Only enable `supportsQuark` for `snes9x` after all gates pass:

- native Snes9x executable builds on macOS;
- `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build` succeeds;
- local ROM launch works with a user-provided SNES ROM;
- embedded frame publishing works in the Macade gameplay panel;
- embedded keyboard input reaches Snes9x joypad state;
- native audio playback works during local embedded launch;
- direct GGPO session reaches synchronized input on loopback;
- served Fightcade session matches the documented quark handshake behavior;
- spectator stream receives match info, state, and input frames.
