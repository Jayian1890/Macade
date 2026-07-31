
uint FUN_10022a10(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    iVar1 = FUN_100228f0(param_1,param_2);
    local_8 = iVar1 << ((byte)local_c & 0x1f) | local_8;
  }
  return local_8;
}
