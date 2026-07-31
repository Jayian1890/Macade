
uint FUN_1000bad0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (((in_ECX != 0) && (iVar1 = *(int *)(in_ECX + 0x1c), iVar1 != 0)) &&
     ((iVar2 = *(int *)(iVar1 + 4), iVar2 == 0x2a || ((iVar2 == 0x71 || (iVar2 == 0x29a)))))) {
    if (*(int *)(iVar1 + 8) != 0) {
      (**(code **)(in_ECX + 0x24))();
    }
    if (*(int *)(*(int *)(in_ECX + 0x1c) + 0x3c) != 0) {
      (**(code **)(in_ECX + 0x24))();
    }
    if (*(int *)(*(int *)(in_ECX + 0x1c) + 0x38) != 0) {
      (**(code **)(in_ECX + 0x24))();
    }
    if (*(int *)(*(int *)(in_ECX + 0x1c) + 0x30) != 0) {
      (**(code **)(in_ECX + 0x24))();
    }
    (**(code **)(in_ECX + 0x24))();
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return (iVar2 != 0x71) - 1 & 0xfffffffd;
  }
  return 0xfffffffe;
}
