
void __cdecl FUN_100082b0(undefined4 param_1)

{
  WPARAM wParam;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  while( true ) {
    local_c = 0;
    local_8 = 0;
    local_18 = 1;
    local_14 = 0;
    local_10 = param_1;
    local_4 = 0;
    wParam = SendMessageA(DAT_1000f170,0x100d,0xffffffff,(LPARAM)&local_18);
    if (wParam == 0xffffffff) break;
    SendMessageA(DAT_1000f170,0x1008,wParam,0);
    DAT_1000f1d0 = DAT_1000f1d0 + -1;
  }
  return;
}
