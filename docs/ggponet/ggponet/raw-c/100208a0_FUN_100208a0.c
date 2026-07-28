
undefined4 FUN_100208a0(void)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d55d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_10002da0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_10002da0();
  local_8._0_1_ = 1;
  FUN_10002da0();
  local_8._0_1_ = 2;
  FUN_100015e0();
  local_8._0_1_ = 3;
  FUN_100015e0();
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_10002da0();
  ExceptionList = local_10;
  return in_ECX;
}
