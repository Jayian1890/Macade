#pragma once

#include "session.hpp"

namespace ggponet::reconstructed {

GGPOSession *create_replay_session(GGPOSessionCallbacks *callbacks, const char *path);

}
