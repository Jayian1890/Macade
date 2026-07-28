
void __thiscall FUN_10001dd0(void *this,undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  uVar1 = *(uint *)((int)this + 0x2c);
  if (uVar1 != 0) {
    if ((int)uVar1 < (int)param_2) {
      param_2 = uVar1;
    }
    puVar3 = *(undefined4 **)((int)this + 0x24);
    for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_1 = *puVar3;
      puVar3 = puVar3 + 1;
      param_1 = param_1 + 1;
    }
    for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)param_1 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    uVar2 = *(int *)((int)this + 0x2c) - param_2;
    *(uint *)((int)this + 0x2c) = uVar2;
    puVar3 = (undefined4 *)((int)*(undefined4 **)((int)this + 0x24) + param_2);
    puVar4 = *(undefined4 **)((int)this + 0x24);
    for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  return;
}
