#pragma once

#include "peer_backend.hpp"

#include <deque>
#include <map>
#include <string>
#include <vector>

namespace ggponet::reconstructed {

constexpr int kClientLocalPort = 0x1774;
constexpr int kPeerLocalPort = 0x1770;

struct ClientEvent {
   int type;
   int count;
   int remote_port;
   int player_side;
   std::string match_id;
   std::string p1;
   std::string p2;
   std::string blurb;
};

struct ClientBackend {
   PeerBackend peer;
   int socket_fd;
   unsigned int next_sequence;
   std::vector<unsigned char> receive_buffer;
   std::vector<unsigned char> send_buffer;
   size_t send_offset;
   std::map<unsigned int, int> pending_commands;
   std::deque<ClientEvent> events;
   std::deque<GameInput> spectator_inputs;
   std::deque<GameInput> replay_inputs;
   std::string game;
   std::string match_id;
   std::string p1;
   std::string p2;
   std::string blurb;
   std::string avatars[4];
   int scores[4];
   int spectator_count;
   int winner;
   bool spectator_source;
   bool replay_source;
   bool replay_active;
   int replay_upload_delay;
   int replay_start_frame;
   std::vector<unsigned char> replay_state;
};

void client_schedule_replay_upload(ClientBackend *client);
bool client_handle_game_event_upload(ClientBackend *client, GGPOClientGameEventType type, void *data);
void client_confirmed_input_hook(PeerBackend *session, const PredictionEvent *event);

}
