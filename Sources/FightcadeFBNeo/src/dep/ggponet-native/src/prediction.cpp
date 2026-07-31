#include "prediction.hpp"

#include "logging.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace ggponet::reconstructed {
namespace {

void assert_or_exit(bool condition, const char *expression, int line)
{
   if (!condition) {
      std::fprintf(stderr, "Assertion: %s @ ..\\source\\prediction.cpp:%d\n", expression, line);
      std::exit(1);
   }
}

void zero_input_bits(GameInput *input)
{
   std::memset(input->bits, 0, sizeof(input->bits));
}

void push_confirmed(Prediction *prediction, const GameInput *input)
{
   prediction->confirmed_queue.push_back(PredictionEvent{0, *input});
}

void move_prediction_forward(Prediction *prediction)
{
   quark_log("MovePredictionForward (l:%zu r:%zu p:%zu)\n", prediction->local_queue.size(),
             prediction->remote_queue.size(), prediction->predict_queue.size());

   if (!prediction->local_queue.empty() &&
       prediction->predict_queue.size() < static_cast<size_t>(prediction->max_prediction_frames)) {
      GameInput local = prediction->local_queue.front();
      prediction->local_queue.pop_front();

      const bool remote_empty = prediction->remote_queue.empty();
      if (!remote_empty) {
         prediction->last_remote_input = prediction->remote_queue.front();
         prediction->remote_queue.pop_front();
         assert_or_exit(prediction->predict_queue.empty(), "_predict_queue.empty()", 0x97);
         assert_or_exit(prediction->last_remote_input.frame == local.frame,
                        "_last_remote_input.frame == local.frame", 0x98);
      } else {
         prediction->predict_queue.push_back(local);
      }

      assert_or_exit(prediction->last_remote_input.frame <= local.frame,
                     "_last_remote_input.frame <= local.frame", 0xa4);
      game_input_or(&local, &prediction->last_remote_input);
      game_input_log(&local, remote_empty ? "Adding latency frame to GameQueue" :
                                      "Adding confirmed frame to GameQueue",
                     true);
      prediction->game_queue.push_back(local);
      if (!remote_empty) {
         push_confirmed(prediction, &local);
      }
   }

   if (!prediction->predict_queue.empty() && !prediction->remote_queue.empty()) {
      quark_log("LOGICIAL ERROR!!!  Queues not empty:\n");
      quark_log("   Local Queue  : %zu.\n", prediction->local_queue.size());
      quark_log("   Remote Queue : %zu.\n", prediction->remote_queue.size());
      quark_log("   Predict Queue: %zu.\n", prediction->predict_queue.size());
   }
}

bool check_prediction(Prediction *prediction, int *first_incorrect_frame)
{
   *first_incorrect_frame = -1;
   while (*first_incorrect_frame < 0 && !prediction->remote_queue.empty() &&
          !prediction->predict_queue.empty()) {
      GameInput remote = prediction->remote_queue.front();
      prediction->last_remote_input.frame = remote.frame;
      prediction->last_remote_input.size = remote.size;

      if (!game_input_equal(&remote, &prediction->last_remote_input, false)) {
         *first_incorrect_frame = remote.frame;
         char predicted[1024];
         char actual[1024];
         game_input_to_string(&prediction->last_remote_input, predicted, sizeof(predicted), true);
         game_input_to_string(&remote, actual, sizeof(actual), true);
         quark_log("Frame p(%s) != r(%s)\n", predicted, actual);
      } else {
         game_input_log(&remote, "Predicted remote frame is correct.", true);
         GameInput confirmed = prediction->predict_queue.front();
         game_input_or(&confirmed, &remote);
         push_confirmed(prediction, &confirmed);
         prediction->remote_queue.pop_front();
         prediction->predict_queue.erase(prediction->predict_queue.begin());
      }
   }
   return *first_incorrect_frame < 0;
}

void rebase_prediction(Prediction *prediction, int first_incorrect_frame)
{
   assert_or_exit(!prediction->remote_queue.empty(), "!_remote_queue.empty()", 0xdf);
   assert_or_exit(prediction->sync_game_queue.empty(), "_sync_game_queue.empty()", 0xe0);

   prediction->sync_game_queue.clear();
   int consumed_remote_count = 0;
   for (const GameInput &predicted : prediction->predict_queue) {
      if (!prediction->remote_queue.empty()) {
         prediction->last_remote_input = prediction->remote_queue.front();
         prediction->remote_queue.pop_front();
         ++consumed_remote_count;
      }
      assert_or_exit(prediction->last_remote_input.frame <= predicted.frame,
                     "_last_remote_input.frame <= predict.frame", 0xed);
      GameInput corrected = predicted;
      game_input_or(&corrected, &prediction->last_remote_input);
      prediction->sync_game_queue.push_back(corrected);
   }

   quark_log("Requeuing %d.\n", first_incorrect_frame);
   for (int i = 0; i < consumed_remote_count && !prediction->sync_game_queue.empty() &&
        !prediction->predict_queue.empty(); ++i) {
      push_confirmed(prediction, &prediction->sync_game_queue[static_cast<size_t>(i)]);
      prediction->predict_queue.erase(prediction->predict_queue.begin());
   }
}

} // namespace

void prediction_construct(Prediction *prediction, int initial_frame_delay, int max_prediction_frames)
{
   prediction->initial_frame_delay = initial_frame_delay;
   prediction->max_prediction_frames = max_prediction_frames;
   prediction->frame_delay = initial_frame_delay;
   prediction->next_expected_frame = 0;
   prediction->local_queue.clear();
   prediction->remote_queue.clear();
   prediction->game_queue.clear();
   prediction->predict_queue.clear();
   prediction->sync_game_queue.clear();
   prediction->confirmed_queue.clear();
   prediction->last_remote_input.frame = -1;
   prediction->last_remote_input.size = 0;
   zero_input_bits(&prediction->last_remote_input);
   std::memset(prediction->last_remote_input.padding, 0, sizeof(prediction->last_remote_input.padding));
   prediction->saved_predict_queue_count = 0;
   prediction->saved_remote_queue_count = 0;
}

void prediction_destroy(Prediction *prediction)
{
   prediction->confirmed_queue.clear();
   prediction->sync_game_queue.clear();
   prediction->predict_queue.clear();
   prediction->game_queue.clear();
   prediction->remote_queue.clear();
   prediction->local_queue.clear();
}

bool prediction_ready_for_local_input(const Prediction *prediction)
{
   return prediction->predict_queue.size() < static_cast<size_t>(prediction->max_prediction_frames - 1);
}

void prediction_set_frame_delay(Prediction *prediction, int delay)
{
   prediction->frame_delay = delay;
}

void prediction_add_remote_input(Prediction *prediction, const GameInput *input)
{
   if (prediction->last_remote_input.frame < 0 && prediction->remote_queue.empty()) {
      GameInput generated = *input;
      zero_input_bits(&generated);
      for (generated.frame = 0; generated.frame < input->frame; ++generated.frame) {
         quark_log("Workaround: Adding generated input to front of remote queue (%d).\n", generated.frame);
         prediction->remote_queue.push_back(generated);
      }
   }
   game_input_log(input, "Adding input to RemoteQueue", true);
   prediction->remote_queue.push_back(*input);
}

void prediction_add_local_input(Prediction *prediction, GameInput *input)
{
   assert_or_exit(prediction_ready_for_local_input(prediction), "ReadyForLocalInput()", 0x43);
   assert_or_exit(prediction->sync_game_queue.empty(), "_sync_game_queue.empty()", 0x44);

   input->frame += prediction->frame_delay;
   if (input->frame == 0) {
      quark_log("Clearing all inputs for first frame in prediction layer.\n");
      zero_input_bits(input);
   }
   if (input->frame < prediction->next_expected_frame) {
      quark_log("Tossing new frame %d (before expected frame %d).\n", input->frame,
                prediction->next_expected_frame);
   }
   if (prediction->next_expected_frame < input->frame) {
      GameInput padding = *input;
      for (padding.frame = prediction->next_expected_frame; padding.frame < input->frame; ++padding.frame) {
         quark_log("Padding local input queue with new frame (%d < %d).\n", padding.frame,
                   prediction->next_expected_frame);
         prediction->local_queue.push_back(padding);
         ++prediction->next_expected_frame;
      }
   }
   assert_or_exit(input->frame == prediction->next_expected_frame, "i.frame == _next_expected_frame", 0x6b);
   game_input_log(input, "Adding new game input to LocalQueue", true);
   prediction->local_queue.push_back(*input);
   ++prediction->next_expected_frame;
}

bool prediction_check_simulation(Prediction *prediction, int *seek_to, int *count)
{
   assert_or_exit(prediction->sync_game_queue.empty(), "_sync_game_queue.empty()", 0x20);
   prediction->saved_remote_queue_count = static_cast<int>(prediction->remote_queue.size());
   prediction->saved_predict_queue_count = static_cast<int>(prediction->predict_queue.size());

   int first_incorrect_frame = -1;
   const bool prediction_correct = check_prediction(prediction, &first_incorrect_frame);
   if (prediction_correct) {
      *seek_to = 0;
   } else {
      rebase_prediction(prediction, first_incorrect_frame);
      *seek_to = first_incorrect_frame - 1;
      *count = static_cast<int>(prediction->sync_game_queue.size());
   }
   assert_or_exit(prediction->predict_queue.empty() || prediction->remote_queue.empty(),
                  "_predict_queue.empty() || _remote_queue.empty()", 0x30);
   return prediction_correct;
}

void prediction_get_input(Prediction *prediction, int frame, GameInput *input)
{
   const char *source = "none";
   if (!prediction->sync_game_queue.empty()) {
      source = "SyncQueue";
      *input = prediction->sync_game_queue.front();
      prediction->sync_game_queue.erase(prediction->sync_game_queue.begin());
   } else {
      source = "GameQueue";
      assert_or_exit(prediction->game_queue.empty(), "_game_queue.empty()", 0x11d);
      move_prediction_forward(prediction);
      assert_or_exit(prediction->game_queue.size() == 1, "_game_queue.size() == 1", 0x11f);
      *input = prediction->game_queue.front();
      prediction->game_queue.pop_front();
   }
   assert_or_exit(input->frame == frame, "input.frame == frameNumber", 0x123);
   char buffer[1024];
   game_input_to_string(input, buffer, sizeof(buffer), true);
   quark_log("Returning input %s from %s to emulator.\n", buffer, source);
}

bool prediction_pop_confirmed_input(Prediction *prediction, PredictionEvent *event)
{
   if (prediction->confirmed_queue.empty()) {
      return false;
   }
   *event = prediction->confirmed_queue.front();
   prediction->confirmed_queue.pop_front();
   return true;
}

}
