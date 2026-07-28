
int FUN_10007a40(void)

{
  undefined4 uVar1;
  undefined4 uStack_20;
  uint uStack_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d478;
  local_10 = ExceptionList;
  uStack_1c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (undefined1 *)&uStack_20;
  allocator<>();
  FUN_10001cc0();
  local_8 = 0;
  uStack_20 = 0x10007a8a;
  uVar1 = FUN_10007cf0();
  *(undefined4 *)(local_18 + 0x14) = uVar1;
  *(undefined4 *)(local_18 + 0x18) = 0;
  ExceptionList = local_10;
  return local_18;
}
