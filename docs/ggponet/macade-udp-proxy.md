# Macade UDP Proxy Layer

This note documents Macade-specific connection assistance around the verified Fightcade GGPO behavior. It does not replace the GGPO peer wire protocol documented in `udp-protocol-map.md`.

## Scope

- Applies to embedded FBNeo `quark:served` match launches.
- Keeps native GGPO packet formats unchanged: sync request/reply, compressed input, quality report, and quality reply remain the documented UDP types `1...5`.
- Uses a local UDP proxy at `127.0.0.1:7001...7009` so Macade can preserve the UDP socket used for Fightcade master registration and peer hole punching.
- Before it observes FBNeo's source socket, the proxy forwards peer packets to the default native GGPO local UDP port `6000`; once FBNeo sends a packet, the proxy updates to that exact source port.
- Native `ggpo_client_connect` honors `MACADE_GGPO_PROXY_HOST`, `MACADE_GGPO_PROXY_PORT`, and `MACADE_GGPO_TCP_REGISTER_PORT` only when Macade sets them.

## Connection Assistance

- The proxy filters only exact Fightcade hole-punch token messages such as `0.x _` and `0.x 0.y ok`; binary GGPO packets are forwarded even if their bytes contain similar ASCII sequences.
- The proxy drains UDP bursts from both local emulator and remote peer sides before sleeping again.
- After a successful punch, the proxy can keep sending the final punch payload until GGPO packets have flowed in both directions.
- Fallback punching tries observed and known Fightcade ports before the wider normal-NAT scan.
- Optional automatic router mapping is user-controlled and best-effort: PCP, NAT-PMP, then UPnP IGD.

## Verification

- FBNeo runtime build: `cd Sources/FightcadeFBNeo && make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl`
- App build: `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build`

This layer still matches the verified evidence because it forwards the native GGPO UDP payloads unchanged and only changes how Macade reaches the remote peer endpoint on macOS.
