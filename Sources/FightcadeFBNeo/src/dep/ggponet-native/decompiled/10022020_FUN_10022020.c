
void FUN_10022020(int *param_1,char param_2)

{
  int iVar1;
  int *in_ECX;
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if ((param_2 == '\0') && (*in_ECX != *param_1)) {
    FUN_10021ff0("frames don\'t match: %d, %d\n",*in_ECX,*param_1);
  }
  if (in_ECX[1] != param_1[1]) {
    FUN_10021ff0("sizes don\'t match: %d, %d\n",in_ECX[1],param_1[1]);
  }
  iVar1 = _memcmp(in_ECX + 2,param_1 + 2,in_ECX[1]);
  if (iVar1 != 0) {
    FUN_10021ff0("bits don\'t match\n");
  }
  if ((in_ECX[1] != 0) && (param_1[1] != 0)) {
    if (((param_2 != '\0') || (*in_ECX == *param_1)) && (in_ECX[1] == param_1[1])) {
      _memcmp(in_ECX + 2,param_1 + 2,in_ECX[1]);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  _sprintf(local_40c,"Assertion: %s @ %s:%d","size && other.size","..\\source\\game_input.cpp",0x57)
  ;
  FUN_10021ff0(&DAT_10031b64,local_40c);
  FUN_10021ff0(&DAT_10031b68);
  FUN_10021ff0(&DAT_10031b6c);
  FUN_10021ff0(&DAT_10031b70);
  MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
