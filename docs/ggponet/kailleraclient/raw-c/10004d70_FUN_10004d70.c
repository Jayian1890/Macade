
void __thiscall FUN_10004d70(void *this,undefined4 param_1)

{
  tagRECT local_210;
  CHAR local_200 [512];
  
  GetWindowRect(*(HWND *)this,&local_210);
  wsprintfA(local_200,&DAT_1000e244,param_1);
  FUN_10001900(DAT_1000ef90,local_200,local_210.left,1);
  wsprintfA(local_200,&DAT_1000e23c,param_1);
  FUN_10001900(DAT_1000ef90,local_200,local_210.top,1);
  wsprintfA(local_200,s__s_cx_1000e234,param_1);
  FUN_10001900(DAT_1000ef90,local_200,local_210.right - local_210.left,1);
  wsprintfA(local_200,s__s_cy_1000e22c,param_1);
  FUN_10001900(DAT_1000ef90,local_200,local_210.bottom - local_210.top,1);
  FUN_10001640(DAT_1000ef90);
  return;
}
