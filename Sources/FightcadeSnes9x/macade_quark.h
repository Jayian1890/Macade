#pragma once

#include <array>
#include <cstdint>
#include <string>

struct MacadeSnes9xQuarkHost {
    bool (*loadGame)(const std::string &game);
    uint32_t (*localJoypadBits)();
    void (*setRollbackMode)(bool enabled);
};

void MacadeSnes9xQuarkConfigure(MacadeSnes9xQuarkHost host);
bool MacadeSnes9xQuarkStart(const std::string &connect);
void MacadeSnes9xQuarkStop();
bool MacadeSnes9xQuarkActive();
bool MacadeSnes9xQuarkSynchronizeInput();
bool MacadeSnes9xQuarkAdvanceFrame();
void MacadeSnes9xQuarkIdle(int milliseconds);
const std::array<uint32_t, 8> &MacadeSnes9xQuarkInputs();
