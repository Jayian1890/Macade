
undefined4 __thiscall FUN_10001ba0(void *this,char *param_1,LPCSTR param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  CHAR local_800 [2048];
  
  iVar3 = 0;
  if (0 < *(int *)((int)this + 0x10)) {
    iVar4 = 0;
    do {
      iVar1 = strncmp(param_1,(char *)(*(int *)((int)this + 4) + iVar4),0x10);
      if (iVar1 == 0) {
        return *(undefined4 *)(*(int *)((int)this + 4) + 0x10 + iVar3 * 0x18);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar3 < *(int *)((int)this + 0x10));
  }
  GetPrivateProfileStringA
            ((LPCSTR)((int)this + 0x11c),param_1,param_2,local_800,0x800,(LPCSTR)((int)this + 0x18))
  ;
  uVar2 = FUN_10001a50(this,param_1,local_800,0);
  return uVar2;
}
