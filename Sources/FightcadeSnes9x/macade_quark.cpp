#include "macade_quark.h"

#include "ggpoclient.h"
#include "ggponet.h"
#include "libretro.h"
#include "snapshot.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace {

constexpr int kGGPOStateHeaderSize = 4 * sizeof(int);
constexpr int kGGPOStateMagic = ('G' << 24) | ('G' << 16) | ('P' << 8) | 'O';
constexpr int kInputSyncFailureLogThreshold = 60;
constexpr int kInputSyncFailureLogInterval = 300;

GGPOSession *ggpoSession = nullptr;
MacadeSnes9xQuarkHost host {};
std::array<uint32_t, 8> networkInputs {};
int inputSyncFailureCount = 0;

bool startsWith(const std::string &value, const char *prefix)
{
    const size_t length = std::strlen(prefix);
    return value.size() >= length && value.compare(0, length, prefix) == 0;
}

void recordInputSyncFailure(const char *reason)
{
    ++inputSyncFailureCount;
    if (inputSyncFailureCount == kInputSyncFailureLogThreshold ||
        (inputSyncFailureCount > kInputSyncFailureLogThreshold && inputSyncFailureCount % kInputSyncFailureLogInterval == 0)) {
        std::fprintf(stderr, "Snes9x GGPO input sync failed %d consecutive times: %s\n", inputSyncFailureCount, reason);
    }
}

void clearInputSyncFailures()
{
    inputSyncFailureCount = 0;
}

void recordInputSyncSuccess()
{
    if (inputSyncFailureCount >= kInputSyncFailureLogThreshold) {
        std::fprintf(stderr, "Snes9x GGPO input sync recovered after %d failed attempts.\n", inputSyncFailureCount);
    }
    inputSyncFailureCount = 0;
}

bool ggpoBeginGameCallback(char *name)
{
    if (name == nullptr || name[0] == 0) {
        std::fprintf(stderr, "Snes9x GGPO begin_game failed: missing game name.\n");
        return false;
    }
    if (host.loadGame == nullptr) {
        std::fprintf(stderr, "Snes9x GGPO begin_game failed for '%s': no ROM loader configured.\n", name);
        return false;
    }
    if (!host.loadGame(name)) {
        std::fprintf(stderr, "Snes9x GGPO begin_game failed to load ROM for '%s'.\n", name);
        return false;
    }
    return true;
}

bool ggpoAdvanceFrameCallback(int)
{
    if (!MacadeSnes9xQuarkSynchronizeInput()) {
        return false;
    }

    if (host.setRollbackMode != nullptr) {
        host.setRollbackMode(true);
    }
    retro_run();
    if (host.setRollbackMode != nullptr) {
        host.setRollbackMode(false);
    }
    return MacadeSnes9xQuarkAdvanceFrame();
}

bool ggpoSaveGameStateCallback(unsigned char **buffer, int *len, int *checksum, int)
{
    if (buffer == nullptr || len == nullptr || checksum == nullptr) {
        std::fprintf(stderr, "Snes9x GGPO save-state failed: invalid callback storage.\n");
        return false;
    }

    *buffer = nullptr;
    *len = 0;
    *checksum = 0;

    const uint32 payloadSize = S9xFreezeSize();
    *len = static_cast<int>(payloadSize) + kGGPOStateHeaderSize;
    *buffer = static_cast<unsigned char *>(std::malloc(*len));
    if (*buffer == nullptr) {
        *len = 0;
        std::fprintf(stderr, "Snes9x GGPO save-state failed: could not allocate %d bytes.\n", static_cast<int>(payloadSize) + kGGPOStateHeaderSize);
        return false;
    }

    int *header = reinterpret_cast<int *>(*buffer);
    header[0] = kGGPOStateMagic;
    header[1] = kGGPOStateHeaderSize;
    header[2] = 0;
    header[3] = 0;
    if (S9xFreezeGameMem(*buffer + kGGPOStateHeaderSize, payloadSize) == FALSE) {
        std::free(*buffer);
        *buffer = nullptr;
        *len = 0;
        std::fprintf(stderr, "Snes9x GGPO save-state failed: S9xFreezeGameMem rejected %u bytes.\n", payloadSize);
    }
    return false;
}

bool ggpoLoadGameStateCallback(unsigned char *buffer, int len)
{
    if (buffer == nullptr || len <= 0) {
        std::fprintf(stderr, "Snes9x GGPO load-state failed: empty state buffer.\n");
        return false;
    }

    int payloadLength = len;
    if (len >= kGGPOStateHeaderSize) {
        int *header = reinterpret_cast<int *>(buffer);
        if (header[0] == kGGPOStateMagic) {
            if (header[1] <= 0 || header[1] > len) {
                std::fprintf(stderr, "Snes9x GGPO load-state failed: invalid GGPO header size %d for %d bytes.\n", header[1], len);
                return false;
            }
            buffer += header[1];
            payloadLength -= header[1];
        }
    }

    const bool loaded = S9xUnfreezeGameMem(buffer, static_cast<uint32>(payloadLength)) == SUCCESS;
    if (!loaded) {
        std::fprintf(stderr, "Snes9x GGPO load-state failed: S9xUnfreezeGameMem rejected %d bytes.\n", payloadLength);
    }
    return loaded;
}

bool ggpoLogGameStateCallback(char *, unsigned char *buffer, int len)
{
    return ggpoLoadGameStateCallback(buffer, len);
}

void ggpoFreeBufferCallback(void *buffer)
{
    std::free(buffer);
}

bool ggpoEventCallback(GGPOEvent *)
{
    return true;
}

GGPOSessionCallbacks makeCallbacks()
{
    GGPOSessionCallbacks callbacks {};
    callbacks.begin_game = ggpoBeginGameCallback;
    callbacks.save_game_state = ggpoSaveGameStateCallback;
    callbacks.load_game_state = ggpoLoadGameStateCallback;
    callbacks.log_game_state = ggpoLogGameStateCallback;
    callbacks.free_buffer = ggpoFreeBufferCallback;
    callbacks.advance_frame = ggpoAdvanceFrameCallback;
    callbacks.on_event = ggpoEventCallback;
    return callbacks;
}

} // namespace

void MacadeSnes9xQuarkConfigure(MacadeSnes9xQuarkHost configuredHost)
{
    host = configuredHost;
}

bool MacadeSnes9xQuarkStart(const std::string &connect)
{
    char game[128] = {};
    char quarkID[128] = {};
    char server[128] = {};
    int port = 0;
    int delay = 0;
    int ranked = 0;
    int player = 0;
    int localPort = 0;
    int remotePort = 0;
    const char *route = nullptr;
    GGPOSessionCallbacks callbacks = makeCallbacks();

    ggpoSession = nullptr;
    networkInputs.fill(0);
    clearInputSyncFailures();

    if (startsWith(connect, "quark:served")) {
        if (std::sscanf(connect.c_str(), "quark:served,%127[^,],%127[^,],%d,%d,%d", game, quarkID, &port, &delay, &ranked) < 4) {
            std::fprintf(stderr, "Failed to parse Snes9x GGPO served command: %s\n", connect.c_str());
            return false;
        }
        route = "served";
        std::fprintf(stderr, "Snes9x GGPO route parsed: served game=%s quark=%s port=%d delay=%d ranked=%d\n", game, quarkID, port, delay, ranked);
        ggpoSession = ggpo_client_connect(&callbacks, game, quarkID, port);
    } else if (startsWith(connect, "quark:direct")) {
        if (std::sscanf(connect.c_str(), "quark:direct,%127[^,],%d,%127[^,],%d,%d,%d,%d", game, &localPort, server, &remotePort, &player, &delay, &ranked) < 6) {
            std::fprintf(stderr, "Failed to parse Snes9x GGPO direct command: %s\n", connect.c_str());
            return false;
        }
        route = "direct";
        std::fprintf(stderr, "Snes9x GGPO route parsed: direct game=%s local=%d remote=%s:%d player=%d delay=%d ranked=%d\n", game, localPort, server, remotePort, player, delay, ranked);
        ggpoSession = ggpo_start_session(&callbacks, game, localPort, server, remotePort, player);
    } else if (startsWith(connect, "quark:stream")) {
        if (std::sscanf(connect.c_str(), "quark:stream,%127[^,],%127[^,],%d", game, quarkID, &remotePort) != 3) {
            std::fprintf(stderr, "Failed to parse Snes9x GGPO stream command: %s\n", connect.c_str());
            return false;
        }
        route = "stream";
        std::fprintf(stderr, "Snes9x GGPO route parsed: stream game=%s quark=%s port=%d\n", game, quarkID, remotePort);
        ggpoSession = ggpo_start_streaming(&callbacks, game, quarkID, remotePort);
    } else if (startsWith(connect, "quark:replay,")) {
        route = "replay";
        std::fprintf(stderr, "Snes9x GGPO route parsed: replay path=%s\n", connect.c_str() + std::strlen("quark:replay,"));
        ggpoSession = ggpo_start_replay(&callbacks, const_cast<char *>(connect.c_str() + std::strlen("quark:replay,")));
    } else {
        std::fprintf(stderr, "Unsupported Snes9x quark command: %s\n", connect.c_str());
        return false;
    }

    if (ggpoSession == nullptr) {
        std::fprintf(stderr, "Snes9x GGPO session creation failed for %s route.\n", route != nullptr ? route : "unknown");
        return false;
    }
    ggpo_set_frame_delay(ggpoSession, delay);
    std::fprintf(stderr, "Snes9x GGPO session started: route=%s delay=%d\n", route != nullptr ? route : "unknown", delay);
    return true;
}

void MacadeSnes9xQuarkStop()
{
    if (ggpoSession != nullptr) {
        ggpo_close_session(ggpoSession);
        ggpoSession = nullptr;
    }
    clearInputSyncFailures();
}

bool MacadeSnes9xQuarkActive()
{
    return ggpoSession != nullptr;
}

bool MacadeSnes9xQuarkSynchronizeInput()
{
    if (ggpoSession == nullptr || host.localJoypadBits == nullptr) {
        recordInputSyncFailure(ggpoSession == nullptr ? "no active session" : "no local input callback");
        return false;
    }

    networkInputs.fill(0);
    networkInputs[0] = host.localJoypadBits();
    if (!ggpo_synchronize_input(ggpoSession, networkInputs.data(), sizeof(uint32_t), static_cast<int>(networkInputs.size()))) {
        recordInputSyncFailure("ggpo_synchronize_input returned false");
        return false;
    }

    recordInputSyncSuccess();
    return true;
}

bool MacadeSnes9xQuarkAdvanceFrame()
{
    return ggpoSession != nullptr && ggpo_advance_frame(ggpoSession);
}

void MacadeSnes9xQuarkIdle(int milliseconds)
{
    if (ggpoSession != nullptr) {
        ggpo_idle(ggpoSession, milliseconds);
    }
}

const std::array<uint32_t, 8> &MacadeSnes9xQuarkInputs()
{
    return networkInputs;
}
