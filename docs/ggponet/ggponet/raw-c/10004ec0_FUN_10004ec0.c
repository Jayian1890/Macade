
undefined4 FUN_10004ec0(undefined4 param_1,allocator<char> *param_2)

{
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d7b8;
  local_10 = ExceptionList;
  uStack_1c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (undefined1 *)&uStack_20;
  std::allocator<char>::allocator<char>((allocator<char> *)&uStack_20,param_2);
  FUN_10006300(param_1);
  local_8 = 0;
  uStack_20 = 0x10004f12;
  FUN_10005d60();
  ExceptionList = local_10;
  return local_18;
}
