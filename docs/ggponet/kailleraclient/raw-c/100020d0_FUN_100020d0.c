
void __fastcall FUN_100020d0(undefined4 *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  *param_1 = &PTR_FUN_1000d1fc;
  if (param_1[2] != 0) {
    Ordinal_22(param_1[2],2);
    Ordinal_3(param_1[2]);
    uVar1 = 0;
    if (DAT_1000ea88 != 0) {
      piVar2 = &DAT_1000ea8c;
LAB_10002111:
      if (*piVar2 != param_1[2]) goto code_r0x10002115;
      if (uVar1 < DAT_1000ea88 - 1) {
        puVar4 = &DAT_1000ea8c + uVar1;
        do {
          uVar1 = uVar1 + 1;
          *puVar4 = puVar4[1];
          puVar4 = puVar4 + 1;
        } while (uVar1 < DAT_1000ea88 - 1);
      }
      DAT_1000ea88 = DAT_1000ea88 - 1;
    }
LAB_1000214a:
    if (param_1[2] == DAT_1000ec98) {
      uVar1 = 0;
      iVar3 = 0;
      DAT_1000ec98 = 0;
      piVar2 = DAT_1000ea80;
      if (0 < (int)DAT_1000ea84) {
        do {
          if ((iVar3 < 0) || ((int)DAT_1000ea84 <= iVar3)) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar4 = (undefined4 *)*piVar2;
          }
          if (puVar4 != param_1) {
            if ((iVar3 < 0) || ((int)DAT_1000ea84 <= iVar3)) {
              iVar6 = 0;
            }
            else {
              iVar6 = *piVar2;
            }
            uVar5 = *(uint *)(iVar6 + 8);
            if (uVar1 < uVar5) {
              uVar1 = uVar5;
              DAT_1000ec98 = uVar5;
            }
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar3 < (int)DAT_1000ea84);
      }
    }
  }
  uVar5 = 0;
  piVar2 = DAT_1000ea80;
  uVar1 = DAT_1000ea84;
  if (0 < (int)DAT_1000ea84) {
    do {
      if ((int)uVar5 < (int)uVar1) {
        puVar4 = (undefined4 *)piVar2[uVar5];
      }
      else {
        puVar4 = (undefined4 *)0x0;
      }
      if (puVar4 == param_1) {
        if ((piVar2 != (int *)0x0) && ((int)uVar5 < (int)uVar1)) {
          DAT_1000ea84 = uVar1 - 1;
          if (uVar5 != DAT_1000ea84) {
            piVar7 = piVar2 + uVar5 + 1;
            piVar8 = piVar2 + uVar5;
            for (uVar1 = DAT_1000ea84 - uVar5 & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
              *piVar8 = *piVar7;
              piVar7 = piVar7 + 1;
              piVar8 = piVar8 + 1;
            }
            for (iVar3 = 0; piVar2 = DAT_1000ea80, iVar3 != 0; iVar3 = iVar3 + -1) {
              *(char *)piVar8 = (char)*piVar7;
              piVar7 = (int *)((int)piVar7 + 1);
              piVar8 = (int *)((int)piVar8 + 1);
            }
          }
          uVar1 = DAT_1000ea84;
          if (((DAT_1000ea84 & 0x1f) == 0) && (DAT_1000ea84 != 0)) {
            piVar2 = realloc(piVar2,DAT_1000ea84 << 2);
            uVar1 = DAT_1000ea84;
            DAT_1000ea80 = piVar2;
          }
        }
        uVar5 = uVar5 - 1;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < (int)uVar1);
  }
  return;
code_r0x10002115:
  uVar1 = uVar1 + 1;
  piVar2 = piVar2 + 1;
  if (DAT_1000ea88 <= uVar1) goto LAB_1000214a;
  goto LAB_10002111;
}
