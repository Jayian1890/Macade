
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10025da0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  int local_8;
  
  local_8 = 0;
  FUN_100251e0(0,&DAT_120394e8,&local_8);
  uVar1 = *(undefined4 *)(in_ECX + 0xe8);
  *(int *)(in_ECX + 0xe8) = *(int *)(in_ECX + 0xe8) + 1;
  FUN_100251e0(uVar1,&DAT_120394e8,&local_8);
  FUN_100251e0(0x12,&DAT_120394e8,&local_8);
  FUN_10025150(param_1,&DAT_120394e8,&local_8);
  FUN_100251e0(param_3,&DAT_120394e8,&local_8);
  FUN_100251e0(param_4,&DAT_120394e8,&local_8);
  _DAT_120394e8 = Ordinal_8(local_8 + -4 + param_3);
  FUN_10026e20(&DAT_120394e8,local_8);
  FUN_10026e20(param_2,param_3);
  return;
}
