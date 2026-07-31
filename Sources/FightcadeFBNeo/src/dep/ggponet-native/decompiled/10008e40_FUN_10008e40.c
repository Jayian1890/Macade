
undefined4 FUN_10008e40(void)

{
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d878;
  local_10 = ExceptionList;
  uStack_1c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (undefined1 *)&uStack_20;
  allocator<>();
  FUN_100024a0();
  local_8 = 0;
  uStack_20 = 0;
  FUN_100091f0();
  ExceptionList = local_10;
  return local_18;
}
