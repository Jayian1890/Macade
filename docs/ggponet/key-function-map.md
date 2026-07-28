# Key Function Map

Purpose: compact guide to the generated per-function decompiler output. The linked Markdown files contain the detailed C-like pseudocode, call tables, string references, data references, and disassembly.

## ggponet.dll Exports

| Role | Address | Document |
| --- | ---: | --- |
| Close session wrapper | `10021b30` | [`ggponet/functions/10021b30_ggpo_close_session.md`](ggponet/functions/10021b30_ggpo_close_session.md) |
| Stats wrapper | `10021b50` | [`ggponet/functions/10021b50_ggpo_get_stats.md`](ggponet/functions/10021b50_ggpo_get_stats.md) |
| Chat/control wrapper | `10021b80` | [`ggponet/functions/10021b80_ggpo_client_chat.md`](ggponet/functions/10021b80_ggpo_client_chat.md) |
| Advance-frame wrapper | `10021bb0` | [`ggponet/functions/10021bb0_ggpo_advance_frame.md`](ggponet/functions/10021bb0_ggpo_advance_frame.md) |
| Synchronize-input wrapper | `10021be0` | [`ggponet/functions/10021be0_ggpo_synchronize_input.md`](ggponet/functions/10021be0_ggpo_synchronize_input.md) |
| Idle/poll wrapper | `10021c20` | [`ggponet/functions/10021c20_ggpo_idle.md`](ggponet/functions/10021c20_ggpo_idle.md) |
| Frame-delay wrapper | `10021c50` | [`ggponet/functions/10021c50_ggpo_set_frame_delay.md`](ggponet/functions/10021c50_ggpo_set_frame_delay.md) |
| Fightcade game-event wrapper | `10021c80` | [`ggponet/functions/10021c80_ggpo_client_set_game_event.md`](ggponet/functions/10021c80_ggpo_client_set_game_event.md) |
| Replay constructor export | `10021d10` | [`ggponet/functions/10021d10_ggpo_start_replay.md`](ggponet/functions/10021d10_ggpo_start_replay.md) |
| Stream/spectator constructor export | `10021d60` | [`ggponet/functions/10021d60_ggpo_start_streaming.md`](ggponet/functions/10021d60_ggpo_start_streaming.md) |
| Synctest constructor export | `10021db0` | [`ggponet/functions/10021db0_ggpo_start_synctest.md`](ggponet/functions/10021db0_ggpo_start_synctest.md) |
| Served Fightcade constructor export | `10021e00` | [`ggponet/functions/10021e00_ggpo_client_connect.md`](ggponet/functions/10021e00_ggpo_client_connect.md) |
| Direct P2P constructor export | `10021e50` | [`ggponet/functions/10021e50_ggpo_start_session.md`](ggponet/functions/10021e50_ggpo_start_session.md) |

## ggponet.dll Backend And Protocol Bodies

| Role | Address | Document |
| --- | ---: | --- |
| Served Fightcade backend constructor | `10029a40` | [`ggponet/functions/10029a40_FUN_10029a40.md`](ggponet/functions/10029a40_FUN_10029a40.md) |
| Direct P2P backend constructor | `100287f0` | [`ggponet/functions/100287f0_FUN_100287f0.md`](ggponet/functions/100287f0_FUN_100287f0.md) |
| Stream/spectator backend constructor | `10028d90` | [`ggponet/functions/10028d90_FUN_10028d90.md`](ggponet/functions/10028d90_FUN_10028d90.md) |
| Replay backend constructor | `10027f60` | [`ggponet/functions/10027f60_FUN_10027f60.md`](ggponet/functions/10027f60_FUN_10027f60.md) |
| Synctest backend constructor | `10027980` | [`ggponet/functions/10027980_FUN_10027980.md`](ggponet/functions/10027980_FUN_10027980.md) |
| UDP dispatcher | `10024240` | [`ggponet/functions/10024240_FUN_10024240.md`](ggponet/functions/10024240_FUN_10024240.md) |
| UDP input packet handler | `100233f0` | [`ggponet/functions/100233f0_FUN_100233f0.md`](ggponet/functions/100233f0_FUN_100233f0.md) |
| UDP quality-reply handler | `10022c20` | [`ggponet/functions/10022c20_FUN_10022c20.md`](ggponet/functions/10022c20_FUN_10022c20.md) |
| UDP quality-report handler | `10023fe0` | [`ggponet/functions/10023fe0_FUN_10023fe0.md`](ggponet/functions/10023fe0_FUN_10023fe0.md) |
| UDP sync-reply handler | `10024050` | [`ggponet/functions/10024050_FUN_10024050.md`](ggponet/functions/10024050_FUN_10024050.md) |
| UDP sync-request handler | `100241b0` | [`ggponet/functions/100241b0_FUN_100241b0.md`](ggponet/functions/100241b0_FUN_100241b0.md) |
| TCP command 17 frame batch | `10025e90` | [`ggponet/functions/10025e90_FUN_10025e90.md`](ggponet/functions/10025e90_FUN_10025e90.md) |
| TCP command 18 state snapshot | `10025da0` | [`ggponet/functions/10025da0_FUN_10025da0.md`](ggponet/functions/10025da0_FUN_10025da0.md) |
| TCP command 19 game event | `10025c90` | [`ggponet/functions/10025c90_FUN_10025c90.md`](ggponet/functions/10025c90_FUN_10025c90.md) |
| TCP command 0 startup | `100261e0` | [`ggponet/functions/100261e0_FUN_100261e0.md`](ggponet/functions/100261e0_FUN_100261e0.md) |
| TCP command 20 spectator register | `10026340` | [`ggponet/functions/10026340_FUN_10026340.md`](ggponet/functions/10026340_FUN_10026340.md) |
| TCP command 15 text/control | `10026380` | [`ggponet/functions/10026380_FUN_10026380.md`](ggponet/functions/10026380_FUN_10026380.md) |
| TCP command 12 quark register | `100263e0` | [`ggponet/functions/100263e0_FUN_100263e0.md`](ggponet/functions/100263e0_FUN_100263e0.md) |
| TCP command 11 port register | `10026420` | [`ggponet/functions/10026420_FUN_10026420.md`](ggponet/functions/10026420_FUN_10026420.md) |
| TCP setup/socket bind | `100264e0` | [`ggponet/functions/100264e0_FUN_100264e0.md`](ggponet/functions/100264e0_FUN_100264e0.md) |
| TCP nonblocking connect/retry | `10026d40` | [`ggponet/functions/10026d40_FUN_10026d40.md`](ggponet/functions/10026d40_FUN_10026d40.md) |
| TCP receive path | `10026f60` | [`ggponet/functions/10026f60_FUN_10026f60.md`](ggponet/functions/10026f60_FUN_10026f60.md) |

## ggpofba-ng.exe GGPO Slice

| Role | Address | Document |
| --- | ---: | --- |
| Command-line/game launch dispatcher; detects `quark:` and enters GGPO path | `00456d80` | [`ggpofba-ng/functions/00456d80_FUN_00456d80.md`](ggpofba-ng/functions/00456d80_FUN_00456d80.md) |
| Route parser; maps `quark:served/direct/synctest/stream/replay` to `ggponet.dll` exports | `0062dc50` | [`ggpofba-ng/functions/0062dc50_FUN_0062dc50.md`](ggpofba-ng/functions/0062dc50_FUN_0062dc50.md) |
| GGPO save-state filename helper: `savestates\%s_ggpo.fs` | `0062d6c0` | [`ggpofba-ng/functions/0062d6c0_FUN_0062d6c0.md`](ggpofba-ng/functions/0062d6c0_FUN_0062d6c0.md) |
| Emulator log bridge to `ggpo_logv` | `0062ded0` | [`ggpofba-ng/functions/0062ded0_FUN_0062ded0.md`](ggpofba-ng/functions/0062ded0_FUN_0062ded0.md) |
| End-of-frame bridge to `ggpo_advance_frame` | `0062df40` | [`ggpofba-ng/functions/0062df40_FUN_0062df40.md`](ggpofba-ng/functions/0062df40_FUN_0062df40.md) |
| Main input sync bridge to `ggpo_synchronize_input` | `004722f0` | [`ggpofba-ng/functions/004722f0_FUN_004722f0.md`](ggpofba-ng/functions/004722f0_FUN_004722f0.md) |
| Idle/poll bridge to `ggpo_idle` | `0055fb20` | [`ggpofba-ng/functions/0055fb20_FUN_0055fb20.md`](ggpofba-ng/functions/0055fb20_FUN_0055fb20.md) |
| Chat/control bridge to `ggpo_client_chat` | `0045d960` | [`ggpofba-ng/functions/0045d960_FUN_0045d960.md`](ggpofba-ng/functions/0045d960_FUN_0045d960.md) |
| Network stats bridge to `ggpo_get_stats` | `0062ebb0` | [`ggpofba-ng/functions/0062ebb0_FUN_0062ebb0.md`](ggpofba-ng/functions/0062ebb0_FUN_0062ebb0.md) |
| Game-event wrapper group | `0062e260` | [`ggpofba-ng/functions/0062e260_FUN_0062e260.md`](ggpofba-ng/functions/0062e260_FUN_0062e260.md) |
| Game-event wrapper group | `0062e500` | [`ggpofba-ng/functions/0062e500_FUN_0062e500.md`](ggpofba-ng/functions/0062e500_FUN_0062e500.md) |
| Game-event wrapper group | `0062ee30` | [`ggpofba-ng/functions/0062ee30_FUN_0062ee30.md`](ggpofba-ng/functions/0062ee30_FUN_0062ee30.md) |
| Game-event wrapper group | `0062f0d0` | [`ggpofba-ng/functions/0062f0d0_FUN_0062f0d0.md`](ggpofba-ng/functions/0062f0d0_FUN_0062f0d0.md) |

## kailleraclient.dll Boundary

| Role | Address | Document |
| --- | ---: | --- |
| Legacy Kaillera version export | `10005800` | [`kailleraclient/functions/10005800_kailleraGetVersion.md`](kailleraclient/functions/10005800_kailleraGetVersion.md) |
| Legacy Kaillera init export | `10005830` | [`kailleraclient/functions/10005830_kailleraInit.md`](kailleraclient/functions/10005830_kailleraInit.md) |
| Legacy Kaillera shutdown export | `10005ba0` | [`kailleraclient/functions/10005ba0_kailleraShutdown.md`](kailleraclient/functions/10005ba0_kailleraShutdown.md) |
| Legacy Kaillera info registration export | `10005be0` | [`kailleraclient/functions/10005be0_kailleraSetInfos.md`](kailleraclient/functions/10005be0_kailleraSetInfos.md) |
| Legacy Kaillera server-dialog export | `10005c80` | [`kailleraclient/functions/10005c80_kailleraSelectServerDialog.md`](kailleraclient/functions/10005c80_kailleraSelectServerDialog.md) |
| Legacy Kaillera play-value export | `10005ca0` | [`kailleraclient/functions/10005ca0_kailleraModifyPlayValues.md`](kailleraclient/functions/10005ca0_kailleraModifyPlayValues.md) |
| Legacy Kaillera chat export | `10005cc0` | [`kailleraclient/functions/10005cc0_kailleraChatSend.md`](kailleraclient/functions/10005cc0_kailleraChatSend.md) |
| Legacy Kaillera end-game export | `10005cd0` | [`kailleraclient/functions/10005cd0_kailleraEndGame.md`](kailleraclient/functions/10005cd0_kailleraEndGame.md) |
| Legacy nonblocking connection path | `10002c80` | [`kailleraclient/functions/10002c80_FUN_10002c80.md`](kailleraclient/functions/10002c80_FUN_10002c80.md) |
| Legacy server-list fetch path; references `kaillera.com/raw_server_list2.php` | `1000ab90` | [`kailleraclient/functions/1000ab90_FUN_1000ab90.md`](kailleraclient/functions/1000ab90_FUN_1000ab90.md) |
