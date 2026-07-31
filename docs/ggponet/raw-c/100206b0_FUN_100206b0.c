
void FUN_100206b0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28;
  undefined4 local_24 [7];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_28 = 0;
  puVar2 = local_24;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_1000a8d0(&local_28);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
