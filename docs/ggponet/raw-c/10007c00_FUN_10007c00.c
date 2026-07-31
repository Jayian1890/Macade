
undefined4 * FUN_10007c00(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar1 = *in_ECX;
  uVar2 = in_ECX[1];
  FUN_100080a0();
  *param_1 = uVar1;
  param_1[1] = uVar2;
  return param_1;
}
