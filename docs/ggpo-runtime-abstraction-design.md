# GGPO Runtime Abstraction Design

Purpose: Phase 4 design for native runtime boundaries before porting public GGPO rollback/input code or changing Fightcade wire behavior. This design keeps protocol work isolated in the native FBNeo runtime and keeps Swift/SwiftUI outside GGPO internals.

Authority: `docs/macade-fightcade-ai-context.md`, `docs/ggponet-address-map.md`, and `docs/ggpo-public-port-boundary.md`.

## Current Problem

The current native runtime stores transport state, served setup, TCP records, UDP packets, rollback, prediction, stream state, callbacks, stats, and diagnostics in one `GGPOSession` struct in `macade_ggpo_session.h`. `macade_ggpo_client.cpp` currently owns exported wrappers, local input queueing, rollback, prediction, stats, events, and close lifecycle. This works for the current prototype but makes Phase 5 rollback migration risky.

## Target Modules

| Module | Owns | Must not own |
| --- | --- | --- |
| `MacadeGGPOApi` | Exported Fightcade-compatible C symbols and thin lifecycle forwarding. | Packet encoding, socket loops, rollback internals, Swift app state. |
| `MacadeSession` | Shared session identity, mode, route metadata, callback table, lifecycle flags, diagnostics counters. | Algorithm-specific storage owned by rollback, UDP, TCP, stream, or rendezvous modules. |
| `MacadeCallbacks` | FBNeo save/load/free/advance/event adapter and overlay event translation. | Network sockets or packet parsing. |
| `MacadeRollbackCore` | Public-GGPO-derived `GameInput`, `InputQueue`, saved-state ring, prediction, rollback replay, frame delay. | UDP/TCP sockets, quark parsing, master registration. |
| `MacadeFightcadeUDP` | Fightcade peer UDP type `1/2/3/4/5`, type `3` bitstream, ack pruning, quality/sync probes, stats inputs. | Served TCP commands, NAT master registration, FBNeo callbacks. |
| `MacadeServedRendezvous` | UDP master registration, token punch, `useports`, proxy/open-port mode setup. | Gameplay input compression or rollback. |
| `MacadeFightcadeTCP` | TCP connection state, command `0/11/12/15/17/18/19/20` builders, signed server-record parser. | UDP packet parsing, rollback prediction. |
| `MacadeStreamRuntime` | Stream route initial state, server records `-12/-13`, spectator count, queued stream inputs. | Served gameplay rollback and direct UDP state. |
| `MacadeDiagnostics` | Redacted structured logs and counters. | User-facing SwiftUI rendering or secret/session data. |

## Session Ownership

`MacadeSession` should become a coordinator with value members for each subsystem. Each subsystem owns its own state and exposes narrow methods.

| Current state group | Target owner |
| --- | --- |
| `udpFd`, `peer`, UDP counters, quality/sync timing, local/remote packet maps | `MacadeFightcadeUDP` |
| `tcpFd`, `tcpSequence`, TCP buffers/counters, quark command records | `MacadeFightcadeTCP` |
| `localInputs`, `remoteInputs`, `predictedRemoteInputs`, `savedFrames`, rollback counters | `MacadeRollbackCore` |
| `streamInitialState`, `streamInputs`, stream counters/player text | `MacadeStreamRuntime` |
| `callbacks`, exported lifecycle, game/mode/player/delay/ranked | `MacadeSession` and `MacadeCallbacks` |
| NAT master/punch/open-port flags and temporary endpoints | `MacadeServedRendezvous` |

## Public API Boundary

The exported functions remain Fightcade-compatible symbol shims. They should allocate or validate `MacadeSession`, then delegate.

| Export | Delegates to |
| --- | --- |
| `ggpo_client_connect` | `MacadeServedRendezvous`, then `MacadeFightcadeTCP`, then `MacadeRollbackCore` startup. |
| `ggpo_start_session` | Direct `MacadeFightcadeUDP`, then `MacadeRollbackCore` startup. |
| `ggpo_start_streaming` | `MacadeFightcadeTCP`, then `MacadeStreamRuntime`. |
| `ggpo_idle` | Mode-specific pump: stream TCP only, served TCP plus UDP, direct UDP only. |
| `ggpo_synchronize_input` | `MacadeRollbackCore`, with network pumps before/after as required by mode. |
| `ggpo_advance_frame` | `MacadeRollbackCore::advanceFrame`, plus mode-specific TCP frame/snapshot scheduling. |
| `ggpo_get_stats` | Aggregate rollback, UDP, TCP, and timesync stats. |
| `ggpo_client_chat` | `MacadeFightcadeTCP` command `15`. |
| `ggpo_client_set_game_event` | Event adapter now; command `19` only after capture evidence. |

## Rollback Boundary

`MacadeRollbackCore` is the only Phase 5 target for public-GGPO ported code. It should expose: `queueLocalInput`, `storeRemoteInput`, `synchronizeInputs`, `advanceFrame`, `setFrameDelay`, `stats`, `hasRollback`, and `runRollback`.

Inputs passed into UDP/TCP should be frame-indexed packet inputs produced by rollback core. UDP/TCP should not inspect saved states or decide rollback seek frames.

## UDP Boundary

`MacadeFightcadeUDP` should expose: `bindDirect`, `attachPeer`, `pumpControl`, `poll`, `sendInputWindow`, `stats`, and `close`. It uses Fightcade packet shape only: type `1/2/3/4/5`. Public GGPO `UdpMsg` headers remain forbidden.

UDP receive emits decoded remote frame inputs and ack frames to `MacadeSession`. `MacadeSession` forwards remote input to rollback core and ack frames to UDP send-window pruning.

## TCP Boundary

`MacadeFightcadeTCP` should expose: `connectServed`, `connectStream`, `startServed`, `startStream`, `poll`, `sendFrameBatch`, `sendSnapshot`, `sendText`, and `close`.

TCP record parsing emits typed events: endpoint notice, match info, chat/control, stream gamebuffer, stream frame batch, spectator count, frame batch, snapshot, disconnect. Open-port endpoint application remains guarded by `MacadeServedRendezvous` state.

## Rendezvous Boundary

`MacadeServedRendezvous` owns master UDP registration and peer discovery before gameplay. It returns a ready peer endpoint and open-port mode metadata. It must not send gameplay type `3` packets or TCP frame batches.

## Callback Boundary

`MacadeCallbacks` owns conversion between FBNeo callbacks and rollback core requirements: save buffer ownership, load state, advance replay frame, event emission, and overlay-safe user messages. It should be the only module calling `GGPOSessionCallbacks` directly.

## File Split Target

Future runtime code should keep each source file under 500 lines. Macade runtime files live under `Sources/FightcadeFBNeo/src/macade`. `macade_ggpo_handshake.cpp` is currently 500 lines, so any Phase 5 or Phase 7 edit in that area should split it before adding behavior.

| Target file | Contents |
| --- | --- |
| `macade_ggpo_api.cpp` | Exported C functions only. |
| `macade_ggpo_session.h/.cpp` | Session coordinator, lifecycle, common metadata. |
| `macade_ggpo_callbacks.cpp` | FBNeo callback adapter and event emission. |
| `macade_ggpo_rollback.*` | Public-GGPO-derived rollback/input queue. |
| `macade_ggpo_udp_wire.*` | Type `1/2/3/4/5` packet codec. |
| `macade_ggpo_udp_peer.*` | UDP socket pump, quality/sync, resend/ack. |
| `macade_ggpo_rendezvous.*` | Master registration, punch, proxy/open-port. |
| `macade_ggpo_tcp.*` | TCP connection, command builders, records. |
| `macade_ggpo_stream.*` | Stream records and spectator playback. |

## Phase 5 Entry Criteria

1. Create `MacadeRollbackCore` behind the current exported API without changing network wire behavior.
2. Preserve current served/direct/stream launch behavior until after rollback migration builds and local harness evidence pass.
3. Add deterministic rollback/input tests or a native harness before replacing ad hoc maps.
4. Recreate runtime build automation before source changes that require a refreshed bundled binary, then run the required `xcodebuild` command.

## Non-Goals For Phase 4

No production runtime code changes were made in Phase 4. TCP parity, UDP timing parity, stream validation, replay, synctest, and command `19` remain evidence-gated later phases.
