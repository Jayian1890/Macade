#include "burner.h"
#include "macade_detector.h"
#include "macade_ggpo_session.h"
#include "macade_overlay.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

extern int iRanked;
extern int kNetSpectator;
extern int kNetVersion;
extern GGPOSession* ggpo;

static const int kStartFrames = 300;
static const int kDetectorFrames = 30;

struct MacadeDetectorRule {
	enum Type { Store, MemEq, MemGts };
	Type type = Store;
	int frames = 0;
	bool raw = false;
	char name[64] = { 0 };
	char area[64] = { 0 };
	unsigned int pointer = 0;
	unsigned int value = 0;
	unsigned int bits = 0;
	unsigned int start = 0;
	unsigned int current = 0;

	bool active() const { return type != Store || name[0] != 0; }
	bool detected() const { return frames >= kDetectorFrames; }
};

struct MacadeGameDetector {
	enum State { None, WaitStart, WaitWinner, WaitEnd };
	State state = None;
	int frameTime = 0;
	int frameStart = 0;
	int score1 = 0;
	int score2 = 0;
	int winner = 0;
	bool rawDetector = false;
	bool running = false;
	bool debug = false;
	std::vector<MacadeDetectorRule> start;
	std::vector<MacadeDetectorRule> player1;
	std::vector<MacadeDetectorRule> player2;
	MacadeDetectorRule char1;
	MacadeDetectorRule char2;
};

static MacadeGameDetector gDetector;

static MacadeDetectorRule::Type RuleType(const char* op)
{
	if (strcmp(op, "eq") == 0) return MacadeDetectorRule::MemEq;
	if (strcmp(op, "gts") == 0) return MacadeDetectorRule::MemGts;
	return MacadeDetectorRule::Store;
}

static void LoadRule(MacadeDetectorRule* rule, const char* name, const char* area, const char* op, unsigned int pointer, unsigned int value, unsigned int bits)
{
	snprintf(rule->name, sizeof(rule->name), "%s", name);
	snprintf(rule->area, sizeof(rule->area), "%s", area);
	rule->type = RuleType(op);
	rule->raw = strcmp(area, "raw") == 0;
	rule->pointer = pointer;
	rule->value = value;
	rule->bits = bits;
	rule->start = 0;
	rule->current = 0;
	rule->frames = 0;
}

static bool LoadDetectorFile(const char* game, std::vector<char>* bytes)
{
	char path[256];
	snprintf(path, sizeof(path), "detector/%s.inf", game);
	FILE* file = fopen(path, "rb");
	if (file == NULL) return false;
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	if (size <= 0 || size > 1024 * 1024) { fclose(file); return false; }
	bytes->resize((size_t)size + 1);
	size_t read = fread(bytes->data(), 1, (size_t)size, file);
	fclose(file);
	(*bytes)[read] = 0;
	return read > 0;
}

static bool PointerInArea(const BurnArea* area, const MacadeDetectorRule& rule)
{
	unsigned int width = rule.bits == 32 ? 4 : (rule.bits == 16 ? 2 : 1);
	return area != NULL && area->Data != NULL && strcmp(area->szName, rule.area) == 0 && rule.pointer + width <= area->nLen;
}

static void UpdateRule(MacadeDetectorRule* rule, const BurnArea* area, bool startDetected)
{
	if (rule == NULL || !rule->active()) return;
	if (area != NULL) {
		if (!PointerInArea(area, *rule)) return;
		unsigned char* data = (unsigned char*)area->Data;
		if (rule->bits == 32) rule->current = ((unsigned int*)data)[rule->pointer >> 2];
		else if (rule->bits == 16) rule->current = ((unsigned short*)data)[rule->pointer >> 1];
		else rule->current = data[rule->pointer];
	} else if (rule->raw) {
		unsigned int width = rule->bits == 32 ? 4 : (rule->bits == 16 ? 2 : 1);
		rule->current = ReadValueAtHardwareAddress(rule->pointer, width, 0);
	} else {
		return;
	}

	if (startDetected) rule->start = rule->current;
	bool found = rule->type == MacadeDetectorRule::MemEq ? rule->current == rule->value :
		(rule->type == MacadeDetectorRule::MemGts && !startDetected && rule->current > rule->start);
	rule->frames = found ? rule->frames + 1 : 0;
}

static void UpdateRules(BurnArea* area, bool detectStart)
{
	bool startDetected = false;
	for (size_t i = 0; i < gDetector.start.size(); i++) {
		UpdateRule(&gDetector.start[i], area, false);
		startDetected = startDetected || (detectStart && gDetector.start[i].detected());
	}
	for (size_t i = 0; i < gDetector.player1.size(); i++) UpdateRule(&gDetector.player1[i], area, startDetected);
	for (size_t i = 0; i < gDetector.player2.size(); i++) UpdateRule(&gDetector.player2[i], area, startDetected);
	UpdateRule(&gDetector.char1, area, startDetected);
	UpdateRule(&gDetector.char2, area, startDetected);
}

static int __cdecl DetectorScan(BurnArea* area)
{
	UpdateRules(area, true);
	return 0;
}

static void SendWinnerIfNeeded(int winner)
{
	if (ggpo == NULL || kNetSpectator || iRanked <= 0 || winner == 0) return;
	int char1 = gDetector.char1.active() ? (int)gDetector.char1.current : -1;
	int char2 = gDetector.char2.active() ? (int)gDetector.char2.current : -1;
	char text[96];
	snprintf(text, sizeof(text), "W%d,%d,%d,%d,%d", winner, gDetector.score1, gDetector.score2, char1, char2);
	ggpo_client_chat(ggpo, text);
}

static void ApplyKOF98MoodSeed(int seed)
{
	if (kNetVersion < NET_VERSION_KOF98_MOOD || seed == 0 || strcmp(BurnDrvGetTextA(DRV_NAME), "kof98") != 0) return;
	srand(seed);
	for (int address = 0x001000A1; address <= 0x001000C2; address++) {
		WriteValueAtHardwareAddress(address, (unsigned int)(rand() % 3), 1, 0);
	}
}

void MacadeDetectorLoad(const char* game, bool debug, int seed)
{
	gDetector = MacadeGameDetector();
	gDetector.debug = debug;
	std::vector<char> bytes;
	bool loaded = false;
	if (game != NULL && LoadDetectorFile(game, &bytes)) {
		char* line = bytes.data();
		while (line != NULL && *line != 0) {
			char* next = strchr(line, '\n');
			if (next != NULL) *next++ = 0;
			char* cr = strchr(line, '\r');
			if (cr != NULL) *cr = 0;
			char target[64], name[64], area[64], op[16];
			unsigned int pointer = 0, value = 0, bits = 0;
			if (sscanf(line, "%63[^=]=%63[^,],%63[^,],%15[^,],0x%X,%u,%u", target, name, area, op, &pointer, &value, &bits) == 7) {
				if (strcmp(target, "start") == 0) { gDetector.start.push_back(MacadeDetectorRule()); LoadRule(&gDetector.start.back(), name, area, op, pointer, value, bits); gDetector.rawDetector = strcmp(area, "raw") == 0; }
				else if (strcmp(target, "player1") == 0) { gDetector.player1.push_back(MacadeDetectorRule()); LoadRule(&gDetector.player1.back(), name, area, op, pointer, value, bits); }
				else if (strcmp(target, "player2") == 0) { gDetector.player2.push_back(MacadeDetectorRule()); LoadRule(&gDetector.player2.back(), name, area, op, pointer, value, bits); }
				else if (strcmp(target, "char1") == 0) LoadRule(&gDetector.char1, name, area, op, pointer, value, bits);
				else if (strcmp(target, "char2") == 0) LoadRule(&gDetector.char2, name, area, op, pointer, value, bits);
				loaded = true;
			}
			line = next;
		}
	}
	if (loaded) {
		MacadeDetectorSetState(MacadeGameDetector::WaitStart, 0, 0);
		MacadeOverlaySetScores(0, 0);
		gDetector.running = true;
		MacadeLog("Macade detector: loaded game=%s rules start=%lu p1=%lu p2=%lu\n", game, (unsigned long)gDetector.start.size(), (unsigned long)gDetector.player1.size(), (unsigned long)gDetector.player2.size());
	} else {
		MacadeDetectorSetState(MacadeGameDetector::None, 0, 0);
		MacadeLog("Macade detector: no detector file for game=%s\n", game == NULL ? "" : game);
	}
	ApplyKOF98MoodSeed(seed);
}

void MacadeDetectorUpdate()
{
	gDetector.frameTime++;
	gDetector.winner = 0;
	if (!gDetector.running || gDetector.state == MacadeGameDetector::None) return;
	if (gDetector.rawDetector) UpdateRules(NULL, true);
	else { BurnAcb = DetectorScan; BurnAreaScan(ACB_MEMORY_RAM | ACB_READ, NULL); }

	bool startDetected = false;
	for (size_t i = 0; i < gDetector.start.size(); i++) startDetected = startDetected || gDetector.start[i].detected();
	if (gDetector.state == MacadeGameDetector::WaitStart && startDetected) {
		MacadeDetectorSetState(MacadeGameDetector::WaitWinner, gDetector.score1, gDetector.score2);
	} else if (gDetector.state == MacadeGameDetector::WaitWinner && gDetector.frameTime - gDetector.frameStart > kStartFrames) {
		bool p1 = false, p2 = false;
		for (size_t i = 0; i < gDetector.player1.size(); i++) p1 = p1 || gDetector.player1[i].detected();
		for (size_t i = 0; i < gDetector.player2.size(); i++) p2 = p2 || gDetector.player2[i].detected();
		if (p1) { gDetector.score1++; gDetector.winner = 1; MacadeDetectorSetState(MacadeGameDetector::WaitStart, gDetector.score1, gDetector.score2); }
		if (p2) { gDetector.score2++; gDetector.winner = 2; MacadeDetectorSetState(MacadeGameDetector::WaitStart, gDetector.score1, gDetector.score2); }
		if (gDetector.winner != 0) {
			MacadeOverlaySetScores(gDetector.score1, gDetector.score2);
			ggpo_client_set_game_event(ggpo, GGPOCLIENT_GAMEEVENT_PLAYER_1_SCORE, &gDetector.score1);
			ggpo_client_set_game_event(ggpo, GGPOCLIENT_GAMEEVENT_PLAYER_2_SCORE, &gDetector.score2);
			SendWinnerIfNeeded(gDetector.winner);
		}
	}
}

void MacadeDetectorSetState(int state, int score1, int score2, int start1, int start2)
{
	if (state == MacadeGameDetector::WaitStart) gDetector.frameStart = gDetector.frameTime;
	gDetector.state = (MacadeGameDetector::State)state;
	gDetector.score1 = score1;
	gDetector.score2 = score2;
	if (!gDetector.player1.empty() && start1 != 0) gDetector.player1[0].start = (unsigned int)start1;
	if (!gDetector.player2.empty() && start2 != 0) gDetector.player2[0].start = (unsigned int)start2;
	MacadeOverlaySetScores(score1, score2);
}

void MacadeDetectorGetState(int& state, int& score1, int& score2, int& start1, int& start2)
{
	state = gDetector.state;
	score1 = gDetector.score1;
	score2 = gDetector.score2;
	start1 = gDetector.player1.empty() ? 0 : (int)gDetector.player1[0].start;
	start2 = gDetector.player2.empty() ? 0 : (int)gDetector.player2[0].start;
}
