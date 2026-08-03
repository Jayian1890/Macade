#include "session.hpp"
#include "client_backend.hpp"
#include "peer_backend.hpp"
#include "replay_backend.hpp"
#include "streaming_backend.hpp"
#include "synctest_backend.hpp"

#include <cstdlib>

extern "C" {

void __cdecl ggpo_close_session(GGPOSession *session)
{
   if (session != nullptr) {
      session->vtable->destroy(session);
   }
}

bool __cdecl ggpo_get_stats(GGPOSession *session, GGPONetworkStats *stats)
{
   if (session == nullptr) {
      return false;
   }
   return session->vtable->get_stats(session, stats);
}

bool __cdecl ggpo_client_chat(GGPOSession *session, char *text)
{
   if (session == nullptr) {
      return false;
   }
   return session->vtable->client_chat(session, text);
}

bool __cdecl ggpo_advance_frame(GGPOSession *session)
{
   if (session == nullptr) {
      return false;
   }
   return session->vtable->advance_frame(session);
}

bool __cdecl ggpo_synchronize_input(GGPOSession *session, void *values, int size, int players)
{
   if (session == nullptr) {
      return false;
   }
   return session->vtable->synchronize_input(session, values, size, players);
}

bool __cdecl ggpo_idle(GGPOSession *session, int timeout)
{
   if (session == nullptr) {
      return false;
   }
   return session->vtable->idle(session, timeout);
}

bool __cdecl ggpo_set_frame_delay(GGPOSession *session, int frame_delay)
{
   if (session == nullptr) {
      return false;
   }
   return session->vtable->set_frame_delay(session, frame_delay);
}

bool __cdecl ggpo_replay_get_status(GGPOSession *session, GGPOReplayStatus *status)
{
   return ggponet::reconstructed::replay_session_get_status(session, status) ||
          ggponet::reconstructed::streaming_session_get_replay_status(session, status);
}

bool __cdecl ggpo_replay_seek(GGPOSession *session, int frame)
{
   return ggponet::reconstructed::replay_session_seek(session, frame) ||
          ggponet::reconstructed::streaming_session_seek_replay(session, frame);
}

bool __cdecl ggpo_client_set_game_event(GGPOSession *session, GGPOClientGameEventType type, void *data)
{
   if (session == nullptr) {
      return false;
   }
   return session->vtable->client_set_game_event(session, type, data);
}

void __cdecl ggpo_logv(GGPOSession *session, char *fmt, va_list args)
{
   if (session != nullptr) {
      session->vtable->logv(session, fmt, args);
   }
}

void __cdecl ggpo_log(GGPOSession *session, char *fmt, ...)
{
   va_list args;
   va_start(args, fmt);
   ggpo_logv(session, fmt, args);
   va_end(args);
}

GGPOSession *__cdecl ggpo_start_replay(GGPOSessionCallbacks *callbacks, char *filename)
{
   return ggponet::reconstructed::create_replay_session(callbacks, filename);
}

GGPOSession *__cdecl ggpo_client_connect(GGPOSessionCallbacks *callbacks, char *game, char *match_id, int server_port)
{
   return ggponet::reconstructed::create_client_session(callbacks, game, match_id, server_port);
}

GGPOSession *__cdecl ggpo_start_session(GGPOSessionCallbacks *callbacks, char *game, int local_port,
                                        char *remote_ip, int remote_port, int player_num)
{
   ggponet::reconstructed::PeerBackend *session =
      ggponet::reconstructed::create_peer_session(callbacks, game, local_port);
   if (session == nullptr) {
      return nullptr;
   }
   ggponet::reconstructed::peer_session_connect(session, remote_ip, remote_port, player_num != 0);
   return &session->base;
}

GGPOSession *__cdecl ggpo_start_streaming(GGPOSessionCallbacks *callbacks, char *game, char *match_id, int server_port)
{
   return ggponet::reconstructed::create_streaming_session(callbacks, game, match_id, server_port);
}

GGPOSession *__cdecl ggpo_start_synctest(GGPOSessionCallbacks *callbacks, char *game, int check_distance)
{
   return ggponet::reconstructed::create_synctest_session(callbacks, game, check_distance);
}

}
