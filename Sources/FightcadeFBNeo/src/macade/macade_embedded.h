#pragma once

struct SDL_Renderer;

struct MacadeEmbeddedOverlayPlayer {
	char name[128];
	char country[16];
	int rank;
	int score;
};

struct MacadeEmbeddedOverlayChatLine {
	char name[128];
	char text[256];
};

struct MacadeEmbeddedOverlayState {
	int enabled;
	int spectator;
	int ranked;
	int player;
	int spectators;
	int ping;
	int delay;
	int systemFrames;
	int chatFrames;
	int chatInputActive;
	char systemMessage[160];
	char chatInput[160];
	MacadeEmbeddedOverlayChatLine chatLines[7];
	MacadeEmbeddedOverlayPlayer players[2];
};

bool MacadeEmbeddedEnabled();
bool MacadeEmbeddedWindowHidden();
void MacadeEmbeddedShutdown();
void MacadeEmbeddedPumpInput();
void MacadeEmbeddedPublishFrame(const void* pixels, int width, int height, int pitch, int bytesPerPixel, int isRGB565);
void MacadeEmbeddedPublishOverlay(const MacadeEmbeddedOverlayState* state);
void MacadeEmbeddedPublishRendererFrame(SDL_Renderer* renderer, int width, int height);

extern "C" int MacadeEmbeddedKeyState(int scancode);
