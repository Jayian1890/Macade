#pragma once

#include "session.hpp"

namespace ggponet::reconstructed {

GGPOSession *create_replay_session(GGPOSessionCallbacks *callbacks, const char *path);
bool replay_session_get_status(GGPOSession *session, GGPOReplayStatus *status);
bool replay_session_seek(GGPOSession *session, int frame);

}
