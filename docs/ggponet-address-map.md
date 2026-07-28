# ggponet.dll Address Map

Purpose: reviewed Phase 2 cross-reference map for the current Fightcade `ggponet.dll`. This file records stable addresses, names, confidence levels, and implementation boundaries. It is evidence for clean native implementation work, not source code to translate.

Authoritative companion context: `docs/macade-fightcade-ai-context.md`. Raw Ghidra export: `ghidra-out/export/`. RetDec slices were previously generated under `.build/ggponet-dll-analysis/extracted/`, which is no longer tracked.

## Evidence Baseline

| Artifact | Value |
| --- | --- |
| DLL | external evidence, not currently tracked |
| SHA256 | `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8` |
| Image base | `0x10000000` |
| Ghidra project | `ghidra-out/` |
| Ghidra export | `ghidra-out/export/` |
| Exporter | not currently tracked after `scripts` cleanup |
| Public GGPO | external `pond3r/ggpo`, commit `7ddadef8546a7d99ff0b3530c6056bc8ee4b9c0a` |

Confidence labels:

| Label | Meaning |
| --- | --- |
| Stable | Address and role agree across export, disassembly/decompilation, and strings or captures where applicable. |
| Probable | Address is stable, but exact public-name or callback semantics need more cross-checking. |
| Pending | Address is stable, but production behavior still requires capture/runtime evidence before implementation. |

## ABI Boundary

The Fightcade DLL exports a GGPO-like C API, but its session vtable is Fightcade-specific. Do not assume the public MIT GGPO backend class layout or vtable order is ABI-compatible with this DLL. Use public GGPO for algorithms and concepts only where strings/control flow align.

## Export Wrappers

| Export | Address | Reviewed role | Backend target or slot | Confidence | Notes |
| --- | ---: | --- | --- | --- | --- |
| `ggpo_close_session` | `0x10021b30` | Close/delete session wrapper. | Destructor/free path. | Probable | RetDec export wrapper exists; exact destructor chain remains type-recovery work. |
| `ggpo_get_stats` | `0x10021b50` | Stats wrapper. | Session vtable `+0x10`. | Stable | Public concept: `GetNetworkStats`; Fightcade stats layout still partial. |
| `ggpo_client_chat` | `0x10021b80` | Chat/control wrapper. | Session vtable `+0x0c`. | Stable | Served backend override is private TCP command `15`. |
| `ggpo_advance_frame` | `0x10021bb0` | Advance/end-frame wrapper. | Session vtable `+0x08`. | Stable | Public rollback concept; implementation must match DLL/captures. |
| `ggpo_synchronize_input` | `0x10021be0` | Input sync/prediction wrapper. | Session vtable `+0x04`. | Stable | Public `SyncInput` semantics are useful; ABI/layout is private. |
| `ggpo_idle` | `0x10021c20` | Poll/timer wrapper. | Session vtable `+0x00`. | Stable | Poll behavior differs by backend. |
| `ggpo_set_frame_delay` | `0x10021c50` | Frame-delay wrapper. | Session vtable `+0x1c`. | Stable | Public concept maps cleanly. |
| `ggpo_client_set_game_event` | `0x10021c80` | Fightcade game-event wrapper. | Session vtable `+0x14`. | Stable address, pending behavior | ASM shows vtable call. Command `19` behavior needs finished-match capture evidence. |
| `ggpo_logv` | `0x10021ca0` | Logging wrapper. | Session logging path. | Stable | Context only. |
| `ggpo_log` | `0x10021cc0` | Variadic logging wrapper. | Calls logging path. | Stable | Context only. |
| `ggpo_start_replay` | `0x10021d10` | Replay backend constructor wrapper. | Allocates `0x40`, calls `0x10027f60`. | Stable address, pending behavior | Local replay only; keep unavailable until verified. |
| `ggpo_start_streaming` | `0x10021d60` | Stream/spectator constructor wrapper. | Allocates `0xb90`, calls `0x10028d90`. | Stable address, pending behavior | TCP stream route needs dedicated capture validation. |
| `ggpo_start_synctest` | `0x10021db0` | Sync-test backend constructor wrapper. | Allocates `0x360`, calls `0x10027980`. | Stable | Local deterministic testing path, not live network. |
| `ggpo_client_connect` | `0x10021e00` | Served Fightcade backend constructor wrapper. | Allocates `0x2338`, calls `0x10029a40`. | Stable | Fightcade-private served TCP plus UDP backend. |
| `ggpo_start_session` | `0x10021e50` | Direct UDP backend constructor wrapper. | Allocates `0x19d8`, calls `0x100287f0`. | Stable | Direct route has no Fightcade TCP command server. |

## Backend Constructors

| Reviewed name | Address | Evidence | Clean implementation guidance | Confidence |
| --- | ---: | --- | --- | --- |
| `FightcadeServedBackend::ctor` | `0x10029a40` | `target-map.tsv`; constructor sets `GGPOBackend::vftable`, calls direct backend constructor first, attaches `ggpo.fightcade.com:6004`. | Private served behavior. Recover from DLL and captures only. | Stable |
| `Peer2PeerBackend::ctor` | `0x100287f0` | `target-map.tsv`; constructor sets `Peer2PeerBackend::vftable`. Public GGPO has `Peer2PeerBackend`. | Public GGPO semantics are useful; preserve Fightcade wire format. | Stable |
| `SpectatorBackend::ctor` | `0x10028d90` | `target-map.tsv`; constructor sets `SpectatorBackend::vftable`, attaches `ggpo.fightcade.com:6004`. | Private stream TCP route. Validate before shipping. | Stable |
| `ReplayBackend::ctor` | `0x10027f60` | `target-map.tsv`; wrapper `ggpo_start_replay` calls it. | Keep unavailable until replay evidence exists. | Pending |
| `SyncTestBackend::ctor` | `0x10027980` | `target-map.tsv`; constructor sets `SyncTestBackend::vftable`. | Local-only future test harness candidate. | Stable |

## Primary Vtables

These entries were dumped directly from the PE image at Ghidra-labeled vtable addresses. Function names are Ghidra auto-names unless a role is reviewed elsewhere in this file.

| Class vtable | Address | Slots |
| --- | ---: | --- |
| `GGPOBackend.primary` | `0x100330f4` | `+0x00 0x10029fb0`, `+0x04 0x10028b30`, `+0x08 0x10028710`, `+0x0c 0x10029f70`, `+0x10 0x100285d0`, `+0x14 0x10029800`, `+0x18 0x10001380`, `+0x1c 0x10028590`, `+0x20 0x10001420`, `+0x24 0x100295e0`, `+0x28 0x10028960` |
| `Peer2PeerBackend.primary` | `0x10033170` | `+0x00 0x10028a30`, `+0x04 0x10028b30`, `+0x08 0x10028710`, `+0x0c 0x10001370`, `+0x10 0x100285d0`, `+0x14 0x10002880`, `+0x18 0x10001380`, `+0x1c 0x10028590`, `+0x20 0x10002890`, `+0x24 0x100013e0`, `+0x28 0x10028960` |
| `ReplayBackend` | `0x100331c8` | `+0x00 0x10027ac0`, `+0x04 0x10027ae0`, `+0x08 0x10002870`, `+0x0c 0x10001370`, `+0x10 0x10001370`, `+0x14 0x10002880`, `+0x18 0x10001380`, `+0x1c 0x10001370`, `+0x20 0x10002d50` |
| `SpectatorBackend.primary` | `0x100331f0` | `+0x00 0x10028ed0`, `+0x04 0x10028c90`, `+0x08 0x10002870`, `+0x0c 0x10001370`, `+0x10 0x10001370`, `+0x14 0x10002880`, `+0x18 0x10001380`, `+0x1c 0x10001370`, `+0x20 0x10003520` |
| `SyncTestBackend` | `0x1003322c` | `+0x00 0x10001370`, `+0x04 0x10027660`, `+0x08 0x10027730`, `+0x0c 0x10001370`, `+0x10 0x10001370`, `+0x14 0x10002880`, `+0x18 0x10027400`, `+0x1c 0x10001370`, `+0x20 0x10003550` |
| `TcpProtocol` | `0x10033330` | `+0x00 0x10001370`, `+0x04 0x10001370`, `+0x08 0x10002880`, `+0x0c 0x10026240` |
| `Udp` | `0x100333bc` | `+0x00 0x10024da0`, `+0x04 0x10001370`, `+0x08 0x10024ba0`, `+0x0c 0x10024a10` |
| `UdpProtocol.primary` | `0x100333e0` | `+0x00 0x10001370`, `+0x04 0x10001370`, `+0x08 0x10024390`, `+0x0c 0x10001370` |
| `UdpProtocol.secondary` | `0x100333f4` | `+0x00 0x100233a0`, `+0x04 0x10024240`, `+0x08 0x10023350` |
| `Sync` | `0x10033418` | `+0x00 0x1000b390` |

Reviewed session slots from export wrappers:

| Slot | Wrapper | Reviewed meaning |
| ---: | --- | --- |
| `+0x00` | `ggpo_idle` | Poll timers/network/backend events. |
| `+0x04` | `ggpo_synchronize_input` | Synchronize/predict input. |
| `+0x08` | `ggpo_advance_frame` | Advance local frame / drain remote input. |
| `+0x0c` | `ggpo_client_chat` | Chat/control text; served override sends TCP command `15`. |
| `+0x10` | `ggpo_get_stats` | Network/timesync stats. |
| `+0x14` | `ggpo_client_set_game_event` | Fightcade game event; command `19` path pending capture evidence. |
| `+0x1c` | `ggpo_set_frame_delay` | Set local frame delay. |

## UDP Protocol Map

| Reviewed name | Address | Public GGPO correlation | Fightcade-specific notes | Confidence |
| --- | ---: | --- | --- | --- |
| `UdpProtocol::OnMsg` / dispatcher | `0x10024240` | Public `udp_proto.cpp::OnMsg` dispatch table. | Fightcade wire uses one-byte type `1/2/3/4/5`, not public GGPO message header. | Stable |
| `UdpProtocol::OnSyncRequest` | `0x100241b0` | Public `OnSyncRequest`. | Packet type `1`; replies with type `2`. | Stable |
| `UdpProtocol::OnSyncReply` | `0x10024050` | Public `OnSyncReply`, nonce validation and synchronized event. | Packet type `2`. | Stable |
| `UdpProtocol::OnInput` | `0x100233f0` | Public `OnInput`; string `Throwing away pending output frame %d\n`. | Packet type `3`; Fightcade bitstream header differs from public struct. | Stable |
| `UdpProtocol::OnQualityReport` | `0x10023fe0` | Public `OnQualityReport`. | Packet type `4`; replies with type `5`. | Stable |
| `UdpProtocol::OnQualityReply` | `0x10022c20` | Public `OnQualityReply`. | Packet type `5`; updates ping/timing. | Stable |
| `UdpProtocol::OnInvalid` | `0x10022d40` | Public assertion `FALSE && "Invalid msg in UdpProtocol"`. | Invalid type path. | Stable |

Useful public constants from `src/lib/ggpo/network/udp_proto.cpp`: `RUNNING_RETRY_INTERVAL = 200`, `KEEP_ALIVE_INTERVAL = 200`, `QUALITY_REPORT_INTERVAL = 1000`, `NETWORK_STATS_INTERVAL = 1000`, `UDP_SHUTDOWN_TIMER = 5000`. Treat these as candidates until current Fightcade captures validate exact timing.

## TCP And Served Protocol Map

| Reviewed name | Address | Wire role | Evidence | Confidence |
| --- | ---: | --- | --- | --- |
| `TcpCommand0Startup` | `0x100261e0` | TCP command `0`. | RetDec/Ghidra target and current pcap startup sequence. | Stable |
| `TcpCommand11RegisterPort` | `0x10026420` | TCP command `11`. | RetDec/Ghidra target and pcap command order. | Stable |
| `TcpCommand12RegisterQuark` | `0x100263e0` | TCP command `12`. | RetDec/Ghidra target and pcap command order. | Stable |
| `TcpCommand15Text` | `0x10026380` | TCP command `15`. | RetDec/Ghidra target; pcap `V14` and `C2` startup messages. | Stable |
| `TcpCommand17FrameBatch` | `0x10025e90` | TCP command `17`. | RetDec/Ghidra target; recurring pcap frame batches. | Stable |
| `TcpCommand18StateSnapshot` | `0x10025da0` | TCP command `18`. | RetDec/Ghidra target; recurring pcap snapshots. | Stable |
| `TcpCommand19GameEvent` | `0x10025c90` | TCP command `19`. | RetDec/Ghidra target only. | Pending capture |
| `TcpCommand20SpectatorRegister` | `0x10026340` | TCP command `20`. | RetDec/Ghidra target; stream route static evidence. | Pending stream capture |
| `TcpProtocol::connected_event` | `0x10028ed0` | TCP connected event path. | String `TcpProtocol connected.\n`. | Probable |
| `TcpProtocol::disconnect_event` | `0x10029c30` | TCP disconnect event path. | String `Got disconnect event from TcpProtocol.\n`. | Probable |
| `Tcp::connect_or_poll` | `0x10026d40` | Nonblocking connect/retry. | String `tcp connection failed (%d)!  retrying...\n`. | Stable address, pending behavior |

Served startup confirmed by current pcap remains: command `0`, `11`, `12`, `15 V14`, `17`, `15 C2,<player>,<delay>,<ranked>`, then recurring `17` and `18`.

## Socket/Timing Anchors

| Area | Requested anchor | Function containing anchor | Evidence |
| --- | ---: | ---: | --- |
| UDP socket/bind | `0x100245d4`, `0x10024632` | `0x100245b0` | String `Could not bind to port %d.  Retrying.\n`. |
| UDP send | `0x100248b4` | `0x10024750` | Calls `sendto`, records `timeGetTime`. |
| UDP recv | `0x10024e2f` | `0x10024da0` | Calls `WSARecv`; handles `WSAECONNRESET` while polling old port. |
| TCP socket/bind | `0x10026521`, `0x10026628` | `0x100264e0` | TCP socket setup. |
| TCP DNS | `0x10026795` | `0x10026760` | Resolves `ggpo.fightcade.com`. |
| TCP send | `0x100268fd` | `0x10026830` | Calls `WSASend`. |
| TCP connect/nonblocking | `0x10026d88`, `0x10026de9` | `0x10026d40` | Connect retry string. |
| TCP recv | `0x10026fea` | `0x10026f60` | Calls `WSARecv`; string `Got WSAECONNRESET in Recv.\n`. |

## Public GGPO Safe-Correlation Areas

| Area | Public source | Safe use | Not safe without DLL/capture evidence |
| --- | --- | --- | --- |
| Input delta bitstream | `network/udp_proto.cpp`, `bitvector.*`, `game_input.*` | Compression/decompression concepts and pending-output pruning semantics. | Public GGPO packet header/layout. |
| Rollback sync | `sync.*`, `input_queue.*`, `backends/p2p.*` | Save/load/advance/input prediction semantics. | Fightcade backend constructor layout or exact callback ABI. |
| Timesync | `timesync.*`, `network/udp_proto.cpp` | Candidate algorithm and stats fields. | Exact wait-frame behavior until current captures/traces verify it. |
| Direct P2P backend | `backends/p2p.*` | Direct route semantics, local input, peer state. | Served TCP commands and Fightcade quark handling. |
| Spectator concept | `backends/spectator.*` | High-level stream playback concept. | Fightcade TCP stream route, command `20`, records `-12`/`-13`. |

## Pending Phase 2 Follow-Ups

1. Name primary vtable slot targets by class after reviewing each function body, not just slot address.
2. Cross-check `GGPOBackend.primary +0x24` and `+0x28` roles; likely disconnect/timer-related but not reviewed enough for production guidance.
3. Cross-check `TcpProtocol` and `UdpProtocol` secondary vtable roles against call sites.
4. Preserve the current rule that command `19`, stream, replay, and open-port fallback require dedicated captures before implementation changes.
