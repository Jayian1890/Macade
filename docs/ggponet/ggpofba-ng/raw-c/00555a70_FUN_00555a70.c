
undefined4 FUN_00555a70(void)

{
  HWND hWnd;
  int iVar1;
  HDC hDC;
  tagPOINT tStack_a4;
  tagRECT tStack_9c;
  undefined4 local_84;
  undefined4 uStack_80;
  int iStack_7c;
  int iStack_78;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_1c;
  
  if (DAT_00b19c9c != (int *)0x0) {
    (**(code **)(*DAT_00b19c9c + 8))(DAT_00b19c9c);
  }
  DAT_00b19c9c = (int *)0x0;
  _memset(&local_84,0,0x7c);
  hWnd = DAT_00ad7508;
  local_84 = 0x7c;
  uStack_80 = 0x10007;
  uStack_1c = 0x4040;
  if (DAT_00b19814 == 0) {
    iStack_78 = DAT_009965d8 - DAT_009965d0;
    iStack_7c = DAT_009965dc - DAT_009965d4;
  }
  else {
    tStack_a4.x = 0;
    tStack_a4.y = 0;
    GetClientRect(DAT_00ad7508,&tStack_9c);
    ClientToScreen(hWnd,&tStack_a4);
    tStack_9c.left = tStack_9c.left + tStack_a4.x;
    tStack_9c.right = tStack_9c.right + tStack_a4.x;
    tStack_9c.bottom = tStack_9c.bottom + tStack_a4.y;
    tStack_9c.top = tStack_9c.top + tStack_a4.y;
    iStack_78 = tStack_9c.right - tStack_9c.left;
    iStack_7c = tStack_9c.bottom - tStack_9c.top;
  }
  uStack_44 = 1;
  uStack_40 = 1;
  iVar1 = (**(code **)(*DAT_00b19da0 + 0x18))(DAT_00b19da0,&local_84,&DAT_00b19c9c,0);
  if (iVar1 < 0) {
    return 1;
  }
  tStack_9c.left = 1;
  tStack_9c.top = 1;
  (**(code **)(*DAT_00b19c9c + 0x74))(DAT_00b19c9c,8,&tStack_9c);
  FUN_00553010(1,0);
  if (DAT_00b19994 == (HGDIOBJ)0x0) {
    DAT_00b19994 = LoadImageA(DAT_00ad6f40,"BMP_GGPO",0,0,0,0);
  }
  if (DAT_00b19c98 == (HDC)0x0) {
    hDC = GetDC((HWND)0x0);
    DAT_00b19c98 = CreateCompatibleDC((HDC)0x0);
    SelectObject(DAT_00b19c98,DAT_00b19994);
    ReleaseDC((HWND)0x0,hDC);
  }
  DAT_00b189d3 = 1;
  return 0;
}
