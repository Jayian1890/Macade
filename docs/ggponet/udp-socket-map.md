# UDP Socket Map

This file records the native conversion evidence for the UDP socket unit used by the peer backend. The source of truth is the verified `ggponet.dll` decompilation under `docs/ggponet/functions` and `docs/ggponet/raw-c`.

## Native Files

- `Sources/FightcadeFBNeo/src/dep/ggponet-native/src/udp_socket.hpp`
- `Sources/FightcadeFBNeo/src/dep/ggponet-native/src/udp_socket.cpp`

## Converted Entries

| Entry | Native Mapping | Evidence |
| --- | --- | --- |
| `10007990` | Builds a packet stat from size plus current monotonic timestamp. | `raw-c/10007990_FUN_10007990.c` stores input size and `timeGetTime()`. |
| `10024520` | UDP log helper prefixes messages with `udp \| ` and forwards to quark logging. | `functions/10024520_FUN_10024520.md` formats into a 1024-byte buffer and calls `FUN_10021ff0`. |
| `100245b0` | Creates a nonblocking UDP socket, binds from base port through base + range, closes on failure, and signals the poller when re-priming. | `functions/100245b0_FUN_100245b0.md` calls socket/bind/closesocket and logs bind/retry/re-prime messages. |
| `100246e0` | Reads `ggpo.network.delay`, stores local port and receiver callback target, then binds `port..port+10`. | `functions/100246e0_FUN_100246e0.md`. |
| `10024750` | Drains queued sends when optional network delay has elapsed; asserts remote endpoint, calls `sendto`, accounts sent bytes, and pops the packet. | `functions/10024750_FUN_10024750.md`. |
| `10024a10` | Poll idle callback that flushes the send queue and returns true. | `functions/10024a10_FUN_10024a10.md`. |
| `10024a30` | Destroys socket state, closes the socket, and clears native queues. | `functions/10024a30_FUN_10024a30.md`. |
| `10024aa0` | Initializes socket descriptor, local port, remote sockaddr, first-packet and receive-pending flags, stats, queues, and poll callback target. | `functions/10024aa0_FUN_10024aa0.md`. |
| `10024ba0` | Prunes packet stats older than 3000 ms, computes bandwidth/count/KB/overhead, and logs the exact network stats format. | `functions/10024ba0_FUN_10024ba0.md`. |
| `10024d60` | Queues a packet with current timestamp and attempts a send drain. | `functions/10024d60_FUN_10024d60.md`. |
| `10024da0` | Nonblocking receive loop with first-packet callback, packet callback, packet-stat insertion, no-data pending state, and `ECONNRESET` rebind handling. | `functions/10024da0_FUN_10024da0.md`. |
| `10025090` | Configures remote IPv4 endpoint with `inet_addr`/`htons`, registers handle/timer/idle poll callbacks, logs priming/remote endpoint, and wakes the poller. | `functions/10025090_FUN_10025090.md`. |

## Platform Mapping

- WinSock `socket(AF_INET, SOCK_DGRAM, 0)`, `bind`, `sendto`, and async `WSARecv` are mapped to BSD sockets with nonblocking `recv` under the existing native `PollBackend`.
- Windows manual event wakeups are mapped to `poll_backend_signal`, preserving the documented re-prime and remote-endpoint wake behavior.
- The overlapped pending flag at `+0x35` maps to `UdpSocket::receive_pending`; `EAGAIN`/`EWOULDBLOCK` is the native no-data/pending state.
- The first-packet flag at `+0x34` maps to `UdpSocket::received_first_packet` and controls first-packet/disconnect callback sequencing.
- Generic STL/deque helper rows used by this code path are runtime-mapped in `CONVERSION_STATUS.csv` only where their exact generic helper behavior is evidenced by the corpus.

## Final Peer Status

This document maps the UDP socket unit. The surrounding `UdpProtocol`, peer event bridge, peer backend vtable behavior, and `ggpo_start_session` / `ggpo_client_connect` exports are now covered by the native implementation and final ledger accounting.
