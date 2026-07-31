
undefined4 FUN_1000c7f0(void)

{
  int in_ECX;
  
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x1c) != 0)) && (*(int *)(in_ECX + 0x24) != 0)) {
    if (*(int *)(*(int *)(in_ECX + 0x1c) + 0x14) != 0) {
      FUN_1000f810();
    }
    (**(code **)(in_ECX + 0x24))();
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return 0;
  }
  return 0xfffffffe;
}
