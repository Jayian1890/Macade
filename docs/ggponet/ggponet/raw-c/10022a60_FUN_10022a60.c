
void FUN_10022a60(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int local_410;
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if ((int)param_2 < 0x100) {
    for (local_410 = 0; local_410 < 8; local_410 = local_410 + 1) {
      if ((1 << ((byte)local_410 & 0x1f) & param_2) == 0) {
        FUN_10022950(param_1,param_3);
      }
      else {
        FUN_100229b0(param_1,param_3);
      }
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  _sprintf(local_40c,"Assertion: %s @ %s:%d","nibble < (1 << BITVECTOR_NIBBLE_SIZE)",
           "..\\source\\bitvector.cpp",0x19);
  FUN_10021ff0(&DAT_10031bf4,local_40c);
  FUN_10021ff0(&DAT_10031bf8);
  FUN_10021ff0(&DAT_10031bfc);
  FUN_10021ff0(&DAT_10031c00);
  MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
