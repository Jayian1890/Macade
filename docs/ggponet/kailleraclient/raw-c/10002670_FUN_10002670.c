
undefined4 * __thiscall FUN_10002670(void *this,int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  *(undefined4 *)((int)this + 8) = 1;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(int *)((int)this + 4) = param_1;
  puVar1 = malloc(param_1 * 0x10c);
  *(undefined4 **)this = puVar1;
  for (uVar2 = *(int *)((int)this + 4) * 0x43 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar1 = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return this;
}
