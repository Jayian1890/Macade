
void FUN_1000e890(void)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(in_ECX + 0x16b4) == 0x10) {
    *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar1 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(in_ECX + 8) + iVar1) = *(undefined1 *)(in_ECX + 0x16b1);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    *(undefined2 *)(in_ECX + 0x16b0) = 0;
    *(undefined4 *)(in_ECX + 0x16b4) = 0;
    return;
  }
  if (7 < *(int *)(in_ECX + 0x16b4)) {
    *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    *(ushort *)(in_ECX + 0x16b0) = (ushort)*(byte *)(in_ECX + 0x16b1);
    *(int *)(in_ECX + 0x16b4) = *(int *)(in_ECX + 0x16b4) + -8;
  }
  return;
}
