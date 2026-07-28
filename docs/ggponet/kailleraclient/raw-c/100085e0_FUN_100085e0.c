
void FUN_100085e0(void)

{
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_10;
  
  FUN_10008570(0);
  lpRect = &local_10;
  hWnd = GetDlgItem(DAT_1000f120,0x3f7);
  GetWindowRect(hWnd,lpRect);
  ScreenToClient(DAT_1000f120,(LPPOINT)&local_10);
  DAT_1000f1d4 = CreateDialogParamA(DAT_1000edb4,(LPCSTR)0x6a,DAT_1000f120,(DLGPROC)&LAB_10008680,0)
  ;
  SetWindowPos(DAT_1000f1d4,(HWND)0x0,local_10.left,local_10.top,local_10.right - local_10.left,
               local_10.bottom - local_10.top,0);
  ShowWindow(DAT_1000f1d4,1);
  return;
}
