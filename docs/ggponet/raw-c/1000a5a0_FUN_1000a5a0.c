
undefined4 * FUN_1000a5a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  while (param_1 != param_2) {
    uVar1 = param_2[-1];
    param_3[-2] = param_2[-2];
    param_3[-1] = uVar1;
    param_2 = param_2 + -2;
    param_3 = param_3 + -2;
  }
  return param_3;
}
