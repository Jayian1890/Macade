# Relevance Assessment

## ggponet.dll

`ggponet.dll` is directly relevant and authoritative for the private Fightcade GGPO network layer. The current DLL hash matches the prior recorded project baseline exactly: `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8`.

Full decompilation output is under `ggponet/`. Every Ghidra-discovered function has a Markdown file and raw C file. Ghidra reported 1180 functions and 0 decompile failures.

## ggpofba-ng.exe

`ggpofba-ng.exe` is relevant as the older FBA emulator-side integration point. It is not the GGPO network implementation itself, but it is useful because it shows how official emulator code parses Fightcade `quark:` routes and calls `ggponet.dll`.

The most important function is `0062dc50`, which maps routes as follows:

| Route prefix | Parsed format | DLL export called |
| --- | --- | --- |
| `quark:served` | `quark:served,%[^,],%[^,],%d,%d` | `ggpo_client_connect` |
| `quark:direct` | `quark:direct,%[^,],%d,%[^,],%d,%d,%d` | `ggpo_start_session` |
| `quark:synctest` | `quark:synctest,%[^,],%d` | `ggpo_start_synctest` |
| `quark:stream` | `quark:stream,%[^,],%[^,],%d` | `ggpo_start_streaming` |
| `quark:replay` | string after `quark:replay,` | `ggpo_start_replay` |

After constructor selection, `0062dc50` logs `Setting smoothing to %d.`, calls `ggpo_set_frame_delay`, and stores the session pointer in global `DAT_00b1a804`.

The focused export includes 57 functions selected by GGPO/quark/Kaillera references plus one caller-expansion level. Ghidra reported 5359 total functions and 0 failures for the selected slice.

## kailleraclient.dll

`kailleraclient.dll` is not relevant for Fightcade GGPO/quark parity. It is a UPX-packed legacy Kaillera v0.9 client with exported `_kaillera*` APIs, Winsock usage, and legacy server-list string `http://kaillera.com/raw_server_list2.php?wg=1&version=0.9`.

It is documented because `ggpofba-ng.exe` imports it, but it should remain a boundary artifact only. Do not use it as implementation authority for Macade's Fightcade-compatible GGPO path.

The packed DLL hash is `ef92ab4990079626ad402537ba05a9116ef48f1734081a433c5a5edc6ae79706`. The unpacked analysis input hash is `be3363a646729dcb685120de45760c43a6b54b1a1fcb336061eb0a903c4636b6`.
