#pragma once

#include <SDL.h>

void MacadeOverlayReset();
void MacadeOverlaySetSession(int spectator, int ranked, int player);
void MacadeOverlaySetGameInfo(const char* player1, const char* player2, int spectator, int ranked, int player);
void MacadeOverlaySetScores(int player1Score, int player2Score);
void MacadeOverlayGetScores(int* player1Score, int* player2Score);
void MacadeOverlaySetSpectators(int count);
void MacadeOverlaySetSystemMessage(const char* message);
void MacadeOverlaySetChatInput(const char* text, int active);
void MacadeOverlayAddChatLine(const char* name, const char* text);
void MacadeOverlaySetStats(double fps, int ping, int delay);
void MacadeOverlayRender(SDL_Renderer* renderer);
