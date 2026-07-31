
/* WARNING: Removing unreachable block (ram,0x10007964) */
/* WARNING: Removing unreachable block (ram,0x1000796c) */

void FUN_10007830(void)

{
  undefined1 *in_ECX;
  char local_40c [1024];
  uint local_c;
  int local_8;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  switch(*in_ECX) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    local_8 = ((int)(*(ushort *)(in_ECX + 9) + 7) >> 3) + 0xb;
    break;
  case 4:
    break;
  case 5:
    break;
  default:
    _sprintf(local_40c,"Assertion: %s @ %s:%d","false","udp_msg.h",0x47);
    FUN_10021ff0(&DAT_10033398,local_40c);
    FUN_10021ff0(&DAT_1003339c);
    FUN_10021ff0(&DAT_1003339c);
    FUN_10021ff0(&DAT_1003339c);
    MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}
