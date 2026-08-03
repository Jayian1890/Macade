#include "replay_backend.hpp"

#include "logging.hpp"

#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <thread>
#include <vector>
#include <zlib.h>

namespace ggponet::reconstructed {
namespace {

constexpr int kGameInputMaxBytes = 0x12;

struct GameInputRecord {
   int frame;
   int size;
   unsigned char bits[kGameInputMaxBytes];
   unsigned char padding[2];
};

static_assert(sizeof(GameInputRecord) == 0x1c);

struct ReplayInputQueue {
   void *reserved[2];
   GameInputRecord **blocks;
   unsigned int map_size;
   unsigned int first;
   unsigned int count;
};

struct ReplayBackend {
   const GGPOSessionVTable *vtable;
   GGPOSessionCallbacks callbacks;
   std::vector<GameInputRecord> input_history;
   std::vector<unsigned char> initial_state;
   unsigned int cursor;
};

void queue_construct(ReplayInputQueue *queue)
{
   std::memset(queue, 0, sizeof(*queue));
}

void queue_grow(ReplayInputQueue *queue, unsigned int minimum_extra)
{
   unsigned int extra = queue->map_size / 2;
   if (extra < 8) {
      extra = 8;
   }
   if (extra < minimum_extra) {
      extra = minimum_extra;
   }

   const unsigned int new_size = queue->map_size + extra;
   auto **new_blocks = static_cast<GameInputRecord **>(std::calloc(new_size, sizeof(GameInputRecord *)));
   if (new_blocks == nullptr) {
      std::abort();
   }

   for (unsigned int i = 0; i < queue->count; ++i) {
      if (queue->map_size != 0) {
         new_blocks[i] = queue->blocks[(queue->first + i) % queue->map_size];
      }
   }

   std::free(queue->blocks);
   queue->blocks = new_blocks;
   queue->map_size = new_size;
   queue->first = 0;
}

void queue_push(ReplayInputQueue *queue, const GameInputRecord *input)
{
   if (queue->map_size <= queue->count + 1U) {
      queue_grow(queue, 1);
   }

   const unsigned int index = (queue->first + queue->count) % queue->map_size;
   if (queue->blocks[index] == nullptr) {
      queue->blocks[index] = static_cast<GameInputRecord *>(std::malloc(sizeof(GameInputRecord)));
      if (queue->blocks[index] == nullptr) {
         std::abort();
      }
   }

   std::memcpy(queue->blocks[index], input, sizeof(GameInputRecord));
   ++queue->count;
}

GameInputRecord *queue_front(ReplayInputQueue *queue)
{
   if (queue->count == 0 || queue->map_size == 0) {
      return nullptr;
   }
   return queue->blocks[queue->first];
}

void queue_pop(ReplayInputQueue *queue)
{
   if (queue->count == 0 || queue->map_size == 0) {
      return;
   }

   ++queue->first;
   if (queue->map_size <= queue->first) {
      queue->first = 0;
   }
   --queue->count;
   if (queue->count == 0) {
      queue->first = 0;
   }
}

void game_input_construct(GameInputRecord *input, int frame, const void *data, int size)
{
   if (size == 0 || size > kGameInputMaxBytes) {
      std::fprintf(stderr, "GGPO Assertion Failed: input size %d is out of range\n", size);
      std::exit(1);
   }

   input->frame = frame;
   input->size = size;
   std::memset(input->bits, 0, sizeof(input->bits));
   std::memset(input->padding, 0, sizeof(input->padding));
   if (data != nullptr) {
      std::memcpy(input->bits, data, static_cast<size_t>(size));
   }
}

bool __cdecl replay_idle(GGPOSession *, int timeout)
{
   std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<unsigned int>(timeout)));
   return true;
}

bool __cdecl replay_synchronize_input(GGPOSession *session, void *values, int size, int players)
{
   auto *backend = reinterpret_cast<ReplayBackend *>(session);
   if (backend->cursor >= backend->input_history.size()) {
      return false;
   }

   const int copied_players = players < 3 ? players : 2;
   const size_t copied_size = static_cast<size_t>(size * copied_players);
   const GameInputRecord &input = backend->input_history[backend->cursor++];
   std::memcpy(values, input.bits, copied_size);
   return true;
}

bool __cdecl replay_return_true(GGPOSession *)
{
   return true;
}

bool __cdecl replay_client_chat(GGPOSession *, char *)
{
   return true;
}

bool __cdecl replay_get_stats(GGPOSession *, GGPONetworkStats *)
{
   return true;
}

bool __cdecl replay_client_set_game_event(GGPOSession *, GGPOClientGameEventType, void *)
{
   return true;
}

void __cdecl replay_logv(GGPOSession *, char *format, va_list args)
{
   function_10001380_logv(format, args);
}

bool __cdecl replay_set_frame_delay(GGPOSession *, int)
{
   return true;
}

void __cdecl replay_destroy(GGPOSession *session)
{
   delete reinterpret_cast<ReplayBackend *>(session);
}

const GGPOSessionVTable replay_vtable = {
   replay_idle,
   replay_synchronize_input,
   replay_return_true,
   replay_client_chat,
   replay_get_stats,
   replay_client_set_game_event,
   replay_logv,
   replay_set_frame_delay,
   replay_destroy,
};

bool read_file(const char *path, std::vector<unsigned char> *contents)
{
   FILE *file = std::fopen(path, "rb");
   if (file == nullptr) {
      return false;
   }

   if (std::fseek(file, 0, SEEK_END) != 0) {
      std::fclose(file);
      return false;
   }
   const long length = std::ftell(file);
   if (length < 0) {
      std::fclose(file);
      return false;
   }
   if (std::fseek(file, 0, SEEK_SET) != 0) {
      std::fclose(file);
      return false;
   }

   contents->resize(static_cast<size_t>(length));
   if (!contents->empty()) {
      std::fread(contents->data(), 1, contents->size(), file);
   }
   std::fclose(file);
   return true;
}

char *find_char(char *start, char *end, char value)
{
   for (char *cursor = start; cursor < end; ++cursor) {
      if (*cursor == value) {
         return cursor;
      }
   }
   return nullptr;
}

void load_replay(ReplayBackend *backend, const char *path)
{
   std::vector<unsigned char> file;
   if (!read_file(path, &file) || file.empty()) {
      return;
   }

   auto *begin = reinterpret_cast<char *>(file.data());
   auto *end = begin + file.size();
   char *header_end = find_char(begin, end, '\0');
   if (header_end == nullptr) {
      return;
   }

   char version[64] = {};
   char game[256] = {};
   long payload_size = 0;
   long compressed_state_size = 0;
   long state_size = 0;
   long input_size = 0;
   long input_count = 0;

   char *line = find_char(begin, header_end, '\n');
   while (line != nullptr) {
      ++line;
      if (line >= header_end || *line == '\0') {
         break;
      }

      char *tab = find_char(line, header_end, '\t');
      if (tab == nullptr) {
         return;
      }
      *tab = '\0';
      char *value = tab + 1;
      char *next = find_char(value, header_end, '\n');
      if (next == nullptr) {
         return;
      }
      *next = '\0';

      if (std::strcmp(line, "version") == 0) {
         std::strcpy(version, value);
      } else if (std::strcmp(line, "game") == 0) {
         std::strcpy(game, value);
      } else if (std::strcmp(line, "payload size") == 0) {
         payload_size = std::atol(value) + 1;
      } else if (std::strcmp(line, "compressed state size") == 0) {
         compressed_state_size = std::atol(value);
      } else if (std::strcmp(line, "state size") == 0) {
         state_size = std::atol(value);
      } else if (std::strcmp(line, "input size") == 0) {
         input_size = std::atol(value);
      } else if (std::strcmp(line, "input count") == 0) {
         input_count = std::atol(value);
      }

      line = next;
   }

   if (payload_size <= 0) {
      return;
   }

   auto *payload = reinterpret_cast<const Bytef *>(header_end + 1);
   if (payload > reinterpret_cast<const Bytef *>(end)) {
      return;
   }

   auto *decompressed = static_cast<unsigned char *>(std::malloc(static_cast<size_t>(payload_size)));
   if (decompressed == nullptr) {
      return;
   }

   uLongf decompressed_size = static_cast<uLongf>(payload_size);
   if (uncompress(decompressed, &decompressed_size, payload, static_cast<uLong>(compressed_state_size)) != Z_OK) {
      std::free(decompressed);
      return;
   }

   backend->initial_state.assign(decompressed, decompressed + state_size);

   unsigned char *input_base = decompressed + state_size;
   for (long i = 0; i < input_count; ++i) {
      GameInputRecord input;
      game_input_construct(&input, 0, input_base + i * input_size, static_cast<int>(input_size));
      backend->input_history.push_back(input);
   }

   if (std::strcmp(version, "0.20") == 0) {
      if (!backend->input_history.empty()) {
         backend->input_history.erase(backend->input_history.begin());
      }
   }

   backend->callbacks.begin_game(game);
   backend->callbacks.load_game_state(backend->initial_state.data(), static_cast<int>(backend->initial_state.size()));
   std::free(decompressed);
}

} // namespace

GGPOSession *create_replay_session(GGPOSessionCallbacks *callbacks, const char *path)
{
   auto *backend = new ReplayBackend();
   if (backend == nullptr) {
      return nullptr;
   }

   backend->vtable = &replay_vtable;
   std::memcpy(&backend->callbacks, callbacks, sizeof(backend->callbacks));
   backend->cursor = 0;
   load_replay(backend, path);
   return reinterpret_cast<GGPOSession *>(backend);
}

bool replay_session_get_status(GGPOSession *session, GGPOReplayStatus *status)
{
   if (session == nullptr || status == nullptr || session->vtable != &replay_vtable) {
      return false;
   }

   auto *backend = reinterpret_cast<ReplayBackend *>(session);
   status->seekable = !backend->initial_state.empty();
   status->current_frame = static_cast<int>(backend->cursor);
   status->total_frames = static_cast<int>(backend->input_history.size());
   status->buffered_frames = status->total_frames;
   return status->seekable != 0;
}

bool replay_session_seek(GGPOSession *session, int frame)
{
   if (session == nullptr || session->vtable != &replay_vtable) {
      return false;
   }

   auto *backend = reinterpret_cast<ReplayBackend *>(session);
   if (backend->initial_state.empty()) {
      return false;
   }

   const int target = std::max(0, std::min(frame, static_cast<int>(backend->input_history.size())));
   backend->callbacks.load_game_state(backend->initial_state.data(), static_cast<int>(backend->initial_state.size()));
   backend->cursor = 0;
   while (static_cast<int>(backend->cursor) < target) {
      if (!backend->callbacks.advance_frame(0)) {
         return false;
      }
   }
   return true;
}

}
