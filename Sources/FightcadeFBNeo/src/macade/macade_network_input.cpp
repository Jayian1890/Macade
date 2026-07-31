#include "burner.h"
#include "ggpomac_internal.h"

#include <stdio.h>
#include <string.h>
#include <strings.h>

extern GGPOSession* ggpo;
extern int kNetGame;
extern int kNetVersion;

static const int kMaxPlayers = 4;
static const int kNetPlayers = 2;
static const int kInputSize = 8 * (4 + 8);

static int gPlayerInputs[kMaxPlayers];
static int gCommonInputs = 0;
static int gDIPInputs = 0;
static int gPlayerOffset[kMaxPlayers];
static int gCommonOffset = 0;
static int gDIPOffset = 0;
static unsigned char gControls[kInputSize];
static int gNetworkGetInputLogCount = 0;
static int gNetworkReplayFrameLogCount = 0;
static int gNetworkLocalNonzeroLogCount = 0;

static bool BufferHasNonzeroByte(const unsigned char* bytes, int size)
{
	for (int i = 0; i < size; i++) if (bytes[i] != 0) return true;
	return false;
}

static void FormatBytes(const unsigned char* bytes, int size, char* out, int outSize)
{
	static const char* hex = "0123456789abcdef";
	if (out == NULL || outSize <= 0) return;
	out[0] = 0;
	if (bytes == NULL || size <= 0) return;
	int written = 0;
	int limit = size < 8 ? size : 8;
	for (int i = 0; i < limit && written + 2 < outSize; i++) {
		out[written++] = hex[(bytes[i] >> 4) & 0xf];
		out[written++] = hex[bytes[i] & 0xf];
	}
	out[written] = 0;
}

static bool InputNameHasPrefix(const BurnInputInfo& input, const char* prefix)
{
	return input.szName != NULL && strncasecmp(input.szName, prefix, strlen(prefix)) == 0;
}

static bool ReadInputInfo(unsigned int index, BurnInputInfo* input)
{
	if (index >= nGameInpCount) return false;
	memset(input, 0, sizeof(*input));
	return BurnDrvGetInputInfo(input, index) == 0;
}

static bool InputValueIsSet(const BurnInputInfo& input)
{
	return input.pVal != NULL && *input.pVal != 0;
}

static bool CommonInputAllowed(const BurnInputInfo& input)
{
	if (!kNetGame || input.szName == NULL) return true;
	if (strcmp(input.szName, "Tilt") == 0) return false;
	if (strcmp(input.szName, "Reset") == 0) return false;
	if (strcmp(input.szName, "Diagnostic") == 0) return false;
	if (strcmp(input.szName, "Service") == 0) return false;
	if (strcmp(input.szName, "Test") == 0) return false;
	return true;
}

int MacadeNetworkInitInput()
{
	memset(gPlayerInputs, 0, sizeof(gPlayerInputs));
	memset(gPlayerOffset, 0, sizeof(gPlayerOffset));
	gCommonInputs = 0;
	gDIPInputs = 0;
	gCommonOffset = 0;
	gDIPOffset = 0;

	if (nGameInpCount == 0) {
		return 1;
	}

	BurnInputInfo input;
	unsigned int index = 0;
	gPlayerOffset[0] = 0;
	while (ReadInputInfo(index, &input) && InputNameHasPrefix(input, "P1")) {
		index++;
	}
	gPlayerInputs[0] = (int)index - gPlayerOffset[0];

	for (int player = 1; player < kMaxPlayers; player++) {
		char prefix[3] = { 'P', (char)('1' + player), 0 };
		gPlayerOffset[player] = (int)index;
		while (ReadInputInfo(index, &input) && InputNameHasPrefix(input, prefix)) {
			index++;
		}
		gPlayerInputs[player] = (int)index - gPlayerOffset[player];
	}

	gCommonOffset = (int)index;
	while (ReadInputInfo(index, &input) && (input.nType & BIT_GROUP_CONSTANT) == 0) {
		index++;
	}
	gCommonInputs = (int)index - gCommonOffset;
	gDIPOffset = (int)index;
	gDIPInputs = (int)nGameInpCount - gDIPOffset;

	printf("Macade GGPO: network inputs p1=%d p2=%d p3=%d p4=%d common=%d dip=%d total=%u\n",
		gPlayerInputs[0], gPlayerInputs[1], gPlayerInputs[2], gPlayerInputs[3], gCommonInputs, gDIPInputs, nGameInpCount);
	fflush(stdout);
	return 0;
}

static bool MacadeCaptureLocalControls(int* blockSize)
{
	int i, j;
	BurnInputInfo input;
	memset(gControls, 0, sizeof(gControls));

	for (i = 0, j = 0; i < gPlayerInputs[0]; i++, j++) {
		if (!ReadInputInfo(i + gPlayerOffset[0], &input)) continue;
		if (InputValueIsSet(input) && input.nType == BIT_DIGITAL) {
			gControls[j >> 3] |= 1 << (j & 7);
		}
	}

	for (i = 0; i < gCommonInputs; i++, j++) {
		if (!ReadInputInfo(i + gCommonOffset, &input)) continue;
		if (InputValueIsSet(input) && CommonInputAllowed(input)) {
			gControls[j >> 3] |= 1 << (j & 7);
		}
	}

	j = (j + 7) >> 3;

	for (i = 0; i < gPlayerInputs[0]; i++) {
		if (!ReadInputInfo(i + gPlayerOffset[0], &input)) continue;
		if (!InputValueIsSet(input) || input.nType == BIT_DIGITAL) continue;
		if (input.nType & BIT_GROUP_ANALOG) {
			if (input.pShortVal == NULL || j + 1 >= kInputSize) continue;
			gControls[j++] = (unsigned char)(*input.pShortVal >> 8);
			gControls[j++] = (unsigned char)(*input.pShortVal & 0xff);
		} else if (j < kInputSize) {
			gControls[j++] = *input.pVal;
		}
	}

	// Fightcade's FBNeo bridge passes one padding byte past the serialized controls.
	*blockSize = j + 1;
	if (*blockSize <= 0 || *blockSize * kNetPlayers > kInputSize) {
		printf("Macade GGPO: invalid input block size=%d max=%d\n", *blockSize, kInputSize / kNetPlayers);
		fflush(stdout);
		return false;
	}
	return true;
}

static void MacadeApplySynchronizedControls(int blockSize)
{
	int i, j;
	BurnInputInfo input;

	for (i = 0, j = 0; i < gPlayerInputs[0]; i++, j++) {
		if (!ReadInputInfo(i + gPlayerOffset[0], &input) || input.pVal == NULL) continue;
		if (input.nType == BIT_DIGITAL) {
			*input.pVal = (gControls[j >> 3] & (1 << (j & 7))) ? 1 : 0;
		}
	}

	for (i = 0; i < gCommonInputs; i++, j++) {
		if (!ReadInputInfo(i + gCommonOffset, &input) || input.pVal == NULL) continue;
		*input.pVal = (gControls[j >> 3] & (1 << (j & 7))) ? 1 : 0;
	}

	j = (j + 7) >> 3;

	for (i = 0; i < gPlayerInputs[0]; i++) {
		if (!ReadInputInfo(i + gPlayerOffset[0], &input)) continue;
		if ((input.nType & BIT_GROUP_ANALOG) && input.pShortVal != NULL && j + 1 < kInputSize) {
			*input.pShortVal = (gControls[j] << 8) | gControls[j + 1];
			j += 2;
		}
	}

	for (int player = 1; player < kMaxPlayers; player++) {
		if (gPlayerInputs[player] == 0) continue;
		int bitOffset = blockSize * player * 8;
		for (i = 0, j = bitOffset; i < gPlayerInputs[player]; i++, j++) {
			if (!ReadInputInfo(i + gPlayerOffset[player], &input) || input.pVal == NULL) continue;
			if (input.nType == BIT_DIGITAL) {
				*input.pVal = (gControls[j >> 3] & (1 << (j & 7))) ? 1 : 0;
			}
		}

		j += gCommonInputs;
		j = (j + 7) >> 3;
		for (i = 0; i < gPlayerInputs[player]; i++) {
			if (!ReadInputInfo(i + gPlayerOffset[player], &input)) continue;
			if ((input.nType & BIT_GROUP_ANALOG) && input.pShortVal != NULL && j + 1 < kInputSize) {
				*input.pShortVal = (gControls[j] << 8) | gControls[j + 1];
				j += 2;
			}
		}

	}
}

int MacadeNetworkGetInput()
{
	if (ggpo == NULL) return 0;
	if (ggpo->isSpectator && !ggpo->streamInitialStateLoaded && ggpo->streamInitialStateReceived && !MacadeLoadStreamingInitialState(ggpo, 0)) return 1;
	int blockSize = 0;
	if (!MacadeCaptureLocalControls(&blockSize)) return 1;
	if (gNetworkGetInputLogCount < 20 || gNetworkGetInputLogCount % 120 == 0) {
		printf("Macade diagnostic: NetworkGetInput=%d frame=%d block=%d player=%d remoteLast=%d localAck=%d\n",
			gNetworkGetInputLogCount, ggpo->currentFrame, blockSize, ggpo->playerIndex, ggpo->remoteLastFrame, ggpo->localAckFrame);
		fflush(stdout);
	}
	if (BufferHasNonzeroByte(gControls, blockSize) && gNetworkLocalNonzeroLogCount < 20) {
		char localBytes[32];
		FormatBytes(gControls, blockSize, localBytes, sizeof(localBytes));
		printf("Macade diagnostic: local input nonzero frame=%d block=%d bytes=%s\n", ggpo->currentFrame, blockSize, localBytes);
		fflush(stdout);
		gNetworkLocalNonzeroLogCount++;
	}
	bool synchronized = ggpo_synchronize_input(ggpo, gControls, blockSize, kNetPlayers);
	if (gNetworkGetInputLogCount < 20 || gNetworkGetInputLogCount % 120 == 0 || !synchronized) {
		printf("Macade diagnostic: NetworkGetInput=%d synchronized=%d frame=%d remoteLast=%d remoteStored=%zu\n",
			gNetworkGetInputLogCount, synchronized ? 1 : 0, ggpo->currentFrame, ggpo->remoteLastFrame, ggpo->remoteInputs.size());
		fflush(stdout);
	}
	gNetworkGetInputLogCount++;
	if (!synchronized) {
		return (ggpo->fatalDesync || ggpo->networkDisconnected) ? 1 : 2;
	}
	MacadeApplySynchronizedControls(blockSize);
	return 0;
}

int MacadeNetworkReplayFrame()
{
	if (ggpo == NULL || ggpo->inputSize <= 0) return 1;
	memset(gControls, 0, sizeof(gControls));
	std::map<int, std::vector<unsigned char> >::iterator local = ggpo->localInputs.find(ggpo->currentFrame);
	if (local != ggpo->localInputs.end() && local->second.size() == (size_t)ggpo->inputSize) memcpy(gControls, local->second.data(), ggpo->inputSize);
	nCurrentFrame++;
	bool synchronized = ggpo_synchronize_input(ggpo, gControls, ggpo->inputSize, kNetPlayers);
	if (!synchronized) return 1;
	MacadeApplySynchronizedControls(ggpo->inputSize);
	UINT8* oldDraw = pBurnDraw;
	INT16* oldSound = pBurnSoundOut;
	pBurnDraw = NULL;
	pBurnSoundOut = NULL;
	BurnDrvFrame();
	pBurnDraw = oldDraw;
	pBurnSoundOut = oldSound;
	if (!ggpo_advance_frame(ggpo)) return 1;
	if (gNetworkReplayFrameLogCount < 8 || gNetworkReplayFrameLogCount % 120 == 0) {
		printf("Macade diagnostic: rollback replay frame=%d remoteLast=%d predicted=%zu\n", ggpo->currentFrame, ggpo->remoteLastFrame, ggpo->predictedRemoteInputs.size());
		fflush(stdout);
	}
	gNetworkReplayFrameLogCount++;
	return 0;
}
