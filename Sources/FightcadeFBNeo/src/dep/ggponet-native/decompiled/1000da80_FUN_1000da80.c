
void FUN_1000da80(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_1000daf0(*(undefined4 *)(in_ECX + 0xb14));
  FUN_1000daf0(*(undefined4 *)(in_ECX + 0xb20));
  FUN_1000d4e0();
  iVar1 = 0x12;
  do {
    if (*(short *)(in_ECX + 0xa76 + (uint)(byte)(&DAT_1002e3ec)[iVar1] * 4) != 0) break;
    iVar1 = iVar1 + -1;
  } while (2 < iVar1);
  *(int *)(in_ECX + 0x16a0) = *(int *)(in_ECX + 0x16a0) + iVar1 * 3 + 0x11;
  return;
}
