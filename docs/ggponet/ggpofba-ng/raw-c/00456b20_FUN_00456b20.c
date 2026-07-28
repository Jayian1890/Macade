
void FUN_00456b20(void)

{
  HANDLE pvVar1;
  HANDLE hSourceHandle;
  HANDLE hSourceProcessHandle;
  LPHANDLE lpTargetHandle;
  DWORD dwDesiredAccess;
  BOOL bInheritHandle;
  DWORD dwOptions;
  int nPriority;
  BYTE aBStack_10c [144];
  byte bStack_7c;
  uint local_8;
  
  local_8 = DAT_00871720 ^ (uint)aBStack_10c;
  dwOptions = 2;
  bInheritHandle = 0;
  dwDesiredAccess = 0;
  lpTargetHandle = (LPHANDLE)&DAT_009e6cb8;
  pvVar1 = GetCurrentProcess();
  hSourceHandle = GetCurrentThread();
  hSourceProcessHandle = GetCurrentProcess();
  DuplicateHandle(hSourceProcessHandle,hSourceHandle,pvVar1,lpTargetHandle,dwDesiredAccess,
                  bInheritHandle,dwOptions);
  FUN_0046ea20();
  FUN_00471f40();
  kailleraInit();
  if (DAT_00b18208 < DAT_008761ec) {
    FUN_00463630();
    FUN_0046f780();
  }
  nPriority = DAT_00ad6f44;
  pvVar1 = GetCurrentThread();
  SetThreadPriority(pvVar1,nPriority);
  DAT_009eb0ee = 1;
  FUN_0052d3a0();
  FUN_00473190();
  if (3 < DAT_00b19804) {
    DAT_00b19804 = 0;
  }
  DAT_00ad7348 = LoadAcceleratorsA(DAT_00ad6f40,(LPCSTR)0xd5);
  FUN_004730e0();
  GetKeyboardState(aBStack_10c);
  if ((bStack_7c & 1) != 0) {
    keybd_event(0x90,'\0',1,0);
    keybd_event(0x90,'\0',3,0);
  }
  DAT_009e6c75 = bStack_7c & 1;
  __security_check_cookie(local_8 ^ (uint)aBStack_10c);
  return;
}
