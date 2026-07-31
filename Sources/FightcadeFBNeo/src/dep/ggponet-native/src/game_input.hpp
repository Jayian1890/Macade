#pragma once

#include <cstddef>

namespace ggponet::reconstructed {

constexpr int kGameInputMaxBytes = 0x12;
constexpr int kGameInputMaxPlayers = 2;
constexpr int kSinglePlayerInputMaxBytes = 9;

struct GameInput {
   int frame;
   int size;
   unsigned char bits[kGameInputMaxBytes];
   unsigned char padding[2];
};

static_assert(sizeof(GameInput) == 0x1c);

void game_input_construct(GameInput *input, int frame, const void *data, size_t size);
void game_input_construct_local(GameInput *input, int frame, const void *data, size_t input_size, int players,
                                int player_index);
void game_input_or(GameInput *input, const GameInput *other);
bool game_input_equal(const GameInput *input, const GameInput *other, bool ignore_frame);
bool game_input_bit(const GameInput *input, unsigned int bit);
void game_input_to_string(const GameInput *input, char *destination, size_t destination_size, bool include_frame);
void game_input_log(const GameInput *input, const char *prefix, bool include_frame);

}
