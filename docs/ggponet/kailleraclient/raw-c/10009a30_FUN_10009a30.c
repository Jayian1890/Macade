
void __thiscall FUN_10009a30(void *this,int param_1)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar4 = *(int *)this;
  if (((iVar4 != 0) && (-1 < param_1)) && (param_1 < *(int *)((int)this + 4))) {
    iVar2 = *(int *)((int)this + 4) + -1;
    *(int *)((int)this + 4) = iVar2;
    if (param_1 != iVar2) {
      puVar5 = (undefined4 *)(iVar4 + 4 + param_1 * 4);
      puVar6 = (undefined4 *)(iVar4 + param_1 * 4);
      for (uVar3 = iVar2 - param_1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar6 = (undefined4 *)((int)puVar6 + 1);
      }
    }
    uVar3 = *(uint *)((int)this + 4);
    if (((uVar3 & 0x1f) == 0) && (uVar3 != 0)) {
      pvVar1 = realloc(*(void **)this,uVar3 * 4);
      *(void **)this = pvVar1;
    }
  }
  return;
}
