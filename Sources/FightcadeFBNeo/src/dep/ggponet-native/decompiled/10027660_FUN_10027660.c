
undefined4 FUN_10027660(void *param_1,int param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  size_t _Size;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_10;
  
  if (param_3 < 2) {
    local_10 = param_3;
  }
  else {
    local_10 = 2;
  }
  _Size = param_2 * local_10;
  FUN_10027580(0);
  if (*(char *)(in_ECX + 0x29d) == '\0') {
    if (*(char *)(in_ECX + 0x29c) == '\0') {
      _memcpy((void *)(in_ECX + 0x32c),param_1,_Size);
    }
    else {
      _memset((void *)(in_ECX + 0x32c),0,_Size);
    }
  }
  else {
    iVar1 = FUN_100035a0();
    puVar3 = (undefined4 *)(iVar1 + 0x10);
    puVar4 = (undefined4 *)(in_ECX + 0x324);
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  _memcpy(param_1,(void *)(in_ECX + 0x32c),_Size);
  return 1;
}
