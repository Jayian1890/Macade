
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10025c90(undefined4 param_1,char *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  size_t sVar2;
  int in_ECX;
  int local_c;
  int local_8;
  
  local_c = 0;
  sVar2 = _strlen(param_2);
  local_8 = sVar2 + 1 + param_4;
  FUN_100251e0(0,&DAT_120394e8,&local_c);
  uVar1 = *(undefined4 *)(in_ECX + 0xe8);
  *(int *)(in_ECX + 0xe8) = *(int *)(in_ECX + 0xe8) + 1;
  FUN_100251e0(uVar1,&DAT_120394e8,&local_c);
  FUN_100251e0(0x13,&DAT_120394e8,&local_c);
  FUN_10025150(param_1,&DAT_120394e8,&local_c);
  FUN_10021ff0("Sending Replay...");
  _DAT_120394e8 = Ordinal_8(local_c + -4 + local_8);
  FUN_10026e20(&DAT_120394e8,local_c);
  FUN_10026e20(param_2,sVar2 + 1);
  FUN_10026e20(param_3,param_4);
  FUN_10021ff0("Done sending Replay...");
  return;
}
