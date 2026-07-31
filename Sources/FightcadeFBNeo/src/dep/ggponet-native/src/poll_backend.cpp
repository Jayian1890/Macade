#include "poll_backend.hpp"

#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>

namespace ggponet::reconstructed {
namespace {

constexpr size_t kMaxPollableHandles = 0x40;

int now_ms()
{
   static const auto start = std::chrono::steady_clock::now();
   const auto elapsed = std::chrono::steady_clock::now() - start;
   return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count());
}

void assert_or_exit(bool condition, const char *expression, int line)
{
   if (!condition) {
      std::fprintf(stderr, "Assertion: %s @ ..\\source\\poll.cpp:%d\n", expression, line);
      std::exit(1);
   }
}

void set_nonblocking(int fd)
{
   const int flags = fcntl(fd, F_GETFL, 0);
   if (flags >= 0) {
      fcntl(fd, F_SETFL, flags | O_NONBLOCK);
   }
}

int next_timer_timeout(const PollBackend *poller, int elapsed_ms)
{
   int result = -1;
   for (const PollTimer &timer : poller->timers) {
      const int remaining = timer.interval_ms + timer.last_fired_ms - elapsed_ms;
      if (result == -1 || remaining < result) {
         result = std::max(remaining, 0);
      }
   }
   return result;
}

bool accumulate_failure(bool current_failed, bool call_result)
{
   return !call_result || current_failed;
}

void drain_fd(int fd)
{
   char buffer[64];
   while (read(fd, buffer, sizeof(buffer)) > 0) {
   }
}

} // namespace

void poll_backend_construct(PollBackend *poller)
{
   poller->start_ms = 0;
   int fds[2];
   if (pipe(fds) != 0) {
      std::abort();
   }
   poller->wake_read_fd = fds[0];
   poller->wake_write_fd = fds[1];
   set_nonblocking(poller->wake_read_fd);
   set_nonblocking(poller->wake_write_fd);
   poller->handles.clear();
   poller->handle_callbacks.clear();
   poller->pre_post_callbacks.clear();
   poller->idle_callbacks.clear();
   poller->timers.clear();
   poller->handles.push_back(poller->wake_read_fd);
   poller->handle_callbacks.push_back({nullptr, nullptr});
}

void poll_backend_destroy(PollBackend *poller)
{
   if (poller->wake_read_fd >= 0) {
      close(poller->wake_read_fd);
      poller->wake_read_fd = -1;
   }
   if (poller->wake_write_fd >= 0) {
      close(poller->wake_write_fd);
      poller->wake_write_fd = -1;
   }
   poller->timers.clear();
   poller->idle_callbacks.clear();
   poller->pre_post_callbacks.clear();
   poller->handle_callbacks.clear();
   poller->handles.clear();
}

bool poll_backend_run(PollBackend *poller, int timeout_ms)
{
   bool failed = false;
   if (poller->start_ms == 0) {
      poller->start_ms = now_ms();
   }
   const int elapsed_ms = now_ms() - poller->start_ms;
   const int timer_timeout = next_timer_timeout(poller, elapsed_ms);
   if (timer_timeout != -1 && timeout_ms > timer_timeout) {
      timeout_ms = timer_timeout;
   }

   std::vector<pollfd> fds;
   fds.reserve(poller->handles.size());
   for (int handle : poller->handles) {
      fds.push_back({handle, POLLIN, 0});
   }

   const int ready = poll(fds.data(), static_cast<nfds_t>(fds.size()), timeout_ms);
   if (ready > 0) {
      for (size_t i = 0; i < fds.size(); ++i) {
         if ((fds[i].revents & POLLIN) == 0) {
            continue;
         }
         if (i == 0 && poller->handle_callbacks[i].target == nullptr) {
            drain_fd(poller->wake_read_fd);
         } else if (i < poller->handle_callbacks.size()) {
            const PollCallback &callback = poller->handle_callbacks[i];
            failed = accumulate_failure(failed,
                                        callback.target->vtable->on_handle(callback.target, callback.context));
         }
         break;
      }
   }

   for (const PollCallback &callback : poller->pre_post_callbacks) {
      failed = accumulate_failure(failed, callback.target->vtable->pre_idle(callback.target, callback.context));
   }
   for (PollTimer &timer : poller->timers) {
      if (timer.interval_ms + timer.last_fired_ms <= elapsed_ms) {
         timer.last_fired_ms = (elapsed_ms / timer.interval_ms) * timer.interval_ms;
         failed = accumulate_failure(failed,
                                     timer.target->vtable->on_timer(timer.target, timer.context, timer.last_fired_ms));
      }
   }
   for (const PollCallback &callback : poller->pre_post_callbacks) {
      failed = accumulate_failure(failed, callback.target->vtable->post_idle(callback.target, callback.context));
   }
   return failed;
}

void poll_backend_add_handle(PollBackend *poller, PollCallbackTarget *target, int handle_fd, void *context)
{
   assert_or_exit(poller->handles.size() < kMaxPollableHandles - 1,
                  "_handle_count < MAX_POLLABLE_HANDLES - 1", 0x15);
   poller->handles.push_back(handle_fd);
   poller->handle_callbacks.push_back({target, context});
}

void poll_backend_add_idle(PollBackend *poller, PollCallbackTarget *target, void *context)
{
   poller->pre_post_callbacks.push_back({target, context});
}

void poll_backend_add_timer(PollBackend *poller, PollCallbackTarget *target, int interval_ms, void *context)
{
   poller->timers.push_back({target, context, interval_ms, 0});
}

void poll_backend_signal(PollBackend *poller)
{
   const char byte = 1;
   if (write(poller->wake_write_fd, &byte, sizeof(byte)) < 0 && errno != EAGAIN) {
      std::abort();
   }
}

void poll_backend_reset(PollBackend *poller)
{
   drain_fd(poller->wake_read_fd);
}

}
