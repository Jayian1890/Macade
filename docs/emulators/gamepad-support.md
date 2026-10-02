# Issue #2: FBNeo gamepad binding support

Controller Options now has an SDL-backed device picker, searchable FBNeo game catalog, actual driver action labels, button/axis/hat capture, clear/reset/cancel, duplicate-binding feedback, and live input indicators. Save and relaunch applies the profile. Keyboard preferences and the advanced SDL recognition database remain separate.

## Input boundary and player sides

Source trace: `DrvInit` constructs `GameInp` through `GameInpInit`, `ConfigGameLoad`, and `GameInpDefault`. The SDL input interface's `NewFrame` calls `MacadeGamepadPoll`. `InputMake` processes saved controls, then `MacadeGamepadApply` combines the configured digital gamepad state with keyboard switches, before FBNeo processes macros. Analog bindings use the selected physical axis, the existing `nAnalogSpeed` relative scaling, or the driver's absolute-axis range.

`RunFrame` still calls `InputMake(true)` only for live input, before `NetworkGetInput`. The latter serializes the first player bank into `controls`, calls `QuarkGetInput`, and restores synchronized player banks. The direct peer backend places local input in slot 0 or 1 using `local_player_is_player2`. The served client vtable delegates synchronization to that same peer backend. No GGPO bytes, player counts, route arguments, transport, frame delays, or rollback polling rules change.

For a match, configure Player 1 in the editor irrespective of the assigned Fightcade match side. The native profile resolver rejects other local-player banks during netplay and all profile input during spectator/replay routes. Local play/training can configure the additional players actually exposed by the driver. This is independent of the standalone `-joy` option.

## Discovery and capture

`macfbneo --macade-controllers` is a settings-only helper process. It initializes a hidden SDL video window to pump Cocoa callbacks, polls the same SDL joystick API used by gameplay, and emits newline-delimited JSON snapshots. It stays a background process, runs only while the section is visible, exits on termination or loss of its parent, and is excluded from the launcher's single-game-process gate. The Swift reader uses a single POSIX pipe read per available chunk: Foundation's `read(upToCount:)` could wait for 16 KB and hide the initial neutral snapshot because the helper emits only changed state. The bundled-helper test exposed that stall; discovery now delivers the first short line immediately.

The bridge uses raw SDL button indices, signed axis directions, and hat bits, rather than synthesizing keyboard events. This deliberate refinement of the planned logical-controller bridge allows unrecognized arcade sticks to be bound without a guessed database mapping. SDL's GameController database still governs legacy logical-controller defaults; it is not a gameplay profile. Capture and gameplay share raw identifiers and thresholds, so changing the database does not reinterpret a captured raw binding.

Digital axis directions require more than 16,000 units of travel; analog axes ignore values within 8,000 units of center. Capture waits for release/neutral before accepting a new control. Axes initialized at the negative endpoint (common for released triggers) are treated as resting controls for capture, using SDL's initial-axis state rather than the currently held stick position. Release controls before connecting a device so that SDL can establish its initial state.

Device identity is SDL GUID plus serial, when available. Without a serial, identical GUIDs use available connection slots; reconnecting indistinguishable controllers in another order cannot be uniquely resolved. The UI describes that limitation. USB/Bluetooth can expose different GUIDs and therefore require separate profiles. Detached handles are closed and input becomes neutral; reconnection is enumerated without restarting gameplay. Legacy joystick enumeration is bounded, unmapped controllers no longer dereference a null GameController, and logical binds are checked before reading their union.

`--macade-gamepad-games` and `--macade-gamepad-inputs <driver>` read Burn driver metadata without loading a ROM. Player identity comes from `szInfo` or the displayed name, matching FBNeo's legacy-driver conventions. The editor includes digital and analog player actions and excludes constants, DIP settings, and non-player service/reset controls.

## Persistence and precedence

Version 1 Codable preferences use the independent `MacadeGamepadPreferences` UserDefaults key. Save/Discard includes these preferences; existing keyboard data is untouched. Launch atomically writes `macade-gamepads-v1.txt` to the FBNeo data directory and passes its path through `MACADE_GAMEPAD_PROFILE_PATH`. Failures propagate through launch rather than silently dropping the profile.

The native parser validates the version, bounds, control kind, exact driver ID, input index, input-info identity, and player. An explicit binding overrides the legacy joystick switch for that action and adds the selected controller state; keyboard switches remain available. Clearing records an explicit unbound gamepad action. Restoring deletes the Macade records for that game's selected player and returns to FBNeo's saved/default controls. Analog bindings own the selected axis for that action. No Macade profile is written into FBNeo's game INI files.

One controller owns a given game action. Reusing a control within the same controller/game/player clears its former Macade action and reports the move. Other games, devices, and player profiles retain their bindings. Profiles are loaded before the first live frame; settings edits require relaunch.

## Verification (2026-10-01)

- Native `make -f makefile.sdl gamepad-tests CPUTYPE=arm64 DEPEND= PERL=perl` links the production SDL input interface, `GameInp`, FBNeo network serializer, Quark boundary, and native GGPO. A real SDL virtual joystick covers buttons, signed axes, drift/dead zones, diagonal hats, invalid control indices, release, disconnect/reconnect, keyboard socket coexistence, and an Out Run analog action.
- The test exercises both direct and served-client synchronization vtables on both player sides, accounts for GGPO's intentional first-frame clear, and checks that a distinct remote action is preserved. Only the network handshake is bypassed; no input serializer or synchronization implementation is replaced. These are input-boundary tests, not live Fightcade connectivity tests.
- Xcode tests cover versioned persistence/projection, old keyboard preferences, conflicts, explicit clear versus restore, invalid records, Save/Discard, capture release gating, held sticks versus resting triggers, disconnect, and the bundled helper/driver metadata contract. SF2 exposes twelve Player 1 actions, 1942 eight, and Out Run three analog actions.
- The settings UI was visually inspected with the PS4 device picker, live state, game-specific action rows, and local-player guidance visible.
- A physically connected PS4 Controller was discovered with a serial identity and six axes. The helper observed a face button and right-stick directions; released triggers reported the negative axis endpoints and were correctly classified as resting. Serial values are intentionally omitted here.
- Build with `xcodebuild -project Macade.xcodeproj -scheme Macade -destination 'platform=macOS' build`, plus the FBNeo build command in AGENTS.md. Runtime staging uses the FBNeo portion of `Scripts/build-macade-full.sh`, including architecture, UUID, portable dependency, and code-signature checks.

Remaining release checks: actual gameplay with physical pads on both Fightcade match sides, USB and Bluetooth comparison, all buttons/hats/triggers, a second controller, and reconnect during a real match. Automated vtable tests and physical discovery/capture do not establish these hardware/live-session results.

## Issue summary

Implemented an actual FBNeo gamepad binding editor beside keyboard bindings. Players can select a detected controller and game, capture the game's named actions, test input, clear or restore bindings, then save and relaunch. The runtime consumes the same SDL controls directly before existing Fightcade/GGPO synchronization, supporting either match side without changing the protocol. The SDL database editor now explains its device-recognition scope. Automated input/persistence checks pass; physical PS4 discovery and selected controls are observed, with full live-match/hardware coverage still outstanding.

SDL API references: [device serials](https://wiki.libsdl.org/SDL2/SDL_JoystickGetSerial), [virtual joysticks](https://wiki.libsdl.org/SDL2/SDL_JoystickAttachVirtual), and [background controller input](https://wiki.libsdl.org/SDL2/SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS).

## C5P and Nova 2 Lite compatibility research (2026-10-01)

Console aliases such as `Wireless Controller` and `Pro Controller` cannot reliably identify the physical model. Controller-specific in-app guidance has been removed; the following remains implementation research. Macade does not invent model GUIDs, VID/PIDs, SDL mappings or fixed game button assignments. Once SDL discovers the device, raw binding supports its reported buttons, axes and hats independently of a GameController database entry.

| Model / connection | Manufacturer instructions | Evidence / limits |
| --- | --- | --- |
| C5P Xbox Bluetooth | Off: hold X, press Home; blue flashing; pair `Xbox Wireless Controller`. | Manufacturer lists Xinput mode for Mac OS. Exact hardware untested. |
| C5P DS Bluetooth | Off: hold RB, press Home; yellow flashing; pair `Wireless Controller` or `DUALSHOCK 4 Wireless Controller`. | Alternative based on documented DS mode and SDL PS4 support. Physical PS4 testing is not C5P testing. |
| C5P NS Bluetooth | Off: hold Y, press Home; pink flashing; pair `Pro Controller`. | Documented non-Switch pairing and SDL Switch support; exact hardware untested. |
| C5P USB / receiver | Data USB cable; receiver pairing: off, hold LB, press Home; purple light. | Manufacturer lists Mac OS; descriptors, backend discovery and receiver behavior unverified. Try Bluetooth if no device/input appears. |
| Nova 2 Lite DS Bluetooth | Hold Home + B; blue flashing; pair `Wireless Controller`. Home + Screenshot for 3 seconds forces pairing. | Documented DS personality; manufacturer platform list does not explicitly promise macOS. Hardware untested. |
| Nova 2 Lite Switch Bluetooth | Hold Home + Y; red flashing; pair `Pro Controller`. | Documented “Other Devices” path and SDL Switch support. Triggers are digital in this mode; SDL can expose their state through axes. Hardware untested. |
| Nova 2 Lite USB / receiver | USB cable; receiver pairing Home + X, then receiver pairing button. Connected: hold Menu + View for 2 seconds to cycle Xbox/Switch modes. | Xbox green, Switch red. Neither mode is promised to enumerate on macOS. Bluetooth remains a possible alternative, pending hardware verification. |

The bundled libraries report SDL2-compat API 2.32.72 and SDL3 3.4.16 (checked through their version APIs). SDL3 contains PS4, Switch and Xbox drivers plus macOS native controller/HID paths. Driver availability does not prove that third-party firmware reports a supported identity or protocol. Windows USB XInput support does not establish macOS support; the Xbox 360 HIDAPI driver has macOS-specific native-controller/libusb selection. No global driver override or guessed database entry was added.

C5P rear ML/MR controls reproduce firmware-programmed inputs (L3/R3 by default); Nova rear L4/R4 controls are programmed on the controller. Macade captures the resulting control, without promising independent paddles. Nova trigger-stop changes require the manufacturer's three-full-press recalibration. Changing mode, transport or firmware button layout requires checking identity and recapturing as necessary. G-Touch mobile touch mapping is not the native binding path. Rumble, gyro, firmware updates and hardware macro editing are outside this feature.

Extended tests use an unmapped six-axis, sixteen-button SDL virtual joystick. Analog/digital triggers, D-pads reported as buttons/hats, and button index 15 reach actual SF2 inputs and release correctly. UI capture accepts varied controls under generic Xbox/PS4/Switch names. These exercise production capture/input, not either manufacturer's hardware protocol. Existing GGPO side/route, keyboard coexistence, analog game and reconnect checks still pass. The 12 selected Xcode tests pass; the bundled-helper metadata/initial-snapshot test completes in 0.885 seconds after the pipe-reader fix. The Xcode build also passes after removing the controller-specific guide.

Sources inspected:

- [abxylute official manual index](https://abxylute.com/pages/tutorials) links the [C5P manual](https://cdn.shopify.com/s/files/1/0610/1847/2600/files/abxylute_C5P_-_0109.pdf?v=1768552134). English pages 15–21 and 24–25 establish modes, pairing names and rear-button defaults. Pages 17–18 were also rendered to verify the diagram.
- [GameSir Nova Lite 2 manual page](https://gamesir.com/support/manuals/gamesir-nova-lite2) identifies Nova 2 Lite in its FAQ and links the [exact Nova 2 Lite PDF](https://cdn.shopify.com/s/files/1/2241/8433/files/GameSir-Nova_2_Lite_manual.pdf?v=1747982416). Its tutorials and advanced-operation sections establish pairing, mode cycling, back buttons and trigger-stop calibration. The [Nova 2 Lite tutorial](https://gamesir.com/pages/tutorials-how-to-connect-nova-2-lite) independently supplies DS-mode pairing; its Home+B icon was visually inspected. No original Nova Lite mappings were reused.
- SDL3 3.4.16: [PS4 driver](https://github.com/libsdl-org/SDL/blob/release-3.4.16/src/joystick/hidapi/SDL_hidapi_ps4.c), [Switch driver](https://github.com/libsdl-org/SDL/blob/release-3.4.16/src/joystick/hidapi/SDL_hidapi_switch.c), [Xbox 360 driver](https://github.com/libsdl-org/SDL/blob/release-3.4.16/src/joystick/hidapi/SDL_hidapi_xbox360.c) and [controller identities](https://github.com/libsdl-org/SDL/blob/release-3.4.16/src/joystick/controller_list.h). Protocol compatibility is an inference about documented modes, not physical validation.

Hardware gate: obtain each model and verify discovery, every control, neutral/release, reconnect, profile identity, local FBNeo and both live Fightcade sides. Record macOS/firmware versions and each transport/mode separately. Neither model is owned by the requester; this gate remains outstanding.

Release 0.6.0 verification (2026-10-02): all 151 Xcode tests passed, including the bundled discovery helper and real local FBNeo launch. The native gamepad/GGPO suite passed again. Removed obsolete SDL copies under `fbneo/lib` that retained Homebrew install names; the runtime uses the verified portable libraries beside `macfbneo`. Launch diagnostics now report that directory when no legacy `lib` directory exists. Hardware and live-match limitations above remain unchanged.

Issue #2 addition: researched C5P and Nova 2 Lite modes, fixed delayed initial discovery, and expanded real input/capture tests for varied control representations. Removed the controller-specific setup guide at the user’s request. Generic SDL input covers reported controls without a fabricated model mapping; exact hardware/transport compatibility remains qualified until physical validation.
