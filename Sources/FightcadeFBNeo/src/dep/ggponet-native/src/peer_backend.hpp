#pragma once

#include "poll_backend.hpp"
#include "session.hpp"
#include "sync_core.hpp"
#include "time_sync.hpp"
#include "udp_protocol.hpp"

namespace ggponet::reconstructed {

struct PeerBackend {
   GGPOSession base;
   GGPOSessionCallbacks callbacks;
   PollBackend poller;
   SyncCore sync;
   UdpProtocol udp;
   TimeSync time_sync;
   bool in_poll;
   bool synchronizing;
   bool local_player_is_player2;
   bool have_input;
   int local_frames_behind;
   int remote_frames_behind;
   void (*confirmed_input_hook)(PeerBackend *session, const PredictionEvent *event);
};

PeerBackend *create_peer_session(GGPOSessionCallbacks *callbacks, char *game, int local_port);
void peer_session_connect(PeerBackend *session, char *remote_ip, int remote_port, bool player2);
bool peer_backend_construct(PeerBackend *session, const GGPOSessionVTable *vtable, GGPOSessionCallbacks *callbacks,
                            char *game, int local_port);
void peer_backend_teardown(PeerBackend *session);
bool peer_backend_idle(PeerBackend *session, int timeout_ms);
bool peer_backend_synchronize_input(PeerBackend *session, void *values, int size, int players);
bool peer_backend_advance_frame(PeerBackend *session);
bool peer_backend_get_stats(PeerBackend *session, GGPONetworkStats *stats);
void peer_backend_logv(PeerBackend *session, char *fmt, va_list args);
bool peer_backend_set_frame_delay(PeerBackend *session, int frame_delay);

}
