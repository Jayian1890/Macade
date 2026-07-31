
void FUN_0062e3c0(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = DAT_00b1a804;
  if (DAT_00b1a914 == 0) {
    cVar2 = FUN_0062e320();
    if (cVar2 == '\0') {
      return;
    }
    FUN_0062e260(uVar1);
    DAT_00b1a914 = 2;
    return;
  }
  if (DAT_00b1a914 != 2) {
    return;
  }
  cVar2 = FUN_0062e320();
  if (cVar2 == '\0') {
    DAT_00b1a918 = DAT_00b1a918 + -1;
  }
  else {
    DAT_00b1a918 = 0x2d0;
  }
  piVar3 = (int *)(DAT_00b19850 + DAT_00b1985c);
  if (DAT_00b1a918 != 0) {
    uVar5 = 0x4c0;
    piVar4 = piVar3;
    do {
      if (*(int *)(((int)&DAT_00873018 - (int)piVar3) + (int)piVar4) != *piVar4) {
        uVar5 = 0x4c0;
        piVar4 = piVar3;
        goto LAB_0062e463;
      }
      uVar5 = uVar5 - 4;
      piVar4 = piVar4 + 1;
    } while (3 < uVar5);
  }
  goto LAB_0062e4a2;
  while( true ) {
    uVar5 = uVar5 - 4;
    piVar4 = piVar4 + 1;
    if (uVar5 < 4) break;
LAB_0062e463:
    if (*(int *)(((int)&DAT_008734d8 - (int)piVar3) + (int)piVar4) != *piVar4) {
      uVar5 = 0x4c0;
      iVar6 = (int)&DAT_00872b58 - (int)piVar3;
      goto LAB_0062e483;
    }
  }
  goto LAB_0062e4a2;
  while( true ) {
    uVar5 = uVar5 - 4;
    piVar3 = piVar3 + 1;
    if (uVar5 < 4) break;
LAB_0062e483:
    if (*(int *)(iVar6 + (int)piVar3) != *piVar3) {
      cVar2 = FUN_0062e360();
      if (cVar2 == '\0') {
        return;
      }
      break;
    }
  }
LAB_0062e4a2:
  FUN_0062e2a0();
  DAT_00b1a914 = 0;
  return;
}
