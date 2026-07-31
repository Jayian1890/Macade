#include "ggpomac_internal.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GGPOSession* ggpo = NULL;

void MacadeLog(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	fflush(stdout);
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

static void GGPOMacFreeSavedState(GGPOSession* session, unsigned char* state)
{
	if (state == NULL) return;
	if (session != NULL && session->callbacks.free_buffer != NULL) session->callbacks.free_buffer(state);
	else free(state);
}

void GGPOMacTrimHistory(GGPOSession* session)
{
	if (session == NULL) return;
	while ((int)session->savedFrames.size() > session->maxSavedFrames) session->savedFrames.erase(session->savedFrames.begin());
	int oldestInputFrame = session->currentFrame - session->maxInputHistoryFrames;
	while (!session->localInputs.empty() && session->localInputs.begin()->first < oldestInputFrame) session->localInputs.erase(session->localInputs.begin());
	while (!session->remoteInputs.empty() && session->remoteInputs.begin()->first < oldestInputFrame) session->remoteInputs.erase(session->remoteInputs.begin());
	while (!session->predictedRemoteInputs.empty() && session->predictedRemoteInputs.begin()->first < oldestInputFrame) session->predictedRemoteInputs.erase(session->predictedRemoteInputs.begin());
}

bool MacadeSaveFrame(GGPOSession* session, int frame)
{
	if (session == NULL || session->callbacks.save_game_state == NULL) return false;
	unsigned char* state = NULL;
	int stateLength = 0;
	int checksum = 0;
	session->callbacks.save_game_state(&state, &stateLength, &checksum, frame);
	if (state == NULL || stateLength <= 0) {
		GGPOMacFreeSavedState(session, state);
		return false;
	}
	GGPOMacSavedFrame saved;
	saved.frame = frame;
	saved.checksum = checksum;
	saved.bytes.assign(state, state + stateLength);
	GGPOMacFreeSavedState(session, state);
	session->savedFrames[frame] = saved;
	session->savedStateCount++;
	GGPOMacTrimHistory(session);
	return true;
}

bool MacadeSaveCurrentFrame(GGPOSession* session)
{
	return MacadeSaveFrame(session, session == NULL ? 0 : session->currentFrame);
}

static const int kGGPOMacNoSavedFrame = -1000000;

static int GGPOMacFirstAvailableSavedFrame(GGPOSession* session, int requestedFrame)
{
	if (session == NULL || session->savedFrames.empty()) return kGGPOMacNoSavedFrame;
	std::map<int, GGPOMacSavedFrame>::iterator exact = session->savedFrames.find(requestedFrame);
	if (exact != session->savedFrames.end()) return exact->first;
	std::map<int, GGPOMacSavedFrame>::iterator next = session->savedFrames.lower_bound(requestedFrame);
	if (next != session->savedFrames.begin()) {
		--next;
		return next->first;
	}
	return session->savedFrames.begin()->first;
}

static const int kGGPOMacNoRollbackFrame = -2;

bool MacadeRunRollbackIfNeeded(GGPOSession* session)
{
	if (session == NULL || session->fatalDesync || session->replaying || session->rollbackRequestedFrame == kGGPOMacNoRollbackFrame) return session != NULL && !session->fatalDesync;
	int targetFrame = session->currentFrame;
	int seekFrame = session->rollbackRequestedFrame;
	if (seekFrame >= targetFrame) {
		session->rollbackRequestedFrame = kGGPOMacNoRollbackFrame;
		return true;
	}
	int savedFrame = GGPOMacFirstAvailableSavedFrame(session, seekFrame);
	if (savedFrame == kGGPOMacNoSavedFrame || session->callbacks.load_game_state == NULL || session->callbacks.advance_frame == NULL) {
		session->fatalDesync = true;
		MacadeLog("Macade GGPO: cannot rollback to frame %d; saved state or callback missing\n", seekFrame);
		return false;
	}
	std::map<int, GGPOMacSavedFrame>::iterator saved = session->savedFrames.find(savedFrame);
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
	session->currentFrame = savedFrame + 1;
	session->rollbackRequestedFrame = kGGPOMacNoRollbackFrame;
	session->replaying = true;
	session->predictedRemoteInputs.erase(session->predictedRemoteInputs.lower_bound(session->currentFrame), session->predictedRemoteInputs.end());
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
	MacadeLog("Macade GGPO: rollback complete target=%d replayed=%d total=%d\n", targetFrame, targetFrame - (savedFrame + 1), session->rollbackCount);
	return true;
}

static void GGPOMacRequestRollback(GGPOSession* session, int frame)
{
	if (session == NULL || frame < 0) return;
	int seekFrame = frame - 1;
	if (seekFrame >= session->currentFrame) return;
	if (session->rollbackRequestedFrame == kGGPOMacNoRollbackFrame || seekFrame < session->rollbackRequestedFrame) session->rollbackRequestedFrame = seekFrame;
}

bool MacadeStoreRemoteInput(GGPOSession* session, int frame, const std::vector<unsigned char>& input)
{
	if (session == NULL || frame < 0 || input.empty()) return false;
	bool newestRemoteInput = frame >= session->remoteLastFrame;
	std::map<int, std::vector<unsigned char> >::iterator predicted = session->predictedRemoteInputs.find(frame);
	if (predicted != session->predictedRemoteInputs.end()) {
		if (predicted->second != input) {
			session->predictionMismatchCount++;
			GGPOMacRequestRollback(session, frame);
			MacadeLog("Macade GGPO: predicted remote frame %d mismatched actual input; rollback queued target=%d\n", frame, session->currentFrame);
		}
		session->predictedRemoteInputs.erase(predicted);
	}
	std::map<int, std::vector<unsigned char> >::iterator existing = session->remoteInputs.find(frame);
	if (existing != session->remoteInputs.end() && existing->second != input) {
		existing->second = input;
		session->predictionMismatchCount++;
		GGPOMacRequestRollback(session, frame);
	} else {
		session->remoteInputs[frame] = input;
	}
	if (newestRemoteInput) {
		session->remoteLastFrame = frame;
		session->lastRemoteInput = input;
	}
	return true;
}
