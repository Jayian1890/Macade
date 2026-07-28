
uint FUN_1000e870(void)

{
  uint uVar1;
  uint uVar2;
  uint in_ECX;
  int in_EDX;
  uint uVar3;
  
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    uVar3 = in_ECX & 1;
    in_ECX = in_ECX >> 1;
    in_EDX = in_EDX + -1;
    uVar1 = (uVar2 | uVar3) << 1;
  } while (0 < in_EDX);
  return uVar2 & 0x7fffffff | uVar3;
}
