#pragma once

#include <cstdint>
#include <vector>

namespace ggponet::reconstructed {

struct PollCallbackVTable {
   bool (*on_handle)(void *self, void *context);
   bool (*pre_idle)(void *self, void *context);
   bool (*on_timer)(void *self, void *context, int elapsed_ms);
   bool (*post_idle)(void *self, void *context);
};

struct PollCallbackTarget {
   const PollCallbackVTable *vtable;
};

struct PollCallback {
   PollCallbackTarget *target;
   void *context;
};

struct PollTimer {
   PollCallbackTarget *target;
   void *context;
   int interval_ms;
   int last_fired_ms;
};

struct PollBackend {
   int start_ms;
   int wake_read_fd;
   int wake_write_fd;
   std::vector<int> handles;
   std::vector<PollCallback> handle_callbacks;
   std::vector<PollCallback> pre_post_callbacks;
   std::vector<PollCallback> idle_callbacks;
   std::vector<PollTimer> timers;
};

void poll_backend_construct(PollBackend *poller);
void poll_backend_destroy(PollBackend *poller);
bool poll_backend_run(PollBackend *poller, int timeout_ms);
void poll_backend_add_handle(PollBackend *poller, PollCallbackTarget *target, int handle_fd, void *context);
void poll_backend_add_idle(PollBackend *poller, PollCallbackTarget *target, void *context);
void poll_backend_add_timer(PollBackend *poller, PollCallbackTarget *target, int interval_ms, void *context);
void poll_backend_signal(PollBackend *poller);
void poll_backend_reset(PollBackend *poller);

}
