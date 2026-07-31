
void FUN_10022310(undefined4 param_1,void *param_2,size_t param_3)

{
  undefined4 *in_ECX;
  char local_80c [1024];
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (param_3 == 0) {
    _sprintf(local_40c,"Assertion: %s @ %s:%d","isize","..\\source\\game_input.cpp",0x1a);
    FUN_10021ff0(&DAT_1003191c,local_40c);
    FUN_10021ff0(&DAT_10031920);
    FUN_10021ff0(&DAT_10031924);
    FUN_10021ff0(&DAT_10031928);
    MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  if ((int)param_3 < 0x13) {
    *in_ECX = param_1;
    in_ECX[1] = param_3;
    _memset(in_ECX + 2,0,0x12);
    if (param_2 != (void *)0x0) {
      _memcpy(in_ECX + 2,param_2,param_3);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  _sprintf(local_80c,"Assertion: %s @ %s:%d","isize <= GAMEINPUT_MAX_BYTES * GAMEINPUT_MAX_PLAYERS",
           "..\\source\\game_input.cpp",0x1b);
  FUN_10021ff0(&DAT_100319b0,local_80c);
  FUN_10021ff0(&DAT_100319b4);
  FUN_10021ff0(&DAT_100319b8);
  FUN_10021ff0(&DAT_100319bc);
  MessageBoxA((HWND)0x0,local_80c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
