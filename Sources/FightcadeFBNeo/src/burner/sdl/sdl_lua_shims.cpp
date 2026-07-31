#include "burner.h"
#include "sdl_lua_shims.h"

#ifndef _WIN32
void* hScrnWnd = NULL;
int LuaConsoleHWnd = 0;
bool bReplayReadOnly = false;

void EmulatorAppDoFast(bool dofast)
{
   bAppDoFast = dofast;
}

int StartFromReset(TCHAR* driverName)
{
   if (driverName != NULL) {
      for (UINT32 i = 0; i < nBurnDrvCount; i++) {
         nBurnDrvActive = i;
         if (!_tcscmp(BurnDrvGetText(DRV_NAME), driverName) && !(BurnDrvGetFlags() & BDF_BOARDROM)) {
            return DrvInit(i, true) == 0;
         }
      }
      return 0;
   }
   return DrvInit(nBurnDrvActive, true) == 0;
}

void SetPauseMode(bool pause)
{
   bRunPause = pause;
}

void StopReplay()
{
   nReplayStatus = 0;
   bReplayReadOnly = false;
}

INT32 VidSNewShortMsg(const TCHAR* text, INT32, INT32, INT32)
{
   if (text != NULL) UpdateMessage((char*)text);
   return 0;
}

int MessageBoxA(void*, const char* text, const char* title, unsigned int)
{
   fprintf(stderr, "%s: %s\n", title ? title : "Lua", text ? text : "");
   return IDYES;
}

short GetAsyncKeyState(int)
{
   return 0;
}

void GetClientRect(void*, RECT* rect)
{
   if (rect == NULL) return;
   rect->left = 0;
   rect->top = 0;
   rect->right = nVidImageWidth;
   rect->bottom = nVidImageHeight;
}

void PrintToWindowConsole(int, const char* str)
{
   if (str != NULL) fputs(str, stdout);
}

void WinLuaOnStart(int) {}
void WinLuaOnStop(int) {}

char* GetSavestateFilename(int slot)
{
   static char path[MAX_PATH];
   static char* savePath = NULL;

#if defined(BUILD_SDL2) && !defined(SDL_WINDOWS)
   if (savePath == NULL) savePath = SDL_GetPrefPath("fbneo", "states");
   snprintf(path, sizeof(path), "%s%s slot %02x.fs", savePath ? savePath : "", BurnDrvGetText(DRV_NAME), slot);
#else
   snprintf(path, sizeof(path), "config/games/%s slot %02x.fs", BurnDrvGetText(DRV_NAME), slot);
#endif

   return path;
}
#endif
