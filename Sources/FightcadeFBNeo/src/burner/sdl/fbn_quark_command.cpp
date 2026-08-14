#include "fbn_quark_command.h"

#include <charconv>
#include <cctype>
#include <string_view>
#include <utility>
#include <vector>

namespace {

constexpr size_t kMaximumTokenLength = 127;
constexpr size_t kMaximumReplayPathLength = 4096;

bool fail(std::string *error, const char *message)
{
   if (error != nullptr) {
      *error = message;
   }
   return false;
}

std::vector<std::string_view> split(std::string_view text)
{
   std::vector<std::string_view> fields;
   size_t start = 0;
   while (true) {
      const size_t separator = text.find(',', start);
      fields.push_back(text.substr(start, separator == std::string_view::npos ? separator : separator - start));
      if (separator == std::string_view::npos) {
         return fields;
      }
      start = separator + 1;
   }
}

bool parse_int(std::string_view text, int minimum, int maximum, int *value)
{
   if (text.empty() || value == nullptr) {
      return false;
   }
   int parsed = 0;
   const auto result = std::from_chars(text.data(), text.data() + text.size(), parsed);
   if (result.ec != std::errc() || result.ptr != text.data() + text.size() || parsed < minimum || parsed > maximum) {
      return false;
   }
   *value = parsed;
   return true;
}

bool valid_token(std::string_view text)
{
   if (text.empty() || text.size() > kMaximumTokenLength || text == "." || text == "..") {
      return false;
   }
   for (unsigned char character : text) {
      if (!std::isalnum(character) && character != '-' && character != '_' && character != '.') {
         return false;
      }
   }
   return true;
}

bool valid_host(std::string_view text)
{
   return valid_token(text);
}

bool valid_player_quark_id(std::string_view text, int *player)
{
   if (!valid_token(text) || text.size() < 3 || text[text.size() - 2] != '.' ||
       (text.back() != '0' && text.back() != '1')) {
      return false;
   }
   *player = text.back() - '0';
   return true;
}

bool valid_replay_path(std::string_view path)
{
   if (path.empty() || path.size() > kMaximumReplayPathLength) {
      return false;
   }
   for (unsigned char character : path) {
      if (character < 0x20 || character == 0x7f) {
         return false;
      }
   }
   return true;
}

} // namespace

bool ParseQuarkCommand(const char *text, QuarkCommand *command, std::string *error)
{
   if (text == nullptr || command == nullptr) {
      return fail(error, "missing command");
   }
   const std::string_view value(text);
   constexpr std::string_view replay_prefix = "quark:replay,";
   if (value.substr(0, replay_prefix.size()) == replay_prefix) {
      const std::string_view path = value.substr(replay_prefix.size());
      if (!valid_replay_path(path)) {
         return fail(error, "invalid replay path");
      }
      *command = {};
      command->type = QuarkCommandType::replay;
      command->replay_path.assign(path);
      return true;
   }

   const std::vector<std::string_view> fields = split(value);
   QuarkCommand parsed;
   if (fields.empty()) {
      return fail(error, "missing route");
   }
   if (fields[0] == "quark:served") {
      if (fields.size() != 6 || !valid_token(fields[1]) || !valid_player_quark_id(fields[2], &parsed.player) ||
          !parse_int(fields[3], 1, 65535, &parsed.port) || !parse_int(fields[4], 0, 20, &parsed.delay) ||
          !parse_int(fields[5], 0, 255, &parsed.ranked)) {
         return fail(error, "invalid served command");
      }
      parsed.type = QuarkCommandType::served;
      parsed.game.assign(fields[1]);
      parsed.quark_id.assign(fields[2]);
   } else if (fields[0] == "quark:training") {
      if (fields.size() != 5 || !valid_token(fields[1]) || !valid_player_quark_id(fields[2], &parsed.player) ||
          !parse_int(fields[3], 1, 65535, &parsed.port) || !parse_int(fields[4], 0, 20, &parsed.delay)) {
         return fail(error, "invalid training command");
      }
      parsed.type = QuarkCommandType::training;
      parsed.game.assign(fields[1]);
      parsed.quark_id.assign(fields[2]);
   } else if (fields[0] == "quark:direct") {
      if (fields.size() != 8 || !valid_token(fields[1]) || !parse_int(fields[2], 1, 65535, &parsed.local_port) ||
          !valid_host(fields[3]) || !parse_int(fields[4], 1, 65535, &parsed.remote_port) ||
          !parse_int(fields[5], 0, 1, &parsed.player) || !parse_int(fields[6], 0, 20, &parsed.delay) ||
          !parse_int(fields[7], 0, 255, &parsed.ranked)) {
         return fail(error, "invalid direct command");
      }
      parsed.type = QuarkCommandType::direct;
      parsed.game.assign(fields[1]);
      parsed.host.assign(fields[3]);
   } else if (fields[0] == "quark:stream") {
      if (fields.size() != 4 || !valid_token(fields[1]) || !valid_token(fields[2]) ||
          !parse_int(fields[3], 1, 65535, &parsed.remote_port)) {
         return fail(error, "invalid stream command");
      }
      parsed.type = QuarkCommandType::stream;
      parsed.game.assign(fields[1]);
      parsed.quark_id.assign(fields[2]);
   } else {
      return fail(error, "unsupported route");
   }

   *command = std::move(parsed);
   return true;
}
