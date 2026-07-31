
void FUN_1000e800(void)

{
  ushort uVar1;
  ushort *puVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  uVar5 = 0;
  puVar2 = (ushort *)(in_ECX + 0x8c);
  iVar3 = 7;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 2;
    uVar5 = uVar5 + uVar1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = (ushort *)(in_ECX + 0xa8);
  iVar3 = 0x79;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 2;
    uVar4 = uVar4 + uVar1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar2 = (ushort *)(in_ECX + 0x28c);
  iVar3 = 0x80;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 2;
    uVar5 = uVar5 + uVar1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(bool *)(in_ECX + 0x1c) = uVar5 <= uVar4 >> 2;
  return;
}
