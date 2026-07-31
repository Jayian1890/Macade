
void FUN_1000d0a0(void)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 0x16b4);
  if (iVar1 < 0xe) {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(2 << ((byte)iVar1 & 0x1f));
    *(int *)(in_ECX + 0x16b4) = iVar1 + 3;
  }
  else {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(2 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar1 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(in_ECX + 8) + iVar1) = *(undefined1 *)(in_ECX + 0x16b1);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    iVar1 = *(int *)(in_ECX + 0x16b4);
    *(int *)(in_ECX + 0x16b4) = iVar1 + -0xd;
    *(ushort *)(in_ECX + 0x16b0) = 2 >> (0x10U - (char)iVar1 & 0x1f);
  }
  iVar1 = *(int *)(in_ECX + 0x16b4);
  if (iVar1 < 10) {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(0x70000 << ((byte)iVar1 & 0x1f));
    *(int *)(in_ECX + 0x16b4) = iVar1 + 7;
  }
  else {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(0 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar1 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(in_ECX + 8) + iVar1) = *(undefined1 *)(in_ECX + 0x16b1);
    iVar1 = *(int *)(in_ECX + 0x16b4);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x16b4) = iVar1 + -9;
    *(ushort *)(in_ECX + 0x16b0) = 0 >> (0x10U - (char)iVar1 & 0x1f);
  }
  FUN_1000e890();
  iVar1 = *(int *)(in_ECX + 0x16b4);
  if ((*(int *)(in_ECX + 0x16ac) - iVar1) + 0xb < 9) {
    if (iVar1 < 0xe) {
      *(ushort *)(in_ECX + 0x16b0) =
           *(ushort *)(in_ECX + 0x16b0) | (ushort)(2 << ((byte)iVar1 & 0x1f));
      *(int *)(in_ECX + 0x16b4) = iVar1 + 3;
    }
    else {
      *(ushort *)(in_ECX + 0x16b0) =
           *(ushort *)(in_ECX + 0x16b0) | (ushort)(2 << ((byte)iVar1 & 0x1f));
      *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
           *(undefined1 *)(in_ECX + 0x16b0);
      iVar1 = *(int *)(in_ECX + 0x14) + 1;
      *(int *)(in_ECX + 0x14) = iVar1;
      *(undefined1 *)(*(int *)(in_ECX + 8) + iVar1) = *(undefined1 *)(in_ECX + 0x16b1);
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
      iVar1 = *(int *)(in_ECX + 0x16b4);
      *(int *)(in_ECX + 0x16b4) = iVar1 + -0xd;
      *(ushort *)(in_ECX + 0x16b0) = 2 >> (0x10U - (char)iVar1 & 0x1f);
    }
    iVar1 = *(int *)(in_ECX + 0x16b4);
    if (iVar1 < 10) {
      *(ushort *)(in_ECX + 0x16b0) =
           *(ushort *)(in_ECX + 0x16b0) | (ushort)(0x70000 << ((byte)iVar1 & 0x1f));
      *(int *)(in_ECX + 0x16b4) = iVar1 + 7;
    }
    else {
      *(ushort *)(in_ECX + 0x16b0) =
           *(ushort *)(in_ECX + 0x16b0) | (ushort)(0 << ((byte)iVar1 & 0x1f));
      *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
           *(undefined1 *)(in_ECX + 0x16b0);
      iVar1 = *(int *)(in_ECX + 0x14) + 1;
      *(int *)(in_ECX + 0x14) = iVar1;
      *(undefined1 *)(*(int *)(in_ECX + 8) + iVar1) = *(undefined1 *)(in_ECX + 0x16b1);
      iVar1 = *(int *)(in_ECX + 0x16b4);
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
      *(int *)(in_ECX + 0x16b4) = iVar1 + -9;
      *(ushort *)(in_ECX + 0x16b0) = 0 >> (0x10U - (char)iVar1 & 0x1f);
    }
    FUN_1000e890();
  }
  *(undefined4 *)(in_ECX + 0x16ac) = 7;
  return;
}
