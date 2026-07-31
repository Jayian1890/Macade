# UDP Protocol Construction Map

This file records the native conversion evidence for `UdpProtocol` construction/configuration. It intentionally stops before packet dispatch, handshake, reliability, and message encoding.

## Native Files

- `Sources/FightcadeFBNeo/src/dep/ggponet-native/src/udp_protocol.hpp`
- `Sources/FightcadeFBNeo/src/dep/ggponet-native/src/udp_protocol.cpp`

## Converted Entries

| Entry | Native Mapping | Evidence |
| --- | --- | --- |
| `10003e40` | Constructs a protocol event by storing the event type. | `functions/10003e40_FUN_10003e40.md`. |
| `10008a50` | Installs the UDP callback receiver vtable. | `functions/10008a50_FUN_10008a50.md`; `binary-source.md` identifies `Udp::Callbacks::vftable`. |
| `100230a0` | Starts UDP listening by passing the local port and protocol callback receiver to the socket init routine. | `functions/100230a0_FUN_100230a0.md`; it passes `this + 4` into `100246e0`. |
| `10023130` | Constructs `UdpProtocol`: callback receiver, embedded UDP socket, protocol queues/state, idle env knobs, four `GameInput(-1, null, 1)` slots, and disconnect state. | `functions/10023130_FUN_10023130.md`. |
| `10023320` | Queues a protocol event and logs `Queuing event`. | `functions/10023320_FUN_10023320.md`. |
| `10023350` | UDP disconnect callback: creates event type `4` and queues it on the protocol event queue. | `functions/10023350_FUN_10023350.md`. |
| `100233a0` | UDP first-packet callback: creates event type `0` and queues it on the protocol event queue. | `functions/100233a0_FUN_100233a0.md`. |

## Constructor State Evidence

- `10023130` writes the primary `UdpProtocol::vftable` at object offset `+0` and the `Udp::Callbacks` vtable at `+4`.
- `10023130` constructs the embedded `Udp` object at `+8` via `10024aa0`.
- `10023130` zeroes protocol state at `+0x10a0`, `+0x10a4`, `+0x10c4`, and `+0x1138`.
- `10023130` constructs one queue at `+0x10a8` and another at `+0x1144`.
- `10023130` initializes four `GameInput` records at `+0x111c`, `+0x10e4`, `+0x10c8`, and `+0x1100` with frame `-1`, null data, and size `1`.
- `10023130` clears 12 bytes at `+0x1094`.
- `10023130` reads `ggpo.idle.framecount`; nonzero values are capped at `10`, otherwise the default is used.
- `10023130` reads `ggpo.idle.frameboost`; nonzero values override the default.

## Verified Defaults

The default constants are from the verified DLL `.data` section at the documented PE mapping in `binary-source.md`:

- `DAT_10038528 = 5`
- `DAT_10038530 = 5`
- `DAT_10038534 = 3`
- `DAT_10038538 = 1000`

## Final Boundary

`10024240` is covered for the complete documented dispatch table, including compressed input type `3`. The surrounding peer backend vtable/session methods, peer event bridge from UdpProtocol type-`3` input events into Sync/Prediction, and reliability/ack/send queue behavior reached by `UdpProtocol::vftable` are covered by the native peer/UDP modules and final conversion ledger.

## Control Message Batch

The native implementation now covers the non-compressed UDP protocol control messages. This includes message sizing, logging, sync request/reply, quality report/reply, and local connect status calculation.

| Entry | Native Mapping | Evidence |
| --- | --- | --- |
| `10007810` | Returns UdpMsg wire size as payload size plus the type byte. | `functions/10007810_FUN_10007810.md`. |
| `10007830` | Computes payload size by message type: fixed sizes for sync/quality messages and bitvector-derived size for compressed input. | `functions/10007830_FUN_10007830.md`. |
| `10008950` | Constructs a UDP message by writing the type byte. | `functions/10008950_FUN_10008950.md`. |
| `10022b70` | Converts elapsed milliseconds to 60 Hz frame count. | `functions/10022b70_FUN_10022b70.md`. |
| `10022bb0` | Computes local connect status from remote frame, RTT frames, elapsed quality-report frames, and current frame. | `functions/10022bb0_FUN_10022bb0.md`. |
| `10022c20` | Handles quality reply by storing `now - echoed_timestamp` as round-trip time. | `functions/10022c20_FUN_10022c20.md`. |
| `10022c50` | UDP protocol log helper prefixes with `udp proto \| `. | `functions/10022c50_FUN_10022c50.md`. |
| `10022d40` | Invalid message path asserts/fails on unknown protocol messages. | `functions/10022d40_FUN_10022d40.md`. |
| `10022e20` | Logs synchronized event queueing for event type `2`. | `functions/10022e20_FUN_10022e20.md`. |
| `10022e60` | Logs UdpMsg details for sync request/reply, quality report/reply, and compressed-input headers. | `functions/10022e60_FUN_10022e60.md`. |
| `10023930` | Logs outgoing messages and queues them for UDP send. | `functions/10023930_FUN_10023930.md`. |
| `10023960` | Sends sync request: stores timestamp, generates 16-bit random token, sends type `1`. | `functions/10023960_FUN_10023960.md`. |
| `10023fe0` | Handles quality report: replies with type `5`, echoes timestamp, stores remote connect status. | `functions/10023fe0_FUN_10023fe0.md`. |
| `10024050` | Handles sync reply: validates token, decrements retries, queues progress/synchronized events, resends until synchronized. | `functions/10024050_FUN_10024050.md`. |
| `100241b0` | Handles sync request by sending type `2` reply with the received token. | `functions/100241b0_FUN_100241b0.md`. |
| `10024210` | Starts synchronization: state `0`, retry count `5`, first sync request. | `functions/10024210_FUN_10024210.md`. |

## Compressed Input Batch

The native implementation now covers the verified UDP compressed-input packet path without wiring peer session exports.

| Entry | Native Mapping | Evidence |
| --- | --- | --- |
| `100228f0` | Reads one bit from a little-endian bitvector and advances the bit offset. | `functions/100228f0_FUN_100228f0.md`. |
| `10022a10` | Reads an 8-bit value from the bitvector, least-significant bit first. | `functions/10022a10_FUN_10022a10.md`. |
| `10022950` | Writes a zero bit into the bitvector and advances the bit offset. | `functions/10022950_FUN_10022950.md`. |
| `100229b0` | Writes a one bit into the bitvector and advances the bit offset. | `functions/100229b0_FUN_100229b0.md`. |
| `10022a60` | Writes an 8-bit value into the bitvector, least-significant bit first, with the documented `< 0x100` assertion. | `functions/10022a60_FUN_10022a60.md`. |
| `100239f0` | Builds type-`3` compressed input packets from the pending local input queue, delta-encodes changed bits, writes start frame, ack frame, bit count, and input size, then queues UDP send. | `functions/100239f0_FUN_100239f0.md`. |
| `100233f0` | Handles type-`3` compressed input packets: ignores input while syncing, decodes bit deltas into `_last_received_input`, queues input events, and discards pending local outputs older than the remote ack frame. | `functions/100233f0_FUN_100233f0.md`. |
| `10023eb0` | Queues local output input, tracks idle frames via frame-agnostic `GameInput` equality, applies the initial 10-frame send grace, and sends/skips according to idle frame count/boost policy. | `functions/10023eb0_FUN_10023eb0.md`; `DAT_1003852c = 10` from verified DLL `.data`. |
| `10024240` | Dispatches the full message table: invalid type `0`, sync request `1`, sync reply `2`, compressed input `3`, quality report `4`, quality reply `5`, and invalid fallback. | `functions/10024240_FUN_10024240.md`. |
| `10024390` | Timer path covers state-`0` sync retry and state-`2` resend/quality-report behavior, including compressed-input resend when the last received/sent frames have not advanced. | `functions/10024390_FUN_10024390.md`. |

Implementation notes:

- Type-`3` message layout is preserved as `type`, `start_frame`, `ack_frame`, `bit_count`, `input_size`, then compressed bitvector bytes.
- Delta encoding writes changed bits as `has_change=1`, `new_bit_value`, `bit_index_byte`; each frame terminates with `has_change=0`.
- Decoding queues a native `UdpProtocolEvent` of type `3` with a copied `GameInput` payload, matching the documented event creation after `_last_received_input` is advanced.
- The native code still does not expose `ggpo_start_session` or `ggpo_client_connect`; peer backend event consumption remains a separate parity gate.
