#include "ggpomac_internal.h"

#include <string.h>

static unsigned int ReadBE32(const unsigned char* data)
{
	return ((unsigned int)data[0] << 24) | ((unsigned int)data[1] << 16) | ((unsigned int)data[2] << 8) | (unsigned int)data[3];
}

static bool ReadString(const unsigned char* payload, unsigned int payloadSize, unsigned int* cursor, char* out, size_t outSize)
{
	if (payload == NULL || cursor == NULL || out == NULL || outSize == 0 || *cursor + 4 > payloadSize) return false;
	unsigned int length = ReadBE32(payload + *cursor);
	*cursor += 4;
	if (length > payloadSize - *cursor) return false;
	unsigned int copySize = length < outSize - 1 ? length : (unsigned int)outSize - 1;
	memcpy(out, payload + *cursor, copySize);
	out[copySize] = 0;
	*cursor += length;
	return true;
}

bool MacadeHandleTCPMatchInfoRecord(GGPOSession* session, const unsigned char* payload, unsigned int payloadSize)
{
	if (session == NULL || payload == NULL || payloadSize < 4) return false;
	unsigned int cursor = 4;
	if (!ReadString(payload, payloadSize, &cursor, session->streamPlayer1, sizeof(session->streamPlayer1))) return false;
	if (!ReadString(payload, payloadSize, &cursor, session->streamPlayer2, sizeof(session->streamPlayer2))) return false;
	if (!ReadString(payload, payloadSize, &cursor, session->streamBlurb, sizeof(session->streamBlurb))) return false;
	if (cursor + 4 <= payloadSize) session->streamSpectatorCount = (int)ReadBE32(payload + cursor);
	MacadeEmitClientEvent(session, GGPOCLIENT_EVENTCODE_MATCHINFO, session->streamPlayer1, session->streamPlayer2, session->streamBlurb, 0);
	if (session->streamSpectatorCount > 0) {
		MacadeEmitClientEvent(session, GGPOCLIENT_EVENTCODE_SPECTATOR_COUNT_CHANGED, NULL, NULL, NULL, session->streamSpectatorCount);
	}
	MacadeLog("Macade GGPO: match info p1=%s p2=%s blurb=%s spectators=%d\n", session->streamPlayer1, session->streamPlayer2, session->streamBlurb, session->streamSpectatorCount);
	return true;
}
