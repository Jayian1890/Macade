# Issue #3: display-aware embedded presentation

## Producer and consumer trace

Read alongside `single-player-launch.md`, `verification.md`, and the local research in `docs/ggponet/native-parity-plan.md` / `native-runtime-mappings.md`.

- Local FBNeo: `RunIdle` → `AudSoundCheck` → `SDLSoundCheck` → `RunGetNextSound` → `RunFrame`. Audio segment consumption clocks simulation. Catch-up sound segments can use `bDraw = 0`; only drawn frames reach video publication. A 59.6 Hz mean does not imply equally spaced publications.
- Embedded matches: `RunIdle` → `RunEmbeddedNetGameIdle` uses the existing `nAppVirtualFps` accumulator and `nEmbeddedNetRunQuark` idle gate. `RunFrame` obtains synchronized input, renders, then notifies GGPO. Catch-up can omit drawing. Prediction-barrier backpressure returns to the existing idle path. Spectator audio force-draw behavior is separate and unchanged.
- Video: `vid_sdl2.cpp::Frame` → `MacadeEmbeddedPublishScaledFrame` → `MacadeEmbeddedPublishFrame`. The bridge copies pixels into one of three shared-memory slots and updates the shared layout, write slot, and publication index. This index counts published images, **not** emulated frames or GGPO frames. Slots have no independent timestamp/layout metadata; they are not a safe historical frame queue with the existing ABI.
- Previously, `EmbeddedVideoNSView` requested `preferredFramesPerSecond = 60`, read only the latest publication, uploaded it, and submitted a drawable. Duplicates returned without drawing. `EmbeddedVideoDiagnostics` counted submissions as `fps`, not physical presentation, and every new view recreated `fightcade-embedded-video-latest.log`.

[Apple's MTKView documentation](https://developer.apple.com/documentation/metalkit/mtkview/preferredframespersecond) says the actual requested rate is normally a divisor of the display maximum. Requesting 60 on a 144 Hz screen can select 48. This explains the issue's reported steady 48 Hz behavior; the 144 Hz observation is the reporter's evidence, not a hardware measurement from this implementation run.

At 60 Hz, independently timed, uneven publications can arrive twice between display samples, followed by a sample with no new image. Reading only the latest discards one image from the burst. Raising the consumer rate on a 120/144 Hz screen reduces this sampling loss, but neither makes the producer evenly paced nor creates additional game frames.

## Implemented presentation boundary

`EmbeddedVideoNSView` disables MTKView's internal timer and creates an [NSView display link](https://developer.apple.com/documentation/appkit/nsview/displaylink(target:selector:)). The callback runs in the main run loop's common modes, requests the active screen's maximum refresh rate, and calls `draw()`. The Metal layer keeps display synchronization enabled. Screen/mode changes update the requested range; detaching, hiding, occluding, or ending the session stops the link. A weak target breaks the display-link/view retain cycle.

At rates above 60 Hz, each display callback samples the latest publication directly. Duplicate publications do not incur another upload/presentation. A resize, settings change, or reattachment can redraw the retained texture even without a new publication. Session changes reset frame identity and textures so identical indices from different sessions cannot be confused.

At rates of 60 Hz or below, `EmbeddedVideoFrameBuffer` observes new publications in a detached task with a requested 1 ms sleep. It copies only new images into owned memory; presentation consumes them in arrival order on display callbacks. This separates burst capture from display sampling without modifying the producer or relying on old shared-memory slots. The queue holds at most two images, dropping the oldest on overflow rather than accumulating latency. Polling is best effort, not a real-time guarantee. The task is cancelled when the consumer detaches, becomes hidden/occluded, switches to a faster display, or is released.

This buffer trades some latency for cadence: normally up to roughly two display intervals of capture-to-dequeue age, plus GPU/compositor time. It adds no fixed startup wait. `maxBufferAgeMs` measures the observed capture-to-dequeue age, not input-to-photon latency. Severe process/UI/GPU stalls can still lose publications. The 1 ms polling and frame copies add CPU/memory traffic only while the low-refresh consumer is active.

Only one GPU submission owns the upload texture at a time. If the previous command has not completed, the callback records `gpuBusy` and returns without waiting or replacing that texture. Metal failures are logged. No call waits for GPU completion on the main thread.

**Unchanged:** native FBNeo source and binaries, shared-memory ABI, audio cadence, `RunEmbeddedNetGameIdle`, `nAppVirtualFps`, frame delay, input collection/serialization, rollback, `QuarkRunIdle`, GGPO advance/synchronize calls, route arguments, matchmaking, and transport. The safe seam demonstrated here is the Swift image consumer. This work makes no timing/protocol parity claim beyond preserving those paths.

## Session diagnostics

The session owns one `EmbeddedVideoDiagnostics` service under `Core/Fightcade`. A view only records events into it. Files live beside the launch log, normally `~/Library/Logs/Macade/`:

- `fightcade-embedded-video-<mode>-<session UUID>.log`
- `fbneo-embedded-<UTC timestamp>-<same session UUID>.log`

The video header records mode, emulator, game, session ID, and launch-log path. Same-mode and same-second launches cannot collide. View recreation appends to the same session writer. Termination/failure flushes the partial summary and closes it. `fightcade-embedded-video-latest.log` is only a convenience symlink; replacing it does not truncate its target. An old regular file at that path is preserved as `fightcade-embedded-video-legacy-<UUID>.log` before migration.

Summaries distinguish:

- `callbackHz`, requested screen rate, and `targetIntervalMs`: display-link scheduling, not emulator FPS.
- `submittedFPS` / `submitted`: new publication indices committed to Metal.
- `presentedFPS` / `presented`: new drawable presentation callbacks with a positive `presentedTime`. Delivery can lag submissions or interval boundaries; static drawables may report late when recycled. Pending callbacks after session closure are not counted.
- `duplicate`: no new image available to the consumer; expected on 120/144 Hz with a roughly 60 Hz source. This is not inherently a stutter count.
- `skipped` / `maxGap`: missing publication indices between submissions. Initial attachment and hidden time are excluded. These do not measure undrawn simulation frames.
- `bufferDrops`, `maxBufferAgeMs`, `gpuBusy`, missing/failed reads, upload/submission costs, and maximum tick/submission/presentation intervals.

For the buffered path, snapshot cost measures dequeue work; frame copying occurs in the capture task. Physical scanout and input-to-photon latency require external measurement.

## Evidence and verification (2026-10-05)

Host: Apple M1, built-in 2560×1600 Retina display, requested/measured display cadence approximately 60 Hz. ROM: installed `sfiii3nr1`, output 384×224. These are short local integration captures, not controlled performance benchmarks or M4 Pro measurements.

| Capture | Observation |
| --- | --- |
| Display-linked latest-only consumer, session `59F3B561-46C1-4CA2-B634-0481E925E87C` | Eight seconds: 476 publication intervals observed by best-effort 1 ms polling; mean 16.783 ms (~59.6 Hz), range 2.086–34.150 ms. Summary submissions 45.38–51.57 FPS; actual presentation callbacks 44.88–52.07 FPS. This reproduced the loss even after replacing the clock. |
| Two-image buffer, session `B4C5E9E4-25D4-4CAC-98FE-6C07D7414DD1` | Eight seconds: submissions 58.00–59.12 FPS; presentation callback summaries 57.13–59.01 FPS (including startup). Observed maximum presentation gap 33.33 ms. Queue overflow remained visible: 7 dropped captured images across the run. |
| Buffer-age instrumentation, session `3ED880C2-F12F-458A-8FA1-0F1BABF17009` | The view became occluded after 1.69 seconds and diagnostics correctly detached. That short visible segment had max captured-image age 30.95 ms, 55.76 submissions/s and 53.98 presentation callbacks/s; it is not an eight-second steady-state result. Main-thread publication observation also saw a 99 ms interval, so this run is not evidence of smooth sustained delivery. |

The first two captures support consumer-side burst loss and its mitigation, while retaining occasional stalls. They do not prove the original report has no additional producer-side problem.

Reproduce the opt-in native-ROM presentation capture with no existing FBNeo game running:

```sh
TEST_RUNNER_MACADE_SINGLE_PLAYER_RUNTIME=1 TEST_RUNNER_MACADE_VIDEO_RUNTIME=1 \
  xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' \
  -derivedDataPath .build/xcode -only-testing:MacadeAppTests/SinglePlayerLaunchTests test
```

Keep its window visible for eight seconds; another window covering it intentionally suspends presentation. Native launch checks verify advancing images and process termination. Unit/integration tests cover unique logs, legacy-log preservation, view reattachment, final summaries, Metal submission after switching sessions with the same frame index, buffer ordering, owned pixel copies, overflow, duplicate capture, and safe stream closure. The timing capture reports observations rather than asserting a machine-dependent FPS threshold.

Required manual follow-up: physical 60/120/144 Hz and ProMotion mode changes, moves between screens, long runs, high video scaling, minimization/restore, and both sides of real direct/served Fightcade matches. For each mode, retain the UUID-specific video and launch logs. Expect roughly 2 or alternating 2/3 display ticks per new image at 120/144 Hz; do not expect 120/144 unique emulator images. Live online cadence, controller latency, audio synchronization, and non-FBNeo emulator performance were not measured here.

Final validation: `xcodebuild ... test` with `TEST_RUNNER_MACADE_SINGLE_PLAYER_RUNTIME=1` passed all 157 tests with zero failures and no skips. The subsequent explicit `xcodebuild ... build` succeeded. `git diff --check` passed. All changed Swift files remain below 500 lines. Native FBNeo and route/protocol sources have no diff; the existing GGPO timing documentation was checked and its preserved boundary cross-referenced.
