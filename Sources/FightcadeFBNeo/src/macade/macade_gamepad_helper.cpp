#include "burner.h"
#include "macade_gamepad.h"
#include "macade_gamepad_devices.h"
#include <unistd.h>
#include <signal.h>

namespace {
volatile sig_atomic_t running = 1;
void stop(int) { running = 0; }

}
int MacadeGamepadCommand(int argc, char** argv)
{
    if (argc < 2) return -1;
    if (!strcmp(argv[1], "--macade-controllers")) {
        SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
        SDL_SetHint(SDL_HINT_MAC_BACKGROUND_APP, "1");
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_EVENTS)) {
            fprintf(stderr, "Controller discovery failed: %s\n", SDL_GetError()); return 1;
        }
        // Cocoa must pump its event loop for macOS controller callbacks, just as gameplay does.
        SDL_Window* window = SDL_CreateWindow("Macade Controller Discovery", 0, 0, 1, 1, SDL_WINDOW_HIDDEN);
        if (!window) { fprintf(stderr, "Controller discovery window failed: %s\n", SDL_GetError()); SDL_Quit(); return 1; }
        signal(SIGTERM, stop); signal(SIGINT, stop);
        MacadePadDevices pads;
        std::string previous;
        while (running && getppid() != 1) {
            pads.poll();
            std::string snapshot = pads.snapshot();
            if (snapshot != previous) {
                puts(snapshot.c_str()); fflush(stdout); previous = snapshot;
            }
            SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
            SDL_Delay(16);
        }
        pads.close(); SDL_DestroyWindow(window); SDL_Quit(); return 0;
    }
    bool games = !strcmp(argv[1], "--macade-gamepad-games");
    bool inputs = !strcmp(argv[1], "--macade-gamepad-inputs");
    if (!games && !inputs) return -1;
    if (inputs && argc != 3) return 1;
    BurnLibInit();
    bool first = true;
    printf("[");
    bool found = games;
    for (unsigned int driver = 0; driver < nBurnDrvCount; ++driver) {
        nBurnDrvActive = driver;
        const char* name = BurnDrvGetTextA(DRV_NAME);
        if (games) {
            if (!first) printf(","); first = false;
            printf("{\"id\":%s,\"title\":%s}", MacadePadJSON(name).c_str(), MacadePadJSON(BurnDrvGetTextA(DRV_FULLNAME)).c_str());
        } else if (!strcmp(name, argv[2])) {
            found = true;
            BurnInputInfo info{};
            for (unsigned int index = 0; !BurnDrvGetInputInfo(&info, index); ++index) {
                int player = MacadeGamepadInputPlayer(info);
                if (!player || !info.szInfo || !*info.szInfo || (info.nType != BIT_DIGITAL && !(info.nType & BIT_GROUP_ANALOG))) continue;
                if (!first) printf(","); first = false;
                printf("{\"index\":%u,\"title\":%s,\"info\":%s,\"player\":%d,\"analog\":%s}",
                    index, MacadePadJSON(info.szName).c_str(), MacadePadJSON(MacadePadHex(info.szInfo)).c_str(), player,
                    info.nType & BIT_GROUP_ANALOG ? "true" : "false");
            }
            break;
        }
    }
    puts("]"); BurnLibExit();
    if (!found) { fprintf(stderr, "Unknown FBNeo game: %s\n", argv[2]); return 1; }
    return 0;
}
