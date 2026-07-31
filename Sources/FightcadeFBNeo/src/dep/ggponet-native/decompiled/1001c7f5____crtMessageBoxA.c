
/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 2008 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  code *pcVar3;
  code *pcVar4;
  int iVar5;
  undefined1 local_18 [8];
  byte local_10;
  undefined1 local_c [4];
  int local_8;
  
  iVar1 = __encoded_null();
  local_8 = 0;
  if (DAT_100393c4 == 0) {
    hModule = LoadLibraryA("USER32.DLL");
    if (hModule == (HMODULE)0x0) {
      return 0;
    }
    pFVar2 = GetProcAddress(hModule,"MessageBoxA");
    if (pFVar2 == (FARPROC)0x0) {
      return 0;
    }
    DAT_100393c4 = __encode_pointer(pFVar2);
    pFVar2 = GetProcAddress(hModule,"GetActiveWindow");
    DAT_100393c8 = __encode_pointer(pFVar2);
    pFVar2 = GetProcAddress(hModule,"GetLastActivePopup");
    DAT_100393cc = __encode_pointer(pFVar2);
    pFVar2 = GetProcAddress(hModule,"GetUserObjectInformationA");
    DAT_100393d4 = __encode_pointer(pFVar2);
    if (DAT_100393d4 != 0) {
      pFVar2 = GetProcAddress(hModule,"GetProcessWindowStation");
      DAT_100393d0 = __encode_pointer(pFVar2);
    }
  }
  if ((DAT_100393d0 != iVar1) && (DAT_100393d4 != iVar1)) {
    pcVar3 = (code *)__decode_pointer(DAT_100393d0);
    pcVar4 = (code *)__decode_pointer(DAT_100393d4);
    if (((pcVar3 != (code *)0x0) && (pcVar4 != (code *)0x0)) &&
       (((iVar5 = (*pcVar3)(), iVar5 == 0 ||
         (iVar5 = (*pcVar4)(iVar5,1,local_18,0xc,local_c), iVar5 == 0)) || ((local_10 & 1) == 0))))
    {
      _UType = _UType | 0x200000;
      goto LAB_1001c937;
    }
  }
  if ((((DAT_100393c8 != iVar1) &&
       (pcVar3 = (code *)__decode_pointer(DAT_100393c8), pcVar3 != (code *)0x0)) &&
      (local_8 = (*pcVar3)(), local_8 != 0)) &&
     ((DAT_100393cc != iVar1 &&
      (pcVar3 = (code *)__decode_pointer(DAT_100393cc), pcVar3 != (code *)0x0)))) {
    local_8 = (*pcVar3)(local_8);
  }
LAB_1001c937:
  pcVar3 = (code *)__decode_pointer(DAT_100393c4);
  if (pcVar3 == (code *)0x0) {
    return 0;
  }
  iVar1 = (*pcVar3)(local_8,_LpText,_LpCaption,_UType);
  return iVar1;
}
