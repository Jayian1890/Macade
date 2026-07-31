#pragma once

#include "poll_backend.hpp"

#include <cstdint>
#include <deque>
#include <netinet/in.h>
#include <vector>

namespace ggponet::reconstructed {

constexpr int kUdpPayloadMax = 0x1000;

struct UdpReceiverVTable {
   void (*on_first_packet)(void *receiver);
   void (*on_packet)(void *receiver, const unsigned char *data, int size);
   void (*on_peer_disconnected)(void *receiver);
};

struct UdpReceiver {
   const UdpReceiverVTable *vtable;
};

struct UdpPacketStat {
   int size;
   int timestamp_ms;
};

struct UdpQueuedPacket {
   std::vector<unsigned char> bytes;
   int timestamp_ms;
};

struct UdpSocket {
   PollCallbackTarget poll_target;
   int socket_fd;
   int local_port;
   sockaddr_in remote_addr;
   bool has_remote_addr;
   bool received_first_packet;
   bool receive_pending;
   int network_delay_ms;
   UdpReceiver *receiver;
   PollBackend *poller;
   int bytes_sent_total;
   int packet_count;
   float kbps;
   std::deque<UdpPacketStat> packet_stats;
   std::deque<UdpQueuedPacket> send_queue;
   unsigned char receive_buffer[kUdpPayloadMax];
};

void udp_socket_construct(UdpSocket *udp);
void udp_socket_destroy(UdpSocket *udp);
bool udp_socket_bind(UdpSocket *udp, int port, int port_range);
void udp_socket_init(UdpSocket *udp, int port, UdpReceiver *receiver);
void udp_socket_set_remote_endpoint(UdpSocket *udp, const char *host, int port, PollBackend *poller);
void udp_socket_queue_send(UdpSocket *udp, const unsigned char *data, int size);
bool udp_socket_flush_send_queue(UdpSocket *udp);
bool udp_socket_poll_receive(UdpSocket *udp);
bool udp_socket_update_stats(UdpSocket *udp);

}
