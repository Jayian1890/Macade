
void FUN_10020080(int param_1,int param_2)

{
  int in_ECX;
  char local_c14 [1028];
  int local_810;
  char local_80c [1024];
  char local_40c [1024];
  uint local_c;
  int local_8;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_8 = *(int *)(in_ECX + 0x10c);
  if (param_1 + param_2 != *(int *)(in_ECX + 0x10c) + -1) {
    _sprintf(local_40c,"Assertion: %s @ %s:%d","seek_to + count == _framecount - 1",
             "..\\source\\sync.cpp",0x54);
    FUN_10021ff0(&DAT_10030a54,local_40c);
    FUN_10021ff0(&DAT_10030a58);
    FUN_10021ff0(&DAT_10030a5c);
    FUN_10021ff0(&DAT_10030a60);
    MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  FUN_10021ff0("Catching up\n");
  FUN_1001fef0(param_1);
  if (*(int *)(in_ECX + 0x10c) == param_1 + 1) {
    for (local_810 = 0; local_810 < param_2; local_810 = local_810 + 1) {
      (**(code **)(in_ECX + 0x18))(0);
    }
    if (*(int *)(in_ECX + 0x10c) == local_8) {
      FUN_10021ff0(&DAT_10030b6c);
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    _sprintf(local_c14,"Assertion: %s @ %s:%d","_framecount == framecount","..\\source\\sync.cpp",
             100);
    FUN_10021ff0(&DAT_10030b44,local_c14);
    FUN_10021ff0(&DAT_10030b48);
    FUN_10021ff0(&DAT_10030b4c);
    FUN_10021ff0(&DAT_10030b50);
    MessageBoxA((HWND)0x0,local_c14,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  _sprintf(local_80c,"Assertion: %s @ %s:%d","_framecount == seek_to + 1","..\\source\\sync.cpp",
           0x5b);
  FUN_10021ff0(&DAT_10030ad4,local_80c);
  FUN_10021ff0(&DAT_10030ad8);
  FUN_10021ff0(&DAT_10030adc);
  FUN_10021ff0(&DAT_10030ae0);
  MessageBoxA((HWND)0x0,local_80c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
