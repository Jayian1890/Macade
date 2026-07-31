
void FUN_1000cf80(void)

{
  undefined2 *puVar1;
  int in_ECX;
  int iVar2;
  
  puVar1 = (undefined2 *)(in_ECX + 0x8c);
  iVar2 = 0x11e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined2 *)(in_ECX + 0x980);
  iVar2 = 0x1e;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar1 = (undefined2 *)(in_ECX + 0xa74);
  iVar2 = 0x13;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(in_ECX + 0x16a4) = 0;
  *(undefined4 *)(in_ECX + 0x16a0) = 0;
  *(undefined4 *)(in_ECX + 0x16a8) = 0;
  *(undefined4 *)(in_ECX + 0x1698) = 0;
  *(undefined2 *)(in_ECX + 0x48c) = 1;
  return;
}
