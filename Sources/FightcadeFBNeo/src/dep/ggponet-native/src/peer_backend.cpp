#include "peer_backend.hpp"

#include "logging.hpp"

#include <algorithm>
#include <cstring>
#include <new>
#include <unistd.h>

namespace ggponet::reconstructed {
namespace {

PeerBackend *peer(GGPOSession *session)
{
   return reinterpret_cast<PeerBackend *>(session);
}

void emit_event(PeerBackend *session, GGPOEvent *event)
{
   session->callbacks.on_event(event);
}

void handle_udp_event(PeerBackend *session, const UdpProtocolEvent &event)
{
   GGPOEvent ggpo_event{};
   switch (event.type) {
   case 0:
      ggpo_event.code = GGPO_EVENTCODE_CONNECTED_TO_PEER;
      emit_event(session, &ggpo_event);
      break;
   case 1:
      ggpo_event.code = GGPO_EVENTCODE_SYNCHRONIZING_WITH_PEER;
      if (event.payload.size() >= 8) {
         std::memcpy(&ggpo_event.u.synchronizing.total, event.payload.data(), sizeof(int));
         std::memcpy(&ggpo_event.u.synchronizing.count, event.payload.data() + 4, sizeof(int));
      }
      emit_event(session, &ggpo_event);
      break;
   case 2:
      ggpo_event.code = GGPO_EVENTCODE_RUNNING;
      emit_event(session, &ggpo_event);
      session->synchronizing = false;
      break;
   case 3:
      if (event.payload.size() >= sizeof(GameInput)) {
         GameInput input{};
         std::memcpy(&input, event.payload.data(), sizeof(input));
         sync_add_remote_input(&session->sync, &input);
      }
      break;
   case 4:
      ggpo_event.code = GGPO_EVENTCODE_DISCONNECTED_FROM_PEER;
      emit_event(session, &ggpo_event);
      break;
   }
}

void drain_udp_events(PeerBackend *session)
{
   UdpProtocolEvent event;
   while (udp_protocol_pop_event(&session->udp, &event)) {
      handle_udp_event(session, event);
   }
}

void refresh_network_lag(PeerBackend *session)
{
   int ping = 0;
   int send_queue_len = 0;
   int kbps_sent = 0;
   udp_protocol_get_network_stats(&session->udp, &ping, &session->local_frames_behind,
                                  &session->remote_frames_behind, &send_queue_len, &kbps_sent);
}

bool peer_idle(GGPOSession *session_base, int timeout_ms)
{
   PeerBackend *session = peer(session_base);
   if (!session->in_poll) {
      poll_backend_run(&session->poller, 0);
      drain_udp_events(session);
      session->in_poll = true;
      sync_check_simulation(&session->sync);
      session->in_poll = false;
      udp_protocol_update_local_connect_status(&session->udp, sync_current_frame(&session->sync));
      if (timeout_ms != 0) {
         usleep(static_cast<useconds_t>(timeout_ms * 1000));
      }
   }
   return true;
}

bool peer_synchronize_input(GGPOSession *session_base, void *values, int size, int players)
{
   PeerBackend *session = peer(session_base);
   if (session->synchronizing) {
      return false;
   }

   const int effective_players = std::min(players, 2);
   GameInput input{};
   game_input_construct_local(&input, -1, values, static_cast<size_t>(size), effective_players,
                              session->local_player_is_player2 ? 1 : 0);

   if (!session->in_poll) {
      if (!sync_add_local_input(&session->sync, &input)) {
         return false;
      }
      const int wait = time_sync_advance_frame(&session->time_sync, &input, session->local_frames_behind,
                                               session->remote_frames_behind);
      if (wait > 0) {
         GGPOEvent event{};
         event.code = GGPO_EVENTCODE_TIMESYNC;
         event.u.timesync.frames_ahead = wait;
         emit_event(session, &event);
      }
      udp_protocol_send_input(&session->udp, &input);
   }

   session->have_input = true;
   sync_get_input(&session->sync, &input);
   std::memset(values, 0, static_cast<size_t>(size * players));
   std::memcpy(values, input.bits, static_cast<size_t>(size * effective_players));
   return true;
}

bool peer_advance_frame(GGPOSession *session_base)
{
   PeerBackend *session = peer(session_base);
   quark_log("End of frame (%d)...\n", sync_current_frame(&session->sync));
   sync_advance_frame(&session->sync);
   peer_idle(session_base, 0);

   PredictionEvent event;
   while (sync_pop_confirmed_input(&session->sync, &event)) {
      if (session->confirmed_input_hook != nullptr) {
         session->confirmed_input_hook(session, &event);
      }
   }
   refresh_network_lag(session);
   return true;
}

bool peer_client_chat(GGPOSession *, char *)
{
   return true;
}

bool peer_get_stats(GGPOSession *session_base, GGPONetworkStats *stats)
{
   PeerBackend *session = peer(session_base);
   std::memset(stats, 0, sizeof(*stats));
   int ping = 0;
   int send_queue_len = 0;
   int kbps_sent = 0;
   udp_protocol_get_network_stats(&session->udp, &ping, &session->local_frames_behind,
                                  &session->remote_frames_behind, &send_queue_len, &kbps_sent);
   int predict_queue_len = 0;
   int recv_queue_len = 0;
   sync_get_prediction_stats(&session->sync, &predict_queue_len, &recv_queue_len);
   stats->network.predict_queue_len = predict_queue_len;
   stats->network.send_queue_len = send_queue_len;
   stats->network.recv_queue_len = recv_queue_len;
   stats->network.ping = ping;
   stats->network.kbps_sent = kbps_sent;
   stats->timesync.local_frames_behind = session->local_frames_behind;
   stats->timesync.remote_frames_behind = session->remote_frames_behind;
   return true;
}

bool peer_client_set_game_event(GGPOSession *, GGPOClientGameEventType, void *)
{
   return true;
}

void peer_logv(GGPOSession *, char *fmt, va_list args)
{
   quark_logv(fmt, args);
}

bool peer_set_frame_delay(GGPOSession *session_base, int frame_delay)
{
   PeerBackend *session = peer(session_base);
   if (session->have_input) {
      return false;
   }
   sync_set_frame_delay(&session->sync, frame_delay);
   return true;
}

void peer_destroy(GGPOSession *session_base)
{
   PeerBackend *session = peer(session_base);
   peer_backend_teardown(session);
   delete session;
}

const GGPOSessionVTable peer_vtable = {
   peer_idle,
   peer_synchronize_input,
   peer_advance_frame,
   peer_client_chat,
   peer_get_stats,
   peer_client_set_game_event,
   peer_logv,
   peer_set_frame_delay,
   peer_destroy,
};

} // namespace

PeerBackend *create_peer_session(GGPOSessionCallbacks *callbacks, char *game, int local_port)
{
   PeerBackend *session = new (std::nothrow) PeerBackend{};
   if (session == nullptr) {
      return nullptr;
   }
   if (!peer_backend_construct(session, &peer_vtable, callbacks, game, local_port)) {
      delete session;
      return nullptr;
   }
   return session;
}

bool peer_backend_construct(PeerBackend *session, const GGPOSessionVTable *vtable, GGPOSessionCallbacks *callbacks,
                            char *game, int local_port)
{
   session->base.vtable = vtable;
   std::memcpy(&session->callbacks, callbacks, sizeof(session->callbacks));
   poll_backend_construct(&session->poller);
   sync_construct(&session->sync);
   udp_protocol_construct(&session->udp);
   time_sync_init(&session->time_sync);
   session->in_poll = false;
   session->synchronizing = true;
   session->local_player_is_player2 = false;
   session->have_input = false;
   session->local_frames_behind = 0;
   session->remote_frames_behind = 0;
   session->confirmed_input_hook = nullptr;

   SyncConfig config{};
   std::memcpy(&config.callbacks, callbacks, sizeof(config.callbacks));
   config.frame_delay = 1;
   config.max_prediction_frames = 20;
   sync_init(&session->sync, &config);
   udp_protocol_bind(&session->udp, local_port);
   if (!session->callbacks.begin_game(game)) {
      quark_log("begin_game failed for %s.\n", game != nullptr ? game : "");
      peer_backend_teardown(session);
      return false;
   }
   return true;
}

void peer_backend_teardown(PeerBackend *session)
{
   time_sync_destroy(&session->time_sync);
   udp_protocol_destroy(&session->udp);
   sync_destroy(&session->sync);
   poll_backend_destroy(&session->poller);
}

bool peer_backend_idle(PeerBackend *session, int timeout_ms)
{
   return peer_idle(&session->base, timeout_ms);
}

bool peer_backend_synchronize_input(PeerBackend *session, void *values, int size, int players)
{
   return peer_synchronize_input(&session->base, values, size, players);
}

bool peer_backend_advance_frame(PeerBackend *session)
{
   return peer_advance_frame(&session->base);
}

bool peer_backend_get_stats(PeerBackend *session, GGPONetworkStats *stats)
{
   return peer_get_stats(&session->base, stats);
}

void peer_backend_logv(PeerBackend *session, char *fmt, va_list args)
{
   peer_logv(&session->base, fmt, args);
}

bool peer_backend_set_frame_delay(PeerBackend *session, int frame_delay)
{
   return peer_set_frame_delay(&session->base, frame_delay);
}

void peer_session_connect(PeerBackend *session, char *remote_ip, int remote_port, bool player2)
{
   udp_protocol_set_remote_endpoint(&session->udp, remote_ip, remote_port, &session->poller);
   session->in_poll = false;
   session->synchronizing = true;
   session->local_player_is_player2 = player2;
   udp_protocol_start_sync(&session->udp);
}

}
