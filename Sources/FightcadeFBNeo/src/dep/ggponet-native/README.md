# ggponet-native Reconstruction

This directory is the native macOS reconstruction workspace for `ggponet.dll`.

Source evidence:
- DLL: `.reverse-engineering/ggponet/ggponet.dll`
- SHA256: `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8`
- Ghidra output: `docs/ggponet`
- Function coverage: 1180 discovered, 1180 decompiled, 0 failures

Tracking files:
- `decompiled/`: one copied raw Ghidra C file for every DLL function.
- `function-inventory.json`: address/name/signature/call graph inventory.
- `export-inventory.json`: named exports and external imports.
- `CONVERSION_STATUS.csv`: per-function conversion ledger.
- `ENTRY_FIRST_ORDER.txt`: initial entry/export-first conversion order.

Native conversion starts at `1001489a entry` and proceeds from the documented call graph. Do not mark a function converted unless its native source is present and traced back to the matching decompiled address.
