
void FUN_100251e0(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = Ordinal_8(param_1);
  *(undefined4 *)(param_2 + *param_3) = uVar1;
  *param_3 = *param_3 + 4;
  return;
}
