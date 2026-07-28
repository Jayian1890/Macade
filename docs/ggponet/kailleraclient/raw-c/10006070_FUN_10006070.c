
void FUN_10006070(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_40 [13];
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1000ca30;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  DAT_1000f1dc = 0;
  DAT_1000f184 = GetTickCount();
  FUN_10001c40(local_40);
  local_4 = 0;
  local_40[0] = 0x14;
  FUN_10001f00(local_40);
  local_4 = 1;
  FUN_100010d0();
  local_4 = 0xffffffff;
  FUN_10001c70((int)local_40);
  if (DAT_1000f1d8 != (HWND)0x0) {
    DestroyWindow(DAT_1000f1d8);
  }
  DAT_1000f1d8 = (HWND)0x0;
  SetFocus(DAT_1000f120);
  SetTimer(DAT_1000f120,0xd1ed1e,10,(TIMERPROC)0x0);
  *unaff_FS_OFFSET = local_c;
  return;
}
