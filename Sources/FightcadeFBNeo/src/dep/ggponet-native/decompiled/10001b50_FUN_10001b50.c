
void FUN_10001b50(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uStack_30;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d410;
  local_10 = ExceptionList;
  uStack_30 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_30;
  ExceptionList = &local_10;
  local_1c = FUN_10002150(1);
  local_18 = 0;
  local_8 = 0;
  puVar2 = &local_1c;
  uVar1 = FUN_10007c60(local_1c,puVar2);
  FUN_10007640(uVar1,puVar2);
  local_18 = local_18 + 1;
  puVar2 = &local_1c;
  uVar1 = FUN_100019c0(local_1c,puVar2);
  FUN_10007640(uVar1,puVar2);
  FUN_10001c25();
  return;
}
