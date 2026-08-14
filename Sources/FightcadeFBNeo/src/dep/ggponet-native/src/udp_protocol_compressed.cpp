#include "udp_protocol.hpp"

#include <cstdint>
#include <cstring>
#include <limits>
#include <utility>
#include <vector>

namespace ggponet::reconstructed {
namespace {

constexpr int kUdpInitialIdleGraceFrames = 10;
constexpr int kMaximumCompressedBits = (kUdpPayloadMax - 12) * 8;

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

bool bitvector_read_bit(const unsigned char *data, int bit_count, int *offset, bool *value)
{
   if (*offset < 0 || *offset >= bit_count) {
      return false;
   }
   *value = (data[*offset / 8] & (1U << (*offset % 8))) != 0;
   ++*offset;
   return true;
}

bool bitvector_read_byte(const unsigned char *data, int bit_count, int *offset, unsigned char *value)
{
   unsigned char result = 0;
   for (int bit = 0; bit < 8; ++bit) {
      bool set = false;
      if (!bitvector_read_bit(data, bit_count, offset, &set)) {
         return false;
      }
      if (set) {
         result = static_cast<unsigned char>(result | (1U << bit));
      }
   }
   *value = result;
   return true;
}

void ensure_bit_capacity(std::vector<unsigned char> *message, int bit_offset)
{
   const size_t required = 12 + static_cast<size_t>(bit_offset / 8) + 1;
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
   for (int bit = 0; bit < 8; ++bit) {
      bitvector_write_bit(message, offset, (value & (1 << bit)) != 0);
   }
}

void queue_input_event(UdpProtocol *protocol, const GameInput &input)
{
   UdpProtocolEvent event;
   event.type = 3;
   event.payload.resize(sizeof(GameInput));
   std::memcpy(event.payload.data(), &input, sizeof(GameInput));
   udp_protocol_log("Queuing event\n");
   protocol->events.push_back(std::move(event));
}

} // namespace

void udp_protocol_send_compressed_input(UdpProtocol *protocol)
{
   if (protocol->pending_outputs.empty()) {
      return;
   }
   const GameInput &first = protocol->pending_outputs.front();
   if (first.size <= 0 || first.size > kGameInputMaxBytes) {
      udp_protocol_log("Dropped invalid pending input size %d.\n", first.size);
      return;
   }

   std::vector<unsigned char> message(12, 0);
   message[0] = 3;
   write_i32(&message, 1, first.frame);
   message[11] = static_cast<unsigned char>(first.size);

   GameInput last = protocol->last_acked_input;
   if (last.frame != -1 && (last.frame == std::numeric_limits<int>::max() || last.frame + 1 != first.frame)) {
      udp_protocol_log("Dropped non-contiguous pending input sequence.\n");
      return;
   }

   int bit_offset = 0;
   int encoded_frames = 0;
   for (const GameInput &current : protocol->pending_outputs) {
      if (current.size != first.size || current.size <= 0 || current.size > kGameInputMaxBytes) {
         break;
      }
      const int maximum_frame_bits = current.size * 8 * 10 + 1;
      if (bit_offset + maximum_frame_bits > kMaximumCompressedBits) {
         break;
      }
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
      ++encoded_frames;
   }
   if (encoded_frames == 0) {
      udp_protocol_log("Could not fit pending input into UDP payload.\n");
      return;
   }

   write_i32(&message, 5, protocol->last_received_input.frame);
   write_u16(&message, 9, static_cast<uint16_t>(bit_offset));
   message.resize(12 + static_cast<size_t>((bit_offset + 7) / 8));
   udp_protocol_send_message(protocol, message);
}

bool udp_protocol_handle_compressed_input(UdpProtocol *protocol, const unsigned char *message, int size)
{
   if (protocol == nullptr || message == nullptr || size < 12) {
      return false;
   }
   if (protocol->sync_state == 0) {
      udp_protocol_log("Ignoring input received while syncing.\n");
      return true;
   }

   const int bit_count = read_u16(message + 9);
   const int input_size = message[11];
   if (bit_count <= 0 || bit_count > (size - 12) * 8 || input_size <= 0 || input_size > kGameInputMaxBytes) {
      udp_protocol_log("Dropped malformed compressed input header.\n");
      return false;
   }

   const int ack_frame = read_i32(message + 5);
   int current_frame = read_i32(message + 1);
   GameInput decoded_input = protocol->last_received_input;
   decoded_input.size = input_size;
   if (decoded_input.frame < 0) {
      if (current_frame == std::numeric_limits<int>::min()) {
         return false;
      }
      decoded_input.frame = current_frame - 1;
   }

   int offset = 0;
   const unsigned char *compressed = message + 12;
   std::vector<GameInput> decoded_frames;
   while (offset < bit_count) {
      if (decoded_input.frame != std::numeric_limits<int>::max() && current_frame > decoded_input.frame + 1) {
         udp_protocol_log("Dropped compressed input with a frame gap.\n");
         return false;
      }
      const bool use_current_frame = decoded_input.frame != std::numeric_limits<int>::max() &&
                                     current_frame == decoded_input.frame + 1;
      bool has_change = false;
      if (!bitvector_read_bit(compressed, bit_count, &offset, &has_change)) {
         return false;
      }
      while (has_change) {
         bool value = false;
         unsigned char bit = 0;
         if (!bitvector_read_bit(compressed, bit_count, &offset, &value) ||
             !bitvector_read_byte(compressed, bit_count, &offset, &bit) || bit >= input_size * 8) {
            udp_protocol_log("Dropped compressed input with an invalid bit change.\n");
            return false;
         }
         if (use_current_frame) {
            set_input_bit(&decoded_input, bit, value);
         }
         if (!bitvector_read_bit(compressed, bit_count, &offset, &has_change)) {
            return false;
         }
      }

      if (!use_current_frame) {
         udp_protocol_log("Skipping past frame:(%d) current is %d.\n", current_frame, decoded_input.frame);
      } else {
         decoded_input.frame = current_frame;
         decoded_frames.push_back(decoded_input);
      }
      if (offset < bit_count) {
         if (current_frame == std::numeric_limits<int>::max()) {
            return false;
         }
         ++current_frame;
      }
   }

   protocol->last_quality_report_time_ms = udp_protocol_now_ms();
   protocol->last_received_input = decoded_input;
   for (const GameInput &input : decoded_frames) {
      char text[1024];
      game_input_to_string(&input, text, sizeof(text), true);
      udp_protocol_log("Sending frame %d to emu (%s).\n", input.frame, text);
      queue_input_event(protocol, input);
   }
   while (!protocol->pending_outputs.empty() && protocol->pending_outputs.front().frame < ack_frame) {
      udp_protocol_log("Throwing away pending output frame %d\n", protocol->pending_outputs.front().frame);
      protocol->last_acked_input = protocol->pending_outputs.front();
      protocol->pending_outputs.pop_front();
   }
   return true;
}

void udp_protocol_send_input(UdpProtocol *protocol, const GameInput *input)
{
   if (protocol == nullptr || input == nullptr || input->size <= 0 || input->size > kGameInputMaxBytes) {
      return;
   }
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
