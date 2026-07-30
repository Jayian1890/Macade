# Macade Fightcade AI Context

Purpose: authoritative, AI-digestible context for Macade's Fightcade integration, native FBNeo runtime, GGPO/network parity, capture workflow, and release gates. Companion implementation plans under `docs/` may exist, but this file remains the source of truth for current evidence and project rules.

## Non-Negotiables

| Rule | Value |
| --- | --- |
| Product target | Native macOS SwiftUI app compatible with Fightcade backend. |
| Backend rule | Do not create replacement matchmaking/backend behavior. |
| Authority order | Current Windows Fightcade binaries/captures, current web protocol, public Fightcade source integration points, `ggponet.dll` static analysis, historical source only as context. |
| Forbidden authorities | Outdated official macOS DMG; Linux client assumptions unless current web evidence requires them. |
| User-facing language | Avoid GGPO/quark/protocol jargon; use plain-language status. |
| Build verification | Use `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build`. |

## Fightcade Architecture

| Component | Current understanding |
| --- | --- |
| Desktop shell | Nativefier/Electron wrapper around `https://web.fightcade.com/`. |
| Lobby transport | Raw browser WebSocket at `wss://ggs.fightcade.com/ws/`. |
| Helper API | `https://web.fightcade.com/api/`, JSON POST. |
| Launcher status API | `https://web.fightcade.com/fc2status/api/`. |
| Official launcher | `fcade://` URL handler; not a dumb command runner. |
| Emulator layer | Official emulator builds plus Fightcade GGPO integration. |
| Netplay handoff | Backend emits match metadata; launcher/runtime performs NAT traversal; emulator receives `quark:` route. |

Public components: `fightcade-fbneo`, `fightcade-snes9x`, `fightcade-detectors`, `fightcade-motd`, upstream MIT `pond3r/ggpo`. Private components: backend, full frontend, local launcher source, GGPO service, `ggponet.dll` source.

## Evidence Index

| ID | Artifact | Notes |
| --- | --- | --- |
| dll.current | external evidence, not currently tracked | Canonical current DLL evidence was removed with `.build`; reacquire before new static-analysis work. |
| dll.sha256 | `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8` | Same for FBNeo/GGPOFBA/SNES9x package copies. |
| asm | external evidence, not currently tracked | Primary static map was removed with `.build`; reacquire before new static-analysis work. |
| decomp | external evidence, not currently tracked | RetDec C was removed with `.build`; verify against ASM/captures when restored. |
| decomp.current | `docs/ggponet/` | Current Ghidra 12.1.2/PyGhidra decompiler output for `ggponet.dll`, focused `ggpofba-ng.exe` GGPO/quark slice, and unpacked `kailleraclient.dll`; includes per-function Markdown, raw C-like pseudocode, calls, callers, strings, data refs, disassembly, indexes, and relevance notes. |
| extracts | external evidence, not currently tracked | Focused TCP/UDP/backend extracts were removed with `.build`. |
| ghidra.project | local ignored scratch, not retained | Ghidra hidden project paths are rejected; use non-hidden ignored paths such as `ghidra-out/project` when regenerating, then remove transient project DBs after export. |
| ghidra.export | `docs/ggponet/` | Current Ghidra 12.1.2/PyGhidra function/symbol/string export docs; `ggponet.dll` full export has all 1180 discovered functions decompiled with status `ok`. |
| ghidra.exporter | local ignored `.reverse-engineering/ggponet/scripts/ExportGgponetDocs.py` | Retained locally with the tool install; not tracked. Recreate or recover from local scratch before rerunning exports elsewhere. |
| address.map | `docs/ggponet-address-map.md` | Reviewed Phase 2 address map for exports, vtables, UDP/TCP targets, and public-GGPO boundaries. |
| public.ggpo.boundary | `docs/ggpo-public-port-boundary.md` | Phase 3 exact public GGPO port/adapt/reference/do-not-port decisions. |
| runtime.abstraction | `docs/ggpo-runtime-abstraction-design.md` | Phase 4 native runtime module boundaries for rollback, UDP, TCP, rendezvous, stream, callbacks, and API shims. |
| parity.improvement.plan | `docs/fightcade-parity-improvement-plan.md` | Actionable Phase 5-10 order for diagnostics, ownership split, rollback migration, UDP/TCP parity, and evidence-gated closure. |
| pcap.current | `/Users/jayian/Downloads/fight.pcapng` | Current official capture; contains one failed/direct-fallback served attempt and one successful direct served attempt. |
| pcap.spectate | `/Users/jayian/Downloads/spectate.pcapng` | Current official spectator capture; proves spectator TCP connects to remote port `7000`, sends command `0`, then commands `20` and `12`, and receives server `-12` gamebuffer plus recurring `-13` frame batches. |
| pcap.summary | not currently tracked | Analyzer output was removed with `.build`; regenerate from `/Users/jayian/Downloads/fight.pcapng` after restoring analyzer tooling. |
| historical.proxy | external reference, not currently tracked | Context for proxy/punch/useports; not sole authority. |
| public.ggpo | external `pond3r/ggpo` checkout | MIT rollback/sync internals only; not currently vendored. |
| source.recovery.plan | `docs/ggponet-source-recovery-plan.md` | Hybrid public GGPO plus `ggponet.dll` recovery plan; Phase 4 runtime abstraction complete. |
| source.recovery.phase2 | `docs/ggponet-source-recovery-plan.md#phase-2-export-baseline` | Phase 2 export baseline and reviewed address map. |
| source.recovery.phase3 | `docs/ggponet-source-recovery-plan.md#phase-3-public-ggpo-boundary` | Phase 3 exact public GGPO port boundary. |
| source.recovery.phase4 | `docs/ggponet-source-recovery-plan.md#phase-4-runtime-abstraction-design` | Phase 4 native runtime abstraction design. |

## Binary Facts

| Fact | Evidence |
| --- | --- |
| Fightcade2 Windows package is Nativefier/Electron wrapper. | `fc2-electron/resources/app/nativefier.json`. |
| Package config URL/user-agent. | `https://web.fightcade.com/`, `Fightcade2-WIN32-v2.1.45`. |
| Local Electron app source is not Fightcade web source. | Unpacked app contains Nativefier shell code only. |
| `fcadefbneo.exe` imports `ggponet.dll`. | PE imports. |
| `ggpofba-ng.exe` imports `ggponet.dll` and `kailleraclient.dll`. | `docs/ggponet/ggpofba-ng/imports-exports.md`. |
| `ggpofba-ng.exe` route parser maps `quark:served/direct/synctest/stream/replay` to `ggponet.dll` exports. | `docs/ggponet/ggpofba-ng/functions/0062dc50_FUN_0062dc50.md`. |
| `kailleraclient.dll` is legacy Kaillera v0.9, not Fightcade GGPO/quark authority. | `docs/ggponet/relevance-assessment.md`; unpacked full function export under `docs/ggponet/kailleraclient/`. |
| FBNeo route strings | `quark:served`, `training`, `direct`, `stream`, `replay`, `debugdetector`. |
| Public Fightcade FBNeo lacks private client implementation. | Public source has headers/import lib, not `ggponet.dll` source. |

## Backend APIs

Helper API bootstrap:

```text
POST https://web.fightcade.com/api/
Content-Type: application/json
```

Known helper request: `{ "req": "location" }` returns `{ "location": "...encrypted...", "res": "OK" }`. Registration uses `reguser` with email, username, password, and recaptcha token.

Launcher status API: `fcade://userstatus/stwlan/{token}` posts to `https://web.fightcade.com/fc2status/api/` with `User-Agent: fcade` and payload fields `req`, `token`, `userstatus`, `uuid`, `guid`, `huid`, `version`, `hash`. Hash formula recovered from launcher: `md5("3jedoQ" + token + "qmkq0" + uuid + "dsnds" + guid + "sec or" + version + "2jden3" + userstatus + "llNjjha" + huid)`.

Lobby WebSocket: `wss://ggs.fightcade.com/ws/`. Requests are JSON strings. Callback requests include `requestIdx`; fire-and-forget uses `requestIdx: -1`.

Key requests: `login`, `autologin`, `join`, `leave`, `channels`, `filteroptions`, `welcome`, `chat`, `msg`, `command`, `challenge`, `cancel`, `reject`, `accept`, `staway`, `stnoaway`, `chaway`, `chnoaway`, `ignore`, `favchannel`, `linkpreview`.

Key events: `broken`, `chat`, `msg`, `join`, `leave`, `kick`, `staway`, `stnoaway`, `chaway`, `chnoaway`, `stwlan`, `updaterank`, `stplaying`, `stnoplaying`, `quarkstats`, `challenge`, `cancel`, `reject`, `accept`, `start`.

Authoritative match handoff is server event `start`; Macade must not launch on `accept` alone or invent match IDs.

```json
{ "req": "start", "channelname": "...", "quarkid": "...", "playerid": 0, "port": 7000, "ranked": 0, "delay": 2, "token": "...", "user": { "name": "opponent" } }
```

Ranked values observed: `0` unranked; `2`, `3`, `5`, `10`, `20` first-to lengths; `-1` training path mostly disabled/commented in official UI evidence.

## Runtime Layout

Macade launches emulator processes directly. It does not use LaunchServices or the installed Fightcade app.

Runtime lookup: `MACADE_FIGHTCADE_RUNTIME`, else `~/Library/Application Support/Macade/FightcadeRuntime` seeded from app bundle `Resources/FightcadeRuntime`.

Expected layout:

```text
FightcadeRuntime/
  manifest.json
  emulators/fbneo/macfbneo
  emulators/fbneo/lib/libSDL2-2.0.0.dylib
  emulators/fbneo/lib/libSDL3.dylib
  detector/*.inf
  roms/fbneo/*.zip
```

Manifest capability: `supportsQuark: true` means native runtime can attempt Fightcade-compatible routes; it does not mean full parity.

Runtime source: modified Fightcade FBNeo lives at `Sources/FightcadeFBNeo`. The tree is trimmed to the macOS SDL2 build inputs, with Macade-specific files under `Sources/FightcadeFBNeo/src/macade`. Runtime bundle resources are tracked at `Sources/MacadeApp/Resources/FightcadeRuntime`. No runtime install script is currently tracked after the `.build`/`scripts` cleanup; direct FBNeo source verification uses `make -f makefile.sdl` from `Sources/FightcadeFBNeo`.

Embedded mode env: `MACADE_EMBEDDED_SESSION_ID`, `MACADE_EMBEDDED_VIDEO_PATH`, `MACADE_EMBEDDED_VIDEO_BYTES`, `MACADE_EMBEDDED_INPUT_SOCKET`, `MACADE_EMBEDDED_HIDE_WINDOW=1`. FBNeo writes shared-memory video and consumes forwarded key events; audio still comes from SDL.

ROM downloader default index: `https://fightcade.download/fc2json.zip`, override with `MACADE_ROM_INDEX_URL`. Downloads are written to `FightcadeRuntime/roms/<emulator>/...`, dependencies are fetched first, and Fightcade-relative extract paths are remapped into the runtime.

## Launch Routes

| Route | Shape | Status |
| --- | --- | --- |
| served | `quark:served,{gameid},{quarkid}.{playerid},{port},{delay},{ranked}` | Implemented subset. |
| training | `quark:training,{gameid},{quarkid}.{playerid},{port},{delay}` | Maps to Training; server-derived metadata required. |
| direct | `quark:direct,{gameid},{localPort},{host},{remotePort},{player},{delay},{ranked}` | Implemented, needs live validation. |
| stream | `quark:stream,{gameid},{quarkid}.2,{port}` | Implemented subset; port must be the lobby-advertised stream port. Needs live validation. |
| replay | Win32-recognized route | Not implemented; keep unavailable. |
| synctest | DLL export, not Fightcade live network | Not implemented; local-only future work. |

Macade-emitted `served` and `direct` routes include ranked metadata. Runtime parsing also accepts current `ggpofba-ng.exe` no-ranked `served`/`direct` forms and treats ranked as `0` for those inputs.

Official web app emits `fcade://` URLs. Macade should launch native emulator processes from the same server-derived metadata. Other official launcher URLs include `play`, `training`, `checkrom`, `killemu`, `autoupdate`, and `userstatus`.

## ASM Anchors

| Area | VA | Evidence |
| --- | ---: | --- |
| UDP socket | `0x100245d4` | `socket`. |
| UDP bind | `0x10024632` | `bind`; string `Could not bind to port %d. Retrying.` |
| UDP send | `0x100248b4` | `sendto`. |
| UDP recv | `0x10024e2f` | `WSARecv`; handles `WSAECONNRESET`. |
| TCP socket | `0x10026521` | `socket`. |
| TCP bind | `0x10026628` | `bind`; string `Tcp bound to port: %d.` |
| TCP DNS | `0x10026795` | `gethostbyname`; resolves `ggpo.fightcade.com`. |
| TCP send | `0x100268fd` | `WSASend`. |
| TCP connect | `0x10026d88` | `connect`. |
| TCP nonblocking | `0x10026de9` | `ioctlsocket`. |
| TCP recv | `0x10026fea` | `WSARecv`. |
| Timing | many | `timeGetTime`; sync/quality/queue/timeout timing. |

## Served Flow

| Step | Flow |
| ---: | --- |
| 1 | Fightcade lobby sends authoritative `start` event. |
| 2 | Macade builds server-derived route and launches native FBNeo. |
| 3 | Official launcher/proxy binds emulator-facing UDP `127.0.0.1:7001` when available. |
| 4 | Official launcher/proxy binds public UDP `0.0.0.0:6006` when available, else assigned port. |
| 5 | Proxy sends UDP master registration `<quark>/7001` to `ggpo.fightcade.com:<serverPort>`. |
| 6 | Master replies `ok <quark>`; client replies ASCII `ok`. |
| 7 | Master sends 6-byte peer endpoint: IPv4 bytes plus little-endian port. |
| 8 | Peers exchange token punch payloads: `<local-token> _`, `<remote-token> _`, `<local-token> <remote-token> ok`. |
| 9 | Historical proxy loop is 10 half-second receive-before-send rounds. |
| 10 | After direct UDP succeeds, FBNeo enters `ggpo_client_connect`. |
| 11 | `ggponet.dll` opens TCP to `ggpo.fightcade.com:<serverPort>` from local TCP `6004` when possible. |
| 12 | TCP startup in current pcap: command `0`, `11`, `12`, `15 V14`, `17`, `15 C2,<player>,<delay>,<ranked>`, then recurring `17` and `18`. |
| 13 | Gameplay peer traffic remains direct UDP type `3`; sync/quality are UDP `1/2` and `4/5`. |
| 14 | TCP continues frame batches (`17`) and state snapshots (`18`). |

Current pcap facts from `/Users/jayian/Downloads/fight.pcapng`: local `192.168.1.119`, server `141.94.138.123:7001`, local UDP `6006`, local TCP `6004`. First served attempt `1785164991594-5611.1` receives peer endpoint `172.7.214.252:59733`, sends repeated token punches, then sends `useports/1785164991594-5611.1` about 11 seconds after master registration; TCP `-7` later reports `172.7.214.252:6000`. Second served attempt `1785165334663-5955.1` receives peer endpoint `196.200.146.10:6006`, completes token exchange, receives TCP `-7` endpoint `127.0.0.1:7001`, then carries direct UDP type `1/2`, `3`, and `4/5` traffic on `192.168.1.119:6006` <-> `196.200.146.10:6006` for about 125 seconds. Loopback `-7` means local proxy endpoint, not public peer.

## DLL Backend Map

The Fightcade DLL exports a GGPO-like C API, but its exported-session vtable layout is Fightcade-specific. Do not use the public MIT GGPO backend ABI or class layout as implementation authority. Use public GGPO only for algorithms and concepts where current DLL strings/control flow agree.

| Export | Static target | Meaning |
| --- | --- | --- |
| `ggpo_client_connect` | `function_10029a40` | Served Fightcade backend: TCP protocol plus UDP GGPO backend. |
| `ggpo_start_session` | `function_100287f0` | Direct UDP peer backend. |
| `ggpo_start_streaming` | `function_10028d90` | Spectator TCP backend. |
| `ggpo_start_replay` | `function_10027f60` | Local GGPOTV replay playback. |
| `ggpo_start_synctest` | `function_10027980` | Local deterministic sync-test. |
| `ggpo_idle` | vtable `+0x00` | Poll timers/UDP/TCP/events. |
| `ggpo_synchronize_input` | vtable `+0x04` | Input sync/prediction. |
| `ggpo_advance_frame` | vtable `+0x08` | End frame/drain remote input. |
| `ggpo_client_chat` | vtable `+0x0c` | TCP command `15`. |
| `ggpo_get_stats` | vtable `+0x10` | Network/sync stats. |
| `ggpo_client_set_game_event` | vtable `+0x14` | Start/avatar/score/winner/finished, command `19` trigger. |
| `ggpo_set_frame_delay` | vtable `+0x1c` | Local input frame delay before synchronized. |

## TCP Protocol

Client command frame: `u32_be length = payloadLength + 8`, `u32_be sequence`, `u32_be command`, payload. String field: `u32_be byteLength`, bytes.

| Function | Command | Payload |
| --- | ---: | --- |
| `function_100261e0` | `0` | `u32 0`, `u32 29`, `u32 1` |
| `function_10026420` | `11` | `string quark`, `u32 localPort` |
| `function_100263e0` | `12` | `string quark` |
| `function_10026380` | `15` | `string quark`, `string text` |
| `function_10025e90` | `17` | `string quark`, frame count/size, frame blocks |
| `function_10025da0` | `18` | `string quark`, compressed length, raw length, zlib state |
| `function_10025c90` | `19` | GGPOTV/replay metadata and payload |
| `function_10026340` | `20` | `string quark`, spectator registration |

Server record frame: `u32_be length`, `i32_be signedRecordCode`, payload.

| Code | Meaning |
| ---: | --- |
| positive | Ack/status. |
| `-7` | Endpoint notice: string plus two u32_be values. Loopback in direct success; public peer possible after open-port fallback. |
| `-8` | Three strings: chat/control `Command` messages. |
| `-10` | One integer: spectator-count-like state. |
| `-11` | Empty autospectate/spectator signal. |
| `-12` | Gamebuffer: raw size plus zlib blob. |
| `-13` | Stream frame batch: frame size, frame count, bytes. |

## UDP Protocol

Dispatcher: `function_10024240`.

| Type | Handler | Meaning |
| ---: | --- | --- |
| `0` | assertion | Invalid. |
| `1` | `function_100241b0` | Sync request; reply type `2`. |
| `2` | `function_10024050` | Sync reply; validates nonce. |
| `3` | `function_100233f0` | Compressed input batch. |
| `4` | `function_10023fe0` | Quality report; reply type `5`. |
| `5` | `function_10022c20` | Quality reply; updates ping/timing. |

Type `3`: `u8 type=3`, `i32_le startFrame`, `i32_le ackFrame`, `u16_le compressedBitCount`, `u8 inputSizeBytes`, bitstream. Frame delta bitstream uses changed records followed by zero marker; changed record is `1` marker, `1` new-value, `8` little-endian bit-index bits. Official receive path expects contiguous frames and discards old pending output frames strictly less than the received `ackFrame`.

## Divergence Rules

| Case | Official evidence | Macade target |
| --- | --- | --- |
| UDP `6006` bind ok | Use `6006`. | Bind `6006` first. |
| UDP `6006` bind fail | Use assigned port. | Continue when compatible. |
| Master send fail | Historical proxy sends `useports/<quark>` and starts FBNeo. | Send only on verified failure conditions. |
| Master `ok` timeout | Historical proxy retries once. | Match after current capture validation. |
| Peer endpoint timeout after `ok` | Send `useports/<quark>`. | Preserve continuation; validate failed-path captures. |
| Initial token punch ok | Direct UDP gameplay. | Prefer direct UDP. |
| Initial token punch fail | Retry via fresh UDP socket, including `6004` path. | Keep verified restricted/fixed retries. |
| All punch attempts fail | Send `useports/<quark>`, start FBNeo without direct proxy. | Continue open-port UDP mode; live validation required. |
| TCP connect fail | DLL has nonblocking retry/error handling. | Implement retry/error parity. |
| TCP `-7` loopback | Successful direct captures show `127.0.0.1:7001`. | Ignore outside open-port fallback. |
| TCP `-7` public | Failed/open-port captures can expose public endpoint. | Apply only after explicit fallback. |
| Direct route | `ggpo_start_session`, UDP only. | No Fightcade TCP command server. |
| Stream route | TCP startup command `0`, then spectator commands `20`, `12`; server `-12`, `-13`. | Keep separate from served gameplay. |
| Replay | Local playback remains unavailable; command `19` upload is implemented for completed ranked sets from DLL static evidence. | Validate against a finished-match capture before treating server acceptance as proven. |
| Synctest | Local deterministic save/load/advance. | Keep local-only. |

## Current Macade Coverage

| Area | Current status |
| --- | --- |
| Fightcade session | Login/autologin WebSocket, launcher status, channels, chat, challenges, `start`. |
| Runtime launch | Native FBNeo SDL2, embedded child process, shared-memory video, input socket. Bundled FBNeo runtime executable is named `macfbneo`. Swift launcher gates `macfbneo` startup so only one FBNeo runtime process is allowed at a time, terminating stale/orphaned existing `macfbneo` or old `fcadefbneo` processes before launching a new one. |
| Native run loop | Netplay frame/input ordering now follows Fightcade Win32 more closely by advancing frame counters before network input sync; embedded/netplay SDL adds a timer fallback when audio-buffer advancement does not produce frames, using millisecond clock units to match the SDL pacing formula. `ggpo_idle(timeout)` treats timeout as a total idle budget for active play, draining TCP nonblocking and waiting on UDP only, after live sampling showed per-transport waits could visibly stall gameplay. Embedded input bypasses SDL's per-frame event pump because Macade forwards input through its own socket and hidden-window sampling showed AppKit event work in the hot path. Early driver initialization suppresses SDL audio until after driver/ROM setup, matching Fightcade Win32 startup sequencing. |
| Routes | served/training/direct/stream parsing. Native training now accepts the Win32 `quark:training` route and uses the served backend with unranked metadata; full training Lua behavior is blocked because the trimmed SDL runtime currently builds `luaengine_stub.cpp` and does not ship the training script assets. |
| Served startup | UDP master, peer address, 10-round token punch, restricted/fixed fallback attempts, `useports` continuation, TCP `-7` open-port peer handling, TCP startup. |
| UDP gameplay | Type `3` input send/receive with ack-based pending-output pruning; type `1/2`, `4/5` probes/replies. Remote-player analog/DIP decode preserves Fightcade's per-player common-input slot advance even though common inputs are ignored for remote players. |
| Prediction/rollback | Bounded last-input prediction, saved-state history, rollback replay via `advance_frame`; rollback replay advances FBNeo's `nCurrentFrame` before synchronized input and leaves `nFramesEmulated` unchanged, matching Fightcade Win32 callback behavior. |
| TCP ongoing | Command `15` chat/control send, incoming `-8` chat/control event emission, `17` frame batches, `18` snapshots, and command `19` ranked replay upload. |
| Stats/events | `ggpo_set_frame_delay`, partial `ggpo_get_stats`, client score/winner/finished replay events, destructive rollback state logging via `log_game_state`. |
| Direct | Binds requested port and peer; uses UDP input/rollback path; needs validation. |
| Stream | Swift launch uses the lobby-advertised stream port. Official `FUN_10028d90` constructs `SpectatorBackend` and starts TCP connection setup before ROM load, but official `FUN_10028ed0` sends stream startup from spectator idle: command `0` is sent when `TcpProtocol` reports connected, then commands `20` and `12` are sent once from spectator idle. Macade now defers stream command `0` until spectator `ggpo_idle`, sends `20`/`12` after the positive command `0` response, handles `-12` gamebuffer and `-13` frame playback, logs TCP close/malformed-record cases, prevents macOS `SIGPIPE` socket crashes, uses a dedicated embedded spectator loop that polls `ggpo_idle` until the initial stream state is loaded before entering timer-driven `RunIdle` frames, and loads the initial gamebuffer once received. Live spectating now plays; native overlay state is published to the existing SwiftUI overlay header, and Swift video presentation now uses an `MTKView` with reusable RGB565/BGRA Metal textures instead of per-frame `CGImage` creation. |
| Unsupported | local replay playback, synctest, full training Lua/movie replay subsystems, complete events/stats/timesync. These remain blocked rather than faked until the local replay backend, synctest backend migration, Lua build assets, or runtime evidence are available. |

## Parity Gaps

| Priority | Gap |
| ---: | --- |
| 1 | Open-port fallback gameplay still needs live proof; native flow now follows current failed-path evidence through `useports` and public TCP `-7` endpoint handling. |
| 2 | TCP nonblocking connect/retry/disconnect parity incomplete. |
| 3 | UDP ack-window pruning, resend cadence, stale input handling, quality cadence, interruption, disconnect timing incomplete. |
| 4 | Timesync wait-frame/state behavior partial. |
| 5 | `ggpo_get_stats` incomplete. |
| 6 | `ggpo_client_set_game_event` still needs live command `19` server-acceptance validation and fuller event-field parity outside score/winner/finished upload. |
| 7 | Client callback mapping incomplete outside matchinfo, spectator count, chat, disconnect, and core peer/running events. |
| 8 | Direct still needs live validation; stream plays but needs post-fix stutter and overlay validation. |
| 9 | Replay and synctest unavailable. |

## Network Flow Parity Plan

| Phase | Goal | Exit criteria |
| ---: | --- | --- |
| 1 | Analyzer fidelity | Analyzer groups by quark/session attempt, filters unrelated traffic, decodes UDP type `3` start/ack/bitcount/input size, emits per-type timing/cadence, reports `useports` timing and TCP startup sequence. |
| 2 | Served happy path | Match current successful served capture: UDP master, token exchange, TCP `0/11/12/15 V14/17/15 C2`, TCP `-7` loopback ignored, direct UDP `1/2/3/4/5` on peer `6006`. |
| 3 | Served fallback path | Match current failed/direct-fallback evidence: peer endpoint `172.7.214.252:59733`, broad token punching, `useports` after punch failure, TCP `-7` public endpoint handling only in open-port mode. |
| 4 | TCP state parity | Replace blocking one-shot TCP assumptions with evidence-backed connect, retry, close, and disconnect behavior; preserve command sequencing and signed server-record handling. |
| 5 | UDP reliability parity | Match official UDP resend cadence, ack pruning, stale/missing input behavior, quality/sync cadence, interruption notification, and disconnect timeout under artificial loss/delay. |
| 6 | Timesync parity | Port public GGPO timesync wait-frame logic where Fightcade DLL behavior agrees; validate against captures with asymmetric delay. |
| 7 | Stats and callbacks | Populate `ggpo_get_stats` and client/GGPO event callbacks to match official overlay/perfmon behavior. |
| 8 | Game events and command `19` | Validate static-evidence score/winner/finished replay upload against a completed ranked capture, then refine any payload or timing differences. |
| 9 | Direct and stream validation | Prove direct route uses UDP only; refine stream playback pacing and spectator overlay after live `20/12` plus `-12/-13` playback validation. |

## Research Findings For Next Implementation

| Area | Current evidence | Implementation implication |
| --- | --- | --- |
| Analyzer | Current rerun decodes 11284 payload packets, 2122 flows, 2356 protocol records, and now reports per-session UDP input windows, ack progression, gap/overlap/repeat/malformed counts, per-kind UDP timing, and TCP command cadence. | Use these focused summaries as Phase A acceptance data and extend them for controlled loss/delay captures. |
| Current pcap attempt 1 | `1785164991594-5611.1` gets peer `172.7.214.252:59733`, sends many token probes, sends `useports` about 11 seconds after registration, then TCP `-7` reports `172.7.214.252:6000`. | Treat as partial failed-path evidence, not proof that open-port mode reaches gameplay. |
| Current pcap attempt 2 | `1785165334663-5955.1` completes token exchange with `196.200.146.10:6006`, then carries 6021 UDP packets for about 131 seconds. | This is the primary served happy-path acceptance fixture. |
| Spectator pcap | `/Users/jayian/Downloads/spectate.pcapng` contains official spectator sessions from local `172.20.10.3:6004` to `141.94.138.123:7000`; stream id example `1785362280459-6720.2`. Official spectator startup sends command `0`, receives a positive ack, sends commands `20` and `12`, then receives large `-12` gamebuffer and recurring `-13` frame batches. Paired captures `/Users/jayian/Downloads/fightcade.pcapng` and `/Users/jayian/Downloads/macade.pcapng` for stream `1785380864870-1970.2` on TCP `7001` show identical Macade/Fightcade client command records and both receive server records `1`, `2`, `3`, `-11`, `-10`, `-12`, and recurring `-13`. | The official capture proves a stream advertised on `7000` uses remote TCP `7000`; live Macade probing on stream `1785379025356-5388.2` proved a stream advertised on `7001` must use remote TCP `7001`. Use the lobby-advertised stream port. The paired captures show Macade's remaining spectate issue is after successful registration, not command payload or port selection. |
| UDP type mix | Successful peer flow: type `3` count 5520, type `4` count 241, type `5` count 234, type `1` count 10, type `2` count 10, token packets 6. Median type `3` spacing is about 20-22 ms per direction; successful type `3` windows show no gaps or malformed packets and monotonic ack progression in both directions. Quality report/reply cadence is about 1000 ms. | Use these counts/cadences as initial smoke thresholds, not exact constants. |
| Native runtime | Current pcap decodes one startup command `17` frame batch before `C2`; native runtime and Swift scaffolding send that order. Native served fallback sends `useports/<quark>` after verified punch failure and applies public TCP `-7` endpoint notices only while in open-port fallback mode. SDL netplay run-loop parity was tightened after lagging matches reached `RunMessageLoop`: frame counters now advance before network input sync, rollback replay advances `nCurrentFrame` before synchronized input without increasing `nFramesEmulated`, embedded/netplay can fall back to timer-driven frames if SDL audio does not advance, embedded spectator playback bypasses SDL audio-driven frame filling, uses timer-driven video pacing, and commits timer-generated audio segments into SDL's playback ring without letting the audio fill callback advance frames, the fallback clock is milliseconds rather than microseconds, active-play `ggpo_idle` no longer blocks once per transport, embedded input skips SDL event pumping, and `DrvInit` is restored to the public Fightcade SDL structure without Macade network setup or net speed tweaks. Native runtime now accepts `quark:training`, sends real command `15` chat/control records, emits incoming `-8` chat events, implements the rollback `log_game_state` diagnostic callback, loads detectors after savestate setup, restores stream flags after driver init, sends TCP command frames as official-style split writes (`u32_be length`, then sequence/command/payload), emits Swift spectator routes with the lobby-advertised stream port, defers stream startup command `0` to spectator idle instead of construction, sends stream `20`/`12` once after command `0` response, drives embedded spectator sessions through a dedicated loop that polls `ggpo_idle` until TCP `-12` is loaded before `RunIdle` frame execution, publishes native overlay state into the SwiftUI shared-memory overlay header, suppresses macOS `SIGPIPE` on TCP sockets, and sends command `19` GGPOTV replay uploads for completed ranked FT sets. Swift video presentation now uses `MTKView`, uploads raw RGB565 frame bytes into a reusable Metal texture, and draws with nearest sampling after repeated live tests showed persistent 4-5 second stutter with `CGImage`/CoreGraphics-based presentation despite a roughly 60 FPS native frame index. Latest verified bundled runtime SHA-256 is `fe92bf71f55f63279ba99815f4dda5f7d567c4a5a553e35d8e5180291f34cf81`. | Keep tests/tools aligned with analyzer output before relying on them for parity; live-validate open-port fallback gameplay, chat/control behavior, training route startup, command `19` acceptance, direct route, stream pacing, and spectator overlay before closing the gap. |
| Runtime diagnostics | Native runtime now logs a bounded close-time session summary with UDP send/resend/receive, sync, quality, TCP record/batch/snapshot, prediction, rollback, saved-state, byte, disconnect, and fatal-desync counters. | Correlate native summaries with analyzer output during live validation and loss/delay tests. |
| Runtime ownership split | Current direct source keeps exported `ggpo_*` shims, client event emission, rollback helpers, and API lifecycle in `src/macade/macade_ggpo_client.cpp`; `src/macade/macade_ggpo_handshake.cpp` owns served rendezvous/TCP startup and is 500 lines. The abandoned `macade_ggpo_api.cpp`/`macade_ggpo_tcp.cpp` split is not present in the build. | Perform behavior-preserving splits before importing public GGPO rollback/input code or adding handshake behavior. |
| Rollback harness | not currently tracked | Recreate the deterministic frame-delay, prediction, mismatch, and rollback harness before Phase C rollback/input migration. |
| TCP implementation | Current native `ConnectTCP` is blocking and fails immediately on connect error; DLL has socket bind, nonblocking connect, WSA event handling, close path, and disconnect event logging. | TCP retry/error parity needs deeper static/dynamic evidence before implementation. |
| UDP implementation | Current native UDP implements type `1/2/3/4/5`, prunes pending local UDP output frames strictly less than incoming type `3` ack frames, resends every 200 ms, sends quality every 1000 ms, sends sync every 2000 ms, interrupts at 5000 ms, and disconnects at 30000 ms. Served rendezvous uses 10 half-second punch rounds, `±512` port scan, restricted/fixed `6004` retries, and no LAN-broadcast-only path. Public GGPO uses similar running retry, quality, and notify/shutdown constants, but Fightcade packets are modified. | Validate cadence constants against Fightcade DLL captures rather than blindly porting public GGPO. |
| Timesync | Current runtime records frame advantage in stats but does not delay frames using public GGPO `TimeSync::recommend_frame_wait_duration`. | Port wait-frame logic only after measuring Fightcade behavior under asymmetric delay. |
| Stats/events | Current `ggpo_get_stats` is partial. `ggpo_client_set_game_event` now handles `STARTING`, player avatar strings, score updates, winner storage, and `FINISHED` command `19` upload. Replay upload builds a `GGPOTV` metadata header plus zlib-compressed initial state and input payload per DLL static evidence. | Need completed ranked-match validation to confirm command `19` timing, metadata, server acceptance, and any missing event fields. |

## Unknown Evidence Collection

| Gap | Why current research is insufficient | How to obtain evidence |
| --- | --- | --- |
| Open-port fallback gameplay | Current pcap shows `useports` and TCP public `-7`, but no confirmed gameplay on that attempt. | Capture a session where direct punch fails but match still reaches gameplay; collect both sides if possible. |
| TCP connect/retry/disconnect | Current pcap is mostly successful; static RetDec shows event cases but not enough timing and retry policy. | Run official Windows Fightcade with API/socket tracing while blocking/unblocking `ggpo.fightcade.com:<port>`. |
| UDP resend/ack exactness | Capture analyzer does not yet decode contiguous frame windows, retransmits, or ack pruning. | Enhance analyzer, then run official sessions with controlled loss/delay. |
| Timesync wait behavior | Packet capture alone does not show emulator frame sleeps or local input-idle decisions. | Combine pcap with official overlay/perfmon video or instrumented DLL call tracing. |
| `ggpo_get_stats` fields | Stats are internal API outputs, not fully visible on wire. | Hook or wrap `ggpo_get_stats` in official FBNeo/Wine and log returned struct fields per second. |
| Game events/command `19` | Static evidence is implemented, but current pcap does not include command `19` and server acceptance is unproven. | Capture a completed ranked set and inspect TCP command `19`, backend response, and any replay files. |
| Direct route | No current direct `quark:direct` capture. | Launch official direct mode in a controlled two-client setup and capture UDP only. |
| Stream route | Official spectator capture proves command/record order. Macade live probing showed command `0` ack and `20/12` registration on the lobby-advertised port, while forcing `7000` for a `7001` stream only produced the command `0` ack. | Retest Macade spectator launch against a live stream with log checks for the advertised remote port, command `0` ack, delayed `20/12`, server `-12`, and recurring `-13`. |

## User Evidence Collection Plan

The user's role is to collect official Fightcade evidence that cannot be produced from Macade source, the current pcap, or static DLL analysis.

1. Capture open-port fallback evidence: run two official Fightcade clients where direct UDP is likely to fail, capture both sides if possible, start a served match, wait until gameplay starts or failure is final, and save pcap plus server IP, peer IPs, match id, player side, delay, and ranked flag. Goal: prove what happens after `useports`.
2. Capture TCP retry/disconnect behavior: run official Fightcade in Windows, start Wireshark or `tshark`, temporarily block `ggpo.fightcade.com:<serverPort>` TCP with Windows firewall, start a match, unblock TCP, and save pcap plus timing notes. Goal: learn official connect retry, timeout, and disconnect behavior.
3. Capture UDP loss/delay behavior: use clumsy on Windows or router `tc netem`, test `0%`, `2%`, and `5%` packet loss, test asymmetric delay such as one side +80 ms, and save pcaps for each scenario. Goal: learn resend, ack, quality, sync, interruption, and timeout behavior.
4. Capture completed match behavior: play a full ranked or FT set in official Fightcade, let post-match flow finish completely, and save pcap. Goal: validate command `19`, winner/score/final-state behavior, and replay-upload acceptance.
5. Capture direct mode: launch official direct mode between two controlled clients and capture both sides. Goal: verify direct route uses UDP only and no Fightcade TCP command server.
6. Capture additional spectator mode if stream behavior diverges: join an active match as spectator and capture from join through at least 60 seconds. Goal: compare against `/Users/jayian/Downloads/spectate.pcapng` for command `0`, command `20`, command `12`, server `-12`, server `-13`, and spectator-count behavior.
7. Provide artifacts: `.pcapng` files, short notes for each capture, Fightcade version, game id, which machine was player 1/player 2/spectator, and any firewall/loss/delay settings used.

## Public GGPO Boundary

Exact Phase 3 boundary is `docs/ggpo-public-port-boundary.md`. Port from MIT public GGPO: `bitvector.*`, `game_input.*`, `input_queue.*`, `sync.*`, and optionally small container helpers. Adapt only: `timesync.*`, selected `network/udp_proto.*` algorithms, and selected `backends/p2p.*` state-machine concepts. Reference only: `src/include/ggponet.h`, public `udp_msg.h`, synctest/spectator concepts, `poll.*`, `types.h`, and `log.*`. Do not port public `main.cpp`, `backends/backend.h`, `network/udp.*`, platform shims, zlib headers, sample apps, docs, or build scaffolding.

Keep Fightcade-specific protocol separate: quark parsing, served TCP startup, UDP rendezvous, commands `11/12/15/17/18/19/20`, signed server records, stream/replay/event behavior, exported-session ABI, and diagnostics.

Detailed source-recovery and integration phases are tracked in `docs/ggponet-source-recovery-plan.md`. Phase 1 verified the current DLL hash, public GGPO checkout, RetDec availability, missing PDB status, and public-GGPO-to-DLL correlation anchors. Phase 2 completed the reviewed DLL address map. Phase 3 completed the exact public-GGPO port boundary.

## Capture Requirements

Scenarios: five-minute served success, failed NAT reaching `useports/<quark>`, clean disconnect, spectator `quark:stream`, finished ranked/replay upload artifacts. Sidecar fields: scenario, Fightcade version, FBNeo version, game, game id, redacted quark id, server port, player side, delay, ranked flag, public IPs, accept/open/first-input/disconnect times, notes.

```sh
Restore or recreate capture-analysis tooling before processing new packet captures. Prior analyzer usage was:

```sh
analyze-ggponet-capture.py capture.pcapng \
  --server-ip <ggpo-server-ip> \
  --peer-ip <peer-public-ip> \
  --out-dir <capture-summary-output-dir>
```

Mapping checklist: command `17/18` cadence, UDP type `3` contiguity/bitstream, UDP sync/quality/retransmission, TCP matchinfo/chat/spectator/disconnect/blob records.

## Runtime Boundaries

Detailed Phase 4 runtime abstraction design is `docs/ggpo-runtime-abstraction-design.md`. Runtime migration should split the current native GGPO state into `MacadeGGPOApi`, `MacadeSession`, `MacadeCallbacks`, `MacadeRollbackCore`, `MacadeFightcadeUDP`, `MacadeServedRendezvous`, `MacadeFightcadeTCP`, `MacadeStreamRuntime`, and `MacadeDiagnostics` before porting public-GGPO rollback/input code.

Detailed parity implementation order is `docs/fightcade-parity-improvement-plan.md`. Start with analyzer/runtime diagnostics and behavior-preserving ownership splits, then migrate rollback/input queues, then pursue UDP reliability and TCP state parity, leaving open-port fallback, timesync waits, command `19` live validation, direct, stream, replay playback, and synctest evidence-gated.

Key ownership rule: UDP/TCP modules exchange decoded frame inputs and typed events with `MacadeSession`; they must not own saved states or rollback decisions. `MacadeCallbacks` should be the only module calling FBNeo GGPO callbacks directly.

| Layer | Responsibilities |
| --- | --- |
| Swift app | Fightcade WebSocket, start/challenge parsing, launch route construction, runtime seeding, process launch, user-readable diagnostics. |
| Native FBNeo | Quark parse, GGPO callbacks, served/direct/stream handshakes, input/state/chat exchange, frame loop, embedded video/input bridge. |
| SwiftUI views | Render UI only; no protocol, networking, launching, or persistence logic. |

## Verification Gates

| Gate | Requirement |
| --- | --- |
| Runtime build | `cd Sources/FightcadeFBNeo && make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl` verifies the native FBNeo source. Recreate install automation before changing runtime sources that require a refreshed bundled app resource binary. |
| App build | `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build`. |
| Offline | Local FBNeo ROM launch still works. |
| Served live | Starts from server `start`, both inputs affect gameplay, stable for five minutes. |
| Loss/delay | Artificial loss/delay triggers bounded prediction/rollback. |
| Stats | Non-zero queue/throughput values in real match. |
| Failures | Startup, missing ROM, NAT failure, timeout, disconnect, emulator exit are user-readable. |
| Logs | Bounded, redacted by default, sufficient for field debugging. |

## Diagnostics Contract

Log by default: redacted start event, derived route, runtime/executable path, emulator command, master host/port, local UDP/TCP ports, match id/player side for local debugging, NAT stage, peer endpoint source, TCP command/server record codes, UDP packet family counts, rollback/prediction summary, emulator pid/exit, disconnect/timeout reason.

Do not log by default: password, session cookie, launcher token, encrypted location, chat bodies unless explicit diagnostic toggle is enabled.

## Current Next Work

1. Start Phase B behavior-preserving ownership splits in the direct vendored source: move exported `ggpo_*` shims, callback/event helpers, served rendezvous/TCP code, and UDP ownership into focused files without changing packet bytes.
2. Migrate rollback/input queues from public GGPO only after those ownership boundaries are split and the rollback harness remains green.
3. Validate UDP reliability with controlled official loss/delay captures before changing resend, interruption, or timesync behavior.
4. Implement TCP connect/retry/disconnect parity after static review and official retry/disconnect evidence.
5. Keep open-port fallback gameplay, `ggpo_get_stats`, command `19` live validation, direct, stream, replay playback, and synctest evidence-gated.
