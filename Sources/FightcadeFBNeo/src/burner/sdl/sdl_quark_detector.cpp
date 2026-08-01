#include "burner.h"
#include "macade_embedded.h"
#include "sdl_quark_detector.h"

#define DETECTOR_FRAMES 30
#define START_FRAMES 300
#define END_FRAMES 500

void QuarkEnd();
void QuarkSendChatCmd(char *text, char cmd);

extern int kNetVersion;

namespace {

struct Detector {
   enum EType { None, Store, MemEq, MemGts };
   int type = None;
   int frames = 0;
   bool raw = false;
   char name[64] = {};
   char area[64] = {};
   unsigned int memory_ptr = 0;
   unsigned int memory_value = 0;
   unsigned int memory_bits = 0;
   unsigned int memory_start = 0;
   unsigned int memory_current = 0;

   bool IsOk() const { return type != None; }
   bool Detected() const { return frames >= DETECTOR_FRAMES; }
   static int GetType(const char *str)
   {
      if (!strcmp(str, "eq")) return MemEq;
      if (!strcmp(str, "gts")) return MemGts;
      return Store;
   }
   void Load(const char *_name, const char *_area, unsigned int _ptr, unsigned int _type, unsigned int _value, unsigned int _bits)
   {
      strcpy(name, _name);
      strcpy(area, _area);
      type = _type;
      raw = !strcmp(_area, "raw");
      memory_ptr = _ptr;
      memory_value = _value;
      memory_bits = _bits;
      memory_start = 0;
      memory_current = 0;
   }
   void Update(const BurnArea *area_ptr, bool start_detected)
   {
      if (area_ptr && strcmp(area_ptr->szName, area)) return;
      if (!area_ptr && !raw) return;
      if (area_ptr) {
         switch (memory_bits) {
            case 32: memory_current = ((unsigned int *)area_ptr->Data)[memory_ptr >> 2]; break;
            case 16: memory_current = ((unsigned short *)area_ptr->Data)[memory_ptr >> 1]; break;
            default: memory_current = ((unsigned char *)area_ptr->Data)[memory_ptr]; break;
         }
      } else {
         switch (memory_bits) {
            case 32: memory_current = ReadValueAtHardwareAddress(memory_ptr, 4, 0); break;
            case 16: memory_current = ReadValueAtHardwareAddress(memory_ptr, 2, 0); break;
            default: memory_current = ReadValueAtHardwareAddress(memory_ptr, 1, 0); break;
         }
      }
      if (start_detected) memory_start = memory_current;
      bool found = false;
      if (type == MemEq) found = memory_current == memory_value;
      if (type == MemGts && !start_detected) found = memory_current > memory_start;
      frames = found ? frames + 1 : 0;
   }
};

struct GameDetector {
   enum { ST_NONE, ST_WAIT_START, ST_WAIT_WINNER, ST_WAIT_END };
   int state = ST_NONE;
   int frame_start = 0;
   int frame_end = 0;
   bool raw_detector = false;
   bool run_detector = false;
   int score1 = 0;
   int score2 = 0;
   int winner = 0;
   std::vector<Detector> dStart;
   std::vector<Detector> dPlayer1;
   std::vector<Detector> dPlayer2;
   Detector dChar1;
   Detector dChar2;

   void Load(const char *game);
   void Update();
   void UpdateDetectors(BurnArea *area, bool detect_start);
};

GameDetector game_detector;
bool debug_mode = false;
int frame_time = 0;
int game_spectator = 0;
int game_ranked = 0;

int __cdecl UpdateDetectorMemory(BurnArea *area);

int LoadDetectorFile(char *data, int size, const char *game)
{
   char path[MAX_PATH];
   const char *runtime = getenv("MACADE_FIGHTCADE_RUNTIME");
   if (runtime && runtime[0]) {
      snprintf(path, sizeof(path), "%s/detector/%s.inf", runtime, game);
   } else {
      snprintf(path, sizeof(path), "detector/%s.inf", game);
   }
   FILE *file = fopen(path, "rb");
   if (!file) return 0;
   int len = static_cast<int>(fread(data, 1, size - 1, file));
   fclose(file);
   data[len] = 0;
   return len;
}

void GameDetector::Load(const char *game)
{
   *this = GameDetector();
   char data[2048];
   bool loaded = false;
   int data_len = LoadDetectorFile(data, sizeof(data), game);
   if (data_len > 0) {
      const char *ini = data;
      const char *end = data + data_len;
      while (ini && ini < end) {
         char line[256];
         const char *pos = strstr(ini, "\n");
         snprintf(line, sizeof(line), "%.*s", static_cast<int>(pos ? pos - ini : end - ini), ini);
         ini = pos ? pos + 1 : NULL;

         char target[64], name[64], area[64], op[16];
         unsigned int ptr, value, bits;
         if (sscanf(line, "%63[^=]=%63[^,],%63[^,],%15[^,],0x%X,%u,%u", target, name, area, op, &ptr, &value, &bits) == 7) {
            int type = Detector::GetType(op);
            if (!strcmp(target, "start")) {
               dStart.push_back(Detector());
               dStart.back().Load(name, area, ptr, type, value, bits);
               raw_detector = !strcmp(area, "raw");
            } else if (!strcmp(target, "player1")) {
               dPlayer1.push_back(Detector());
               dPlayer1.back().Load(name, area, ptr, type, value, bits);
            } else if (!strcmp(target, "player2")) {
               dPlayer2.push_back(Detector());
               dPlayer2.back().Load(name, area, ptr, type, value, bits);
            } else if (!strcmp(target, "char1")) {
               dChar1.Load(name, area, ptr, type, value, bits);
            } else if (!strcmp(target, "char2")) {
               dChar2.Load(name, area, ptr, type, value, bits);
            }
            loaded = true;
         }
      }
   }
   DetectorSetState(loaded ? ST_WAIT_START : ST_NONE, 0, 0);
   run_detector = loaded;
}

void GameDetector::Update()
{
   if (state == ST_NONE && !debug_mode) return;
   winner = 0;
   if (raw_detector) {
      UpdateDetectors(NULL, true);
   } else {
      BurnAcb = UpdateDetectorMemory;
      BurnAreaScan(ACB_MEMORY_RAM | ACB_READ, NULL);
   }

   BurnInputInfo info{};
   for (unsigned int i = 0; i < nGameInpCount; i++) {
      BurnDrvGetInputInfo(&info, i);
      auto *pgi = &GameInp[i];
      if (pgi->nInput == GIT_SWITCH && pgi->Input.pVal && !strcmp(info.szInfo, "reset") && *pgi->Input.pVal) {
         state = ST_WAIT_START;
      }
   }

   bool start_detected = false;
   for (size_t i = 0; i < dStart.size(); i++) start_detected |= dStart[i].Detected();
   if (state == ST_WAIT_START && start_detected) {
      DetectorSetState(ST_WAIT_WINNER, score1, score2);
   } else if (state == ST_WAIT_WINNER && (frame_time - frame_start) > START_FRAMES) {
      bool player1_detected = false;
      bool player2_detected = false;
      for (size_t i = 0; i < dPlayer1.size(); i++) player1_detected |= dPlayer1[i].Detected();
      for (size_t i = 0; i < dPlayer2.size(); i++) player2_detected |= dPlayer2[i].Detected();
      if (player1_detected && !player2_detected) {
         score1++;
         DetectorSetState(ST_WAIT_START, score1, score2);
         winner = 1;
      } else if (player2_detected && !player1_detected) {
         score2++;
         DetectorSetState(ST_WAIT_START, score1, score2);
         winner = 2;
      }
   }
   if (game_ranked > 1 && (score1 == game_ranked || score2 == game_ranked)) frame_end = frame_time;
}

void GameDetector::UpdateDetectors(BurnArea *area, bool detect_start)
{
   bool start_detected = false;
   for (size_t i = 0; i < dStart.size(); i++) {
      dStart[i].Update(area, false);
      start_detected |= dStart[i].Detected() && detect_start;
   }
   for (size_t i = 0; i < dPlayer1.size(); i++) dPlayer1[i].Update(area, start_detected);
   for (size_t i = 0; i < dPlayer2.size(); i++) dPlayer2[i].Update(area, start_detected);
   if (dChar1.IsOk()) dChar1.Update(area, start_detected);
   if (dChar2.IsOk()) dChar2.Update(area, start_detected);
}

int __cdecl UpdateDetectorMemory(BurnArea *area)
{
   bool two_player = true;
   if (!strcmp(BurnDrvGetTextA(DRV_NAME), "ssf2xjr1") && !strcmp("CpsRamFF", area->szName)) {
      if (ReadValueAtHardwareAddress(0xFF82F6, 1, 0)) {
         BurnInputInfo info{};
         int addr = 0xE18A;
         while (((unsigned char *)area->Data)[addr] == 0xFF && addr <= 0xE199) addr++;
         if (addr <= 0xE199) {
            if (((unsigned char *)area->Data)[0x87DC] == 0) {
               BurnDrvGetInputInfo(&info, 0);
               if (info.pVal && *info.pVal) ((unsigned char *)area->Data)[addr] = ((unsigned char *)area->Data)[0x84F0];
            }
            if (((unsigned char *)area->Data)[0x8BDC] == 0) {
               BurnDrvGetInputInfo(&info, 12);
               if (info.pVal && *info.pVal) ((unsigned char *)area->Data)[addr] = ((unsigned char *)area->Data)[0x88F0];
            }
         }
      }
      if (((unsigned char *)area->Data)[0x87DC] == 0 || ((unsigned char *)area->Data)[0x8BDC] == 0) two_player = false;
   }

   if (kNetVersion >= NET_VERSION_SFA3_STAGE && !strcmp(BurnDrvGetTextA(DRV_NAME), "sfa3")) {
      const char stages[] = { 0,2,4,6,8,10,12,14,16,18,42,22,24,26,28,30,32,34,0,34,0,42,44,0,48,50,52,54,56,58,42,42 };
      BurnInputInfo info{};
      if (ReadValueAtHardwareAddress(0xFF855B, 2, 0) == 0x400) {
         BurnDrvGetInputInfo(&info, 0);
         if (info.pVal && *info.pVal) WriteValueAtHardwareAddress(0xFFFFD1, stages[ReadValueAtHardwareAddress(0xFF8502, 1, 0)] + 1, 1, 0);
      }
      if (ReadValueAtHardwareAddress(0xFF895B, 2, 0) == 0x400 && ReadValueAtHardwareAddress(0xFF855B, 2, 0) != 0x400) {
         BurnDrvGetInputInfo(&info, 12);
         if (info.pVal && *info.pVal) WriteValueAtHardwareAddress(0xFFFFD1, stages[ReadValueAtHardwareAddress(0xFF8902, 1, 0)] + 1, 1, 0);
      }
      int value = ReadValueAtHardwareAddress(0xFF8101 + 7 * 2, 2, 0);
      int stage = ReadValueAtHardwareAddress(0xFFFFD1, 1, 0) - 1;
      if (value == 0x01 && stage >= 0) {
         for (int i = 0; i < static_cast<int>(sizeof(stages)); i++) {
            if (stages[i] == stage) {
               WriteValueAtHardwareAddress(0xFF8101, stage, 1, 0);
               WriteValueAtHardwareAddress(0xFFFFD1, 0, 1, 0);
               break;
            }
         }
      }
   }

   game_detector.UpdateDetectors(area, two_player);
   return 0;
}

} // namespace

void DetectorLoad(const char *game, bool debug, int seed)
{
   debug_mode = debug;
   game_detector.Load(game);
   if (kNetVersion >= NET_VERSION_KOF98_MOOD && seed && !strcmp(BurnDrvGetTextA(DRV_NAME), "kof98")) {
      srand(seed);
      for (int i = 0x001000A1; i <= 0x001000C2; i++) WriteValueAtHardwareAddress(i, rand() % 3, 1, 0);
   }
}

void DetectorUpdate()
{
   frame_time++;
   bool enabled = game_detector.run_detector && !game_detector.frame_end && game_detector.state != GameDetector::ST_NONE;
   if (enabled) {
      game_detector.Update();
      if (game_ranked && !game_spectator && game_detector.winner != 0) {
         int char1 = game_detector.dChar1.IsOk() ? game_detector.dChar1.memory_current : -1;
         int char2 = game_detector.dChar2.IsOk() ? game_detector.dChar2.memory_current : -1;
         char temp[32];
         snprintf(temp, sizeof(temp), "%d,%d,%d,%d,%d", game_detector.winner, game_detector.score1, game_detector.score2, char1, char2);
         QuarkSendChatCmd(temp, 'W');
      }
   }
   if (game_detector.frame_end && (frame_time - game_detector.frame_end) > END_FRAMES) {
      MacadeEmbeddedSetOverlayMatchEnded();
      QuarkEnd();
   }
}

void DetectorSetGameInfo(int spectator, int ranked)
{
   game_spectator = spectator;
   game_ranked = ranked;
}

void DetectorSetState(int state, int score1, int score2, int start1, int start2)
{
   if (state == GameDetector::ST_WAIT_START) game_detector.frame_start = frame_time;
   game_detector.state = state;
   game_detector.score1 = score1;
   game_detector.score2 = score2;
   if (!game_detector.dPlayer1.empty() && start1 != 0) game_detector.dPlayer1[0].memory_start = start1;
   if (!game_detector.dPlayer2.empty() && start2 != 0) game_detector.dPlayer2[0].memory_start = start2;
}

void DetectorGetState(int &state, int &score1, int &score2, int &start1, int &start2)
{
   state = game_detector.state;
   score1 = game_detector.score1;
   score2 = game_detector.score2;
   start1 = !game_detector.dPlayer1.empty() ? game_detector.dPlayer1[0].memory_start : 0;
   start2 = !game_detector.dPlayer2.empty() ? game_detector.dPlayer2[0].memory_start : 0;
}
