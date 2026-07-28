#include "burner.h"
#include "luaengine.h"

INT32 bRunaheadFrame = 0;

void CallRegisteredLuaFunctions(LuaCallID) {}
void CallRegisteredLuaMemHook(unsigned int, int, unsigned int, LuaMemHookType) {}
void FBA_LuaFrameBoundary() {}
int FBA_LoadLuaCode(const char*) { return 1; }
void FBA_ReloadLuaCode() {}
void FBA_LuaStop() {}
int FBA_LuaRunning() { return 0; }
int FBA_LuaUsingJoypad() { return 0; }
UINT32 FBA_LuaReadJoypad() { return 0; }
int FBA_LuaSpeed() { return 100; }
int FBA_LuaRerecordCountSkip() { return 0; }
void FBA_LuaGui(unsigned char*, int, int, int, int) {}
void FBA_LuaClearGui() {}
void FBA_LuaEnableGui(UINT8) {}
char* FBA_GetLuaScriptName() { return NULL; }
lua_State* FBA_GetLuaState() { return NULL; }
INT_PTR CALLBACK DlgLuaScriptDialog(HWND, UINT, WPARAM, LPARAM) { return 0; }
void luasav_save(const char*) {}
void luasav_load(const char*) {}

INT32 VidSNewTinyMsg(const TCHAR* pText, INT32, INT32, INT32)
{
	if (pText) UpdateMessage(const_cast<TCHAR*>(pText));
	return 0;
}

INT32 VidSNewShortMsg(const TCHAR* pText, INT32 nRGB, INT32 nDuration, INT32 nPriority)
{
	return VidSNewTinyMsg(pText, nRGB, nDuration, nPriority);
}
