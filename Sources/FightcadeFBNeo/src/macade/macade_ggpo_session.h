#pragma once

#include <netinet/in.h>
#include <deque>
#include <map>
#include <vector>

#include "ggpomac.h"

struct MacadeSavedFrame {
	int frame = -1;
	int checksum = 0;
	std::vector<unsigned char> bytes;
};

struct GGPOSession {
	int udpFd = -1;
	int tcpFd = -1;
	sockaddr_in peer{};
	bool hasPeer = false;
	bool openPortFallback = false;
	bool isSpectator = false;
	bool streamStartupSent = false;
	bool streamTcpStarted = false;
	bool streamInitialStateReceived = false;
	bool streamInitialStateLoaded = false;
	char quarkId[128] = { 0 };
	int playerIndex = 0;
	int delay = 0;
	int inputSize = 0;
	int currentFrame = 0;
	int remoteLastFrame = -1;
	int localAckFrame = -1;
	int localSendHighFrame = -1;
	int lastLocalQueuedFrame = -1;
	unsigned int tcpSequence = 6;
	int tcpRecordLogCount = 0;
	int tcpBatchLogCount = 0;
	int tcpLastBatchFrame = -60;
	int tcpBatchSendCount = 0;
	int tcpSnapshotSendCount = 0;
	int tcpLastSnapshotBatch = 0;
	bool tcpReadySent = false;
	int remoteTimeoutCount = 0;
	int udpInputSendCount = 0;
	int udpInputReceiveCount = 0;
	int udpSyncSendCount = 0;
	int udpSyncReplyReceiveCount = 0;
	int udpQualitySendCount = 0;
	int udpQualityReplyReceiveCount = 0;
	int udpControlReplySendCount = 0;
	int udpPingMs = 0;
	int localFrameAdvantage = 0;
	int remoteFrameAdvantage = 0;
	int maxPredictionFrames = 8;
	int predictionCount = 0;
	int predictionMismatchCount = 0;
	int rollbackRequestedFrame = -1;
	int rollbackCount = 0;
	int rollbackReplayFrameCount = 0;
	int savedStateCount = 0;
	int maxSavedFrames = 180;
	int maxInputHistoryFrames = 600;
	int streamReceiveFrame = 0;
	int streamFrameReadCount = 0;
	int streamFrameBatchCount = 0;
	int streamGameBufferCount = 0;
	int streamSpectatorCount = 0;
	unsigned int udpSyncNonce = 0;
	unsigned int udpQualityNonce = 0;
	long long udpSyncSentAtMs = 0;
	long long udpQualitySentAtMs = 0;
	long long udpLastSendAtMs = 0;
	long long udpLastInputSendAtMs = 0;
	long long udpLastReceiveAtMs = 0;
	long long udpLastInputReceiveAtMs = 0;
	long long udpLastInterruptLogAtMs = 0;
	bool replaying = false;
	bool fatalDesync = false;
	bool networkInterrupted = false;
	bool networkDisconnected = false;
	bool clientDisconnectEventSent = false;
	unsigned long long bytesSent = 0;
	unsigned long long bytesReceived = 0;
	long long startedAtMs = 0;
	char streamPlayer1[256] = { 0 };
	char streamPlayer2[256] = { 0 };
	char streamBlurb[256] = { 0 };
	char gameName[64] = { 0 };
	char replayPlayerAvatar[2][256] = {{ 0 }};
	int replayScores[2] = { 0, 0 };
	int replayWinner = -1;
	bool replayArmed = false;
	bool replayUploaded = false;
	std::vector<unsigned char> replayInitialState;
	std::vector<std::vector<unsigned char> > replayInputs;
	GGPOSessionCallbacks callbacks{};
	std::map<int, std::vector<unsigned char> > localInputs;
	std::map<int, std::vector<unsigned char> > remoteInputs;
	std::map<int, std::vector<unsigned char> > predictedRemoteInputs;
	std::map<int, MacadeSavedFrame> savedFrames;
	std::vector<unsigned char> tcpReceiveBuffer;
	std::vector<unsigned char> streamInitialState;
	std::deque<std::vector<unsigned char> > streamInputs;
	std::vector<unsigned char> lastLocalInput;
	std::vector<unsigned char> lastRemoteInput;
};

void MacadeLog(const char* format, ...);
void MacadeEmitClientEvent(GGPOSession* session, GGPOClientEventCode code, const char* p1, const char* p2, const char* blurb, int count);
void MacadeEmitChatEvent(GGPOSession* session, const char* username, const char* text);
void MacadeMarkDisconnected(GGPOSession* session);
bool MacadeSaveCurrentFrame(GGPOSession* session);
bool MacadeRunRollbackIfNeeded(GGPOSession* session);
bool MacadeStoreRemoteInput(GGPOSession* session, int frame, const std::vector<unsigned char>& input);
bool MacadeEstablishServedSession(GGPOSession* session, const char* quark, int serverport);
bool MacadeEstablishDirectSession(GGPOSession* session, int localport, const char* remoteip, int remoteport);
bool MacadeEstablishStreamingSession(GGPOSession* session, const char* quark, int serverport);
bool MacadeStartStreamingTCPIfNeeded(GGPOSession* session);
void MacadeHandleTCPStreamRecord(GGPOSession* session, int code, const unsigned char* payload, unsigned int payloadSize);
void MacadeHandleTCPChatRecord(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize);
bool MacadeHandleTCPMatchInfoRecord(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize);
bool MacadeLoadStreamingInitialState(GGPOSession* session, int timeoutMs);
void MacadePollTCP(GGPOSession* session, int timeoutMs);
bool MacadeSendTCPChat(GGPOSession* session, const char* text);
bool MacadeHandleGameEvent(GGPOSession* session, GGPOClientGameEventType type, void* data);
void MacadeReplayRecordInput(GGPOSession* session, const unsigned char* bytes, int size);
void MacadeSendTCPReadyIfNeeded(GGPOSession* session);
void MacadeSendTCPFrameBatch(GGPOSession* session);
bool MacadePollUDP(GGPOSession* session, int timeoutMs);
void MacadeSendUDPInput(GGPOSession* session, const unsigned char* bytes, int size, int frame);
void MacadePumpUDPControl(GGPOSession* session);
int MacadeNetworkReplayFrame();
