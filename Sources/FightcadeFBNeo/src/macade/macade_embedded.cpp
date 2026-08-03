#include "macade_embedded.h"

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

static const uint32_t kMagic = 0x5644434d;
static const int kHeaderSize = 4096;
static const int kSlotCount = 3;

static int gInputFd = -1;
static int gVideoFd = -1;
static unsigned char* gVideo = NULL;
static size_t gVideoBytes = 0;
static uint64_t gFrameIndex = 0;
static uint32_t gOverlaySequence = 0;
static unsigned char gKeys[1024] = { 0 };
static char gChatInput[160] = { 0 };
static char gChatSubmit[160] = { 0 };
static bool gChatInputActive = false;

static void EnsureVideo();
extern int MacadeEmbeddedVideoScale;
extern int nAudVolume;
extern int AudSoundSetVolume();
extern void QuarkReplaySetPaused(int paused);
extern void QuarkReplaySetFastForward(int enabled);
extern void QuarkReplaySeek(int frame);
extern void QuarkReplayStep(int delta);

static int ClampVideoScale(int scale)
{
	if (scale < 0) return 0;
	if (scale > 5) return 5;
	return scale;
}

static int ClampVolume(int volume)
{
	if (volume < 0) return 0;
	if (volume > 100) return 100;
	return volume;
}

enum {
	kOverlaySequence = 60,
	kOverlayEnabled = 64,
	kOverlaySpectator = 68,
	kOverlayRanked = 72,
	kOverlayPlayer = 76,
	kOverlaySpectators = 80,
	kOverlayPing = 84,
	kOverlayDelay = 88,
	kOverlaySystemFrames = 92,
	kOverlayChatFrames = 96,
	kOverlayChatInputActive = 100,
	kOverlaySystemMessage = 104,
	kOverlaySystemMessageLength = 160,
	kOverlayChatInput = 264,
	kOverlayChatInputLength = 160,
	kOverlayChatLines = 424,
	kOverlayChatLineCount = 7,
	kOverlayChatLineSize = 384,
	kOverlayChatLineNameLength = 128,
	kOverlayChatLineText = 128,
	kOverlayChatLineTextLength = 256,
	kOverlayPlayers = 3112,
	kOverlayPlayerSize = 152,
	kOverlayPlayerNameLength = 128,
	kOverlayPlayerCountry = 128,
	kOverlayPlayerCountryLength = 16,
	kOverlayPlayerRank = 144,
	kOverlayPlayerScore = 148,
	kOverlayConnectionPhase = 3420,
	kOverlayMatchEnded = 3424,
	kOverlayReplayCurrentFrame = 3428,
	kOverlayReplayTotalFrames = 3432,
	kOverlayReplayBufferedFrames = 3436,
	kOverlayReplaySeekable = 3440,
	kOverlayReplayPaused = 3444,
	kOverlayReplayFastForwarding = 3448,
};

static void Store32(int offset, uint32_t value)
{
	if (gVideo == NULL || offset < 0 || (size_t)offset + 4 > gVideoBytes) return;
	memcpy(gVideo + offset, &value, 4);
}

static void Store64(int offset, uint64_t value)
{
	if (gVideo == NULL || offset < 0 || (size_t)offset + 8 > gVideoBytes) return;
	memcpy(gVideo + offset, &value, 8);
}

static void StoreString(int offset, int length, const char* value)
{
	if (gVideo == NULL || offset < 0 || length <= 0 || (size_t)offset + (size_t)length > gVideoBytes) return;
	memset(gVideo + offset, 0, (size_t)length);
	if (value == NULL) return;
	strncpy((char*)gVideo + offset, value, (size_t)length - 1);
}

static void BumpOverlay()
{
	EnsureVideo();
	Store32(kOverlayEnabled, 1);
	Store32(kOverlaySequence, ++gOverlaySequence);
}

static int HexValue(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return -1;
}

static void DecodeHex(char* out, size_t outSize, const char* hex)
{
	if (outSize == 0) return;
	size_t written = 0;
	while (hex != NULL && hex[0] != 0 && hex[1] != 0 && written + 1 < outSize) {
		int hi = HexValue(hex[0]);
		int lo = HexValue(hex[1]);
		if (hi < 0 || lo < 0) break;
		out[written++] = (char)((hi << 4) | lo);
		hex += 2;
	}
	out[written] = 0;
}

static void StorePlayer(int index, const char* value)
{
	char name[128] = { 0 };
	int rank = -1;
	int score = 0;
	if (value != NULL) {
		const char* hash = strchr(value, '#');
		size_t nameLen = hash == NULL ? strlen(value) : (size_t)(hash - value);
		if (nameLen >= sizeof(name)) nameLen = sizeof(name) - 1;
		memcpy(name, value, nameLen);
		if (hash != NULL) sscanf(hash + 1, "%d,%d", &rank, &score);
	}
	int offset = kOverlayPlayers + index * kOverlayPlayerSize;
	StoreString(offset, kOverlayPlayerNameLength, name);
	StoreString(offset + kOverlayPlayerCountry, kOverlayPlayerCountryLength, "");
	Store32(offset + kOverlayPlayerRank, (uint32_t)rank);
	Store32(offset + kOverlayPlayerScore, (uint32_t)score);
}

bool MacadeEmbeddedEnabled()
{
	const char* session = getenv("MACADE_EMBEDDED_SESSION_ID");
	return session != NULL && session[0] != 0;
}

bool MacadeEmbeddedWindowHidden()
{
	const char* value = getenv("MACADE_EMBEDDED_HIDE_WINDOW");
	return value != NULL && strcmp(value, "1") == 0;
}

static void EnsureVideo()
{
	if (gVideo != NULL || !MacadeEmbeddedEnabled()) return;
	const char* path = getenv("MACADE_EMBEDDED_VIDEO_PATH");
	const char* bytesText = getenv("MACADE_EMBEDDED_VIDEO_BYTES");
	if (path == NULL || path[0] == 0 || bytesText == NULL || bytesText[0] == 0) return;

	gVideoBytes = (size_t)strtoull(bytesText, NULL, 10);
	if (gVideoBytes <= kHeaderSize) return;
	gVideoFd = open(path, O_RDWR, 0600);
	if (gVideoFd < 0) return;

	void* mapped = mmap(NULL, gVideoBytes, PROT_READ | PROT_WRITE, MAP_SHARED, gVideoFd, 0);
	if (mapped == MAP_FAILED) {
		close(gVideoFd);
		gVideoFd = -1;
		return;
	}

	gVideo = (unsigned char*)mapped;
	Store32(0, kMagic);
	Store32(4, 1);
	Store32(8, kHeaderSize);
	Store32(12, kSlotCount);
	Store32(36, (uint32_t)((gVideoBytes - kHeaderSize) / kSlotCount));
}

static void EnsureInput()
{
	if (gInputFd >= 0 || !MacadeEmbeddedEnabled()) return;
	const char* path = getenv("MACADE_EMBEDDED_INPUT_SOCKET");
	if (path == NULL || path[0] == 0) return;

	gInputFd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (gInputFd < 0) return;

	unlink(path);
	sockaddr_un address;
	memset(&address, 0, sizeof(address));
	address.sun_family = AF_UNIX;
	strncpy(address.sun_path, path, sizeof(address.sun_path) - 1);
	if (bind(gInputFd, (sockaddr*)&address, sizeof(address)) != 0) {
		close(gInputFd);
		gInputFd = -1;
	}
}

void MacadeEmbeddedShutdown()
{
	if (gVideo != NULL) {
		munmap(gVideo, gVideoBytes);
		gVideo = NULL;
	}
	if (gVideoFd >= 0) {
		close(gVideoFd);
		gVideoFd = -1;
	}
	if (gInputFd >= 0) {
		close(gInputFd);
		gInputFd = -1;
	}
}

void MacadeEmbeddedPumpInput()
{
	EnsureInput();
	if (gInputFd < 0) return;

	while (true) {
		fd_set readSet;
		FD_ZERO(&readSet);
		FD_SET(gInputFd, &readSet);
		timeval tv;
		tv.tv_sec = 0;
		tv.tv_usec = 0;
		if (select(gInputFd + 1, &readSet, NULL, NULL, &tv) <= 0) return;

		char buffer[384];
		ssize_t count = recv(gInputFd, buffer, sizeof(buffer) - 1, 0);
		if (count <= 0) return;
		buffer[count] = 0;

		int pressed = 0;
		int scancode = 0;
		int videoScale = 0;
		int volume = 0;
		int replayValue = 0;
		if (sscanf(buffer, "key %d %d", &pressed, &scancode) == 2 && scancode >= 0 && scancode < (int)sizeof(gKeys)) {
			gKeys[scancode] = pressed ? 1 : 0;
		} else if (sscanf(buffer, "videoScale %d", &videoScale) == 1) {
			MacadeEmbeddedVideoScale = ClampVideoScale(videoScale);
		} else if (sscanf(buffer, "volume %d", &volume) == 1) {
			nAudVolume = ClampVolume(volume) * 100;
			AudSoundSetVolume();
		} else if (sscanf(buffer, "replayPause %d", &replayValue) == 1) {
			QuarkReplaySetPaused(replayValue);
		} else if (sscanf(buffer, "replayFastForward %d", &replayValue) == 1) {
			QuarkReplaySetFastForward(replayValue);
		} else if (sscanf(buffer, "replaySeek %d", &replayValue) == 1) {
			QuarkReplaySeek(replayValue);
		} else if (sscanf(buffer, "replayStep %d", &replayValue) == 1) {
			QuarkReplayStep(replayValue);
		} else if (strcmp(buffer, "chatBegin") == 0) {
			gChatInputActive = true;
			gChatInput[0] = 0;
			EnsureVideo();
			StoreString(kOverlayChatInput, kOverlayChatInputLength, gChatInput);
			Store32(kOverlayChatInputActive, 1);
			MacadeEmbeddedSetOverlaySystemMessage("", 0);
			BumpOverlay();
		} else if (strncmp(buffer, "chatUpdate ", 11) == 0) {
			DecodeHex(gChatInput, sizeof(gChatInput), buffer + 11);
			EnsureVideo();
			StoreString(kOverlayChatInput, kOverlayChatInputLength, gChatInput);
			Store32(kOverlayChatInputActive, gChatInputActive ? 1 : 0);
			BumpOverlay();
		} else if (strncmp(buffer, "chatSubmit ", 11) == 0) {
			DecodeHex(gChatSubmit, sizeof(gChatSubmit), buffer + 11);
			gChatInputActive = false;
			gChatInput[0] = 0;
			EnsureVideo();
			StoreString(kOverlayChatInput, kOverlayChatInputLength, gChatInput);
			Store32(kOverlayChatInputActive, 0);
			BumpOverlay();
		} else if (strcmp(buffer, "chatCancel") == 0) {
			gChatInputActive = false;
			gChatInput[0] = 0;
			EnsureVideo();
			StoreString(kOverlayChatInput, kOverlayChatInputLength, gChatInput);
			Store32(kOverlayChatInputActive, 0);
			BumpOverlay();
		}
	}
}

extern "C" int MacadeEmbeddedKeyState(int scancode)
{
	MacadeEmbeddedPumpInput();
	if (scancode < 0 || scancode >= (int)sizeof(gKeys)) return 0;
	return gKeys[scancode] ? 1 : 0;
}

void MacadeEmbeddedPublishFrame(const void* pixels, int width, int height, int pitch, int bytesPerPixel, int isRGB565)
{
	MacadeEmbeddedPumpInput();
	EnsureVideo();
	if (gVideo == NULL || pixels == NULL || width <= 0 || height <= 0 || pitch <= 0) return;

	uint32_t frames = 0;
	memcpy(&frames, gVideo + kOverlaySystemFrames, 4);
	if (frames > 0) Store32(kOverlaySystemFrames, frames - 1);
	memcpy(&frames, gVideo + kOverlayChatFrames, 4);
	if (frames > 0) Store32(kOverlayChatFrames, frames - 1);
	StoreString(kOverlayChatInput, kOverlayChatInputLength, gChatInput);
	Store32(kOverlayChatInputActive, gChatInputActive ? 1 : 0);

	uint32_t slotCapacity = 0;
	memcpy(&slotCapacity, gVideo + 36, 4);
	size_t byteCount = (size_t)pitch * (size_t)height;
	if (slotCapacity == 0 || byteCount > slotCapacity) return;

	uint32_t slot = (uint32_t)((gFrameIndex + 1) % kSlotCount);
	memcpy(gVideo + kHeaderSize + (size_t)slot * slotCapacity, pixels, byteCount);
	Store32(16, (uint32_t)width);
	Store32(20, (uint32_t)height);
	Store32(24, (uint32_t)pitch);
	Store32(28, (uint32_t)bytesPerPixel);
	Store32(32, isRGB565 ? 1 : 0);
	Store32(40, slot);
	Store32(44, 1);
	Store64(48, ++gFrameIndex);
}

void MacadeEmbeddedSetOverlaySystemMessage(const char* message, int frames)
{
	EnsureVideo();
	StoreString(kOverlaySystemMessage, kOverlaySystemMessageLength, message);
	Store32(kOverlaySystemFrames, frames > 0 ? (uint32_t)frames : 0);
	BumpOverlay();
}

void MacadeEmbeddedSetOverlayConnectionPhase(int phase)
{
	EnsureVideo();
	Store32(kOverlayConnectionPhase, phase > 0 ? (uint32_t)phase : 0);
	BumpOverlay();
}

void MacadeEmbeddedSetOverlayGameInfo(const char* player1, const char* player2, int spectator, int ranked, int player)
{
	EnsureVideo();
	Store32(kOverlaySpectator, spectator ? 1 : 0);
	Store32(kOverlayRanked, ranked > 0 ? (uint32_t)ranked : 0);
	Store32(kOverlayPlayer, player > 0 ? 1 : 0);
	Store32(kOverlayMatchEnded, 0);
	StorePlayer(0, player1);
	StorePlayer(1, player2);
	BumpOverlay();
}

void MacadeEmbeddedSetOverlayScores(int score1, int score2)
{
	EnsureVideo();
	Store32(kOverlayPlayers + kOverlayPlayerScore, score1 > 0 ? (uint32_t)score1 : 0);
	Store32(kOverlayPlayers + kOverlayPlayerSize + kOverlayPlayerScore, score2 > 0 ? (uint32_t)score2 : 0);
	BumpOverlay();
}

void MacadeEmbeddedSetOverlaySpectators(int spectators)
{
	EnsureVideo();
	Store32(kOverlaySpectators, spectators > 0 ? (uint32_t)spectators : 0);
	BumpOverlay();
}

void MacadeEmbeddedSetOverlayStats(int ping, int delay)
{
	EnsureVideo();
	Store32(kOverlayPing, ping > 0 ? (uint32_t)ping : 0);
	Store32(kOverlayDelay, delay > 0 ? (uint32_t)delay : 0);
	BumpOverlay();
}

void MacadeEmbeddedSetOverlayMatchEnded()
{
	EnsureVideo();
	Store32(kOverlayMatchEnded, 1);
	StoreString(kOverlaySystemMessage, kOverlaySystemMessageLength, "Match Complete");
	Store32(kOverlaySystemFrames, 300);
	BumpOverlay();
}

void MacadeEmbeddedAddOverlayChatLine(const char* name, const char* text)
{
	EnsureVideo();
	if (gVideo == NULL) return;
	for (int i = kOverlayChatLineCount - 1; i > 0; --i) {
		memcpy(gVideo + kOverlayChatLines + i * kOverlayChatLineSize,
		       gVideo + kOverlayChatLines + (i - 1) * kOverlayChatLineSize,
		       kOverlayChatLineSize);
	}
	StoreString(kOverlayChatLines, kOverlayChatLineNameLength, name);
	StoreString(kOverlayChatLines + kOverlayChatLineText, kOverlayChatLineTextLength, text);
	Store32(kOverlayChatFrames, 300);
	BumpOverlay();
}

void MacadeEmbeddedSetReplayStatus(int currentFrame, int totalFrames, int bufferedFrames, int seekable, int paused, int fastForwarding)
{
	EnsureVideo();
	Store32(kOverlayReplayCurrentFrame, currentFrame > 0 ? (uint32_t)currentFrame : 0);
	Store32(kOverlayReplayTotalFrames, totalFrames > 0 ? (uint32_t)totalFrames : 0);
	Store32(kOverlayReplayBufferedFrames, bufferedFrames > 0 ? (uint32_t)bufferedFrames : 0);
	Store32(kOverlayReplaySeekable, seekable ? 1 : 0);
	Store32(kOverlayReplayPaused, paused ? 1 : 0);
	Store32(kOverlayReplayFastForwarding, fastForwarding ? 1 : 0);
	BumpOverlay();
}

int MacadeEmbeddedConsumeChatSubmit(char* text, int size)
{
	MacadeEmbeddedPumpInput();
	if (text == NULL || size <= 0 || gChatSubmit[0] == 0) return 0;
	strncpy(text, gChatSubmit, (size_t)size - 1);
	text[size - 1] = 0;
	gChatSubmit[0] = 0;
	return text[0] != 0;
}
