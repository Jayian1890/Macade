#include "udp_socket.hpp"

#include "logging.hpp"

#include <algorithm>
#include <arpa/inet.h>
#include <cerrno>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <sys/socket.h>
#include <utility>
#include <unistd.h>

namespace ggponet::reconstructed {
namespace {

int now_ms()
{
   static const auto start = std::chrono::steady_clock::now();
   const auto elapsed = std::chrono::steady_clock::now() - start;
   return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count());
}

void udp_log(const char *format, ...)
{
   char prefixed[1200];
   std::snprintf(prefixed, sizeof(prefixed), "udp | %s", format);
   va_list args;
   va_start(args, format);
   quark_logv(prefixed, args);
   va_end(args);
}

void assert_or_exit(bool condition, const char *expression, int line)
{
   if (!condition) {
      std::fprintf(stderr, "Assertion: %s @ ..\\source\\network\\udp.cpp:%d\n", expression, line);
      std::exit(1);
   }
}

void set_nonblocking(int fd)
{
   const int flags = fcntl(fd, F_GETFL, 0);
   if (flags >= 0) {
      fcntl(fd, F_SETFL, flags | O_NONBLOCK);
   }
}

void close_socket(UdpSocket *udp)
{
   if (udp->socket_fd != -1) {
      close(udp->socket_fd);
      udp->socket_fd = -1;
   }
}

bool on_handle(void *, void *context)
{
   return udp_socket_poll_receive(static_cast<UdpSocket *>(context));
}

bool pre_idle(void *, void *)
{
   return true;
}

bool on_timer(void *, void *context, int)
{
   return udp_socket_update_stats(static_cast<UdpSocket *>(context));
}

bool post_idle(void *, void *context)
{
   return udp_socket_flush_send_queue(static_cast<UdpSocket *>(context));
}

const PollCallbackVTable udp_poll_vtable = {
   on_handle,
   pre_idle,
   on_timer,
   post_idle,
};

} // namespace

void udp_socket_construct(UdpSocket *udp)
{
   udp->poll_target.vtable = &udp_poll_vtable;
   udp->socket_fd = -1;
   udp->local_port = -1;
   std::memset(&udp->remote_addr, 0, sizeof(udp->remote_addr));
   udp->has_remote_addr = false;
   udp->received_first_packet = false;
   udp->receive_pending = false;
   udp->network_delay_ms = 0;
   udp->receiver = nullptr;
   udp->poller = nullptr;
   udp->bytes_sent_total = 0;
   udp->packet_count = 0;
   udp->kbps = 0.0f;
   udp->packet_stats.clear();
   udp->send_queue.clear();
   std::memset(udp->receive_buffer, 0, sizeof(udp->receive_buffer));
}

void udp_socket_destroy(UdpSocket *udp)
{
   close_socket(udp);
   udp->send_queue.clear();
   udp->packet_stats.clear();
   udp->poller = nullptr;
   udp->receiver = nullptr;
}

bool udp_socket_bind(UdpSocket *udp, int port, int port_range)
{
   udp->receive_pending = false;
   close_socket(udp);

   bool bound = false;
   for (int candidate = port; candidate <= port + port_range; ++candidate) {
      const int fd = socket(AF_INET, SOCK_DGRAM, 0);
      if (fd == -1) {
         continue;
      }
      sockaddr_in local{};
      local.sin_family = AF_INET;
      local.sin_addr.s_addr = htonl(INADDR_ANY);
      local.sin_port = htons(static_cast<uint16_t>(candidate));
      if (bind(fd, reinterpret_cast<sockaddr *>(&local), sizeof(local)) == 0) {
         set_nonblocking(fd);
         udp->socket_fd = fd;
         udp->local_port = candidate;
         bound = true;
         udp_log("Udp bound to port: %d.\n", udp->local_port);
         break;
      }
      udp_log("Could not bind to port %d.  Retrying.\n", candidate);
      close(fd);
   }

   if (!bound) {
      udp->socket_fd = -1;
      return false;
   }
   if (udp->has_remote_addr && udp->poller != nullptr) {
      udp_log("Re-priming socket for port %d.\n", udp->local_port);
      poll_backend_signal(udp->poller);
   }
   return true;
}

void udp_socket_init(UdpSocket *udp, int port, UdpReceiver *receiver)
{
   const char *delay = std::getenv("ggpo.network.delay");
   udp->network_delay_ms = delay == nullptr ? 0 : static_cast<int>(std::atol(delay));
   udp->local_port = port;
   udp->receiver = receiver;
   udp_socket_bind(udp, port, 10);
}

void udp_socket_set_remote_endpoint(UdpSocket *udp, const char *host, int port, PollBackend *poller)
{
   udp->remote_addr = {};
   udp->remote_addr.sin_family = AF_INET;
   udp->remote_addr.sin_addr.s_addr = inet_addr(host);
   udp->remote_addr.sin_port = htons(static_cast<uint16_t>(port));
   udp->has_remote_addr = true;
   udp->poller = poller;

   if (poller != nullptr && udp->socket_fd != -1) {
      poll_backend_add_handle(poller, &udp->poll_target, udp->socket_fd, udp);
      poll_backend_add_timer(poller, &udp->poll_target, 1000, udp);
      poll_backend_add_idle(poller, &udp->poll_target, udp);
      udp_log("Priming socket for port %d.\n", udp->local_port);
      udp_log("Remote endpoint is %s:%d.\n", host, port);
      poll_backend_signal(poller);
   }
}

void udp_socket_queue_send(UdpSocket *udp, const unsigned char *data, int size)
{
   assert_or_exit(size >= 0 && size <= kUdpPayloadMax, "size <= MAX_UDP_PACKET_SIZE", 0xb0);
   UdpQueuedPacket packet;
   if (size > 0) {
      packet.bytes.assign(data, data + size);
   }
   packet.timestamp_ms = now_ms();
   udp->send_queue.push_back(std::move(packet));
   udp_socket_flush_send_queue(udp);
}

bool udp_socket_flush_send_queue(UdpSocket *udp)
{
   const int current_ms = now_ms();
   while (!udp->send_queue.empty()) {
      const UdpQueuedPacket &packet = udp->send_queue.front();
      if (udp->network_delay_ms != 0 && current_ms < packet.timestamp_ms + udp->network_delay_ms) {
         break;
      }
      assert_or_exit(udp->has_remote_addr, "_peer_addr.sin_addr.s_addr", 0xb8);
      const ssize_t sent = sendto(udp->socket_fd,
                                  packet.bytes.data(),
                                  packet.bytes.size(),
                                  0,
                                  reinterpret_cast<const sockaddr *>(&udp->remote_addr),
                                  sizeof(udp->remote_addr));
      assert_or_exit(sent != -1, "FALSE && \"Unknown error in sendto\"", 0xc0);
      udp->bytes_sent_total += static_cast<int>(sent);
      udp->send_queue.pop_front();
   }
   return true;
}

bool udp_socket_poll_receive(UdpSocket *udp)
{
   if (!udp->has_remote_addr || udp->socket_fd == -1) {
      return true;
   }

   while (true) {
      const ssize_t count = recv(udp->socket_fd, udp->receive_buffer, sizeof(udp->receive_buffer), 0);
      if (count >= 0) {
         if (!udp->received_first_packet && udp->receiver != nullptr) {
            udp->receiver->vtable->on_first_packet(udp->receiver);
            udp->received_first_packet = true;
         }
         if (udp->receiver != nullptr) {
            udp->receiver->vtable->on_packet(udp->receiver, udp->receive_buffer, static_cast<int>(count));
         }
         udp->receive_pending = false;
         udp->packet_stats.push_back({static_cast<int>(count), now_ms()});
         continue;
      }
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
         udp->receive_pending = true;
         return true;
      }
      if (errno == ECONNRESET) {
         if (udp->received_first_packet && udp->receiver != nullptr) {
            udp->receiver->vtable->on_peer_disconnected(udp->receiver);
            udp->received_first_packet = false;
         }
         udp_log("Got WSAECONNRESET while polling old port %d.  Reconnecting\n", udp->local_port);
         udp_socket_bind(udp, udp->local_port, 0);
         return true;
      }
      assert_or_exit(false, "FALSE && \"Unknown return value from WSARecv\"", 0x94);
   }
}

bool udp_socket_update_stats(UdpSocket *udp)
{
   const int current_ms = now_ms();
   while (!udp->packet_stats.empty() && udp->packet_stats.front().timestamp_ms < current_ms - 3000) {
      udp->packet_stats.pop_front();
   }
   if (udp->packet_stats.empty()) {
      return true;
   }

   int bytes = 0;
   udp->packet_count = 0;
   for (const UdpPacketStat &stat : udp->packet_stats) {
      bytes += stat.size + 0x2a;
      ++udp->packet_count;
   }
   const int elapsed = std::max(udp->packet_stats.back().timestamp_ms - udp->packet_stats.front().timestamp_ms, 1);
   const double seconds = static_cast<double>(elapsed) / 1000.0;
   const double bytes_per_second = static_cast<double>(bytes) / seconds;
   const double overhead = static_cast<double>(udp->packet_count * 0x2a) * 100.0 / static_cast<double>(bytes);
   udp->kbps = static_cast<float>((8.0 * bytes_per_second) / 1024.0);
   udp_log("Network Stats -- Bandwidth: %.2f KBps   Packets Sent: %5d (%.2f pps)   KB Sent: %.2f   Overhead: %.2f %%.\n",
           static_cast<double>(udp->kbps),
           udp->packet_count,
           static_cast<double>(udp->packet_count) * 1000.0 / 3000.0,
           static_cast<double>(bytes) / 1024.0,
           overhead);
   return true;
}

}
