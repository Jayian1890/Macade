
undefined4 * FUN_10027f60(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d5ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100028c0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  *in_ECX = ReplayBackend::vftable;
  FUN_10002da0();
  local_8 = 0;
  puVar2 = in_ECX;
  for (iVar1 = 7; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
  }
  FUN_10027b70(param_2);
  ExceptionList = local_10;
  return in_ECX;
}
