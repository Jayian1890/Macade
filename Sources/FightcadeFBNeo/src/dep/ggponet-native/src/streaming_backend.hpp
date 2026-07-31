#pragma once

#include "session.hpp"

namespace ggponet::reconstructed {

GGPOSession *create_streaming_session(GGPOSessionCallbacks *callbacks, const char *game, const char *match_id,
                                      int server_port);

}
