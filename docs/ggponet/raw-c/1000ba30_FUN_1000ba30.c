
void FUN_1000ba30(void)

{
  int in_ECX;
  undefined4 in_EDX;
  int iVar1;
  
  *(char *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) = (char)((uint)in_EDX >> 8);
  iVar1 = *(int *)(in_ECX + 0x14) + 1;
  *(int *)(in_ECX + 0x14) = iVar1;
  *(char *)(*(int *)(in_ECX + 8) + iVar1) = (char)in_EDX;
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  return;
}
