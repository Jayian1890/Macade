#include "burner.h"

#include <strings.h>

namespace {

constexpr int kMaxPlayers = 4;
constexpr int kInputSize = 8 * (4 + 8);

int player_inputs[kMaxPlayers];
int common_inputs;
int dip_inputs;
int player_offset[kMaxPlayers];
int common_offset;
int dip_offset;
unsigned char controls[kInputSize];

bool is_player_input(const BurnInputInfo &info, int player)
{
   char prefix[3] = {'P', static_cast<char>('1' + player), 0};
   return strncasecmp(info.szName, prefix, 2) == 0;
}

bool common_input_allowed(const BurnInputInfo &info)
{
   if (!kNetGame) {
      return true;
   }
   const bool allow_reset = strcmp(BurnDrvGetTextA(DRV_NAME), "sf2hf") == 0 &&
                            kNetVersion >= NET_VERSION_RESET_SF2HF;
   return strcmp(info.szName, "Tilt") != 0 &&
          (strcmp(info.szName, "Reset") != 0 || allow_reset) &&
          strcmp(info.szName, "Diagnostic") != 0 &&
          strcmp(info.szName, "Service") != 0 &&
          strcmp(info.szName, "Test") != 0;
}

} // namespace

int NetworkInitInput()
{
   if (nGameInpCount == 0) {
      return 1;
   }

   BurnInputInfo info{};
   unsigned int index = 0;
   player_offset[0] = 0;
   do {
      BurnDrvGetInputInfo(&info, index++);
   } while (is_player_input(info, 0) && index <= nGameInpCount);
   index--;
   player_inputs[0] = index - player_offset[0];

   for (int player = 1; player < kMaxPlayers; player++) {
      player_offset[player] = index;
      while (is_player_input(info, player) && index < nGameInpCount) {
         BurnDrvGetInputInfo(&info, ++index);
      }
      player_inputs[player] = index - player_offset[player];
   }

   common_offset = index;
   while ((info.nType & BIT_GROUP_CONSTANT) == 0 && index < nGameInpCount) {
      BurnDrvGetInputInfo(&info, ++index);
   }
   common_inputs = index - common_offset;
   dip_offset = index;
   dip_inputs = nGameInpCount - dip_offset;
   return 0;
}

int NetworkGetInput()
{
   BurnInputInfo info{};
   memset(controls, 0, sizeof(controls));

   int bit = 0;
   for (int i = 0; i < player_inputs[0]; i++, bit++) {
      BurnDrvGetInputInfo(&info, i + player_offset[0]);
      if (*info.pVal && info.nType == BIT_DIGITAL) {
         controls[bit >> 3] |= 1 << (bit & 7);
      }
   }
   for (int i = 0; i < common_inputs; i++, bit++) {
      BurnDrvGetInputInfo(&info, i + common_offset);
      if (*info.pVal && common_input_allowed(info)) {
         controls[bit >> 3] |= 1 << (bit & 7);
      }
   }

   int byte_count = (bit + 7) >> 3;
   for (int i = 0; i < player_inputs[0]; i++) {
      BurnDrvGetInputInfo(&info, i + player_offset[0]);
      if (*info.pVal && info.nType != BIT_DIGITAL) {
         if (info.nType & BIT_GROUP_ANALOG) {
            controls[byte_count++] = *info.pShortVal >> 8;
            controls[byte_count++] = *info.pShortVal & 0xff;
         } else {
            controls[byte_count++] = *info.pVal;
         }
      }
   }
   for (int i = 0; i < dip_inputs; i++, byte_count++) {
      BurnDrvGetInputInfo(&info, i + dip_offset);
      controls[byte_count] = *info.pVal;
   }

   const int player_size = byte_count + 1;
   if (kNetGame && !QuarkGetInput(controls, player_size, kMaxPlayers)) {
      return 1;
   }

   bit = 0;
   for (int i = 0; i < player_inputs[0]; i++, bit++) {
      BurnDrvGetInputInfo(&info, i + player_offset[0]);
      if (info.nType == BIT_DIGITAL) {
         *info.pVal = (controls[bit >> 3] & (1 << (bit & 7))) ? 1 : 0;
      }
   }
   for (int i = 0; i < common_inputs; i++, bit++) {
      BurnDrvGetInputInfo(&info, i + common_offset);
      *info.pVal = (controls[bit >> 3] & (1 << (bit & 7))) ? 1 : 0;
   }

   byte_count = (bit + 7) >> 3;
   for (int i = 0; i < player_inputs[0]; i++) {
      BurnDrvGetInputInfo(&info, i + player_offset[0]);
      if (info.nType & BIT_GROUP_ANALOG) {
         *info.pShortVal = (controls[byte_count] << 8) | controls[byte_count + 1];
         byte_count += 2;
      }
   }
   for (int i = 0; i < dip_inputs; i++, byte_count++) {
      BurnDrvGetInputInfo(&info, i + dip_offset);
      *info.pVal = controls[byte_count];
   }

   for (int player = 1; player < kMaxPlayers; player++) {
      int offset = player_size * (player << 3);
      for (int i = 0; i < player_inputs[player]; i++, offset++) {
         BurnDrvGetInputInfo(&info, i + player_offset[player]);
         if (info.nType == BIT_DIGITAL) {
            *info.pVal = (controls[offset >> 3] & (1 << (offset & 7))) ? 1 : 0;
         }
      }
   }
   return 0;
}
