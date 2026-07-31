#pragma once

#include "session.hpp"

namespace ggponet::reconstructed {

GGPOSession *create_client_session(GGPOSessionCallbacks *callbacks, char *game, char *match_id, int server_port);

}
