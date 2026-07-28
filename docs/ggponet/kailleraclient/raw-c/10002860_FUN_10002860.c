
undefined4 __thiscall FUN_10002860(void *this,int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  time_t tVar12;
  char *unaff_retaddr;
  
  iVar2 = Ordinal_11(param_1);
  if (iVar2 != -1) {
    *param_1 = iVar2;
    return 0;
  }
  iVar2 = 0;
  if (0 < *(int *)((int)this + 4)) {
    iVar7 = 0;
    do {
      iVar3 = _stricmp((char *)(iVar7 + 6 + *(int *)this),(char *)param_1);
      if ((iVar3 == 0) && (*(char *)(iVar7 + 5 + *(int *)this) == '\0')) {
        tVar12 = time((time_t *)0x0);
        *(int *)(iVar2 * 0x10c + *(int *)this) = (int)tVar12;
        iVar2 = iVar2 * 0x10c + *(int *)this;
        if (*(char *)(iVar2 + 4) != '\0') {
          iVar2 = *(int *)(iVar2 + 0x108);
          if (iVar2 != -1) {
            *param_1 = iVar2;
            return 0;
          }
          return 0xffffffff;
        }
        goto LAB_100029c7;
      }
      iVar2 = iVar2 + 1;
      iVar7 = iVar7 + 0x10c;
    } while (iVar2 < *(int *)((int)this + 4));
  }
  iVar2 = -1;
  iVar7 = 0;
  if (0 < *(int *)((int)this + 4)) {
    iVar3 = *(int *)this;
    iVar4 = 0;
    iVar10 = -0x10c;
    do {
      iVar8 = iVar7;
      if (*(int *)(iVar4 + iVar3) == 0) break;
      if (((iVar2 == -1) || (*(int *)(iVar4 + iVar3) < *(int *)(iVar10 + iVar3))) &&
         (*(char *)(iVar4 + 4 + iVar3) != '\0')) {
        iVar2 = iVar7;
        iVar10 = iVar4;
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + 0x10c;
      iVar8 = iVar2;
    } while (iVar7 < *(int *)((int)this + 4));
    if (iVar8 != -1) {
      uVar5 = 0xffffffff;
      iVar8 = iVar8 * 0x10c;
      do {
        pcVar9 = unaff_retaddr;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = unaff_retaddr + 1;
        cVar1 = *unaff_retaddr;
        unaff_retaddr = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar9 = pcVar9 + -uVar5;
      pcVar11 = (char *)(iVar8 + 6 + iVar3);
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar11 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar11 = pcVar11 + 1;
      }
      *(undefined1 *)(iVar8 + 5 + *(int *)this) = 0;
      *(undefined4 *)(iVar8 + 0x108 + *(int *)this) = 0xffffffff;
      *(undefined1 *)(iVar8 + 4 + *(int *)this) = 0;
      tVar12 = time((time_t *)0x0);
      *(int *)(iVar8 + *(int *)this) = (int)tVar12;
LAB_100029c7:
      FUN_100029e0(this);
      return 1;
    }
  }
  return 0xffffffff;
}
