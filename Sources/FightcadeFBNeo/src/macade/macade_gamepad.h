#pragma once
void MacadeGamepadPoll();
void MacadeGamepadClose();
bool MacadeGamepadOwnsInput(unsigned int index);
void MacadeGamepadApply(bool copy);
bool MacadeGamepadPlayerOneOnly();
void MacadeGamepadIsolatePlayerOne(bool copy);
// Returns -1 for an ordinary emulator launch, otherwise a helper's exit status.
int MacadeGamepadCommand(int argc, char** argv);

int MacadeGamepadInputPlayer(const struct BurnInputInfo& info);
