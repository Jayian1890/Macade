#pragma once

#include <cstddef>
#include <cstdint>

bool MacadeSnes9xAudioStart(double sampleRate);
void MacadeSnes9xAudioStop();
void MacadeSnes9xAudioWriteSample(int16_t left, int16_t right);
void MacadeSnes9xAudioWriteBatch(const int16_t *samples, size_t frames);
