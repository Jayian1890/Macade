
undefined4 FUN_1000c7b0(void)

{
  uint *puVar1;
  int in_ECX;
  
  if ((in_ECX != 0) && (puVar1 = *(uint **)(in_ECX + 0x1c), puVar1 != (uint *)0x0)) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *puVar1 = -(uint)(puVar1[3] != 0) & 7;
    FUN_1000ea40(0);
    return 0;
  }
  return 0xfffffffe;
}
