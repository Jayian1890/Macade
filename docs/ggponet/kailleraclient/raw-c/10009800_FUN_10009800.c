
void FUN_10009800(void)

{
  tagRECT local_20;
  tagRECT local_10;
  
  DAT_1000f16c = GetForegroundWindow();
  DAT_1000f1d8 = CreateDialogParamA(DAT_1000edb4,(LPCSTR)0x6d,DAT_1000f16c,(DLGPROC)&LAB_100098b0,0)
  ;
  GetWindowRect(DAT_1000f16c,&local_10);
  GetWindowRect(DAT_1000f1d8,&local_20);
  MoveWindow(DAT_1000f1d8,
             ((local_10.right - local_10.left) - (local_20.right - local_20.left)) / 2 +
             local_10.left,
             ((local_10.bottom - local_10.top) - (local_20.bottom - local_20.top)) / 2 +
             local_10.top,local_20.right - local_20.left,local_20.bottom - local_20.top,0);
  ShowWindow(DAT_1000f1d8,5);
  return;
}
