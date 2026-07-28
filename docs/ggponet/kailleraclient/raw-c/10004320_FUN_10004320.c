
int __thiscall FUN_10004320(void *this,char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)((int)this + 0x10) == 0) {
    iVar1 = _stricmp(param_1,param_2);
    if (*(int *)((int)this + 0xc) == -1) {
      iVar1 = -iVar1;
    }
  }
  else {
    if (*param_1 == '>') {
      return (-(uint)(*(int *)((int)this + 0xc) != -1) & 2) - 1;
    }
    if (*param_2 == '>') {
      return (-(uint)(*(int *)((int)this + 0xc) != -1) & 0xfffffffe) + 1;
    }
    iVar1 = atoi(param_1);
    iVar2 = atoi(param_2);
    iVar1 = iVar1 - iVar2;
    if (*(int *)((int)this + 0xc) == -1) {
      return -iVar1;
    }
  }
  return iVar1;
}
