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

#include "macade_embedded.h"

static const uint32_t kMagic = 0x5644434d;
static const int kHeaderSize = 4096;
static const int kSlotCount = 3;
static int gInputFd = -1;
static int gVideoFd = -1;
static unsigned char* gVideo = NULL;
static size_t gVideoBytes = 0;
static uint64_t gFrameIndex = 0;
static unsigned char gKeys[1024] = { 0 };

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
	if (value == NULL || value[0] == 0) return;
	strncpy((char*)gVideo + offset, value, (size_t)length - 1);
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
	if (mapped == MAP_FAILED) { close(gVideoFd); gVideoFd = -1; return; }
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
	sockaddr_un address; memset(&address, 0, sizeof(address));
	address.sun_family = AF_UNIX;
	strncpy(address.sun_path, path, sizeof(address.sun_path) - 1);
	if (bind(gInputFd, (sockaddr*)&address, sizeof(address)) != 0) { close(gInputFd); gInputFd = -1; return; }
}

void MacadeEmbeddedShutdown()
{
	if (gVideo != NULL) { munmap(gVideo, gVideoBytes); gVideo = NULL; }
	if (gVideoFd >= 0) { close(gVideoFd); gVideoFd = -1; }
	if (gInputFd >= 0) { close(gInputFd); gInputFd = -1; }
}

void MacadeEmbeddedPumpInput()
{
	EnsureInput();
	if (gInputFd < 0) return;
	while (true) {
		fd_set readSet; FD_ZERO(&readSet); FD_SET(gInputFd, &readSet);
		timeval tv; tv.tv_sec = 0; tv.tv_usec = 0;
		if (select(gInputFd + 1, &readSet, NULL, NULL, &tv) <= 0) return;
		char buffer[512]; ssize_t count = recv(gInputFd, buffer, sizeof(buffer) - 1, 0);
		if (count <= 0) return;
		buffer[count] = 0;
		int pressed = 0; int scancode = 0;
		if (sscanf(buffer, "key %d %d", &pressed, &scancode) == 2 && scancode >= 0 && scancode < (int)sizeof(gKeys)) gKeys[scancode] = pressed ? 1 : 0;
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
	EnsureVideo();
	if (gVideo == NULL || pixels == NULL || width <= 0 || height <= 0 || pitch <= 0) return;
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

void MacadeEmbeddedPublishOverlay(const MacadeEmbeddedOverlayState* state)
{
	EnsureVideo();
	if (gVideo == NULL || state == NULL) return;
	Store32(56, (uint32_t)(state->spectators < 0 ? 0 : state->spectators));
	Store32(60, (uint32_t)(gFrameIndex + 1));
	Store32(64, state->enabled ? 1 : 0);
	Store32(68, state->spectator ? 1 : 0);
	Store32(72, (uint32_t)state->ranked);
	Store32(76, (uint32_t)state->player);
	Store32(80, (uint32_t)(state->spectators < 0 ? 0 : state->spectators));
	Store32(84, (uint32_t)(state->ping < 0 ? 0 : state->ping));
	Store32(88, (uint32_t)(state->delay < 0 ? 0 : state->delay));
	Store32(92, (uint32_t)(state->systemFrames < 0 ? 0 : state->systemFrames));
	Store32(96, (uint32_t)(state->chatFrames < 0 ? 0 : state->chatFrames));
	Store32(100, state->chatInputActive ? 1 : 0);
	StoreString(104, 160, state->systemMessage);
	StoreString(264, 160, state->chatInput);
	for (int i = 0; i < 2; i++) {
		int offset = 3112 + i * 152;
		StoreString(offset, 128, state->players[i].name);
		StoreString(offset + 128, 16, state->players[i].country);
		Store32(offset + 144, (uint32_t)state->players[i].rank);
		Store32(offset + 148, (uint32_t)state->players[i].score);
	}
}

void MacadeEmbeddedPublishRendererFrame(SDL_Renderer*, int, int)
{
}
