#pragma once

#include <string>

namespace ggponet::reconstructed {

struct MacadeProxyConfig {
   bool enabled;
   std::string host;
   int port;
   int register_port;
};

MacadeProxyConfig macade_proxy_config();
int macade_proxy_register_port(int fallback_port);

}
