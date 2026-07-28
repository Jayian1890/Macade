
void __cdecl FUN_10008510(int param_1)

{
  LRESULT LVar1;
  int iVar2;
  WPARAM wParam;
  
  wParam = 0;
  LVar1 = SendMessageA(DAT_1000f138,0x1004,0,0);
  if (0 < LVar1) {
    do {
      iVar2 = FUN_10004210(&DAT_1000f138,wParam);
      if (iVar2 == param_1) {
        SendMessageA(DAT_1000f138,0x1008,wParam,0);
        wParam = wParam - 1;
      }
      wParam = wParam + 1;
      LVar1 = SendMessageA(DAT_1000f138,0x1004,0,0);
    } while ((int)wParam < LVar1);
  }
  return;
}
