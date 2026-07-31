#pragma once

#include "game_input.hpp"
#include "prediction.hpp"
#include "session.hpp"

namespace ggponet::reconstructed {

constexpr int kSyncSavedStateCount = 0x16;

struct SyncConfig {
   GGPOSessionCallbacks callbacks;
   int frame_delay;
   int max_prediction_frames;
};

struct SyncSavedState {
   unsigned char *buffer;
   int size;
   int frame;
   int checksum;
};

struct SyncCore {
   GGPOSessionCallbacks callbacks;
   Prediction prediction;
   int frame_count;
   SyncSavedState saved[kSyncSavedStateCount];
   int saved_state_head;
};

void sync_construct(SyncCore *sync);
void sync_destroy(SyncCore *sync);
void sync_init(SyncCore *sync, const SyncConfig *config);
int sync_current_frame(const SyncCore *sync);
void sync_advance_frame(SyncCore *sync);
void sync_check_simulation(SyncCore *sync);
void sync_add_remote_input(SyncCore *sync, const GameInput *input);
bool sync_add_local_input(SyncCore *sync, GameInput *input);
void sync_get_input(SyncCore *sync, GameInput *input);
void sync_get_prediction_stats(const SyncCore *sync, int *predict_count, int *remote_count);
void sync_get_saved_state(const SyncCore *sync, int frame, unsigned char **buffer, int *size);
bool sync_pop_confirmed_input(SyncCore *sync, PredictionEvent *event);
void sync_set_frame_delay(SyncCore *sync, int delay);

}
