#include "burner.h"
#include "sdl2_inprint.h"
#include "macade_embedded.h"
#include "macade_overlay.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct OverlayPlayer {
	char name[128];
	char country[16];
	int rank;
	int score;
};

struct OverlayChatLine {
	char name[128];
	char text[256];
};

struct OverlayState {
	bool enabled;
	int spectator;
	int ranked;
	int player;
	int spectators;
	double fps;
	int ping;
	int delay;
	int systemFrames;
	int chatFrames;
	int chatInputActive;
	char systemMessage[160];
	char chatInput[160];
	OverlayChatLine chatLines[7];
	OverlayPlayer players[2];
};

static OverlayState gOverlay;

static void PublishOverlay()
{
	MacadeEmbeddedOverlayState state;
	memset(&state, 0, sizeof(state));
	state.enabled = gOverlay.enabled ? 1 : 0;
	state.spectator = gOverlay.spectator;
	state.ranked = gOverlay.ranked;
	state.player = gOverlay.player;
	state.spectators = gOverlay.spectators;
	state.ping = gOverlay.ping;
	state.delay = gOverlay.delay;
	state.systemFrames = gOverlay.systemFrames;
	state.chatFrames = gOverlay.chatFrames;
	state.chatInputActive = gOverlay.chatInputActive;
	snprintf(state.systemMessage, sizeof(state.systemMessage), "%s", gOverlay.systemMessage);
	snprintf(state.chatInput, sizeof(state.chatInput), "%s", gOverlay.chatInput);
	for (int i = 0; i < 7; i++) {
		snprintf(state.chatLines[i].name, sizeof(state.chatLines[i].name), "%s", gOverlay.chatLines[i].name);
		snprintf(state.chatLines[i].text, sizeof(state.chatLines[i].text), "%s", gOverlay.chatLines[i].text);
	}
	for (int i = 0; i < 2; i++) {
		snprintf(state.players[i].name, sizeof(state.players[i].name), "%s", gOverlay.players[i].name);
		snprintf(state.players[i].country, sizeof(state.players[i].country), "%s", gOverlay.players[i].country);
		state.players[i].rank = gOverlay.players[i].rank;
		state.players[i].score = gOverlay.players[i].score;
	}
	MacadeEmbeddedPublishOverlay(&state);
}

static const char* RankLabel(int rank)
{
	static const char* ranks[] = { "?", "E", "D", "C", "B", "A", "S" };
	return rank >= 0 && rank < (int)(sizeof(ranks) / sizeof(ranks[0])) ? ranks[rank] : "?";
}

static int TextWidth(const char* text)
{
	return text == NULL ? 0 : (int)strlen(text) * 8;
}

static int ParseInt(const char* text, int fallback)
{
	if (text == NULL || text[0] == 0) return fallback;
	char* end = NULL;
	long value = strtol(text, &end, 10);
	return end == text ? fallback : (int)value;
}

static void CopyRange(char* out, size_t outSize, const char* begin, const char* end)
{
	if (out == NULL || outSize == 0) return;
	size_t length = begin != NULL && end != NULL && end > begin ? (size_t)(end - begin) : 0;
	if (length >= outSize) length = outSize - 1;
	if (length > 0) memcpy(out, begin, length);
	out[length] = 0;
}

static void ParsePlayer(const char* value, OverlayPlayer* player)
{
	if (player == NULL || value == NULL || value[0] == 0) return;
	const char* hash = strrchr(value, '#');
	if (hash == NULL) {
		snprintf(player->name, sizeof(player->name), "%s", value);
		return;
	}

	CopyRange(player->name, sizeof(player->name), value, hash);
	char fields[96];
	snprintf(fields, sizeof(fields), "%s", hash + 1);
	char* rank = fields;
	char* score = strchr(fields, ',');
	char* country = NULL;
	if (score != NULL) {
		*score++ = 0;
		country = strchr(score, ',');
		if (country != NULL) *country++ = 0;
	}
	player->rank = ParseInt(rank, player->rank);
	player->score = ParseInt(score, player->score);
	if (country != NULL && country[0] != 0) snprintf(player->country, sizeof(player->country), "%s", country);
}

void MacadeOverlayReset()
{
	memset(&gOverlay, 0, sizeof(gOverlay));
	gOverlay.players[0].rank = -1;
	gOverlay.players[1].rank = -1;
	PublishOverlay();
}

void MacadeOverlaySetSession(int spectator, int ranked, int player)
{
	gOverlay.enabled = true;
	gOverlay.spectator = spectator;
	gOverlay.ranked = ranked;
	gOverlay.player = player;
	PublishOverlay();
}

void MacadeOverlaySetGameInfo(const char* player1, const char* player2, int spectator, int ranked, int player)
{
	MacadeOverlaySetSession(spectator, ranked, player);
	ParsePlayer(player1, &gOverlay.players[0]);
	ParsePlayer(player2, &gOverlay.players[1]);
	PublishOverlay();
}

void MacadeOverlaySetScores(int player1Score, int player2Score)
{
	gOverlay.players[0].score = player1Score < 0 ? 0 : player1Score;
	gOverlay.players[1].score = player2Score < 0 ? 0 : player2Score;
	PublishOverlay();
}

void MacadeOverlayGetScores(int* player1Score, int* player2Score)
{
	if (player1Score != NULL) *player1Score = gOverlay.players[0].score;
	if (player2Score != NULL) *player2Score = gOverlay.players[1].score;
}

void MacadeOverlaySetSpectators(int count)
{
	gOverlay.spectators = count < 0 ? 0 : count;
	PublishOverlay();
}

void MacadeOverlaySetSystemMessage(const char* message)
{
	if (message == NULL || message[0] == 0) {
		gOverlay.systemMessage[0] = 0;
		gOverlay.systemFrames = 0;
		PublishOverlay();
		return;
	}
	snprintf(gOverlay.systemMessage, sizeof(gOverlay.systemMessage), "%s", message);
	gOverlay.systemFrames = 180;
	PublishOverlay();
}

void MacadeOverlaySetChatInput(const char* text, int active)
{
	gOverlay.chatInputActive = active ? 1 : 0;
	if (text == NULL) text = "";
	snprintf(gOverlay.chatInput, sizeof(gOverlay.chatInput), "%s", text);
	PublishOverlay();
}

void MacadeOverlayAddChatLine(const char* name, const char* text)
{
	if (text == NULL || text[0] == 0) return;
	for (int i = 6; i > 0; i--) gOverlay.chatLines[i] = gOverlay.chatLines[i - 1];
	snprintf(gOverlay.chatLines[0].name, sizeof(gOverlay.chatLines[0].name), "%s", name == NULL || name[0] == 0 ? "Player" : name);
	snprintf(gOverlay.chatLines[0].text, sizeof(gOverlay.chatLines[0].text), "%s", text);
	gOverlay.chatFrames = 360;
	PublishOverlay();
}

void MacadeOverlaySetStats(double fps, int ping, int delay)
{
	gOverlay.fps = fps;
	gOverlay.ping = ping;
	gOverlay.delay = delay;
	if (gOverlay.chatFrames > 0 && !gOverlay.chatInputActive) gOverlay.chatFrames--;
	PublishOverlay();
}

static void DrawTextRight(SDL_Renderer* renderer, const char* text, int x, int y)
{
	inprint_shadowed(renderer, text, x - TextWidth(text), y);
}

void MacadeOverlayRender(SDL_Renderer* renderer)
{
	if (renderer == NULL || !gOverlay.enabled) return;
	int width = 0;
	int height = 0;
	if (SDL_GetRendererOutputSize(renderer, &width, &height) != 0 || width <= 0 || height <= 0) return;

	SDL_BlendMode oldBlend;
	SDL_GetRenderDrawBlendMode(renderer, &oldBlend);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 155);
	SDL_Rect topBar = { 0, 0, width, 48 };
	SDL_RenderFillRect(renderer, &topBar);
	SDL_SetRenderDrawBlendMode(renderer, oldBlend);

	char left[192];
	char right[192];
	char center[64];
	const OverlayPlayer& p1 = gOverlay.players[0];
	const OverlayPlayer& p2 = gOverlay.players[1];
	snprintf(left, sizeof(left), "%s%s%s%s%s", gOverlay.player == 0 && !gOverlay.spectator ? "* " : "", p1.name[0] ? p1.name : "Player 1", p1.rank >= 0 ? " #" : "", p1.rank >= 0 ? RankLabel(p1.rank) : "", p1.country[0] ? " " : "");
	if (p1.country[0]) snprintf(left + strlen(left), sizeof(left) - strlen(left), "[%s]", p1.country);
	snprintf(right, sizeof(right), "%s%s%s%s%s", p2.country[0] ? "[" : "", p2.country[0] ? p2.country : "", p2.country[0] ? "] " : "", p2.rank >= 0 ? "#" : "", p2.rank >= 0 ? RankLabel(p2.rank) : "");
	if (p2.rank >= 0) snprintf(right + strlen(right), sizeof(right) - strlen(right), " ");
	snprintf(right + strlen(right), sizeof(right) - strlen(right), "%s%s", p2.name[0] ? p2.name : "Player 2", gOverlay.player == 1 && !gOverlay.spectator ? " *" : "");
	if (gOverlay.ranked > 1) snprintf(center, sizeof(center), "%d  FT%d  %d", p1.score, gOverlay.ranked, p2.score);
	else snprintf(center, sizeof(center), "%d  VS  %d", p1.score, p2.score);

	inprint_shadowed(renderer, left, 12, 10);
	DrawTextRight(renderer, right, width - 12, 10);
	inprint_shadowed(renderer, center, (width - TextWidth(center)) / 2, 10);

	char details[192];
	details[0] = 0;
	if (gOverlay.spectator && gOverlay.spectators > 1) snprintf(details, sizeof(details), "Spectating | Spectators %d", gOverlay.spectators - 1);
	else if (gOverlay.spectator) snprintf(details, sizeof(details), "Spectating");
	else if (gOverlay.ping > 0) snprintf(details, sizeof(details), "Ping %dms | Delay %d", gOverlay.ping, gOverlay.delay);
	else snprintf(details, sizeof(details), "Delay %d", gOverlay.delay);
	inprint_shadowed(renderer, details, (width - TextWidth(details)) / 2, 30);

	if (gOverlay.systemFrames > 0 && gOverlay.systemMessage[0]) {
		inprint_shadowed(renderer, gOverlay.systemMessage, (width - TextWidth(gOverlay.systemMessage)) / 2, 64);
		gOverlay.systemFrames--;
	}
	if (gOverlay.chatInputActive) {
		char chat[192];
		snprintf(chat, sizeof(chat), "> %s", gOverlay.chatInput);
		inprint_shadowed(renderer, chat, 12, height - 28);
	}
}
