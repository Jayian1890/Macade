#pragma once

#include <cstdarg>

namespace ggponet::reconstructed {

void quark_logv(const char *format, va_list args);
void quark_log(const char *format, ...);
bool function_10001380_logv(const char *format, va_list args);

}
