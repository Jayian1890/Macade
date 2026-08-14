#include "tcp_framing.hpp"

#include <arpa/inet.h>
#include <cstring>
#include <limits>

namespace ggponet::reconstructed {

uint32_t tcp_read_be32(const unsigned char *bytes)
{
   uint32_t value = 0;
   std::memcpy(&value, bytes, sizeof(value));
   return ntohl(value);
}

void tcp_append_be32(std::vector<unsigned char> *buffer, uint32_t value)
{
   const uint32_t be = htonl(value);
   const auto *bytes = reinterpret_cast<const unsigned char *>(&be);
   buffer->insert(buffer->end(), bytes, bytes + sizeof(be));
}

bool tcp_read_string(const unsigned char *payload, size_t size, size_t *offset, std::string *value)
{
   if (offset == nullptr || value == nullptr || *offset > size || size - *offset < 4) {
      return false;
   }
   const size_t length = tcp_read_be32(payload + *offset);
   *offset += 4;
   if (length > size - *offset) {
      return false;
   }
   value->assign(reinterpret_cast<const char *>(payload + *offset), length);
   *offset += length;
   return true;
}

bool tcp_append_string(std::vector<unsigned char> *payload, const std::string &value)
{
   if (payload == nullptr || value.size() > std::numeric_limits<uint32_t>::max()) {
      return false;
   }
   tcp_append_be32(payload, static_cast<uint32_t>(value.size()));
   payload->insert(payload->end(), value.begin(), value.end());
   return true;
}

bool tcp_append_command(std::vector<unsigned char> *buffer, uint32_t sequence, int command,
                        const std::vector<unsigned char> &payload)
{
   if (buffer == nullptr || payload.size() > kTcpMaximumFrameBytes - 8) {
      return false;
   }
   tcp_append_be32(buffer, static_cast<uint32_t>(payload.size() + 8));
   tcp_append_be32(buffer, sequence);
   tcp_append_be32(buffer, static_cast<uint32_t>(command));
   buffer->insert(buffer->end(), payload.begin(), payload.end());
   return true;
}

TcpFrameStatus tcp_take_frame(std::vector<unsigned char> *buffer, std::vector<unsigned char> *frame)
{
   if (buffer == nullptr || frame == nullptr) {
      return TcpFrameStatus::invalid;
   }
   if (buffer->size() < 4) {
      return TcpFrameStatus::incomplete;
   }
   const size_t length = tcp_read_be32(buffer->data());
   if (length > kTcpMaximumFrameBytes) {
      return TcpFrameStatus::invalid;
   }
   const size_t total_size = length + 4;
   if (buffer->size() < total_size) {
      return TcpFrameStatus::incomplete;
   }
   frame->assign(buffer->begin() + 4, buffer->begin() + total_size);
   buffer->erase(buffer->begin(), buffer->begin() + total_size);
   return TcpFrameStatus::ready;
}

}
