
undefined4 * FUN_10002530(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d3c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  allocator<>(DAT_10037490 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  std::allocator<char>::allocator<char>
            ((allocator<char> *)(in_ECX + 1),(allocator<char> *)&stack0x00000004);
  uVar1 = FUN_10003bc0(1);
  iVar2 = FUN_10001080(4,uVar1);
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_10003e40(in_ECX);
  }
  *in_ECX = local_24;
  ExceptionList = local_10;
  return in_ECX;
}
