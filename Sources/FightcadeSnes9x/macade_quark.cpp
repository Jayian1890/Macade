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

GGPOSession *ggpoSession = nullptr;
MacadeSnes9xQuarkHost host {};
std::array<uint32_t, 8> networkInputs {};

bool startsWith(const std::string &value, const char *prefix)
{
    const size_t length = std::strlen(prefix);
    return value.size() >= length && value.compare(0, length, prefix) == 0;
}

bool ggpoBeginGameCallback(char *name)
{
    return name != nullptr && host.loadGame != nullptr && host.loadGame(name);
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
    const uint32 payloadSize = S9xFreezeSize();
    *len = static_cast<int>(payloadSize) + kGGPOStateHeaderSize;
    *checksum = 0;
    *buffer = static_cast<unsigned char *>(std::malloc(*len));
    if (*buffer == nullptr) {
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
    }
    return false;
}

bool ggpoLoadGameStateCallback(unsigned char *buffer, int len)
{
    if (buffer == nullptr || len <= 0) {
        return false;
    }

    int payloadLength = len;
    if (len >= kGGPOStateHeaderSize) {
        int *header = reinterpret_cast<int *>(buffer);
        if (header[0] == kGGPOStateMagic && header[1] > 0 && header[1] <= len) {
            buffer += header[1];
            payloadLength -= header[1];
        }
    }
    return S9xUnfreezeGameMem(buffer, static_cast<uint32>(payloadLength)) == SUCCESS;
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
    GGPOSessionCallbacks callbacks = makeCallbacks();

    if (startsWith(connect, "quark:served")) {
        if (std::sscanf(connect.c_str(), "quark:served,%127[^,],%127[^,],%d,%d,%d", game, quarkID, &port, &delay, &ranked) < 4) {
            return false;
        }
        ggpoSession = ggpo_client_connect(&callbacks, game, quarkID, port);
    } else if (startsWith(connect, "quark:direct")) {
        if (std::sscanf(connect.c_str(), "quark:direct,%127[^,],%d,%127[^,],%d,%d,%d,%d", game, &localPort, server, &remotePort, &player, &delay, &ranked) < 6) {
            return false;
        }
        ggpoSession = ggpo_start_session(&callbacks, game, localPort, server, remotePort, player);
    } else if (startsWith(connect, "quark:stream")) {
        if (std::sscanf(connect.c_str(), "quark:stream,%127[^,],%127[^,],%d", game, quarkID, &remotePort) != 3) {
            return false;
        }
        ggpoSession = ggpo_start_streaming(&callbacks, game, quarkID, remotePort);
    } else if (startsWith(connect, "quark:replay,")) {
        ggpoSession = ggpo_start_replay(&callbacks, const_cast<char *>(connect.c_str() + std::strlen("quark:replay,")));
    } else {
        std::fprintf(stderr, "Unsupported Snes9x quark command: %s\n", connect.c_str());
        return false;
    }

    if (ggpoSession == nullptr) {
        return false;
    }
    ggpo_set_frame_delay(ggpoSession, delay);
    return true;
}

void MacadeSnes9xQuarkStop()
{
    if (ggpoSession != nullptr) {
        ggpo_close_session(ggpoSession);
        ggpoSession = nullptr;
    }
}

bool MacadeSnes9xQuarkActive()
{
    return ggpoSession != nullptr;
}

bool MacadeSnes9xQuarkSynchronizeInput()
{
    if (ggpoSession == nullptr || host.localJoypadBits == nullptr) {
        return false;
    }

    networkInputs.fill(0);
    networkInputs[0] = host.localJoypadBits();
    return ggpo_synchronize_input(ggpoSession, networkInputs.data(), sizeof(uint32_t), static_cast<int>(networkInputs.size()));
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
