
void FUN_1000dbd0(int param_1,int param_2)

{
  ushort uVar1;
  int in_ECX;
  int iVar2;
  int in_EDX;
  int iVar3;
  
  iVar2 = *(int *)(in_ECX + 0x16b4);
  if (iVar2 < 0xc) {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(in_EDX + -0x101 << ((byte)iVar2 & 0x1f));
    *(int *)(in_ECX + 0x16b4) = iVar2 + 5;
  }
  else {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(in_EDX + -0x101 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar2 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
    iVar2 = *(int *)(in_ECX + 0x16b4);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x16b4) = iVar2 + -0xb;
    *(ushort *)(in_ECX + 0x16b0) = (ushort)(in_EDX + -0x101) >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar2 = *(int *)(in_ECX + 0x16b4);
  if (iVar2 < 0xc) {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(param_1 + -1 << ((byte)iVar2 & 0x1f));
    *(int *)(in_ECX + 0x16b4) = iVar2 + 5;
  }
  else {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(param_1 + -1 << ((byte)iVar2 & 0x1f));
    *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar2 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar2;
    *(undefined1 *)(iVar2 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
    iVar2 = *(int *)(in_ECX + 0x16b4);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x16b4) = iVar2 + -0xb;
    *(ushort *)(in_ECX + 0x16b0) = (ushort)(param_1 + -1) >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar3 = *(int *)(in_ECX + 0x16b4);
  iVar2 = param_2 + -4;
  if (iVar3 < 0xd) {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar2 << ((byte)iVar3 & 0x1f));
    *(int *)(in_ECX + 0x16b4) = iVar3 + 4;
  }
  else {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar2 << ((byte)iVar3 & 0x1f));
    *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar3 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar3;
    *(undefined1 *)(iVar3 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
    iVar3 = *(int *)(in_ECX + 0x16b4);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x16b4) = iVar3 + -0xc;
    *(ushort *)(in_ECX + 0x16b0) = (ushort)iVar2 >> (0x10U - (char)iVar3 & 0x1f);
  }
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar3 = *(int *)(in_ECX + 0x16b4);
      if (iVar3 < 0xe) {
        *(ushort *)(in_ECX + 0x16b0) =
             *(ushort *)(in_ECX + 0x16b0) |
             *(short *)(in_ECX + 0xa76 + (uint)(byte)(&DAT_1002e3ec)[iVar2] * 4) <<
             ((byte)iVar3 & 0x1f);
        *(int *)(in_ECX + 0x16b4) = iVar3 + 3;
      }
      else {
        uVar1 = *(ushort *)(in_ECX + 0xa76 + (uint)(byte)(&DAT_1002e3ec)[iVar2] * 4);
        *(ushort *)(in_ECX + 0x16b0) = *(ushort *)(in_ECX + 0x16b0) | uVar1 << ((byte)iVar3 & 0x1f);
        *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
             *(undefined1 *)(in_ECX + 0x16b0);
        iVar3 = *(int *)(in_ECX + 0x14) + 1;
        *(int *)(in_ECX + 0x14) = iVar3;
        *(undefined1 *)(iVar3 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
        iVar3 = *(int *)(in_ECX + 0x16b4);
        *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
        *(int *)(in_ECX + 0x16b4) = iVar3 + -0xd;
        *(ushort *)(in_ECX + 0x16b0) = uVar1 >> (0x10U - (char)iVar3 & 0x1f);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  FUN_1000de40(in_EDX + -1);
  FUN_1000de40(param_1 + -1);
  return;
}
