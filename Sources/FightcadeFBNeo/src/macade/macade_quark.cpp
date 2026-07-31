#include "burner.h"
#ifndef __declspec
#define __declspec(x)
#endif
#include "burnint.h"
#include "ggpomac_internal.h"
#include "macade_overlay.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

extern int kNetVersion;
extern int kNetGame;
extern int kNetSpectator;
extern GGPOSession* ggpo;
void MacadeDetectorLoad(const char* game, bool debug, int seed);
void MacadeQuarkRestoreNetworkFlags();

char kNetQuarkId[128] = { 0 };
int kNetLua = 0;
static char gMacadeGame[64] = { 0 };
static bool gMacadeLocalTraining = false;
static bool gMacadeTrainingLuaLoaded = false;
static bool gMacadeGameplayTrackingStarted = false;
static int gMacadeSessionLua = 0;
int iRanked = 0;
int iPlayer = 0;
int iDelay = 0;
int iSeed = 0;

static const int kMacadeGGPOStateHeaderSize = 6 * sizeof(int);
static const int kMacadeGGPOStateMagic = 0x4747504f;
static std::vector<unsigned char> gMacadeStateBuffer;
static const unsigned char* gMacadeLoadCursor = NULL;
static int gMacadeLoadRemaining = 0;
static FILE* gMacadeLogFile = NULL;
static int gMacadeLogChecksum = 0;

struct MacadeQuarkCommand {
	char mode[16];
	char game[64];
	char quarkId[128];
	char replayFile[1024];
	char remoteHost[128];
	int port;
	int remotePort;
	int delay;
	int ranked;
	int player;
	bool spectator;
};

static int MacadeQuarkHash(const char* id, int len)
{
	unsigned int hash = 1315423911;
	for (int i = 0; i < len; i++) hash ^= ((hash << 5) + id[i] + (hash >> 2));
	return (hash & 0x7FFFFFFF);
}

static int MacadeQuarkPlayer(const char* quarkId)
{
	const char* dot = strrchr(quarkId, '.');
	return (dot == NULL || dot[1] == '\0') ? 0 : atoi(dot + 1);
}

static bool MacadeParseRankedValue(const char* value, int* ranked)
{
	if (value == NULL || ranked == NULL) return false;
	if (strcmp(value, "null") == 0) {
		*ranked = 0;
		return true;
	}
	char* end = NULL;
	long parsed = strtol(value, &end, 10);
	if (end == value || *end != '\0') return false;
	*ranked = (int)parsed;
	return true;
}

static bool MacadeParseQuarkCommand(const char* command, MacadeQuarkCommand* parsed)
{
	char ranked[32] = { 0 };
	int consumed = 0;
	memset(parsed, 0, sizeof(*parsed));
	parsed->port = -1;
	if (sscanf(command, "quark:served,%63[^,],%127[^,],%d,%d,%31[^,]%n", parsed->game, parsed->quarkId, &parsed->port, &parsed->delay, ranked, &consumed) == 5 && command[consumed] == '\0' && MacadeParseRankedValue(ranked, &parsed->ranked)) {
		strncpy(parsed->mode, "served", sizeof(parsed->mode) - 1);
		parsed->player = MacadeQuarkPlayer(parsed->quarkId);
		return true;
	}
	consumed = 0;
	if (sscanf(command, "quark:served,%63[^,],%127[^,],%d,%d%n", parsed->game, parsed->quarkId, &parsed->port, &parsed->delay, &consumed) == 4 && command[consumed] == '\0') {
		strncpy(parsed->mode, "served", sizeof(parsed->mode) - 1);
		parsed->player = MacadeQuarkPlayer(parsed->quarkId);
		return true;
	}
	consumed = 0;
	if (sscanf(command, "quark:training,%63[^,],%127[^,],%d,%d%n", parsed->game, parsed->quarkId, &parsed->port, &parsed->delay, &consumed) == 4 && command[consumed] == '\0') {
		strncpy(parsed->mode, "training", sizeof(parsed->mode) - 1);
		parsed->player = MacadeQuarkPlayer(parsed->quarkId);
		return true;
	}
	consumed = 0;
	if (sscanf(command, "macade:training,%63[^,]%n", parsed->game, &consumed) == 1 && command[consumed] == '\0') {
		strncpy(parsed->mode, "traininglocal", sizeof(parsed->mode) - 1);
		parsed->player = 0;
		parsed->delay = 0;
		return true;
	}
	consumed = 0;
	if (sscanf(command, "quark:direct,%63[^,],%d,%127[^,],%d,%d,%d,%31[^,]%n", parsed->game, &parsed->port, parsed->remoteHost, &parsed->remotePort, &parsed->player, &parsed->delay, ranked, &consumed) == 7 && command[consumed] == '\0' && MacadeParseRankedValue(ranked, &parsed->ranked)) {
		strncpy(parsed->mode, "direct", sizeof(parsed->mode) - 1);
		return true;
	}
	consumed = 0;
	if (sscanf(command, "quark:direct,%63[^,],%d,%127[^,],%d,%d,%d%n", parsed->game, &parsed->port, parsed->remoteHost, &parsed->remotePort, &parsed->player, &parsed->delay, &consumed) == 6 && command[consumed] == '\0') {
		strncpy(parsed->mode, "direct", sizeof(parsed->mode) - 1);
		return true;
	}
	if (sscanf(command, "quark:stream,%63[^,],%127[^,],%d", parsed->game, parsed->quarkId, &parsed->port) == 3) {
		strncpy(parsed->mode, "stream", sizeof(parsed->mode) - 1);
		parsed->player = 2;
		parsed->spectator = true;
		return true;
	}
	if (strncmp(command, "quark:replay,", 13) == 0 && command[13] != 0) {
		strncpy(parsed->mode, "replay", sizeof(parsed->mode) - 1);
		strncpy(parsed->replayFile, command + 13, sizeof(parsed->replayFile) - 1);
		parsed->player = 0;
		parsed->delay = 0;
		return MacadeReadReplayGameName(parsed->replayFile, parsed->game, sizeof(parsed->game));
	}
	return false;
}

static bool __cdecl MacadeBeginGame(char* game)
{
	printf("Macade GGPO callback: begin_game game=%s\n", game ? game : "");
	fflush(stdout);
	return true;
}

static int __cdecl MacadeReadAcb(struct BurnArea* pba)
{
	if (pba == NULL || pba->Data == NULL || pba->nLen == 0) return 0;
	const unsigned char* bytes = (const unsigned char*)pba->Data;
	gMacadeStateBuffer.insert(gMacadeStateBuffer.end(), bytes, bytes + pba->nLen);
	return 0;
}

static int __cdecl MacadeWriteAcb(struct BurnArea* pba)
{
	if (pba == NULL || pba->Data == NULL || pba->nLen == 0) return 0;
	if (gMacadeLoadRemaining < (int)pba->nLen) return 1;
	memcpy(pba->Data, gMacadeLoadCursor, pba->nLen);
	gMacadeLoadCursor += pba->nLen;
	gMacadeLoadRemaining -= (int)pba->nLen;
	return 0;
}

static bool __cdecl MacadeSaveState(unsigned char** buffer, int* len, int* checksum, int)
{
	if (buffer == NULL || len == NULL || checksum == NULL) return false;
	*buffer = NULL; *len = 0; *checksum = 0;
	gMacadeStateBuffer.clear();
	gMacadeStateBuffer.reserve(2 * 1024 * 1024);
	BurnAcb = MacadeReadAcb;
	BurnAreaScan(ACB_FULLSCANL | ACB_READ, NULL);
	if (gMacadeStateBuffer.empty()) return false;
	*len = (int)gMacadeStateBuffer.size() + kMacadeGGPOStateHeaderSize;
	*buffer = (unsigned char*)malloc((size_t)*len);
	if (*buffer == NULL) { *len = 0; return false; }
	int* header = (int*)*buffer;
	int score1 = 0;
	int score2 = 0;
	MacadeOverlayGetScores(&score1, &score2);
	header[0] = kMacadeGGPOStateMagic;
	header[1] = kMacadeGGPOStateHeaderSize;
	header[2] = nBurnVer;
	header[3] = ((score1 & 0xff) << 8) | ((score2 & 0xff) << 16) | ((iRanked & 0xff) << 24);
	header[4] = 0;
	header[5] = 0;
	memcpy(*buffer + kMacadeGGPOStateHeaderSize, gMacadeStateBuffer.data(), gMacadeStateBuffer.size());
	return true;
}

static void MacadeApplyPostStateLoadFixups()
{
	if (!strcmp(BurnDrvGetTextA(DRV_NAME), "sfiii3nr1") && ReadValueAtHardwareAddress(0x638FC63, 1, 0) == 0x0A) {
		WriteValueAtHardwareAddress(0x638FC63, 0x0B, 1, 0);
	}
}

static bool __cdecl MacadeLoadState(unsigned char* buffer, int len)
{
	if (buffer == NULL || len <= 0) return false;
	int payloadOffset = 0;
	if (len >= kMacadeGGPOStateHeaderSize) {
		int* header = (int*)buffer;
		if (header[0] == kMacadeGGPOStateMagic && header[1] > 0 && header[1] <= len) {
			payloadOffset = header[1];
			int score1 = (header[3] >> 8) & 0xff;
			int score2 = (header[3] >> 16) & 0xff;
			int ranked = (header[3] >> 24) & 0xff;
			if (ranked > 0) iRanked = ranked;
			MacadeOverlaySetSession(kNetSpectator, iRanked, iPlayer);
			MacadeOverlaySetScores(score1, score2);
		}
	}
	gMacadeLoadCursor = buffer + payloadOffset;
	gMacadeLoadRemaining = len - payloadOffset;
	BurnAcb = MacadeWriteAcb;
	int result = BurnAreaScan(ACB_FULLSCANL | ACB_WRITE, NULL);
	gMacadeLoadCursor = NULL;
	gMacadeLoadRemaining = 0;
	if (result == 0) MacadeApplyPostStateLoadFixups();
	return result == 0;
}

static void MacadeComputeLogChecksum(struct BurnArea* pba)
{
	if (pba == NULL || pba->Data == NULL) return;
	const unsigned char* bytes = (const unsigned char*)pba->Data;
	for (unsigned int i = 0; i < pba->nLen; i++) {
		if (bytes[i] != 0) {
			if ((i & 1) != 0) gMacadeLogChecksum *= bytes[i];
			else gMacadeLogChecksum += bytes[i] * 317;
		} else {
			gMacadeLogChecksum++;
		}
	}
}

static int __cdecl MacadeLogAcb(struct BurnArea* pba)
{
	if (gMacadeLogFile == NULL || pba == NULL || pba->Data == NULL) return 0;
	fprintf(gMacadeLogFile, "%s:", pba->szName == NULL ? "" : pba->szName);
	for (unsigned int i = 0; i < pba->nLen; i++) {
		if ((i % 30) == 0) fprintf(gMacadeLogFile, "\noffset %9u :", i);
		else if ((i % 10) == 0) fprintf(gMacadeLogFile, " - ");
		fprintf(gMacadeLogFile, " %02x", ((unsigned char*)pba->Data)[i]);
	}
	fprintf(gMacadeLogFile, "\n");
	MacadeComputeLogChecksum(pba);
	return 0;
}

static bool __cdecl MacadeLogState(char* filename, unsigned char* buffer, int len)
{
	if (filename == NULL || buffer == NULL || len <= 0) return false;
	if (!MacadeLoadState(buffer, len)) return false;
	gMacadeLogFile = fopen(filename, "w");
	if (gMacadeLogFile == NULL) return false;
	gMacadeLogChecksum = 0;
	BurnAcb = MacadeLogAcb;
	BurnAreaScan(ACB_FULLSCANL | ACB_READ, NULL);
	fprintf(gMacadeLogFile, "\n");
	fprintf(gMacadeLogFile, "Checksum:       %d\n", gMacadeLogChecksum);
	fprintf(gMacadeLogFile, "Buffer Pointer: %p\n", buffer);
	fprintf(gMacadeLogFile, "Buffer Len:     %d\n", len);
	fclose(gMacadeLogFile);
	gMacadeLogFile = NULL;
	return true;
}
static void __cdecl MacadeFreeBuffer(void* buffer) { free(buffer); }
static bool __cdecl MacadeAdvanceFrame(int) { return MacadeNetworkReplayFrame() == 0; }

static void MacadeStartGameplayTracking()
{
	if (gMacadeGameplayTrackingStarted || kNetSpectator || gMacadeLocalTraining) return;
	gMacadeGameplayTrackingStarted = true;
	if (ggpo != NULL && iRanked > 0) ggpo_client_set_game_event(ggpo, GGPOCLIENT_GAMEEVENT_STARTING, NULL);
	MacadeDetectorLoad(gMacadeGame, false, iSeed);
}

static void MacadeLoadTrainingLuaIfNeeded()
{
	if (!gMacadeLocalTraining || gMacadeTrainingLuaLoaded) return;
	gMacadeTrainingLuaLoaded = true;
	int result = FBA_LoadLuaCode("fbneo-training-mode/fbneo-training-mode.lua");
	printf("Macade quark: Fightcade training Lua load result=%d\n", result);
	fflush(stdout);
}

static bool __cdecl MacadeOnEvent(GGPOEvent* info)
{
	if (info != NULL && ggpo_is_client_eventcode(info->code)) {
		GGPOClientEvent* event = (GGPOClientEvent*)info;
		switch (event->code) {
		case GGPOCLIENT_EVENTCODE_CONNECTING:
			MacadeOverlaySetSystemMessage("Connecting...");
			break;
		case GGPOCLIENT_EVENTCODE_CONNECTED:
			MacadeOverlaySetSystemMessage("Connected");
			break;
		case GGPOCLIENT_EVENTCODE_RETREIVING_MATCHINFO:
			MacadeOverlaySetSystemMessage("Retrieving Match Info...");
			break;
		case GGPOCLIENT_EVENTCODE_MATCHINFO:
			MacadeOverlaySetSystemMessage("");
			MacadeOverlaySetGameInfo(event->u.matchinfo.p1, event->u.matchinfo.p2, kNetSpectator, iRanked, iPlayer);
			break;
		case GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED:
			MacadeOverlaySetSpectators(event->u.spectator_count_changed.count);
			break;
		case GGPOCLIENT_EVENTCODE_CHAT:
			MacadeOverlayAddChatLine(event->u.chat.username, event->u.chat.text);
			break;
		case GGPOCLIENT_EVENTCODE_DISCONNECTED:
			MacadeOverlaySetSystemMessage("Disconnected!");
			break;
		default:
			break;
		}
	}
	else if (info != NULL) {
		switch (info->code) {
		case GGPO_EVENTCODE_CONNECTED_TO_PEER:
			MacadeOverlaySetSystemMessage("Connected to Peer");
			break;
		case GGPO_EVENTCODE_SYNCHRONIZING_WITH_PEER:
			MacadeOverlaySetSystemMessage("Synchronizing with Peer...");
			break;
		case GGPO_EVENTCODE_RUNNING:
			MacadeOverlaySetSystemMessage("");
			break;
		case GGPO_EVENTCODE_DISCONNECTED_FROM_PEER:
			MacadeOverlaySetSystemMessage("Disconnected from Peer");
			break;
		default:
			break;
		}
	}
	printf("Macade GGPO callback: on_event code=%d\n", info ? info->code : 0);
	fflush(stdout);
	return true;
}

int MacadeQuarkHandleCommand(const char* command)
{
	MacadeQuarkCommand parsed;
	if (!MacadeParseQuarkCommand(command, &parsed)) {
		printf("Macade quark: unsupported command format: %s\n", command);
		fflush(stdout);
		return 2;
	}
	kNetVersion = NET_VERSION;
	kNetGame = 1;
	kNetSpectator = parsed.spectator ? 1 : 0;
	bool localTraining = strcmp(parsed.mode, "traininglocal") == 0;
	gMacadeLocalTraining = localTraining;
	gMacadeTrainingLuaLoaded = false;
	kNetLua = strcmp(parsed.mode, "served") == 0 ? 0 : 1;
	gMacadeSessionLua = kNetLua;
	strncpy(kNetQuarkId, parsed.quarkId, sizeof(kNetQuarkId) - 1);
	strncpy(gMacadeGame, parsed.game, sizeof(gMacadeGame) - 1);
	iRanked = parsed.ranked;
	iPlayer = parsed.player;
	iDelay = parsed.delay;
	int quarkIdLength = (int)strlen(parsed.quarkId);
	iSeed = parsed.spectator || quarkIdLength < 2 ? 0 : MacadeQuarkHash(parsed.quarkId, quarkIdLength - 2);
	MacadeOverlayReset();
	MacadeOverlaySetSession(parsed.spectator ? 1 : 0, parsed.ranked, parsed.player);
	MacadeOverlaySetSystemMessage(localTraining ? "Training" : (strcmp(parsed.mode, "replay") == 0 ? "Replay" : "Connecting..."));
	gMacadeGameplayTrackingStarted = false;
	printf("Macade quark: parsed command\nMacade quark: mode=%s\nMacade quark: game=%s\nMacade quark: quarkId=%s\n", parsed.mode, parsed.game, parsed.quarkId);
	printf("Macade quark: port=%d\nMacade quark: remoteHost=%s\nMacade quark: remotePort=%d\nMacade quark: delay=%d\nMacade quark: ranked=%d\nMacade quark: player=%d\nMacade quark: spectator=%d\nMacade quark: seed=%d\n", parsed.port, parsed.remoteHost, parsed.remotePort, parsed.delay, parsed.ranked, parsed.player, parsed.spectator ? 1 : 0, iSeed);
	GGPOSessionCallbacks cb;
	memset(&cb, 0, sizeof(cb));
	cb.begin_game = MacadeBeginGame;
	cb.save_game_state = MacadeSaveState;
	cb.load_game_state = MacadeLoadState;
	cb.log_game_state = MacadeLogState;
	cb.free_buffer = MacadeFreeBuffer;
	cb.advance_frame = MacadeAdvanceFrame;
	cb.on_event = MacadeOnEvent;
	if (localTraining) {
		printf("Macade quark: native Fightcade local training session prepared\n");
		fflush(stdout);
		return 0;
	}
	if (strcmp(parsed.mode, "replay") == 0) ggpo = ggpo_start_replay(&cb, parsed.replayFile);
	else if (strcmp(parsed.mode, "direct") == 0) ggpo = ggpo_start_session(&cb, parsed.game, parsed.port, parsed.remoteHost, parsed.remotePort, parsed.player);
	else ggpo = parsed.spectator ? ggpo_start_streaming(&cb, parsed.game, parsed.quarkId, parsed.port) : ggpo_client_connect(&cb, parsed.game, parsed.quarkId, parsed.port);
	if (ggpo == NULL) return 2;
	ggpo_set_frame_delay(ggpo, parsed.delay);
	printf("Macade quark: native Fightcade GGPO %s session connected\n", parsed.mode);
	fflush(stdout);
	return 0;
}

int MacadeQuarkLoadStateIfAvailable()
{
	if (gMacadeGame[0] == 0) return 0;
	if (ggpo != NULL && ggpo->isReplayPlayback) {
		MacadeQuarkRestoreNetworkFlags();
		return MacadeLoadReplayInitialStateIfNeeded(ggpo) ? 0 : 1;
	}
	if (ggpo != NULL && ggpo->isSpectator) {
		MacadeQuarkRestoreNetworkFlags();
		if (!ggpo->streamInitialStateReceived) return 1;
		return MacadeLoadStreamingInitialState(ggpo, 0) ? 0 : 1;
	}
	if (!kNetGame) return 0;
	const char* suffixes[3] = { "_ggpo.fs", iRanked ? "_fbneo_ranked.fs" : "_fbneo.fs", iRanked ? "_fbneo.fs" : NULL };
	char path[256];
	for (int i = 0; i < 3; i++) {
		if (suffixes[i] == NULL) continue;
		snprintf(path, sizeof(path), "savestates/%s%s", gMacadeGame, suffixes[i]);
		FILE* file = fopen(path, "rb");
		if (file == NULL) continue;
		fclose(file);
		int result = BurnStateLoad(path, 1, NULL);
		printf("Macade quark: savestate load path=%s result=%d\n", path, result);
		fflush(stdout);
		if (ggpo != NULL && MacadeSaveFrame(ggpo, -1)) printf("Macade quark: rollback initial state captured frame=-1\n");
		MacadeStartGameplayTracking();
		MacadeLoadTrainingLuaIfNeeded();
		return result;
	}
	printf("Macade quark: no Fightcade savestate found for game=%s\n", gMacadeGame);
	fflush(stdout);
	if (ggpo != NULL && MacadeSaveFrame(ggpo, -1)) printf("Macade quark: rollback initial state captured frame=-1\n");
	MacadeStartGameplayTracking();
	MacadeLoadTrainingLuaIfNeeded();
	return 1;
}

const char* MacadeQuarkGameName() { return gMacadeGame; }
bool MacadeQuarkSessionActive() { return gMacadeGame[0] != 0 && (ggpo != NULL || gMacadeLocalTraining); }
bool MacadeQuarkLocalTrainingActive() { return gMacadeGame[0] != 0 && gMacadeLocalTraining; }
bool MacadeQuarkSessionRunning() { return ggpo != NULL && !ggpo->networkDisconnected && !ggpo->fatalDesync; }
bool MacadeQuarkStreamInitialStateLoaded() { return ggpo != NULL && ggpo->isSpectator && ggpo->streamInitialStateLoaded; }
void MacadeQuarkRestoreNetworkFlags()
{
	if (!MacadeQuarkSessionActive()) return;
	kNetVersion = NET_VERSION;
	kNetGame = 1;
	kNetSpectator = ggpo != NULL && ggpo->isSpectator ? 1 : 0;
	kNetLua = gMacadeSessionLua;
}
void MacadeQuarkRunIdle(int ms) { if (ggpo != NULL) ggpo_idle(ggpo, ms); }
bool MacadeQuarkIncrementFrame()
{
	if (ggpo == NULL) return true;
	bool result = ggpo_advance_frame(ggpo);
	GGPONetworkStats stats;
	memset(&stats, 0, sizeof(stats));
	if (ggpo_get_stats(ggpo, &stats)) MacadeOverlaySetStats(0, stats.network.ping, iDelay);
	return result;
}
