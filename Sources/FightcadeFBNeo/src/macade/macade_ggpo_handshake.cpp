#include "macade_ggpo_session.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#include <string>
#include <vector>
#include <zlib.h>
extern int iDelay;
extern int iPlayer;
extern int iRanked;

static const int kUDPPort = 6006;
static const int kTCPPort = 6004;
static const int kRegisterValue = 6000;
static const int kPunchAttempts = 10;
static const int kTCPFrameBatchInterval = 60;
static const int kTCPSnapshotFirstBatch = 3;
static const int kTCPSnapshotIntervalBatches = 11;
static const char* kMasterHost = "ggpo.fightcade.com";

static void AppendBE32(std::vector<unsigned char>& out, unsigned int value)
{
	out.push_back((value >> 24) & 0xff); out.push_back((value >> 16) & 0xff);
	out.push_back((value >> 8) & 0xff); out.push_back(value & 0xff);
}

static void AppendString(std::vector<unsigned char>& out, const char* value)
{
	unsigned int length = value == NULL ? 0 : (unsigned int)strlen(value);
	AppendBE32(out, length); out.insert(out.end(), value, value + length);
}

static unsigned int ReadBE32(const unsigned char* data)
{
	return ((unsigned int)data[0] << 24) | ((unsigned int)data[1] << 16) | ((unsigned int)data[2] << 8) | (unsigned int)data[3];
}

static bool Resolve(const char* host, int port, int socktype, int protocol, sockaddr_in* out)
{
	addrinfo hints; memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET; hints.ai_socktype = socktype; hints.ai_protocol = protocol;
	addrinfo* result = NULL; char portText[16]; snprintf(portText, sizeof(portText), "%d", port);
	if (getaddrinfo(host, portText, &hints, &result) != 0 || result == NULL) return false;
	memcpy(out, result->ai_addr, sizeof(sockaddr_in)); freeaddrinfo(result); return true;
}

static bool SendAll(int fd, const unsigned char* bytes, size_t count)
{
	while (count > 0) {
		ssize_t sent = send(fd, bytes, count, 0);
		if (sent <= 0) return false;
		bytes += sent; count -= (size_t)sent;
	}
	return true;
}

static bool SendCommand(int fd, unsigned int sequence, unsigned int command, const std::vector<unsigned char>& payload)
{
	std::vector<unsigned char> header; AppendBE32(header, (unsigned int)payload.size() + 8);
	std::vector<unsigned char> body; AppendBE32(body, sequence); AppendBE32(body, command);
	body.insert(body.end(), payload.begin(), payload.end());
	return SendAll(fd, header.data(), header.size()) && SendAll(fd, body.data(), body.size());
}

static int ConnectTCP(int port)
{
	sockaddr_in remote;
	if (!Resolve(kMasterHost, port, SOCK_STREAM, IPPROTO_TCP, &remote)) return -1;
	int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd < 0) return -1;
	int noSigPipe = 1; setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE, &noSigPipe, sizeof(noSigPipe));
	sockaddr_in local; memset(&local, 0, sizeof(local));
	local.sin_family = AF_INET; local.sin_port = htons(kTCPPort); local.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(fd, (sockaddr*)&local, sizeof(local)) != 0) {
		MacadeLog("Macade GGPO: TCP local bind %d unavailable; using system assigned port\n", kTCPPort);
	}
	if (connect(fd, (sockaddr*)&remote, sizeof(remote)) != 0) { close(fd); return -1; }
	socklen_t localLen = sizeof(local);
	if (getsockname(fd, (sockaddr*)&local, &localLen) == 0) {
		MacadeLog("Macade GGPO: TCP connected local=%d remote=%d\n", ntohs(local.sin_port), port);
	}
	return fd;
}

static int BindUDP()
{
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (fd < 0) return -1;
	int yes = 1; setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(yes));
	sockaddr_in local; memset(&local, 0, sizeof(local));
	local.sin_family = AF_INET; local.sin_port = htons(kUDPPort); local.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(fd, (sockaddr*)&local, sizeof(local)) != 0) {
		MacadeLog("Macade GGPO: UDP local bind %d unavailable; using system assigned port\n", kUDPPort);
		local.sin_port = 0;
		if (bind(fd, (sockaddr*)&local, sizeof(local)) != 0) { close(fd); return -1; }
	}
	socklen_t localLen = sizeof(local);
	if (getsockname(fd, (sockaddr*)&local, &localLen) == 0) MacadeLog("Macade GGPO: UDP bound local=%d\n", ntohs(local.sin_port));
	return fd;
}

static bool RecvFrom(int fd, unsigned char* buffer, int capacity, sockaddr_in* from, int timeoutMs, int* count)
{
	fd_set readSet; FD_ZERO(&readSet); FD_SET(fd, &readSet);
	timeval tv; tv.tv_sec = timeoutMs / 1000; tv.tv_usec = (timeoutMs % 1000) * 1000;
	if (select(fd + 1, &readSet, NULL, NULL, &tv) <= 0) return false;
	socklen_t len = sizeof(*from); ssize_t received = recvfrom(fd, buffer, capacity, 0, (sockaddr*)from, &len);
	if (received <= 0) return false;
	*count = (int)received; return true;
}
static void SendUsePortsToMaster(int fd, const sockaddr_in* master, const char* quark)
{
	char payload[192]; snprintf(payload, sizeof(payload), "useports/%s", quark);
	sendto(fd, payload, strlen(payload), 0, (const sockaddr*)master, sizeof(*master));
	MacadeLog("Macade GGPO: UDP master fallback sent payload=%s\n", payload);
}

static bool MasterUDP(GGPOSession* session, const char* quark, int serverport)
{
	sockaddr_in master;
	if (!Resolve(kMasterHost, serverport, SOCK_DGRAM, IPPROTO_UDP, &master)) return false;
	char registration[192]; snprintf(registration, sizeof(registration), "%s/7001", quark);
	unsigned char buffer[1024]; sockaddr_in from; int count = 0;
	char expected[192]; snprintf(expected, sizeof(expected), "ok %s", quark);
	for (int attempt = 0; attempt < 2; attempt++) {
		sendto(session->udpFd, registration, strlen(registration), 0, (sockaddr*)&master, sizeof(master));
		MacadeLog("Macade GGPO: UDP master registration sent payload=%s attempt=%d\n", registration, attempt + 1);
		if (RecvFrom(session->udpFd, buffer, sizeof(buffer), &from, 10000, &count)) break;
	}
	if (count <= 0) { MacadeLog("Macade GGPO: UDP master ok timeout\n"); return false; }
	if (count != (int)strlen(expected) || memcmp(buffer, expected, count) != 0) return false;
	sendto(session->udpFd, "ok", 2, 0, (sockaddr*)&master, sizeof(master));
	MacadeLog("Macade GGPO: UDP master ok acknowledged\n");
	if (!RecvFrom(session->udpFd, buffer, sizeof(buffer), &from, 25000, &count)) { SendUsePortsToMaster(session->udpFd, &master, quark); session->openPortFallback = true; session->hasPeer = false; return true; }
	if (count >= 2 && buffer[0] == '0' && buffer[1] == '.') {
		session->peer = from;
		session->hasPeer = true;
		MacadeLog("Macade GGPO: UDP master peer from early token=%s:%d\n", inet_ntoa(session->peer.sin_addr), ntohs(session->peer.sin_port));
		return true;
	}
	if (count != 6) return false;
	memset(&session->peer, 0, sizeof(session->peer)); session->peer.sin_family = AF_INET;
	unsigned char* addr = (unsigned char*)&session->peer.sin_addr.s_addr;
	addr[0] = buffer[0]; addr[1] = buffer[1]; addr[2] = buffer[2]; addr[3] = buffer[3];
	session->peer.sin_port = htons((unsigned short)(buffer[4] | (buffer[5] << 8))); session->hasPeer = true;
	MacadeLog("Macade GGPO: UDP master peer=%s:%d\n", inet_ntoa(session->peer.sin_addr), ntohs(session->peer.sin_port));
	return true;
}

static int WrappedPort(int port) { return port < 1 ? 65535 + port : (port > 65535 ? port - 65535 : port); }

static void SendUDPControlReply(int fd, const sockaddr_in* to, const unsigned char* buffer, int count)
{
	if (fd < 0 || to == NULL || buffer == NULL || count < 5) return;
	unsigned char reply[6];
	if (buffer[0] == 1) {
		reply[0] = 2;
		memcpy(reply + 1, buffer + 1, 4);
		sendto(fd, reply, 5, 0, (const sockaddr*)to, sizeof(*to));
	} else if (buffer[0] == 4) {
		reply[0] = 5;
		if (count >= 6) memcpy(reply + 1, buffer + 2, 4);
		else memcpy(reply + 1, buffer + 1, 4);
		sendto(fd, reply, 5, 0, (const sockaddr*)to, sizeof(*to));
	}
}

static int RestrictedPort(const char* quark)
{
	const char* dash = strchr(quark, '-');
	if (dash == NULL) return 26004;
	const char* suffix = dash + 1;
	const char* dot = strchr(suffix, '.');
	if (dot == NULL || dot == suffix) return 26004;
	size_t suffixLength = (size_t)(dot - suffix);
	if (suffixLength > 14) return 26004;
	char portText[16];
	portText[0] = '4';
	memcpy(portText + 1, suffix, suffixLength);
	portText[suffixLength + 1] = 0;
	int port = atoi(portText);
	return port > 0 && port <= 65535 ? port : 26004;
}

static bool PunchWithSocket(GGPOSession* session, int fd, const char* label, int targetPort, int attempts, int sleepUs)
{
	char localToken[32]; snprintf(localToken, sizeof(localToken), "0.%u", (unsigned int)(arc4random_uniform(900000000) + 100000000));
	char remoteToken[64] = { 0 }; bool remoteKnowsLocalToken = false;
	unsigned char buffer[1024]; sockaddr_in from; int count = 0; sockaddr_in target = session->peer;
	target.sin_port = htons(WrappedPort(targetPort));
	if (attempts > 1) MacadeLog("Macade GGPO: UDP punch start label=%s target=%s:%d attempts=%d\n", label, inet_ntoa(target.sin_addr), ntohs(target.sin_port), attempts);
	for (int i = 0; i < attempts; i++) {
		if (remoteToken[0] && remoteKnowsLocalToken) { MacadeLog("Macade GGPO: UDP punch complete label=%s peer=%s:%d\n", label, inet_ntoa(session->peer.sin_addr), ntohs(session->peer.sin_port)); return true; }
		if (RecvFrom(fd, buffer, sizeof(buffer) - 1, &from, 0, &count)) {
			buffer[count] = 0;
			if (from.sin_addr.s_addr == target.sin_addr.s_addr && from.sin_port != target.sin_port && ntohs(from.sin_port) != 7000 && ntohs(from.sin_port) != 7001 && ntohs(from.sin_port) != 7002) target = from;
			if (count > 2 && buffer[0] == '0' && buffer[1] == '.') { sscanf((char*)buffer, "%63s", remoteToken); remoteKnowsLocalToken = strstr((char*)buffer, " ok") != NULL; session->peer = from; target = from; }
			else if (count >= 5 && buffer[0] <= 5) { session->peer = from; target = from; SendUDPControlReply(fd, &from, buffer, count); return true; }
		}
		char payload[128]; snprintf(payload, sizeof(payload), remoteToken[0] ? "%s %s ok" : "%s _", localToken, remoteToken);
		sendto(fd, payload, strlen(payload), 0, (sockaddr*)&target, sizeof(target));
		if (sleepUs > 0) usleep((useconds_t)sleepUs);
	}
	return remoteToken[0] != 0;
}

static bool ScanPeerPorts(GGPOSession* session, int fd, int basePort, int firstOffset, const char* label)
{
	for (int offset = firstOffset; offset <= 512; offset++) {
		if (offset == 0) {
			if (PunchWithSocket(session, fd, label, basePort, 1, 0)) return true;
			continue;
		}
		if (PunchWithSocket(session, fd, label, basePort + offset, 1, 0)) return true;
		if (PunchWithSocket(session, fd, label, basePort - offset, 1, 0)) return true;
	}
	return false;
}

static bool RebindAndPunch(GGPOSession* session, int bindPort, int targetPort, int scanPort, const char* label)
{
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (fd < 0) return false;
	sockaddr_in local; memset(&local, 0, sizeof(local));
	local.sin_family = AF_INET; local.sin_port = htons(bindPort); local.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(fd, (sockaddr*)&local, sizeof(local)) != 0) { MacadeLog("Macade GGPO: UDP punch unable to bind fallback port=%d\n", bindPort); close(fd); return false; }
	bool ok = PunchWithSocket(session, fd, label, targetPort, kPunchAttempts, 500000);
	if (!ok && scanPort > 0) {
		if (scanPort > 6005 && scanPort < 6009) ok = PunchWithSocket(session, fd, label, targetPort, 1024, 0);
		else ok = ScanPeerPorts(session, fd, scanPort, 0, label);
	}
	if (ok) { close(session->udpFd); session->udpFd = fd; return true; }
	close(fd); return false;
}

static bool HolePunch(GGPOSession* session, const char* quark)
{
	if (session == NULL || !session->hasPeer) return false;
	int basePort = ntohs(session->peer.sin_port);
	if (PunchWithSocket(session, session->udpFd, "initial", basePort, kPunchAttempts, 500000)) return true;
	if (ScanPeerPorts(session, session->udpFd, basePort, 1, "scan")) return true;
	if (RebindAndPunch(session, RestrictedPort(quark), RestrictedPort(quark), basePort, "restricted")) return true;
	if (RebindAndPunch(session, 6004, 6004, 0, "fixed6004")) return true;
	MacadeLog("Macade GGPO: UDP punch failed after all fallbacks\n"); return false;
}

static void ApplyTCPEndpointNotice(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL || payload == NULL || payloadSize < 12) return;
	unsigned int hostLength = ReadBE32(payload); if (hostLength == 0 || hostLength >= 256 || payloadSize < 4 + hostLength + 8) return;
	char host[256]; memcpy(host, payload + 4, hostLength); host[hostLength] = 0;
	unsigned int port = ReadBE32(payload + 4 + hostLength); unsigned int value2 = ReadBE32(payload + 8 + hostLength);
	bool loopback = strncmp(host, "127.", 4) == 0 || strcmp(host, "0.0.0.0") == 0 || strcmp(host, "localhost") == 0;
	MacadeLog("Macade GGPO: TCP endpoint notice host=%s value1=%u value2=%u fallback=%d\n", host, port, value2, session->openPortFallback ? 1 : 0);
	if (!session->openPortFallback || loopback || port == 0 || port > 65535) return;
	sockaddr_in peer; if (!Resolve(host, (int)port, SOCK_DGRAM, IPPROTO_UDP, &peer)) return;
	session->peer = peer; session->hasPeer = true;
	MacadeLog("Macade GGPO: open-port UDP peer set from TCP notice peer=%s:%d\n", inet_ntoa(session->peer.sin_addr), ntohs(session->peer.sin_port));
}
static void HandleTCPFrameBatch(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize)
{
	if (payloadSize < 8) return;
	unsigned int frameSize = ReadBE32(payload); unsigned int frameCount = ReadBE32(payload + 4);
	if (frameSize == 0 || frameSize > 64 || frameCount > 240 || payloadSize < 8 + frameSize * frameCount) return;
	if (session->inputSize == 0) session->inputSize = (int)frameSize;
	int frame = session->remoteLastFrame + 1;
	for (unsigned int i = 0; i < frameCount; i++, frame++) {
		const unsigned char* bytes = payload + 8 + i * frameSize;
		MacadeStoreRemoteInput(session, frame, std::vector<unsigned char>(bytes, bytes + frameSize));
	}
	MacadeLog("Macade GGPO: TCP frame batch received frameSize=%u count=%u last=%d\n", frameSize, frameCount, session->remoteLastFrame);
}

static void HandleTCPServerRecord(GGPOSession* session, int code, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL) return;
	if (session->isSpectator) {
		MacadeHandleTCPStreamRecord(session, code, payload, payloadSize);
		return;
	}
	if (code == -7) ApplyTCPEndpointNotice(session, payload, payloadSize);
	else if (code == -8) MacadeHandleTCPChatRecord(session, payload, payloadSize);
	else if (code == 3) MacadeHandleTCPMatchInfoRecord(session, payload, payloadSize);
	else if (code == 14) HandleTCPFrameBatch(session, payload, payloadSize);
}

static bool PayloadContains(const unsigned char* payload, unsigned int payloadSize, const char* needle)
{
	unsigned int needleSize = needle == NULL ? 0 : (unsigned int)strlen(needle);
	if (payload == NULL || needleSize == 0 || payloadSize < needleSize) return false;
	for (unsigned int offset = 0; offset <= payloadSize - needleSize; offset++) {
		if (memcmp(payload + offset, needle, needleSize) == 0) return true;
	}
	return false;
}

static bool MacadeWaitForTCPStartup(GGPOSession* session)
{
	if (session == NULL || session->tcpFd < 0) return false;
	std::vector<unsigned char>& tcpBuffer = session->tcpReceiveBuffer;
	int elapsedMs = 0;
	bool commandEcho = false;
	while (elapsedMs < 10000) {
		fd_set readSet; FD_ZERO(&readSet); FD_SET(session->tcpFd, &readSet);
		timeval tv; tv.tv_sec = 0; tv.tv_usec = 250000;
		int ready = select(session->tcpFd + 1, &readSet, NULL, NULL, &tv);
		elapsedMs += 250;
		if (ready < 0) { MacadeMarkDisconnected(session); return false; }
		if (ready == 0) continue;
		unsigned char buffer[4096]; ssize_t count = recv(session->tcpFd, buffer, sizeof(buffer), 0);
		if (count <= 0) { MacadeMarkDisconnected(session); return false; }
		session->bytesReceived += (unsigned long long)count;
		tcpBuffer.insert(tcpBuffer.end(), buffer, buffer + count);
		while (tcpBuffer.size() >= 8) {
			unsigned int length = ReadBE32(&tcpBuffer[0]);
			if (length < 4 || length > 1024 * 1024) { tcpBuffer.clear(); MacadeMarkDisconnected(session); return false; }
			if (tcpBuffer.size() < length + 4) break;
			int code = (int)(int32_t)ReadBE32(&tcpBuffer[4]);
			const unsigned char* payload = &tcpBuffer[8];
			unsigned int payloadSize = length - 4;
			MacadeLog("Macade GGPO: TCP startup record code=%d payload=%u\n", code, payloadSize);
			if (code == -7) ApplyTCPEndpointNotice(session, payload, payloadSize);
			if (code == 3) MacadeHandleTCPMatchInfoRecord(session, payload, payloadSize);
			if (code == 14) HandleTCPFrameBatch(session, payload, payloadSize);
			if (code == -8 && PayloadContains(payload, payloadSize, "Command")) {
				MacadeLog("Macade GGPO: TCP startup command echo received\n");
				commandEcho = true;
			}
			if (commandEcho && (!session->openPortFallback || session->hasPeer)) {
				tcpBuffer.erase(tcpBuffer.begin(), tcpBuffer.begin() + length + 4);
				return true;
			}
			tcpBuffer.erase(tcpBuffer.begin(), tcpBuffer.begin() + length + 4);
		}
	}
	MacadeLog(commandEcho ? "Macade GGPO: TCP startup open-port peer timeout\n" : "Macade GGPO: TCP startup command echo timeout\n");
	return false;
}

static bool ShouldLogCount(int count) { return count < 8 || count % 120 == 0; }

void MacadePollTCP(GGPOSession* session, int timeoutMs)
{
	if (session == NULL || session->tcpFd < 0) return;
	fd_set readSet; FD_ZERO(&readSet); FD_SET(session->tcpFd, &readSet);
	timeval tv; tv.tv_sec = timeoutMs / 1000; tv.tv_usec = (timeoutMs % 1000) * 1000;
	int ready = select(session->tcpFd + 1, &readSet, NULL, NULL, &tv);
	if (ready < 0) { MacadeMarkDisconnected(session); return; }
	if (ready == 0) return;
	unsigned char buffer[4096]; ssize_t count = recv(session->tcpFd, buffer, sizeof(buffer), 0);
	if (count <= 0) { MacadeLog("Macade GGPO: TCP recv closed count=%zd spectator=%d\n", count, session->isSpectator ? 1 : 0); MacadeMarkDisconnected(session); return; }
	session->bytesReceived += (unsigned long long)count;
	std::vector<unsigned char>& tcpBuffer = session->tcpReceiveBuffer;
	tcpBuffer.insert(tcpBuffer.end(), buffer, buffer + count);
	while (tcpBuffer.size() >= 8) {
		unsigned int length = ReadBE32(&tcpBuffer[0]);
		if (length < 4 || length > 1024 * 1024) { MacadeLog("Macade GGPO: TCP invalid record length=%u buffered=%zu\n", length, tcpBuffer.size()); tcpBuffer.clear(); MacadeMarkDisconnected(session); return; }
		if (tcpBuffer.size() < length + 4) return;
		int code = (int)(int32_t)ReadBE32(&tcpBuffer[4]);
		if (ShouldLogCount(session->tcpRecordLogCount)) MacadeLog("Macade GGPO: TCP server record code=%d payload=%u\n", code, length - 4);
		if (session->isSpectator && !session->streamTcpStarted && code == 1 && length >= 8 && ReadBE32(&tcpBuffer[8]) == 0 && session->quarkId[0] != 0) { std::vector<unsigned char> payload; AppendString(payload, session->quarkId); bool ok20 = SendCommand(session->tcpFd, session->tcpSequence++, 20, payload); payload.clear(); AppendString(payload, session->quarkId); bool ok12 = SendCommand(session->tcpFd, session->tcpSequence++, 12, payload); session->streamTcpStarted = ok20 && ok12; MacadeLog("Macade GGPO: stream TCP registration sent after command0 ack quark=%s commands=20,12 ok20=%d ok12=%d\n", session->quarkId, ok20 ? 1 : 0, ok12 ? 1 : 0); if (!session->streamTcpStarted) MacadeMarkDisconnected(session); }
		HandleTCPServerRecord(session, code, &tcpBuffer[8], length - 4);
		session->tcpRecordLogCount++;
		tcpBuffer.erase(tcpBuffer.begin(), tcpBuffer.begin() + length + 4);
	}
}

static void MacadeFreeSavedState(GGPOSession* session, unsigned char* state)
{
	if (state == NULL) return;
	if (session != NULL && session->callbacks.free_buffer != NULL) session->callbacks.free_buffer(state);
	else free(state);
}

static void MacadeSendTCPSnapshot(GGPOSession* session)
{
	if (session == NULL || session->tcpFd < 0 || session->callbacks.save_game_state == NULL || session->quarkId[0] == 0) return;
	unsigned char* state = NULL;
	int stateLength = 0;
	int checksum = 0;
	session->callbacks.save_game_state(&state, &stateLength, &checksum, session->currentFrame);
	if (state == NULL || stateLength <= 0) {
		MacadeFreeSavedState(session, state);
		return;
	}
	uLongf compressedLength = compressBound((uLong)stateLength);
	std::vector<unsigned char> compressed((size_t)compressedLength);
	int result = compress2(compressed.data(), &compressedLength, state, (uLong)stateLength, Z_BEST_SPEED);
	MacadeFreeSavedState(session, state);
	if (result != Z_OK) return;
	compressed.resize((size_t)compressedLength);

	std::vector<unsigned char> payload;
	AppendString(payload, session->quarkId);
	AppendBE32(payload, (unsigned int)compressedLength);
	AppendBE32(payload, (unsigned int)stateLength);
	payload.insert(payload.end(), compressed.begin(), compressed.end());
	if (SendCommand(session->tcpFd, session->tcpSequence++, 18, payload)) {
		session->bytesSent += (unsigned long long)payload.size() + 12ULL;
		session->tcpSnapshotSendCount++;
		session->tcpLastSnapshotBatch = session->tcpBatchSendCount;
		MacadeLog("Macade GGPO: TCP snapshot sent compressed=%lu raw=%d count=%d\n", (unsigned long)compressedLength, stateLength, session->tcpSnapshotSendCount);
	}
}

void MacadeSendTCPFrameBatch(GGPOSession* session)
{
	if (session == NULL || session->tcpFd < 0 || session->inputSize <= 0 || session->quarkId[0] == 0 || session->localSendHighFrame < 0) return;
	if (session->currentFrame - session->tcpLastBatchFrame < kTCPFrameBatchInterval) return;
	const int frameCount = 60;
	std::vector<unsigned char> payload;
	AppendString(payload, session->quarkId); AppendBE32(payload, frameCount); AppendBE32(payload, (unsigned int)session->inputSize);
	std::vector<unsigned char> empty(session->inputSize, 0);
	std::vector<unsigned char> previous = empty;
	int firstFrame = session->localSendHighFrame - frameCount + 1;
	for (int frame = firstFrame; frame <= session->localSendHighFrame; frame++) {
		std::map<int, std::vector<unsigned char> >::iterator input = session->localInputs.find(frame);
		const std::vector<unsigned char>& bytes = input == session->localInputs.end() ? previous : input->second;
		payload.insert(payload.end(), bytes.begin(), bytes.begin() + session->inputSize);
		previous = bytes;
	}
	if (SendCommand(session->tcpFd, session->tcpSequence++, 17, payload)) {
		session->bytesSent += (unsigned long long)payload.size() + 12ULL;
		session->tcpLastBatchFrame = session->currentFrame;
		session->tcpBatchSendCount++;
		if (ShouldLogCount(session->tcpBatchLogCount)) MacadeLog("Macade GGPO: TCP frame batch sent frame=%d count=%d\n", session->currentFrame, session->tcpBatchSendCount);
		session->tcpBatchLogCount++;
		bool needsSnapshot = session->tcpBatchSendCount >= kTCPSnapshotFirstBatch &&
			(session->tcpSnapshotSendCount == 0 || session->tcpBatchSendCount - session->tcpLastSnapshotBatch >= kTCPSnapshotIntervalBatches);
		if (needsSnapshot) MacadeSendTCPSnapshot(session);
	}
}

static void StartTCP(GGPOSession* session, const char* quark)
{
	int fd = session == NULL ? -1 : session->tcpFd;
	if (fd < 0) return;
	std::vector<unsigned char> payload;
	AppendBE32(payload, 0); AppendBE32(payload, 29); AppendBE32(payload, 1); SendCommand(fd, 1, 0, payload);
	payload.clear(); AppendString(payload, quark); AppendBE32(payload, kRegisterValue); SendCommand(fd, 2, 11, payload);
	payload.clear(); AppendString(payload, quark); SendCommand(fd, 3, 12, payload);
	payload.clear(); AppendString(payload, quark); AppendString(payload, "V14"); SendCommand(fd, 4, 15, payload);
	payload.clear(); AppendString(payload, quark); AppendBE32(payload, 60); AppendBE32(payload, 10); payload.insert(payload.end(), 60 * 10, 0); SendCommand(fd, 5, 17, payload);
	char ready[64]; snprintf(ready, sizeof(ready), "C2,%d,%d,%d", iPlayer, iDelay, iRanked);
	payload.clear(); AppendString(payload, quark); AppendString(payload, ready); SendCommand(fd, 6, 15, payload);
	session->tcpSequence = 7;
	MacadeLog("Macade GGPO: served TCP startup sent quark=%s ready=%s\n", quark, ready);
}
bool MacadeStartStreamingTCPIfNeeded(GGPOSession* session)
{
	if (session == NULL || !session->isSpectator || session->streamStartupSent) return true;
	if (session->tcpFd < 0) return false;
	std::vector<unsigned char> payload;
	AppendBE32(payload, 0); AppendBE32(payload, 29); AppendBE32(payload, 1); bool ok = SendCommand(session->tcpFd, 1, 0, payload);
	session->tcpSequence = 2;
	session->streamStartupSent = ok;
	MacadeLog("Macade GGPO: stream TCP startup sent from idle quark=%s commands=0 ok=%d\n", session->quarkId, ok ? 1 : 0);
	return ok;
}
bool MacadeEstablishServedSession(GGPOSession* session, const char* quark, int serverport)
{
	strncpy(session->quarkId, quark, sizeof(session->quarkId) - 1);
	session->udpFd = BindUDP();
	if (session->udpFd < 0) return false;
	if (!MasterUDP(session, quark, serverport)) return false;
	if (session->hasPeer && !HolePunch(session, quark)) {
		sockaddr_in master;
		if (Resolve(kMasterHost, serverport, SOCK_DGRAM, IPPROTO_UDP, &master)) SendUsePortsToMaster(session->udpFd, &master, quark);
		session->openPortFallback = true;
		session->hasPeer = false;
		MacadeLog("Macade GGPO: UDP punch failed; continuing with open-port fallback\n");
	}
	session->tcpFd = ConnectTCP(serverport);
	if (session->tcpFd < 0) { MacadeLog("Macade GGPO: TCP connect failed after UDP punch\n"); return false; }
	StartTCP(session, quark);
	if (!MacadeWaitForTCPStartup(session)) return false;
	return true;
}

bool MacadeEstablishStreamingSession(GGPOSession* session, const char* quark, int serverport)
{
	if (session == NULL || quark == NULL || quark[0] == 0) return false;
	strncpy(session->quarkId, quark, sizeof(session->quarkId) - 1);
	session->isSpectator = true;
	session->tcpFd = ConnectTCP(serverport);
	if (session->tcpFd < 0) {
		MacadeLog("Macade GGPO: stream TCP connect failed port=%d\n", serverport);
		return false;
	}
	MacadeLog("Macade GGPO: stream TCP connected; startup deferred until idle quark=%s\n", quark);
	return true;
}
