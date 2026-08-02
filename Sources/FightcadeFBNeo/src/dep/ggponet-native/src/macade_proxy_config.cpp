#include "macade_proxy_config.hpp"

#include <cstdlib>

namespace ggponet::reconstructed {
namespace {

int env_port(const char *name)
{
   const char *value = std::getenv(name);
   if (value == nullptr) {
      return 0;
   }
   const long port = std::strtol(value, nullptr, 10);
   return port > 0 && port <= 65535 ? static_cast<int>(port) : 0;
}

} // namespace

MacadeProxyConfig macade_proxy_config()
{
   const char *host = std::getenv("MACADE_GGPO_PROXY_HOST");
   const int port = env_port("MACADE_GGPO_PROXY_PORT");
   const int register_port = env_port("MACADE_GGPO_TCP_REGISTER_PORT");
   return MacadeProxyConfig{
      host != nullptr && host[0] != 0 && port > 0,
      host != nullptr ? host : "",
      port,
      register_port,
   };
}

int macade_proxy_register_port(int fallback_port)
{
   const int port = env_port("MACADE_GGPO_TCP_REGISTER_PORT");
   return port > 0 ? port : fallback_port;
}

}
