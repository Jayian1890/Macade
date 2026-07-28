
undefined4 FUN_1000c830(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int in_EDX;
  
  if (((param_1 == (char *)0x0) || (*param_1 != s_1_1_4_10036000[0])) || (param_2 != 0x38)) {
    return 0xfffffffa;
  }
  if (in_ECX == 0) {
    return 0xfffffffe;
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  if (*(int *)(in_ECX + 0x20) == 0) {
    *(code **)(in_ECX + 0x20) = FUN_1000cda0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  if (*(int *)(in_ECX + 0x24) == 0) {
    *(undefined1 **)(in_ECX + 0x24) = &LAB_1000cdc0;
  }
  iVar1 = (**(code **)(in_ECX + 0x20))(0x18);
  *(int *)(in_ECX + 0x1c) = iVar1;
  if (iVar1 == 0) {
    return 0xfffffffc;
  }
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0xc) = 0;
  if (in_EDX < 0) {
    in_EDX = -in_EDX;
    *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0xc) = 1;
  }
  if ((7 < in_EDX) && (in_EDX < 0x10)) {
    *(int *)(*(int *)(in_ECX + 0x1c) + 0x10) = in_EDX;
    uVar2 = FUN_1000eab0(1 << ((byte)in_EDX & 0x1f));
    *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0x14) = uVar2;
    if (*(int *)(*(int *)(in_ECX + 0x1c) + 0x14) == 0) {
      FUN_1000c7f0();
      return 0xfffffffc;
    }
    FUN_1000c7b0();
    return 0;
  }
  FUN_1000c7f0();
  return 0xfffffffe;
}
