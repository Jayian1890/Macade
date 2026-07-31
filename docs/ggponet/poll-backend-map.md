# Poll Backend Map

This map is derived from verified `docs/ggponet/functions` and `docs/ggponet/raw-c` evidence. It covers the shared polling state constructed by Peer2PeerBackend before Sync and UDP protocol construction.

## State

| Logical state | Evidence |
| --- | --- |
| Start timestamp at `+0x00` | `10028090` initializes it from `timeGetTime()` on first run and computes elapsed time from it |
| Handle count at `+0x04` | `100284c0` sets it to `0`, adds one constructor-created manual event, and `10028330` increments it for registered handles |
| Wait handles at `+0x08` | `10028090` passes this array to `WaitForMultipleObjects`; `10028330` stores registered handles here |
| Handle callbacks at `+0x108` | `10028330` stores target/context pairs; `10028090` invokes target vtable slot `0` when a handle fires |
| Per-idle callbacks at `+0x308` / `+0x320` | `10028090` invokes vtable slot `1` before timers and slot `3` after timers; `10028490` appends callback pairs |
| Periodic timers at `+0x338` | `10028450` stores target/context/interval/last-fired; `10027ff0` computes next delay; `10028090` invokes vtable slot `2` |

## Function Roles

| Entry | Role |
| ---: | --- |
| `100079f0` | Build target/context callback pair |
| `10008c90` | Build timer callback record with interval and zero last-fired time |
| `10027ff0` | Return next timer timeout, clamped at zero, or `-1` with no timers |
| `10028090` | Poll run loop: wait handles, run pre-idle callbacks, run due timers, run post-idle callbacks |
| `10028330` | Register handle and handle callback, asserting `_handle_count < MAX_POLLABLE_HANDLES - 1` |
| `10028450` | Register periodic timer callback |
| `10028490` | Register per-idle callback pair |
| `100284c0` | Construct poll backend state and add constructor-created manual event |

## Native Mapping

The Windows DLL uses manual-reset events and `WaitForMultipleObjects`. The native macOS implementation uses `poll(2)` and a nonblocking wake pipe for the constructor-created manual event. This preserves the evidenced behavior without depending on Windows handles.

Socket-specific `SetEvent`/`ResetEvent` calls remain part of the UDP and TCP socket gates; the poll module exposes signal/reset hooks for those later conversions.
