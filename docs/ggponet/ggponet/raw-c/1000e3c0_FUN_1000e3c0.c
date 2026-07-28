
void FUN_1000e3c0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  int in_ECX;
  uint uVar4;
  int in_EDX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint local_10;
  
  local_10 = 0;
  if (*(int *)(in_ECX + 0x1698) != 0) {
    do {
      uVar6 = (uint)*(ushort *)(*(int *)(in_ECX + 0x169c) + local_10 * 2);
      uVar7 = (uint)*(byte *)(local_10 + *(int *)(in_ECX + 0x1690));
      local_10 = local_10 + 1;
      if (uVar6 == 0) {
        uVar6 = (uint)*(ushort *)(in_EDX + 2 + uVar7 * 4);
        iVar8 = *(int *)(in_ECX + 0x16b4);
        if ((int)(0x10 - uVar6) < iVar8) {
          uVar1 = *(ushort *)(in_EDX + uVar7 * 4);
          *(ushort *)(in_ECX + 0x16b0) =
               *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar8 & 0x1f);
          *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
               *(undefined1 *)(in_ECX + 0x16b0);
          iVar8 = *(int *)(in_ECX + 0x14) + 1;
          *(int *)(in_ECX + 0x14) = iVar8;
          *(undefined1 *)(iVar8 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
          *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
          iVar8 = *(int *)(in_ECX + 0x16b4) + -0x10 + uVar6;
          *(ushort *)(in_ECX + 0x16b0) = uVar1 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
        }
        else {
          *(ushort *)(in_ECX + 0x16b0) =
               *(ushort *)(in_ECX + 0x16b0) | *(short *)(in_EDX + uVar7 * 4) << ((byte)iVar8 & 0x1f)
          ;
          iVar8 = iVar8 + uVar6;
        }
LAB_1000e731:
        *(int *)(in_ECX + 0x16b4) = iVar8;
      }
      else {
        uVar4 = (uint)(byte)(&DAT_1002eaf8)[uVar7];
        uVar10 = (uint)*(ushort *)(in_EDX + 0x406 + uVar4 * 4);
        bVar3 = (byte)*(int *)(in_ECX + 0x16b4);
        if ((int)(0x10 - uVar10) < *(int *)(in_ECX + 0x16b4)) {
          uVar1 = *(ushort *)(in_EDX + 0x404 + uVar4 * 4);
          *(ushort *)(in_ECX + 0x16b0) = *(ushort *)(in_ECX + 0x16b0) | uVar1 << (bVar3 & 0x1f);
          *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
               *(undefined1 *)(in_ECX + 0x16b0);
          iVar8 = *(int *)(in_ECX + 0x14) + 1;
          *(int *)(in_ECX + 0x14) = iVar8;
          *(undefined1 *)(*(int *)(in_ECX + 8) + iVar8) = *(undefined1 *)(in_ECX + 0x16b1);
          *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
          *(ushort *)(in_ECX + 0x16b0) = uVar1 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
          *(uint *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + -0x10 + uVar10;
        }
        else {
          *(ushort *)(in_ECX + 0x16b0) =
               *(ushort *)(in_ECX + 0x16b0) |
               *(short *)(in_EDX + 0x404 + uVar4 * 4) << (bVar3 & 0x1f);
          *(uint *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + uVar10;
        }
        iVar8 = *(int *)(&DAT_1002e2b4 + uVar4 * 4);
        if (iVar8 != 0) {
          iVar9 = uVar7 - *(int *)(&DAT_1002ebf8 + uVar4 * 4);
          iVar5 = *(int *)(in_ECX + 0x16b4);
          if (0x10 - iVar8 < iVar5) {
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar5 & 0x1f));
            *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
                 *(undefined1 *)(in_ECX + 0x16b0);
            iVar5 = *(int *)(in_ECX + 0x14) + 1;
            *(int *)(in_ECX + 0x14) = iVar5;
            *(undefined1 *)(*(int *)(in_ECX + 8) + iVar5) = *(undefined1 *)(in_ECX + 0x16b1);
            *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
            iVar5 = *(int *)(in_ECX + 0x16b4) + -0x10;
            *(ushort *)(in_ECX + 0x16b0) =
                 (ushort)iVar9 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar5 & 0x1f));
          }
          *(int *)(in_ECX + 0x16b4) = iVar5 + iVar8;
        }
        uVar7 = uVar6 - 1;
        if (uVar7 < 0x100) {
          bVar3 = (&DAT_1002e8f7)[uVar6];
        }
        else {
          bVar3 = (&DAT_1002e9f8)[uVar7 >> 7];
        }
        uVar6 = (uint)bVar3;
        iVar8 = *(int *)(in_ECX + 0x16b4);
        uVar4 = (uint)*(ushort *)(param_1 + 2 + uVar6 * 4);
        if ((int)(0x10 - uVar4) < iVar8) {
          uVar1 = *(ushort *)(param_1 + uVar6 * 4);
          *(ushort *)(in_ECX + 0x16b0) =
               *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar8 & 0x1f);
          *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
               *(undefined1 *)(in_ECX + 0x16b0);
          iVar8 = *(int *)(in_ECX + 0x14) + 1;
          *(int *)(in_ECX + 0x14) = iVar8;
          *(undefined1 *)(*(int *)(in_ECX + 8) + iVar8) = *(undefined1 *)(in_ECX + 0x16b1);
          iVar8 = *(int *)(in_ECX + 0x16b4);
          *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
          *(uint *)(in_ECX + 0x16b4) = iVar8 + -0x10 + uVar4;
          *(ushort *)(in_ECX + 0x16b0) = uVar1 >> (0x10U - (char)iVar8 & 0x1f);
        }
        else {
          *(ushort *)(in_ECX + 0x16b0) =
               *(ushort *)(in_ECX + 0x16b0) |
               *(short *)(param_1 + uVar6 * 4) << ((byte)iVar8 & 0x1f);
          *(uint *)(in_ECX + 0x16b4) = iVar8 + uVar4;
        }
        iVar8 = *(int *)(&DAT_1002e328 + uVar6 * 4);
        if (iVar8 != 0) {
          iVar9 = uVar7 - *(int *)(&DAT_1002ec6c + uVar6 * 4);
          iVar5 = *(int *)(in_ECX + 0x16b4);
          if (0x10 - iVar8 < iVar5) {
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar5 & 0x1f));
            *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
                 *(undefined1 *)(in_ECX + 0x16b0);
            iVar5 = *(int *)(in_ECX + 0x14) + 1;
            *(int *)(in_ECX + 0x14) = iVar5;
            *(undefined1 *)(iVar5 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
            *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
            iVar8 = *(int *)(in_ECX + 0x16b4) + -0x10 + iVar8;
            *(ushort *)(in_ECX + 0x16b0) =
                 (ushort)iVar9 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
          }
          else {
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar5 & 0x1f));
            iVar8 = iVar5 + iVar8;
          }
          goto LAB_1000e731;
        }
      }
    } while (local_10 < *(uint *)(in_ECX + 0x1698));
  }
  iVar8 = *(int *)(in_ECX + 0x16b4);
  uVar1 = *(ushort *)(in_EDX + 0x402);
  if ((int)(0x10 - (uint)uVar1) < iVar8) {
    uVar2 = *(ushort *)(in_EDX + 0x400);
    *(ushort *)(in_ECX + 0x16b0) = *(ushort *)(in_ECX + 0x16b0) | uVar2 << ((byte)iVar8 & 0x1f);
    *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar8 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar8;
    *(undefined1 *)(*(int *)(in_ECX + 8) + iVar8) = *(undefined1 *)(in_ECX + 0x16b1);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    iVar8 = *(int *)(in_ECX + 0x16b4) + -0x10;
    *(ushort *)(in_ECX + 0x16b0) = uVar2 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
  }
  else {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | *(short *)(in_EDX + 0x400) << ((byte)iVar8 & 0x1f);
  }
  *(uint *)(in_ECX + 0x16b4) = iVar8 + (uint)uVar1;
  *(uint *)(in_ECX + 0x16ac) = (uint)*(ushort *)(in_EDX + 0x402);
  return;
}
