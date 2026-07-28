
void FUN_10027440(undefined4 param_1,char *param_2)

{
  char local_40c [1024];
  uint local_c;
  va_list local_8;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_8 = &stack0x0000000c;
  _vsprintf(local_40c,param_2,local_8);
  local_8 = (va_list)0x0;
  _puts(local_40c);
  OutputDebugStringA(local_40c);
  FUN_100273b0();
  DebugBreak();
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}
