#include <cstddef>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>

#include "logging.hpp"
#include "session.hpp"
#include "synctest_backend.hpp"

namespace ggponet::reconstructed {
namespace {

constexpr int kGameInputMaxBytes = 0x12;
constexpr int kSavedStateCount = 0x16;

struct GameInputRecord {
   int frame;
   int size;
   unsigned char bits[kGameInputMaxBytes];
   unsigned char padding[2];
};

static_assert(sizeof(GameInputRecord) == 0x1c);

struct SavedState {
   unsigned char *buffer;
   int size;
   int frame;
   int checksum;
};

struct SyncState {
   void *vtable;
   GGPOSessionCallbacks callbacks;
   unsigned char reserved[0xe8];
   int frame;
   SavedState saved[kSavedStateCount];
   int head;
};


struct SyncReplayEntry {
   int frame;
   int checksum;
   unsigned char *buffer;
   int size;
   GameInputRecord input;
};


struct ReplayCheckQueue {
   void *reserved[2];
   SyncReplayEntry **blocks;
   unsigned int map_size;
   unsigned int first;
   unsigned int count;
};

struct SyncTestBackend {
   const GGPOSessionVTable *vtable;
   GGPOSessionCallbacks callbacks;
   SyncState sync;
   int check_distance;
   int last_verified_frame;
   bool rolling;
   bool replaying;
   unsigned char pad_29e[2];
   FILE *log_file;
   char game[0x80];
   GameInputRecord last_input;
   ReplayCheckQueue replay_queue;
};


void queue_construct(ReplayCheckQueue *queue)
{
   std::memset(queue, 0, sizeof(*queue));
}

void queue_grow(ReplayCheckQueue *queue)
{
   unsigned int extra = queue->map_size / 2;
   if (extra < 8) {
      extra = 8;
   }
   const unsigned int new_size = queue->map_size + extra;
   auto **new_blocks = static_cast<SyncReplayEntry **>(std::calloc(new_size, sizeof(SyncReplayEntry *)));
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

void queue_push(ReplayCheckQueue *queue, const SyncReplayEntry *entry)
{
   if (queue->map_size <= queue->count + 1U) {
      queue_grow(queue);
   }
   const unsigned int index = (queue->first + queue->count) % queue->map_size;
   if (queue->blocks[index] == nullptr) {
      queue->blocks[index] = static_cast<SyncReplayEntry *>(std::malloc(sizeof(SyncReplayEntry)));
      if (queue->blocks[index] == nullptr) {
         std::abort();
      }
   }
   std::memcpy(queue->blocks[index], entry, sizeof(SyncReplayEntry));
   ++queue->count;
}

SyncReplayEntry *queue_front(ReplayCheckQueue *queue)
{
   if (queue->count == 0 || queue->map_size == 0) {
      return nullptr;
   }
   return queue->blocks[queue->first];
}

void queue_pop(ReplayCheckQueue *queue)
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

void sync_init(SyncState *sync, const GGPOSessionCallbacks *callbacks)
{
   std::memset(sync, 0, sizeof(*sync));
   std::memcpy(&sync->callbacks, callbacks, sizeof(sync->callbacks));
   sync->frame = 0;
   sync->head = 0;
}

SavedState *sync_previous_state(SyncState *sync)
{
   int index = sync->head - 1;
   if (index < 0) {
      index = kSavedStateCount - 1;
   }
   return &sync->saved[index];
}

int sync_find_frame(SyncState *sync, int frame)
{
   for (int i = 0; i < kSavedStateCount; ++i) {
      if (sync->saved[i].frame == frame) {
         return i;
      }
   }
   std::fprintf(stderr, "GGPO Assertion Failed: could not find saved frame %d\n", frame);
   std::exit(1);
}

void sync_save_current_frame(SyncState *sync)
{
   SavedState *state = &sync->saved[sync->head];
   if (state->buffer != nullptr) {
      sync->callbacks.free_buffer(state->buffer);
      state->buffer = nullptr;
   }
   state->frame = sync->frame;
   sync->callbacks.save_game_state(&state->buffer, &state->size, &state->checksum, state->frame);
   sync->head = (sync->head + 1U) % kSavedStateCount;
}

void sync_advance_frame(SyncState *sync)
{
   sync_save_current_frame(sync);
   ++sync->frame;
}

void sync_load_frame(SyncState *sync, int frame)
{
   if (frame == sync->frame) {
      return;
   }
   const int index = sync_find_frame(sync, frame);
   SavedState *state = &sync->saved[index];
   if (state->buffer == nullptr || state->size == 0) {
      std::fprintf(stderr, "GGPO Assertion Failed: state->buf && state->cbuf\n");
      std::exit(1);
   }
   sync->callbacks.load_game_state(state->buffer, state->size);
   sync->frame = state->frame + 1;
   sync->head = (index + 1U) % kSavedStateCount;
}

void close_log(SyncTestBackend *backend)
{
   if (backend->log_file != nullptr) {
      std::fprintf(backend->log_file, "Closing log file.\n");
      std::fclose(backend->log_file);
      backend->log_file = nullptr;
   }
}

void open_log(SyncTestBackend *backend, bool state)
{
   close_log(backend);
   mkdir("synclogs", 0777);
   char path[268];
   std::snprintf(path, sizeof(path), "synclogs/%s-%04d-%s.log", state ? "state" : "log", backend->sync.frame,
                 backend->replaying ? "replay" : "original");
   backend->log_file = std::fopen(path, "w");
}

void debug_break(SyncTestBackend *backend, const char *format, ...)
{
   char message[1024];
   va_list args;
   va_start(args, format);
   std::vsnprintf(message, sizeof(message), format, args);
   va_end(args);
   std::puts(message);
   close_log(backend);
   std::abort();
}

bool __cdecl synctest_idle(GGPOSession *, int)
{
   return true;
}

bool __cdecl synctest_synchronize_input(GGPOSession *session, void *values, int size, int players)
{
   auto *backend = reinterpret_cast<SyncTestBackend *>(session);
   const int copied_players = players < 2 ? players : 2;
   const size_t copied_size = static_cast<size_t>(size * copied_players);
   open_log(backend, false);
   if (!backend->replaying) {
      if (!backend->rolling) {
         std::memcpy(&backend->last_input.bits, values, copied_size);
      } else {
         std::memset(&backend->last_input.bits, 0, copied_size);
      }
   } else {
      SyncReplayEntry *entry = queue_front(&backend->replay_queue);
      if (entry != nullptr) {
         std::memcpy(&backend->last_input, &entry->input, sizeof(backend->last_input));
      }
   }
   std::memcpy(values, backend->last_input.bits, copied_size);
   return true;
}

bool __cdecl synctest_advance_frame(GGPOSession *session)
{
   auto *backend = reinterpret_cast<SyncTestBackend *>(session);
   sync_advance_frame(&backend->sync);
   close_log(backend);
   if (backend->replaying) {
      return true;
   }

   const int frame = backend->sync.frame;
   if (frame != 1) {
      SavedState *previous = sync_previous_state(&backend->sync);
      SyncReplayEntry entry = {};
      entry.frame = frame;
      entry.checksum = previous->checksum;
      entry.size = previous->size;
      entry.buffer = static_cast<unsigned char *>(std::malloc(static_cast<size_t>(previous->size)));
      if (entry.buffer != nullptr && previous->buffer != nullptr) {
         std::memcpy(entry.buffer, previous->buffer, static_cast<size_t>(previous->size));
      }
      std::memcpy(&entry.input, &backend->last_input, sizeof(entry.input));
      queue_push(&backend->replay_queue, &entry);
   }

   if (frame - backend->last_verified_frame == backend->check_distance) {
      sync_load_frame(&backend->sync, backend->last_verified_frame - 1);
      backend->replaying = true;
      while (backend->replay_queue.count != 0) {
         backend->callbacks.advance_frame(0);
         SyncReplayEntry entry = *queue_front(&backend->replay_queue);
         queue_pop(&backend->replay_queue);
         if (entry.frame != frame) {
            debug_break(backend, "Frame number %d does not match saved frame number %d", entry.frame, frame);
         }
         const int checksum = sync_previous_state(&backend->sync)->checksum;
         if (entry.checksum != checksum) {
            debug_break(backend, "Checksum for frame %d does not match saved (%d != %d)", frame, checksum, entry.checksum);
         }
         std::printf("Checksum %08d for frame %d matches.\n", checksum, entry.frame);
         std::free(entry.buffer);
      }
      backend->last_verified_frame = frame;
      backend->replaying = false;
   }
   return true;
}

bool __cdecl synctest_client_chat(GGPOSession *, char *)
{
   return true;
}

bool __cdecl synctest_get_stats(GGPOSession *, GGPONetworkStats *)
{
   return true;
}

bool __cdecl synctest_client_set_game_event(GGPOSession *, GGPOClientGameEventType, void *)
{
   return true;
}

void __cdecl synctest_logv(GGPOSession *session, char *format, va_list args)
{
   function_10027400_synctest_logv(session, format, args);
}

bool __cdecl synctest_set_frame_delay(GGPOSession *, int)
{
   return true;
}

void __cdecl synctest_destroy(GGPOSession *session)
{
   std::free(session);
}

const GGPOSessionVTable synctest_vtable = {
   synctest_idle,
   synctest_synchronize_input,
   synctest_advance_frame,
   synctest_client_chat,
   synctest_get_stats,
   synctest_client_set_game_event,
   synctest_logv,
   synctest_set_frame_delay,
   synctest_destroy,
};

} // namespace

bool function_10027400_synctest_logv(void *self, const char *format, va_list args)
{
   auto *file = reinterpret_cast<SyncTestBackend *>(self)->log_file;
   if (file != nullptr) {
      std::vfprintf(file, format, args);
   }
   return true;
}

GGPOSession *create_synctest_session(GGPOSessionCallbacks *callbacks, const char *game, int check_distance)
{
   void *storage = std::malloc(sizeof(SyncTestBackend));
   if (storage == nullptr) {
      return nullptr;
   }
   auto *backend = static_cast<SyncTestBackend *>(storage);
   std::memset(backend, 0, sizeof(*backend));
   backend->vtable = &synctest_vtable;
   std::memcpy(&backend->callbacks, callbacks, sizeof(backend->callbacks));
   sync_init(&backend->sync, callbacks);
   backend->check_distance = check_distance;
   backend->last_verified_frame = 1;
   backend->rolling = false;
   backend->replaying = false;
   backend->log_file = nullptr;
   std::strcpy(backend->game, game);
   queue_construct(&backend->replay_queue);

   GGPOSessionCallbacks sync_callbacks = backend->callbacks;
   sync_init(&backend->sync, &sync_callbacks);
   backend->callbacks.begin_game(backend->game);
   return reinterpret_cast<GGPOSession *>(backend);
}

}
