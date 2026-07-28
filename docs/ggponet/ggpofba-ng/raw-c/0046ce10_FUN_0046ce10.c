
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ce10(void)

{
  HMODULE hModule;
  undefined4 uVar1;
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPCWSTR pWVar2;
  undefined1 *puVar3;
  BOOL BVar4;
  int iVar5;
  LPCWSTR pWVar6;
  int unaff_EDI;
  undefined1 local_40c [1028];
  uint local_8;
  
  local_8 = DAT_00871720 ^ (uint)local_40c;
  if (DAT_00ad74c4 == 0) {
LAB_0046ce2f:
    __security_check_cookie(local_8 ^ (uint)local_40c);
    return;
  }
  if (unaff_EDI == 0) {
    uVar1 = FUN_0052d560(0);
    _sprintf(&DAT_00ad7360,"%.8s",uVar1);
    FUN_0046ca30();
    hModule = DAT_00ad6f40;
    if ((DAT_00b181e9 == '\0') ||
       (puVar3 = *(undefined1 **)(DAT_00b1820c + 0x127c), puVar3 == (undefined1 *)0x0)) {
      hResInfo = FindResourceA(DAT_00ad6f40,(LPCSTR)0x25,(LPCSTR)0x6);
      hResData = LoadResource(hModule,hResInfo);
      pWVar2 = LockResource(hResData);
      pWVar6 = (LPCWSTR)0x0;
      if (pWVar2 != (LPCWSTR)0x0) {
        iVar5 = 0xf;
        pWVar6 = pWVar2;
        do {
          iVar5 = iVar5 + -1;
          pWVar6 = pWVar6 + (ushort)*pWVar6 + 1;
        } while (iVar5 != 0);
      }
      pWVar2 = pWVar6 + 1;
      if (*pWVar6 == L'\0') {
        pWVar2 = pWVar6;
      }
      iVar5 = WideCharToMultiByte(0,0,pWVar2,(uint)(ushort)*pWVar6,&DAT_00b1b920,0x1400,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if (iVar5 == 0) {
        puVar3 = (undefined1 *)0x0;
      }
      else {
        (&DAT_00b1b920)[(ushort)*pWVar6] = 0;
        puVar3 = &DAT_00b1b920;
      }
    }
    uVar1 = DAT_00ad74cc;
    _DAT_009e6cf4 = _DAT_009e6cf4 | 2;
    DAT_00ad74cc = 1;
    _DAT_009e6cf0 = puVar3;
    BVar4 = GetSaveFileNameA((LPOPENFILENAMEA)&DAT_009e6cc0);
    DAT_00ad74cc = uVar1;
    if (BVar4 == 0) goto LAB_0046ce2f;
  }
  else {
    uVar1 = FUN_0052d560(0);
    _sprintf(&DAT_00ad7360,".\\savestates\\%s slot %02x.fs",uVar1);
  }
  iVar5 = FUN_00475170();
  if ((iVar5 != 0) && (unaff_EDI == 0)) {
    FUN_0045f2f0(0x10000,0x352);
    FUN_0045f2f0(0x10000,0x28d);
    FUN_0045f500();
  }
  __security_check_cookie(local_8 ^ (uint)local_40c);
  return;
}
