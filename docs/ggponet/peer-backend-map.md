# Peer Backend Conversion Map

This map is derived from the verified Fightcade `ggponet.dll` corpus documented in `docs/ggponet/binary-source.md`.
`ggpo_client_connect` and `ggpo_start_session` are now wired to native backends; runtime verification remains a separate parity gate.

## Export Entry Points

| Export | Entry | Allocation | Constructor path |
| --- | ---: | ---: | --- |
| `ggpo_client_connect` | `10021e00` | `0x2338` | `10029a40` |
| `ggpo_start_session` | `10021e50` | `0x19d8` | `100287f0`, then `10028ac0` |

## Direct Session Export

The native `ggpo_start_session` export now follows the verified `10021e50` path:

| Step | Native Mapping | Evidence |
| --- | --- | --- |
| Allocate peer session | `create_peer_session` uses non-throwing allocation and returns null on failure. | `functions/10021e50_ggpo_start_session.md` allocation branch. |
| Construct peer core | `create_peer_session` maps `100287f0`. | `functions/100287f0_FUN_100287f0.md`. |
| Start remote peer | `peer_session_connect` maps `10028ac0`. | `functions/10028ac0_FUN_10028ac0.md`. |
| Return session | `ggpo_start_session` returns the peer `GGPOSession` header. | `functions/10021e50_ggpo_start_session.md`. |

## Shared Peer Core

Both exports depend on `Peer2PeerBackend` behavior.

`100287f0` constructs the peer session:

| Step | Function | Evidence |
| --- | ---: | --- |
| Set `Peer2PeerBackend::vftable` | `100287f0` | writes `Peer2PeerBackend::vftable` to first two object pointers |
| Construct poll/shared backend state | `100284c0` | called before Sync construction |
| Construct Sync | `100203d0` | sets `Sync::vftable`, initializes save-state ring |
| Construct UdpProtocol | `10023130` | sets `UdpProtocol::vftable`, initializes UDP protocol state and idle env knobs |
| Construct TimeSync | `10027350` | sets `TimeSync::vftable`, clears local/remote arrays, sets `0x78` sample window |
| Copy callbacks | `100287f0` | copies seven callback pointers |
| Initialize Sync | `10020350` | copies callbacks/options into Sync and calls `100205a0` |
| Bind/start UDP | `100230a0` | calls `100246e0(localport, callbacks)` |
| Call `begin_game` | `100287f0` | invokes callback slot 0 with game string |

`10028ac0` starts the remote peer:

| Step | Function | Evidence |
| --- | ---: | --- |
| Configure remote endpoint | `10023fa0` | calls `10025090(remote_ip, remote_port)` |
| Mark backend active | `10028ac0` | clears `0x19c8`, sets `0x19c9`, stores player side flag at `0x19d4` |
| Start protocol sync | `10024210` | clears protocol state, seeds random sync packet via `10023960` |

## Peer Vtables

`Peer2PeerBackend::vftable` entries from `binary-source.md`:

| Slot | Target | Role evidenced so far |
| ---: | ---: | --- |
| 0 | `10028a30` | idle/poll, calls poll loop, sync idle, timesync, rollback update |
| 1 | `10028b30` | synchronize input, prediction, time-sync event, confirmed input copy |
| 2 | `10028710` | advance frame, sync advance, idle(0), save current frame |
| 3 | `10001370` | leaf true |
| 4 | `100285d0` | get stats |
| 5 | `10002880` | leaf true |
| 6 | `10001380` | logv |
| 7 | `10028590` | set frame delay before first sync input |
| 8 | `10002890` | deleting destructor |
| 9 | `100013e0` | peer event hook leaf void |
| 10 | `10028960` | UDP protocol event to GGPO event callback bridge |

`GGPOBackend::vftable` extends the peer behavior used by `ggpo_client_connect`:

| Slot | Target | Role evidenced so far |
| ---: | ---: | --- |
| 0 | `10029fb0` | idle, delegates peer idle and processes lobby TCP events while not active |
| 1 | `10028b30` | synchronize input |
| 2 | `10028710` | advance frame |
| 3 | `10029f70` | client chat command, requires match id string |
| 4 | `100285d0` | get stats |
| 5 | `10029800` | client game event ingestion and replay-state upload trigger |
| 6 | `10001380` | logv |
| 7 | `10028590` | set frame delay |
| 8 | `10001420` | deleting destructor |
| 9 | `100295e0` | per-frame spectator stream/replay capture and upload |
| 10 | `10028960` | UDP protocol event bridge |

## Client TCP Events

`TcpProtocol` first dispatches negative wire/server codes through `PTR_FUN_100332c4`. The queued event consumed by `10029c30` is not always the same number as the wire code.

`10029c30` consumes `TcpProtocol` events for `GGPOBackend`:

| Wire | Queued Event | Source parser | Behavior |
| ---: | ---: | --- | --- |
| response to command `0` | `0` | version/connect response | sends command `0xb` with match id and local user id, emits `5001` connected |
| `9` / queued `1` | `1` / `10` | disconnect | emits `5006` disconnected and returns |
| queued `2` | `2` | no-op/empty | returns |
| `7` | `8` | `10025740` start match | calls `10028ac0`, sets local player flags, requests match info, emits `5002` retrieving matchinfo |
| response to command `0xc` | `0xb` | `10025810` match info | emits `5003`, then `5004`, then `5005` system chat prompt |
| `8` | `0xc` | `10025680` chat | emits `5005` chat only if match id matches |
| `10` | `0x10` | `100253e0` spectator count | emits `5004` |
| `11` | `0x11` | `10025460` upload trigger | starts delayed replay-state upload when streaming is enabled |

## Native Peer Core Batch

The internal native peer backend implements the core `Peer2PeerBackend` behavior in `Sources/FightcadeFBNeo/src/dep/ggponet-native/src/peer_backend.cpp`, and the public `ggpo_start_session` export is wired to this native startup path.

| Entry | Native Mapping | Evidence |
| --- | --- | --- |
| `100287f0` | Constructs the peer session: callback copy, poll/shared state, SyncCore, UdpProtocol, TimeSync, Sync init with frame delay `1` and max prediction `20`, UDP bind, and `begin_game`. | `functions/100287f0_FUN_100287f0.md`. |
| `10028ac0` | Starts the remote peer: configures remote UDP endpoint, clears idle reentrancy, marks synchronizing, stores player-side flag, and starts UDP synchronization. | `functions/10028ac0_FUN_10028ac0.md`. |
| `10028a30` | Peer idle: runs poll loop, drains UDP protocol events, enters Sync simulation check under the reentrancy flag, updates local connect status, and sleeps when requested. | `functions/10028a30_FUN_10028a30.md`. |
| `10028660` | Drains UdpProtocol event queue and dispatches each event through the peer event bridge. | `functions/10028660_FUN_10028660.md`; `functions/100230e0_FUN_100230e0.md`. |
| `100286c0` | Drains confirmed prediction events after frame advance. The base peer slot is a no-op for each confirmed event, matching `Peer2PeerBackend::vftable` slot 9. | `functions/100286c0_FUN_100286c0.md`; `binary-source.md`. |
| `10028b30` | Synchronize input: rejects while synchronizing, builds local `GameInput`, adds local input outside rollback/poll reentrancy, emits TimeSync when needed, sends UDP input, then returns combined Sync input bytes. | `functions/10028b30_FUN_10028b30.md`. |
| `10028710` | Advance frame: logs current frame, advances Sync, calls idle(0), drains confirmed inputs, snapshots UDP lag stats. | `functions/10028710_FUN_10028710.md`. |
| `10028960` | Bridges UdpProtocol events: connected `1000`, synchronizing `1001`, running `1002`, remote input into Sync, and disconnected `1003`. | `functions/10028960_FUN_10028960.md`. |
| `100285d0` | Maps Sync prediction stats plus UdpProtocol network stats into `GGPONetworkStats`. | `functions/100285d0_FUN_100285d0.md`; `functions/10022ce0_FUN_10022ce0.md`; `functions/100244f0_FUN_100244f0.md`. |
| `10028590` | Allows frame-delay changes only before first synchronized input, then delegates to Sync. | `functions/10028590_FUN_10028590.md`. |
| `10028790` | Peer teardown destroys TimeSync, UdpProtocol, SyncCore, and poll/shared state. | `functions/10028790_FUN_10028790.md`. |
| `10023fa0` | Configures UDP remote endpoint and registers the 1000ms protocol timer. | `functions/10023fa0_FUN_10023fa0.md`. |
| `100230e0` | Pops one queued UdpProtocol event from the event queue. | `functions/100230e0_FUN_100230e0.md`. |
| `10022ce0` | Produces UdpProtocol network stat snapshot: ping, local/remote frame lag, and send queue length. | `functions/10022ce0_FUN_10022ce0.md`. |
| `100244f0` | Produces UDP socket stat snapshot used by protocol stats. | `functions/100244f0_FUN_100244f0.md`. |

Implementation notes:

- The native peer event bridge preserves the documented GGPO event codes: `1000`, `1001`, `1002`, `1003`, and TimeSync `1004` from synchronize-input.
- The native `PeerBackend` has a `GGPOSession` header and vtable-compatible behavior for existing export wrappers; `ggpo_start_session` is wired to this native path.
- The scalar deleting-destructor slot `10002890` is covered by the native public close path: the session destroy hook runs peer teardown and deletes the peer object, matching the documented destructor-plus-flag-delete behavior.

## Final Conversion Boundary

The main native client and direct session exports are wired. The conversion ledger now has no remaining `decompiled_imported` rows.

| Area | Resolution |
| --- | --- |
| Sync save/load/rollback and prediction | Native converted in `sync_core`, `prediction`, and upload producer modules |
| UDP protocol handshake/messages | Native converted in UDP protocol/socket modules |
| Udp socket/poll integration | Native converted in UDP socket and poll backend modules |
| Time sync | Native converted in `time_sync` |
| Peer backend vtable methods | Native converted in `peer_backend` |
| Client TCP parser/serializer helpers | Native converted in `client_backend`, `client_backend_upload`, and `streaming_backend` |
| Backend deleting destructor slots | Native converted through the session destroy hook and backend teardown/delete paths |
| STL/CRT/compiler/zlib helper rows | Native runtime mapped in `native-runtime-mappings.md` |

Anonymous helper rows were not marked converted solely to increase percentage; runtime-mapped rows are limited to the direct evidence categories documented in `native-runtime-mappings.md`.

## Client Wrapper Foundation Batch

The native tree now contains a wired `ClientBackend` in `Sources/FightcadeFBNeo/src/dep/ggponet-native/src/client_backend.cpp`.

Converted in this batch:

| Entry | Native Mapping | Evidence |
| --- | --- | --- |
| `10029f70` | `GGPOBackend::client_chat`: returns false without a match id; otherwise sends chat command `0xf`. | `functions/10029f70_FUN_10029f70.md`. |
| `10026380` | Chat command payload: match id string, chat text string, command `0xf`. | `functions/10026380_FUN_10026380.md`. |
| `100299b0` | `GGPOBackend` teardown path destroys client TCP state and delegates to peer backend teardown. | `functions/100299b0_FUN_100299b0.md`. |
| `10029a40` | `GGPOBackend` constructor: peer construction on local UDP port `0x1770`, client state initialization, TCP connect to `ggpo.fightcade.com`, version command, and connecting event `5000`. | `functions/10029a40_FUN_10029a40.md`. |
| `10029c30` | TCP event pump: connect response, start match, match info, spectator count, match-filtered chat, upload trigger, and disconnect handling. | `functions/10029c30_FUN_10029c30.md`. |
| `10029fb0` | Idle wrapper delegates peer idle, then processes TCP lobby events outside peer poll reentrancy. | `functions/10029fb0_FUN_10029fb0.md`. |
| `10021e00` | `ggpo_client_connect` export returns the native client session or null on allocation failure. | `functions/10021e00_ggpo_client_connect.md`. |
| `10025320` | Final TCP flush drains the send queue with 10ms waits and closes the socket. | `functions/10025320_FUN_10025320.md`. |
| `10026420` | Client connect command `0xb`: match id string plus peer UDP local port. | `functions/10026420_FUN_10026420.md`. |
| `10026480` | TCP close helper shuts down and closes the native socket after final flush. | `functions/10026480_FUN_10026480.md`. |

Deleting destructor coverage:

- `10001420`: covered by the native public close path; the session destroy hook runs `GGPOBackend` teardown and deletes the client object, matching the documented destructor-plus-flag-delete behavior.

## Client Upload Producer Batch

The native client backend now includes the replay/spectator upload producer in `client_backend_upload.cpp`.

Converted in this batch:

| Entry | Native Mapping | Evidence |
| --- | --- | --- |
| `10025e90` | Sends command `0x11` with match id, input count, input size, and a 60-frame confirmed-input batch when spectators are connected. | `functions/10025e90_FUN_10025e90.md`. |
| `10025da0` | Sends command `0x12` with match id, compressed state size, original state size, and compressed save-state bytes. | `functions/10025da0_FUN_10025da0.md`. |
| `10025c90` | Sends command `0x13` with match id, NUL-terminated GGPOTV metadata, and compressed replay payload. | `functions/10025c90_FUN_10025c90.md`. |
| `100295e0` | Handles confirmed input producer events: spectator batch queue, delayed state upload trigger, replay start-state capture, and replay input queue. | `functions/100295e0_FUN_100295e0.md`. |
| `10029160` | Builds the full replay payload from captured save state plus input bytes, emits documented GGPOTV metadata fields, compresses payload, and delegates to command `0x13`. | `functions/10029160_FUN_10029160.md`. |
| `10029800` | Handles replay game events: start/reset, player metadata, scores, winner, final replay upload, and requested TCP flush. | `functions/10029800_FUN_10029800.md`. |

## Final Ledger Boundary

The conversion ledger now resolves `1180/1180` rows (`100.0%`): `229 native_converted`, `951 native-runtime-mapped`, and `0 decompiled_imported`.

The runtime-mapped portion is restricted to directly evidenced MSVC CRT/STL/compiler helpers, trivial compiler/library leaves with no protocol behavior, and bundled zlib support described in `native-runtime-mappings.md`.
