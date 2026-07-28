
void __thiscall FUN_1000c680(void *this,LONG *param_1)

{
  tagRECT local_10;
  
  GetClientRect(*(HWND *)this,&local_10);
  SendMessageA(*(HWND *)this,0x1328,0,(LPARAM)&local_10);
  *param_1 = local_10.left;
  param_1[1] = local_10.top;
  param_1[2] = local_10.right;
  param_1[3] = local_10.bottom;
  return;
}
