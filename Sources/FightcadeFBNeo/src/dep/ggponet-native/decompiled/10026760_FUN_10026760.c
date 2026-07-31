
void FUN_10026760(undefined4 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x44) = 2;
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  iVar2 = Ordinal_52(param_1[1]);
  if (iVar2 == 0) {
    uVar3 = Ordinal_11(param_1[1]);
    *(undefined4 *)(in_ECX + 0x48) = uVar3;
  }
  else {
    _memcpy((void *)(in_ECX + 0x48),(void *)**(undefined4 **)(iVar2 + 0xc),4);
  }
  uVar1 = Ordinal_9(*(undefined2 *)(param_1 + 2));
  *(undefined2 *)(in_ECX + 0x46) = uVar1;
  FUN_10028330(in_ECX,*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x2c));
  FUN_10028330(in_ECX,*(undefined4 *)(in_ECX + 0x40),*(undefined4 *)(in_ECX + 0x40));
  return;
}
