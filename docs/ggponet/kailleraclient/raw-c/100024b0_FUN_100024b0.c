
undefined4 __thiscall FUN_100024b0(void *this,undefined4 param_1,int *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_14;
  undefined1 local_10 [8];
  int *piStack_8;
  
  *(undefined4 *)((int)this + 0xc) = 0;
  iVar1 = *param_2;
  local_14 = 0x10;
  iVar2 = Ordinal_17(*(undefined4 *)((int)this + 8),param_1);
  if (iVar2 == -1) {
    return 1;
  }
  *param_2 = iVar2;
  if (piStack_8 != (int *)0x0) {
    *piStack_8 = iVar1;
    piStack_8[1] = -(uint)(param_3 != '\0') & 2;
    piStack_8[2] = (int)local_10;
    piStack_8[3] = (int)&local_14;
  }
  return 0;
}
