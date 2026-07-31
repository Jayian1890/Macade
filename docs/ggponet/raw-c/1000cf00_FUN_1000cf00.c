
void FUN_1000cf00(void)

{
  int in_ECX;
  
  FUN_1000cf70();
  *(int *)(in_ECX + 0xb10) = in_ECX + 0x8c;
  *(int *)(in_ECX + 0xb1c) = in_ECX + 0x980;
  *(undefined ***)(in_ECX + 0xb18) = &PTR_DAT_10036118;
  *(undefined ***)(in_ECX + 0xb24) = &PTR_DAT_10036130;
  *(int *)(in_ECX + 0xb28) = in_ECX + 0xa74;
  *(undefined **)(in_ECX + 0xb30) = &DAT_10036148;
  *(undefined2 *)(in_ECX + 0x16b0) = 0;
  *(undefined4 *)(in_ECX + 0x16b4) = 0;
  *(undefined4 *)(in_ECX + 0x16ac) = 8;
  FUN_1000cf80();
  return;
}
