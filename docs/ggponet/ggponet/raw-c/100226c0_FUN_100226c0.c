
void FUN_100226c0(char *param_1,char param_2)

{
  char cVar1;
  undefined4 *in_ECX;
  char local_420 [16];
  int local_410;
  char local_40c [1024];
  uint local_c;
  undefined4 local_8;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (in_ECX[1] != 0) {
    local_8 = 0;
    if (param_2 == '\0') {
      _sprintf(param_1,"(size:%d ",in_ECX[1]);
    }
    else {
      _sprintf(param_1,"(frame:%d size:%d ",*in_ECX,in_ECX[1]);
    }
    for (local_410 = 0; local_410 < in_ECX[1] * 8; local_410 = local_410 + 1) {
      cVar1 = FUN_10008970(local_410);
      if (cVar1 != '\0') {
        _sprintf(local_420,"%2d ",local_410);
        FUN_10011490(param_1,local_420);
      }
    }
    FUN_10011490(param_1,&DAT_10031a64);
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  _sprintf(local_40c,"Assertion: %s @ %s:%d",&DAT_100319f4,"..\\source\\game_input.cpp",0x27);
  FUN_10021ff0(&DAT_10031a14,local_40c);
  FUN_10021ff0(&DAT_10031a18);
  FUN_10021ff0(&DAT_10031a1c);
  FUN_10021ff0(&DAT_10031a20);
  MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
