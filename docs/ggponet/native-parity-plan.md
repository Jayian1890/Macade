# Native ggponet Parity Plan

This plan is for replacing the verified Fightcade `ggponet.dll` behavior with native macOS code without stubs or shortcut behavior.

## Rules

- Only mark a function `native_converted` when its behavior is implemented from verified `docs/ggponet` evidence.
- Do not wire an export if it can reach an unimplemented runtime path.
- Keep each native source file under 500 lines.
- Verify native code with a dylib compile and verify the app with `xcodebuild` after code changes.
- Keep protocol and runtime evidence in `docs/ggponet`.

## Definition Of 100 Percent

Public parity requires all 15 named exports to behave correctly in native code.

Full corpus parity means every behavior reachable from those exports is converted or proven irrelevant to exported runtime behavior. CRT/compiler/runtime helper functions do not need one-to-one native files when native C++ provides the same behavior, but the conversion ledger must document the mapping.

## Phase 1: Completed Baseline

| Area | Status |
| --- | --- |
| Verified DLL provenance | Complete |
| Decompilation corpus | Complete: 1180 functions, 0 failures |
| Export wrapper dispatch | Complete |
| Replay backend | Complete |
| SyncTest backend | Complete |
| Spectator streaming TCP backend | Complete |
| TimeSync core | Complete |

## Phase 2: Shared Peer Primitives

These are safe to convert before wiring `ggpo_start_session`.

| Gate | Area | Representative entries | Status |
| --- | --- | --- | --- |
| 2.1 | GameInput | `10008970`, `10022020`, `100221f0`, `10022310`, `100224a0`, `100226c0`, `10022860` | Complete |
| 2.2 | Prediction and input queues | `10020570`, `100206b0`, `10020700`, `10020940`, `10020eb0`, `10021290`, `10021340`, `10021660`, `10021870` | Complete |
| 2.3 | Sync core save-state/Prediction bridge | `1001fce0`, `1001fd20`, `1001fe30`, `1001fef0`, `10020080`, `100202e0`, `10020310`, `10020350`, `100203d0`, `10020420`, `10020480`, `100204f0` | Complete |
| 2.3b | Sync-adjacent UDP protocol send helpers | `10022bb0`, `10023eb0` | Complete |
| 2.4 | Poll/shared backend state | `10027ff0`, `10028090`, `10028330`, `10028450`, `10028490`, `100284c0` | Complete |

## Phase 3: UDP Transport And Protocol

Do not start `ggpo_start_session` until these are complete.

| Gate | Area | Representative entries | Status |
| --- | --- | --- | --- |
| 3.1 | UDP socket bind/send/recv | `10024520`, `100245b0`, `100246e0`, `10024750`, `10024a10`, `10024a30`, `10024aa0`, `10024ba0`, `10024d60`, `10024da0`, `10025090` | Complete: see `udp-socket-map.md` |
| 3.2 | UDP protocol construction/config | `10003e40`, `10008a50`, `100230a0`, `10023130`, `10023320`, `10023350`, `100233a0` | Complete: see `udp-protocol-map.md` |
| 3.3 | UDP handshake/sync | `10023960`, `100239f0`, `10024050`, `10024210`, `10024390` | Complete: sync request/reply, compressed-input send/resend, and quality-report timer paths covered |
| 3.4 | UDP message encode/decode | `10022d40`, `10022e60`, `100233a0`, `100233f0`, `10024240` | Complete: control messages, compressed input, and dispatch table covered |
| 3.5 | Reliability/ack/send queue | entries reached from `UdpProtocol::vftable` and message handlers | Partial: compressed-input pending-output ack/discard and resend are implemented; final direct-session audit still pending |

## Phase 4: Peer Backend

| Gate | Area | Representative entries | Status |
| --- | --- | --- | --- |
| 4.1 | Peer constructor/destructor | `100287f0`, `10028790`, `10002890` | Complete: constructor/destructor and scalar deleting destructor semantics covered by native destroy hook |
| 4.2 | Peer idle | `10028a30`, `10028660`, `100286c0` | Complete |
| 4.3 | Peer synchronize input | `10028b30`, prediction and confirmed input calls | Complete |
| 4.4 | Peer advance frame | `10028710`, `100202e0` | Complete |
| 4.5 | Peer stats/frame delay/event bridge | `100285d0`, `10028590`, `10028960` | Complete |

## Phase 5: Direct Session Export

| Gate | Area | Representative entries | Status |
| --- | --- | --- | --- |
| 5.1 | `ggpo_start_session` | `10021e50`, `100287f0`, `10028ac0` | Complete: export wired to native peer constructor/start path |
| 5.2 | Direct peer session verification | local loopback and build verification | Build verification complete; local runtime loopback still pending |

## Phase 6: Fightcade Client Wrapper

Only start after direct peer sessions are complete.

| Gate | Area | Representative entries | Status |
| --- | --- | --- | --- |
| 6.1 | `GGPOBackend` constructor/destructor | `10029a40`, `100299b0`, `10001420` | Complete: constructor/destructor and scalar deleting destructor semantics covered by native destroy hook |
| 6.2 | Lobby TCP client events | `10029c30` | Complete: documented TCP events and chat/upload edge cases covered |
| 6.3 | Client chat/game events | `10029f70`, `10029800` | Complete for chat and game-event upload handling |
| 6.4 | Replay upload/spectator producer | `100295e0`, `10029160`, upload commands | Complete: spectator input batches, delayed state upload, and final replay upload are implemented |
| 6.5 | `ggpo_client_connect` | `10021e00` | Complete: export wired to native client constructor |

Current ledger: `229 native_converted`, `951 native-runtime-mapped`, `0 decompiled_imported`; resolved corpus `1180/1180` (`100.0%`).

## Phase 7: Final Audit

| Gate | Requirement | Status |
| --- | --- | --- |
| 7.1 | All named exports implemented | Complete: wrappers dispatch to native replay, synctest, streaming, peer, and client backends |
| 7.2 | No `decompiled_imported` functions reachable from named exports without a native mapping | Complete: conversion ledger has no remaining `decompiled_imported` rows |
| 7.3 | Native dylib exported symbol audit | Complete: native dylib exports all 15 expected `ggpo_*` symbols |
| 7.4 | `xcodebuild` passes | Complete: `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build` succeeded |
| 7.5 | End-to-end Macade runtime wiring | Complete: SDL FBNeo accepts `quark:*`, links native `ggponet`, synchronizes inputs through GGPO, and bundled manifest enables `supportsQuark` |
| 7.6 | Runtime verification against documented Fightcade behavior | Pending: live/local GGPO session testing still required |

## SDL Runtime Wiring

The macOS SDL FBNeo runtime now compiles native `ggponet` directly into the bundled `macfbneo` executable. Macade launches `quark:*` commands through the existing `FightcadeLaunchRoutes`; `FightcadeLauncher` permits these routes because the bundled runtime manifest declares `supportsQuark: true`.

The SDL bridge covers:

- `quark:served`, `quark:training`, `quark:direct`, `quark:stream`, and `quark:replay` session creation.
- GGPO callbacks for begin-game, save-state, load-state, log-state, free-buffer, advance-frame, and event dispatch.
- Bundled Fightcade savestate lookup under `MACADE_FIGHTCADE_RUNTIME/savestates`.
- Per-frame network input packing/synchronization and GGPO advance/idle calls in the SDL run loop.
- GGPO match-info, spectator-count, system-message, and chat events are forwarded into Macade's embedded overlay metadata; embedded chat input packets are sent through `ggpo_client_chat`.
- Native `ggpo_*` symbols linked into `Sources/MacadeApp/Resources/FightcadeRuntime/emulators/fbneo/macfbneo`.
- Spectate/streaming requires `ggpo_idle` even before the first game state is loaded; the SDL run loop pumps `QuarkRunIdle` on both audio and non-audio idle paths so the streaming TCP socket can receive match info and initial state.
- The first streamed state follows the official FBNeo delayed-load path: `DrvInit`, `MediaInit`, `RunInit`, then `BurnAreaScan` with `nAcbLoadState = kNetSpectator` while restoring state bytes.
- Embedded spectate forces draw/publish on audio-driven frames and publishes a redraw immediately after first streamed state restore; otherwise SDL can produce audio-only frames with `pBurnDraw = NULL` and leave the embedded video stream black.
