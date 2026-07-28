
void __thiscall FUN_10009ab0(void *this,undefined4 *param_1,uint param_2)

{
  int iVar1;
  void *pvVar2;
  size_t _NewSize;
  uint uVar3;
  undefined4 *puVar4;
  
  if ((int)param_2 < 1) {
    return;
  }
  if (*(void **)this == (void *)0x0) {
    *(uint *)((int)this + 8) = param_2 << 4;
    pvVar2 = malloc(param_2 << 4);
  }
  else {
    iVar1 = *(int *)((int)this + 4) + param_2;
    _NewSize = *(size_t *)((int)this + 8);
    if (iVar1 <= (int)_NewSize) goto LAB_10009b03;
    do {
      _NewSize = _NewSize * 2;
    } while ((int)_NewSize < iVar1);
    *(size_t *)((int)this + 8) = _NewSize;
    pvVar2 = realloc(*(void **)this,_NewSize);
  }
  *(void **)this = pvVar2;
LAB_10009b03:
  puVar4 = (undefined4 *)(*(int *)this + *(int *)((int)this + 4));
  for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)param_1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_2;
  return;
}
