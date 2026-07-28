
void FUN_1000bb60(void)

{
  ushort uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x24) << 1;
  *(undefined2 *)(*(int *)(in_ECX + 0x3c) + -2 + *(int *)(in_ECX + 0x44) * 2) = 0;
  uVar4 = *(int *)(in_ECX + 0x44) * 2 - 2;
  puVar5 = *(undefined4 **)(in_ECX + 0x3c);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  iVar2 = *(int *)(in_ECX + 0x7c) * 0xc;
  *(uint *)(in_ECX + 0x78) = (uint)*(ushort *)(&DAT_1002e23a + iVar2);
  *(uint *)(in_ECX + 0x84) = (uint)*(ushort *)(&DAT_1002e238 + iVar2);
  *(uint *)(in_ECX + 0x88) = (uint)*(ushort *)(&DAT_1002e23c + iVar2);
  uVar1 = *(ushort *)(&DAT_1002e23e + iVar2);
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(uint *)(in_ECX + 0x74) = (uint)uVar1;
  *(undefined4 *)(in_ECX + 0x70) = 2;
  *(undefined4 *)(in_ECX + 0x58) = 2;
  return;
}
