
/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 2008 Release */

int __cdecl __mtinit(void)

{
  HMODULE hModule;
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  _ptiddata _Ptd;
  DWORD DVar4;
  
  hModule = GetModuleHandleW(L"KERNEL32.DLL");
  if (hModule == (HMODULE)0x0) {
    hModule = (HMODULE)__crt_waiting_on_module_handle(L"KERNEL32.DLL");
  }
  if (hModule != (HMODULE)0x0) {
    DAT_10039224 = GetProcAddress(hModule,"FlsAlloc");
    DAT_10039228 = GetProcAddress(hModule,"FlsGetValue");
    DAT_1003922c = GetProcAddress(hModule,"FlsSetValue");
    DAT_10039230 = GetProcAddress(hModule,"FlsFree");
    if ((((DAT_10039224 == (FARPROC)0x0) || (DAT_10039228 == (FARPROC)0x0)) ||
        (DAT_1003922c == (FARPROC)0x0)) || (DAT_10039230 == (FARPROC)0x0)) {
      DAT_10039228 = TlsGetValue_exref;
      DAT_10039224 = (FARPROC)&LAB_100171fc;
      DAT_1003922c = TlsSetValue_exref;
      DAT_10039230 = TlsFree_exref;
    }
    DAT_100377f4 = TlsAlloc();
    if (DAT_100377f4 == 0xffffffff) {
      return 0;
    }
    BVar1 = TlsSetValue(DAT_100377f4,DAT_10039228);
    if (BVar1 == 0) {
      return 0;
    }
    __init_pointers();
    DAT_10039224 = (FARPROC)__encode_pointer(DAT_10039224);
    DAT_10039228 = (FARPROC)__encode_pointer(DAT_10039228);
    DAT_1003922c = (FARPROC)__encode_pointer(DAT_1003922c);
    DAT_10039230 = (FARPROC)__encode_pointer(DAT_10039230);
    iVar2 = __mtinitlocks();
    if (iVar2 != 0) {
      pcVar3 = (code *)__decode_pointer(DAT_10039224,__freefls_4);
      DAT_100377f0 = (*pcVar3)();
      if ((DAT_100377f0 != -1) && (_Ptd = __calloc_crt(1,0x214), _Ptd != (_ptiddata)0x0)) {
        pcVar3 = (code *)__decode_pointer(DAT_1003922c,DAT_100377f0,_Ptd);
        iVar2 = (*pcVar3)();
        if (iVar2 != 0) {
          __initptd(_Ptd,(pthreadlocinfo)0x0);
          DVar4 = GetCurrentThreadId();
          _Ptd->_thandle = 0xffffffff;
          _Ptd->_tid = DVar4;
          return 1;
        }
      }
    }
  }
  __mtterm();
  return 0;
}
