#include "udp_protocol.hpp"

#include "logging.hpp"

#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <utility>

namespace ggponet::reconstructed {
namespace {

void invalid_message()
{
   std::fprintf(stderr, "Assertion: FALSE && \"Invalid msg in UdpProtocol\" @ ..\\source\\network\\udp_proto.cpp:304\n");
   std::exit(1);
}

void unknown_message()
{
   std::fprintf(stderr, "Assertion: FALSE && \"Unknown UdpMsg type.\" @ ..\\source\\network\\udp_proto.cpp:287\n");
   std::exit(1);
}

int env_clamped(const char *name, int default_value, int max_value)
{
   const char *text = std::getenv(name);
   if (text == nullptr) {
      return default_value;
   }
   const long value = std::atol(text);
   if (value == 0) {
      return default_value;
   }
   return value > max_value ? max_value : static_cast<int>(value);
}

int env_nonzero(const char *name, int default_value)
{
   const char *text = std::getenv(name);
   if (text == nullptr) {
      return default_value;
   }
   const long value = std::atol(text);
   return value == 0 ? default_value : static_cast<int>(value);
}

UdpProtocol *owner_from_receiver(void *receiver)
{
   return static_cast<UdpProtocolReceiver *>(receiver)->protocol;
}

void on_first_packet(void *receiver)
{
   udp_protocol_enqueue_event(owner_from_receiver(receiver), 0);
}

void on_packet(void *receiver, const unsigned char *data, int size)
{
   udp_protocol_handle_packet(owner_from_receiver(receiver), data, size);
}

void on_peer_disconnected(void *receiver)
{
   udp_protocol_enqueue_event(owner_from_receiver(receiver), 4);
}

bool protocol_on_handle(void *, void *)
{
   return true;
}

bool protocol_pre_idle(void *, void *)
{
   return true;
}

bool protocol_on_timer(void *, void *context, int)
{
   return udp_protocol_on_timer(static_cast<UdpProtocol *>(context));
}

bool protocol_post_idle(void *, void *)
{
   return true;
}

const UdpReceiverVTable protocol_receiver_vtable = {
   on_first_packet,
   on_packet,
   on_peer_disconnected,
};

const PollCallbackVTable protocol_poll_vtable = {
   protocol_on_handle,
   protocol_pre_idle,
   protocol_on_timer,
   protocol_post_idle,
};

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

int message_payload_size(const unsigned char *message)
{
   switch (message[0]) {
   case 1:
   case 2:
   case 5:
      return 4;
   case 3:
      return 11 + ((static_cast<int>(read_u16(message + 9)) + 7) >> 3);
   case 4:
      return 5;
   default:
      unknown_message();
   }
   return 0;
}

int message_size(const unsigned char *message)
{
   return message_payload_size(message) + 1;
}

std::vector<unsigned char> message_with_i32(unsigned char type, int value)
{
   std::vector<unsigned char> message(5, 0);
   message[0] = type;
   write_i32(&message, 1, value);
   return message;
}

std::vector<unsigned char> quality_report_message(int local_status)
{
   std::vector<unsigned char> message(6, 0);
   message[0] = 4;
   message[1] = static_cast<unsigned char>(local_status);
   write_i32(&message, 2, udp_protocol_now_ms());
   return message;
}

void log_message(UdpProtocol *, const char *prefix, const unsigned char *message)
{
   switch (message[0]) {
   case 1:
      udp_protocol_log("%s sync-request (%d).\n", prefix, read_i32(message + 1));
      break;
   case 2:
      udp_protocol_log("%s sync-reply (%d).\n", prefix, read_i32(message + 1));
      break;
   case 3:
      udp_protocol_log("%s game-compressed-input %d (+compressed).\n", prefix, read_i32(message + 1));
      break;
   case 4:
      udp_protocol_log("%s quality report.\n", prefix);
      break;
   case 5:
      udp_protocol_log("%s quality reply.\n", prefix);
      break;
   default:
      unknown_message();
   }
}

void send_sync_request(UdpProtocol *protocol)
{
   protocol->last_sync_send_time_ms = udp_protocol_now_ms();
   protocol->sync_random = std::rand() & 0xffff;
   udp_protocol_send_message(protocol, message_with_i32(1, protocol->sync_random));
}

void send_sync_reply(UdpProtocol *protocol, const unsigned char *message)
{
   udp_protocol_send_message(protocol, message_with_i32(2, read_i32(message + 1)));
}

void send_quality_reply(UdpProtocol *protocol, const unsigned char *message)
{
   udp_protocol_send_message(protocol, message_with_i32(5, read_i32(message + 2)));
   protocol->remote_connect_status = static_cast<signed char>(message[1]);
}

void handle_quality_reply(UdpProtocol *protocol, const unsigned char *message)
{
   protocol->round_trip_time_ms = udp_protocol_now_ms() - read_i32(message + 1);
}

void handle_sync_reply(UdpProtocol *protocol, const unsigned char *message)
{
   if (protocol->sync_state != 0) {
      udp_protocol_log("Ignoring SyncReply while not synching.\n");
      return;
   }
   const int received_random = read_i32(message + 1);
   if (received_random != protocol->sync_random) {
      udp_protocol_log("sync reply %d != %d.  Keep looking...\n", received_random, protocol->sync_random);
      return;
   }

   --protocol->sync_retries_remaining;
   if (protocol->sync_retries_remaining == 0) {
      udp_protocol_log("Synchronized!\n");
      udp_protocol_enqueue_event(protocol, 2);
      protocol->sync_state = 2;
      protocol->last_received_input.frame = -1;
      return;
   }

   UdpProtocolEvent event;
   event.type = 1;
   event.payload.resize(8);
   const int completed = kUdpProtocolDefaultSyncRetries - protocol->sync_retries_remaining;
   std::memcpy(event.payload.data(), &kUdpProtocolDefaultSyncRetries, sizeof(int));
   std::memcpy(event.payload.data() + 4, &completed, sizeof(int));
   udp_protocol_log("Queuing event\n");
   protocol->events.push_back(std::move(event));
   send_sync_request(protocol);
}

} // namespace

void udp_protocol_construct(UdpProtocol *protocol)
{
   protocol->poll_target.vtable = &protocol_poll_vtable;
   protocol->receiver.base.vtable = &protocol_receiver_vtable;
   protocol->receiver.protocol = protocol;
   udp_socket_construct(&protocol->udp);
   protocol->local_connect_status = 0;
   protocol->remote_connect_status = 0;
   protocol->round_trip_time_ms = 0;
   protocol->last_quality_report_time_ms = 0;
   protocol->incoming_messages.clear();
   protocol->sync_state = 0;
   protocol->last_sync_send_time_ms = 0;
   protocol->sync_retries_remaining = 0;
   protocol->sync_random = 0;
   protocol->pending_outputs.clear();
   protocol->peer_disconnect_timeout = 0;
   protocol->idle_frame_count = env_clamped("ggpo.idle.framecount", kUdpProtocolDefaultIdleFrameCount, 10);
   protocol->idle_frame_boost = env_nonzero("ggpo.idle.frameboost", kUdpProtocolDefaultIdleFrameBoost);

   game_input_construct(&protocol->last_received_input, -1, nullptr, 1);
   game_input_construct(&protocol->last_acked_input, -1, nullptr, 1);
   game_input_construct(&protocol->pending_output, -1, nullptr, 1);
   game_input_construct(&protocol->last_sent_input, -1, nullptr, 1);
   std::memset(protocol->peer_disconnect_state, 0, sizeof(protocol->peer_disconnect_state));
   protocol->events.clear();
}

void udp_protocol_destroy(UdpProtocol *protocol)
{
   protocol->events.clear();
   protocol->incoming_messages.clear();
   protocol->pending_outputs.clear();
   udp_socket_destroy(&protocol->udp);
}

void udp_protocol_bind(UdpProtocol *protocol, int local_port)
{
   udp_socket_init(&protocol->udp, local_port, &protocol->receiver.base);
}

void udp_protocol_set_remote_endpoint(UdpProtocol *protocol, const char *host, int port, PollBackend *poller)
{
   udp_socket_set_remote_endpoint(&protocol->udp, host, port, poller);
   if (poller != nullptr) {
      poll_backend_add_timer(poller, &protocol->poll_target, kUdpProtocolDefaultRetryIntervalMs, protocol);
   }
}

void udp_protocol_enqueue_event(UdpProtocol *protocol, int type)
{
   if (type == 2) {
      udp_protocol_log("%s (event: Synchronzied).\n", "Queuing event");
   } else {
      udp_protocol_log("Queuing event\n");
   }
   protocol->events.push_back({type, {}});
}

void udp_protocol_start_sync(UdpProtocol *protocol)
{
   protocol->sync_state = 0;
   protocol->sync_retries_remaining = kUdpProtocolDefaultSyncRetries;
   send_sync_request(protocol);
}

bool udp_protocol_on_timer(UdpProtocol *protocol)
{
   if (protocol->sync_state == 0) {
      if (protocol->last_sync_send_time_ms + kUdpProtocolDefaultRetryIntervalMs < udp_protocol_now_ms()) {
         udp_protocol_log("No luck after %d ms... Re-queueing sync packet.\n", kUdpProtocolDefaultRetryIntervalMs);
         send_sync_request(protocol);
      }
   } else if (protocol->sync_state == 2) {
      if (protocol->last_sync_send_time_ms == protocol->last_received_input.frame &&
          protocol->sync_retries_remaining == protocol->last_acked_input.frame) {
         udp_protocol_log("Haven't exchanged packets in a while (last received:%d  last sent:%d).  Resending.\n",
                          protocol->last_received_input.frame,
                          protocol->last_acked_input.frame);
         udp_protocol_send_compressed_input(protocol);
      }
      protocol->sync_retries_remaining = protocol->last_acked_input.frame;
      protocol->last_sync_send_time_ms = protocol->last_received_input.frame;
      udp_protocol_send_message(protocol, quality_report_message(protocol->local_connect_status));
   }
   return true;
}

void udp_protocol_handle_packet(UdpProtocol *protocol, const unsigned char *data, int size)
{
   if (size <= 0) {
      invalid_message();
   }
   if ((data[0] == 1 || data[0] == 2 || data[0] == 5) && size < 5) {
      invalid_message();
   }
   if (data[0] == 4 && size < 6) {
      invalid_message();
   }
   if (data[0] == 3 && size < 11) {
      invalid_message();
   }
   const int expected = message_size(data);
   if (size < expected) {
      invalid_message();
   }
   log_message(protocol, "recv", data);
   switch (data[0]) {
   case 1:
      send_sync_reply(protocol, data);
      break;
   case 2:
      handle_sync_reply(protocol, data);
      break;
   case 3:
      udp_protocol_handle_compressed_input(protocol, data);
      break;
   case 4:
      send_quality_reply(protocol, data);
      break;
   case 5:
      handle_quality_reply(protocol, data);
      break;
   default:
      invalid_message();
   }
}

void udp_protocol_update_local_connect_status(UdpProtocol *protocol, int current_frame)
{
   const int round_trip_frames = (protocol->round_trip_time_ms * 60) / 1000;
   const int frame_age = protocol->last_quality_report_time_ms < udp_protocol_now_ms()
                            ? ((udp_protocol_now_ms() - protocol->last_quality_report_time_ms) * 60) / 1000
                            : 0;
   protocol->local_connect_status =
      protocol->last_received_input.frame + round_trip_frames + frame_age - current_frame;
}

void udp_protocol_send_message(UdpProtocol *protocol, const std::vector<unsigned char> &message)
{
   log_message(protocol, "send", message.data());
   udp_socket_queue_send(&protocol->udp, message.data(), message_size(message.data()));
}

void udp_protocol_log(const char *format, ...)
{
   char prefixed[1200];
   std::snprintf(prefixed, sizeof(prefixed), "udp proto | %s", format);
   va_list args;
   va_start(args, format);
   quark_logv(prefixed, args);
   va_end(args);
}

int udp_protocol_now_ms()
{
   static const auto start = std::chrono::steady_clock::now();
   const auto elapsed = std::chrono::steady_clock::now() - start;
   return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count());
}

bool udp_protocol_pop_event(UdpProtocol *protocol, UdpProtocolEvent *event)
{
   if (protocol->events.empty()) {
      return false;
   }
   *event = std::move(protocol->events.front());
   protocol->events.pop_front();
   return true;
}

void udp_protocol_get_network_stats(const UdpProtocol *protocol, int *ping, int *local_frames_behind,
                                    int *remote_frames_behind, int *send_queue_len, int *kbps_sent)
{
   *ping = protocol->round_trip_time_ms;
   *local_frames_behind = protocol->local_connect_status;
   *remote_frames_behind = protocol->remote_connect_status;
   *send_queue_len = static_cast<int>(protocol->pending_outputs.size());
   *kbps_sent = static_cast<int>(protocol->udp.kbps);
}

}
