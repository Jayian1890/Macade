# Emulator Inventory

This inventory records the emulator IDs and runtime evidence currently available for Macade's native Fightcade parity work. It is implementation context, not an enablement decision by itself.

## Bundled Macade Runtime

Current bundled executables under `Sources/MacadeApp/Resources/FightcadeRuntime/emulators`:

| Runtime ID | Executable | Local embedded | Fightcade routes |
| --- | --- | --- | --- |
| `fbneo` | `emulators/fbneo/macfbneo` | Enabled | Enabled for match, direct, spectate, and Fightcade training. |
| `snes9x` | `emulators/snes9x/snes9x` | Enabled | Disabled pending direct, served, stream, and replay verification. |
| `flycast` | `emulators/flycast/Flycast Dojo.app/Contents/MacOS/Flycast Dojo` | Enabled for local ROM launch. | Disabled pending Dojo route translation and verification. |

The bundled manifest is the runtime gate. Adding an emulator to this inventory does not mean Macade can launch it.

## Cached Fightcade Channels

Local cache files inspected:

- `~/Library/Caches/Macade/Lobby/channels-jayian1890.json`
- `~/Library/Caches/Macade/Lobby/channels-jayian18902.json`

Unique cached channel IDs by emulator:

| Emulator ID | Unique channels | Systems seen |
| --- | ---: | --- |
| `fbneo` | 49 | `Arcade FC2`, `NES` |
| `snes9x` | 4 | `Super NES` |
| `flycast` | 3 | `Dreamcast`, `NAOMI` |

Cached non-FBNeo examples:

| Emulator ID | Game ID | System | Title |
| --- | --- | --- | --- |
| `snes9x` | `snes_bof2u` | `Super NES` | `Breath of Fire II (USA) (SUPER NES)` |
| `snes9x` | `snes_kinstu1` | `Super NES` | `Killer Instinct (USA) (SUPER NES)` |
| `snes9x` | `snes_smwu` | `Super NES` | `Super Mario World (USA) (SUPER NES)` |
| `snes9x` | `snes_umk3u` | `Super NES` | `Ultimate Mortal Kombat 3 (USA) (SUPER NES)` |
| `flycast` | `flycast_cvs2` | `NAOMI` | `Capcom Vs. SNK 2 Mark Of The Millennium 2001 (Flycast) (NAOMI)` |
| `flycast` | `flycast_mvsc2` | `NAOMI` | `Marvel Vs. Capcom 2 New Age of Heroes (Flycast) (NAOMI)` |
| `flycast` | `flycast_dc_mvsc2` | `Dreamcast` | `Marvel vs. Capcom 2 (USA) (DREAMCAST)` |

## Windows Runtime Evidence

Current extracted Windows Fightcade runtime evidence exists at `.reverse-engineering/downloads/fightcade-windows-extracted/emulator`.

| Runtime directory | Evidence | Macade handling |
| --- | --- | --- |
| `fbneo` | `fcadefbneo.exe`, `ggponet.dll`, current native GGPO parity docs. | Native runtime bundled and enabled. |
| `snes9x` | `fcadesnes9x.exe`, `ggponet.dll`, `fcadesnes9x.default.conf`, `quark:served`, `quark:direct`, `quark:stream`, `quark:replay`. | Native local runtime bundled; quark routes gated off until verification. |
| `flycast` | `flycast.exe`, `emu.default.cfg`, `flycast_roms.json`, Dojo strings/config. | Not bundled; requires Flycast Dojo integration before enablement. |
| `ggpofba` | `ggpofba-ng.exe`, `ggponet.dll`, `kailleraclient.dll`, FC1 strings, `quark:*` strings. | Not bundled; `fc1` canonical runtime ID is `ggpofba`. |

## Native Flycast Dojo Probe

The matching Flycast Dojo source is cloned at `.reverse-engineering/sources/flycast-dojo`:

- tag `dojo-6.46`
- commit `e8cf3115b3979f686185f587a2cf42e1fd19ede6`

A native macOS build probe exists at `.reverse-engineering/build/flycast-dojo-macos-portable/Flycast Dojo.app`.

Observed build properties:

- executable `Contents/MacOS/Flycast Dojo` is a Mach-O arm64 binary;
- app bundle version is `dojo-6.46`, commit `e8cf311`;
- `otool -L` shows only system libraries/frameworks and no Homebrew dylib dependency;
- `Contents/Resources/data` is present and includes `flycast_roms.json`, default VMU data, EEPROM/NVMEM files, and `default.zip`;
- CLI help supports `-config section:key=value` virtual config values and `[CONTENT]` launch input.

Macade now bundles a patched version of this app for local embedded launch. The patch links Macade's embedded bridge, publishes BGRA frames from the SDL OpenGL swap path, translates Macade embedded key events into Flycast's SDL keyboard device, and passes resolved local ROM paths to Flycast. This only enables local embedded launch.

This does not enable Fightcade routes. Served matches, direct routes, spectating, training, and replay still require route-specific Dojo config translation and verification.

## Alias Decisions

| Fightcade ID | Canonical runtime ID | Evidence |
| --- | --- | --- |
| `fc1` | `ggpofba` | Windows package contains `emulator/ggpofba/ggpofba-ng.exe`, and executable strings include `FB1 FC1`, `FC1`, and `quark:*`. Do not treat `fc1` as FBNeo. |
| `nulldc` | `flycast` | Current Windows package has Flycast but no NullDC directory; ROM index hints group `nulldc` with Dreamcast/Flycast content. |
| `flycast` | `flycast` | Current cached channels and Windows runtime both use Flycast. |

## Flycast Evidence Boundary

The Flycast runtime evidence is Dojo-based, not an FBNeo/Snes9x-style direct `quark:*` executable path.

Observed strings/config keys include:

- `Flycast Dojo`
- `flycast-dojo://`
- `dojo`
- `Quark`
- `GGPOPort`
- `GGPODelay`
- `GGPORemotePort`
- `ServerIP`
- `ServerPort`
- `NetplayMethod`
- `Spectating`
- `Training`
- `ReplayFilename`

`flycast_roms.json` currently contains 230 keys in the extracted Windows runtime. Flycast enablement must use this Dojo/config evidence and cannot reuse FBNeo/Snes9x quark command assumptions without a route-specific translation and verification pass.
