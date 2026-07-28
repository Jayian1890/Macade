
int FUN_10008d90(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_10008d70();
  if (uVar1 <= param_1) {
    FUN_100116d5();
  }
  return *(int *)(in_ECX + 0xc) + param_1 * 8;
}
