#include "ggpomac_internal.h"
#include "macade_overlay.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <algorithm>
#include <string>
#include <vector>
#include <zlib.h>

struct ReplayMetadata {
	std::string version;
	std::string game;
	int payloadSize = 0;
	int compressedSize = 0;
	int stateSize = 0;
	int inputSize = 0;
	int inputCount = 0;
};

static bool AppendText(char* text, size_t textSize, int* offset, const char* format, ...)
{
	if (text == NULL || offset == NULL || *offset < 0 || (size_t)*offset >= textSize) return false;
	va_list args;
	va_start(args, format);
	int written = vsnprintf(text + *offset, textSize - (size_t)*offset, format, args);
	va_end(args);
	if (written < 0) return false;
	*offset += written;
	return (size_t)*offset < textSize;
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
	if (session == NULL || session->tcpFd < 0) return false;
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

static void CopyText(char* out, size_t outSize, const char* value)
{
	if (out == NULL || outSize == 0) return;
	if (value == NULL) value = "";
	snprintf(out, outSize, "%s", value);
}

static bool ReadReplayFile(const char* path, std::vector<unsigned char>* bytes)
{
	if (path == NULL || bytes == NULL) return false;
	FILE* file = fopen(path, "rb");
	if (file == NULL) return false;
	if (fseek(file, 0, SEEK_END) != 0) { fclose(file); return false; }
	long length = ftell(file);
	if (length <= 0) { fclose(file); return false; }
	if (fseek(file, 0, SEEK_SET) != 0) { fclose(file); return false; }
	bytes->assign((size_t)length, 0);
	size_t read = fread(bytes->data(), 1, (size_t)length, file);
	fclose(file);
	return read == (size_t)length;
}

static bool ParseInteger(const char* value, int* out)
{
	if (value == NULL || out == NULL) return false;
	char* end = NULL;
	long parsed = strtol(value, &end, 10);
	if (end == value || *end != 0 || parsed < 0 || parsed > INT32_MAX) return false;
	*out = (int)parsed;
	return true;
}

static void ApplyReplayMetadataLine(ReplayMetadata* metadata, const char* key, const char* value)
{
	if (metadata == NULL || key == NULL || value == NULL) return;
	if (strcmp(key, "version") == 0) metadata->version = value;
	else if (strcmp(key, "game") == 0) metadata->game = value;
	else if (strcmp(key, "payload size") == 0) ParseInteger(value, &metadata->payloadSize);
	else if (strcmp(key, "compressed state size") == 0) ParseInteger(value, &metadata->compressedSize);
	else if (strcmp(key, "state size") == 0) ParseInteger(value, &metadata->stateSize);
	else if (strcmp(key, "input size") == 0) ParseInteger(value, &metadata->inputSize);
	else if (strcmp(key, "input count") == 0) ParseInteger(value, &metadata->inputCount);
}

static bool ParseReplayMetadata(const char* text, ReplayMetadata* metadata)
{
	if (text == NULL || metadata == NULL || strncmp(text, "GGPOTV\n", 7) != 0) return false;
	const char* line = strchr(text, '\n');
	while (line != NULL && *line != 0) {
		line++;
		if (*line == 0) break;
		const char* tab = strchr(line, '\t');
		const char* newline = strchr(line, '\n');
		if (tab == NULL || newline == NULL || tab > newline) break;
		std::string key(line, tab - line);
		std::string value(tab + 1, newline - tab - 1);
		ApplyReplayMetadataLine(metadata, key.c_str(), value.c_str());
		line = newline;
	}
	return metadata->version == "0.20" && !metadata->game.empty() && metadata->payloadSize > 0
		&& metadata->compressedSize > 0 && metadata->stateSize > 0 && metadata->inputSize > 0
		&& metadata->inputCount >= 0 && metadata->payloadSize >= metadata->stateSize;
}

bool MacadeLoadReplayFile(GGPOSession* session, const char* path)
{
	if (session == NULL) return false;
	std::vector<unsigned char> file;
	if (!ReadReplayFile(path, &file)) return false;
	std::vector<unsigned char>::iterator nul = std::find(file.begin(), file.end(), 0);
	if (nul == file.end()) return false;
	ReplayMetadata metadata;
	if (!ParseReplayMetadata((const char*)file.data(), &metadata)) return false;
	size_t compressedOffset = (size_t)(nul - file.begin()) + 1;
	if (compressedOffset + (size_t)metadata.compressedSize > file.size()) return false;
	std::vector<unsigned char> payload((size_t)metadata.payloadSize, 0);
	uLongf payloadLength = (uLongf)payload.size();
	int result = uncompress(payload.data(), &payloadLength, file.data() + compressedOffset, (uLong)metadata.compressedSize);
	if (result != Z_OK || payloadLength != (uLongf)metadata.payloadSize) return false;
	if ((metadata.payloadSize - metadata.stateSize) / metadata.inputSize < metadata.inputCount) return false;

	CopyText(session->gameName, sizeof(session->gameName), metadata.game.c_str());
	session->isReplayPlayback = true;
	session->inputSize = metadata.inputSize;
	session->replayInputSize = metadata.inputSize;
	session->replayReadFrame = 0;
	session->replayInitialStateLoaded = false;
	session->replayInitialState.assign(payload.begin(), payload.begin() + metadata.stateSize);
	session->replayInputs.clear();
	for (int frame = 0; frame < metadata.inputCount; frame++) {
		size_t offset = (size_t)metadata.stateSize + (size_t)frame * (size_t)metadata.inputSize;
		session->replayInputs.push_back(std::vector<unsigned char>(payload.begin() + offset, payload.begin() + offset + metadata.inputSize));
	}
	if (session->callbacks.begin_game != NULL) session->callbacks.begin_game(session->gameName);
	MacadeLog("Macade GGPO: replay loaded game=%s inputs=%d inputSize=%d state=%d\n", session->gameName, metadata.inputCount, metadata.inputSize, metadata.stateSize);
	return true;
}

bool MacadeReadReplayGameName(const char* path, char* out, size_t outSize)
{
	if (out == NULL || outSize == 0) return false;
	out[0] = 0;
	std::vector<unsigned char> file;
	if (!ReadReplayFile(path, &file)) return false;
	std::vector<unsigned char>::iterator nul = std::find(file.begin(), file.end(), 0);
	if (nul == file.end()) return false;
	ReplayMetadata metadata;
	if (!ParseReplayMetadata((const char*)file.data(), &metadata)) return false;
	CopyText(out, outSize, metadata.game.c_str());
	return out[0] != 0;
}

bool MacadeLoadReplayInitialStateIfNeeded(GGPOSession* session)
{
	if (session == NULL || !session->isReplayPlayback) return false;
	if (session->replayInitialStateLoaded) return true;
	if (session->callbacks.load_game_state != NULL && !session->replayInitialState.empty()) {
		if (!session->callbacks.load_game_state(session->replayInitialState.data(), (int)session->replayInitialState.size())) {
			session->fatalDesync = true;
			return false;
		}
	}
	session->replayInitialStateLoaded = true;
	MacadeLog("Macade GGPO: replay initial state applied game=%s bytes=%zu\n", session->gameName, session->replayInitialState.size());
	return true;
}

static bool CaptureInitialState(GGPOSession* session)
{
	if (session == NULL || !session->replayArmed || !session->replayInitialState.empty()) return true;
	if (session->callbacks.save_game_state == NULL) return false;
	unsigned char* state = NULL;
	int stateLength = 0;
	int checksum = 0;
	if (!session->callbacks.save_game_state(&state, &stateLength, &checksum, session->currentFrame) || state == NULL || stateLength <= 0) {
		if (state != NULL && session->callbacks.free_buffer != NULL) session->callbacks.free_buffer(state);
		else if (state != NULL) free(state);
		return false;
	}
	session->replayInitialState.assign(state, state + stateLength);
	if (session->callbacks.free_buffer != NULL) session->callbacks.free_buffer(state);
	else free(state);
	MacadeLog("Macade GGPO: replay baseline captured frame=%d bytes=%d checksum=%d\n", session->currentFrame, stateLength, checksum);
	return true;
}

static void ArmReplay(GGPOSession* session)
{
	if (session == NULL || session->isSpectator || session->isReplayPlayback || session->tcpFd < 0 || session->quarkId[0] == 0) return;
	session->replayArmed = true;
	session->replayUploaded = false;
	session->replayWinner = -1;
	session->replayInitialState.clear();
	session->replayInputs.clear();
	session->replayScores[0] = 0;
	session->replayScores[1] = 0;
	session->replayPlayerAvatar[0][0] = 0;
	session->replayPlayerAvatar[1][0] = 0;
	MacadeLog("Macade GGPO: replay upload armed series=%s game=%s\n", session->quarkId, session->gameName);
}

void MacadeReplayRecordInput(GGPOSession* session, const unsigned char* bytes, int size)
{
	if (session == NULL || session->isReplayPlayback || !session->replayArmed || session->replayUploaded || session->replaying) return;
	if (bytes == NULL || size <= 0 || size > 256) return;
	if (!CaptureInitialState(session)) return;
	session->replayInputs.push_back(std::vector<unsigned char>(bytes, bytes + size));
}

static bool BuildReplayPayload(GGPOSession* session, std::vector<unsigned char>* metadata, std::vector<unsigned char>* compressed)
{
	if (session == NULL || metadata == NULL || compressed == NULL || session->replayInputs.empty()) return false;
	if (!CaptureInitialState(session) || session->replayInitialState.empty()) return false;
	int inputSize = (int)session->replayInputs[0].size();
	if (inputSize <= 0) return false;
	std::vector<unsigned char> payload = session->replayInitialState;
	for (size_t i = 0; i < session->replayInputs.size(); i++) {
		if ((int)session->replayInputs[i].size() != inputSize) return false;
		payload.insert(payload.end(), session->replayInputs[i].begin(), session->replayInputs[i].end());
	}
	uLongf compressedLength = compressBound((uLong)payload.size());
	compressed->assign((size_t)compressedLength, 0);
	int result = compress2(compressed->data(), &compressedLength, payload.data(), (uLong)payload.size(), Z_BEST_SPEED);
	if (result != Z_OK) return false;
	compressed->resize((size_t)compressedLength);

	char text[4096];
	int offset = 0;
	if (!AppendText(text, sizeof(text), &offset, "GGPOTV\nversion\t0.20\ngame\t%s\n", session->gameName[0] ? session->gameName : "")) return false;
	if (session->streamPlayer1[0] && !AppendText(text, sizeof(text), &offset, "player 1 username\t%s\n", session->streamPlayer1)) return false;
	if (session->streamPlayer2[0] && !AppendText(text, sizeof(text), &offset, "player 2 username\t%s\n", session->streamPlayer2)) return false;
	for (int player = 0; player < 2; player++) {
		if (session->replayPlayerAvatar[player][0] == 0) continue;
		if (!AppendText(text, sizeof(text), &offset, "player %d avatar\t%s\n", player + 1, session->replayPlayerAvatar[player])) return false;
		if (!AppendText(text, sizeof(text), &offset, "player %d score\t%d\n", player + 1, session->replayScores[player])) return false;
	}
	if (!AppendText(text, sizeof(text), &offset,
		"series\t%s\nwinner\t%d\ninput size\t%d\ninput count\t%zu\nstate size\t%zu\ncompressed state size\t%zu\npayload size\t%zu\n",
		session->quarkId, session->replayWinner, inputSize, session->replayInputs.size(), session->replayInitialState.size(), compressed->size(), payload.size())) return false;
	metadata->assign(text, text + offset + 1);
	return true;
}

static bool UploadReplay(GGPOSession* session)
{
	if (session == NULL || !session->replayArmed || session->replayUploaded || session->tcpFd < 0) return false;
	std::vector<unsigned char> metadata;
	std::vector<unsigned char> compressed;
	if (!BuildReplayPayload(session, &metadata, &compressed)) {
		MacadeLog("Macade GGPO: replay upload skipped; payload unavailable inputs=%zu state=%zu\n", session->replayInputs.size(), session->replayInitialState.size());
		return false;
	}
	std::vector<unsigned char> payload;
	AppendString(payload, session->quarkId);
	payload.insert(payload.end(), metadata.begin(), metadata.end());
	payload.insert(payload.end(), compressed.begin(), compressed.end());
	MacadeLog("Macade GGPO: Sending Replay... inputs=%zu compressed=%zu\n", session->replayInputs.size(), compressed.size());
	if (!SendCommand(session, 19, payload)) {
		MacadeMarkDisconnected(session);
		return false;
	}
	session->replayUploaded = true;
	MacadeLog("Macade GGPO: Done sending Replay...\n");
	return true;
}

bool MacadeHandleGameEvent(GGPOSession* session, GGPOClientGameEventType type, void* data)
{
	if (session == NULL) return true;
	if (type == GGPOCLIENT_GAMEEVENT_STARTING) {
		ArmReplay(session);
		return true;
	}
	if (data != NULL && type >= GGPOCLIENT_GAMEEVENT_PLAYER_1 && type <= GGPOCLIENT_GAMEEVENT_PLAYER_2) {
		CopyText(session->replayPlayerAvatar[type - GGPOCLIENT_GAMEEVENT_PLAYER_1], sizeof(session->replayPlayerAvatar[0]), (const char*)data);
		return true;
	}
	int score1 = 0;
	int score2 = 0;
	MacadeOverlayGetScores(&score1, &score2);
	if (data != NULL && type == GGPOCLIENT_GAMEEVENT_PLAYER_1_SCORE) score1 = *(int*)data;
	else if (data != NULL && type == GGPOCLIENT_GAMEEVENT_PLAYER_2_SCORE) score2 = *(int*)data;
	else if (data != NULL && type == GGPOCLIENT_GAMEEVENT_WINNER) session->replayWinner = *(int*)data;
	else if (type == GGPOCLIENT_GAMEEVENT_FINISHED) { UploadReplay(session); return true; }
	if (type == GGPOCLIENT_GAMEEVENT_PLAYER_1_SCORE || type == GGPOCLIENT_GAMEEVENT_PLAYER_2_SCORE) {
		session->replayScores[0] = score1;
		session->replayScores[1] = score2;
		MacadeOverlaySetScores(score1, score2);
	}
	return true;
}
