# ggpomac

`ggpomac` is Macade's native macOS replacement boundary for Fightcade's
`ggponet.dll` export surface.

The package goal is API parity with the Windows DLL exports used by
Fightcade FBNeo, while keeping the implementation native to macOS. Consumers
should include `ggpomac.h` instead of reaching into Macade-specific GGPO
implementation headers.

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

## Implementation Notes

The current implementation lives in `src/macade/macade_ggpo_*.cpp` because it
is still tightly coupled to the embedded FBNeo runtime, savestates, overlays,
and launch flow. `ggpomac.h` is the public package facade; implementation can
move behind it incrementally without changing callers.

Use `docs/ggponet/` as the authority for matching Fightcade-specific behavior.
