
/* WARNING: Removing unreachable block (ram,0x10023074) */

void FUN_10022e60(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  undefined4 in_ECX;
  char local_814 [1028];
  uint local_410;
  undefined1 local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  switch(*param_2) {
  case 1:
    FUN_10022c50();
    break;
  case 2:
    FUN_10022c50();
    break;
  case 3:
    local_410 = 0;
    local_40c[0] = 0;
    while (((int)local_410 < (int)(uint)*(ushort *)(param_2 + 9) && (local_410 < 0x3ff))) {
      iVar1 = FUN_100228f0(param_2 + 0xc,&local_410);
      if (iVar1 == 0) {
        FUN_10011490(local_40c,&DAT_10031f88);
      }
      else {
        FUN_10011490(local_40c,&DAT_10031f84);
      }
    }
    FUN_10022c50(in_ECX,"%s game-compressed-input %d (+%s).\n",param_1,*(undefined4 *)(param_2 + 1),
                 local_40c);
    break;
  case 4:
    FUN_10022c50();
    break;
  case 5:
    FUN_10022c50();
    break;
  default:
    _sprintf(local_814,"Assertion: %s @ %s:%d","FALSE && \"Unknown UdpMsg type.\"",
             "..\\source\\network\\udp_proto.cpp",0x11f);
    FUN_10022c50(in_ECX,&DAT_10032008,local_814);
    FUN_10022c50(in_ECX,&DAT_1003200c);
    FUN_10022c50(in_ECX,&DAT_10032010);
    FUN_10022c50(in_ECX,&DAT_10032014);
    MessageBoxA((HWND)0x0,local_814,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
