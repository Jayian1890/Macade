#include "tcp_framing.hpp"
#include "udp_protocol.hpp"

#include <arpa/inet.h>
#include <cassert>
#include <climits>
#include <cstring>
#include <string>
#include <vector>

using namespace ggponet::reconstructed;

namespace {

void write_i32(std::vector<unsigned char> *packet, size_t offset, int value)
{
   std::memcpy(packet->data() + offset, &value, sizeof(value));
}

void write_u16(std::vector<unsigned char> *packet, size_t offset, uint16_t value)
{
   std::memcpy(packet->data() + offset, &value, sizeof(value));
}

void append_bit(std::vector<bool> *bits, bool value)
{
   bits->push_back(value);
}

void append_byte(std::vector<bool> *bits, unsigned char value)
{
   for (int bit = 0; bit < 8; ++bit) {
      append_bit(bits, (value & (1U << bit)) != 0);
   }
}

std::vector<unsigned char> compressed_packet(int frame, int ack_frame, int input_size,
                                             const std::vector<bool> &bits)
{
   std::vector<unsigned char> packet(12 + (bits.size() + 7) / 8, 0);
   packet[0] = 3;
   write_i32(&packet, 1, frame);
   write_i32(&packet, 5, ack_frame);
   write_u16(&packet, 9, static_cast<uint16_t>(bits.size()));
   packet[11] = static_cast<unsigned char>(input_size);
   for (size_t index = 0; index < bits.size(); ++index) {
      if (bits[index]) {
         packet[12 + index / 8] = static_cast<unsigned char>(packet[12 + index / 8] | (1U << (index % 8)));
      }
   }
   return packet;
}

void test_tcp_framing()
{
   std::vector<unsigned char> encoded;
   const std::vector<unsigned char> payload = {1, 2, 3};
   assert(tcp_append_command(&encoded, 7, 11, payload));

   std::vector<unsigned char> partial(encoded.begin(), encoded.begin() + 3);
   std::vector<unsigned char> frame;
   assert(tcp_take_frame(&partial, &frame) == TcpFrameStatus::incomplete);
   partial.insert(partial.end(), encoded.begin() + 3, encoded.end());
   assert(tcp_take_frame(&partial, &frame) == TcpFrameStatus::ready);
   assert(frame.size() == 11);
   assert(tcp_read_be32(frame.data()) == 7);
   assert(tcp_read_be32(frame.data() + 4) == 11);
   assert(std::vector<unsigned char>(frame.begin() + 8, frame.end()) == payload);
   assert(partial.empty());

   std::vector<unsigned char> oversized;
   tcp_append_be32(&oversized, static_cast<uint32_t>(kTcpMaximumFrameBytes + 1));
   assert(tcp_take_frame(&oversized, &frame) == TcpFrameStatus::invalid);

   std::vector<unsigned char> malformed_string;
   tcp_append_be32(&malformed_string, UINT_MAX);
   size_t offset = 0;
   std::string value;
   assert(!tcp_read_string(malformed_string.data(), malformed_string.size(), &offset, &value));
}

void test_udp_compressed_input_validation()
{
   UdpProtocol protocol;
   udp_protocol_construct(&protocol);
   protocol.sync_state = 2;

   const std::vector<unsigned char> unknown = {0};
   assert(!udp_protocol_handle_packet(&protocol, unknown.data(), static_cast<int>(unknown.size())));

   const std::vector<unsigned char> short_input(11, 0);
   assert(!udp_protocol_handle_packet(&protocol, short_input.data(), static_cast<int>(short_input.size())));

   const std::vector<bool> valid_bits = {false};
   const auto valid = compressed_packet(0, -1, 1, valid_bits);
   assert(udp_protocol_handle_packet(&protocol, valid.data(), static_cast<int>(valid.size())));
   assert(protocol.last_received_input.frame == 0);
   assert(protocol.events.size() == 1);

   std::vector<bool> invalid_index_bits;
   append_bit(&invalid_index_bits, true);
   append_bit(&invalid_index_bits, true);
   append_byte(&invalid_index_bits, 8);
   append_bit(&invalid_index_bits, false);
   const auto invalid_index = compressed_packet(1, -1, 1, invalid_index_bits);
   assert(!udp_protocol_handle_packet(&protocol, invalid_index.data(), static_cast<int>(invalid_index.size())));
   assert(protocol.last_received_input.frame == 0);
   assert(protocol.events.size() == 1);

   const std::vector<bool> truncated_change = {true};
   const auto truncated = compressed_packet(1, -1, 1, truncated_change);
   assert(!udp_protocol_handle_packet(&protocol, truncated.data(), static_cast<int>(truncated.size())));
   assert(protocol.last_received_input.frame == 0);

   auto impossible_bit_count = compressed_packet(1, -1, 1, valid_bits);
   write_u16(&impossible_bit_count, 9, 9);
   assert(!udp_protocol_handle_packet(&protocol, impossible_bit_count.data(),
                                      static_cast<int>(impossible_bit_count.size())));

   const auto zero_input = compressed_packet(1, -1, 0, valid_bits);
   assert(!udp_protocol_handle_packet(&protocol, zero_input.data(), static_cast<int>(zero_input.size())));
   udp_protocol_destroy(&protocol);
}

void test_udp_endpoint_filter()
{
   UdpSocket socket;
   udp_socket_construct(&socket);
   socket.has_remote_addr = true;
   socket.remote_addr.sin_family = AF_INET;
   socket.remote_addr.sin_port = htons(6004);
   assert(inet_pton(AF_INET, "198.51.100.7", &socket.remote_addr.sin_addr) == 1);

   sockaddr_in matching = socket.remote_addr;
   assert(udp_socket_source_matches(&socket, matching));
   matching.sin_port = htons(6005);
   assert(!udp_socket_source_matches(&socket, matching));
   matching = socket.remote_addr;
   assert(inet_pton(AF_INET, "203.0.113.9", &matching.sin_addr) == 1);
   assert(!udp_socket_source_matches(&socket, matching));

   assert(!udp_socket_queue_send(&socket, nullptr, kUdpPayloadMax + 1));
   udp_socket_destroy(&socket);
}

void test_malformed_udp_corpus_is_nonfatal()
{
   UdpProtocol protocol;
   udp_protocol_construct(&protocol);
   protocol.sync_state = 2;
   uint32_t state = 0x5a17c9e3;
   for (int iteration = 0; iteration < 10000; ++iteration) {
      state = state * 1664525U + 1013904223U;
      const size_t size = state % 129U;
      std::vector<unsigned char> packet(size);
      for (unsigned char &byte : packet) {
         state = state * 1664525U + 1013904223U;
         byte = static_cast<unsigned char>(state >> 24);
      }
      udp_protocol_handle_packet(&protocol, packet.data(), static_cast<int>(packet.size()));
   }
   udp_protocol_destroy(&protocol);
}

} // namespace

int main()
{
   test_tcp_framing();
   test_udp_compressed_input_validation();
   test_udp_endpoint_filter();
   test_malformed_udp_corpus_is_nonfatal();
   return 0;
}
