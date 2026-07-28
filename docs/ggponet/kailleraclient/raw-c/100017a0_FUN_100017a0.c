
undefined4 * __thiscall FUN_100017a0(void *this,char *param_1,char *param_2)

{
  char cVar1;
  HMODULE hModule;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  DWORD nSize;
  
  if (param_2 == (char *)0x0) {
    uVar2 = 0xffffffff;
    pcVar6 = s_config_1000e070;
    do {
      pcVar5 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar5 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar5;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar6 = pcVar5 + -uVar2;
    pcVar5 = (char *)((int)this + 0x11c);
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar5 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  else {
    strncpy((char *)((int)this + 0x11c),param_2,0x1f);
    *(undefined1 *)((int)this + 0x13b) = 0;
  }
  if (param_1 == (char *)0x0) {
    pcVar6 = (char *)((int)this + 0x18);
    nSize = 0x104;
    pcVar5 = pcVar6;
    hModule = GetModuleHandleA((LPCSTR)0x0);
    GetModuleFileNameA(hModule,pcVar5,nSize);
    cVar1 = *pcVar6;
    pcVar5 = pcVar6;
    while (cVar1 != '\0') {
      pcVar7 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
      cVar1 = *pcVar7;
    }
    for (; ((pcVar6 < pcVar5 && (*pcVar5 != '.')) && (*pcVar5 != '\\')); pcVar5 = pcVar5 + -1) {
    }
    if (*pcVar5 == '.') {
      uVar2 = 0xffffffff;
      pcVar6 = &DAT_1000e06c;
      do {
        pcVar7 = pcVar6;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      pcVar7 = pcVar7 + -uVar2;
      pcVar6 = pcVar5 + 1;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar6 = pcVar6 + 4;
      }
    }
    else {
      if (*pcVar5 == '\\') {
        uVar2 = 0xffffffff;
        pcVar5 = pcVar5 + 1;
        do {
          pcVar7 = param_2;
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          pcVar7 = param_2 + 1;
          cVar1 = *param_2;
          param_2 = pcVar7;
        } while (cVar1 != '\0');
        uVar2 = ~uVar2;
        pcVar7 = pcVar7 + -uVar2;
        pcVar6 = pcVar5;
      }
      else {
        uVar2 = 0xffffffff;
        do {
          pcVar7 = param_2;
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          pcVar7 = param_2 + 1;
          cVar1 = *param_2;
          param_2 = pcVar7;
        } while (cVar1 != '\0');
        uVar2 = ~uVar2;
        pcVar7 = pcVar7 + -uVar2;
      }
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar6 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar6 = pcVar6 + 1;
      }
      uVar2 = 0xffffffff;
      pcVar6 = &DAT_1000e064;
      do {
        pcVar7 = pcVar6;
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar2 = ~uVar2;
      iVar4 = -1;
      do {
        pcVar6 = pcVar5;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar6 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar6;
      } while (cVar1 != '\0');
      pcVar7 = pcVar7 + -uVar2;
      pcVar6 = pcVar6 + -1;
      for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar6 = pcVar6 + 4;
      }
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  else {
    strncpy((char *)((int)this + 0x18),param_1,0x103);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined1 *)((int)this + 0x11b) = 0;
  return this;
}
