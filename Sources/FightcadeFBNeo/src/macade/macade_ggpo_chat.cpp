#include "macade_ggpo_session.h"

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <vector>

static unsigned int ReadBE32(const unsigned char* data)
{
	return ((unsigned int)data[0] << 24) | ((unsigned int)data[1] << 16) | ((unsigned int)data[2] << 8) | (unsigned int)data[3];
}

static void AppendBE32(std::vector<unsigned char>& out, unsigned int value)
{
	out.push_back((value >> 24) & 0xff);
	out.push_back((value >> 16) & 0xff);
	out.push_back((value >> 8) & 0xff);
	out.push_back(value & 0xff);
}

static void AppendString(std::vector<unsigned char>& out, const char* value)
{
	unsigned int length = value == NULL ? 0 : (unsigned int)strlen(value);
	AppendBE32(out, length);
	out.insert(out.end(), value, value + length);
}

static bool SendAll(int fd, const unsigned char* bytes, size_t count)
{
	while (count > 0) {
		ssize_t sent = send(fd, bytes, count, 0);
		if (sent <= 0) return false;
		bytes += sent;
		count -= (size_t)sent;
	}
	return true;
}

static bool SendCommand(GGPOSession* session, unsigned int command, const std::vector<unsigned char>& payload)
{
	std::vector<unsigned char> header;
	AppendBE32(header, (unsigned int)payload.size() + 8);
	std::vector<unsigned char> body;
	AppendBE32(body, session->tcpSequence++);
	AppendBE32(body, command);
	body.insert(body.end(), payload.begin(), payload.end());
	if (!SendAll(session->tcpFd, header.data(), header.size()) || !SendAll(session->tcpFd, body.data(), body.size())) return false;
	session->bytesSent += (unsigned long long)(header.size() + body.size());
	return true;
}

static void CopyPlayerName(char* out, size_t outSize, const char* value)
{
	if (out == NULL || outSize == 0) return;
	const char* fallback = "You";
	if (value == NULL || value[0] == 0) {
		snprintf(out, outSize, "%s", fallback);
		return;
	}
	const char* end = strchr(value, '#');
	size_t length = end == NULL ? strlen(value) : (size_t)(end - value);
	if (length == 0) {
		snprintf(out, outSize, "%s", fallback);
		return;
	}
	if (length >= outSize) length = outSize - 1;
	memcpy(out, value, length);
	out[length] = 0;
}

static void EmitLocalChat(GGPOSession* session, const char* text)
{
	char name[128];
	if (session->isSpectator) CopyPlayerName(name, sizeof(name), "You");
	else CopyPlayerName(name, sizeof(name), session->playerIndex == 1 ? session->streamPlayer2 : session->streamPlayer1);
	MacadeEmitChatEvent(session, name, text);
}

bool MacadeSendTCPChat(GGPOSession* session, const char* text)
{
	if (session == NULL || session->tcpFd < 0 || session->quarkId[0] == 0 || text == NULL) return false;
	std::vector<unsigned char> payload;
	AppendString(payload, session->quarkId);
	AppendString(payload, text);
	if (!SendCommand(session, 15, payload)) {
		MacadeMarkDisconnected(session);
		return false;
	}
	EmitLocalChat(session, text);
	return true;
}

static bool ReadStringField(const unsigned char* payload, unsigned int payloadSize, unsigned int* cursor, char* out, unsigned int outSize)
{
	if (payload == NULL || cursor == NULL || out == NULL || outSize == 0 || *cursor + 4 > payloadSize) return false;
	unsigned int length = ReadBE32(payload + *cursor);
	*cursor += 4;
	if (length >= outSize || length > payloadSize - *cursor) return false;
	memcpy(out, payload + *cursor, length);
	out[length] = 0;
	*cursor += length;
	return true;
}

void MacadeHandleTCPChatRecord(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL || payload == NULL) return;
	char quark[128];
	char username[128];
	char text[1024];
	unsigned int cursor = 0;
	if (!ReadStringField(payload, payloadSize, &cursor, quark, sizeof(quark))) return;
	if (!ReadStringField(payload, payloadSize, &cursor, username, sizeof(username))) return;
	if (!ReadStringField(payload, payloadSize, &cursor, text, sizeof(text))) return;
	if (strcmp(quark, session->quarkId) != 0) return;
	if (strcmp(username, "Command") == 0) return;
	MacadeEmitChatEvent(session, username, text);
}
