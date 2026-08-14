#include "fbn_quark_command.h"

#include <cassert>
#include <cstdint>
#include <string>

namespace {

void test_valid_commands()
{
   QuarkCommand command;
   std::string error;

   assert(ParseQuarkCommand("quark:served,sfiii3n,1234567890-42.1,7000,2,3", &command, &error));
   assert(command.type == QuarkCommandType::served);
   assert(command.game == "sfiii3n");
   assert(command.quark_id == "1234567890-42.1");
   assert(command.port == 7000);
   assert(command.player == 1);
   assert(command.delay == 2);
   assert(command.ranked == 3);

   assert(ParseQuarkCommand("quark:training,sfiii3n,1234567890-42.0,7000,4", &command));
   assert(command.type == QuarkCommandType::training);
   assert(command.player == 0);
   assert(command.delay == 4);

   assert(ParseQuarkCommand("quark:direct,sfiii3n,6000,127.0.0.1,6001,1,2,0", &command));
   assert(command.type == QuarkCommandType::direct);
   assert(command.local_port == 6000);
   assert(command.host == "127.0.0.1");
   assert(command.remote_port == 6001);
   assert(command.player == 1);

   assert(ParseQuarkCommand("quark:stream,sfiii3n,1234567890-42.7,7100", &command));
   assert(command.type == QuarkCommandType::stream);
   assert(command.remote_port == 7100);

   assert(ParseQuarkCommand("quark:replay,/tmp/match,with-comma.fcreplay", &command));
   assert(command.type == QuarkCommandType::replay);
   assert(command.replay_path == "/tmp/match,with-comma.fcreplay");
}

void test_invalid_commands()
{
   QuarkCommand command;
   const char *invalid[] = {
      "",
      "quark:served",
      "quark:servedgarbage,sfiii3n,123.0,7000,2,0",
      "quark:served,sfiii3n,,7000,2,0",
      "quark:served,sfiii3n,123.2,7000,2,0",
      "quark:served,sfiii3n,123.0,0,2,0",
      "quark:served,sfiii3n,123.0,65536,2,0",
      "quark:served,sfiii3n,123.0,7000,2ms,0",
      "quark:served,sfiii3n,123.0,7000,21,0",
      "quark:served,sfiii3n,123.0,7000,2,256",
      "quark:served,../sfiii3n,123.0,7000,2,0",
      "quark:served,sfiii3n,123.0,7000,2,0,extra",
      "quark:training,sfiii3n,123.0,7000",
      "quark:direct,sfiii3n,6000,127.0.0.1,6001,2,2,0",
      "quark:direct,sfiii3n,6000,bad host,6001,0,2,0",
      "quark:stream,sfiii3n,123.2,0",
      "quark:replay,",
      "quark:unknown,sfiii3n",
   };
   for (const char *text : invalid) {
      assert(!ParseQuarkCommand(text, &command));
   }
   assert(!ParseQuarkCommand(nullptr, &command));
   assert(!ParseQuarkCommand("quark:stream,sfiii3n,123.2,7001", nullptr));
}

void test_parser_corpus_is_nonfatal()
{
   uint32_t state = 0x18d3a76f;
   QuarkCommand command;
   for (int iteration = 0; iteration < 10000; ++iteration) {
      state = state * 1664525U + 1013904223U;
      std::string text(state % 257U, 'a');
      for (char &character : text) {
         state = state * 1664525U + 1013904223U;
         character = static_cast<char>(1 + (state % 126U));
      }
      ParseQuarkCommand(text.c_str(), &command);
   }
}

} // namespace

int main()
{
   test_valid_commands();
   test_invalid_commands();
   test_parser_corpus_is_nonfatal();
   return 0;
}
