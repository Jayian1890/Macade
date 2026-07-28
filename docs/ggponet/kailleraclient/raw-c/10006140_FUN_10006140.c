
undefined4 __cdecl FUN_10006140(HWND param_1)

{
  HWND hWnd;
  BOOL BVar1;
  tagMSG local_1c;
  
  hWnd = CreateDialogParamA(DAT_1000edb4,(LPCSTR)0x68,param_1,(DLGPROC)&LAB_100061f0,0);
  ShowWindow(hWnd,5);
  while (DAT_1000f1e8 == 0) {
    BVar1 = GetMessageA(&local_1c,(HWND)0x0,0,0);
    if (((BVar1 != 0) && (BVar1 = IsDialogMessageA(DAT_1000f1d4,&local_1c), BVar1 == 0)) &&
       (BVar1 = IsDialogMessageA(hWnd,&local_1c), BVar1 == 0)) {
      TranslateMessage(&local_1c);
      DispatchMessageA(&local_1c);
    }
  }
  DestroyWindow(hWnd);
  return 0;
}
