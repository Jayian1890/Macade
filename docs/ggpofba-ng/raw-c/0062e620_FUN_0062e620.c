
void FUN_0062e620(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = DAT_00b1a804;
  if (DAT_00b1a9b0 == 0) {
    cVar2 = FUN_0062e4c0();
    if (cVar2 != '\0') {
      DAT_00b1a9b0 = 1;
      return;
    }
  }
  else if (DAT_00b1a9b0 == 1) {
    cVar2 = FUN_0062e4c0();
    if (cVar2 == '\0') {
      FUN_0062e500(uVar1);
      DAT_00b1a9b0 = 2;
      return;
    }
  }
  else if (DAT_00b1a9b0 == 2) {
    cVar2 = FUN_0062e4c0();
    if (cVar2 != '\0') {
      DAT_00b1a9b0 = 1;
    }
    iVar5 = 0;
    do {
      iVar6 = 0;
      do {
        if ((&DAT_00b1a9b8)[iVar5 * 3 + iVar6] == 0) {
          uVar4 = 0;
          do {
            if (0 < DAT_00b1a90c) {
              piVar3 = &DAT_00a8a08c;
              iVar7 = DAT_00b1a90c;
              do {
                if (piVar3[-1] == *(int *)((int)&DAT_008192e4 + uVar4)) {
                  if (iVar5 == 0) {
                    if (iVar6 == 0) {
                      if ((*piVar3 == 0x28) && (piVar3[1] == 0xe)) {
                        DAT_00b1a9b8 = *(undefined4 *)((int)&PTR_DAT_008192e0 + uVar4);
                      }
                    }
                    else if (((iVar6 == 1) && (*piVar3 == 0x28)) && (piVar3[1] == 0x25)) {
                      DAT_00b1a9bc = *(undefined4 *)((int)&PTR_DAT_008192e0 + uVar4);
                    }
                  }
                  else if (iVar5 == 1) {
                    if (iVar6 == 0) {
                      if ((piVar3[2] + *piVar3 == 0x158) && (piVar3[1] == 0xe)) {
                        DAT_00b1a9c4 = *(undefined4 *)((int)&PTR_DAT_008192e0 + uVar4);
                      }
                    }
                    else if (((iVar6 == 1) && (piVar3[2] + *piVar3 == 0x158)) && (piVar3[1] == 0x25)
                            ) {
                      DAT_00b1a9c8 = *(undefined4 *)((int)&PTR_DAT_008192e0 + uVar4);
                    }
                  }
                }
                piVar3 = piVar3 + 5;
                iVar7 = iVar7 + -1;
              } while (iVar7 != 0);
            }
            uVar4 = uVar4 + 8;
          } while (uVar4 < 0x100);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 2);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    cVar2 = FUN_0062e4c0();
    if (cVar2 != '\0') {
      cVar2 = FUN_0062e4c0();
      if (cVar2 == '\0') {
        DAT_00b1a9cc = 1;
      }
      else {
        DAT_00b1a9c0 = 1;
      }
      FUN_0062e540();
      DAT_00b1a9b0 = 0;
    }
  }
  return;
}
