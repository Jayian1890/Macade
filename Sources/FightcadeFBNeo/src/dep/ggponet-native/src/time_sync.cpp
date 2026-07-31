#include "time_sync.hpp"

#include "logging.hpp"

#include <algorithm>
#include <cstring>

namespace ggponet::reconstructed {
namespace {

int g_time_sync_iteration;

int truncate_toward_zero(float value)
{
   return static_cast<int>(value);
}

} // namespace

void time_sync_init(TimeSync *sync)
{
   std::memset(sync->local, 0, sizeof(sync->local));
   std::memset(sync->remote, 0, sizeof(sync->remote));
   std::memset(sync->inputs, 0, sizeof(sync->inputs));
   sync->next_prediction_frame = 0x78;
}

void time_sync_reset_vtable_only(TimeSync *)
{
}

void time_sync_destroy(TimeSync *sync)
{
   time_sync_reset_vtable_only(sync);
}

int time_sync_recommend_frame_wait_duration(TimeSync *sync)
{
   int local_total = 0;
   for (int value : sync->local) {
      local_total += value;
   }

   int remote_total = 0;
   for (int value : sync->remote) {
      remote_total += value;
   }

   ++g_time_sync_iteration;
   const float local_average = static_cast<float>(local_total) / 40.0F;
   const float remote_average = static_cast<float>(remote_total) / 40.0F;
   if (remote_average <= local_average) {
      return 0;
   }

   int sleep_frames = truncate_toward_zero(((remote_average - local_average) / 2.0F) + 0.5F);
   quark_log("iteration %d:  sleep frames is %d\n", g_time_sync_iteration, sleep_frames);
   if (sleep_frames < 3) {
      return 0;
   }

   for (int index = 1; index < 10; ++index) {
      if (!game_input_equal(&sync->inputs[index], &sync->inputs[0], true)) {
         quark_log("iteration %d:  rejecting due to input stuff at position %d...!!!\n", g_time_sync_iteration,
                   index);
         return 0;
      }
   }
   return std::min(sleep_frames, 9);
}

int time_sync_advance_frame(TimeSync *sync, const GameInput *input, int local_frames_behind, int remote_frames_behind)
{
   std::memcpy(&sync->inputs[input->frame % 10], input, sizeof(*input));
   sync->local[input->frame % 40] = local_frames_behind;
   sync->remote[input->frame % 40] = remote_frames_behind;
   int wait = 0;
   if (sync->next_prediction_frame <= input->frame) {
      wait = time_sync_recommend_frame_wait_duration(sync);
      if (wait > 0) {
         sync->next_prediction_frame = input->frame + 0xf0;
      }
   }
   return wait;
}

}
