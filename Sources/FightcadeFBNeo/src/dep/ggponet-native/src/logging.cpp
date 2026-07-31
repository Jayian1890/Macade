#include "logging.hpp"

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

namespace ggponet::reconstructed {
namespace {

FILE *quark_log_file = nullptr;
std::chrono::steady_clock::time_point quark_log_start;
bool quark_log_start_set = false;

void write_quark_log(FILE *file, const char *format, va_list args)
{
   if (std::getenv("quark.log.timestamps") != nullptr) {
      int elapsed_ms = 0;
      const auto now = std::chrono::steady_clock::now();
      if (!quark_log_start_set) {
         quark_log_start = now;
         quark_log_start_set = true;
      } else {
         elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(now - quark_log_start).count());
      }
      std::fprintf(file, "%d.%03d : ", elapsed_ms / 1000, elapsed_ms % 1000);
   }

   va_list file_args;
   va_copy(file_args, args);
   std::vfprintf(file, format, file_args);
   va_end(file_args);

   std::fflush(file);
}

} // namespace

void quark_logv(const char *format, va_list args)
{
   if (std::getenv("quark.log") == nullptr || std::getenv("quark.log.ignore") != nullptr) {
      return;
   }

   if (quark_log_file == nullptr) {
      char path[1024];
      std::snprintf(path, sizeof(path), "c:\\users\\ponder\\log-%d.log", getpid());
      quark_log_file = std::fopen(path, "w");
   }

   if (quark_log_file != nullptr) {
      write_quark_log(quark_log_file, format, args);
   }
}

void quark_log(const char *format, ...)
{
   va_list args;
   va_start(args, format);
   quark_logv(format, args);
   va_end(args);
}

bool function_10001380_logv(const char *format, va_list args)
{
   quark_logv(format, args);
   return true;
}

}
