#include "burner.h"
#include "macade_gamepad.h"
#include "macade_gamepad_devices.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

int MacadeGamepadInputPlayer(const BurnInputInfo& info)
{
    auto player = [](const char* label) {
        return label && (label[0] == 'P' || label[0] == 'p') && label[1] >= '1' && label[1] <= '4'
            ? label[1] - '0' : 0;
    };
    int named = player(info.szName);
    int hinted = player(info.szInfo);
    // Mirror GameInpInit's treatment of older drivers with inconsistent names.
    return hinted && named <= 1 ? hinted : named;
}

namespace {
struct Binding {
    std::string device, game, info;
    unsigned int input;
    int player;
    MacadePadControl control;
};
MacadePadDevices devices;
std::vector<Binding> bindings;
bool loaded = false;
const Binding* bindingFor(unsigned int index)
{
    if (kNetSpectator) return nullptr;
    const char* game = BurnDrvGetTextA(DRV_NAME);
    if (!game) return nullptr;
    BurnInputInfo info{};
    if (BurnDrvGetInputInfo(&info, index)) return nullptr;
    for (const auto& binding : bindings) {
        if (binding.input == index && binding.game == game && (!kNetGame || binding.player == 1)
            && binding.info == MacadePadHex(info.szInfo) && info.szName
            && MacadeGamepadInputPlayer(info) == binding.player
            && (!kNetGame || ((info.szName[0] == 'P' || info.szName[0] == 'p') && info.szName[1] == '1'))
            && (info.nType == BIT_DIGITAL || (info.nType & BIT_GROUP_ANALOG))
            && (info.nType != BIT_DIGITAL || binding.control.kind != 'x')
            && (!(info.nType & BIT_GROUP_ANALOG) || binding.control.kind == 'x' || binding.control.kind == '-')) return &binding;
    }
    return nullptr;
}
}
void MacadeGamepadPoll()
{
    if (!loaded) {
        loaded = true;
        const char* path = getenv("MACADE_GAMEPAD_PROFILE_PATH");
        if (path) {
            std::ifstream file(path); std::string line;
            if (std::getline(file, line) && line == "MACADE_GAMEPADS 1") {
                while (bindings.size() < 4096 && std::getline(file, line)) {
                    Binding b{}; std::istringstream row(line);
                    if (!(row >> b.device >> b.game >> b.input >> b.player >> b.info
                        >> b.control.kind >> b.control.index >> b.control.direction)) continue;
                    if (b.player < 1 || b.player > 4 || b.input > 4096 || b.control.index < 0 || b.control.index > 255) continue;
                    if (std::string("bahx-").find(b.control.kind) == std::string::npos) continue;
                    if (b.control.kind == 'a' && b.control.direction != -1 && b.control.direction != 1) continue;
                    if (b.control.kind == 'h' && b.control.direction != 1 && b.control.direction != 2 && b.control.direction != 4 && b.control.direction != 8) continue;
                    bindings.push_back(b);
                }
            }
        }
    }
    if (!bindings.empty() && !kNetSpectator) devices.poll();
}
void MacadeGamepadClose() { devices.close(); }
bool MacadeGamepadOwnsInput(unsigned int index) { return bindingFor(index) != nullptr; }
void MacadeGamepadApply(bool copy)
{
    if (kNetSpectator) return;
    for (unsigned int i = 0; i < nGameInpCount; ++i) {
        const Binding* binding = bindingFor(i);
        if (!binding) continue;
        struct GameInp* input = &GameInp[i];
        if (!input->Input.pVal) continue;
        if (input->nType == BIT_DIGITAL) {
            if (input->nInput != 0 && input->nInput != GIT_SWITCH) continue;
            input->Input.nVal |= devices.state(binding->device, binding->control) != 0;
            if (copy) *input->Input.pVal = input->Input.nVal;
        } else if (input->nType & BIT_GROUP_ANALOG) {
            int axis = binding->control.kind == 'x' ? devices.state(binding->device, binding->control) : 0;
            int value = input->nType == BIT_ANALOG_REL ? (axis * 2 * nAnalogSpeed) >> 13 : axis + 32768;
            if (input->nType == BIT_ANALOG_REL) value = std::max(-32768, std::min(32767, value));
            else value = std::max(1, std::min(65535, value));
            input->Input.nVal = static_cast<UINT16>(value);
            if (copy) *input->Input.pShortVal = input->Input.nVal;
        }
    }
}
