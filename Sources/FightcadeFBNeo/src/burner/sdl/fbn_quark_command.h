#pragma once

#include <string>

enum class QuarkCommandType {
   served,
   training,
   direct,
   stream,
   replay,
};

struct QuarkCommand {
   QuarkCommandType type = QuarkCommandType::served;
   std::string game;
   std::string quark_id;
   std::string host;
   std::string replay_path;
   int port = 0;
   int local_port = 0;
   int remote_port = 0;
   int player = 0;
   int delay = 0;
   int ranked = 0;
};

bool ParseQuarkCommand(const char *text, QuarkCommand *command, std::string *error = nullptr);
