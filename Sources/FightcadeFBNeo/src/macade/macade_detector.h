#pragma once

void MacadeDetectorLoad(const char* game, bool debug, int seed);
void MacadeDetectorUpdate();
void MacadeDetectorSetState(int state, int score1, int score2, int start1 = 0, int start2 = 0);
void MacadeDetectorGetState(int& state, int& score1, int& score2, int& start1, int& start2);
