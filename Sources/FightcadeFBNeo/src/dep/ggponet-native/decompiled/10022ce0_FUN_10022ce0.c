
void FUN_10022ce0(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_100244f0(param_1 + 4);
  *param_1 = *(undefined4 *)(in_ECX + 0x108c);
  param_1[1] = *(undefined4 *)(in_ECX + 0x10a4);
  param_1[2] = *(undefined4 *)(in_ECX + 0x10a0);
  uVar1 = FUN_10001680();
  param_1[3] = uVar1;
  return;
}
