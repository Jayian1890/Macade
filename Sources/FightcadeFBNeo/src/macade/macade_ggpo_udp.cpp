#include "macade_ggpo_session.h"

#include <arpa/inet.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>

static const long long kUDPQualityIntervalMs = 1000;
static const long long kUDPSyncIntervalMs = 2000;
static const long long kUDPResendIntervalMs = 200;
static const long long kUDPInterruptNotifyMs = 5000;
static const long long kUDPDisconnectTimeoutMs = 30000;

static long long MacadeUDPMilliseconds()
{
	timeval tv;
	gettimeofday(&tv, NULL);
	return (long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL;
}

static void WriteLE32(unsigned char* out, int value)
{
	out[0] = value & 0xff;
	out[1] = (value >> 8) & 0xff;
	out[2] = (value >> 16) & 0xff;
	out[3] = (value >> 24) & 0xff;
}

static int ReadLE32(const unsigned char* in)
{
	return (int)in[0] | ((int)in[1] << 8) | ((int)in[2] << 16) | ((int)in[3] << 24);
}

static void WriteLE16(unsigned char* out, int value)
{
	out[0] = value & 0xff;
	out[1] = (value >> 8) & 0xff;
}

static int ReadLE16(const unsigned char* in)
{
	return (int)in[0] | ((int)in[1] << 8);
}

static bool InputBit(const unsigned char* bytes, int bit)
{
	return (bytes[bit / 8] & (1 << (bit % 8))) != 0;
}

static void SetInputBit(std::vector<unsigned char>& bytes, int bit, bool value)
{
	if (value) bytes[bit / 8] |= 1 << (bit % 8);
	else bytes[bit / 8] &= ~(1 << (bit % 8));
}

static void WriteCompressedBit(unsigned char* payload, int* bitCount, bool value)
{
	if (value) payload[*bitCount / 8] |= 1 << (*bitCount % 8);
	(*bitCount)++;
}

static bool ReadCompressedBit(const unsigned char* payload, int bitCount, int* bitOffset, bool* value)
{
	if (*bitOffset >= bitCount) return false;
	*value = (payload[*bitOffset / 8] & (1 << (*bitOffset % 8))) != 0;
	(*bitOffset)++;
	return true;
}

static bool WriteFrameInputDelta(unsigned char* packet, int packetBytes, int* bitCount, const std::vector<unsigned char>& previous, const std::vector<unsigned char>& current, int size)
{
	for (int bit = 0; bit < size * 8; bit++) {
		bool oldValue = InputBit(previous.data(), bit);
		bool newValue = InputBit(current.data(), bit);
		if (oldValue == newValue) continue;
		if (*bitCount + 10 > (packetBytes - 12) * 8) return false;
		WriteCompressedBit(packet + 12, bitCount, true);
		WriteCompressedBit(packet + 12, bitCount, newValue);
		for (int indexBit = 0; indexBit < 8; indexBit++) WriteCompressedBit(packet + 12, bitCount, (bit & (1 << indexBit)) != 0);
	}
	if (*bitCount + 1 > (packetBytes - 12) * 8) return false;
	WriteCompressedBit(packet + 12, bitCount, false);
	return true;
}

static void NoteUDPSend(GGPOSession* session, ssize_t sent)
{
	if (session == NULL || sent <= 0) return;
	session->udpLastSendAtMs = MacadeUDPMilliseconds();
	session->bytesSent += (unsigned long long)sent;
}

static void SendUDPControlReply(GGPOSession* session, const sockaddr_in* to, const unsigned char* buffer, int count)
{
	if (session == NULL || session->udpFd < 0 || to == NULL || buffer == NULL || count < 5) return;
	unsigned char reply[6];
	ssize_t sent = 0;
	if (buffer[0] == 1) {
		reply[0] = 2;
		memcpy(reply + 1, buffer + 1, 4);
		sent = sendto(session->udpFd, reply, 5, 0, (const sockaddr*)to, sizeof(*to));
	} else if (buffer[0] == 4) {
		reply[0] = 5;
		if (count >= 6) memcpy(reply + 1, buffer + 2, 4);
		else memcpy(reply + 1, buffer + 1, 4);
		sent = sendto(session->udpFd, reply, 5, 0, (const sockaddr*)to, sizeof(*to));
	}
	if (sent > 0) { session->udpControlReplySendCount++; NoteUDPSend(session, sent); }
}

static void SendUDPSyncProbe(GGPOSession* session, long long now)
{
	if (session == NULL || session->udpFd < 0 || !session->hasPeer) return;
	unsigned char packet[5];
	packet[0] = 1;
	session->udpSyncNonce = arc4random();
	if (session->udpSyncNonce == 0) session->udpSyncNonce = (unsigned int)now;
	WriteLE32(packet + 1, (int)session->udpSyncNonce);
	ssize_t sent = sendto(session->udpFd, packet, sizeof(packet), 0, (sockaddr*)&session->peer, sizeof(session->peer));
	if (sent > 0) {
		session->udpSyncSendCount++;
		session->udpSyncSentAtMs = now;
		NoteUDPSend(session, sent);
	}
}

static void SendUDPQualityReport(GGPOSession* session, long long now)
{
	if (session == NULL || session->udpFd < 0 || !session->hasPeer) return;
	unsigned char packet[6];
	packet[0] = 4;
	int advantage = session->currentFrame - session->remoteLastFrame;
	if (advantage < -128) advantage = -128;
	if (advantage > 127) advantage = 127;
	session->localFrameAdvantage = advantage;
	packet[1] = (unsigned char)(int8_t)advantage;
	session->udpQualityNonce = arc4random();
	if (session->udpQualityNonce == 0) session->udpQualityNonce = (unsigned int)now;
	WriteLE32(packet + 2, (int)session->udpQualityNonce);
	ssize_t sent = sendto(session->udpFd, packet, sizeof(packet), 0, (sockaddr*)&session->peer, sizeof(session->peer));
	if (sent > 0) {
		session->udpQualitySendCount++;
		session->udpQualitySentAtMs = now;
		NoteUDPSend(session, sent);
	}
}

void MacadePumpUDPControl(GGPOSession* session)
{
	if (session == NULL || session->udpFd < 0 || !session->hasPeer || session->networkDisconnected) return;
	long long now = MacadeUDPMilliseconds();
	if (session->udpSyncSentAtMs == 0 || now - session->udpSyncSentAtMs >= kUDPSyncIntervalMs) SendUDPSyncProbe(session, now);
	if (session->udpQualitySentAtMs == 0 || now - session->udpQualitySentAtMs >= kUDPQualityIntervalMs) SendUDPQualityReport(session, now);
	if (session->inputSize > 0 && session->localSendHighFrame > session->localAckFrame && session->udpLastInputSendAtMs > 0 && now - session->udpLastInputSendAtMs >= kUDPResendIntervalMs) {
		const unsigned char* fallback = session->lastLocalInput.empty() ? NULL : session->lastLocalInput.data();
		if (fallback != NULL) MacadeSendUDPInput(session, fallback, session->inputSize, session->localSendHighFrame);
	}
	if (session->udpLastReceiveAtMs > 0 && now - session->udpLastReceiveAtMs >= kUDPInterruptNotifyMs && !session->networkInterrupted) {
		session->networkInterrupted = true;
		session->udpLastInterruptLogAtMs = now;
		MacadeLog("Macade GGPO: UDP peer silent for %lld ms; waiting before disconnect\n", now - session->udpLastReceiveAtMs);
	}
	if (session->udpLastReceiveAtMs > 0 && now - session->udpLastReceiveAtMs >= kUDPDisconnectTimeoutMs) {
		MacadeMarkDisconnected(session);
		MacadeLog("Macade GGPO: UDP peer timed out after %lld ms\n", now - session->udpLastReceiveAtMs);
	}
}

void MacadeSendUDPInput(GGPOSession* session, const unsigned char* bytes, int size, int frame)
{
	if (session == NULL || session->udpFd < 0 || !session->hasPeer || bytes == NULL || size <= 0 || frame < 0) return;
	int startFrame = session->localAckFrame + 1;
	if (startFrame < 0) startFrame = 0;
	if (startFrame > frame) startFrame = frame;
	while (startFrame <= frame) {
		unsigned char packet[256];
		memset(packet, 0, sizeof(packet));
		std::vector<unsigned char> previous(size, 0);
		if (startFrame > 0) {
			std::map<int, std::vector<unsigned char> >::iterator prior = session->localInputs.find(startFrame - 1);
			if (prior != session->localInputs.end() && prior->second.size() == (size_t)size) previous = prior->second;
		}
		packet[0] = 3;
		WriteLE32(packet + 1, startFrame);
		WriteLE32(packet + 5, session->remoteLastFrame);
		packet[11] = (unsigned char)size;
		int bitCount = 0;
		int packetStart = startFrame;
		int inputFrame = startFrame;
		for (; inputFrame <= frame; inputFrame++) {
			std::map<int, std::vector<unsigned char> >::iterator input = session->localInputs.find(inputFrame);
			std::vector<unsigned char> current = previous;
			if (input != session->localInputs.end() && input->second.size() == (size_t)size) current = input->second;
			int beforeBits = bitCount;
			if (!WriteFrameInputDelta(packet, sizeof(packet), &bitCount, previous, current, size)) {
				bitCount = beforeBits;
				break;
			}
			previous = current;
			if (inputFrame - packetStart >= 31) { inputFrame++; break; }
		}
		if (bitCount <= 0 || inputFrame == packetStart) return;
		WriteLE16(packet + 9, bitCount);
		int count = 12 + ((bitCount + 7) / 8);
		if (count > (int)sizeof(packet)) return;
		ssize_t sent = sendto(session->udpFd, packet, count, 0, (sockaddr*)&session->peer, sizeof(session->peer));
		if (sent > 0) { session->udpInputSendCount++; session->udpLastInputSendAtMs = MacadeUDPMilliseconds(); NoteUDPSend(session, sent); }
		startFrame = inputFrame;
	}
}

bool MacadePollUDP(GGPOSession* session, int timeoutMs)
{
	if (session == NULL || session->udpFd < 0) return false;
	MacadePumpUDPControl(session);
	bool handled = false;
	int waitMs = timeoutMs;
	while (true) {
		fd_set readSet; FD_ZERO(&readSet); FD_SET(session->udpFd, &readSet);
		timeval tv; tv.tv_sec = waitMs / 1000; tv.tv_usec = (waitMs % 1000) * 1000;
		if (select(session->udpFd + 1, &readSet, NULL, NULL, &tv) <= 0) return handled;
		waitMs = 0;
		unsigned char buffer[1024]; sockaddr_in from; socklen_t fromLen = sizeof(from);
		ssize_t count = recvfrom(session->udpFd, buffer, sizeof(buffer), 0, (sockaddr*)&from, &fromLen);
		if (count <= 0) return handled;
		session->bytesReceived += (unsigned long long)count;
		session->udpLastReceiveAtMs = MacadeUDPMilliseconds();
		if (session->networkInterrupted) {
			session->networkInterrupted = false;
			MacadeLog("Macade GGPO: UDP peer resumed after interruption\n");
		}
		if (count > 2 && buffer[0] == '0' && buffer[1] == '.') {
			session->peer = from;
			session->hasPeer = true;
			handled = true;
			continue;
		}
		if (count >= 5 && (buffer[0] == 1 || buffer[0] == 4)) {
			if (buffer[0] == 4 && count >= 2) session->remoteFrameAdvantage = (int)(int8_t)buffer[1];
			SendUDPControlReply(session, &from, buffer, (int)count);
			handled = true;
			continue;
		}
		if (count >= 5 && buffer[0] == 2) {
			unsigned int nonce = (unsigned int)ReadLE32(buffer + 1);
			if (nonce == session->udpSyncNonce && session->udpSyncSentAtMs > 0) {
				session->udpPingMs = (int)(MacadeUDPMilliseconds() - session->udpSyncSentAtMs);
				session->udpSyncReplyReceiveCount++;
			}
			handled = true;
			continue;
		}
		if (count >= 5 && buffer[0] == 5) {
			unsigned int nonce = (unsigned int)ReadLE32(buffer + 1);
			if (nonce == session->udpQualityNonce && session->udpQualitySentAtMs > 0) {
				session->udpPingMs = (int)(MacadeUDPMilliseconds() - session->udpQualitySentAtMs);
				session->udpQualityReplyReceiveCount++;
			}
			handled = true;
			continue;
		}
		if (count >= 12 && buffer[0] == 3) {
			session->udpInputReceiveCount++;
			session->udpLastInputReceiveAtMs = session->udpLastReceiveAtMs;
			int startFrame = ReadLE32(buffer + 1);
			int ackFrame = ReadLE32(buffer + 5);
			int bitCount = ReadLE16(buffer + 9);
			int inputBytes = buffer[11];
			int payloadBytes = (bitCount + 7) / 8;
			if (inputBytes > 0 && inputBytes <= 64 && count >= 12 + payloadBytes) {
				if (ackFrame > session->localAckFrame) session->localAckFrame = ackFrame;
				if (session->lastRemoteInput.size() != (size_t)inputBytes) session->lastRemoteInput.assign(inputBytes, 0);
				if (startFrame > 0 && session->remoteInputs.find(startFrame - 1) == session->remoteInputs.end() && startFrame != session->remoteLastFrame + 1) {
					MacadeLog("Macade GGPO: UDP input batch missing base frame start=%d remoteLast=%d; waiting for resend\n", startFrame, session->remoteLastFrame);
					continue;
				}
				int bitOffset = 0;
				int frame = startFrame;
				std::vector<unsigned char> previous(inputBytes, 0);
				if (startFrame > 0) {
					std::map<int, std::vector<unsigned char> >::iterator prior = session->remoteInputs.find(startFrame - 1);
					if (prior != session->remoteInputs.end() && prior->second.size() == (size_t)inputBytes) previous = prior->second;
					else if (startFrame == session->remoteLastFrame + 1) previous = session->lastRemoteInput;
				}
				while (bitOffset < bitCount) {
					std::vector<unsigned char> current = previous;
					while (bitOffset < bitCount) {
						bool changed = false;
						if (!ReadCompressedBit(buffer + 12, bitCount, &bitOffset, &changed)) break;
						if (!changed) break;
						bool value = false;
						if (!ReadCompressedBit(buffer + 12, bitCount, &bitOffset, &value)) break;
						int index = 0;
						for (int indexBit = 0; indexBit < 8; indexBit++) {
							bool indexValue = false;
							if (ReadCompressedBit(buffer + 12, bitCount, &bitOffset, &indexValue) && indexValue) index |= 1 << indexBit;
						}
						if (index >= 0 && index < inputBytes * 8) SetInputBit(current, index, value);
					}
					MacadeStoreRemoteInput(session, frame, current);
					previous = current;
					frame++;
				}
				handled = true;
			}
		}
	}
}
