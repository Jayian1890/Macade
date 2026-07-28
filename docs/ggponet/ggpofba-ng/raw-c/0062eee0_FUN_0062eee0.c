
void FUN_0062eee0(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int iVar7;
  uint uVar8;
  int local_14;
  int *local_10;
  
  uVar1 = DAT_00b1a804;
  if (DAT_00b1a9e8 == 0) {
    cVar2 = FUN_0062e4c0();
    if (cVar2 != '\0') {
      DAT_00b1a9e8 = 1;
      return;
    }
  }
  else if (DAT_00b1a9e8 == 1) {
    cVar2 = FUN_0062e4c0();
    if (cVar2 == '\0') {
      FUN_0062ee30(uVar1);
      DAT_00b1a9e8 = 2;
      return;
    }
  }
  else if (DAT_00b1a9e8 == 2) {
    cVar2 = FUN_0062e4c0();
    if (cVar2 != '\0') {
      DAT_00b1a9e8 = 1;
    }
    local_10 = &DAT_008194ac;
    local_14 = 0;
    do {
      if (*(int *)((int)&DAT_00b1a9f0 + local_14) == 0) {
        uVar8 = 0;
        piVar4 = local_10;
        do {
          if (0 < extraout_EDX) {
            piVar3 = &DAT_00a8a090;
            iVar5 = 0;
            do {
              if (((piVar3[-2] == *piVar4) &&
                  (piVar3[-1] == *(int *)((int)&DAT_009a3938 + local_14))) &&
                 (*piVar3 == *(int *)((int)&DAT_009a393c + local_14))) {
                *(undefined4 *)((int)&DAT_00b1a9f0 + local_14) =
                     *(undefined4 *)(&UNK_008194a8 + uVar8 * 0xc);
                goto LAB_0062eff1;
              }
              iVar5 = iVar5 + 1;
              piVar3 = piVar3 + 5;
            } while (iVar5 < extraout_EDX);
          }
          uVar8 = uVar8 + 1;
          piVar4 = piVar4 + 3;
        } while (uVar8 < 0x12);
      }
LAB_0062eff1:
      local_10 = local_10 + 1;
      local_14 = local_14 + 8;
    } while ((int)local_10 < 0x8194b4);
    cVar2 = FUN_0062e4c0();
    iVar5 = extraout_EDX_00;
    if ((cVar2 != '\0') || (cVar2 = FUN_0062e4c0(), iVar5 = extraout_EDX_01, cVar2 != '\0')) {
      local_14 = 0;
      local_10 = &DAT_00b1a9f4;
      do {
        iVar7 = 0;
        do {
          iVar6 = 0;
          if (0 < iVar5) {
            piVar4 = &DAT_00a8a090;
            do {
              if ((piVar4[-1] == *(int *)(&DAT_009a3948 + (local_14 + iVar7) * 8)) &&
                 (*piVar4 == *(int *)(&DAT_009a394c + (local_14 + iVar7) * 8))) {
                if ((0 < (int)(&DAT_00a8a088)[iVar6 * 5]) && ((&DAT_00a8a088)[iVar6 * 5] != 0xa420))
                {
                  *local_10 = *local_10 + 1;
                }
                break;
              }
              iVar6 = iVar6 + 1;
              piVar4 = piVar4 + 5;
            } while (iVar6 < iVar5);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
        local_14 = local_14 + 2;
        local_10 = local_10 + 2;
      } while ((int)local_10 < 0xb1aa04);
      FUN_0062ee60();
      DAT_00b1a9e8 = 0;
    }
  }
  return;
}
