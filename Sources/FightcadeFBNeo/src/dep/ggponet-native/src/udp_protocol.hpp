#pragma once

#include "game_input.hpp"
#include "poll_backend.hpp"
#include "udp_socket.hpp"

#include <deque>
#include <vector>

namespace ggponet::reconstructed {

constexpr int kUdpProtocolDefaultSyncRetries = 5;
constexpr int kUdpProtocolDefaultIdleFrameCount = 5;
constexpr int kUdpProtocolDefaultIdleFrameBoost = 3;
constexpr int kUdpProtocolDefaultRetryIntervalMs = 1000;

struct UdpProtocol;

struct UdpProtocolReceiver {
   UdpReceiver base;
   UdpProtocol *protocol;
};

struct UdpProtocolEvent {
   int type;
   std::vector<unsigned char> payload;
};

struct UdpProtocol {
   PollCallbackTarget poll_target;
   UdpProtocolReceiver receiver;
   UdpSocket udp;
   int local_connect_status;
   int remote_connect_status;
   int round_trip_time_ms;
   int last_quality_report_time_ms;
   std::deque<std::vector<unsigned char>> incoming_messages;
   int sync_state;
   int last_sync_send_time_ms;
   int sync_retries_remaining;
   int sync_random;
   std::deque<GameInput> pending_outputs;
   GameInput pending_output;
   GameInput last_acked_input;
   GameInput last_sent_input;
   GameInput last_received_input;
   unsigned char peer_disconnect_state[12];
   int peer_disconnect_timeout;
   int idle_frame_count;
   int idle_frame_boost;
   std::deque<UdpProtocolEvent> events;
};

void udp_protocol_construct(UdpProtocol *protocol);
void udp_protocol_destroy(UdpProtocol *protocol);
void udp_protocol_bind(UdpProtocol *protocol, int local_port);
void udp_protocol_set_remote_endpoint(UdpProtocol *protocol, const char *host, int port, PollBackend *poller);
void udp_protocol_enqueue_event(UdpProtocol *protocol, int type);
void udp_protocol_start_sync(UdpProtocol *protocol);
bool udp_protocol_on_timer(UdpProtocol *protocol);
void udp_protocol_handle_packet(UdpProtocol *protocol, const unsigned char *data, int size);
void udp_protocol_update_local_connect_status(UdpProtocol *protocol, int current_frame);
void udp_protocol_send_message(UdpProtocol *protocol, const std::vector<unsigned char> &message);
void udp_protocol_send_compressed_input(UdpProtocol *protocol);
void udp_protocol_handle_compressed_input(UdpProtocol *protocol, const unsigned char *message);
void udp_protocol_send_input(UdpProtocol *protocol, const GameInput *input);
void udp_protocol_log(const char *format, ...);
int udp_protocol_now_ms();
bool udp_protocol_pop_event(UdpProtocol *protocol, UdpProtocolEvent *event);
void udp_protocol_get_network_stats(const UdpProtocol *protocol, int *ping, int *local_frames_behind,
                                    int *remote_frames_behind, int *send_queue_len, int *kbps_sent);

}
