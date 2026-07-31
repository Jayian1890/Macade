
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046cbd0(void)

{
  HMODULE hModule;
  undefined4 uVar1;
  int iVar2;
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPCWSTR pWVar3;
  undefined1 *puVar4;
  BOOL BVar5;
  LPCWSTR pWVar6;
  int unaff_EDI;
  undefined1 local_40c [1028];
  uint local_8;
  
  local_8 = DAT_00871720 ^ (uint)local_40c;
  if (unaff_EDI == 0) {
    if (DAT_00ad74c4 == 0) {
      _sprintf(&DAT_00ad7360,"savestate");
    }
    else {
      uVar1 = FUN_0052d560(0);
      _sprintf(&DAT_00ad7360,"%.8s*.fs",uVar1);
    }
    FUN_0046ca30();
    hModule = DAT_00ad6f40;
    if ((DAT_00b181e9 == '\0') ||
       (puVar4 = *(undefined1 **)(DAT_00b1820c + 0x1274), puVar4 == (undefined1 *)0x0)) {
      hResInfo = FindResourceA(DAT_00ad6f40,(LPCSTR)0x25,(LPCSTR)0x6);
      hResData = LoadResource(hModule,hResInfo);
      pWVar3 = LockResource(hResData);
      pWVar6 = (LPCWSTR)0x0;
      if (pWVar3 != (LPCWSTR)0x0) {
        iVar2 = 0xe;
        pWVar6 = pWVar3;
        do {
          iVar2 = iVar2 + -1;
          pWVar6 = pWVar6 + (ushort)*pWVar6 + 1;
        } while (iVar2 != 0);
      }
      pWVar3 = pWVar6 + 1;
      if (*pWVar6 == L'\0') {
        pWVar3 = pWVar6;
      }
      iVar2 = WideCharToMultiByte(0,0,pWVar3,(uint)(ushort)*pWVar6,&DAT_00b1b920,0x1400,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if (iVar2 == 0) {
        puVar4 = (undefined1 *)0x0;
      }
      else {
        (&DAT_00b1b920)[(ushort)*pWVar6] = 0;
        puVar4 = &DAT_00b1b920;
      }
    }
    uVar1 = DAT_00ad74cc;
    DAT_00ad74cc = 1;
    _DAT_009e6cf0 = puVar4;
    BVar5 = GetOpenFileNameA((LPOPENFILENAMEA)&DAT_009e6cc0);
    DAT_00ad74cc = uVar1;
    if (BVar5 == 0) {
      __security_check_cookie(local_8 ^ (uint)local_40c);
      return;
    }
  }
  else {
    uVar1 = FUN_0052d560(0);
    _sprintf(&DAT_00ad7360,".\\savestates\\%s slot %02x.fs",uVar1);
  }
  iVar2 = FUN_00474e10(1);
  if (unaff_EDI != 0) goto LAB_0046cdf0;
  if (iVar2 == 3) {
    FUN_0045f2f0(0x10000,0x28e);
    uVar1 = 0x354;
LAB_0046cdd9:
    FUN_0045f2f0(0x10000,uVar1);
  }
  else if (iVar2 == 4) {
    FUN_0045f2f0(0x10000,0x28e);
    FUN_0045f2f0(0x10000,0x356,"FB Alpha");
  }
  else {
    if (iVar2 != 5) {
      if (iVar2 == 0) goto LAB_0046cdf0;
      FUN_0045f2f0(0x10000,0x353);
      uVar1 = 0x28d;
      goto LAB_0046cdd9;
    }
    FUN_0045f2f0(0x10000,0x28e);
    FUN_0045f2f0(0x10000,0x355,"FB Alpha");
  }
  FUN_0045f500();
LAB_0046cdf0:
  __security_check_cookie(local_8 ^ (uint)local_40c);
  return;
}
