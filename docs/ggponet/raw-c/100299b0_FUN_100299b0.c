
void FUN_100299b0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d73e;
  local_10 = ExceptionList;
  uVar1 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = GGPOBackend::vftable;
  in_ECX[1] = GGPOBackend::vftable;
  local_8 = 0;
  FUN_100014b0(uVar1);
  FUN_10001470();
  FUN_10026160();
  local_8 = 0xffffffff;
  FUN_10028790();
  ExceptionList = local_10;
  return;
}
