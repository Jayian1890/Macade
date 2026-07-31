
undefined4 * FUN_100284c0(void)

{
  uint uVar1;
  HANDLE pvVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d594;
  local_10 = ExceptionList;
  uVar1 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = 0;
  in_ECX[1] = 0;
  _vector_constructor_iterator_(in_ECX + 0x42,8,0x40,FUN_10008c60);
  FUN_10008d00(uVar1);
  local_8 = 0;
  FUN_10008d00();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_10008e40();
  pvVar2 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  in_ECX[in_ECX[1] + 2] = pvVar2;
  in_ECX[1] = in_ECX[1] + 1;
  ExceptionList = local_10;
  return in_ECX;
}
