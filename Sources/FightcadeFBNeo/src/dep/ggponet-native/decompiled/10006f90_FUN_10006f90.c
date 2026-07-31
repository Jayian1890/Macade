
void FUN_10006f90(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uStack_3c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d3a0;
  local_10 = ExceptionList;
  uStack_3c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  local_1c = FUN_10007620(1);
  local_18 = 0;
  local_8 = 0;
  local_20 = 0;
  puVar2 = &local_20;
  uVar1 = FUN_10007c60(local_1c,puVar2);
  FUN_10007640(uVar1,puVar2);
  local_18 = local_18 + 1;
  local_24 = 0;
  puVar2 = &local_24;
  uVar1 = FUN_100019c0(local_1c,puVar2);
  FUN_10007640(uVar1,puVar2);
  local_18 = local_18 + 1;
  local_28 = 0;
  puVar2 = &local_28;
  uVar1 = FUN_100086e0(local_1c,puVar2);
  FUN_10007640(uVar1,puVar2);
  FUN_100070bd();
  return;
}
