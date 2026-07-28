
void FUN_1000ba60(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar3 = *(uint *)(*(int *)(in_ECX + 0x1c) + 0x14);
  if (*(uint *)(in_ECX + 0x10) < uVar3) {
    uVar3 = *(uint *)(in_ECX + 0x10);
  }
  if (uVar3 != 0) {
    puVar4 = *(undefined4 **)(*(int *)(in_ECX + 0x1c) + 0x10);
    puVar5 = *(undefined4 **)(in_ECX + 0xc);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(uint *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + uVar3;
    *(uint *)(*(int *)(in_ECX + 0x1c) + 0x10) = *(int *)(*(int *)(in_ECX + 0x1c) + 0x10) + uVar3;
    *(uint *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + uVar3;
    *(uint *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) - uVar3;
    *(uint *)(*(int *)(in_ECX + 0x1c) + 0x14) = *(int *)(*(int *)(in_ECX + 0x1c) + 0x14) - uVar3;
    iVar1 = *(int *)(in_ECX + 0x1c);
    if (*(int *)(iVar1 + 0x14) == 0) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
    }
  }
  return;
}
