
undefined4 __cdecl FUN_1000b650(HWND param_1)

{
  int iVar1;
  
  iVar1 = GetWindowTextLengthA(DAT_1000f40c);
  if (iVar1 == 0) {
    MessageBoxA(param_1,s_You_must_enter_a_user_name__1000e9b0,s_Error_1000e7d0,0);
    return 0;
  }
  GetWindowTextA(DAT_1000f40c,&DAT_1000edc8,0x1f);
  return 1;
}
