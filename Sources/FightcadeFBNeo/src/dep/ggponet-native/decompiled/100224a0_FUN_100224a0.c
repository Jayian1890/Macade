
void FUN_100224a0(undefined4 param_1,void *param_2,size_t param_3,int param_4,int param_5)

{
  undefined4 *in_ECX;
  char local_c0c [1024];
  char local_80c [1024];
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (param_3 == 0) {
    _sprintf(local_40c,"Assertion: %s @ %s:%d","isize","..\\source\\game_input.cpp",0xc);
    FUN_10021ff0(&DAT_100317bc,local_40c);
    FUN_10021ff0(&DAT_100317c0);
    FUN_10021ff0(&DAT_100317c4);
    FUN_10021ff0(&DAT_100317c8);
    MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  if ((int)param_3 < 10) {
    if (param_4 < 3) {
      *in_ECX = param_1;
      in_ECX[1] = param_3 * param_4;
      _memset(in_ECX + 2,0,0x12);
      if (param_2 != (void *)0x0) {
        _memcpy((void *)((int)in_ECX + param_5 * param_3 + 8),param_2,param_3);
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    _sprintf(local_c0c,"Assertion: %s @ %s:%d","players <= GAMEINPUT_MAX_PLAYERS",
             "..\\source\\game_input.cpp",0xe);
    FUN_10021ff0(&DAT_100318b8,local_c0c);
    FUN_10021ff0(&DAT_100318bc);
    FUN_10021ff0(&DAT_100318c0);
    FUN_10021ff0(&DAT_100318c4);
    MessageBoxA((HWND)0x0,local_c0c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  _sprintf(local_80c,"Assertion: %s @ %s:%d","isize <= GAMEINPUT_MAX_BYTES",
           "..\\source\\game_input.cpp",0xd);
  FUN_10021ff0(&DAT_10031838,local_80c);
  FUN_10021ff0(&DAT_1003183c);
  FUN_10021ff0(&DAT_10031840);
  FUN_10021ff0(&DAT_10031844);
  MessageBoxA((HWND)0x0,local_80c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
