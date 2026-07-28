# GGPO/Fightcade Binary Decompilation Notes

Purpose: AI-readable map of the current Windows Fightcade GGPO-related binaries and the generated per-function decompiler output in this directory.

## Artifact Summary

| Binary | Source | SHA256 | Scope | Relevance |
| --- | --- | --- | --- | --- |
| `ggponet.dll` | `emulator/fbneo/ggponet.dll` from current Windows Fightcade installer | `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8` | Full Ghidra export, 1180 functions, 0 failures | Primary Fightcade GGPO/network authority. |
| `ggpofba-ng.exe` | `emulator/ggpofba/ggpofba-ng.exe` from current Windows Fightcade installer | `ba4d267d1b5dc027acdc3bfaddfe900a08214cbc4c19d522ac79e3381f8ca91f` | Focused Ghidra export, 57 GGPO/quark/Kaillera functions, 0 failures | Relevant emulator-side route parser and `ggponet.dll` API caller. |
| `kailleraclient.dll` | `emulator/ggpofba/kailleraclient.dll`; UPX-unpacked for analysis | packed `ef92ab4990079626ad402537ba05a9116ef48f1734081a433c5a5edc6ae79706`, unpacked `be3363a646729dcb685120de45760c43a6b54b1a1fcb336061eb0a903c4636b6` | Full Ghidra export of unpacked DLL, 210 functions, 0 failures | Legacy Kaillera boundary only; not Fightcade GGPO/quark authority. |

## Directory Layout

| Path | Contents |
| --- | --- |
| `ggponet/index.md` | Full `ggponet.dll` function index. |
| `ggponet/functions/` | One Markdown file per discovered `ggponet.dll` function, with decompiled C, calls, callers, strings, data refs, and disassembly. |
| `ggponet/raw-c/` | One raw Ghidra C-like pseudocode file per `ggponet.dll` function. |
| `ggpofba-ng/index.md` | Focused function index for `ggpofba-ng.exe` GGPO/quark/Kaillera slice. |
| `ggpofba-ng/functions/` | One Markdown file per relevant `ggpofba-ng.exe` function. |
| `kailleraclient/index.md` | Full function index for unpacked `kailleraclient.dll`. |
| `kailleraclient/functions/` | One Markdown file per unpacked Kaillera function. |
| `*/imports-exports.md` | Import/export symbols identified by Ghidra. |
| `*/strings.md` | Strings identified by Ghidra. |
| `*/function-index.json` | Machine-readable function index. |

## Decompiler Method

Decompiler: local Ghidra 12.1.2 headless decompiler through PyGhidra 3.1.0 and local Temurin JDK 21. RetDec was used for metadata and UPX unpacking of `kailleraclient.dll`.

All scratch binaries, tools, and projects are under ignored local paths. The generated documents in `docs/ggponet/` are the tracked output.

## Relevance Conclusions

`ggponet.dll` is the authoritative private Fightcade networking DLL. Its exported GGPO-like API is documented completely under `ggponet/functions/` and must be treated as Fightcade-specific, not ABI-compatible with public MIT GGPO internals.

`ggpofba-ng.exe` is relevant because it parses `quark:` routes and calls the `ggponet.dll` exports. It is not the primary network implementation, but it defines the emulator-side callback table and route-to-export mapping.

`kailleraclient.dll` is not relevant to Fightcade GGPO/quark parity. It is a legacy Kaillera client imported by `ggpofba-ng.exe` for older netplay UI flows. It should not be used as authority for Macade's Fightcade-compatible GGPO path.

## Key Function Guide

Use `key-function-map.md` for a compact map of the most important decompiled functions and their generated files.
