// Link against the production runtime and use its globals without starting a ROM.
#define main MacadeRuntimeMain
#include "../../burner/sdl/main.cpp"
#undef main
#include "../macade_gamepad.h"
#include "../macade_embedded.h"
#include "../macade_gamepad_devices.h"
#include "../../dep/ggponet-native/src/peer_backend.hpp"
#include "../../dep/ggponet-native/src/client_backend.cpp"
#include <algorithm>
#include <sys/socket.h>
#include <sys/un.h>
#include <cassert>
#include <fstream>
#include <unistd.h>

extern GGPOSession* ggpo;
using namespace ggponet::reconstructed;

static UINT32 driver(const char* name)
{
    for (UINT32 i = 0; i < nBurnDrvCount; ++i) {
        nBurnDrvActive = i;
        if (!strcmp(BurnDrvGetTextA(DRV_NAME), name)) return i;
    }
    assert(false); return 0;
}
static bool begin(char*) { return true; }
static bool event(GGPOEvent*) { return true; }
static bool save(unsigned char** buffer, int* length, int* checksum, int) {
    *length = 1; *checksum = 0; *buffer = (unsigned char*)malloc(1); **buffer = 0; return true;
}
static void release(void* buffer) { free(buffer); }
static void frame() { ++nCurrentFrame; assert(InputMake(true) == 0); }
static int value(int index) { return *GameInp[index].Input.pVal; }

int main()
{
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    assert(SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_EVENTS) == 0);
    // Exercise a raw device with no GameController database mapping. Console
    // modes and generic HID backends can differ in trigger/D-pad representation.
    // This tests input shapes, not either manufacturer's hardware protocol.
    int virtualIndex = SDL_JoystickAttachVirtual(SDL_JOYSTICK_TYPE_UNKNOWN, 6, 16, 1);
    assert(virtualIndex >= 0);
    assert(!SDL_IsGameController(virtualIndex));
    SDL_Joystick* joystick = SDL_JoystickOpen(virtualIndex);
    MacadePadDevices devices;
    devices.poll();
    auto pad = std::find_if(devices.devices().begin(), devices.devices().end(), [&](const MacadePadDevice& pad) {
        return pad.instance == SDL_JoystickInstanceID(joystick);
    });
    assert(pad != devices.devices().end());
    std::string identity = pad->id;
    assert(devices.state(identity, {'b', 0, 0}) == 0);
    SDL_JoystickSetVirtualButton(joystick, 0, 1);
    devices.poll(); assert(devices.state(identity, {'b', 0, 0}) == 1);
    SDL_JoystickSetVirtualAxis(joystick, 0, 7000);
    devices.poll(); assert(devices.state(identity, {'a', 0, 1}) == 0);
    SDL_JoystickSetVirtualAxis(joystick, 0, 24000);
    SDL_JoystickSetVirtualHat(joystick, 0, SDL_HAT_UP | SDL_HAT_RIGHT);
    devices.poll();
    assert(devices.state(identity, {'a', 0, 1}) == 1);
    assert(devices.state(identity, {'x', 0, 0}) == 24000);
    assert(devices.state(identity, {'h', 0, SDL_HAT_UP}) == 1);
    assert(devices.state(identity, {'h', 0, SDL_HAT_LEFT}) == 0);
    assert(devices.state(identity, {'b', 99, 0}) == 0);

    BurnLibInit(); driver("sf2"); nMaxPlayers = BurnDrvGetMaxPlayers();
    assert(GameInpInit() == 0);
    BurnInputInfo punch{}, kick{}, second{}, trigger{}, extraButton{}, direction{};
    BurnDrvGetInputInfo(&punch, 6); BurnDrvGetInputInfo(&kick, 9); BurnDrvGetInputInfo(&second, 18);
    BurnDrvGetInputInfo(&trigger, 7); BurnDrvGetInputInfo(&extraButton, 8); BurnDrvGetInputInfo(&direction, 4);
    char path[] = "/tmp/macade-gamepads-test-XXXXXX";
    int fd = mkstemp(path); assert(fd >= 0); close(fd);
    std::ofstream profile(path);
    profile << "MACADE_GAMEPADS 1\n" << identity << " sf2 6 1 " << MacadePadHex(punch.szInfo) << " b 0 0\n"
        << identity << " sf2 9 1 " << MacadePadHex(kick.szInfo) << " h 0 1\n"
        << identity << " sf2 18 2 " << MacadePadHex(second.szInfo) << " b 1 0\n"
        << identity << " sf2 7 1 " << MacadePadHex(trigger.szInfo) << " a 4 1\n"
        << identity << " sf2 8 1 " << MacadePadHex(extraButton.szInfo) << " b 15 0\n"
        << identity << " sf2 4 1 " << MacadePadHex(direction.szInfo) << " b 14 0\n"
        << identity << " outrun 3 1 " << MacadePadHex("p1 x-axis") << " x 0 0\n";
    profile.close(); setenv("MACADE_GAMEPAD_PROFILE_PATH", path, 1);
    assert(InputInit() == 0); GameInpDefault();
    frame(); assert(value(6) == 1 && value(9) == 1 && value(18) == 0);
    SDL_JoystickSetVirtualButton(joystick, 1, 1);
    frame(); assert(value(18) == 1);
    SDL_JoystickSetVirtualAxis(joystick, 4, -32768); // released analog trigger
    frame(); assert(value(7) == 0);
    SDL_JoystickSetVirtualAxis(joystick, 4, 32767);
    SDL_JoystickSetVirtualButton(joystick, 15, 1); // digital trigger / higher button index
    SDL_JoystickSetVirtualButton(joystick, 14, 1); // D-pad exposed as a button
    frame(); assert(value(7) == 1 && value(8) == 1 && value(4) == 1);
    SDL_JoystickSetVirtualAxis(joystick, 4, -32768);
    SDL_JoystickSetVirtualButton(joystick, 15, 0);
    SDL_JoystickSetVirtualButton(joystick, 14, 0);
    frame(); assert(value(7) == 0 && value(8) == 0 && value(4) == 0);
    // Exercise the existing embedded keyboard socket alongside the gamepad profile.
    char socketPath[100]; snprintf(socketPath, sizeof(socketPath), "/tmp/macade-key-test-%d.sock", getpid());
    setenv("MACADE_EMBEDDED_SESSION_ID", "gamepad-test", 1);
    setenv("MACADE_EMBEDDED_INPUT_SOCKET", socketPath, 1);
    MacadeEmbeddedPumpInput();
    int sender = socket(AF_UNIX, SOCK_DGRAM, 0); assert(sender >= 0);
    sockaddr_un address{}; address.sun_family = AF_UNIX;
    snprintf(address.sun_path, sizeof(address.sun_path), "%s", socketPath);
    auto key = [&](const char* command) {
        assert(sendto(sender, command, strlen(command), 0, (sockaddr*)&address, sizeof(address)) > 0);
        frame();
    };
    // A keyboard switch remains available for a profiled action.
    GameInp[6].nInput = GIT_SWITCH; GameInp[6].Input.Switch.nCode = FBK_A;
    SDL_JoystickSetVirtualButton(joystick, 0, 0);
    SDL_JoystickSetVirtualHat(joystick, 0, SDL_HAT_CENTERED);
    frame(); assert(value(6) == 0 && value(9) == 0);
    key("key 1 4"); assert(value(6) == 1);
    key("key 0 4"); assert(value(6) == 0);
    SDL_JoystickSetVirtualButton(joystick, 0, 1);

    // Real InputMake -> NetworkGetInput -> QuarkGetInput -> native GGPO synchronization.
    // Only the handshake is bypassed; no packet format or serialization is replaced.
    GGPOSessionCallbacks callbacks{};
    callbacks.begin_game = begin; callbacks.on_event = event;
    callbacks.save_game_state = save; callbacks.free_buffer = release;
    for (int route = 0; route < 2; ++route) for (int side = 0; side < 2; ++side) {
        ClientBackend client{};
        PeerBackend* peer;
        if (route == 0) { peer = create_peer_session(&callbacks, (char*)"sf2", 0); assert(peer); }
        else {
            client.socket_fd = -1;
            assert(peer_backend_construct(&client.peer, &client_vtable, &callbacks, (char*)"sf2", 0));
            peer = &client.peer;
        }
        assert(peer_session_connect(peer, (char*)"127.0.0.1", 9, side != 0));
        peer->synchronizing = false;
        sync_set_frame_delay(&peer->sync, 0);
        ggpo = &peer->base; kNetGame = 1; NetworkInitInput();
        frame(); assert(value(6) == 1);
        // Player 2's local-play profile must not enter a match's remote bank.
        assert(!MacadeGamepadOwnsInput(18));
        assert(NetworkGetInput() == 0);
        // GGPO intentionally clears the first frame; test the next synchronized frame.
        assert(value(6) == 0 && value(18) == 0);
        const int inputSize = peer->sync.prediction.predict_queue.back().size / 2;
        GameInput initialRemote{};
        initialRemote.frame = 0; initialRemote.size = inputSize * 2;
        sync_add_remote_input(&peer->sync, &initialRemote);
        sync_check_simulation(&peer->sync);
        assert(peer->sync.prediction.predict_queue.empty());
        sync_advance_frame(&peer->sync);
        GameInput remote{};
        remote.frame = 1; remote.size = inputSize * 2;
        remote.bits[inputSize * (1 - side)] = 1 << 7; // remote medium punch
        sync_add_remote_input(&peer->sync, &remote);
        frame(); assert(NetworkGetInput() == 0);
        assert(value(side == 0 ? 6 : 18) == 1);
        assert(value(side == 0 ? 18 : 6) == 0);
        assert(value(side == 0 ? 19 : 7) == 1);
        printf("GGPO %s side %d: bound P1 weak punch synchronized into game P%d\n", route ? "served vtable" : "direct", side + 1, side + 1);
        ggpo = nullptr;
        if (route == 0) peer->base.vtable->destroy(&peer->base); else peer_backend_teardown(peer);
        kNetGame = 0;
    }
    kNetSpectator = 1;
    assert(!MacadeGamepadOwnsInput(6));
    kNetSpectator = 0;

    SDL_JoystickDetachVirtual(virtualIndex);
    devices.poll(); assert(devices.state(identity, {'b', 0, 0}) == 0);
    frame(); assert(value(6) == 0 && value(18) == 0);
    SDL_JoystickClose(joystick);
    int reconnected = SDL_JoystickAttachVirtual(SDL_JOYSTICK_TYPE_UNKNOWN, 6, 16, 1);
    assert(reconnected >= 0);
    joystick = SDL_JoystickOpen(reconnected);
    devices.poll();
    assert(std::any_of(devices.devices().begin(), devices.devices().end(), [&](const MacadePadDevice& pad) { return pad.id == identity; }));
    SDL_JoystickSetVirtualButton(joystick, 0, 1);
    frame(); assert(value(6) == 1);
    GameInpExit(); InputExit();
    driver("outrun"); nMaxPlayers = BurnDrvGetMaxPlayers();
    assert(GameInpInit() == 0); assert(InputInit() == 0); GameInpDefault();
    SDL_JoystickSetVirtualAxis(joystick, 0, 24000);
    frame();
    assert(static_cast<INT16>(*GameInp[3].Input.pShortVal) == (24000 * 2 * nAnalogSpeed) >> 13);
    SDL_JoystickSetVirtualAxis(joystick, 0, 7000); frame();
    assert(*GameInp[3].Input.pShortVal == 0);
    close(sender); MacadeEmbeddedShutdown(); unlink(socketPath);
    InputExit(); GameInpExit(); BurnLibExit();
    devices.close(); SDL_JoystickClose(joystick); SDL_JoystickDetachVirtual(reconnected); SDL_Quit(); unlink(path);
    puts("PASS: unmapped SDL device, analog/digital triggers, button/hat D-pad, high button indices, profile input, analog game axis, keyboard, both GGPO sides, spectator exclusion, disconnect and reconnect");
}
