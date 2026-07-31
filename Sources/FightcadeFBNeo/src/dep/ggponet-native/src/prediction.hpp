#pragma once

#include "game_input.hpp"

#include <cstddef>
#include <deque>
#include <vector>

namespace ggponet::reconstructed {

struct PredictionEvent {
   int type;
   GameInput input;
};

static_assert(sizeof(PredictionEvent) == 0x20);

struct Prediction {
   int initial_frame_delay;
   int max_prediction_frames;
   int frame_delay;
   int next_expected_frame;
   std::deque<GameInput> local_queue;
   std::deque<GameInput> remote_queue;
   std::deque<GameInput> game_queue;
   std::vector<GameInput> predict_queue;
   std::vector<GameInput> sync_game_queue;
   GameInput last_remote_input;
   std::deque<PredictionEvent> confirmed_queue;
   int saved_predict_queue_count;
   int saved_remote_queue_count;
};

void prediction_construct(Prediction *prediction, int initial_frame_delay, int max_prediction_frames);
void prediction_destroy(Prediction *prediction);
bool prediction_ready_for_local_input(const Prediction *prediction);
void prediction_set_frame_delay(Prediction *prediction, int delay);
void prediction_add_remote_input(Prediction *prediction, const GameInput *input);
void prediction_add_local_input(Prediction *prediction, GameInput *input);
bool prediction_check_simulation(Prediction *prediction, int *seek_to, int *count);
void prediction_get_input(Prediction *prediction, int frame, GameInput *input);
bool prediction_pop_confirmed_input(Prediction *prediction, PredictionEvent *event);

}
