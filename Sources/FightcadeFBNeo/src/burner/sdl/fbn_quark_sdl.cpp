#include "burner.h"
#include "ggpoclient.h"
#include "ggponet.h"
#include "macade_embedded.h"
#include "sdl_quark_detector.h"

#include <sys/stat.h>
#include <unistd.h>

GGPOSession *ggpo = NULL;
extern int nAcbVersion;
extern int nAcbLoadState;

namespace {

constexpr int kStateHeaderSize = 6 * sizeof(int);

char game_name[MAX_PATH];
bool delay_load = false;
bool replay_record = false;
bool replay_recording = false;
int ranked_match = 0;
int local_player = 0;
int frame_delay = 0;
int game_seed = 0;

char acb_buffer[16 * 1024 * 1024];
char *acb_scan;
int acb_checksum;
FILE *acb_log;

int hash_quark_id(const char *id, int len)
{
   unsigned int hash = 1315423911;
   for (int i = 0; i < len; i++) {
      hash ^= ((hash << 5) + id[i] + (hash >> 2));
   }
   return hash & 0x7fffffff;
}

bool file_exists(const char *path)
{
   struct stat info{};
   return path[0] != 0 && stat(path, &info) == 0 && S_ISREG(info.st_mode);
}

void savestate_path(char *path, size_t size, const char *game, bool ranked)
{
   const char *runtime = getenv("MACADE_FIGHTCADE_RUNTIME");
   if (runtime != NULL && runtime[0] != 0) {
      snprintf(path, size, "%s/savestates/%s_fbneo%s.fs", runtime, game, ranked ? "_ranked" : "");
      return;
   }
   snprintf(path, size, "savestates/%s_fbneo%s.fs", game, ranked ? "_ranked" : "");
}

int find_game(const char *name)
{
   UINT32 previous = nBurnDrvActive;
   for (UINT32 i = 0; i < nBurnDrvCount; i++) {
      nBurnDrvActive = i;
      if (strcmp(BurnDrvGetTextA(DRV_NAME), name) == 0 && !(BurnDrvGetFlags() & BDF_BOARDROM)) {
         nBurnDrvActive = previous;
         return static_cast<int>(i);
      }
   }
   nBurnDrvActive = previous;
   return -1;
}

void set_burn_fps(const char *name, int version)
{
   if (version < NET_VERSION_60FPS) {
      bForce60Hz = 1;
      nBurnFPS = 5994;
      nAppVirtualFps = nBurnFPS;
      return;
   }
   if (version >= NET_VERSION_UMK3UC_FRAMERATE && strcmp(name, "umk3uc") == 0) {
      bForce60Hz = 1;
      nBurnFPS = 6000;
      nAppVirtualFps = nBurnFPS;
      return;
   }
   if (version < NET_VERSION_DISABLE_FORCE_60HZ) {
      bForce60Hz = 1;
      if (version >= NET_VERSION_MK_FRAMERATE &&
          (!strcmp(name, "mk") || !strcmp(name, "mk2") || !strcmp(name, "mk2p") ||
           !strcmp(name, "mk3") || !strcmp(name, "umk3") || !strcmp(name, "umk3p") ||
           !strcmp(name, "umk3uc") || !strcmp(name, "umk3uk") || !strcmp(name, "wwfman"))) {
         bForce60Hz = 0;
         return;
      }
      nBurnFPS = 6000;
      nAppVirtualFps = nBurnFPS;
   }
}

bool load_fightcade_state(const char *name)
{
   char state[MAX_PATH];
   if (ranked_match) {
      savestate_path(state, sizeof(state), name, true);
      if (file_exists(state) && BurnStateLoad(state, 1, &DrvInitCallback) == 0) {
         return true;
      }
   }
   savestate_path(state, sizeof(state), name, false);
   return file_exists(state) && BurnStateLoad(state, 1, &DrvInitCallback) == 0;
}

int log_acb(BurnArea *area)
{
   fprintf(acb_log, "%s:", area->szName);
   for (int i = 0; i < static_cast<int>(area->nLen); i++) {
      if ((i % 30) == 0) {
         fprintf(acb_log, "\noffset %9d :", i);
      }
      fprintf(acb_log, " %02x", static_cast<unsigned char *>(area->Data)[i]);
   }
   fprintf(acb_log, "\n");
   return 0;
}

int read_acb(BurnArea *area)
{
   memcpy(acb_scan, area->Data, area->nLen);
   acb_scan += area->nLen;
   return 0;
}

int write_acb(BurnArea *area)
{
   memcpy(area->Data, acb_scan, area->nLen);
   acb_scan += area->nLen;
   return 0;
}

} // namespace

bool __cdecl ggpo_on_event_callback(GGPOEvent *info)
{
   if (ggpo_is_client_eventcode(info->code)) {
      GGPOClientEvent *client = reinterpret_cast<GGPOClientEvent *>(info);
      if (client->code == GGPOCLIENT_EVENTCODE_CONNECTING) {
         MacadeEmbeddedSetOverlayConnectionPhase(1);
         MacadeEmbeddedSetOverlaySystemMessage("Connecting...", 180);
      } else if (client->code == GGPOCLIENT_EVENTCODE_CONNECTED) {
         MacadeEmbeddedSetOverlayConnectionPhase(2);
         MacadeEmbeddedSetOverlaySystemMessage("Connected", 120);
      } else if (client->code == GGPOCLIENT_EVENTCODE_RETREIVING_MATCHINFO) {
         MacadeEmbeddedSetOverlayConnectionPhase(3);
         MacadeEmbeddedSetOverlaySystemMessage("Retrieving Match Info...", 180);
      } else if (client->code == GGPOCLIENT_EVENTCODE_DISCONNECTED) {
         MacadeEmbeddedSetOverlayConnectionPhase(8);
         MacadeEmbeddedSetOverlaySystemMessage("Disconnected!", 300);
      } else if (client->code == GGPOCLIENT_EVENTCODE_MATCHINFO) {
         MacadeEmbeddedSetOverlayConnectionPhase(4);
         MacadeEmbeddedSetOverlaySystemMessage("", 0);
         MacadeEmbeddedSetOverlayGameInfo(client->u.matchinfo.p1, client->u.matchinfo.p2, kNetSpectator, ranked_match, local_player);
      } else if (client->code == GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED) {
         MacadeEmbeddedSetOverlaySpectators(client->u.spectator_count_changed.count);
      } else if (client->code == GGPOCLIENT_EVENTCODE_CHAT && client->u.chat.text && client->u.chat.text[0] != 0) {
         MacadeEmbeddedAddOverlayChatLine(client->u.chat.username, client->u.chat.text);
      }
      if (client->code == GGPOCLIENT_EVENTCODE_MATCHINFO && kNetSpectator && client->u.matchinfo.blurb) {
         kNetVersion = strlen(client->u.matchinfo.blurb) > 0 ? atoi(client->u.matchinfo.blurb) : NET_VERSION;
         set_burn_fps(game_name, kNetVersion);
      }
      printf("Macade quark event: client code=%d\n", client->code);
      return true;
   }
   printf("Macade quark event: code=%d\n", info->code);
   if (info->code == GGPO_EVENTCODE_CONNECTED_TO_PEER) {
      MacadeEmbeddedSetOverlayConnectionPhase(5);
      MacadeEmbeddedSetOverlaySystemMessage("Connected to Peer", 120);
   } else if (info->code == GGPO_EVENTCODE_SYNCHRONIZING_WITH_PEER) {
      MacadeEmbeddedSetOverlayConnectionPhase(6);
      MacadeEmbeddedSetOverlaySystemMessage("Synchronizing with Peer...", 180);
   } else if (info->code == GGPO_EVENTCODE_RUNNING) {
      char version[16];
      snprintf(version, sizeof(version), "%d", NET_VERSION);
      QuarkSendChatCmd(version, 'V');
      MacadeEmbeddedSetOverlayConnectionPhase(7);
      MacadeEmbeddedSetOverlaySystemMessage("", 0);
   } else if (info->code == GGPO_EVENTCODE_DISCONNECTED_FROM_PEER) {
      MacadeEmbeddedSetOverlayConnectionPhase(8);
      MacadeEmbeddedSetOverlaySystemMessage("Disconnected from Peer", 300);
   }
   return true;
}

bool __cdecl ggpo_begin_game_callback(char *name)
{
   snprintf(game_name, sizeof(game_name), "%s", name);
   set_burn_fps(name, kNetVersion);
   int index = find_game(name);
   if (index < 0) {
      printf("Macade quark: game not supported by FBNeo: %s\n", name);
      return false;
   }

   if (kNetSpectator) {
      nBurnDrvActive = index;
      DetectorLoad(name, false, game_seed);
      DetectorSetGameInfo(kNetSpectator, ranked_match);
      delay_load = true;
      return true;
   }

   if (!load_fightcade_state(name)) {
      nBurnDrvActive = index;
      if (DrvInit(index, true) != 0) {
         return false;
      }
   }
   DetectorLoad(name, false, game_seed);
   DetectorSetGameInfo(kNetSpectator, ranked_match);
   MediaInit();
   MacadeEmbeddedSetOverlayGameInfo("Player1#0,0", "Player2#0,0", 0, ranked_match, local_player);
   MacadeEmbeddedSetOverlayStats(0, frame_delay);
   return true;
}

bool __cdecl ggpo_advance_frame_callback(int)
{
   nFramesEmulated--;
   return RunFrame(0, 0, 0, 1) == 0;
}

bool __cdecl ggpo_save_game_state_callback(unsigned char **buffer, int *len, int *checksum, int)
{
   acb_checksum = 0;
   acb_scan = acb_buffer;
   BurnAcb = read_acb;
   BurnAreaScan(ACB_FULLSCANL | ACB_READ, NULL);
   int payload_size = static_cast<int>(acb_scan - acb_buffer);

   *checksum = acb_checksum;
   *len = payload_size + kStateHeaderSize;
   *buffer = static_cast<unsigned char *>(malloc(*len));
   if (*buffer == NULL) {
      return false;
   }

   int *header = reinterpret_cast<int *>(*buffer);
   header[0] = 'GGPO';
   header[1] = kStateHeaderSize;
   header[2] = nBurnVer;
   header[3] = 0;
   header[4] = 0;
   header[5] = 0;
   if (!kNetSpectator) {
      int state, score1, score2, start1, start2;
      DetectorGetState(state, score1, score2, start1, start2);
      header[3] = state | ((score1 & 0xff) << 8) | ((score2 & 0xff) << 16) | (ranked_match << 24);
      header[4] = (start1 & 0xff) | ((start2 & 0xff) << 8);
   }
   memcpy(*buffer + kStateHeaderSize, acb_buffer, payload_size);
   return false;
}

bool __cdecl ggpo_load_game_state_callback(unsigned char *buffer, int)
{
   if (delay_load) {
      if (DrvInit(nBurnDrvActive, true) != 0) {
         return false;
      }
      MediaInit();
      RunInit();
      delay_load = false;
   }
   int *header = reinterpret_cast<int *>(buffer);
   if (header[0] == 'GGPO') {
      int header_size = header[1];
      int header_count = header_size / sizeof(int);
      nAcbVersion = header[2];
      int state = header[3] & 0xff;
      int score1 = (header[3] >> 8) & 0xff;
      int score2 = (header[3] >> 16) & 0xff;
      int ranked = (header[3] >> 24) & 0xff;
      int start1 = header_count > 4 ? header[4] & 0xff : 0;
      int start2 = header_count > 4 ? (header[4] >> 8) & 0xff : 0;
      if (kNetSpectator) {
         ranked_match = ranked;
         DetectorSetGameInfo(kNetSpectator, ranked_match);
         DetectorSetState(state, score1, score2, start1, start2);
      }
      buffer += header_size;
   }
   acb_scan = reinterpret_cast<char *>(buffer);
   BurnAcb = write_acb;
   nAcbLoadState = kNetSpectator;
   BurnAreaScan(ACB_FULLSCANL | ACB_WRITE, NULL);
   nAcbLoadState = 0;
   nAcbVersion = nBurnVer;
   if (kNetSpectator) {
      VidRedraw();
      VidPaint(0);
   }
   return true;
}

bool __cdecl ggpo_log_game_state_callback(char *filename, unsigned char *buffer, int len)
{
   if (!ggpo_load_game_state_callback(buffer, len)) {
      return false;
   }
   acb_log = fopen(filename, "w");
   if (acb_log == NULL) {
      return false;
   }
   BurnAcb = log_acb;
   BurnAreaScan(ACB_FULLSCANL | ACB_READ, NULL);
   fclose(acb_log);
   return true;
}

void __cdecl ggpo_free_buffer_callback(void *buffer)
{
   free(buffer);
}

bool QuarkInit(const char *connect)
{
   char game[128] = {};
   char quark_id[128] = {};
   char server[128] = {};
   int port = 0;
   int delay = 0;
   int ranked = 0;
   int player = 0;
   int local_port = 0;
   int remote_port = 0;

   kNetVersion = NET_VERSION;
   kNetGame = 1;
   kNetLua = 0;
   kNetSpectator = 0;
   kNetQuarkId[0] = 0;
   bForce60Hz = 0;
   ranked_match = 0;
   local_player = 0;
   frame_delay = 0;
   MacadeEmbeddedSetOverlayConnectionPhase(1);

   GGPOSessionCallbacks cb{};
   cb.begin_game = ggpo_begin_game_callback;
   cb.load_game_state = ggpo_load_game_state_callback;
   cb.save_game_state = ggpo_save_game_state_callback;
   cb.log_game_state = ggpo_log_game_state_callback;
   cb.free_buffer = ggpo_free_buffer_callback;
   cb.advance_frame = ggpo_advance_frame_callback;
   cb.on_event = ggpo_on_event_callback;

   if (strncmp(connect, "quark:served", strlen("quark:served")) == 0) {
      sscanf(connect, "quark:served,%127[^,],%127[^,],%d,%d,%d", game, quark_id, &port, &delay, &ranked);
      ranked_match = ranked;
      local_player = atoi(&quark_id[strlen(quark_id) - 1]);
      frame_delay = delay;
      game_seed = hash_quark_id(quark_id, static_cast<int>(strlen(quark_id)) - 2);
      ggpo = ggpo_client_connect(&cb, game, quark_id, port);
      snprintf(kNetQuarkId, sizeof(kNetQuarkId), "%s", quark_id);
   } else if (strncmp(connect, "quark:training", strlen("quark:training")) == 0) {
      sscanf(connect, "quark:training,%127[^,],%127[^,],%d,%d", game, quark_id, &port, &delay);
      local_player = atoi(&quark_id[strlen(quark_id) - 1]);
      frame_delay = delay;
      game_seed = hash_quark_id(quark_id, static_cast<int>(strlen(quark_id)) - 2);
      ggpo = ggpo_client_connect(&cb, game, quark_id, port);
      snprintf(kNetQuarkId, sizeof(kNetQuarkId), "%s", quark_id);
      kNetLua = 1;
   } else if (strncmp(connect, "quark:direct", strlen("quark:direct")) == 0) {
      sscanf(connect, "quark:direct,%127[^,],%d,%127[^,],%d,%d,%d,%d", game, &local_port, server,
             &remote_port, &player, &delay, &ranked);
      kNetLua = 1;
      ranked_match = ranked;
      local_player = player;
      frame_delay = delay;
      game_seed = 0;
      ggpo = ggpo_start_session(&cb, game, local_port, server, remote_port, player);
   } else if (strncmp(connect, "quark:stream", strlen("quark:stream")) == 0) {
      sscanf(connect, "quark:stream,%127[^,],%127[^,],%d", game, quark_id, &remote_port);
      kNetSpectator = 1;
      kNetLua = 1;
      ggpo = ggpo_start_streaming(&cb, game, quark_id, remote_port);
      snprintf(kNetQuarkId, sizeof(kNetQuarkId), "%s", quark_id);
   } else if (strncmp(connect, "quark:replay", strlen("quark:replay")) == 0) {
      kNetSpectator = 1;
      kNetLua = 1;
      ggpo = ggpo_start_replay(&cb, const_cast<char *>(connect + strlen("quark:replay,")));
   }

   if (ggpo == NULL) {
      kNetGame = 0;
      printf("Macade quark: failed to create native GGPO session for %s\n", connect);
      return false;
   }
   ggpo_set_frame_delay(ggpo, frame_delay);
   printf("Macade quark: native GGPO session started for %s\n", connect);
   return true;
}

void QuarkEnd()
{
   if (ggpo != NULL) {
      ggpo_close_session(ggpo);
      ggpo = NULL;
   }
   kNetGame = 0;
   kNetSpectator = 0;
}

void QuarkRunIdle(int ms)
{
   char chat[160];
   if (MacadeEmbeddedConsumeChatSubmit(chat, sizeof(chat))) {
      QuarkSendChatText(chat);
   }
   if (ggpo != NULL) ggpo_idle(ggpo, ms);
}
bool QuarkGetInput(void *values, int size, int players) { return ggpo != NULL && ggpo_synchronize_input(ggpo, values, size, players); }
bool QuarkIncrementFrame() { return ggpo != NULL && ggpo_advance_frame(ggpo); }
void QuarkSendChatText(char *text) { QuarkSendChatCmd(text, 'T'); }
void QuarkSendChatCmd(char *text, char cmd)
{
   char buffer[1024];
   buffer[0] = cmd;
   strncpy(&buffer[1], text, sizeof(buffer) - 2);
   buffer[sizeof(buffer) - 1] = 0;
   if (ggpo != NULL) ggpo_client_chat(ggpo, buffer);
}
void QuarkUpdateStats(double fps)
{
   GGPONetworkStats stats{};
   if (ggpo != NULL && ggpo_get_stats(ggpo, &stats)) {
      printf("Macade quark stats: fps=%2.2f ping=%d delay=%d\n", fps, stats.network.ping, frame_delay);
   }
}
void QuarkRecordReplay() { replay_record = true; replay_recording = false; }
