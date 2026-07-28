
void __cdecl FUN_10008cd0(int param_1,int param_2)

{
  LRESULT LVar1;
  int *lParam;
  HMENU hMenu;
  BOOL BVar2;
  WPARAM wParam;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  tagRECT local_138;
  undefined1 local_128 [8];
  undefined4 local_120;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_100 [256];
  
  if (DAT_1000eeec != (code *)0x0) {
    GetWindowRect(DAT_1000f138,&local_138);
    LVar1 = SendMessageA(DAT_1000f138,0x1004,0,0);
    wParam = 0;
    if (0 < LVar1) {
      while( true ) {
        if (&stack0x00000000 == (undefined1 *)0x148) {
          lParam = (int *)0x0;
        }
        else {
          local_148 = 0;
          lParam = &local_148;
        }
        SendMessageA(DAT_1000f138,0x100e,wParam,(LPARAM)lParam);
        if ((((local_148 <= param_1 - local_138.left) && (param_1 - local_138.left <= local_140)) &&
            (local_144 <= param_2 - local_138.top)) && (param_2 - local_138.top <= local_13c))
        break;
        wParam = wParam + 1;
        if (LVar1 <= (int)wParam) {
          return;
        }
      }
      if (wParam != 0xffffffff) {
        hMenu = CreatePopupMenu();
        AppendMenuA(hMenu,0,1,s_More_infos_about_this_game____1000e7d8);
        BVar2 = TrackPopupMenu(hMenu,0x100,param_1,param_2,0,DAT_1000f138,(RECT *)0x0);
        if (BVar2 == 1) {
          local_114 = local_100;
          local_120 = 0;
          local_110 = 0xff;
          SendMessageA(DAT_1000f138,0x102d,wParam,(LPARAM)local_128);
          (*DAT_1000eeec)(local_100);
        }
        DestroyMenu(hMenu);
      }
    }
  }
  return;
}
