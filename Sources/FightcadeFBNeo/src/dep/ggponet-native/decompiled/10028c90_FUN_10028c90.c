
undefined4 FUN_10028c90(void *param_1,int param_2,int param_3)

{
  int iVar1;
  size_t _Size;
  char *pcVar2;
  undefined4 uVar3;
  int local_c;
  
  iVar1 = FUN_10008a70();
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    pcVar2 = "confirmed input frame";
    FUN_10002dc0("confirmed input frame",0);
    FUN_10022860(pcVar2,uVar3);
    uVar3 = FUN_10008a70();
    FUN_10021ff0("Input queue length is %d.\n",uVar3);
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
    uVar3 = 1;
  }
  return uVar3;
}
