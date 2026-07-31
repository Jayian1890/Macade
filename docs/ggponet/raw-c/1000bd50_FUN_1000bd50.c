
void FUN_1000bd50(void)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  int *in_ECX;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar1 = in_ECX[9];
  do {
    uVar5 = in_ECX[0x19];
    uVar6 = (in_ECX[0xd] - uVar5) - in_ECX[0x1b];
    if (uVar6 == 0) {
      if ((uVar5 != 0) || (uVar7 = uVar1, in_ECX[0x1b] != 0)) {
LAB_1000bd83:
        uVar7 = uVar6;
        if (in_ECX[9] + -0x106 + uVar1 <= uVar5) {
          puVar8 = (undefined4 *)(in_ECX[0xc] + uVar1);
          puVar9 = (undefined4 *)in_ECX[0xc];
          for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined1 *)puVar9 = *(undefined1 *)puVar8;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            puVar9 = (undefined4 *)((int)puVar9 + 1);
          }
          in_ECX[0x1a] = in_ECX[0x1a] - uVar1;
          iVar3 = in_ECX[0x11];
          in_ECX[0x19] = in_ECX[0x19] - uVar1;
          in_ECX[0x15] = in_ECX[0x15] - uVar1;
          puVar4 = (ushort *)(in_ECX[0xf] + iVar3 * 2);
          do {
            puVar4 = puVar4 + -1;
            if (*puVar4 < uVar1) {
              uVar2 = 0;
            }
            else {
              uVar2 = *puVar4 - (short)uVar1;
            }
            iVar3 = iVar3 + -1;
            *puVar4 = uVar2;
          } while (iVar3 != 0);
          puVar4 = (ushort *)(in_ECX[0xe] + uVar1 * 2);
          uVar5 = uVar1;
          do {
            puVar4 = puVar4 + -1;
            if (*puVar4 < uVar1) {
              uVar2 = 0;
            }
            else {
              uVar2 = *puVar4 - (short)uVar1;
            }
            uVar5 = uVar5 - 1;
            *puVar4 = uVar2;
          } while (uVar5 != 0);
          uVar7 = uVar6 + uVar1;
        }
      }
    }
    else {
      if (uVar6 != 0xffffffff) goto LAB_1000bd83;
      uVar7 = 0xfffffffe;
    }
    if (*(int *)(*in_ECX + 4) == 0) {
      return;
    }
    iVar3 = FUN_1000be70(uVar7);
    uVar5 = in_ECX[0x1b] + iVar3;
    in_ECX[0x1b] = uVar5;
    if (2 < uVar5) {
      uVar6 = (uint)*(byte *)(in_ECX[0x19] + in_ECX[0xc]);
      in_ECX[0x10] = uVar6;
      in_ECX[0x10] = (uVar6 << ((byte)in_ECX[0x14] & 0x1f) ^
                     (uint)*(byte *)(in_ECX[0x19] + in_ECX[0xc] + 1)) & in_ECX[0x13];
    }
    if (0x105 < uVar5) {
      return;
    }
    if (*(int *)(*in_ECX + 4) == 0) {
      return;
    }
  } while( true );
}
