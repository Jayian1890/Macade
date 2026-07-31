#include "ggpomac_internal.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

extern int iDelay;
extern int iPlayer;
extern GGPOSession* ggpo;

static long long GGPOMacNowMilliseconds()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return (long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL;
}

static void GGPOMacEmitEvent(GGPOSession* session, GGPOEventCode code)
{
	if (session == NULL || session->callbacks.on_event == NULL) return;
	GGPOEvent event;
	memset(&event, 0, sizeof(event));
	event.code = code;
	session->callbacks.on_event(&event);
}

static void GGPOMacQueueLocalInput(GGPOSession* session, const std::vector<unsigned char>& input)
{
	if (session == NULL || input.empty()) return;
	int delay = session->delay < 0 ? 0 : session->delay;
	int targetFrame = session->currentFrame + delay;
	std::vector<unsigned char> fill(input.size(), 0);
	if (session->lastLocalInput.size() == input.size()) fill = session->lastLocalInput;
	int nextFrame = session->lastLocalQueuedFrame + 1;
	if (nextFrame < 0) nextFrame = 0;
	for (int frame = nextFrame; frame < targetFrame; frame++) session->localInputs[frame] = fill;
	session->localInputs[targetFrame] = input;
	session->lastLocalQueuedFrame = targetFrame;
	if (targetFrame > session->localSendHighFrame) session->localSendHighFrame = targetFrame;
	session->lastLocalInput = input;
}

static std::vector<unsigned char> GGPOMacInputForFrame(const std::map<int, std::vector<unsigned char> >& inputs, int frame, int size, const std::vector<unsigned char>& fallback)
{
	std::map<int, std::vector<unsigned char> >::const_iterator input = inputs.find(frame);
	if (input != inputs.end() && input->second.size() == (size_t)size) return input->second;
	if (fallback.size() == (size_t)size) return fallback;
	return std::vector<unsigned char>(size, 0);
}

GGPOSession* __cdecl ggpo_client_connect(GGPOSessionCallbacks* cb, char* game, char* matchid, int serverport)
{
	GGPOSession* session = new GGPOSession();
	if (cb != NULL) session->callbacks = *cb;
	if (game != NULL) strncpy(session->gameName, game, sizeof(session->gameName) - 1);
	session->playerIndex = iPlayer < 0 ? 0 : (iPlayer > 1 ? 1 : iPlayer);
	session->delay = iDelay;
	session->startedAtMs = GGPOMacNowMilliseconds();
	if (!MacadeEstablishServedSession(session, matchid, serverport)) {
		delete session;
		return NULL;
	}
	if (session->callbacks.begin_game != NULL) session->callbacks.begin_game(game);
	GGPOMacEmitEvent(session, GGPO_EVENTCODE_CONNECTED_TO_PEER);
	GGPOMacEmitEvent(session, GGPO_EVENTCODE_RUNNING);
	MacadeLog("Macade GGPO: native served session ready game=%s match=%s player=%d\n", game, matchid, session->playerIndex);
	return session;
}

GGPOSession* __cdecl ggpo_start_session(GGPOSessionCallbacks* cb, char* game, int localport, char* remoteip, int remoteport, int player_num)
{
	GGPOSession* session = new GGPOSession();
	if (cb != NULL) session->callbacks = *cb;
	if (game != NULL) strncpy(session->gameName, game, sizeof(session->gameName) - 1);
	session->playerIndex = player_num < 0 ? 0 : (player_num > 1 ? 1 : player_num);
	session->delay = iDelay;
	session->startedAtMs = GGPOMacNowMilliseconds();
	if (!MacadeEstablishDirectSession(session, localport, remoteip, remoteport)) {
		delete session;
		return NULL;
	}
	if (session->callbacks.begin_game != NULL) session->callbacks.begin_game(game);
	GGPOMacEmitEvent(session, GGPO_EVENTCODE_CONNECTED_TO_PEER);
	GGPOMacEmitEvent(session, GGPO_EVENTCODE_RUNNING);
	MacadeLog("Macade GGPO: native direct session ready game=%s local=%d remote=%s:%d player=%d\n", game, localport, remoteip, remoteport, session->playerIndex);
	return session;
}

GGPOSession* __cdecl ggpo_start_synctest(GGPOSessionCallbacks*, char*, int) { return NULL; }

GGPOSession* __cdecl ggpo_start_streaming(GGPOSessionCallbacks* cb, char* game, char* matchid, int serverport)
{
	GGPOSession* session = new GGPOSession();
	if (cb != NULL) session->callbacks = *cb;
	if (game != NULL) strncpy(session->gameName, game, sizeof(session->gameName) - 1);
	session->isSpectator = true;
	session->playerIndex = 2;
	session->startedAtMs = GGPOMacNowMilliseconds();
	if (!MacadeEstablishStreamingSession(session, matchid, serverport)) {
		delete session;
		return NULL;
	}
	if (session->callbacks.begin_game != NULL) session->callbacks.begin_game(game);
	GGPOMacEmitEvent(session, GGPO_EVENTCODE_CONNECTED_TO_PEER);
	GGPOMacEmitEvent(session, GGPO_EVENTCODE_RUNNING);
	MacadeLog("Macade GGPO: native stream session ready game=%s match=%s\n", game, matchid);
	return session;
}

GGPOSession* __cdecl ggpo_start_replay(GGPOSessionCallbacks*, char*) { return NULL; }

void __cdecl ggpo_close_session(GGPOSession* session)
{
	if (session == NULL) return;
	if (session->udpFd >= 0) close(session->udpFd);
	if (session->tcpFd >= 0) close(session->tcpFd);
	delete session;
	if (ggpo == session) ggpo = NULL;
}

bool __cdecl ggpo_idle(GGPOSession* session, int timeout)
{
	int waitMs = timeout < 0 ? 0 : timeout;
	if (session != NULL && session->isSpectator) {
		MacadeStartStreamingTCPIfNeeded(session);
		MacadePollTCP(session, waitMs);
		return !session->networkDisconnected;
	}
	MacadePumpUDPControl(session);
	MacadePollTCP(session, 0);
	MacadePollUDP(session, waitMs);
	MacadePollTCP(session, 0);
	return session == NULL || (!session->networkDisconnected && MacadeRunRollbackIfNeeded(session));
}

bool __cdecl ggpo_synchronize_input(GGPOSession* session, void* values, int size, int players)
{
	if (session == NULL || values == NULL || players < 2 || size <= 0) return false;
	if (session->fatalDesync) return false;
	if (session->networkDisconnected) return false;
	if (session->isSpectator) {
		if (!session->streamInitialStateLoaded) return false;
		MacadePollTCP(session, 0);
		if (session->streamInputs.empty()) {
			MacadePollTCP(session, 16);
			if (session->streamInputs.empty()) return false;
		}
		int totalSize = size * players;
		int streamPlayers = players < 2 ? players : 2;
		int streamSize = size * streamPlayers;
		memset(values, 0, (size_t)totalSize);
		std::vector<unsigned char> input = session->streamInputs.front();
		session->streamInputs.pop_front();
		int copySize = input.size() < (size_t)streamSize ? (int)input.size() : streamSize;
		memcpy(values, input.data(), copySize);
		session->inputSize = size;
		session->streamFrameReadCount++;
		return true;
	}
	if (!session->replaying && !MacadeRunRollbackIfNeeded(session)) return false;
	unsigned char* bytes = (unsigned char*)values;
	int localSlot = session->playerIndex;
	int remoteSlot = localSlot == 0 ? 1 : 0;
	session->inputSize = size;
	std::vector<unsigned char> rawLocal(bytes, bytes + size);
	if (!session->replaying) {
		GGPOMacQueueLocalInput(session, rawLocal);
		MacadePumpUDPControl(session);
		MacadeSendUDPInput(session, rawLocal.data(), size, session->localSendHighFrame);
		MacadeSendTCPReadyIfNeeded(session);
		MacadeSendTCPFrameBatch(session);
		MacadePollTCP(session, 0);
		MacadePollUDP(session, 0);
		if (!MacadeRunRollbackIfNeeded(session)) return false;
	}
	memset(bytes, 0, (size_t)size * players);
	std::vector<unsigned char> local = GGPOMacInputForFrame(session->localInputs, session->currentFrame, size, session->lastLocalInput);
	memcpy(bytes + localSlot * size, local.data(), size);
	std::map<int, std::vector<unsigned char> >::iterator remote = session->remoteInputs.find(session->currentFrame);
	if (remote != session->remoteInputs.end()) {
		int copySize = remote->second.size() < (size_t)size ? (int)remote->second.size() : size;
		memcpy(bytes + remoteSlot * size, remote->second.data(), copySize);
		session->predictedRemoteInputs.erase(session->currentFrame);
	} else {
		if (session->currentFrame - session->remoteLastFrame > session->maxPredictionFrames) {
			if (session->remoteTimeoutCount < 8 || session->remoteTimeoutCount % 120 == 0) MacadeLog("Macade GGPO: remote frame %d missing beyond prediction window; netplay cannot advance\n", session->currentFrame);
			session->remoteTimeoutCount++;
			return false;
		}
		std::vector<unsigned char> predicted(size, 0);
		if (session->lastRemoteInput.size() == (size_t)size) predicted = session->lastRemoteInput;
		else if (session->currentFrame > 0) {
			std::map<int, std::vector<unsigned char> >::iterator prior = session->remoteInputs.find(session->currentFrame - 1);
			if (prior != session->remoteInputs.end() && prior->second.size() == (size_t)size) predicted = prior->second;
		}
		session->predictedRemoteInputs[session->currentFrame] = predicted;
		session->predictionCount++;
		if (session->remoteTimeoutCount < 8 || session->remoteTimeoutCount % 120 == 0) MacadeLog("Macade GGPO: predicting remote frame %d from last known frame %d\n", session->currentFrame, session->remoteLastFrame);
		session->remoteTimeoutCount++;
		memcpy(bytes + remoteSlot * size, predicted.data(), predicted.size());
	}
	MacadeReplayRecordInput(session, local.data(), size);
	return true;
}

bool __cdecl ggpo_advance_frame(GGPOSession* session)
{
	if (session != NULL) {
		session->currentFrame++;
		if (session->isSpectator) {
			MacadePollTCP(session, 0);
			return true;
		}
		MacadeSaveCurrentFrame(session);
		GGPOMacTrimHistory(session);
	}
	return true;
}

bool __cdecl ggpo_get_stats(GGPOSession* session, GGPONetworkStats* stats)
{
	if (stats == NULL) return false;
	memset(stats, 0, sizeof(*stats));
	if (session == NULL) return true;
	stats->network.predict_queue_len = (int)session->predictedRemoteInputs.size();
	stats->network.send_queue_len = session->localAckFrame < 0 ? session->localSendHighFrame + 1 : session->localSendHighFrame - session->localAckFrame;
	if (stats->network.send_queue_len < 0) stats->network.send_queue_len = 0;
	stats->network.recv_queue_len = session->remoteLastFrame >= session->currentFrame ? session->remoteLastFrame - session->currentFrame + 1 : 0;
	stats->network.ping = session->udpPingMs;
	long long elapsedMs = GGPOMacNowMilliseconds() - session->startedAtMs;
	if (elapsedMs > 0) stats->network.kbps_sent = (int)((session->bytesSent * 8ULL) / (unsigned long long)elapsedMs);
	stats->timesync.local_frames_behind = session->localFrameAdvantage < 0 ? -session->localFrameAdvantage : 0;
	stats->timesync.remote_frames_behind = session->localFrameAdvantage > 0 ? session->localFrameAdvantage : 0;
	return true;
}

bool __cdecl ggpo_set_frame_delay(GGPOSession* session, int frames)
{
	if (session == NULL) return false;
	if (frames < 0) frames = 0;
	session->delay = frames;
	iDelay = frames;
	MacadeLog("Macade GGPO: frame delay set to %d\n", frames);
	return true;
}

bool __cdecl ggpo_client_chat(GGPOSession* session, char* text) { return MacadeSendTCPChat(session, text); }
bool __cdecl ggpo_client_set_game_event(GGPOSession* session, GGPOClientGameEventType type, void* data) { return MacadeHandleGameEvent(session, type, data); }
void __cdecl ggpo_log(GGPOSession*, char* fmt, ...) { va_list args; va_start(args, fmt); vprintf(fmt, args); va_end(args); }
void __cdecl ggpo_logv(GGPOSession*, char* fmt, va_list args) { vprintf(fmt, args); }
