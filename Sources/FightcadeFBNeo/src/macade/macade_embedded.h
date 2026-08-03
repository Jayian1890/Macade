#pragma once

bool MacadeEmbeddedEnabled();
bool MacadeEmbeddedWindowHidden();
void MacadeEmbeddedShutdown();
void MacadeEmbeddedPumpInput();
void MacadeEmbeddedPublishFrame(const void* pixels, int width, int height, int pitch, int bytesPerPixel, int isRGB565);
void MacadeEmbeddedSetOverlayConnectionPhase(int phase);
void MacadeEmbeddedSetOverlaySystemMessage(const char* message, int frames);
void MacadeEmbeddedSetOverlayGameInfo(const char* player1, const char* player2, int spectator, int ranked, int player);
void MacadeEmbeddedSetOverlayScores(int score1, int score2);
void MacadeEmbeddedSetOverlaySpectators(int spectators);
void MacadeEmbeddedSetOverlayStats(int ping, int delay);
void MacadeEmbeddedSetOverlayMatchEnded();
void MacadeEmbeddedAddOverlayChatLine(const char* name, const char* text);
void MacadeEmbeddedSetReplayStatus(int currentFrame, int totalFrames, int bufferedFrames, int seekable, int paused, int fastForwarding);
int MacadeEmbeddedConsumeChatSubmit(char* text, int size);

extern "C" int MacadeEmbeddedKeyState(int scancode);
