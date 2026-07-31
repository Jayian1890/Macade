
undefined4 FUN_10027ae0(void *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t _Size;
  int local_c;
  
  iVar1 = FUN_10008a70();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_3 < 3) {
      local_c = param_3;
    }
    else {
      local_c = 2;
    }
    _Size = param_2 * local_c;
    iVar1 = FUN_10002dc0();
    _memcpy(param_1,(void *)(iVar1 + 8),_Size);
    FUN_10002e00();
    uVar2 = 1;
  }
  return uVar2;
}
