
void FUN_10026060(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = Ordinal_8(param_3 + 8);
  local_c = Ordinal_8(*(undefined4 *)(in_ECX + 0xe8));
  local_8 = Ordinal_8(param_1);
  FUN_10021ff0("Sending command %d to server.\n",param_1);
  FUN_10026e20(&local_10,4);
  FUN_10026e20(&local_c,4);
  FUN_10026e20(&local_8,4);
  FUN_10026e20(param_2,param_3);
  local_14 = *(undefined4 *)(in_ECX + 0xe8);
  *(int *)(in_ECX + 0xe8) = *(int *)(in_ECX + 0xe8) + 1;
  puVar1 = (undefined4 *)FUN_10004b10(&local_14);
  *puVar1 = (&PTR_FUN_10033270)[param_1];
  return;
}
