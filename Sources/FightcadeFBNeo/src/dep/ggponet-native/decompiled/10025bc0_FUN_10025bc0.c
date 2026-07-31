
undefined4 * FUN_10025bc0(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d5c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100028e0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  *in_ECX = TcpProtocol::vftable;
  FUN_10026ae0(0);
  local_8 = 0;
  FUN_10002da0();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10004ae0();
  in_ECX[0x3a] = 1;
  in_ECX[0x3d] = 0x400;
  pvVar1 = _malloc(in_ECX[0x3d]);
  in_ECX[0x3b] = pvVar1;
  in_ECX[0x3c] = 0;
  ExceptionList = local_10;
  return in_ECX;
}
