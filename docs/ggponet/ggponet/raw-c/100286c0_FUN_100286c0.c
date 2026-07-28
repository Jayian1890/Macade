
void FUN_100286c0(void)

{
  char cVar1;
  int *in_ECX;
  undefined1 local_28 [32];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  while( true ) {
    cVar1 = FUN_10002830(local_28);
    if (cVar1 == '\0') break;
    (**(code **)(*in_ECX + 0x24))(local_28);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
