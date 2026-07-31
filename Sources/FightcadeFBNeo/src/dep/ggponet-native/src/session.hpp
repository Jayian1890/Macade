#pragma once

#include <cstdarg>

#include "../include/ggpoclient.h"
#include "../include/ggponet.h"

struct GGPOSessionVTable {
   bool (*idle)(GGPOSession *session, int timeout);
   bool (*synchronize_input)(GGPOSession *session, void *values, int size, int players);
   bool (*advance_frame)(GGPOSession *session);
   bool (*client_chat)(GGPOSession *session, char *text);
   bool (*get_stats)(GGPOSession *session, GGPONetworkStats *stats);
   bool (*client_set_game_event)(GGPOSession *session, GGPOClientGameEventType type, void *data);
   void (*logv)(GGPOSession *session, char *fmt, va_list args);
   bool (*set_frame_delay)(GGPOSession *session, int frame_delay);
   void (*destroy)(GGPOSession *session);
};

struct GGPOSession {
   const GGPOSessionVTable *vtable;
};
