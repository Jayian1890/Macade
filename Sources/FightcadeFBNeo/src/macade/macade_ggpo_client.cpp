#include "burner.h"
#include "macade_ggpo_session.h"
#include "macade_overlay.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

extern int iDelay;
extern int iPlayer;

GGPOSession* ggpo = NULL;

static long long MacadeNowMilliseconds()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return (long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL;
}

void MacadeLog(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	fflush(stdout);
}

static void EmitEvent(GGPOSession* session, GGPOEventCode code)
{
	if (session == NULL || session->callbacks.on_event == NULL) return;
	GGPOEvent event;
	memset(&event, 0, sizeof(event));
	event.code = code;
	session->callbacks.on_event(&event);
}

void MacadeEmitClientEvent(GGPOSession* session, GGPOClientEventCode code, const char* p1, const char* p2, const char* blurb, int count)
{
	if (session == NULL || session->callbacks.on_event == NULL) return;
	GGPOClientEvent event;
	memset(&event, 0, sizeof(event));
	event.code = code;
	if (code == GGPOCLIENT_EVENTCODE_MATCHINFO) {
		event.u.matchinfo.p1 = const_cast<char*>(p1 == NULL ? "" : p1);
		event.u.matchinfo.p2 = const_cast<char*>(p2 == NULL ? "" : p2);
		event.u.matchinfo.blurb = const_cast<char*>(blurb == NULL ? "" : blurb);
	} else if (code == GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED) {
		event.u.spectator_count_changed.count = count;
	}
	session->callbacks.on_event((GGPOEvent*)&event);
}

void MacadeEmitChatEvent(GGPOSession* session, const char* username, const char* text)
{
	if (session == NULL || session->callbacks.on_event == NULL) return;
	GGPOClientEvent event;
	memset(&event, 0, sizeof(event));
	event.code = GGPOCLIENT_EVENTCODE_CHAT;
	event.u.chat.username = const_cast<char*>(username == NULL ? "" : username);
	event.u.chat.text = const_cast<char*>(text == NULL ? "" : text);
	session->callbacks.on_event((GGPOEvent*)&event);
}

void MacadeMarkDisconnected(GGPOSession* session)
{
	if (session == NULL) return;
	session->networkDisconnected = true;
	if (!session->clientDisconnectEventSent) {
		session->clientDisconnectEventSent = true;
		MacadeLog("Macade GGPO: transport disconnected tcp=%d udp=%d spectator=%d\n", session->tcpFd, session->udpFd, session->isSpectator ? 1 : 0);
		MacadeEmitClientEvent(session, GGPOCLIENT_EVENTCODE_DISCONNECTED, NULL, NULL, NULL, 0);
	}
}

static void MacadeFreeSavedState(GGPOSession* session, unsigned char* state)
{
	if (state == NULL) return;
	if (session != NULL && session->callbacks.free_buffer != NULL) session->callbacks.free_buffer(state);
	else free(state);
}

static void MacadeTrimHistory(GGPOSession* session)
{
	if (session == NULL) return;
	while ((int)session->savedFrames.size() > session->maxSavedFrames) session->savedFrames.erase(session->savedFrames.begin());
	int oldestInputFrame = session->currentFrame - session->maxInputHistoryFrames;
	while (!session->localInputs.empty() && session->localInputs.begin()->first < oldestInputFrame) session->localInputs.erase(session->localInputs.begin());
	while (!session->remoteInputs.empty() && session->remoteInputs.begin()->first < oldestInputFrame) session->remoteInputs.erase(session->remoteInputs.begin());
	while (!session->predictedRemoteInputs.empty() && session->predictedRemoteInputs.begin()->first < oldestInputFrame) session->predictedRemoteInputs.erase(session->predictedRemoteInputs.begin());
}

bool MacadeSaveCurrentFrame(GGPOSession* session)
{
	if (session == NULL || session->callbacks.save_game_state == NULL) return false;
	unsigned char* state = NULL;
	int stateLength = 0;
	int checksum = 0;
	session->callbacks.save_game_state(&state, &stateLength, &checksum, session->currentFrame);
	if (state == NULL || stateLength <= 0) {
		MacadeFreeSavedState(session, state);
		return false;
	}
	MacadeSavedFrame saved;
	saved.frame = session->currentFrame;
	saved.checksum = checksum;
	saved.bytes.assign(state, state + stateLength);
	MacadeFreeSavedState(session, state);
	session->savedFrames[session->currentFrame] = saved;
	session->savedStateCount++;
	MacadeTrimHistory(session);
	return true;
}

static int MacadeFirstAvailableSavedFrame(GGPOSession* session, int requestedFrame)
{
	if (session == NULL || session->savedFrames.empty()) return -1;
	std::map<int, MacadeSavedFrame>::iterator exact = session->savedFrames.find(requestedFrame);
	if (exact != session->savedFrames.end()) return exact->first;
	std::map<int, MacadeSavedFrame>::iterator next = session->savedFrames.lower_bound(requestedFrame);
	if (next != session->savedFrames.begin()) {
		--next;
		return next->first;
	}
	return session->savedFrames.begin()->first;
}

bool MacadeRunRollbackIfNeeded(GGPOSession* session)
{
	if (session == NULL || session->fatalDesync || session->replaying || session->rollbackRequestedFrame < 0) return session != NULL && !session->fatalDesync;
	int targetFrame = session->currentFrame;
	int seekFrame = session->rollbackRequestedFrame;
	if (seekFrame >= targetFrame) {
		session->rollbackRequestedFrame = -1;
		return true;
	}
	int savedFrame = MacadeFirstAvailableSavedFrame(session, seekFrame);
	if (savedFrame < 0 || session->callbacks.load_game_state == NULL || session->callbacks.advance_frame == NULL) {
		session->fatalDesync = true;
		MacadeLog("Macade GGPO: cannot rollback to frame %d; saved state or callback missing\n", seekFrame);
		return false;
	}
	std::map<int, MacadeSavedFrame>::iterator saved = session->savedFrames.find(savedFrame);
	if (saved == session->savedFrames.end() || saved->second.bytes.empty()) {
		session->fatalDesync = true;
		MacadeLog("Macade GGPO: saved state for rollback frame %d is unavailable\n", savedFrame);
		return false;
	}
	MacadeLog("Macade GGPO: rollback start seek=%d saved=%d target=%d checksum=%d\n", seekFrame, savedFrame, targetFrame, saved->second.checksum);
	if (!session->callbacks.load_game_state(saved->second.bytes.data(), (int)saved->second.bytes.size())) {
		session->fatalDesync = true;
		MacadeLog("Macade GGPO: rollback load failed frame=%d\n", savedFrame);
		return false;
	}
	session->currentFrame = savedFrame;
	session->rollbackRequestedFrame = -1;
	session->replaying = true;
	session->predictedRemoteInputs.erase(session->predictedRemoteInputs.lower_bound(savedFrame), session->predictedRemoteInputs.end());
	while (session->currentFrame < targetFrame && !session->fatalDesync) {
		int before = session->currentFrame;
		if (!session->callbacks.advance_frame(0) || session->currentFrame != before + 1) {
			session->fatalDesync = true;
			MacadeLog("Macade GGPO: rollback replay failed at frame=%d current=%d\n", before, session->currentFrame);
			break;
		}
		session->rollbackReplayFrameCount++;
	}
	session->replaying = false;
	if (session->fatalDesync) return false;
	session->rollbackCount++;
	MacadeLog("Macade GGPO: rollback complete target=%d replayed=%d total=%d\n", targetFrame, targetFrame - savedFrame, session->rollbackCount);
	return true;
}

static void MacadeRequestRollback(GGPOSession* session, int frame)
{
	if (session == NULL || frame < 0) return;
	if (frame >= session->currentFrame) return;
	if (session->rollbackRequestedFrame < 0 || frame < session->rollbackRequestedFrame) session->rollbackRequestedFrame = frame;
}

bool MacadeStoreRemoteInput(GGPOSession* session, int frame, const std::vector<unsigned char>& input)
{
	if (session == NULL || frame < 0 || input.empty()) return false;
	std::map<int, std::vector<unsigned char> >::iterator predicted = session->predictedRemoteInputs.find(frame);
	if (predicted != session->predictedRemoteInputs.end()) {
		if (predicted->second != input) {
			session->predictionMismatchCount++;
			MacadeRequestRollback(session, frame);
			MacadeLog("Macade GGPO: predicted remote frame %d mismatched actual input; rollback queued target=%d\n", frame, session->currentFrame);
		}
		session->predictedRemoteInputs.erase(predicted);
	}
	std::map<int, std::vector<unsigned char> >::iterator existing = session->remoteInputs.find(frame);
	if (existing != session->remoteInputs.end() && existing->second != input) {
		existing->second = input;
		session->predictionMismatchCount++;
		MacadeRequestRollback(session, frame);
	} else {
		session->remoteInputs[frame] = input;
	}
	if (frame > session->remoteLastFrame) session->remoteLastFrame = frame;
	session->lastRemoteInput = input;
	return true;
}

static void MacadeQueueLocalInput(GGPOSession* session, const std::vector<unsigned char>& input)
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

static std::vector<unsigned char> MacadeInputForFrame(const std::map<int, std::vector<unsigned char> >& inputs, int frame, int size, const std::vector<unsigned char>& fallback)
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
	session->startedAtMs = MacadeNowMilliseconds();
	if (!MacadeEstablishServedSession(session, matchid, serverport)) {
		delete session;
		return NULL;
	}
	if (session->callbacks.begin_game != NULL) session->callbacks.begin_game(game);
	EmitEvent(session, GGPO_EVENTCODE_CONNECTED_TO_PEER);
	EmitEvent(session, GGPO_EVENTCODE_RUNNING);
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
	session->startedAtMs = MacadeNowMilliseconds();
	if (!MacadeEstablishDirectSession(session, localport, remoteip, remoteport)) {
		delete session;
		return NULL;
	}
	if (session->callbacks.begin_game != NULL) session->callbacks.begin_game(game);
	EmitEvent(session, GGPO_EVENTCODE_CONNECTED_TO_PEER);
	EmitEvent(session, GGPO_EVENTCODE_RUNNING);
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
	session->startedAtMs = MacadeNowMilliseconds();
	if (!MacadeEstablishStreamingSession(session, matchid, serverport)) {
		delete session;
		return NULL;
	}
	if (session->callbacks.begin_game != NULL) session->callbacks.begin_game(game);
	EmitEvent(session, GGPO_EVENTCODE_CONNECTED_TO_PEER);
	EmitEvent(session, GGPO_EVENTCODE_RUNNING);
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
	// Keep the timeout as a total idle budget; blocking once per transport visibly stalls gameplay.
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
		MacadeQueueLocalInput(session, rawLocal);
		MacadePumpUDPControl(session);
		MacadeSendUDPInput(session, rawLocal.data(), size, session->localSendHighFrame);
		MacadeSendTCPFrameBatch(session);
		MacadePollTCP(session, 0);
		MacadePollUDP(session, 0);
		if (!MacadeRunRollbackIfNeeded(session)) return false;
	}
	memset(bytes, 0, (size_t)size * players);
	std::vector<unsigned char> local = MacadeInputForFrame(session->localInputs, session->currentFrame, size, session->lastLocalInput);
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
		MacadeTrimHistory(session);
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
	long long elapsedMs = MacadeNowMilliseconds() - session->startedAtMs;
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

bool __cdecl ggpo_client_chat(GGPOSession* session, char* text)
{
	return MacadeSendTCPChat(session, text);
}
bool __cdecl ggpo_client_set_game_event(GGPOSession* session, GGPOClientGameEventType type, void* data) { return MacadeHandleGameEvent(session, type, data); }
void __cdecl ggpo_log(GGPOSession*, char* fmt, ...) { va_list args; va_start(args, fmt); vprintf(fmt, args); va_end(args); }
void __cdecl ggpo_logv(GGPOSession*, char* fmt, va_list args) { vprintf(fmt, args); }
