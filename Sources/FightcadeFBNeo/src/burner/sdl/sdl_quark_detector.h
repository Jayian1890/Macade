#pragma once

void DetectorLoad(const char *game, bool debug, int seed);
void DetectorUpdate();
void DetectorSetGameInfo(int spectator, int ranked);
void DetectorSetState(int state, int score1, int score2, int start1, int start2);
void DetectorGetState(int &state, int &score1, int &score2, int &start1, int &start2);
