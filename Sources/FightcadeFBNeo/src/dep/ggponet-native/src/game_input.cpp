#include "game_input.hpp"

#include "logging.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace ggponet::reconstructed {
namespace {

void assert_or_exit(bool condition, const char *expression, int line)
{
   if (!condition) {
      std::fprintf(stderr, "Assertion: %s @ ..\\source\\game_input.cpp:%d\n", expression, line);
      std::exit(1);
   }
}

} // namespace

void game_input_construct(GameInput *input, int frame, const void *data, size_t size)
{
   assert_or_exit(size != 0, "isize", 0x1a);
   assert_or_exit(size <= kGameInputMaxBytes, "isize <= GAMEINPUT_MAX_BYTES * GAMEINPUT_MAX_PLAYERS", 0x1b);
   input->frame = frame;
   input->size = static_cast<int>(size);
   std::memset(input->bits, 0, sizeof(input->bits));
   std::memset(input->padding, 0, sizeof(input->padding));
   if (data != nullptr) {
      std::memcpy(input->bits, data, size);
   }
}

void game_input_construct_local(GameInput *input, int frame, const void *data, size_t input_size, int players,
                                int player_index)
{
   assert_or_exit(input_size != 0, "isize", 0x0c);
   assert_or_exit(input_size <= kSinglePlayerInputMaxBytes, "isize <= GAMEINPUT_MAX_BYTES", 0x0d);
   assert_or_exit(players <= kGameInputMaxPlayers, "players <= GAMEINPUT_MAX_PLAYERS", 0x0e);
   input->frame = frame;
   input->size = static_cast<int>(input_size * static_cast<size_t>(players));
   std::memset(input->bits, 0, sizeof(input->bits));
   std::memset(input->padding, 0, sizeof(input->padding));
   if (data != nullptr) {
      std::memcpy(input->bits + player_index * input_size, data, input_size);
   }
}

void game_input_or(GameInput *input, const GameInput *other)
{
   assert_or_exit(input->size != 0, "size", 0x45);
   for (int i = 0; i < input->size; ++i) {
      input->bits[i] = static_cast<unsigned char>(input->bits[i] | other->bits[i]);
   }
}

bool game_input_equal(const GameInput *input, const GameInput *other, bool ignore_frame)
{
   if (!ignore_frame && input->frame != other->frame) {
      quark_log("frames don't match: %d, %d\n", input->frame, other->frame);
   }
   if (input->size != other->size) {
      quark_log("sizes don't match: %d, %d\n", input->size, other->size);
   }
   if (std::memcmp(input->bits, other->bits, static_cast<size_t>(input->size)) != 0) {
      quark_log("bits don't match\n");
   }
   assert_or_exit(input->size != 0 && other->size != 0, "size && other.size", 0x57);
   return (ignore_frame || input->frame == other->frame) && input->size == other->size &&
          std::memcmp(input->bits, other->bits, static_cast<size_t>(input->size)) == 0;
}

bool game_input_bit(const GameInput *input, unsigned int bit)
{
   return (input->bits[bit / 8] & (1U << (bit % 8))) != 0;
}

void game_input_to_string(const GameInput *input, char *destination, size_t destination_size, bool include_frame)
{
   assert_or_exit(input->size != 0, "size", 0x27);
   if (include_frame) {
      std::snprintf(destination, destination_size, "(frame:%d size:%d ", input->frame, input->size);
   } else {
      std::snprintf(destination, destination_size, "(size:%d ", input->size);
   }
   for (int bit = 0; bit < input->size * 8; ++bit) {
      if (game_input_bit(input, static_cast<unsigned int>(bit))) {
         char text[16];
         std::snprintf(text, sizeof(text), "%2d ", bit);
         std::strncat(destination, text, destination_size - std::strlen(destination) - 1);
      }
   }
   std::strncat(destination, ")", destination_size - std::strlen(destination) - 1);
}

void game_input_log(const GameInput *input, const char *prefix, bool include_frame)
{
   char buffer[1028];
   std::strcpy(buffer, prefix);
   const size_t used = std::strlen(buffer);
   game_input_to_string(input, buffer + used, sizeof(buffer) - used, include_frame);
   std::strcat(buffer, "\n");
   quark_log("%s", buffer);
}

}
