#include "udp_protocol.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

namespace ggponet::reconstructed {
namespace {

constexpr int kUdpInitialIdleGraceFrames = 10;

void assert_or_exit(bool condition, const char *expression, int line)
{
   if (!condition) {
      std::fprintf(stderr, "Assertion: %s @ ..\\source\\network\\udp_proto.cpp:%d\n", expression, line);
      std::exit(1);
   }
}

int read_i32(const unsigned char *data)
{
   int value = 0;
   std::memcpy(&value, data, sizeof(value));
   return value;
}

uint16_t read_u16(const unsigned char *data)
{
   uint16_t value = 0;
   std::memcpy(&value, data, sizeof(value));
   return value;
}

void write_i32(std::vector<unsigned char> *data, size_t offset, int value)
{
   std::memcpy(data->data() + offset, &value, sizeof(value));
}

void write_u16(std::vector<unsigned char> *data, size_t offset, uint16_t value)
{
   std::memcpy(data->data() + offset, &value, sizeof(value));
}

bool input_bit(const GameInput *input, int bit)
{
   return (input->bits[bit / 8] & (1U << (bit % 8))) != 0;
}

void set_input_bit(GameInput *input, int bit, bool value)
{
   const auto mask = static_cast<unsigned char>(1U << (bit % 8));
   if (value) {
      input->bits[bit / 8] = static_cast<unsigned char>(input->bits[bit / 8] | mask);
   } else {
      input->bits[bit / 8] = static_cast<unsigned char>(input->bits[bit / 8] & ~mask);
   }
}

bool bitvector_read_bit(const unsigned char *data, int *offset)
{
   const bool value = (data[*offset / 8] & (1U << (*offset % 8))) != 0;
   ++*offset;
   return value;
}

unsigned char bitvector_read_byte(const unsigned char *data, int *offset)
{
   unsigned char value = 0;
   for (int bit = 0; bit < 8; ++bit) {
      if (bitvector_read_bit(data, offset)) {
         value = static_cast<unsigned char>(value | (1U << bit));
      }
   }
   return value;
}

void ensure_bit_capacity(std::vector<unsigned char> *message, int bit_offset)
{
   const size_t required = 12 + static_cast<size_t>((bit_offset + 8) / 8) + 1;
   if (message->size() < required) {
      message->resize(required, 0);
   }
}

void bitvector_write_bit(std::vector<unsigned char> *message, int *offset, bool value)
{
   ensure_bit_capacity(message, *offset);
   unsigned char *byte = message->data() + 12 + (*offset / 8);
   const auto mask = static_cast<unsigned char>(1U << (*offset % 8));
   if (value) {
      *byte = static_cast<unsigned char>(*byte | mask);
   } else {
      *byte = static_cast<unsigned char>(*byte & ~mask);
   }
   ++*offset;
}

void bitvector_write_byte(std::vector<unsigned char> *message, int *offset, int value)
{
   assert_or_exit(value < 0x100, "i < (1 << BITVECTOR_NIBBLE_SIZE)", 0x73);
   for (int bit = 0; bit < 8; ++bit) {
      bitvector_write_bit(message, offset, (value & (1 << bit)) != 0);
   }
}

void queue_input_event(UdpProtocol *protocol)
{
   UdpProtocolEvent event;
   event.type = 3;
   event.payload.resize(sizeof(GameInput));
   std::memcpy(event.payload.data(), &protocol->last_received_input, sizeof(GameInput));
   udp_protocol_log("Queuing event\n");
   protocol->events.push_back(std::move(event));
}

} // namespace

void udp_protocol_send_compressed_input(UdpProtocol *protocol)
{
   if (protocol->pending_outputs.empty()) {
      return;
   }

   std::vector<unsigned char> message(12, 0);
   message[0] = 3;
   write_i32(&message, 1, protocol->pending_outputs.front().frame);
   message[11] = static_cast<unsigned char>(protocol->pending_outputs.front().size);

   GameInput last = protocol->last_acked_input;
   assert_or_exit(last.frame == -1 || last.frame + 1 == read_i32(message.data() + 1),
                  "last.frame == -1 || last.frame + 1 == msg->u.input.start_frame", 0x6d);

   int bit_offset = 0;
   for (const GameInput &current : protocol->pending_outputs) {
      if (std::memcmp(current.bits, last.bits, static_cast<size_t>(current.size)) != 0) {
         for (int bit = 0; bit < current.size * 8; ++bit) {
            const bool current_bit = input_bit(&current, bit);
            if (current_bit != input_bit(&last, bit)) {
               bitvector_write_bit(&message, &bit_offset, true);
               bitvector_write_bit(&message, &bit_offset, current_bit);
               bitvector_write_byte(&message, &bit_offset, bit);
            }
         }
      }
      bitvector_write_bit(&message, &bit_offset, false);
      protocol->last_sent_input = current;
      last = current;
   }

   write_i32(&message, 5, protocol->last_received_input.frame);
   write_u16(&message, 9, static_cast<uint16_t>(bit_offset));
   message.resize(12 + static_cast<size_t>((bit_offset + 7) / 8));
   udp_protocol_send_message(protocol, message);
}

void udp_protocol_handle_compressed_input(UdpProtocol *protocol, const unsigned char *message)
{
   if (protocol->sync_state == 0) {
      udp_protocol_log("Ignoring input received while syncing.\n");
      return;
   }

   const int bit_count = read_u16(message + 9);
   const int ack_frame = read_i32(message + 5);
   int current_frame = read_i32(message + 1);
   const int input_size = message[11];
   assert_or_exit(input_size > 0 && input_size <= kGameInputMaxBytes,
                  "isize <= GAMEINPUT_MAX_BYTES * GAMEINPUT_MAX_PLAYERS", 0x1b);

   protocol->last_quality_report_time_ms = udp_protocol_now_ms();
   protocol->last_received_input.size = input_size;
   if (protocol->last_received_input.frame < 0) {
      protocol->last_received_input.frame = current_frame - 1;
   }

   int offset = 0;
   const unsigned char *compressed = message + 12;
   while (offset < bit_count) {
      assert_or_exit(protocol->last_received_input.frame + 1 >= current_frame,
                     "currentFrame <= (_last_received_input.frame + 1)", 0x173);
      const bool use_current_frame = current_frame == protocol->last_received_input.frame + 1;
      while (bitvector_read_bit(compressed, &offset)) {
         const bool value = bitvector_read_bit(compressed, &offset);
         const int bit = bitvector_read_byte(compressed, &offset);
         if (use_current_frame) {
            set_input_bit(&protocol->last_received_input, bit, value);
         }
      }
      assert_or_exit(offset <= bit_count, "offset <= numBits", 0x181);

      if (!use_current_frame) {
         udp_protocol_log("Skipping past frame:(%d) current is %d.\n", current_frame,
                          protocol->last_received_input.frame);
      } else {
         assert_or_exit(current_frame == protocol->last_received_input.frame + 1,
                        "currentFrame == _last_received_input.frame + 1", 0x18c);
         protocol->last_received_input.frame = current_frame;
         char text[1024];
         game_input_to_string(&protocol->last_received_input, text, sizeof(text), true);
         udp_protocol_log("Sending frame %d to emu (%s).\n", protocol->last_received_input.frame, text);
         queue_input_event(protocol);
      }
      ++current_frame;
   }

   while (!protocol->pending_outputs.empty() && protocol->pending_outputs.front().frame < ack_frame) {
      udp_protocol_log("Throwing away pending output frame %d\n", protocol->pending_outputs.front().frame);
      protocol->last_acked_input = protocol->pending_outputs.front();
      protocol->pending_outputs.pop_front();
   }
}

void udp_protocol_send_input(UdpProtocol *protocol, const GameInput *input)
{
   protocol->pending_outputs.push_back(*input);
   if (game_input_equal(&protocol->pending_output, input, true)) {
      ++protocol->peer_disconnect_timeout;
   } else {
      protocol->peer_disconnect_timeout = 0;
   }
   protocol->pending_output = *input;

   if (input->frame < kUdpInitialIdleGraceFrames || protocol->peer_disconnect_timeout < protocol->idle_frame_count ||
       input->frame % protocol->idle_frame_boost == 0) {
      udp_protocol_log("Sending frame %d (not idle)\n", input->frame);
      udp_protocol_send_compressed_input(protocol);
   } else {
      udp_protocol_log("Skipping frame %d (idle)\n", input->frame);
   }
}

}
