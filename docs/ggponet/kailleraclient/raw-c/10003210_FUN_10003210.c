
void __thiscall FUN_10003210(void *this,undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar2 = *(uint *)((int)this + 0x1c);
  if ((int)uVar2 < (int)param_2) {
    param_2 = uVar2;
  }
  iVar4 = *(int *)((int)this + 0x18) - uVar2;
  if (iVar4 < 0) {
    iVar4 = iVar4 + *(int *)((int)this + 0x10);
  }
  uVar2 = *(int *)((int)this + 0x10) - iVar4;
  if ((int)param_2 < (int)uVar2) {
    uVar2 = param_2;
  }
  puVar3 = (undefined4 *)(*(int *)((int)this + 8) + iVar4);
  puVar5 = param_1;
  for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  for (uVar1 = uVar2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  if ((int)uVar2 < (int)param_2) {
    puVar3 = *(undefined4 **)((int)this + 8);
    puVar5 = (undefined4 *)((int)param_1 + uVar2);
    for (uVar1 = param_2 - uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar2 = param_2 - uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  return;
}
