#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace ggponet::reconstructed {

constexpr size_t kTcpMaximumFrameBytes = 64U * 1024U * 1024U;

enum class TcpFrameStatus {
   incomplete,
   ready,
   invalid,
};

uint32_t tcp_read_be32(const unsigned char *bytes);
void tcp_append_be32(std::vector<unsigned char> *buffer, uint32_t value);
bool tcp_read_string(const unsigned char *payload, size_t size, size_t *offset, std::string *value);
bool tcp_append_string(std::vector<unsigned char> *payload, const std::string &value);
bool tcp_append_command(std::vector<unsigned char> *buffer, uint32_t sequence, int command,
                        const std::vector<unsigned char> &payload);
TcpFrameStatus tcp_take_frame(std::vector<unsigned char> *buffer, std::vector<unsigned char> *frame);

}
