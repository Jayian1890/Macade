
void FUN_0062f180(void)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = DAT_00b1a804;
  if (DAT_00b1aa00 == 0) {
    cVar3 = FUN_0062e4c0();
    if (cVar3 != '\0') {
      DAT_00b1aa00 = 1;
      return;
    }
  }
  else if (DAT_00b1aa00 == 1) {
    cVar3 = FUN_0062e4c0();
    if (cVar3 == '\0') {
      FUN_0062f0d0(uVar2);
      DAT_00b1aa00 = 2;
      return;
    }
  }
  else if (DAT_00b1aa00 == 2) {
    cVar3 = FUN_0062e4c0();
    if (cVar3 != '\0') {
      DAT_00b1aa00 = 1;
    }
    if ((DAT_00b1aa08 == 0) || (DAT_00b1aa10 == 0)) {
      uVar7 = 0;
      do {
        if (0 < extraout_EDX) {
          piVar4 = &DAT_00a8a08c;
          iVar5 = extraout_EDX;
          do {
            iVar8 = DAT_00b1aa10;
            if (((piVar4[-1] == *(int *)((int)&DAT_00819634 + uVar7)) && (piVar4[1] == 0x18)) &&
               (iVar8 = *(int *)((int)&PTR_s_Demitri_00819630 + uVar7), *piVar4 < 0xa0)) {
              DAT_00b1aa08 = *(int *)((int)&PTR_s_Demitri_00819630 + uVar7);
              iVar8 = DAT_00b1aa10;
            }
            DAT_00b1aa10 = iVar8;
            piVar4 = piVar4 + 5;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        uVar7 = uVar7 + 8;
      } while (uVar7 < 0x78);
    }
    cVar3 = FUN_0062e4c0();
    if (cVar3 != '\0') {
      iVar5 = 0;
      iVar8 = 0;
      DAT_00b1aa0c = 0;
      DAT_00b1aa14 = 0;
      if (0 < extraout_EDX_00) {
        piVar4 = &DAT_00a8a08c;
        iVar6 = extraout_EDX_00;
        do {
          if (piVar4[1] == 0x17) {
            iVar1 = *piVar4;
            if ((iVar1 == 8) || (iVar1 == 0x22)) {
              iVar5 = iVar5 + 1;
            }
            else if ((iVar1 == 0x148) || (iVar1 == 0x162)) {
              iVar8 = iVar8 + 1;
            }
          }
          piVar4 = piVar4 + 5;
          iVar6 = iVar6 + -1;
          DAT_00b1aa0c = iVar5;
          DAT_00b1aa14 = iVar8;
        } while (iVar6 != 0);
      }
      FUN_0062f100();
      DAT_00b1aa00 = 0;
    }
  }
  return;
}
