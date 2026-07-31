
void FUN_10022860(char *param_1,byte param_2)

{
  size_t sVar1;
  uint uVar2;
  undefined1 local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  FUN_10011480(local_40c,param_1);
  uVar2 = (uint)param_2;
  sVar1 = _strlen(param_1);
  FUN_100226c0(local_40c + sVar1,uVar2);
  FUN_10011490(local_40c,&DAT_10031a68);
  FUN_10021ff0(local_40c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
