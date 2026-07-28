
void __thiscall FUN_10001d80(void *this,undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  FUN_10001cf0(this,param_2 + *(int *)((int)this + 0x2c));
  puVar2 = (undefined4 *)(*(int *)((int)this + 0x24) + *(int *)((int)this + 0x2c));
  for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  *(uint *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + param_2;
  return;
}
