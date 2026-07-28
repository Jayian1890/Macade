
void FUN_10026160(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_1002d655;
  local_10 = ExceptionList;
  uVar1 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = TcpProtocol::vftable;
  local_8 = 1;
  FUN_10004a80(uVar1);
  local_8 = local_8 & 0xffffff00;
  FUN_10002980();
  local_8 = 0xffffffff;
  FUN_10026a50();
  ExceptionList = local_10;
  return;
}
