#pragma once

#include "session.hpp"

namespace ggponet::reconstructed {

GGPOSession *create_streaming_session(GGPOSessionCallbacks *callbacks, const char *game, const char *match_id,
                                      int server_port);
bool streaming_session_get_replay_status(GGPOSession *session, GGPOReplayStatus *status);
bool streaming_session_seek_replay(GGPOSession *session, int frame);

}
