
void __thiscall FUN_10004180(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  tagRECT local_30;
  undefined4 local_20;
  int local_1c [7];
  
  GetClientRect(*(HWND *)this,&local_30);
  local_30.right = local_30.right + (-2 - local_30.left);
  piVar2 = local_1c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  local_20 = 6;
  local_1c[2] = param_1;
  if (param_2 != 0) {
    local_1c[1] = MulDiv(local_30.right,param_2,100);
  }
  SendMessageA(*(HWND *)this,0x101b,*(WPARAM *)((int)this + 4),(LPARAM)&local_20);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}
