#pragma once
#include <SDL.h>
#include <string>
#include <vector>

struct MacadePadControl {
    char kind = 'b'; // button, signed axis direction, hat bit, full analog axis
    int index = 0;
    int direction = 0;
};
struct MacadePadDevice {
    SDL_Joystick* joystick = nullptr;
    SDL_JoystickID instance = -1;
    std::string id;
    std::string name;
    bool hasSerial = false;
};
class MacadePadDevices {
public:
    ~MacadePadDevices();
    void poll();
    void close();
    const std::vector<MacadePadDevice>& devices() const { return pads; }
    int state(const std::string& device, const MacadePadControl& control) const;
    std::string snapshot() const;
private:
    std::vector<MacadePadDevice> pads;
};
std::string MacadePadHex(const char* text);
std::string MacadePadJSON(const std::string& text);
