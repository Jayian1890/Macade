
undefined4 __thiscall FUN_10001a50(void *this,char *param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  
  iVar8 = 0;
  if (0 < *(int *)((int)this + 0x10)) {
    iVar10 = 0;
    do {
      iVar3 = strncmp(param_1,(char *)(iVar10 + *(int *)((int)this + 4)),0x10);
      if (iVar3 == 0) {
        iVar8 = iVar8 * 0x18;
        pcVar5 = *(char **)(*(int *)((int)this + 4) + 0x10 + iVar8);
        if (pcVar5 == (char *)0x0) goto LAB_10001b72;
        uVar6 = 0xffffffff;
        pcVar9 = pcVar5;
        goto code_r0x10001b2c;
      }
      iVar8 = iVar8 + 1;
      iVar10 = iVar10 + 0x18;
    } while (iVar8 < *(int *)((int)this + 0x10));
  }
  if ((*(int *)((int)this + 0x14) <= *(int *)((int)this + 0x10)) || (*(int *)((int)this + 4) == 0))
  {
    iVar8 = *(int *)((int)this + 0x10) + 8;
    *(int *)((int)this + 0x14) = iVar8;
    pvVar4 = realloc(*(void **)((int)this + 4),iVar8 * 0x18);
    *(void **)((int)this + 4) = pvVar4;
  }
  strncpy((char *)(*(int *)((int)this + 4) + *(int *)((int)this + 0x10) * 0x18),param_1,0x10);
  *(undefined4 *)(*(int *)((int)this + 4) + 0x14 + *(int *)((int)this + 0x10) * 0x18) = param_3;
  pcVar5 = _strdup(param_2);
  *(char **)(*(int *)((int)this + 4) + 0x10 + *(int *)((int)this + 0x10) * 0x18) = pcVar5;
  uVar2 = *(undefined4 *)(*(int *)((int)this + 4) + 0x10 + *(int *)((int)this + 0x10) * 0x18);
  *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
  return uVar2;
  while( true ) {
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    if (cVar1 == '\0') break;
code_r0x10001b2c:
    if (uVar6 == 0) break;
  }
  uVar7 = 0xffffffff;
  pcVar9 = param_2;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  if (~uVar7 - 1 < ~uVar6 - 1) {
    uVar6 = 0xffffffff;
    do {
      pcVar9 = param_2;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar9 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar9;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar9 + -uVar6;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar5 = pcVar5 + 1;
    }
  }
  else {
    if (pcVar5 != (char *)0x0) {
      free(pcVar5);
    }
LAB_10001b72:
    pcVar5 = _strdup(param_2);
    *(char **)(*(int *)((int)this + 4) + 0x10 + iVar8) = pcVar5;
  }
  *(undefined4 *)(*(int *)((int)this + 4) + 0x14 + iVar8) = param_3;
  return *(undefined4 *)(*(int *)((int)this + 4) + 0x10 + iVar8);
}
