# ggponet.dll Binary Source

## Verified Artifact

The active `ggponet.dll` source artifact is the FBNeo copy from the official Fightcade Windows package.

| Field | Value |
| --- | --- |
| Download endpoint | `https://www.fightcade.com/download/windows` |
| Redirect target observed | `https://web.fightcade.com/download/Fightcade-win32-latest.exe` |
| Installer SHA256 | `81db623ee85d65cdaf0ad9e7c65e583ed3a29150c47d940e389ff634dde1af78` |
| Extracted path | `emulator/fbneo/ggponet.dll` |
| Restored local path | `.reverse-engineering/ggponet/ggponet.dll` |
| DLL SHA256 | `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8` |
| DLL MD5 | `f88dc44447fd1088d732739426710dd5` |
| DLL format | `PE32 executable (DLL) (GUI) Intel 80386, for MS Windows` |
| DLL size | `284160` bytes |

The same DLL hash is present in the official package at:

| Package path | SHA256 |
| --- | --- |
| `emulator/ggpofba/ggponet.dll` | `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8` |
| `emulator/fbneo/ggponet.dll` | `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8` |
| `emulator/snes9x/ggponet.dll` | `a7721eafb66fed1c0383b4dbc62ad61e9837acab9762586fe9fe39adbe1615a8` |

## Rejected Artifact

The public DLL-files.com mirror provides a different `ggponet.dll` and must not be used for Fightcade parity.

| Field | Value |
| --- | --- |
| Mirror MD5 | `2979a27626a751851a971a3ce70b0055` |
| Mirror SHA256 | `bdc1a8530d97e754e250e4ba32b81f38974f2fa003696ad7558b32c43415e0bf` |
| Reason rejected | SHA256 does not match the Fightcade package DLL or this corpus |

## PE Section Mapping

| Section | VA | Raw Offset | Raw Size |
| --- | ---: | ---: | ---: |
| `.text` | `0x10001000` | `0x00000400` | `0x0002ca00` |
| `.rdata` | `0x1002e000` | `0x0002ce00` | `0x00007a00` |
| `.data` | `0x10036000` | `0x00034800` | `0x00002c00` |

## Native GGPO Vtable Pointers

These rows are raw little-endian function/data pointer entries dumped from `.rdata` in the verified DLL. Non-pointer string/data rows are intentionally omitted.

| Vtable | Slot VA | Target |
| --- | ---: | ---: |
| `GGPOBackend::vftable` | `0x100330f4` | `0x10029fb0` |
| `GGPOBackend::vftable` | `0x100330f8` | `0x10028b30` |
| `GGPOBackend::vftable` | `0x100330fc` | `0x10028710` |
| `GGPOBackend::vftable` | `0x10033100` | `0x10029f70` |
| `GGPOBackend::vftable` | `0x10033104` | `0x100285d0` |
| `GGPOBackend::vftable` | `0x10033108` | `0x10029800` |
| `GGPOBackend::vftable` | `0x1003310c` | `0x10001380` |
| `GGPOBackend::vftable` | `0x10033110` | `0x10028590` |
| `GGPOBackend::vftable` | `0x10033114` | `0x10001420` |
| `GGPOBackend::vftable` | `0x10033118` | `0x100295e0` |
| `GGPOBackend::vftable` | `0x1003311c` | `0x10028960` |
| `GGPOBackend::vftable` | `0x10033120` | `0x100335d8` |
| `GGPOBackend::vftable` | `0x10033124` | `0x10001370` |
| `GGPOBackend::vftable` | `0x10033128` | `0x10001370` |
| `GGPOBackend::vftable` | `0x1003312c` | `0x10002880` |
| `GGPOBackend::vftable` | `0x10033130` | `0x10001370` |
| `GGPOBackend::vftable` | `0x10033134` | `0x10033858` |
| `IPollSink::vftable` | `0x10033138` | `0x10001370` |
| `IPollSink::vftable` | `0x1003313c` | `0x10001370` |
| `IPollSink::vftable` | `0x10033140` | `0x10002880` |
| `IPollSink::vftable` | `0x10033144` | `0x10001370` |
| `IPollSink::vftable` | `0x10033148` | `0x10033844` |
| `GGPOSession::vftable` | `0x1003314c` | `0x10001370` |
| `GGPOSession::vftable` | `0x10033150` | `0x10011951` |
| `GGPOSession::vftable` | `0x10033154` | `0x10002870` |
| `GGPOSession::vftable` | `0x10033158` | `0x10001370` |
| `GGPOSession::vftable` | `0x1003315c` | `0x10001370` |
| `GGPOSession::vftable` | `0x10033160` | `0x10002880` |
| `GGPOSession::vftable` | `0x10033164` | `0x10001380` |
| `GGPOSession::vftable` | `0x10033168` | `0x10001370` |
| `GGPOSession::vftable` | `0x1003316c` | `0x10033830` |
| `Peer2PeerBackend::vftable` | `0x10033170` | `0x10028a30` |
| `Peer2PeerBackend::vftable` | `0x10033174` | `0x10028b30` |
| `Peer2PeerBackend::vftable` | `0x10033178` | `0x10028710` |
| `Peer2PeerBackend::vftable` | `0x1003317c` | `0x10001370` |
| `Peer2PeerBackend::vftable` | `0x10033180` | `0x100285d0` |
| `Peer2PeerBackend::vftable` | `0x10033184` | `0x10002880` |
| `Peer2PeerBackend::vftable` | `0x10033188` | `0x10001380` |
| `Peer2PeerBackend::vftable` | `0x1003318c` | `0x10028590` |
| `Peer2PeerBackend::vftable` | `0x10033190` | `0x10002890` |
| `Peer2PeerBackend::vftable` | `0x10033194` | `0x100013e0` |
| `Peer2PeerBackend::vftable` | `0x10033198` | `0x10028960` |
| `Peer2PeerBackend::vftable` | `0x1003319c` | `0x1003381c` |
| `Peer2PeerBackend::vftable` | `0x100331a0` | `0x10001370` |
| `Peer2PeerBackend::vftable` | `0x100331a4` | `0x10001370` |
| `Peer2PeerBackend::vftable` | `0x100331a8` | `0x10002880` |
| `Peer2PeerBackend::vftable` | `0x100331ac` | `0x10001370` |
| `ReplayBackend::vftable` | `0x100331c8` | `0x10027ac0` |
| `ReplayBackend::vftable` | `0x100331cc` | `0x10027ae0` |
| `ReplayBackend::vftable` | `0x100331d0` | `0x10002870` |
| `ReplayBackend::vftable` | `0x100331d4` | `0x10001370` |
| `ReplayBackend::vftable` | `0x100331d8` | `0x10001370` |
| `ReplayBackend::vftable` | `0x100331dc` | `0x10002880` |
| `ReplayBackend::vftable` | `0x100331e0` | `0x10001380` |
| `ReplayBackend::vftable` | `0x100331e4` | `0x10001370` |
| `ReplayBackend::vftable` | `0x100331e8` | `0x10002d50` |
| `SpectatorBackend::vftable` | `0x100331f0` | `0x10028ed0` |
| `SpectatorBackend::vftable` | `0x100331f4` | `0x10028c90` |
| `SpectatorBackend::vftable` | `0x100331f8` | `0x10002870` |
| `SpectatorBackend::vftable` | `0x100331fc` | `0x10001370` |
| `SpectatorBackend::vftable` | `0x10033200` | `0x10001370` |
| `SpectatorBackend::vftable` | `0x10033204` | `0x10002880` |
| `SpectatorBackend::vftable` | `0x10033208` | `0x10001380` |
| `SpectatorBackend::vftable` | `0x1003320c` | `0x10001370` |
| `SpectatorBackend::vftable` | `0x10033210` | `0x10003520` |
| `SpectatorBackend::vftable` | `0x10033218` | `0x10001370` |
| `SpectatorBackend::vftable` | `0x1003321c` | `0x10001370` |
| `SpectatorBackend::vftable` | `0x10033220` | `0x10002880` |
| `SpectatorBackend::vftable` | `0x10033224` | `0x10001370` |
| `SyncTestBackend::vftable` | `0x1003322c` | `0x10001370` |
| `SyncTestBackend::vftable` | `0x10033230` | `0x10027660` |
| `SyncTestBackend::vftable` | `0x10033234` | `0x10027730` |
| `SyncTestBackend::vftable` | `0x10033238` | `0x10001370` |
| `SyncTestBackend::vftable` | `0x1003323c` | `0x10001370` |
| `SyncTestBackend::vftable` | `0x10033240` | `0x10002880` |
| `SyncTestBackend::vftable` | `0x10033244` | `0x10027400` |
| `SyncTestBackend::vftable` | `0x10033248` | `0x10001370` |
| `SyncTestBackend::vftable` | `0x1003324c` | `0x10003550` |
| `TimeSync::vftable` | `0x10033254` | `0x10003e10` |
| `Tcp::vftable` | `0x1003325c` | `0x100270e0` |
| `Tcp::vftable` | `0x10033260` | `0x10001370` |
| `Tcp::vftable` | `0x10033264` | `0x10002880` |
| `Tcp::vftable` | `0x10033268` | `0x10001370` |
| `Tcp::vftable` | `0x1003326c` | `0x00000000` |
| `Tcp::vftable` | `0x10033270` | `0x100258f0` |
| `TcpProtocol::vftable` | `0x10033330` | `0x10001370` |
| `TcpProtocol::vftable` | `0x10033334` | `0x10001370` |
| `TcpProtocol::vftable` | `0x10033338` | `0x10002880` |
| `TcpProtocol::vftable` | `0x1003333c` | `0x10026240` |
| `Udp::vftable` | `0x100333bc` | `0x10024da0` |
| `Udp::vftable` | `0x100333c0` | `0x10001370` |
| `Udp::vftable` | `0x100333c4` | `0x10024ba0` |
| `Udp::vftable` | `0x100333c8` | `0x10024a10` |
| `Udp::Callbacks::vftable` | `0x100333d0` | `0x10011951` |
| `Udp::Callbacks::vftable` | `0x100333d4` | `0x10011951` |
| `Udp::Callbacks::vftable` | `0x100333d8` | `0x10011951` |
| `UdpProtocol::vftable` | `0x100333e0` | `0x10001370` |
| `UdpProtocol::vftable` | `0x100333e4` | `0x10001370` |
| `UdpProtocol::vftable` | `0x100333e8` | `0x10024390` |
| `UdpProtocol::vftable` | `0x100333ec` | `0x10001370` |
| `UdpProtocol::vftable` | `0x100333f4` | `0x100233a0` |
| `UdpProtocol::vftable` | `0x100333f8` | `0x10024240` |
| `UdpProtocol::vftable` | `0x100333fc` | `0x10023350` |
| `Sync::vftable` | `0x10033418` | `0x1000b390` |
