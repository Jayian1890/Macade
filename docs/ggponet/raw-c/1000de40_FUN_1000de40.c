
void FUN_1000de40(int param_1)

{
  ushort uVar1;
  int in_ECX;
  int iVar2;
  int in_EDX;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort *local_10;
  uint local_c;
  int local_4;
  
  local_c = 0xffffffff;
  iVar2 = 7;
  iVar6 = 4;
  if (*(ushort *)(in_EDX + 2) == 0) {
    iVar2 = 0x8a;
    iVar6 = 3;
  }
  if (-1 < param_1) {
    local_10 = (ushort *)(in_EDX + 6);
    local_4 = param_1 + 1;
    iVar3 = 0;
    uVar5 = (uint)*(ushort *)(in_EDX + 2);
    do {
      iVar4 = iVar3 + 1;
      uVar8 = (uint)*local_10;
      if ((iVar2 <= iVar4) || (uVar5 != uVar8)) {
        if (iVar4 < iVar6) {
          do {
            iVar2 = *(int *)(in_ECX + 0x16b4);
            uVar7 = (uint)*(ushort *)(in_ECX + 0xa76 + uVar5 * 4);
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(in_ECX + 0xa74 + uVar5 * 4);
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
                   *(undefined1 *)(in_ECX + 0x16b0);
              iVar2 = *(int *)(in_ECX + 0x14) + 1;
              *(int *)(in_ECX + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
              *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
              *(ushort *)(in_ECX + 0x16b0) =
                   uVar1 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
              *(uint *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) |
                   *(short *)(in_ECX + 0xa74 + uVar5 * 4) << ((byte)iVar2 & 0x1f);
              *(uint *)(in_ECX + 0x16b4) = iVar2 + uVar7;
            }
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        else if (uVar5 == 0) {
          if (iVar4 < 0xb) {
            iVar2 = *(int *)(in_ECX + 0x16b4);
            uVar7 = (uint)*(ushort *)(in_ECX + 0xaba);
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(in_ECX + 0xab8);
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
                   *(undefined1 *)(in_ECX + 0x16b0);
              iVar2 = *(int *)(in_ECX + 0x14) + 1;
              *(int *)(in_ECX + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
              *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
              *(ushort *)(in_ECX + 0x16b0) =
                   uVar1 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
              *(uint *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | *(short *)(in_ECX + 0xab8) << ((byte)iVar2 & 0x1f)
              ;
              *(uint *)(in_ECX + 0x16b4) = iVar2 + uVar7;
            }
            iVar2 = *(int *)(in_ECX + 0x16b4);
            if (iVar2 < 0xe) {
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar3 + -2 << ((byte)iVar2 & 0x1f));
              iVar2 = iVar2 + 3;
LAB_1000e359:
              *(int *)(in_ECX + 0x16b4) = iVar2;
            }
            else {
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar3 + -2 << ((byte)iVar2 & 0x1f));
              *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
                   *(undefined1 *)(in_ECX + 0x16b0);
              iVar2 = *(int *)(in_ECX + 0x14) + 1;
              *(int *)(in_ECX + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
              iVar2 = *(int *)(in_ECX + 0x16b4);
              *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
              *(int *)(in_ECX + 0x16b4) = iVar2 + -0xd;
              *(ushort *)(in_ECX + 0x16b0) = (ushort)(iVar3 + -2) >> (0x10U - (char)iVar2 & 0x1f);
            }
          }
          else {
            iVar2 = *(int *)(in_ECX + 0x16b4);
            uVar7 = (uint)*(ushort *)(in_ECX + 0xabe);
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(in_ECX + 0xabc);
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
                   *(undefined1 *)(in_ECX + 0x16b0);
              iVar2 = *(int *)(in_ECX + 0x14) + 1;
              *(int *)(in_ECX + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
              *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
              *(ushort *)(in_ECX + 0x16b0) =
                   uVar1 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
              *(uint *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | *(short *)(in_ECX + 0xabc) << ((byte)iVar2 & 0x1f)
              ;
              *(uint *)(in_ECX + 0x16b4) = iVar2 + uVar7;
            }
            iVar2 = *(int *)(in_ECX + 0x16b4);
            if (iVar2 < 10) {
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar3 + -10 << ((byte)iVar2 & 0x1f));
              iVar2 = iVar2 + 7;
              goto LAB_1000e359;
            }
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar3 + -10 << ((byte)iVar2 & 0x1f));
            *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
                 *(undefined1 *)(in_ECX + 0x16b0);
            iVar2 = *(int *)(in_ECX + 0x14) + 1;
            *(int *)(in_ECX + 0x14) = iVar2;
            *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
            iVar2 = *(int *)(in_ECX + 0x16b4);
            *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
            *(int *)(in_ECX + 0x16b4) = iVar2 + -9;
            *(ushort *)(in_ECX + 0x16b0) = (ushort)(iVar3 + -10) >> (0x10U - (char)iVar2 & 0x1f);
          }
        }
        else {
          if (uVar5 != local_c) {
            iVar2 = *(int *)(in_ECX + 0x16b4);
            uVar7 = (uint)*(ushort *)(in_ECX + 0xa76 + uVar5 * 4);
            iVar4 = iVar3;
            if ((int)(0x10 - uVar7) < iVar2) {
              uVar1 = *(ushort *)(in_ECX + 0xa74 + uVar5 * 4);
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar2 & 0x1f);
              *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
                   *(undefined1 *)(in_ECX + 0x16b0);
              iVar2 = *(int *)(in_ECX + 0x14) + 1;
              *(int *)(in_ECX + 0x14) = iVar2;
              *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
              *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
              *(ushort *)(in_ECX + 0x16b0) =
                   uVar1 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f);
              *(uint *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + -0x10 + uVar7;
            }
            else {
              *(ushort *)(in_ECX + 0x16b0) =
                   *(ushort *)(in_ECX + 0x16b0) |
                   *(short *)(in_ECX + 0xa74 + uVar5 * 4) << ((byte)iVar2 & 0x1f);
              *(uint *)(in_ECX + 0x16b4) = iVar2 + uVar7;
            }
          }
          iVar2 = *(int *)(in_ECX + 0x16b4);
          uVar7 = (uint)*(ushort *)(in_ECX + 0xab6);
          if ((int)(0x10 - uVar7) < iVar2) {
            uVar1 = *(ushort *)(in_ECX + 0xab4);
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar2 & 0x1f);
            *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
                 *(undefined1 *)(in_ECX + 0x16b0);
            iVar2 = *(int *)(in_ECX + 0x14) + 1;
            *(int *)(in_ECX + 0x14) = iVar2;
            *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
            *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
            *(ushort *)(in_ECX + 0x16b0) = uVar1 >> (0x10U - (char)*(int *)(in_ECX + 0x16b4) & 0x1f)
            ;
            *(uint *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + -0x10 + uVar7;
          }
          else {
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | *(short *)(in_ECX + 0xab4) << ((byte)iVar2 & 0x1f);
            *(uint *)(in_ECX + 0x16b4) = iVar2 + uVar7;
          }
          iVar2 = *(int *)(in_ECX + 0x16b4);
          if (iVar2 < 0xf) {
            *(ushort *)(in_ECX + 0x16b0) =
                 *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar4 + -3 << ((byte)iVar2 & 0x1f));
            iVar2 = iVar2 + 2;
            goto LAB_1000e359;
          }
          *(ushort *)(in_ECX + 0x16b0) =
               *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar4 + -3 << ((byte)iVar2 & 0x1f));
          *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
               *(undefined1 *)(in_ECX + 0x16b0);
          iVar2 = *(int *)(in_ECX + 0x14) + 1;
          *(int *)(in_ECX + 0x14) = iVar2;
          *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
          iVar2 = *(int *)(in_ECX + 0x16b4);
          *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
          *(int *)(in_ECX + 0x16b4) = iVar2 + -0xe;
          *(ushort *)(in_ECX + 0x16b0) = (ushort)(iVar4 + -3) >> (0x10U - (char)iVar2 & 0x1f);
        }
        iVar4 = 0;
        local_c = uVar5;
        if (uVar8 == 0) {
          iVar2 = 0x8a;
          iVar6 = 3;
        }
        else if (uVar5 == uVar8) {
          iVar2 = 6;
          iVar6 = 3;
        }
        else {
          iVar2 = 7;
          iVar6 = 4;
        }
      }
      local_10 = local_10 + 2;
      local_4 = local_4 + -1;
      iVar3 = iVar4;
      uVar5 = uVar8;
    } while (local_4 != 0);
  }
  return;
}
