
undefined4 FUN_100205a0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = param_1[1];
  *in_ECX = *param_1;
  in_ECX[1] = uVar1;
  in_ECX[0x2a] = 0xffffffff;
  FUN_1000a800();
  in_ECX[3] = 0;
  in_ECX[2] = *param_1;
  return 1;
}
