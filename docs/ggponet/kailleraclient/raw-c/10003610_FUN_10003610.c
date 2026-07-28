
void __thiscall FUN_10003610(void *this,char *param_1)

{
  char cVar1;
  char *pcVar2;
  LPSTR _Memory;
  void *this_00;
  undefined4 *this_01;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  LPSTR pCVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar9;
  undefined4 local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  puStack_8 = &DAT_1000c96b;
  *unaff_FS_OFFSET = &local_c;
  FUN_100034d0((int)this);
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = malloc(~uVar3);
  uVar3 = 0xffffffff;
  *(char **)((int)this + 0x14) = pcVar2;
  pcVar6 = param_1;
  do {
    pcVar8 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar8 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar2 = pcVar2 + 1;
  }
  FUN_10003aa0(*(char **)((int)this + 0x14),(undefined4 *)((int)this + 0x18),
               (int *)((int)this + 0x10),(undefined4 *)((int)this + 0x20),
               (undefined4 *)((int)this + 0x1c));
  uVar3 = 0xffffffff;
  do {
    pcVar2 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar2;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar2 + -uVar3;
  pcVar6 = *(char **)((int)this + 0x14);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pcVar2 = *(char **)((int)this + 0x18);
  if (((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) || (*(int *)((int)this + 0x10) == 0)) {
    *(undefined4 *)((int)this + 0xc) = 0xffffffff;
    if (*(void **)((int)this + 0x40) != (void *)0x0) {
      free(*(void **)((int)this + 0x40));
    }
    uVar3 = 0xffffffff;
    pcVar2 = s_invalid_URL_1000e154;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = malloc(~uVar3);
    uVar3 = 0xffffffff;
    *(char **)((int)this + 0x40) = pcVar2;
    pcVar6 = s_invalid_URL_1000e154;
    do {
      pcVar8 = pcVar6;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar6 = pcVar8 + -uVar3;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar2 = pcVar2 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar2 = pcVar2 + 1;
    }
  }
  else {
    if ((*(char **)((int)this + 0x28) == (char *)0x0) || (**(char **)((int)this + 0x28) == '\0')) {
      uVar3 = 0xffffffff;
      pcVar6 = *(char **)((int)this + 0x20);
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      iVar5 = ~uVar3 + 0xe;
    }
    else {
      uVar3 = 0xffffffff;
      pcVar6 = *(char **)((int)this + 0x14);
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar6 = *(char **)((int)this + 0x24);
      iVar5 = ~uVar3 + 0xe;
      if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
        uVar4 = 0xffffffff;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        iVar5 = ~uVar3 + 0x48 + (~uVar4 - 1) * 2;
      }
    }
    uVar3 = 0xffffffff;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = *(char **)((int)this + 0x1c);
    iVar5 = iVar5 + ~uVar3 + 6;
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      uVar3 = 0xffffffff;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      iVar5 = iVar5 + 0x2e + (~uVar3 - 1) * 2;
    }
    if (*(char **)((int)this + 0x30) != (char *)0x0) {
      uVar3 = 0xffffffff;
      pcVar2 = *(char **)((int)this + 0x30);
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      iVar5 = iVar5 + (~uVar3 - 1);
    }
    _Memory = malloc(iVar5 + 0x400);
    if (_Memory == (LPSTR)0x0) {
      if (*(void **)((int)this + 0x40) != (void *)0x0) {
        free(*(void **)((int)this + 0x40));
      }
      uVar3 = 0xffffffff;
      pcVar2 = s_error_allocating_memory_1000e1d8;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = malloc(~uVar3);
      uVar3 = 0xffffffff;
      *(char **)((int)this + 0x40) = pcVar2;
      pcVar6 = s_error_allocating_memory_1000e1d8;
      do {
        pcVar8 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar6 = pcVar8 + -uVar3;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
      *(undefined4 *)((int)this + 0xc) = 0xffffffff;
    }
    if ((*(char **)((int)this + 0x28) == (char *)0x0) || (**(char **)((int)this + 0x28) == '\0')) {
      uVar9 = *(undefined4 *)((int)this + 0x20);
    }
    else {
      uVar9 = *(undefined4 *)((int)this + 0x14);
    }
    wsprintfA(_Memory,s_GET__s_HTTP_1_0_1000e1c4,uVar9);
    uVar3 = 0xffffffff;
    pCVar7 = _Memory;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pCVar7;
      pCVar7 = pCVar7 + 1;
    } while (cVar1 != '\0');
    wsprintfA(_Memory + (~uVar3 - 1),s_Host__s_1000e1b8,*(undefined4 *)((int)this + 0x18));
    if ((*(char **)((int)this + 0x1c) != (char *)0x0) && (**(char **)((int)this + 0x1c) != '\0')) {
      uVar3 = 0xffffffff;
      pcVar2 = s_Authorization__Basic_1000e1a0;
      do {
        pcVar6 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar5 = -1;
      pCVar7 = _Memory;
      do {
        pcVar2 = pCVar7;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar2 = pCVar7 + 1;
        cVar1 = *pCVar7;
        pCVar7 = pcVar2;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + -uVar3;
      pcVar2 = pcVar2 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
      uVar3 = 0xffffffff;
      pCVar7 = _Memory;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pCVar7;
        pCVar7 = pCVar7 + 1;
      } while (cVar1 != '\0');
      FUN_10003560(*(char **)((int)this + 0x1c),_Memory + (~uVar3 - 1));
      uVar3 = 0xffffffff;
      pcVar2 = &DAT_1000e108;
      do {
        pcVar6 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar5 = -1;
      pCVar7 = _Memory;
      do {
        pcVar2 = pCVar7;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar2 = pCVar7 + 1;
        cVar1 = *pCVar7;
        pCVar7 = pcVar2;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + -uVar3;
      pcVar2 = pcVar2 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
    }
    if ((*(char **)((int)this + 0x24) != (char *)0x0) && (**(char **)((int)this + 0x24) != '\0')) {
      uVar3 = 0xffffffff;
      pcVar2 = s_Proxy_Authorization__Basic_1000e184;
      do {
        pcVar6 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar5 = -1;
      pCVar7 = _Memory;
      do {
        pcVar2 = pCVar7;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar2 = pCVar7 + 1;
        cVar1 = *pCVar7;
        pCVar7 = pcVar2;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + -uVar3;
      pcVar2 = pcVar2 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
      uVar3 = 0xffffffff;
      pCVar7 = _Memory;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pCVar7;
        pCVar7 = pCVar7 + 1;
      } while (cVar1 != '\0');
      FUN_10003560(*(char **)((int)this + 0x24),_Memory + (~uVar3 - 1));
      uVar3 = 0xffffffff;
      pcVar2 = &DAT_1000e108;
      do {
        pcVar6 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar5 = -1;
      pCVar7 = _Memory;
      do {
        pcVar2 = pCVar7;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar2 = pCVar7 + 1;
        cVar1 = *pCVar7;
        pCVar7 = pcVar2;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + -uVar3;
      pcVar2 = pcVar2 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
    }
    if (*(char **)((int)this + 0x30) != (char *)0x0) {
      uVar3 = 0xffffffff;
      pcVar2 = *(char **)((int)this + 0x30);
      do {
        pcVar6 = pcVar2;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar5 = -1;
      pCVar7 = _Memory;
      do {
        pcVar2 = pCVar7;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar2 = pCVar7 + 1;
        cVar1 = *pCVar7;
        pCVar7 = pcVar2;
      } while (cVar1 != '\0');
      pcVar6 = pcVar6 + -uVar3;
      pcVar2 = pcVar2 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
    }
    uVar3 = 0xffffffff;
    pcVar2 = &DAT_1000e108;
    do {
      pcVar6 = pcVar2;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar5 = -1;
    pCVar7 = _Memory;
    do {
      pcVar2 = pCVar7;
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      pcVar2 = pCVar7 + 1;
      cVar1 = *pCVar7;
      pCVar7 = pcVar2;
    } while (cVar1 != '\0');
    pcVar6 = pcVar6 + -uVar3;
    pcVar2 = pcVar2 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar2 = pcVar2 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar2 = pcVar2 + 1;
    }
    uVar3 = *(uint *)((int)this + 8);
    if ((int)uVar3 < 0x1000) {
      uVar3 = 0x1000;
    }
    this_00 = operator_new(0x148);
    this_01 = (undefined4 *)0x0;
    local_4 = 0;
    if (this_00 != (void *)0x0) {
      uVar4 = 0xffffffff;
      pCVar7 = _Memory;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pCVar7;
        pCVar7 = pCVar7 + 1;
      } while (cVar1 != '\0');
      this_01 = FUN_10002a40(this_00,*(int *)this,~uVar4 + 3,uVar3);
    }
    *(undefined4 **)((int)this + 4) = this_01;
    local_4 = 0xffffffff;
    if (this_01 == (undefined4 *)0x0) {
      *(undefined4 *)((int)this + 0xc) = 0xffffffff;
      if (*(void **)((int)this + 0x40) != (void *)0x0) {
        free(*(void **)((int)this + 0x40));
      }
      uVar3 = 0xffffffff;
      pcVar2 = s_could_not_create_connection_obje_1000e160;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = malloc(~uVar3);
      uVar3 = 0xffffffff;
      *(char **)((int)this + 0x40) = pcVar2;
      pcVar6 = s_could_not_create_connection_obje_1000e160;
      do {
        pcVar8 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar6 = pcVar8 + -uVar3;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar2 = pcVar2 + 1;
      }
      free(_Memory);
    }
    else {
      pcVar2 = *(char **)((int)this + 0x28);
      if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
        uVar9 = *(undefined4 *)((int)this + 0x10);
        pcVar2 = *(char **)((int)this + 0x18);
      }
      else {
        uVar9 = *(undefined4 *)((int)this + 0x2c);
      }
      FUN_10002b50(this_01,pcVar2,uVar9);
      FUN_100031d0(*(void **)((int)this + 4),_Memory);
      free(_Memory);
    }
  }
  *unaff_FS_OFFSET = local_c;
  return;
}
