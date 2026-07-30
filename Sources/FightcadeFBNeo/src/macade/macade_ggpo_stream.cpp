#include "macade_ggpo_session.h"

#include <string.h>
#include <zlib.h>

static unsigned int ReadBE32(const unsigned char* data)
{
	return ((unsigned int)data[0] << 24) | ((unsigned int)data[1] << 16) | ((unsigned int)data[2] << 8) | (unsigned int)data[3];
}

static bool ShouldLogCount(int count) { return count < 8 || count % 120 == 0; }

static void HandleTCPStreamGameBuffer(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL || payload == NULL || payloadSize < 4) return;
	unsigned int rawLength = ReadBE32(payload);
	if (rawLength == 0 || rawLength > 128 * 1024 * 1024) return;
	uLongf decompressedLength = (uLongf)rawLength;
	std::vector<unsigned char> decompressed((size_t)decompressedLength);
	int result = uncompress(decompressed.data(), &decompressedLength, payload + 4, (uLong)(payloadSize - 4));
	if (result != Z_OK || decompressedLength != rawLength) {
		MacadeLog("Macade GGPO: stream gamebuffer decompress failed result=%d raw=%u compressed=%u produced=%lu\n", result, rawLength, payloadSize - 4, (unsigned long)decompressedLength);
		return;
	}
	decompressed.resize((size_t)decompressedLength);
	session->streamInitialState.swap(decompressed);
	session->streamInitialStateReceived = true;
	session->streamGameBufferCount++;
	MacadeLog("Macade GGPO: stream gamebuffer received raw=%u compressed=%u count=%d\n", rawLength, payloadSize - 4, session->streamGameBufferCount);
}

static void HandleTCPStreamFrameBatch(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL || payload == NULL || payloadSize < 8) return;
	unsigned int frameSize = ReadBE32(payload);
	unsigned int frameCount = ReadBE32(payload + 4);
	if (frameSize == 0 || frameSize > 256 || frameCount > 600 || payloadSize < 8 + frameSize * frameCount) return;
	if (session->inputSize == 0) session->inputSize = (int)frameSize;
	const unsigned char* frames = payload + 8;
	for (unsigned int i = 0; i < frameCount; i++) {
		const unsigned char* bytes = frames + i * frameSize;
		session->streamInputs.push_back(std::vector<unsigned char>(bytes, bytes + frameSize));
		session->streamReceiveFrame++;
	}
	session->streamFrameBatchCount++;
	if (ShouldLogCount(session->streamFrameBatchCount)) MacadeLog("Macade GGPO: stream frame batch received frameSize=%u count=%u queued=%zu batches=%d\n", frameSize, frameCount, session->streamInputs.size(), session->streamFrameBatchCount);
}

static void HandleTCPStreamSpectatorCount(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL || payload == NULL || payloadSize < 4) return;
	session->streamSpectatorCount = (int)ReadBE32(payload);
	MacadeEmitClientEvent(session, GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED, NULL, NULL, NULL, session->streamSpectatorCount);
}

void MacadeHandleTCPStreamRecord(GGPOSession* session, int code, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL) return;
	if (code == 3) MacadeHandleTCPMatchInfoRecord(session, payload, payloadSize);
	else if (code == -12) HandleTCPStreamGameBuffer(session, payload, payloadSize);
	else if (code == -13) HandleTCPStreamFrameBatch(session, payload, payloadSize);
	else if (code == -10) HandleTCPStreamSpectatorCount(session, payload, payloadSize);
}

bool MacadeLoadStreamingInitialState(GGPOSession* session, int timeoutMs)
{
	if (session == NULL) { MacadeLog("Macade GGPO: stream initial state unavailable; no session\n"); return false; }
	if (!session->isSpectator) { MacadeLog("Macade GGPO: stream initial state unavailable; session is not spectator\n"); return false; }
	if (session->callbacks.load_game_state == NULL) { MacadeLog("Macade GGPO: stream initial state unavailable; load callback missing\n"); return false; }
	MacadeLog("Macade GGPO: waiting for stream initial gamebuffer timeout=%d\n", timeoutMs);
	int elapsedMs = 0;
	while (!session->streamInitialStateReceived && elapsedMs < timeoutMs) {
		MacadePollTCP(session, 250);
		elapsedMs += 250;
	}
	if (!session->streamInitialStateReceived || session->streamInitialState.empty()) {
		MacadeLog("Macade GGPO: stream initial gamebuffer unavailable after %d ms\n", elapsedMs);
		return false;
	}
	if (session->streamInitialStateLoaded) return true;
	if (!session->callbacks.load_game_state(session->streamInitialState.data(), (int)session->streamInitialState.size())) {
		MacadeLog("Macade GGPO: stream initial state load failed len=%zu\n", session->streamInitialState.size());
		return false;
	}
	session->streamInitialStateLoaded = true;
	session->currentFrame = 0;
	MacadeLog("Macade GGPO: stream initial state loaded len=%zu queuedFrames=%zu\n", session->streamInitialState.size(), session->streamInputs.size());
	return true;
}
