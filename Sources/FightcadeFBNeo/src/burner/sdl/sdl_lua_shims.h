#pragma once

#ifndef _WIN32
#include <unistd.h>

#ifndef _MAX_PATH
#define _MAX_PATH MAX_PATH
#endif

#define _getcwd getcwd
#define _chdir chdir

#ifndef MB_OK
#define MB_OK 0
#define MB_YESNO 4
#define MB_ICONSTOP 16
#define IDYES 6
#endif

extern void* hScrnWnd;
extern int LuaConsoleHWnd;
extern bool bReplayReadOnly;
extern INT32 nReplayStatus;
extern bool bAppDoFast;

int StartFromReset(TCHAR* driverName);
void SetPauseMode(bool pause);
void StopReplay();
void EmulatorAppDoFast(bool dofast);
INT32 VidSNewShortMsg(const TCHAR* text, INT32 rgb, INT32 duration, INT32 priority);
int MessageBoxA(void*, const char* text, const char* title, unsigned int type);
short GetAsyncKeyState(int key);
void GetClientRect(void*, RECT* rect);
void PrintToWindowConsole(int, const char* str);
void WinLuaOnStart(int);
void WinLuaOnStop(int);
char* GetSavestateFilename(int slot);
#endif
