
undefined4 * FUN_100074b0(undefined4 *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = param_1[1];
  *in_ECX = *param_1;
  in_ECX[1] = uVar1;
  *(undefined1 *)(in_ECX + 2) = *param_2;
  return in_ECX;
}
