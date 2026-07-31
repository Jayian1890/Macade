# Prediction And Input Queue Map

This map is derived from the verified `docs/ggponet/raw-c` corpus. The input queue gate in `native-parity-plan.md` must be implemented as a prediction manager, not as isolated container helpers.

## Core State

The prediction layer uses three `GameInput` queues and a last-remote input record.

| Logical state | Evidence |
| --- | --- |
| Local queue at `+0x10` | `10021340` adds local input and pads missing frames; disassembly calls queue helpers with `ECX = this + 0x10` |
| Remote queue at `+0x30` | `10021290` adds remote input and has an initial generated-input workaround; disassembly calls queue helpers with `ECX = this + 0x30` |
| Game queue at `+0x50` | `10020eb0` pushes emulator-facing frames; `10021870` requires size `1` before pop with `ECX = this + 0x50` |
| Prediction queue at `+0x70` | `10020700`, `10020940`, `10020eb0` push/rebase/check predicted local frames; disassembly uses `ECX = this + 0x70` |
| Sync queue at `+0x8c` | `10021870` prefers this queue and labels it `SyncQueue`; `10021340` asserts it is empty before accepting local input |
| Last remote input at `+0xa8` | `10020700`, `10020940`, `10020eb0` compare/merge with local frames |
| Confirmed event queue at `+0xc4` | `100206b0` pushes type-`0` plus `GameInput` records; `100205f0` pops 8 dwords and `10002830` exposes them to peer idle |

## Scalar Fields

| Offset | Role | Evidence |
| ---: | --- | --- |
| `+0x04` | max prediction frames | `10020570` compares prediction queue size to `field - 1`; `10020eb0` also gates prediction movement against this field |
| `+0x08` | frame delay | `10021340` adds this to incoming local frame before queueing |
| `+0x0c` | next expected local frame | `10021340` pads until this frame and increments after local inserts |
| `+0xe4` | saved prediction queue count | `10021660` records `+0x70` count before consistency check |
| `+0xe8` | saved remote queue count | `10021660` records `+0x30` count before consistency check |

## Function Roles

| Entry | Role |
| ---: | --- |
| `10020570` | Ready-for-local-input check: prediction queue size is below configured cap minus one |
| `100206b0` | Push one confirmed type-`0` event containing a `GameInput` into the queue at `+0xc4` |
| `10020700` | Check predicted frames against remote queue; returns first mismatch frame or `-1` |
| `10020940` | Rebase prediction queue after a mismatch by replaying queued predictions |
| `10020eb0` | Move prediction forward; merge local/remote inputs into confirmed game queue and queue confirmed events when remote input is available |
| `10021290` | Add remote input, including first-frame generated input workaround when needed |
| `10021340` | Add local input, apply frame delay, pad missing local frames, enforce next expected frame |
| `10021870` | Get input for emulator from sync queue or game queue and assert requested frame matches |

## Required Native Boundary

Implement these together as one `Prediction` module after `GameInput` and before `Sync` wiring. A queue-only module would be incomplete because the verified behavior includes frame-delay adjustment, prediction replay, mismatch detection, and local/remote merge semantics.
