#include "sync_core.hpp"

#include "logging.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace ggponet::reconstructed {
namespace {

void assert_or_exit(bool condition, const char *expression, int line)
{
   if (!condition) {
      std::fprintf(stderr, "Assertion: %s @ ..\\source\\sync.cpp:%d\n", expression, line);
      std::exit(1);
   }
}

int find_saved_state_index(const SyncCore *sync, int frame)
{
   for (int i = 0; i < kSyncSavedStateCount; ++i) {
      if (sync->saved[i].frame == frame) {
         return i;
      }
   }
   assert_or_exit(false, "FALSE", 0xaa);
   return 0;
}

SyncSavedState *current_saved_state(SyncCore *sync)
{
   return &sync->saved[sync->saved_state_head];
}

void save_current_frame(SyncCore *sync)
{
   SyncSavedState *state = current_saved_state(sync);
   if (state->buffer != nullptr) {
      sync->callbacks.free_buffer(state->buffer);
      state->buffer = nullptr;
   }

   state->frame = sync->frame_count;
   sync->callbacks.save_game_state(&state->buffer, &state->size, &state->checksum, state->frame);
   quark_log("=== Saved frame info %d (size: %d  checksum: %08x).\n", state->frame, state->size,
             state->checksum);
   sync->saved_state_head = (sync->saved_state_head + 1U) % kSyncSavedStateCount;
}

void load_frame(SyncCore *sync, int frame)
{
   if (frame == sync->frame_count) {
      quark_log("Skipping NOP.\n");
      return;
   }

   const int index = find_saved_state_index(sync, frame);
   sync->saved_state_head = index;
   SyncSavedState *state = current_saved_state(sync);
   quark_log("=== Loading frame info %d (size: %d  checksum: %08x).\n", state->frame, state->size,
             state->checksum);
   assert_or_exit(state->buffer != nullptr && state->size != 0, "state->buf && state->cbuf", 0x79);
   sync->callbacks.load_game_state(state->buffer, state->size);
   sync->frame_count = state->frame + 1;
   sync->saved_state_head = (sync->saved_state_head + 1U) % kSyncSavedStateCount;
}

void adjust_simulation(SyncCore *sync, int seek_to, int count)
{
   const int original_frame = sync->frame_count;
   assert_or_exit(seek_to + count == sync->frame_count - 1,
                  "seek_to + count == _framecount - 1", 0x54);

   quark_log("Catching up\n");
   load_frame(sync, seek_to);
   assert_or_exit(sync->frame_count == seek_to + 1, "_framecount == seek_to + 1", 0x5b);
   for (int i = 0; i < count; ++i) {
      sync->callbacks.advance_frame(0);
   }
   assert_or_exit(sync->frame_count == original_frame, "_framecount == framecount", 100);
   quark_log("Catching up finished.\n");
}

} // namespace

void sync_construct(SyncCore *sync)
{
   sync->callbacks = {};
   prediction_construct(&sync->prediction, 0, 0);
   sync->frame_count = 0;
   for (SyncSavedState &state : sync->saved) {
      state = {};
   }
   sync->saved_state_head = 0;
}

void sync_destroy(SyncCore *sync)
{
   prediction_destroy(&sync->prediction);
}

void sync_init(SyncCore *sync, const SyncConfig *config)
{
   std::memcpy(&sync->callbacks, &config->callbacks, sizeof(sync->callbacks));
   sync->frame_count = 0;
   prediction_construct(&sync->prediction, config->frame_delay, config->max_prediction_frames);
}

int sync_current_frame(const SyncCore *sync)
{
   return sync->frame_count;
}

void sync_advance_frame(SyncCore *sync)
{
   save_current_frame(sync);
   ++sync->frame_count;
}

void sync_check_simulation(SyncCore *sync)
{
   int seek_to = 0;
   int count = 0;
   if (!prediction_check_simulation(&sync->prediction, &seek_to, &count)) {
      adjust_simulation(sync, seek_to, count);
   }
}

void sync_add_remote_input(SyncCore *sync, const GameInput *input)
{
   prediction_add_remote_input(&sync->prediction, input);
}

bool sync_add_local_input(SyncCore *sync, GameInput *input)
{
   if (!prediction_ready_for_local_input(&sync->prediction)) {
      quark_log("Rejecting input from emualtor: reached prediction barrier.\n");
      return false;
   }

   input->frame = sync->frame_count;
   quark_log("SyncInput: Sending frame %d to synchronization layer.\n", input->frame);
   prediction_add_local_input(&sync->prediction, input);
   return true;
}

void sync_get_input(SyncCore *sync, GameInput *input)
{
   prediction_get_input(&sync->prediction, sync->frame_count, input);
}

void sync_get_prediction_stats(const SyncCore *sync, int *predict_count, int *remote_count)
{
   *predict_count = sync->prediction.saved_predict_queue_count;
   *remote_count = sync->prediction.saved_remote_queue_count;
}

void sync_get_saved_state(const SyncCore *sync, int frame, unsigned char **buffer, int *size)
{
   const int index = find_saved_state_index(sync, frame);
   const SyncSavedState &state = sync->saved[index];
   *buffer = state.buffer;
   *size = state.size;
}

bool sync_pop_confirmed_input(SyncCore *sync, PredictionEvent *event)
{
   return prediction_pop_confirmed_input(&sync->prediction, event);
}

void sync_set_frame_delay(SyncCore *sync, int delay)
{
   prediction_set_frame_delay(&sync->prediction, delay);
}

}
