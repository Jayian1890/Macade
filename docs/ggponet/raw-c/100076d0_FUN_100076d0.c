
undefined4 *
FUN_100076d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  uVar1 = param_4[1];
  in_ECX[3] = *param_4;
  in_ECX[4] = uVar1;
  *(undefined1 *)(in_ECX + 5) = param_5;
  *(undefined1 *)((int)in_ECX + 0x15) = 0;
  return in_ECX;
}
