#pragma once

#include "session.hpp"

namespace ggponet::reconstructed {

GGPOSession *create_synctest_session(GGPOSessionCallbacks *callbacks, const char *game, int check_distance);
bool function_10027400_synctest_logv(void *self, const char *format, va_list args);

}
