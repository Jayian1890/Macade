#include "client_backend.hpp"

#include "client_backend_internal.hpp"
#include "logging.hpp"
#include "macade_proxy_config.hpp"
#include "tcp_framing.hpp"

#include <algorithm>
#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <deque>
#include <fcntl.h>
#include <map>
#include <netdb.h>
#include <new>
#include <string>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

namespace ggponet::reconstructed {
namespace {

bool set_nonblocking(int fd)
{
   const int flags = fcntl(fd, F_GETFL, 0);
   return flags >= 0 && fcntl(fd, F_SETFL, flags | O_NONBLOCK) == 0;
}

bool finish_connect(int fd)
{
   fd_set writes;
   FD_ZERO(&writes);
   FD_SET(fd, &writes);
   timeval timeout{2, 0};
   if (select(fd + 1, nullptr, &writes, nullptr, &timeout) <= 0) {
      return false;
   }
   int error = 0;
   socklen_t error_size = sizeof(error);
   return getsockopt(fd, SOL_SOCKET, SO_ERROR, &error, &error_size) == 0 && error == 0;
}

int connect_client_socket(int server_port)
{
   addrinfo hints{};
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
   addrinfo *results = nullptr;
   const std::string port = std::to_string(server_port);
   if (getaddrinfo("ggpo.fightcade.com", port.c_str(), &hints, &results) != 0) {
      return -1;
   }
   int connected = -1;
   for (int local_port = kClientLocalPort; local_port <= kClientLocalPort + 5 && connected < 0; ++local_port) {
      for (addrinfo *item = results; item != nullptr && connected < 0; item = item->ai_next) {
         const int fd = socket(item->ai_family, item->ai_socktype, item->ai_protocol);
         if (fd < 0) {
            continue;
         }
#ifdef SO_NOSIGPIPE
         int no_sigpipe = 1;
         setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE, &no_sigpipe, sizeof(no_sigpipe));
#endif
         sockaddr_in local{};
         local.sin_family = AF_INET;
         local.sin_addr.s_addr = htonl(INADDR_ANY);
         local.sin_port = htons(static_cast<uint16_t>(local_port));
         if (bind(fd, reinterpret_cast<sockaddr *>(&local), sizeof(local)) == 0 && set_nonblocking(fd) &&
             (connect(fd, item->ai_addr, item->ai_addrlen) == 0 || (errno == EINPROGRESS && finish_connect(fd)))) {
            connected = fd;
         } else {
            close(fd);
         }
      }
   }
   freeaddrinfo(results);
   return connected;
}

void queue_disconnect(ClientBackend *client)
{
   if (client->socket_fd >= 0) {
      close(client->socket_fd);
      client->socket_fd = -1;
   }
   if (!client->disconnected) {
      client->disconnected = true;
      client->events.push_back({10});
   }
}

void send_command(ClientBackend *client, int command, const std::vector<unsigned char> &payload)
{
   quark_log("Sending command %d to server.\n", command);
   const unsigned int sequence = client->next_sequence;
   if (!tcp_append_command(&client->send_buffer, sequence, command, payload)) {
      quark_log("TcpProtocol rejected oversized command %d (%zu bytes).\n", command, payload.size());
      queue_disconnect(client);
      return;
   }
   ++client->next_sequence;
   client->pending_commands[sequence] = command;
}

void send_version(ClientBackend *client)
{
   std::vector<unsigned char> payload;
   tcp_append_be32(&payload, 0);
   tcp_append_be32(&payload, 0x1d);
   tcp_append_be32(&payload, 1);
   send_command(client, 0, payload);
}

void flush_socket(ClientBackend *client)
{
   while (client->socket_fd >= 0 && client->send_offset < client->send_buffer.size()) {
      const ssize_t sent = send(client->socket_fd, client->send_buffer.data() + client->send_offset,
                                client->send_buffer.size() - client->send_offset, 0);
      if (sent > 0) {
         client->send_offset += static_cast<size_t>(sent);
      } else if (sent < 0 && errno == EINTR) {
         continue;
      } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
         return;
      } else {
         queue_disconnect(client);
         return;
      }
   }
   if (client->send_offset == client->send_buffer.size()) {
      client->send_buffer.clear();
      client->send_offset = 0;
   }
}

void parse_matchinfo(ClientBackend *client, const unsigned char *payload, size_t size)
{
   size_t offset = 0;
   ClientEvent event{};
   event.type = 0xb;
   if (tcp_read_string(payload, size, &offset, &event.p1) && tcp_read_string(payload, size, &offset, &event.p2) &&
       tcp_read_string(payload, size, &offset, &event.blurb) && offset <= size && size - offset >= 4) {
      event.count = static_cast<int>(tcp_read_be32(payload + offset));
      client->events.push_back(std::move(event));
   } else {
      quark_log("TcpProtocol dropped malformed matchinfo response (%zu bytes).\n", size);
   }
}

void parse_server_event(ClientBackend *client, int code, const unsigned char *payload, size_t size)
{
   quark_log("TcpProtocol received server event %d (%zu bytes).\n", code, size);
   if (code == 7) {
      size_t offset = 0;
      ClientEvent event{};
      event.type = 8;
      if (tcp_read_string(payload, size, &offset, &event.p1) && offset <= size && size - offset >= 8) {
         event.remote_port = static_cast<int>(tcp_read_be32(payload + offset));
         event.player_side = static_cast<int>(tcp_read_be32(payload + offset + 4));
         if (event.p1.empty() || event.remote_port <= 0 || event.remote_port > 65535 ||
             (event.player_side != 0 && event.player_side != 1)) {
            quark_log("TcpProtocol dropped invalid match endpoint event.\n");
            return;
         }
         quark_log("Starting match %s (port %d).\n", event.p1.c_str(), event.remote_port);
         client->events.push_back(std::move(event));
      } else {
         quark_log("TcpProtocol dropped malformed match start event (%zu bytes).\n", size);
      }
   } else if (code == 8) {
      size_t offset = 0;
      ClientEvent event{};
      event.type = 0xc;
      if (tcp_read_string(payload, size, &offset, &event.match_id) && tcp_read_string(payload, size, &offset, &event.p1) &&
          tcp_read_string(payload, size, &offset, &event.p2)) {
         client->events.push_back(std::move(event));
      }
   } else if (code == 9) {
      client->events.push_back({10});
   } else if (code == 10 && size >= 4) {
      client->events.push_back({0x10, static_cast<int>(tcp_read_be32(payload))});
   } else if (code == 11) {
      client->events.push_back({0x11});
   }
}

void parse_response(ClientBackend *client, unsigned int sequence, int response, const unsigned char *payload, size_t size)
{
   auto found = client->pending_commands.find(sequence);
   if (found == client->pending_commands.end()) {
      quark_log("TcpProtocol dropped response for unknown sequence %u (%d, %zu bytes).\n", sequence, response, size);
      return;
   }
   const int command = found->second;
   client->pending_commands.erase(found);
   quark_log("TcpProtocol received response for command %d: %d (%zu bytes).\n", command, response, size);
   if (command == 0) {
      client->events.push_back({response == 0 ? 0 : 10});
   } else if (command == 0xc && response == 0) {
      parse_matchinfo(client, payload, size);
   }
}

void parse_packets(ClientBackend *client)
{
   while (true) {
      std::vector<unsigned char> frame;
      const TcpFrameStatus status = tcp_take_frame(&client->receive_buffer, &frame);
      if (status == TcpFrameStatus::incomplete) {
         return;
      }
      if (status == TcpFrameStatus::invalid) {
         quark_log("TcpProtocol rejected oversized frame.\n");
         client->receive_buffer.clear();
         queue_disconnect(client);
         return;
      }
      if (frame.size() < 4) {
         quark_log("TcpProtocol dropped short packet length %zu.\n", frame.size());
         continue;
      }
      const unsigned char *packet = frame.data();
      const int sequence_or_event = static_cast<int>(tcp_read_be32(packet));
      if (sequence_or_event < 0) {
         parse_server_event(client, -sequence_or_event, packet + 4, frame.size() - 4);
      } else if (frame.size() >= 8) {
         parse_response(client, static_cast<unsigned int>(sequence_or_event),
                        static_cast<int>(tcp_read_be32(packet + 4)), packet + 8, frame.size() - 8);
      }
   }
}

void poll_socket(ClientBackend *client)
{
   if (client->socket_fd < 0) {
      return;
   }
   fd_set reads;
   fd_set writes;
   FD_ZERO(&reads);
   FD_ZERO(&writes);
   FD_SET(client->socket_fd, &reads);
   if (client->send_offset < client->send_buffer.size()) {
      FD_SET(client->socket_fd, &writes);
   }
   timeval timeout{0, 0};
   const int selected = select(client->socket_fd + 1, &reads, &writes, nullptr, &timeout);
   if (selected < 0) {
      if (errno != EINTR) {
         queue_disconnect(client);
      }
      return;
   }
   if (selected == 0) {
      return;
   }
   if (FD_ISSET(client->socket_fd, &writes)) {
      flush_socket(client);
   }
   if (client->socket_fd >= 0 && FD_ISSET(client->socket_fd, &reads)) {
      unsigned char bytes[4096];
      while (client->socket_fd >= 0) {
         const ssize_t received = recv(client->socket_fd, bytes, sizeof(bytes), 0);
         if (received > 0) {
            client->receive_buffer.insert(client->receive_buffer.end(), bytes, bytes + received);
            parse_packets(client);
            if (client->socket_fd < 0) {
               break;
            }
         } else if (received == 0) {
            queue_disconnect(client);
            break;
         } else if (errno == EINTR) {
            continue;
         } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
            break;
         } else {
            queue_disconnect(client);
            break;
         }
      }
   }
}

void emit_client_event(ClientBackend *client, GGPOClientEvent *event)
{
   client->peer.callbacks.on_event(reinterpret_cast<GGPOEvent *>(event));
}

void send_string_command(ClientBackend *client, int command, const std::string &text)
{
   std::vector<unsigned char> payload;
   tcp_append_string(&payload, text);
   send_command(client, command, payload);
}

void send_connect_command(ClientBackend *client)
{
   std::vector<unsigned char> payload;
   tcp_append_string(&payload, client->match_id);
   tcp_append_be32(&payload, static_cast<uint32_t>(macade_proxy_register_port(client->peer.udp.udp.local_port)));
   send_command(client, 0xb, payload);
}

void send_chat_command(ClientBackend *client, const char *text)
{
   std::vector<unsigned char> payload;
   tcp_append_string(&payload, client->match_id);
   tcp_append_string(&payload, text != nullptr ? text : "");
   send_command(client, 0xf, payload);
}

void process_events(ClientBackend *client)
{
   while (!client->events.empty()) {
      ClientEvent event = std::move(client->events.front());
      client->events.pop_front();
      GGPOClientEvent callback{};
      if (event.type == 0) {
         send_connect_command(client);
         callback.code = GGPOCLIENT_EVENTCODE_CONNECTED;
         emit_client_event(client, &callback);
      } else if (event.type == 8) {
         MacadeProxyConfig proxy = macade_proxy_config();
         std::string remote_host = proxy.enabled ? proxy.host : event.p1;
         const int remote_port = proxy.enabled ? proxy.port : event.remote_port;
         if (proxy.enabled) {
            quark_log("Using Macade GGPO proxy endpoint %s:%d for served match peer UDP.\n", remote_host.c_str(),
                      remote_port);
         }
         if (!peer_session_connect(&client->peer, remote_host.data(), remote_port, event.player_side == 0)) {
            quark_log("Could not configure served match peer UDP endpoint %s:%d.\n", remote_host.c_str(), remote_port);
            queue_disconnect(client);
            continue;
         }
         client->spectator_source = event.player_side == 0;
         client->replay_source = event.player_side == 0;
         send_string_command(client, 0xc, client->match_id);
         callback.code = GGPOCLIENT_EVENTCODE_RETREIVING_MATCHINFO;
         emit_client_event(client, &callback);
      } else if (event.type == 0xb) {
         client->p1 = event.p1;
         client->p2 = event.p2;
         client->blurb = event.blurb;
         client->spectator_count = event.count;
         callback.code = GGPOCLIENT_EVENTCODE_MATCHINFO;
         callback.u.matchinfo.p1 = client->p1.data();
         callback.u.matchinfo.p2 = client->p2.data();
         callback.u.matchinfo.blurb = client->blurb.data();
         emit_client_event(client, &callback);
         callback = {};
         callback.code = GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED;
         callback.u.spectator_count_changed.count = client->spectator_count;
         emit_client_event(client, &callback);
         callback = {};
         callback.code = GGPOCLIENT_EVENTCODE_CHAT;
         callback.u.chat.username = const_cast<char *>("System");
         callback.u.chat.text = const_cast<char *>("Press 'T' to chat...");
         emit_client_event(client, &callback);
      } else if (event.type == 0x10) {
         client->spectator_count = event.count;
         callback.code = GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED;
         callback.u.spectator_count_changed.count = client->spectator_count;
         emit_client_event(client, &callback);
      } else if (event.type == 0xc) {
         if (event.match_id != client->match_id) {
            return;
         }
         callback.code = GGPOCLIENT_EVENTCODE_CHAT;
         callback.u.chat.username = event.p1.data();
         callback.u.chat.text = event.p2.data();
         emit_client_event(client, &callback);
      } else if (event.type == 0x11) {
         client_schedule_replay_upload(client);
      } else if (event.type == 10) {
         quark_log("Got disconnect event from TcpProtocol.\n");
         callback.code = GGPOCLIENT_EVENTCODE_DISCONNECTED;
         emit_client_event(client, &callback);
         return;
      }
   }
}

ClientBackend *client(GGPOSession *session)
{
   return reinterpret_cast<ClientBackend *>(session);
}

bool client_idle(GGPOSession *session, int timeout)
{
   ClientBackend *backend = client(session);
   const bool result = peer_backend_idle(&backend->peer, timeout);
   if (result && !backend->peer.in_poll) {
      poll_socket(backend);
      process_events(backend);
      flush_socket(backend);
   }
   return result;
}

bool client_synchronize_input(GGPOSession *session, void *values, int size, int players)
{
   return peer_backend_synchronize_input(&client(session)->peer, values, size, players);
}

bool client_advance_frame(GGPOSession *session)
{
   return peer_backend_advance_frame(&client(session)->peer);
}

bool client_chat(GGPOSession *session, char *text)
{
   ClientBackend *backend = client(session);
   if (backend->match_id.empty()) {
      return false;
   }
   send_chat_command(backend, text);
   flush_socket(backend);
   return true;
}

bool client_get_stats(GGPOSession *session, GGPONetworkStats *stats)
{
   return peer_backend_get_stats(&client(session)->peer, stats);
}

bool client_set_game_event(GGPOSession *session, GGPOClientGameEventType type, void *data)
{
   return client_handle_game_event_upload(client(session), type, data);
}

void client_logv(GGPOSession *session, char *fmt, va_list args)
{
   peer_backend_logv(&client(session)->peer, fmt, args);
}

bool client_set_frame_delay(GGPOSession *session, int frame_delay)
{
   return peer_backend_set_frame_delay(&client(session)->peer, frame_delay);
}

void client_destroy(GGPOSession *session)
{
   ClientBackend *backend = client(session);
   if (backend->socket_fd >= 0) {
      close(backend->socket_fd);
   }
   peer_backend_teardown(&backend->peer);
   delete backend;
}

const GGPOSessionVTable client_vtable = {
   client_idle,       client_synchronize_input, client_advance_frame, client_chat, client_get_stats,
   client_set_game_event, client_logv,          client_set_frame_delay, client_destroy,
};
} // namespace

GGPOSession *create_client_session(GGPOSessionCallbacks *callbacks, char *game, char *match_id, int server_port)
{
   auto *backend = new (std::nothrow) ClientBackend{};
   if (backend == nullptr) {
      return nullptr;
   }
   backend->game = game != nullptr ? game : "";
   backend->match_id = match_id != nullptr ? match_id : "";
   if (!peer_backend_construct(&backend->peer, &client_vtable, callbacks, backend->game.data(), kPeerLocalPort)) {
      delete backend;
      return nullptr;
   }
   backend->peer.confirmed_input_hook = client_confirmed_input_hook;
   backend->socket_fd = connect_client_socket(server_port);
   backend->disconnected = backend->socket_fd < 0;
   backend->next_sequence = 0;
   backend->send_offset = 0;
   backend->spectator_count = 0;
   backend->winner = -1;
   if (backend->socket_fd >= 0) {
      send_version(backend);
   } else {
      backend->events.push_back({10});
   }
   GGPOClientEvent event{};
   event.code = GGPOCLIENT_EVENTCODE_CONNECTING;
   emit_client_event(backend, &event);
   return &backend->peer.base;
}

}
