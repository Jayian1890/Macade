
undefined4 __thiscall FUN_10004210(void *this,undefined4 param_1)

{
  HWND hWnd;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28;
  undefined4 local_24 [7];
  undefined4 local_8;
  
  hWnd = *(HWND *)this;
  puVar2 = local_24;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_28 = 4;
  local_24[0] = param_1;
  SendMessageA(hWnd,0x1005,0,(LPARAM)&local_28);
  return local_8;
}
