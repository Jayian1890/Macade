#pragma once

#include "game_input.hpp"

namespace ggponet::reconstructed {

struct TimeSync {
   int local[40];
   int remote[40];
   GameInput inputs[10];
   int next_prediction_frame;
};

void time_sync_init(TimeSync *sync);
void time_sync_reset_vtable_only(TimeSync *sync);
void time_sync_destroy(TimeSync *sync);
int time_sync_recommend_frame_wait_duration(TimeSync *sync);
int time_sync_advance_frame(TimeSync *sync, const GameInput *input, int local_frames_behind,
                            int remote_frames_behind);

}
