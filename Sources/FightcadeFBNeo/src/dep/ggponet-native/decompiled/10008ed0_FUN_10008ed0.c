
int FUN_10008ed0(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_10008eb0();
  if (uVar1 <= param_1) {
    FUN_100116d5();
  }
  return param_1 * 0x10 + *(int *)(in_ECX + 0xc);
}
