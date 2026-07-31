#pragma once

bool MacadeEmbeddedEnabled();
bool MacadeEmbeddedWindowHidden();
void MacadeEmbeddedShutdown();
void MacadeEmbeddedPumpInput();
void MacadeEmbeddedPublishFrame(const void* pixels, int width, int height, int pitch, int bytesPerPixel, int isRGB565);

extern "C" int MacadeEmbeddedKeyState(int scancode);
