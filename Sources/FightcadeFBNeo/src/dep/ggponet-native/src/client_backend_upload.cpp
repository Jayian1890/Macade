#include "client_backend_internal.hpp"

#include "logging.hpp"

#include <arpa/inet.h>
#include <cerrno>
#include <chrono>
#include <cstring>
#include <cstdio>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <zlib.h>

namespace ggponet::reconstructed {
namespace {

void append_be32(std::vector<unsigned char> *buffer, uint32_t value)
{
   const uint32_t be = htonl(value);
   const auto *bytes = reinterpret_cast<const unsigned char *>(&be);
   buffer->insert(buffer->end(), bytes, bytes + sizeof(be));
}

void append_string(std::vector<unsigned char> *payload, const std::string &value)
{
   append_be32(payload, static_cast<uint32_t>(value.size()));
   payload->insert(payload->end(), value.begin(), value.end());
}

void send_command(ClientBackend *client, int command, const std::vector<unsigned char> &payload)
{
   quark_log("Sending command %d to server.\n", command);
   const unsigned int sequence = client->next_sequence++;
   client->pending_commands[sequence] = command;
   append_be32(&client->send_buffer, static_cast<uint32_t>(payload.size() + 8));
   append_be32(&client->send_buffer, sequence);
   append_be32(&client->send_buffer, static_cast<uint32_t>(command));
   client->send_buffer.insert(client->send_buffer.end(), payload.begin(), payload.end());
}

void flush_socket(ClientBackend *client)
{
   while (client->socket_fd >= 0 && client->send_offset < client->send_buffer.size()) {
      const ssize_t sent = send(client->socket_fd, client->send_buffer.data() + client->send_offset,
                                client->send_buffer.size() - client->send_offset, 0);
      if (sent > 0) {
         client->send_offset += static_cast<size_t>(sent);
      } else if (errno == EAGAIN || errno == EWOULDBLOCK) {
         return;
      } else {
         client->events.push_back({10});
         return;
      }
   }
   if (client->send_offset == client->send_buffer.size()) {
      client->send_buffer.clear();
      client->send_offset = 0;
   }
}

void finish_flush_and_close(ClientBackend *client)
{
   quark_log("Flushing...");
   while (client->socket_fd >= 0 && client->send_offset < client->send_buffer.size()) {
      flush_socket(client);
      if (client->send_offset < client->send_buffer.size()) {
         std::this_thread::sleep_for(std::chrono::milliseconds(10));
         quark_log(".");
      }
   }
   if (client->socket_fd >= 0) {
      quark_log("Closing TCP socket.");
      shutdown(client->socket_fd, SHUT_RDWR);
      close(client->socket_fd);
      client->socket_fd = -1;
   }
}

bool compress_bytes(const unsigned char *input, size_t input_size, std::vector<unsigned char> *output)
{
   uLongf compressed_size = compressBound(static_cast<uLong>(input_size));
   output->resize(static_cast<size_t>(compressed_size));
   if (compress2(output->data(), &compressed_size, input, static_cast<uLong>(input_size), Z_BEST_SPEED) != Z_OK) {
      output->clear();
      return false;
   }
   output->resize(static_cast<size_t>(compressed_size));
   return true;
}

bool saved_state_for_frame(ClientBackend *client, int frame, unsigned char **buffer, int *size, int *checksum)
{
   for (const SyncSavedState &state : client->peer.sync.saved) {
      if (state.frame == frame) {
         *buffer = state.buffer;
         *size = state.size;
         *checksum = state.checksum;
         return state.buffer != nullptr && state.size > 0;
      }
   }
   return false;
}

void send_spectator_inputs(ClientBackend *client)
{
   if (client->spectator_inputs.empty() || client->spectator_count <= 0) {
      return;
   }
   std::vector<unsigned char> payload;
   append_string(&payload, client->match_id);
   append_be32(&payload, static_cast<uint32_t>(client->spectator_inputs.size()));
   append_be32(&payload, static_cast<uint32_t>(client->spectator_inputs.front().size));
   for (const GameInput &input : client->spectator_inputs) {
      char text[1024];
      game_input_to_string(&input, text, sizeof(text), true);
      quark_log("Sending confirmed frame to server: %s.\n", text);
      payload.insert(payload.end(), input.bits, input.bits + input.size);
   }
   send_command(client, 0x11, payload);
}

void send_state_upload(ClientBackend *client, const GameInput *input)
{
   unsigned char *state = nullptr;
   int state_size = 0;
   int checksum = 0;
   if (!saved_state_for_frame(client, input->frame, &state, &state_size, &checksum)) {
      return;
   }
   std::vector<unsigned char> compressed;
   if (!compress_bytes(state, static_cast<size_t>(state_size), &compressed)) {
      return;
   }
   std::vector<unsigned char> payload;
   append_string(&payload, client->match_id);
   append_be32(&payload, static_cast<uint32_t>(compressed.size()));
   append_be32(&payload, static_cast<uint32_t>(state_size));
   payload.insert(payload.end(), compressed.begin(), compressed.end());
   send_command(client, 0x12, payload);
}

void append_replay_header(ClientBackend *client, size_t payload_size, size_t compressed_size,
                          std::vector<unsigned char> *header)
{
   char buffer[4096];
   int used = std::snprintf(buffer, sizeof(buffer), "GGPOTV\nversion\t0.20\ngame\t%s\n", client->game.c_str());
   if (!client->p1.empty()) {
      used += std::snprintf(buffer + used, sizeof(buffer) - static_cast<size_t>(used),
                            "player 1 username\t%s\n", client->p1.c_str());
   }
   if (!client->p2.empty()) {
      used += std::snprintf(buffer + used, sizeof(buffer) - static_cast<size_t>(used),
                            "player 2 username\t%s\n", client->p2.c_str());
   }
   for (int i = 0; i < 2; ++i) {
      if (!client->avatars[i].empty()) {
         used += std::snprintf(buffer + used, sizeof(buffer) - static_cast<size_t>(used),
                               "player %d avatar\t%s\nplayer %d score\t%d\n", i + 1, client->avatars[i].c_str(),
                               i + 1, client->scores[i]);
      }
   }
   const int input_size = client->replay_inputs.empty() ? 0 : client->replay_inputs.front().size;
   used += std::snprintf(buffer + used, sizeof(buffer) - static_cast<size_t>(used),
                         "series\t%s\nwinner\t%d\ninput size\t%d\ninput count\t%zu\nstate size\t%zu\n"
                         "compressed state size\t%zu\npayload size\t%zu\n",
                         client->match_id.c_str(), client->winner, input_size, client->replay_inputs.size(),
                         client->replay_state.size(), compressed_size, payload_size);
   header->assign(reinterpret_cast<unsigned char *>(buffer), reinterpret_cast<unsigned char *>(buffer) + used + 1);
}

void send_replay_upload(ClientBackend *client)
{
   if (client->match_id.empty() || client->replay_state.empty()) {
      return;
   }
   std::vector<unsigned char> replay_payload = client->replay_state;
   for (const GameInput &input : client->replay_inputs) {
      replay_payload.insert(replay_payload.end(), input.bits, input.bits + input.size);
   }
   std::vector<unsigned char> compressed;
   if (!compress_bytes(replay_payload.data(), replay_payload.size(), &compressed)) {
      return;
   }
   std::vector<unsigned char> header;
   append_replay_header(client, replay_payload.size(), compressed.size(), &header);
   std::vector<unsigned char> payload;
   append_string(&payload, client->match_id);
   payload.insert(payload.end(), header.begin(), header.end());
   payload.insert(payload.end(), compressed.begin(), compressed.end());
   quark_log("Sending Replay...");
   send_command(client, 0x13, payload);
   quark_log("Done sending Replay...");
}

} // namespace

void client_schedule_replay_upload(ClientBackend *client)
{
   if (client->spectator_source && client->replay_upload_delay == 0) {
      client->replay_upload_delay = 3;
   }
}

bool client_handle_game_event_upload(ClientBackend *client, GGPOClientGameEventType type, void *data)
{
   if (!client->replay_source) {
      return true;
   }
   if (type == GGPOCLIENT_GAMEEVENT_STARTING) {
      client->replay_active = true;
      client->replay_start_frame = 0;
      client->winner = -1;
      client->replay_state.clear();
      client->replay_inputs.clear();
      for (int i = 0; i < 4; ++i) {
         client->avatars[i].clear();
         client->scores[i] = 0;
      }
   } else if (type >= GGPOCLIENT_GAMEEVENT_PLAYER_1 && type <= GGPOCLIENT_GAMEEVENT_PLAYER_4) {
      client->avatars[type - GGPOCLIENT_GAMEEVENT_PLAYER_1] = data != nullptr ? static_cast<char *>(data) : "";
   } else if (type >= GGPOCLIENT_GAMEEVENT_PLAYER_1_SCORE && type <= GGPOCLIENT_GAMEEVENT_PLAYER_4_SCORE) {
      client->scores[type - GGPOCLIENT_GAMEEVENT_PLAYER_1_SCORE] = data != nullptr ? *static_cast<int *>(data) : 0;
   } else if (type == GGPOCLIENT_GAMEEVENT_WINNER) {
      client->winner = data != nullptr ? *static_cast<int *>(data) : -1;
   } else if (type == GGPOCLIENT_GAMEEVENT_FINISHED) {
      if (client->replay_active && !client->replay_inputs.empty()) {
         send_replay_upload(client);
         client->replay_active = false;
      }
      if (data != nullptr && *static_cast<int *>(data) != 0) {
         finish_flush_and_close(client);
      }
   }
   return true;
}

void client_confirmed_input_hook(PeerBackend *session, const PredictionEvent *event)
{
   auto *client = reinterpret_cast<ClientBackend *>(session);
   if (event->type != 0) {
      return;
   }
   if (client->spectator_source) {
      client->spectator_inputs.push_back(event->input);
      if (client->spectator_inputs.size() == 60) {
         send_spectator_inputs(client);
         if (client->replay_upload_delay != 0 && --client->replay_upload_delay == 0) {
            send_state_upload(client, &event->input);
         }
         client->spectator_inputs.clear();
      }
   }
   if (client->replay_source && client->replay_active) {
      if (client->replay_start_frame == 0) {
         unsigned char *state = nullptr;
         int state_size = 0;
         int checksum = 0;
         if (saved_state_for_frame(client, event->input.frame, &state, &state_size, &checksum)) {
            client->replay_start_frame = event->input.frame;
            client->replay_state.assign(state, state + state_size);
         }
      }
      client->replay_inputs.push_back(event->input);
   }
}

}
