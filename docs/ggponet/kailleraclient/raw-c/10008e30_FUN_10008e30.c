
void FUN_10008e30(void)

{
  BOOL BVar1;
  tagMSG local_1c;
  
  BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    BVar1 = IsDialogMessageA(DAT_1000f1d4,&local_1c);
    if (BVar1 == 0) {
      BVar1 = IsDialogMessageA(DAT_1000f120,&local_1c);
      if (BVar1 == 0) {
        TranslateMessage(&local_1c);
        DispatchMessageA(&local_1c);
      }
    }
  }
  return;
}
