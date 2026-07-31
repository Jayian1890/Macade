
/* WARNING: Removing unreachable block (ram,0x10022e00) */
/* WARNING: Removing unreachable block (ram,0x10022e08) */

void FUN_10022d40(void)

{
  undefined4 in_ECX;
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  _sprintf(local_40c,"Assertion: %s @ %s:%d","FALSE && \"Invalid msg in UdpProtocol\"",
           "..\\source\\network\\udp_proto.cpp",0x130);
  FUN_10022c50(in_ECX,&DAT_100320ac,local_40c);
  FUN_10022c50(in_ECX,&DAT_100320b0);
  FUN_10022c50(in_ECX,&DAT_100320b4);
  FUN_10022c50(in_ECX,&DAT_100320b8);
  MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
