
void __cdecl FUN_10008570(int param_1)

{
  uint nCmdShow;
  HWND pHVar1;
  uint uVar2;
  
  nCmdShow = (uint)(param_1 != 0);
  uVar2 = nCmdShow;
  pHVar1 = GetDlgItem(DAT_1000f120,0x3f0);
  ShowWindow(pHVar1,uVar2);
  uVar2 = nCmdShow;
  pHVar1 = GetDlgItem(DAT_1000f120,0x3f1);
  ShowWindow(pHVar1,uVar2);
  uVar2 = nCmdShow;
  pHVar1 = GetDlgItem(DAT_1000f120,0x3f2);
  ShowWindow(pHVar1,uVar2);
  pHVar1 = GetDlgItem(DAT_1000f120,0x3f7);
  ShowWindow(pHVar1,nCmdShow);
  return;
}
