
undefined4 * FUN_10024aa0(void)

{
  HANDLE pvVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d4ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100028e0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  *in_ECX = Udp::vftable;
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0xffffffff;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  in_ECX[0x40e] = 0;
  FUN_10007a40();
  local_8 = 0;
  FUN_10002da0();
  _memset(in_ECX + 0x416,0,0xc);
  _memset(in_ECX + 8,0,0x10);
  _memset(in_ECX + 3,0,0x14);
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
  in_ECX[7] = pvVar1;
  ExceptionList = local_10;
  return in_ECX;
}
