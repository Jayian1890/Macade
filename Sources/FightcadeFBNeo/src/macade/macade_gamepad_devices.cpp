#include "macade_gamepad_devices.h"
#include <algorithm>
#include <map>
#include <sstream>

std::string MacadePadHex(const char* text)
{
    std::string result;
    const char* hex = "0123456789abcdef";
    if (text) for (const unsigned char* p = (const unsigned char*)text; *p; ++p) {
        result += hex[*p >> 4]; result += hex[*p & 15];
    }
    return result;
}
std::string MacadePadJSON(const std::string& text)
{
    std::string result = "\"";
    for (unsigned char c : text) {
        if (c == '"' || c == '\\') { result += '\\'; result += c; }
        else if (c < 32) {
            char escape[8]; snprintf(escape, sizeof(escape), "\\u%04x", c); result += escape;
        } else result += c;
    }
    return result + "\"";
}
MacadePadDevices::~MacadePadDevices() { close(); }
void MacadePadDevices::close()
{
    for (auto& pad : pads) SDL_JoystickClose(pad.joystick);
    pads.clear();
}
void MacadePadDevices::poll()
{
    SDL_PumpEvents();
    pads.erase(std::remove_if(pads.begin(), pads.end(), [](const MacadePadDevice& pad) {
        if (SDL_JoystickGetAttached(pad.joystick)) return false;
        SDL_JoystickClose(pad.joystick); return true;
    }), pads.end());
    for (int index = 0; index < SDL_NumJoysticks() && pads.size() < 16; ++index) {
        SDL_JoystickID instance = SDL_JoystickGetDeviceInstanceID(index);
        if (std::any_of(pads.begin(), pads.end(), [instance](const MacadePadDevice& pad) {
            return pad.instance == instance;
        })) continue;
        SDL_Joystick* joystick = SDL_JoystickOpen(index);
        if (!joystick) continue;
        char guid[33]; SDL_JoystickGetGUIDString(SDL_JoystickGetGUID(joystick), guid, sizeof(guid));
        const char* serial = SDL_JoystickGetSerial(joystick);
        std::string prefix = std::string(guid) + ":";
        bool hasSerial = serial && *serial;
        std::string id = prefix + (hasSerial ? "s" + MacadePadHex(serial) : "n0");
        if (!hasSerial) {
            int slot = 0;
            do { id = prefix + "n" + std::to_string(slot++); }
            while (std::any_of(pads.begin(), pads.end(), [&id](const MacadePadDevice& pad) { return pad.id == id; }));
        }
        const char* name = SDL_JoystickName(joystick);
        pads.push_back({joystick, instance, id, name ? name : "Unnamed controller", hasSerial});
    }
    SDL_JoystickUpdate();
}
int MacadePadDevices::state(const std::string& device, const MacadePadControl& control) const
{
    auto found = std::find_if(pads.begin(), pads.end(), [&device](const MacadePadDevice& pad) { return pad.id == device; });
    if (found == pads.end() || control.index < 0 || !SDL_JoystickGetAttached(found->joystick)) return 0;
    SDL_Joystick* joy = found->joystick;
    if (control.kind == 'b' && control.index < SDL_JoystickNumButtons(joy))
        return SDL_JoystickGetButton(joy, control.index) != 0;
    if (control.kind == 'h' && control.index < SDL_JoystickNumHats(joy))
        return (SDL_JoystickGetHat(joy, control.index) & control.direction) != 0;
    if ((control.kind == 'a' || control.kind == 'x') && control.index < SDL_JoystickNumAxes(joy)) {
        int axis = SDL_JoystickGetAxis(joy, control.index);
        if (control.kind == 'x') return std::abs(axis) <= 8000 ? 0 : axis;
        return control.direction < 0 ? axis < -16000 : axis > 16000;
    }
    return 0;
}
std::string MacadePadDevices::snapshot() const
{
    std::ostringstream out; out << "{\"devices\":[";
    bool firstPad = true;
    for (const auto& pad : pads) {
        if (!firstPad) out << ','; firstPad = false;
        out << "{\"id\":" << MacadePadJSON(pad.id) << ",\"name\":" << MacadePadJSON(pad.name)
            << ",\"hasSerial\":" << (pad.hasSerial ? "true" : "false") << ",\"controls\":[";
        bool firstControl = true;
        auto emit = [&](char kind, int index, int direction) {
            if (!firstControl) out << ','; firstControl = false;
            out << "{\"kind\":\"" << kind << "\",\"index\":" << index << ",\"direction\":" << direction << '}';
        };
        for (int i = 0; i < SDL_JoystickNumButtons(pad.joystick); ++i)
            if (state(pad.id, {'b', i, 0})) emit('b', i, 0);
        for (int i = 0; i < SDL_JoystickNumHats(pad.joystick); ++i)
            for (int bit : {1, 2, 4, 8}) if (state(pad.id, {'h', i, bit})) emit('h', i, bit);
        for (int i = 0; i < SDL_JoystickNumAxes(pad.joystick); ++i)
            for (int sign : {-1, 1}) if (state(pad.id, {'a', i, sign})) emit('a', i, sign);
        out << "],\"axes\":[";
        for (int i = 0; i < SDL_JoystickNumAxes(pad.joystick); ++i) {
            if (i) out << ','; out << SDL_JoystickGetAxis(pad.joystick, i);
        }
        out << "],\"initialAxes\":[";
        for (int i = 0; i < SDL_JoystickNumAxes(pad.joystick); ++i) {
            Sint16 initial = 0;
            SDL_JoystickGetAxisInitialState(pad.joystick, i, &initial);
            if (i) out << ','; out << initial;
        }
        out << "]}";
    }
    return out.str() + "]}";
}
