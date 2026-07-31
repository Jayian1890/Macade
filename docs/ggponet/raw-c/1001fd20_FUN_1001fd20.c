
/* WARNING: Removing unreachable block (ram,0x1001fe09) */

void FUN_1001fd20(int param_1)

{
  int in_ECX;
  char local_414 [1028];
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  local_10 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_8 = 0x16;
  for (local_c = 0; (local_c < 0x16 && (*(int *)(in_ECX + 0x118 + local_c * 0x10) != param_1));
      local_c = local_c + 1) {
  }
  if (local_c == 0x16) {
    _sprintf(local_414,"Assertion: %s @ %s:%d","FALSE","..\\source\\sync.cpp",0xaa);
    FUN_10021ff0(&DAT_10030c98,local_414);
    FUN_10021ff0(&DAT_10030c9c);
    FUN_10021ff0(&DAT_10030ca0);
    FUN_10021ff0(&DAT_10030ca4);
    MessageBoxA((HWND)0x0,local_414,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  __security_check_cookie(local_10 ^ (uint)&stack0xfffffffc);
  return;
}
