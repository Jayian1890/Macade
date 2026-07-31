
void FUN_10002a20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    FUN_10002bf0(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10));
    FUN_100033b0(*(undefined4 *)(in_ECX + 0xc),*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc) >> 3
                );
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}
