
undefined4 __thiscall FUN_10003150(void *this,undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar1 = FUN_10003140((int)this);
  if (iVar1 < (int)param_2) {
    return 0xffffffff;
  }
  iVar1 = *(int *)((int)this + 0x14);
  iVar4 = *(int *)((int)this + 0x20) + *(int *)((int)this + 0x24);
  if (iVar1 <= iVar4) {
    iVar4 = iVar4 - iVar1;
  }
  uVar3 = iVar1 - iVar4;
  if ((int)param_2 < iVar1 - iVar4) {
    uVar3 = param_2;
  }
  puVar5 = param_1;
  puVar6 = (undefined4 *)(*(int *)((int)this + 0xc) + iVar4);
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  if ((int)uVar3 < (int)param_2) {
    puVar5 = (undefined4 *)(uVar3 + (int)param_1);
    puVar6 = *(undefined4 **)((int)this + 0xc);
    for (uVar2 = param_2 - uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    for (uVar3 = param_2 - uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
  }
  *(uint *)((int)this + 0x24) = *(int *)((int)this + 0x24) + param_2;
  return 0;
}
