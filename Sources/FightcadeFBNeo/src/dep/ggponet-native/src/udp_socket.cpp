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
#include <netdb.h>
#include <string>
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

bool set_nonblocking(int fd)
{
   const int flags = fcntl(fd, F_GETFL, 0);
   return flags >= 0 && fcntl(fd, F_SETFL, flags | O_NONBLOCK) == 0;
}

void close_socket(UdpSocket *udp)
{
   if (udp->socket_fd != -1) {
      close(udp->socket_fd);
      udp->socket_fd = -1;
   }
}

void notify_peer_disconnected(UdpSocket *udp)
{
   if (udp->received_first_packet && udp->receiver != nullptr) {
      udp->receiver->vtable->on_peer_disconnected(udp->receiver);
   }
   udp->received_first_packet = false;
}

bool resolve_remote_endpoint(const char *host, int port, sockaddr_in *endpoint)
{
   if (host == nullptr || host[0] == '\0' || port <= 0 || port > 65535 || endpoint == nullptr) {
      return false;
   }
   addrinfo hints{};
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_DGRAM;
   addrinfo *results = nullptr;
   const std::string service = std::to_string(port);
   if (getaddrinfo(host, service.c_str(), &hints, &results) != 0) {
      return false;
   }
   bool resolved = false;
   for (addrinfo *item = results; item != nullptr; item = item->ai_next) {
      if (item->ai_family == AF_INET && item->ai_addrlen >= sizeof(sockaddr_in)) {
         std::memcpy(endpoint, item->ai_addr, sizeof(sockaddr_in));
         resolved = true;
         break;
      }
   }
   freeaddrinfo(results);
   return resolved;
}

bool on_handle(void *, void *context)
{
   return udp_socket_poll_receive(static_cast<UdpSocket *>(context));
}

bool pre_idle(void *, void *) { return true; }

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
   if (udp == nullptr || port < 0 || port > 65535 || port_range < 0) {
      return false;
   }
   udp->receive_pending = false;
   close_socket(udp);
   const int last_port = static_cast<int>(std::min<long long>(65535, static_cast<long long>(port) + port_range));

   for (int candidate = port; candidate <= last_port; ++candidate) {
      const int fd = socket(AF_INET, SOCK_DGRAM, 0);
      if (fd == -1) {
         continue;
      }
      sockaddr_in local{};
      local.sin_family = AF_INET;
      local.sin_addr.s_addr = htonl(INADDR_ANY);
      local.sin_port = htons(static_cast<uint16_t>(candidate));
      if (bind(fd, reinterpret_cast<sockaddr *>(&local), sizeof(local)) == 0 && set_nonblocking(fd)) {
         udp->socket_fd = fd;
         udp->local_port = candidate;
         if (candidate == 0) {
            socklen_t length = sizeof(local);
            if (getsockname(fd, reinterpret_cast<sockaddr *>(&local), &length) == 0) {
               udp->local_port = ntohs(local.sin_port);
            }
         }
         udp_log("Udp bound to port: %d.\n", udp->local_port);
         if (udp->has_remote_addr && udp->poller != nullptr) {
            bool replaced = false;
            for (size_t index = 1; index < udp->poller->handle_callbacks.size(); ++index) {
               if (udp->poller->handle_callbacks[index].context == udp) {
                  udp->poller->handles[index] = fd;
                  replaced = true;
                  break;
               }
            }
            if (!replaced) {
               poll_backend_add_handle(udp->poller, &udp->poll_target, fd, udp);
            }
            udp_log("Re-priming socket for port %d.\n", udp->local_port);
            poll_backend_signal(udp->poller);
         }
         return true;
      }
      udp_log("Could not bind to port %d.  Retrying.\n", candidate);
      close(fd);
   }

   udp->socket_fd = -1;
   udp->local_port = -1;
   return false;
}

bool udp_socket_init(UdpSocket *udp, int port, UdpReceiver *receiver)
{
   const char *delay = std::getenv("ggpo.network.delay");
   udp->network_delay_ms = delay == nullptr ? 0 : std::max(0, static_cast<int>(std::atol(delay)));
   udp->receiver = receiver;
   return udp_socket_bind(udp, port, 10);
}

bool udp_socket_set_remote_endpoint(UdpSocket *udp, const char *host, int port, PollBackend *poller)
{
   sockaddr_in endpoint{};
   if (udp == nullptr || poller == nullptr || udp->socket_fd == -1 ||
       !resolve_remote_endpoint(host, port, &endpoint)) {
      if (udp != nullptr) {
         udp->has_remote_addr = false;
      }
      return false;
   }
   udp->remote_addr = endpoint;
   udp->has_remote_addr = true;
   udp->poller = poller;
   poll_backend_add_handle(poller, &udp->poll_target, udp->socket_fd, udp);
   poll_backend_add_timer(poller, &udp->poll_target, 1000, udp);
   poll_backend_add_idle(poller, &udp->poll_target, udp);
   udp_log("Priming socket for port %d.\n", udp->local_port);
   udp_log("Remote endpoint is %s:%d.\n", host, port);
   poll_backend_signal(poller);
   return true;
}

bool udp_socket_source_matches(const UdpSocket *udp, const sockaddr_in &source)
{
   return udp != nullptr && udp->has_remote_addr && source.sin_family == AF_INET &&
          source.sin_addr.s_addr == udp->remote_addr.sin_addr.s_addr && source.sin_port == udp->remote_addr.sin_port;
}

bool udp_socket_queue_send(UdpSocket *udp, const unsigned char *data, int size)
{
   if (udp == nullptr || size < 0 || size > kUdpPayloadMax || (size > 0 && data == nullptr) ||
       udp->socket_fd == -1 || !udp->has_remote_addr) {
      udp_log("Dropped invalid UDP send request (%d bytes).\n", size);
      return false;
   }
   UdpQueuedPacket packet;
   if (size > 0) {
      packet.bytes.assign(data, data + size);
   }
   packet.timestamp_ms = now_ms();
   udp->send_queue.push_back(std::move(packet));
   return udp_socket_flush_send_queue(udp);
}

bool udp_socket_flush_send_queue(UdpSocket *udp)
{
   if (udp == nullptr || udp->socket_fd == -1 || !udp->has_remote_addr) {
      return false;
   }
   const int current_ms = now_ms();
   while (!udp->send_queue.empty()) {
      const UdpQueuedPacket &packet = udp->send_queue.front();
      if (udp->network_delay_ms != 0 && current_ms < packet.timestamp_ms + udp->network_delay_ms) {
         break;
      }
      const ssize_t sent = sendto(udp->socket_fd, packet.bytes.data(), packet.bytes.size(), 0,
                                  reinterpret_cast<const sockaddr *>(&udp->remote_addr), sizeof(udp->remote_addr));
      if (sent == static_cast<ssize_t>(packet.bytes.size())) {
         udp->bytes_sent_total += static_cast<int>(sent);
         udp->send_queue.pop_front();
         continue;
      }
      if (sent < 0 && errno == EINTR) {
         continue;
      }
      if (sent < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
         return true;
      }
      udp_log("Permanent sendto failure on port %d: %s.\n", udp->local_port, std::strerror(errno));
      notify_peer_disconnected(udp);
      udp->send_queue.clear();
      return false;
   }
   return true;
}

bool udp_socket_poll_receive(UdpSocket *udp)
{
   if (udp == nullptr || !udp->has_remote_addr || udp->socket_fd == -1) {
      return false;
   }

   while (true) {
      sockaddr_in source{};
      socklen_t source_length = sizeof(source);
      const ssize_t count = recvfrom(udp->socket_fd, udp->receive_buffer, sizeof(udp->receive_buffer), 0,
                                     reinterpret_cast<sockaddr *>(&source), &source_length);
      if (count >= 0) {
         if (source_length < sizeof(sockaddr_in) || !udp_socket_source_matches(udp, source)) {
            udp_log("Dropped UDP packet from unexpected endpoint.\n");
            continue;
         }
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
      if (errno == EINTR) {
         continue;
      }
      if (errno == EAGAIN || errno == EWOULDBLOCK) {
         udp->receive_pending = true;
         return true;
      }
      if (errno == ECONNRESET) {
         notify_peer_disconnected(udp);
         udp_log("Got ECONNRESET while polling old port %d.  Reconnecting.\n", udp->local_port);
         return udp_socket_bind(udp, udp->local_port, 0);
      }
      udp_log("Permanent recvfrom failure on port %d: %s.\n", udp->local_port, std::strerror(errno));
      notify_peer_disconnected(udp);
      return false;
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
           static_cast<double>(udp->kbps), udp->packet_count,
           static_cast<double>(udp->packet_count) * 1000.0 / 3000.0,
           static_cast<double>(bytes) / 1024.0, overhead);
   return true;
}

}
