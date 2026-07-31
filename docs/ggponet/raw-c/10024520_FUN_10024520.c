
void FUN_10024520(undefined4 param_1,char *param_2)

{
  char local_414 [1023];
  undefined1 local_15;
  uint local_10;
  size_t local_c;
  va_list local_8;
  
  local_10 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  FUN_10011480(local_414,"udp | ");
  local_c = _strlen(local_414);
  local_8 = &stack0x0000000c;
  __vsnprintf(local_414 + local_c,0x3ff - local_c,param_2,local_8);
  local_15 = 0;
  FUN_10021ff0(local_414);
  local_8 = (va_list)0x0;
  __security_check_cookie(local_10 ^ (uint)&stack0xfffffffc);
  return;
}
