#pragma once

struct SDL_Renderer;

bool MacadeEmbeddedEnabled();
bool MacadeEmbeddedWindowHidden();
void MacadeEmbeddedShutdown();
void MacadeEmbeddedPumpInput();
void MacadeEmbeddedPublishFrame(const void* pixels, int width, int height, int pitch, int bytesPerPixel, int isRGB565);
void MacadeEmbeddedPublishRendererFrame(SDL_Renderer* renderer, int width, int height);

extern "C" int MacadeEmbeddedKeyState(int scancode);
