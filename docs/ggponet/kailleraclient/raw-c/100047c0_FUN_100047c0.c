
void __thiscall
FUN_100047c0(void *this,int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  HWND pHVar1;
  
  if (param_1 == 0) {
    pHVar1 = (HWND)0x0;
  }
  else {
    pHVar1 = GetDlgItem(*(HWND *)this,param_1);
  }
  FUN_10004650(this,pHVar1,param_2,param_3,param_4,param_5,param_6);
  return;
}
