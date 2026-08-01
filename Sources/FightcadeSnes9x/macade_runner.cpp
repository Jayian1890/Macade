#include "libretro.h"
#include "macade_audio.h"
#include "macade_quark.h"
#include "macade_embedded.h"

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <csignal>
#include <string>
#include <sys/stat.h>
#include <thread>
#include <vector>

bool bNetRollback = false;
int MacadeEmbeddedVideoScale = 0;

namespace {

constexpr int kExitUsage = 64;
constexpr int kExitRom = 66;
constexpr int kExitUnsupported = 78;

volatile sig_atomic_t stopRequested = 0;
std::string systemDirectory = ".";
std::string saveDirectory = ".";
retro_pixel_format pixelFormat = RETRO_PIXEL_FORMAT_RGB565;
bool gameLoaded = false;
bool suppressVideo = false;

void handleSignal(int)
{
    stopRequested = 1;
}

bool startsWith(const std::string &value, const char *prefix)
{
    const size_t length = std::strlen(prefix);
    return value.size() >= length && value.compare(0, length, prefix) == 0;
}

bool endsWith(const std::string &value, const char *suffix)
{
    const size_t length = std::strlen(suffix);
    return value.size() >= length && value.compare(value.size() - length, length, suffix) == 0;
}

std::string lowercase(std::string value)
{
    std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return value;
}

bool fileExists(const std::string &path)
{
    struct stat info {};
    return !path.empty() && stat(path.c_str(), &info) == 0 && S_ISREG(info.st_mode) && info.st_size > 0;
}

bool hasPathSeparator(const std::string &value)
{
    return value.find('/') != std::string::npos || value.find('\\') != std::string::npos;
}

bool hasKnownExtension(const std::string &value)
{
    const std::string lower = lowercase(value);
    return endsWith(lower, ".zip") || endsWith(lower, ".sfc") || endsWith(lower, ".smc");
}

void appendUnique(std::vector<std::string> &values, const std::string &value)
{
    if (!value.empty() && std::find(values.begin(), values.end(), value) == values.end()) {
        values.push_back(value);
    }
}

std::vector<std::string> gameStems(const std::string &game)
{
    std::vector<std::string> stems;
    appendUnique(stems, game);

    const std::string lower = lowercase(game);
    if (startsWith(lower, "snes9x_")) {
        appendUnique(stems, game.substr(7));
    }
    if (startsWith(lower, "snes_")) {
        appendUnique(stems, game.substr(5));
    }

    return stems;
}

std::vector<std::string> romCandidates(const std::string &game)
{
    std::vector<std::string> candidates;

    if (hasPathSeparator(game) || hasKnownExtension(game)) {
        appendUnique(candidates, game);
    }

    const char *romDirEnv = std::getenv("MACADE_ROM_DIR");
    const std::string romDir = romDirEnv && romDirEnv[0] ? romDirEnv : ".";

    for (const std::string &stem : gameStems(game)) {
        if (hasKnownExtension(stem)) {
            appendUnique(candidates, romDir + "/" + stem);
            continue;
        }

        appendUnique(candidates, romDir + "/" + stem + ".zip");
        appendUnique(candidates, romDir + "/" + stem + ".sfc");
        appendUnique(candidates, romDir + "/" + stem + ".smc");
    }

    return candidates;
}

std::string resolveGameArgument(const std::string &argument)
{
    if (startsWith(argument, "macade:training,")) {
        return argument.substr(std::strlen("macade:training,"));
    }
    return argument;
}

std::string resolveRomPath(const std::string &game)
{
    for (const std::string &candidate : romCandidates(game)) {
        if (fileExists(candidate)) {
            return candidate;
        }
    }
    return "";
}

bool loadRomForGame(const std::string &game)
{
    if (gameLoaded) {
        return true;
    }

    const std::string romPath = resolveRomPath(game);
    if (romPath.empty()) {
        std::fprintf(stderr, "Could not find Snes9x ROM for '%s'.\n", game.c_str());
        for (const std::string &candidate : romCandidates(game)) {
            std::fprintf(stderr, "searched: %s\n", candidate.c_str());
        }
        return false;
    }

    retro_game_info gameInfo {};
    gameInfo.path = romPath.c_str();
    if (!retro_load_game(&gameInfo)) {
        std::fprintf(stderr, "Snes9x failed to load ROM: %s\n", romPath.c_str());
        return false;
    }

    gameLoaded = true;
    retro_system_av_info avInfo {};
    retro_get_system_av_info(&avInfo);
    MacadeSnes9xAudioStart(avInfo.timing.sample_rate);
    return true;
}

uint32_t bitForRetroID(unsigned id)
{
    switch (id) {
    case RETRO_DEVICE_ID_JOYPAD_B: return 0x0040;
    case RETRO_DEVICE_ID_JOYPAD_Y: return 0x0080;
    case RETRO_DEVICE_ID_JOYPAD_SELECT: return 0x8000;
    case RETRO_DEVICE_ID_JOYPAD_START: return 0x4000;
    case RETRO_DEVICE_ID_JOYPAD_UP: return 0x0020;
    case RETRO_DEVICE_ID_JOYPAD_DOWN: return 0x0010;
    case RETRO_DEVICE_ID_JOYPAD_LEFT: return 0x2000;
    case RETRO_DEVICE_ID_JOYPAD_RIGHT: return 0x1000;
    case RETRO_DEVICE_ID_JOYPAD_A: return 0x0800;
    case RETRO_DEVICE_ID_JOYPAD_X: return 0x0400;
    case RETRO_DEVICE_ID_JOYPAD_L: return 0x0200;
    case RETRO_DEVICE_ID_JOYPAD_R: return 0x0100;
    default: return 0;
    }
}

int16_t keyState(int scancode)
{
    return MacadeEmbeddedKeyState(scancode) ? 1 : 0;
}

bool localButtonPressed(unsigned id)
{
    switch (id) {
    case RETRO_DEVICE_ID_JOYPAD_B: return keyState(29) != 0;
    case RETRO_DEVICE_ID_JOYPAD_Y: return keyState(27) != 0;
    case RETRO_DEVICE_ID_JOYPAD_SELECT: return keyState(34) != 0;
    case RETRO_DEVICE_ID_JOYPAD_START: return keyState(30) != 0;
    case RETRO_DEVICE_ID_JOYPAD_UP: return keyState(82) != 0;
    case RETRO_DEVICE_ID_JOYPAD_DOWN: return keyState(81) != 0;
    case RETRO_DEVICE_ID_JOYPAD_LEFT: return keyState(80) != 0;
    case RETRO_DEVICE_ID_JOYPAD_RIGHT: return keyState(79) != 0;
    case RETRO_DEVICE_ID_JOYPAD_A: return keyState(4) != 0;
    case RETRO_DEVICE_ID_JOYPAD_X: return keyState(22) != 0;
    case RETRO_DEVICE_ID_JOYPAD_L: return keyState(6) != 0;
    case RETRO_DEVICE_ID_JOYPAD_R: return keyState(7) != 0;
    default: return false;
    }
}

uint32_t localJoypadBits()
{
    MacadeEmbeddedPumpInput();
    uint32_t value = 0;
    for (unsigned id = RETRO_DEVICE_ID_JOYPAD_B; id <= RETRO_DEVICE_ID_JOYPAD_R; ++id) {
        if (localButtonPressed(id)) {
            value |= bitForRetroID(id);
        }
    }
    return value;
}

void setRollbackMode(bool enabled)
{
    bNetRollback = enabled;
    suppressVideo = enabled;
}

void retroLog(retro_log_level, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    std::vfprintf(stderr, format, args);
    va_end(args);
}

bool environmentCallback(unsigned command, void *data)
{
    switch (command) {
    case RETRO_ENVIRONMENT_GET_LOG_INTERFACE:
        if (data != nullptr) {
            auto *callback = static_cast<retro_log_callback *>(data);
            callback->log = retroLog;
            return true;
        }
        return false;
    case RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY:
        if (data != nullptr) {
            *static_cast<const char **>(data) = systemDirectory.c_str();
            return true;
        }
        return false;
    case RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY:
        if (data != nullptr) {
            *static_cast<const char **>(data) = saveDirectory.c_str();
            return true;
        }
        return false;
    case RETRO_ENVIRONMENT_SET_PIXEL_FORMAT:
        if (data != nullptr) {
            pixelFormat = *static_cast<retro_pixel_format *>(data);
            return pixelFormat == RETRO_PIXEL_FORMAT_RGB565 || pixelFormat == RETRO_PIXEL_FORMAT_XRGB8888 || pixelFormat == RETRO_PIXEL_FORMAT_0RGB1555;
        }
        return false;
    case RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE:
        if (data != nullptr) {
            *static_cast<bool *>(data) = false;
            return true;
        }
        return false;
    case RETRO_ENVIRONMENT_GET_AUDIO_VIDEO_ENABLE:
        if (data != nullptr) {
            *static_cast<int *>(data) = 1;
            return true;
        }
        return false;
    case RETRO_ENVIRONMENT_SET_SUBSYSTEM_INFO:
    case RETRO_ENVIRONMENT_SET_CONTROLLER_INFO:
    case RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS:
    case RETRO_ENVIRONMENT_SET_PERFORMANCE_LEVEL:
    case RETRO_ENVIRONMENT_SET_SUPPORT_ACHIEVEMENTS:
    case RETRO_ENVIRONMENT_SET_GEOMETRY:
        return true;
    default:
        return false;
    }
}

void videoRefresh(const void *data, unsigned width, unsigned height, size_t pitch)
{
    if (suppressVideo || data == nullptr || width == 0 || height == 0 || pitch == 0) {
        return;
    }

    const int bytesPerPixel = pixelFormat == RETRO_PIXEL_FORMAT_XRGB8888 ? 4 : 2;
    const int isRGB565 = pixelFormat == RETRO_PIXEL_FORMAT_RGB565 ? 1 : 0;
    MacadeEmbeddedPublishFrame(data, static_cast<int>(width), static_cast<int>(height), static_cast<int>(pitch), bytesPerPixel, isRGB565);
}

void audioSample(int16_t left, int16_t right)
{
    if (!suppressVideo) {
        MacadeSnes9xAudioWriteSample(left, right);
    }
}

size_t audioSampleBatch(const int16_t *samples, size_t frames)
{
    if (!suppressVideo) {
        MacadeSnes9xAudioWriteBatch(samples, frames);
    }
    return frames;
}

void inputPoll()
{
    MacadeEmbeddedPumpInput();
}

int16_t inputState(unsigned port, unsigned device, unsigned, unsigned id)
{
    if (device != RETRO_DEVICE_JOYPAD) {
        return 0;
    }

    if (MacadeSnes9xQuarkActive()) {
        const auto &inputs = MacadeSnes9xQuarkInputs();
        if (port >= inputs.size()) {
            return 0;
        }
        return (inputs[port] & bitForRetroID(id)) ? 1 : 0;
    }

    if (port != 0) {
        return 0;
    }

    return localButtonPressed(id) ? 1 : 0;
}

void configureDirectories()
{
    const char *runtime = std::getenv("MACADE_FIGHTCADE_RUNTIME");
    if (runtime && runtime[0]) {
        systemDirectory = runtime;
        saveDirectory = runtime;
    }
}

void printUsage(const char *executable)
{
    std::fprintf(stderr, "usage: %s <game-id|macade:training,game-id|rom-path>\n", executable);
}

} // namespace

int main(int argc, char **argv)
{
    if (argc < 2 || argv[1] == nullptr || argv[1][0] == 0) {
        printUsage(argv[0]);
        return kExitUsage;
    }

    if (!MacadeEmbeddedEnabled()) {
        std::fprintf(stderr, "This Snes9x runner requires a Macade embedded session.\n");
        return kExitUnsupported;
    }

    const std::string command = argv[1];
    configureDirectories();
    std::signal(SIGINT, handleSignal);
    std::signal(SIGTERM, handleSignal);

    retro_set_environment(environmentCallback);
    retro_set_video_refresh(videoRefresh);
    retro_set_audio_sample(audioSample);
    retro_set_audio_sample_batch(audioSampleBatch);
    retro_set_input_poll(inputPoll);
    retro_set_input_state(inputState);
    retro_init();
    MacadeSnes9xQuarkConfigure({ loadRomForGame, localJoypadBits, setRollbackMode });

    const bool quarkCommand = startsWith(command, "quark:");
    if (quarkCommand) {
        if (!MacadeSnes9xQuarkStart(command)) {
            std::fprintf(stderr, "Snes9x failed to start native GGPO session: %s\n", command.c_str());
            retro_deinit();
            MacadeEmbeddedShutdown();
            return kExitUnsupported;
        }
    } else if (!loadRomForGame(resolveGameArgument(command))) {
        retro_deinit();
        MacadeEmbeddedShutdown();
        return kExitRom;
    }

    retro_system_av_info avInfo {};
    if (gameLoaded) {
        retro_get_system_av_info(&avInfo);
    }
    const double fps = avInfo.timing.fps > 1.0 ? avInfo.timing.fps : 60.0;
    const auto frameDuration = std::chrono::duration<double>(1.0 / fps);
    auto nextFrame = std::chrono::steady_clock::now();

    while (!stopRequested) {
        if (MacadeSnes9xQuarkActive()) {
            if (!gameLoaded) {
                MacadeSnes9xQuarkIdle(16);
                std::this_thread::sleep_for(std::chrono::milliseconds(16));
                continue;
            }
            if (!MacadeSnes9xQuarkSynchronizeInput()) {
                MacadeSnes9xQuarkIdle(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                continue;
            }
        }

        retro_run();
        if (MacadeSnes9xQuarkActive()) {
            MacadeSnes9xQuarkAdvanceFrame();
            MacadeSnes9xQuarkIdle(0);
        }
        nextFrame += std::chrono::duration_cast<std::chrono::steady_clock::duration>(frameDuration);
        std::this_thread::sleep_until(nextFrame);
        if (std::chrono::steady_clock::now() > nextFrame + std::chrono::seconds(1)) {
            nextFrame = std::chrono::steady_clock::now();
        }
    }

    MacadeSnes9xQuarkStop();
    if (gameLoaded) {
        retro_unload_game();
    }
    MacadeSnes9xAudioStop();
    retro_deinit();
    MacadeEmbeddedShutdown();
    return 0;
}
