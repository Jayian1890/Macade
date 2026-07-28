# Public GGPO Port Boundary

Purpose: Phase 3 extraction of the exact public MIT GGPO files and functions Macade may port or adapt. This boundary exists because Phase 2 proved the Fightcade `ggponet.dll` C API is GGPO-like, but its session vtable layout and Fightcade served/TCP behavior are private and not ABI-compatible with public MIT GGPO.

Authoritative context: `docs/macade-fightcade-ai-context.md`. Address map: `docs/ggponet-address-map.md`. Public reference: external `pond3r/ggpo` checkout at commit `7ddadef8546a7d99ff0b3530c6056bc8ee4b9c0a`; it is not currently vendored.

## License

Public GGPO is MIT licensed. Preserve the MIT copyright/license notice in any source file that ports substantial public GGPO code.

## Decision Classes

| Class | Meaning |
| --- | --- |
| Port | Public implementation may be ported into clean native runtime code with platform/assert/log adaptations. |
| Adapt | Public implementation is useful, but must be rewritten around Macade/Fightcade packet, callback, or runtime boundaries. |
| Reference | Use only for names, field meanings, or conceptual guidance. |
| Do not port | Excluded from production migration. |

## File Decisions

| Public file | Decision | Scope |
| --- | --- | --- |
| `src/lib/ggpo/bitvector.cpp`, `.h` | Port | Bit order and changed-bit encoding match the current Fightcade UDP type `3` evidence. |
| `src/lib/ggpo/game_input.cpp`, `.h` | Port | Input frame, byte buffer, bit helpers, equality, erase/init semantics. Adapt fixed max sizes if FBNeo input size requires dynamic storage. |
| `src/lib/ggpo/input_queue.cpp`, `.h` | Port | Prediction, frame delay, confirmed-frame discard, first-incorrect-frame tracking. |
| `src/lib/ggpo/sync.cpp`, `.h` | Port | Save/load ring, rollback seek/replay, confirmed input, prediction reset, frame increment. Adapt callbacks and allocation ownership. |
| `src/lib/ggpo/timesync.cpp`, `.h` | Adapt | Algorithm may be ported behind validation; enable frame waits only after Fightcade behavior is proven under asymmetric delay. |
| `src/lib/ggpo/ring_buffer.h` | Port or replace | Small bounded FIFO helper. `std::array`/custom deque is acceptable if behavior stays equivalent. |
| `src/lib/ggpo/static_buffer.h` | Port or replace | Small bounded vector helper; not required if native runtime uses standard containers. |
| `src/lib/ggpo/network/udp_proto.cpp`, `.h` | Adapt | Use selected algorithms only. Fightcade packet layout and served flow are private. |
| `src/lib/ggpo/network/udp_msg.h` | Reference | Type names and public field meanings only. Do not use public wire layout for Fightcade. |
| `src/lib/ggpo/backends/p2p.cpp`, `.h` | Adapt | Direct route state machine concepts, callback event mapping, stats plumbing. Do not use class layout or startup API as ABI. |
| `src/lib/ggpo/backends/synctest.cpp`, `.h` | Reference | Local deterministic harness concepts; Macade keeps synctest unavailable in UI until explicitly implemented. |
| `src/lib/ggpo/backends/spectator.cpp`, `.h` | Reference | High-level spectator buffering only. Fightcade stream route uses private TCP commands/records. |
| `src/lib/ggpo/backends/backend.h` | Do not port | Public vtable layout conflicts with Fightcade DLL evidence. Define Macade runtime interfaces instead. |
| `src/lib/ggpo/main.cpp` | Do not port | Public exported API wrappers do not include Fightcade served `ggpo_client_connect`, command `15`, command `19`, or the private vtable layout. |
| `src/lib/ggpo/network/udp.cpp`, `.h` | Do not port | Windows socket wrapper and public packet dispatch are not Macade/Fightcade authority. |
| `src/lib/ggpo/poll.cpp`, `.h` | Reference | Timer/polling concept only. Macade runtime should use native event loop/timers. |
| `src/lib/ggpo/platform_windows.*`, `platform_linux.*` | Do not port | Replace with Macade/macOS platform shims. |
| `src/lib/ggpo/log.cpp`, `.h` | Reference | Logging shape only. Use Macade redacted diagnostics. |
| `src/lib/ggpo/types.h` | Reference | Type aliases/macros only. Use project-local types and assertions. |
| `src/include/ggponet.h` | Reference | Error codes, callback field meanings, event/stat names. Do not use as exact Fightcade header. |
| `src/lib/ggpo/zlib.h`, `zconf.h` | Do not port | Use existing zlib/miniz integration if compression is needed. |
| `src/apps/**`, `doc/**`, build files | Do not port | Sample app/docs/build scaffolding only. |

## Exact Port List

| Area | Functions |
| --- | --- |
| Bitvector | `BitVector_SetBit`, `BitVector_ClearBit`, `BitVector_WriteNibblet`, `BitVector_ReadBit`, `BitVector_ReadNibblet`. |
| Game input | `GameInput::init`, `GameInput::value`, `GameInput::set`, `GameInput::clear`, `GameInput::erase`, `GameInput::equal`; `desc`/`log` only if useful for diagnostics. |
| Input queue | `InputQueue::Init`, `GetLastConfirmedFrame`, `GetFirstIncorrectFrame`, `DiscardConfirmedFrames`, `ResetPrediction`, `GetConfirmedInput`, `GetInput`, `AddInput`, `AddDelayedInputToQueue`, `AdvanceQueueHead`. |
| Rollback sync | `Sync::Init`, `SetLastConfirmedFrame`, `AddLocalInput`, `AddRemoteInput`, `GetConfirmedInputs`, `SynchronizeInputs`, `CheckSimulation`, `IncrementFrame`, `AdjustSimulation`, `LoadFrame`, `SaveCurrentFrame`, `FindSavedFrameIndex`, `CreateQueues`, `CheckSimulationConsistency`, `SetFrameDelay`, `ResetPrediction`, `GetEvent`. |
| Timesync candidate | `TimeSync::advance_frame`, `TimeSync::recommend_frame_wait_duration`. Gate runtime use behind capture validation. |
| UDP adaptation | `UdpProtocol::SendPendingOutput`, `OnInput`, `OnSyncRequest`, `OnSyncReply`, `OnQualityReport`, `OnQualityReply`, `GetNetworkStats`, `SetLocalFrameNumber`, `RecommendFrameDelay`, `SetDisconnectTimeout`, `SetDisconnectNotifyStart`; rewrite around Fightcade one-byte packet types. |

## UDP Adaptation Rules

| Public concept | Fightcade rule |
| --- | --- |
| Public `UdpMsg` header has magic/sequence/type. | Fightcade current evidence uses one-byte type `1/2/3/4/5`; do not emit public `UdpMsg` headers. |
| Public type `3` carries connect status and disconnect bit. | Current Fightcade type `3` evidence is `type`, `startFrame`, `ackFrame`, `compressedBitCount`, `inputSizeBytes`, bitstream. Add extra fields only with DLL/capture proof. |
| Public pending output pruning pops frames `< ack_frame`. | Port this behavior; it is confirmed by DLL string and current native fix. |
| Public changed-bit encoding uses marker, value bit, and 8-bit little-endian index. | Port this encoding for Fightcade type `3` bitstream. |
| Public retry/quality constants are `200 ms` and `1000 ms`. | Treat as candidates; final timing requires controlled Fightcade captures. |
| Public keepalive/input-ack types `6/7`. | Do not implement for Fightcade unless current DLL/captures prove they are live. |

## Callback And Stats Boundary

Use public `GGPOSessionCallbacks` only for callback intent: save, load, free, advance frame, event notification. Do not rely on public exported API names or vtable order. Macade should keep a project-local callback/session interface matching Fightcade evidence and FBNeo integration needs.

Use public `GGPONetworkStats` field meanings as a starting point: send queue length, receive/prediction queue length, ping, kbps sent, local/remote frame advantage. Full `ggpo_get_stats` parity still requires official runtime tracing.

## Migration Order

1. Port `GameInput`, `InputQueue`, and small container helpers first; add deterministic local tests or a native harness before network changes.
2. Port `Sync` rollback after callback ownership and save-buffer lifecycle are explicit in Macade runtime code.
3. Adapt UDP type `3` compression/decompression around current Fightcade packet shape.
4. Add timesync wait-frame behavior only after asymmetric-delay evidence confirms Fightcade behavior.
5. Keep served TCP, NAT traversal, stream, replay, command `19`, and exported wrapper ABI out of the public-GGPO migration.

## Non-Goals For Phase 3

No production runtime code changes were made in Phase 3. Runtime migration starts in Phase 5 after Phase 4 defines the native abstraction boundaries.
