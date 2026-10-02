# Single Player launch (2026-10-02)

The room header's Single Player button calls `launchSinglePlayer(in:)`, which validates the room's actual emulator/game identifiers, installed native local runtime and ROM. Room membership and Fightcade match capabilities are not required. An active match/direct session, another launch, or an in-progress ROM operation disables the action. The view model rechecks availability at invocation and sets the launch flag before scheduling work, preventing duplicate launches.

The launch cancels Fightcade TV/replay cycling, stops the previous local/viewing session, and opens `FightcadeEmbeddedLaunch.singlePlayer`. Its arguments contain only the game identifier, its mode/title are Single Player, and it has no match metadata or required Quark capability. `FightcadeLauncher.openEmbedded` still validates embedded support, resolves the ROM, writes normal controller preferences, creates the shared video/input resources and starts the bundled native emulator. Match-only netplay preparation is bypassed by the existing launcher rule. The successful session selects the originating room and shows Gameplay; launch errors use the existing error presentation and clear the busy state. The normal Gameplay Stop action terminates the emulator.

The existing Test Launch and Training tools remain available. Single Player uses the same local emulator path as Test Launch, with a distinct session label. FBNeo's regular local arcade game handles credits, start and CPU play; this button does not invent an emulator-specific CPU or training mode. Existing gamepad/keyboard input paths and Fightcade/GGPO routes are unchanged.

## Verification

`TEST_RUNNER_MACADE_SINGLE_PLAYER_RUNTIME=1 xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' -derivedDataPath .build/xcode -only-testing:MacadeAppTests/SinglePlayerLaunchTests -only-testing:MacadeAppTests/FightcadeRuntimeRegressionTests -only-testing:MacadeAppTests/ChannelTVTests test` passed 35 tests.

The opt-in integration test invokes the production view model with the production launcher and the installed `sfiii3nr1` ROM. Bundled FBNeo rendered nonzero 384×224 video at frame 71, continued advancing, and exited after Stop. It also verifies Gameplay routing, selected room and Single Player session identity. It skips when another FBNeo game is running. Other tests cover missing runtime/ROM, launch failure, duplicate clicks, active match/direct protection and local-versus-Quark routing. Other emulator/ROM combinations and physical gamepad gameplay were not exercised by this launch check.

Release 0.6.0 verification (2026-10-02): the same command without the `-only-testing` filters passed all 151 tests with zero failures. The native Single Player test ran without skipping, rendered 384×224 at frame 76, observed advancing frames, and confirmed termination after Stop. The full runtime staging script also passed its architecture, portable-dependency and code-signature checks.
