
void __thiscall FUN_10004c50(void *this,undefined4 param_1)

{
  UINT X;
  UINT Y;
  UINT cx;
  UINT cy;
  HWND hWnd;
  tagRECT *lpRect;
  tagRECT local_220;
  tagRECT local_210;
  CHAR local_200 [512];
  
  GetWindowRect(*(HWND *)this,&local_220);
  wsprintfA(local_200,&DAT_1000e244,param_1);
  X = FUN_100019d0(DAT_1000ef90,local_200,local_220.left);
  wsprintfA(local_200,&DAT_1000e23c,param_1);
  Y = FUN_100019d0(DAT_1000ef90,local_200,local_220.top);
  wsprintfA(local_200,s__s_cx_1000e234,param_1);
  cx = FUN_100019d0(DAT_1000ef90,local_200,local_220.right - local_220.left);
  wsprintfA(local_200,s__s_cy_1000e22c,param_1);
  cy = FUN_100019d0(DAT_1000ef90,local_200,local_220.bottom - local_220.top);
  lpRect = &local_210;
  hWnd = GetDesktopWindow();
  GetWindowRect(hWnd,lpRect);
  if (((int)X <= local_210.right) && ((int)Y <= local_210.bottom)) {
    SetWindowPos(*(HWND *)this,(HWND)0x0,X,Y,cx,cy,0x404);
  }
  return;
}
