# Fightcade Snes9x Runtime

This directory contains Macade's native Snes9x runtime work.

## Upstream Source

- Repository: `https://github.com/fightcadeorg/fightcade-snes9x`
- Imported commit: `d56c95d81449f823164ef3cb62a218329c75ccce`
- Upstream version evidence: `fcadesnes9x 1.60-2`

The upstream source is under `upstream/`. Macade-specific runtime code lives outside that tree.

## Local Patches

The libretro makefile is patched to include bundled zip support because Fightcade Snes9x accepts zipped ROMs and Macade resolves `.zip` as the primary Fightcade ROM format.

Local embedded audio is played directly with macOS `AudioToolbox` from the libretro signed 16-bit stereo PCM callbacks.

The runner links Macade's native GGPO implementation and contains Snes9x quark callbacks, but the app manifest intentionally keeps Snes9x `supportsQuark` disabled until direct, served, stream, and replay sessions are verified.
