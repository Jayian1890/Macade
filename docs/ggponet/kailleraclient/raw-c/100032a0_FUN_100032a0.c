
int __thiscall FUN_100032a0(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)this + 0x1c);
  iVar2 = (*(int *)((int)this + 0x18) - iVar1) + param_1;
  if ((-1 < param_1) && (param_1 <= iVar1)) {
    if (iVar2 < 0) {
      iVar2 = iVar2 + *(int *)((int)this + 0x10);
    }
    if (*(int *)((int)this + 0x10) <= iVar2) {
      iVar2 = iVar2 - *(int *)((int)this + 0x10);
    }
    if (param_2 != 0) {
      *(int *)((int)this + 0x1c) = iVar1 + -1;
    }
    return (int)*(char *)(*(int *)((int)this + 8) + iVar2);
  }
  return -1;
}
