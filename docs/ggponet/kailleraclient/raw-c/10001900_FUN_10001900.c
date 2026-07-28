
void __thiscall FUN_10001900(void *this,char *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)((int)this + 8)) {
    iVar3 = 0;
    do {
      iVar1 = strncmp(param_1,(char *)(iVar3 + *(int *)this),0x10);
      if (iVar1 == 0) {
        *(undefined4 *)(iVar4 * 0x18 + 0x14 + *(int *)this) = 1;
        *(undefined4 *)(iVar4 * 0x18 + 0x10 + *(int *)this) = param_2;
        return;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x18;
    } while (iVar4 < *(int *)((int)this + 8));
  }
  if ((*(int *)((int)this + 0xc) <= *(int *)((int)this + 8)) || (*(int *)this == 0)) {
    iVar4 = *(int *)((int)this + 8) + 8;
    *(int *)((int)this + 0xc) = iVar4;
    pvVar2 = realloc(*(void **)this,iVar4 * 0x18);
    *(void **)this = pvVar2;
  }
  strncpy((char *)(*(int *)this + *(int *)((int)this + 8) * 0x18),param_1,0x10);
  *(undefined4 *)(*(int *)this + 0x14 + *(int *)((int)this + 8) * 0x18) = param_3;
  *(undefined4 *)(*(int *)this + 0x10 + *(int *)((int)this + 8) * 0x18) = param_2;
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  return;
}
