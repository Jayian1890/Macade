
UINT __thiscall FUN_100019d0(void *this,char *param_1,INT param_2)

{
  int iVar1;
  UINT UVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < *(int *)((int)this + 8)) {
    iVar4 = 0;
    do {
      iVar1 = strncmp(param_1,(char *)(iVar4 + *(int *)this),0x10);
      if (iVar1 == 0) {
        return *(UINT *)(*(int *)this + 0x10 + iVar3 * 0x18);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar3 < *(int *)((int)this + 8));
  }
  UVar2 = GetPrivateProfileIntA
                    ((LPCSTR)((int)this + 0x11c),param_1,param_2,(LPCSTR)((int)this + 0x18));
  FUN_10001900(this,param_1,UVar2,0);
  return UVar2;
}
