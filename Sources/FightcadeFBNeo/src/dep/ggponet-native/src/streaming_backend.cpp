#include "streaming_backend.hpp"

#include "logging.hpp"

#include <algorithm>
#include <arpa/inet.h>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <deque>
#include <fcntl.h>
#include <map>
#include <netdb.h>
#include <string>
#include <sys/select.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include <zlib.h>

namespace ggponet::reconstructed {
namespace {

constexpr int kGameInputMaxBytes = 0x12;
constexpr int kDefaultLocalPort = 0x1774;

struct GameInputRecord {
   int frame;
   int size;
   unsigned char bits[kGameInputMaxBytes];
   unsigned char padding[2];
};

struct TcpEvent {
   int type;
   int count;
   std::string p1;
   std::string p2;
   std::string blurb;
   std::vector<unsigned char> compressed_state;
   int state_size;
   GameInputRecord input;
};

struct StreamingBackend {
   const GGPOSessionVTable *vtable;
   GGPOSessionCallbacks callbacks;
   int socket_fd;
   bool disconnected;
   unsigned int next_sequence;
   std::string game;
   std::string match_id;
   std::vector<unsigned char> receive_buffer;
   std::vector<unsigned char> send_buffer;
   size_t send_offset;
   std::map<unsigned int, int> pending_commands;
   std::deque<TcpEvent> events;
   std::vector<GameInputRecord> inputs;
   std::vector<unsigned char> initial_state;
   unsigned int input_cursor;
   std::string p1;
   std::string p2;
   std::string blurb;
   int spectator_count;
};

uint32_t read_be32(const unsigned char *bytes)
{
   uint32_t value;
   std::memcpy(&value, bytes, sizeof(value));
   return ntohl(value);
}

void append_be32(std::vector<unsigned char> *buffer, uint32_t value)
{
   const uint32_t be = htonl(value);
   const auto *bytes = reinterpret_cast<const unsigned char *>(&be);
   buffer->insert(buffer->end(), bytes, bytes + sizeof(be));
}

bool read_string(const unsigned char *payload, size_t size, size_t *offset, std::string *value)
{
   if (*offset + 4 > size) {
      return false;
   }
   const uint32_t length = read_be32(payload + *offset);
   *offset += 4;
   if (*offset + length > size) {
      return false;
   }
   value->assign(reinterpret_cast<const char *>(payload + *offset), length);
   *offset += length;
   return true;
}

void append_string(std::vector<unsigned char> *payload, const std::string &value)
{
   append_be32(payload, static_cast<uint32_t>(value.size()));
   payload->insert(payload->end(), value.begin(), value.end());
}

void queue_event(StreamingBackend *backend, TcpEvent event)
{
   backend->events.push_back(std::move(event));
}

void queue_disconnect(StreamingBackend *backend)
{
   if (!backend->disconnected) {
      backend->disconnected = true;
      queue_event(backend, TcpEvent{2});
   }
}

bool set_nonblocking(int fd)
{
   const int flags = fcntl(fd, F_GETFL, 0);
   return flags >= 0 && fcntl(fd, F_SETFL, flags | O_NONBLOCK) == 0;
}

bool finish_connect(int fd, int timeout_seconds)
{
   fd_set writes;
   FD_ZERO(&writes);
   FD_SET(fd, &writes);
   timeval timeout{timeout_seconds, 0};
   if (select(fd + 1, nullptr, &writes, nullptr, &timeout) <= 0) {
      return false;
   }
   int error = 0;
   socklen_t error_size = sizeof(error);
   return getsockopt(fd, SOL_SOCKET, SO_ERROR, &error, &error_size) == 0 && error == 0;
}

int connect_socket(int server_port)
{
   addrinfo hints = {};
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;

   addrinfo *results = nullptr;
   const std::string port = std::to_string(server_port);
   if (getaddrinfo("ggpo.fightcade.com", port.c_str(), &hints, &results) != 0) {
      return -1;
   }

   int connected = -1;
   for (int local_port = kDefaultLocalPort; local_port <= kDefaultLocalPort + 5 && connected < 0; ++local_port) {
      for (addrinfo *item = results; item != nullptr && connected < 0; item = item->ai_next) {
         const int fd = socket(item->ai_family, item->ai_socktype, item->ai_protocol);
         if (fd < 0) {
            continue;
         }
#ifdef SO_NOSIGPIPE
         int no_sigpipe = 1;
         setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE, &no_sigpipe, sizeof(no_sigpipe));
#endif
         sockaddr_in local = {};
         local.sin_family = AF_INET;
         local.sin_addr.s_addr = htonl(INADDR_ANY);
         local.sin_port = htons(static_cast<uint16_t>(local_port));
         if (bind(fd, reinterpret_cast<sockaddr *>(&local), sizeof(local)) != 0 || !set_nonblocking(fd)) {
            close(fd);
            continue;
         }
         const int result = connect(fd, item->ai_addr, item->ai_addrlen);
         if (result == 0 || (errno == EINPROGRESS && finish_connect(fd, 2))) {
            connected = fd;
         } else {
            close(fd);
         }
      }
   }
   freeaddrinfo(results);
   return connected;
}

void send_command(StreamingBackend *backend, int command, const std::vector<unsigned char> &payload)
{
   const unsigned int sequence = backend->next_sequence++;
   backend->pending_commands[sequence] = command;
   append_be32(&backend->send_buffer, static_cast<uint32_t>(payload.size() + 8));
   append_be32(&backend->send_buffer, sequence);
   append_be32(&backend->send_buffer, static_cast<uint32_t>(command));
   backend->send_buffer.insert(backend->send_buffer.end(), payload.begin(), payload.end());
}

void send_version(StreamingBackend *backend)
{
   std::vector<unsigned char> payload;
   append_be32(&payload, 0);
   append_be32(&payload, 0x1d);
   append_be32(&payload, 1);
   send_command(backend, 0, payload);
}

void send_match_string(StreamingBackend *backend, int command)
{
   std::vector<unsigned char> payload;
   append_string(&payload, backend->match_id);
   send_command(backend, command, payload);
}

void parse_matchinfo(StreamingBackend *backend, const unsigned char *payload, size_t size)
{
   size_t offset = 0;
   TcpEvent event = {};
   event.type = 0xb;
   if (!read_string(payload, size, &offset, &event.p1) || !read_string(payload, size, &offset, &event.p2) ||
       !read_string(payload, size, &offset, &event.blurb) || offset + 4 > size) {
      return;
   }
   event.count = static_cast<int>(read_be32(payload + offset));
   queue_event(backend, std::move(event));
}

void parse_server_event(StreamingBackend *backend, int event_code, const unsigned char *payload, size_t size)
{
   if (event_code == 9) {
      queue_event(backend, TcpEvent{10});
   } else if (event_code == 10 && size >= 4) {
      TcpEvent event = {};
      event.type = 0x10;
      event.count = static_cast<int>(read_be32(payload));
      queue_event(backend, std::move(event));
   } else if (event_code == 12 && size >= 4) {
      const uint32_t state_size = read_be32(payload);
      TcpEvent event = {};
      event.type = 0xf;
      event.state_size = static_cast<int>(state_size);
      event.compressed_state.assign(payload + 4, payload + size);
      queue_event(backend, std::move(event));
   } else if (event_code == 13 && size >= 8) {
      const int input_size = static_cast<int>(read_be32(payload));
      const int count = static_cast<int>(read_be32(payload + 4));
      if (input_size <= 0 || input_size > kGameInputMaxBytes || count < 0 ||
          static_cast<size_t>(count) > (size - 8) / static_cast<size_t>(input_size)) {
         return;
      }
      for (int i = 0; i < count; ++i) {
         TcpEvent event = {};
         event.type = 0xe;
         event.input.frame = 0;
         event.input.size = input_size;
         std::memset(event.input.bits, 0, sizeof(event.input.bits));
         std::memcpy(event.input.bits, payload + 8 + static_cast<size_t>(i * input_size), input_size);
         queue_event(backend, std::move(event));
      }
   }
}

void parse_response(StreamingBackend *backend, unsigned int sequence, int response, const unsigned char *payload, size_t size)
{
   auto found = backend->pending_commands.find(sequence);
   if (found == backend->pending_commands.end()) {
      return;
   }
   const int command = found->second;
   backend->pending_commands.erase(found);
   if (command == 0) {
      queue_event(backend, TcpEvent{response == 0 ? 0 : 2});
   } else if (command == 0xc && response == 0) {
      parse_matchinfo(backend, payload, size);
   }
}

void parse_packets(StreamingBackend *backend)
{
   while (backend->receive_buffer.size() >= 4) {
      const uint32_t length = read_be32(backend->receive_buffer.data());
      if (backend->receive_buffer.size() < static_cast<size_t>(length + 4)) {
         return;
      }
      if (length < 4) {
         backend->receive_buffer.erase(backend->receive_buffer.begin(), backend->receive_buffer.begin() + length + 4);
         continue;
      }
      const unsigned char *packet = backend->receive_buffer.data() + 4;
      const int sequence_or_event = static_cast<int>(read_be32(packet));
      if (sequence_or_event < 0) {
         parse_server_event(backend, -sequence_or_event, packet + 4, length - 4);
      } else if (length >= 8) {
         parse_response(backend, static_cast<unsigned int>(sequence_or_event), static_cast<int>(read_be32(packet + 4)),
                        packet + 8, length - 8);
      }
      backend->receive_buffer.erase(backend->receive_buffer.begin(), backend->receive_buffer.begin() + length + 4);
   }
}

void flush_socket(StreamingBackend *backend)
{
   while (backend->socket_fd >= 0 && backend->send_offset < backend->send_buffer.size()) {
      const ssize_t sent = send(backend->socket_fd, backend->send_buffer.data() + backend->send_offset,
                                backend->send_buffer.size() - backend->send_offset, 0);
      if (sent > 0) {
         backend->send_offset += static_cast<size_t>(sent);
      } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
         return;
      } else {
         queue_disconnect(backend);
         return;
      }
   }
   if (backend->send_offset == backend->send_buffer.size()) {
      backend->send_buffer.clear();
      backend->send_offset = 0;
   }
}

void poll_socket(StreamingBackend *backend, int timeout)
{
   if (backend->socket_fd < 0) {
      std::this_thread::sleep_for(std::chrono::milliseconds(std::max(timeout, 0)));
      return;
   }
   fd_set reads;
   fd_set writes;
   FD_ZERO(&reads);
   FD_ZERO(&writes);
   FD_SET(backend->socket_fd, &reads);
   if (backend->send_offset < backend->send_buffer.size()) {
      FD_SET(backend->socket_fd, &writes);
   }
   timeval wait{timeout / 1000, (timeout % 1000) * 1000};
   const int result = select(backend->socket_fd + 1, &reads, &writes, nullptr, timeout >= 0 ? &wait : nullptr);
   if (result < 0) {
      if (errno != EINTR) {
         queue_disconnect(backend);
      }
      return;
   }
   if (FD_ISSET(backend->socket_fd, &writes)) {
      flush_socket(backend);
   }
   if (FD_ISSET(backend->socket_fd, &reads)) {
      unsigned char bytes[4096];
      while (true) {
         const ssize_t received = recv(backend->socket_fd, bytes, sizeof(bytes), 0);
         if (received > 0) {
            backend->receive_buffer.insert(backend->receive_buffer.end(), bytes, bytes + received);
         } else if (received == 0) {
            queue_disconnect(backend);
            break;
         } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
            break;
         } else {
            queue_disconnect(backend);
            break;
         }
      }
      parse_packets(backend);
   }
}

bool process_event(StreamingBackend *backend, const TcpEvent &event)
{
   if (event.type == 0) {
      send_match_string(backend, 0x14);
      send_match_string(backend, 0xc);
   } else if (event.type == 2) {
      return false;
   } else if (event.type == 10) {
      GGPOClientEvent callback = {};
      callback.code = GGPOCLIENT_EVENTCODE_DISCONNECTED;
      backend->callbacks.on_event(reinterpret_cast<GGPOEvent *>(&callback));
      return false;
   } else if (event.type == 0xb) {
      backend->p1 = event.p1;
      backend->p2 = event.p2;
      backend->blurb = event.blurb;
      backend->spectator_count = event.count;
      GGPOClientEvent info = {};
      info.code = GGPOCLIENT_EVENTCODE_MATCHINFO;
      info.u.matchinfo.p1 = backend->p1.data();
      info.u.matchinfo.p2 = backend->p2.data();
      info.u.matchinfo.blurb = backend->blurb.data();
      backend->callbacks.on_event(reinterpret_cast<GGPOEvent *>(&info));
      GGPOClientEvent count = {};
      count.code = GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED;
      count.u.spectator_count_changed.count = backend->spectator_count;
      backend->callbacks.on_event(reinterpret_cast<GGPOEvent *>(&count));
   } else if (event.type == 0xe) {
      backend->inputs.push_back(event.input);
   } else if (event.type == 0xf) {
      std::vector<unsigned char> state(static_cast<size_t>(event.state_size));
      uLongf state_size = static_cast<uLongf>(state.size());
      if (uncompress(state.data(), &state_size, event.compressed_state.data(), event.compressed_state.size()) == Z_OK) {
         backend->initial_state.assign(state.data(), state.data() + state_size);
         backend->callbacks.load_game_state(state.data(), static_cast<int>(state_size));
      }
   } else if (event.type == 0x10) {
      backend->spectator_count = event.count;
      GGPOClientEvent callback = {};
      callback.code = GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED;
      callback.u.spectator_count_changed.count = backend->spectator_count;
      backend->callbacks.on_event(reinterpret_cast<GGPOEvent *>(&callback));
   }
   return true;
}

bool __cdecl streaming_idle(GGPOSession *session, int timeout)
{
   auto *backend = reinterpret_cast<StreamingBackend *>(session);
   poll_socket(backend, timeout);
   while (!backend->events.empty()) {
      TcpEvent event = std::move(backend->events.front());
      backend->events.pop_front();
      if (!process_event(backend, event)) {
         return false;
      }
   }
   flush_socket(backend);
   return true;
}

bool __cdecl streaming_synchronize_input(GGPOSession *session, void *values, int size, int players)
{
   auto *backend = reinterpret_cast<StreamingBackend *>(session);
   if (backend->input_cursor >= backend->inputs.size()) {
      return false;
   }
   const int copied_players = players < 3 ? players : 2;
   const size_t copied_size = static_cast<size_t>(size * copied_players);
   std::memcpy(values, backend->inputs[backend->input_cursor++].bits, copied_size);
   return true;
}

bool __cdecl streaming_return_true(GGPOSession *) { return true; }
bool __cdecl streaming_client_chat(GGPOSession *, char *) { return true; }
bool __cdecl streaming_get_stats(GGPOSession *, GGPONetworkStats *) { return true; }
bool __cdecl streaming_client_set_game_event(GGPOSession *, GGPOClientGameEventType, void *) { return true; }
bool __cdecl streaming_set_frame_delay(GGPOSession *, int) { return true; }

void __cdecl streaming_logv(GGPOSession *, char *format, va_list args)
{
   function_10001380_logv(format, args);
}

void __cdecl streaming_destroy(GGPOSession *session)
{
   auto *backend = reinterpret_cast<StreamingBackend *>(session);
   if (backend->socket_fd >= 0) {
      close(backend->socket_fd);
   }
   delete backend;
}

const GGPOSessionVTable streaming_vtable = {
   streaming_idle,          streaming_synchronize_input, streaming_return_true, streaming_client_chat,
   streaming_get_stats,     streaming_client_set_game_event, streaming_logv,    streaming_set_frame_delay,
   streaming_destroy,
};

} // namespace

GGPOSession *create_streaming_session(GGPOSessionCallbacks *callbacks, const char *game, const char *match_id, int server_port)
{
   auto *backend = new StreamingBackend();
   backend->vtable = &streaming_vtable;
   std::memcpy(&backend->callbacks, callbacks, sizeof(backend->callbacks));
   backend->socket_fd = connect_socket(server_port);
   backend->disconnected = backend->socket_fd < 0;
   backend->next_sequence = 0;
   backend->game = game != nullptr ? game : "";
   backend->match_id = match_id != nullptr ? match_id : "";
   backend->send_offset = 0;
   backend->spectator_count = 0;
   backend->input_cursor = 0;
   if (backend->socket_fd >= 0) {
      send_version(backend);
   } else {
      queue_disconnect(backend);
   }
   backend->callbacks.begin_game(backend->game.data());
   return reinterpret_cast<GGPOSession *>(backend);
}
bool streaming_session_get_replay_status(GGPOSession *session, GGPOReplayStatus *status) {
   if (session == nullptr || status == nullptr || session->vtable != &streaming_vtable) return false;
   auto *backend = reinterpret_cast<StreamingBackend *>(session);
   status->seekable = !backend->initial_state.empty();
   status->current_frame = static_cast<int>(backend->input_cursor);
   status->total_frames = static_cast<int>(backend->inputs.size());
   status->buffered_frames = status->total_frames;
   return status->seekable != 0;
}
bool streaming_session_seek_replay(GGPOSession *session, int frame) {
   if (session == nullptr || session->vtable != &streaming_vtable) return false;
   auto *backend = reinterpret_cast<StreamingBackend *>(session);
   if (backend->initial_state.empty()) return false;
   const int target = std::max(0, std::min(frame, static_cast<int>(backend->inputs.size())));
   backend->callbacks.load_game_state(backend->initial_state.data(), static_cast<int>(backend->initial_state.size()));
   backend->input_cursor = 0;
   while (static_cast<int>(backend->input_cursor) < target) if (!backend->callbacks.advance_frame(0)) return false;
   return true;
}
}
