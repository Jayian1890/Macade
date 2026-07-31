
undefined4 * FUN_10026ae0(undefined4 param_1)

{
  HANDLE pvVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d4d4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100028e0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  *in_ECX = Tcp::vftable;
  in_ECX[4] = param_1;
  in_ECX[5] = 0xffffffff;
  in_ECX[6] = 0xffffffff;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  FUN_10002da0();
  local_8 = 0;
  FUN_10002da0();
  _memset(in_ECX + 0x11,0,0x10);
  _memset(in_ECX + 7,0,0x14);
  _memset(in_ECX + 0xc,0,0x14);
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
  in_ECX[0xb] = pvVar1;
  pvVar1 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCSTR)0x0);
  in_ECX[0x10] = pvVar1;
  ExceptionList = local_10;
  return in_ECX;
}
