
undefined4 FUN_1000b710(void)

{
  int iVar1;
  int in_ECX;
  
  if ((((in_ECX != 0) && (iVar1 = *(int *)(in_ECX + 0x1c), iVar1 != 0)) &&
      (*(int *)(in_ECX + 0x20) != 0)) && (*(int *)(in_ECX + 0x24) != 0)) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 2;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
    if (*(int *)(iVar1 + 0x18) < 0) {
      *(undefined4 *)(iVar1 + 0x18) = 0;
    }
    *(uint *)(iVar1 + 4) = (-(uint)(*(int *)(iVar1 + 0x18) != 0) & 0x47) + 0x2a;
    *(undefined4 *)(in_ECX + 0x30) = 1;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    FUN_1000cf00();
    FUN_1000bb60();
    return 0;
  }
  return 0xfffffffe;
}
