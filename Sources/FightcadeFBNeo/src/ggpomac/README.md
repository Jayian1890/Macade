# ggpomac

`ggpomac` is Macade's native macOS replacement package for Fightcade's
`ggponet.dll` export surface.

The package goal is API parity with the DLL exports used by Fightcade FBNeo,
while keeping the implementation native to macOS. Consumers should include
`ggpomac.h` instead of reaching into Macade-specific GGPO implementation
headers.

## Export Surface

The native surface intentionally keeps the original exported symbol names:

| Export | Status |
| --- | --- |
| `ggpo_start_session` | Implemented by native Macade GGPO runtime |
| `ggpo_client_connect` | Implemented by native Macade GGPO runtime |
| `ggpo_start_streaming` | Implemented by native Macade GGPO runtime |
| `ggpo_start_replay` | Declared; implementation currently returns `NULL` |
| `ggpo_start_synctest` | Declared; implementation currently returns `NULL` |
| `ggpo_close_session` | Implemented by native Macade GGPO runtime |
| `ggpo_idle` | Implemented by native Macade GGPO runtime |
| `ggpo_synchronize_input` | Implemented by native Macade GGPO runtime |
| `ggpo_advance_frame` | Implemented by native Macade GGPO runtime |
| `ggpo_get_stats` | Implemented by native Macade GGPO runtime |
| `ggpo_set_frame_delay` | Implemented by native Macade GGPO runtime |
| `ggpo_client_chat` | Implemented by native Macade GGPO runtime |
| `ggpo_client_set_game_event` | Implemented by native Macade GGPO runtime |
| `ggpo_log` | Implemented by native Macade GGPO runtime |
| `ggpo_logv` | Implemented by native Macade GGPO runtime |

## Source Layout

| File | Role |
| --- | --- |
| `ggpomac.h` | Public DLL-compatible API surface. |
| `ggpomac_internal.h` | Native session state and internal runtime contracts. |
| `ggpomac_api.cpp` | Exported `ggpo_*` and Fightcade client API functions. |
| `ggpomac_runtime.cpp` | Shared session state, event bridge, logging, rollback, and input storage helpers. |

The transport, chat, replay upload, stream, and emulator integration pieces are
still implemented by the existing FBNeo integration files under `src/macade`.
Those files depend on `ggpomac_internal.h`; they no longer own the public
`ggpo_*` API implementation.
