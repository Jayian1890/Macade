# Macade UDP Proxy Layer

This note documents Macade-specific connection assistance around the verified Fightcade GGPO behavior. It does not replace the GGPO peer wire protocol documented in `udp-protocol-map.md`.

## Scope

- Applies to embedded FBNeo `quark:served` match launches.
- Completes master registration and peer hole punching before starting the emulator process.
- Keeps native GGPO packet formats unchanged: sync request/reply, compressed input, quality report, and quality reply remain the documented UDP types `1...5`.
- Uses a local UDP proxy at `127.0.0.1:7001...7009` so Macade can preserve the UDP socket used for Fightcade master registration and peer hole punching.
- Before it observes FBNeo's source socket, the proxy forwards peer packets to the default native GGPO local UDP port `6000`; once FBNeo sends a packet, the proxy updates to that exact source port.
- The master transport first tries local UDP port `6006`, then an ephemeral port if `6006` is unavailable. Registration still advertises the reserved local proxy port.
- Native `ggpo_client_connect` honors `MACADE_GGPO_PROXY_HOST`, `MACADE_GGPO_PROXY_PORT`, and `MACADE_GGPO_TCP_REGISTER_PORT` only for a successfully prepared proxy route.

## Connection Assistance

- Master registration sends `<quark-id>.<player>/<proxy-port>`, requires the exact `ok <quark-id>.<player>` response, and retries once after a timeout.
- The proxy filters only exact Fightcade hole-punch token messages such as `0.x _` and `0.x 0.y ok`; binary GGPO packets are forwarded even when they contain similar ASCII bytes.
- Hole punching succeeds only after the peer acknowledges the exact locally generated token. Packets from the master or an unrelated endpoint cannot complete the exchange.
- Macade first punches the peer endpoint supplied by the master. If that fails, it creates a fresh socket bound to local port `6004` and targets remote port `6004`.
- The proxy drains UDP bursts from both local emulator and remote peer sides before sleeping again.
- After a successful punch, the proxy can keep sending the final punch payload until GGPO packets have flowed in both directions.
- A permanent proxy transport failure terminates the embedded runtime and preserves the connection failure in session status.
- Optional automatic router mapping is user-controlled and best-effort: PCP, NAT-PMP, then UPnP IGD for UDP ports `6006`, `6004`, and `6000`.

## Native Useports Fallback

- Registration, acknowledgment, peer-address, or punch failure selects the historical Fightcade native fallback instead of aborting launch.
- Macade sends `useports/<quark-id>.<player>` to the Fightcade master as a best-effort diagnostic transition.
- The emulator then starts without any `MACADE_GGPO_*` variables, allowing native `ggpo_client_connect` to use the Fightcade open-port path.
- This fallback does not introduce a matchmaking service or alter GGPO packet bytes.
- Automated tests cover route selection and payload ordering. A successful session across external NAT still requires live Fightcade verification.

## Verification

- App netplay tests: `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' -only-testing:MacadeAppTests/FightcadeNetplaySessionTests -only-testing:MacadeAppTests/FightcadeNetplayLifecycleTests test`
- Native malformed-packet and quark-command tests: `Sources/FightcadeFBNeo/src/dep/ggponet-native/tests/run-sanitizers.sh`
- FBNeo runtime build: `cd Sources/FightcadeFBNeo && make -f makefile.sdl -j"$(sysctl -n hw.ncpu 2>/dev/null || echo 4)" CPUTYPE="$(uname -m)" DEPEND= PERL=perl`
- App build: `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build`

This layer still matches the verified evidence because valid native GGPO UDP payloads are forwarded unchanged. Macade only selects how the native macOS runtime reaches the Fightcade master and peer endpoints.
