# Native Runtime Mapping Audit

The verified `ggponet.dll` corpus includes MSVC CRT, STL, exception handling, stack-cookie, startup, and unwind helpers. These are not Fightcade protocol logic. Native macOS builds use libc++, libSystem, compiler-generated exception handling, and standard C/C++ runtime facilities instead of porting those PE32/MSVC helper bodies one-to-one.

Ledger rows marked with `native-runtime-mapped` mean:

- the raw function is a compiler/CRT/STL support helper, not GGPO protocol behavior;
- native C++ compilation supplies the equivalent runtime behavior;
- no fake GGPO behavior or stubbed export is introduced;
- the function should not block parity for named exports unless future evidence shows Fightcade-specific custom logic inside that row.

This category is intentionally separate from hand-written `native_converted` runtime modules such as Replay, SyncTest, Spectator streaming, TimeSync, and GameInput.

## Included Categories

| Category | Examples |
| --- | --- |
| MSVC exception/unwind scaffolding | `Catch_All@...`, `Unwind@...`, `__CxxThrowException`, `__EH_prolog3`, `__SEH_prolog4` |
| Stack/security cookie support | `__security_check_cookie`, `___report_gsfailure`, `___security_init_cookie` |
| CRT allocation/string/file wrappers | `_malloc`, `_free`, `_strlen`, `_getenv`, `_fflush`, `_fclose`, `_exit` |
| STL/string/vector/function helpers | `std::function<...>::~function`, `_Vector_iterator<>`, `_String_const_iterator<>`, `basic_string<>` |
| CRT startup/termination | `__CRT_INIT`, `___DllMainCRTStartup`, `__initterm`, `_atexit`, `doexit` |
| Bundled zlib support | `1000b390` through `10010c88`, evidenced by zlib `1.1.4` and inflate/deflate error strings; native code uses system zlib |
| Anonymous STL/debug-container helpers | Only rows whose decompiled body directly references STL/debug evidence such as `basic_string`, `std::function`, `_Container_proxy`, `_Tree`, iterator diagnostics, or Visual Studio library-function annotations |

## 75 Percent Resolution Batch

The 75 percent ledger update maps only rows with direct evidence:

- Clearly named MSVC CRT/STL/compiler helpers from the function name or signature.
- Bundled zlib `1.1.4` compression/inflate helpers, replaced by native system zlib in replay/state upload and streaming paths.
- Anonymous STL/debug-container helpers whose own decompiled body references STL types, Visual Studio library annotations, container proxies, iterator diagnostics, or exception/unwind scaffolding.
- DLL/CRT attach timing and startup hooks that are provided by the native Mach-O process runtime.

Rows that are merely anonymous `FUN_...` entries without one of those evidence markers remain `decompiled_imported`.

## Excluded Categories

Unknown `FUN_...` rows are not runtime-mapped just because they are small. They remain `decompiled_imported` until their role is evidenced and converted or mapped by category.

## Final Corpus Accounting Batch

The final ledger pass resolves the remaining anonymous rows only when their own corpus entry shows one of these evidence categories:

- STL/template support bodies that call or reference `_Vector_iterator<>`, `_String_const_iterator<>`, `_Char_traits_cat<>`, `max_size`, allocator, exception, or standard container helpers.
- Scalar deleting destructors whose decompiled body only calls a destructor and then `operator delete` when flag bit `1` is set.
- CRT/compiler support rows for import thunks, pointer initialization, vectorized `memcpy`, string/memory primitives, exception `what()` helpers, or process/runtime globals.
- Trivial no-op/getter/setter/return helpers with no export name, no Fightcade protocol strings, and no protocol state transitions.
- Remaining zlib/stream support rows evidenced by the bundled compression/runtime call graph; native code uses system zlib for compressed replay/state/streaming payloads.

Export-reachable backend deleting destructor slots are not classified as pure runtime helpers. `10001420`, `10002890`, and `10003550` are marked `native_converted` because the native `GGPOSession` destroy hook performs the documented backend teardown and object delete behavior.
