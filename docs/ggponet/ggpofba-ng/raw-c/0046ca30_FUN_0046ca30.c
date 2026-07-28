
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ca30(void)

{
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPCWSTR pWVar1;
  int iVar2;
  char *pcVar3;
  char *unaff_EBX;
  LPCWSTR pWVar4;
  char *pcVar5;
  
  hModule = DAT_00ad6f40;
  if ((DAT_00b181e9 == '\0') || (pcVar3 = *(char **)(DAT_00b1820c + 0x147c), pcVar3 == (char *)0x0))
  {
    hResInfo = FindResourceA(DAT_00ad6f40,(LPCSTR)0x29,(LPCSTR)0x6);
    hResData = LoadResource(hModule,hResInfo);
    pWVar1 = LockResource(hResData);
    pWVar4 = (LPCWSTR)0x0;
    if (pWVar1 != (LPCWSTR)0x0) {
      iVar2 = 0xf;
      pWVar4 = pWVar1;
      do {
        iVar2 = iVar2 + -1;
        pWVar4 = pWVar4 + (ushort)*pWVar4 + 1;
      } while (iVar2 != 0);
    }
    pWVar1 = pWVar4 + 1;
    if (*pWVar4 == L'\0') {
      pWVar1 = pWVar4;
    }
    iVar2 = WideCharToMultiByte(0,0,pWVar1,(uint)(ushort)*pWVar4,&DAT_00b1b920,0x1400,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar2 == 0) {
      pcVar3 = (char *)0x0;
    }
    else {
      (&DAT_00b1b920)[(ushort)*pWVar4] = 0;
      pcVar3 = &DAT_00b1b920;
    }
  }
  _sprintf(unaff_EBX,pcVar3,"FB Alpha");
  pcVar3 = unaff_EBX;
  do {
    pcVar5 = pcVar3;
    pcVar3 = pcVar5 + 1;
  } while (*pcVar5 != '\0');
  pcVar3 = " (*.fs, *.fr)";
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar5 = pcVar5 + 4;
  }
  *pcVar5 = *pcVar3;
  _memset(&DAT_009e6cc0,0,0x58);
  _DAT_009e6cc0 = 0x58;
  _DAT_009e6cc4 = DAT_00ad7508;
  _DAT_009e6ccc = unaff_EBX;
  _DAT_009e6cdc = &DAT_00ad7360;
  _DAT_009e6ce0 = 0x104;
  _DAT_009e6cec = ".\\savestates";
  _DAT_009e6cf4 = 0xc;
  _DAT_009e6cfc = &DAT_007f9e30;
  return;
}
