
void FUN_100221f0(int param_1)

{
  int in_ECX;
  int local_410;
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 4) != 0) {
    for (local_410 = 0; local_410 < *(int *)(in_ECX + 4); local_410 = local_410 + 1) {
      *(byte *)(in_ECX + local_410 + 8) =
           *(byte *)(in_ECX + local_410 + 8) | *(byte *)(param_1 + local_410 + 8);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  _sprintf(local_40c,"Assertion: %s @ %s:%d",&DAT_10031a88,"..\\source\\game_input.cpp",0x45);
  FUN_10021ff0(&DAT_10031aa8,local_40c);
  FUN_10021ff0(&DAT_10031aac);
  FUN_10021ff0(&DAT_10031ab0);
  FUN_10021ff0(&DAT_10031ab4);
  MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
