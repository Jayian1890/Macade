# Sync Core Map

This map is derived from the verified `docs/ggponet/functions` and `docs/ggponet/raw-c` corpus. It covers the native Sync core that sits above Prediction and below Peer2PeerBackend. UDP transport/protocol behavior is intentionally excluded here.

## State

| Logical state | Evidence |
| --- | --- |
| Callback table at Sync `+0x04` | `10020350` copies seven callback pointers; `1001fe30`, `1001fef0`, and `10020080` call save/load/free/advance callbacks by offset |
| Prediction subobject at `+0x20` | `100203d0` constructs it, `10020350` initializes it, and `10020420`/`10020460`/`10020480`/`100204f0` delegate through it |
| Current frame at `+0x10c` | `10002810`, `100202e0`, `10020480`, and `100204f0` read or update it |
| Saved-state ring at `+0x110` | `1001fe30` and `1001fef0` use 22 records, each 16 bytes: buffer, size, frame, checksum |
| Saved-state head at `+0x270` | `1001fce0`, `1001fe30`, and `1001fef0` use modulo `0x16` ring indexing |

## Function Roles

| Entry | Role |
| ---: | --- |
| `1001fce0` | Previous saved-state ring entry lookup |
| `1001fd20` | Find saved-state index by frame, assert if missing |
| `1001fe30` | Save current frame, free overwritten buffer first, advance ring head |
| `1001fef0` | Load a saved frame, set `_framecount = saved.frame + 1`, advance ring head |
| `10020080` | Rollback catch-up: load `seek_to`, call `advance_frame(0)` `count` times, assert original frame count is restored |
| `100202e0` | Save current frame and increment frame count |
| `10020310` | Return saved-state buffer and size for a frame |
| `10020350` | Copy callbacks/options and initialize Prediction with frame delay and max prediction frames |
| `100203b0` | Sync destructor path delegates Prediction teardown |
| `100203d0` | Sync constructor path initializes Prediction, frame count, saved-state ring |
| `10020420` | Run Prediction consistency check and perform rollback catch-up when needed |
| `10020460` | Add remote input to Prediction |
| `10020480` | Add local input at current frame if Prediction accepts it |
| `100204f0` | Get emulator input for current frame from Prediction |
| `10020520` / `10002850` | Read saved Prediction queue counts for stats |

## Boundary

`10022bb0` and `10023eb0` remain outside this Sync-core pass because they use UdpProtocol timing/send state and call UDP send paths. They must be converted with the UDP protocol gate, not as standalone Sync code.
