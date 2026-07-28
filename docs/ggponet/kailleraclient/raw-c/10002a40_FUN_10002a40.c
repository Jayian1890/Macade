
undefined4 * __thiscall FUN_10002a40(void *this,int param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  puStack_8 = &DAT_1000c94b;
  *unaff_FS_OFFSET = &local_c;
  *(undefined1 **)((int)this + 0x144) = &DAT_1000ec9c;
  if (param_1 == -1) {
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_10002670(pvVar1,0x40);
    }
    *(undefined4 **)((int)this + 0x138) = puVar2;
    *(undefined4 *)((int)this + 0x13c) = 1;
  }
  else {
    *(int *)((int)this + 0x138) = param_1;
    *(undefined4 *)((int)this + 0x13c) = 0;
  }
  *(uint *)((int)this + 0x10) = param_3;
  *(uint *)((int)this + 0x14) = param_2;
  pvVar1 = malloc(param_3);
  *(void **)((int)this + 8) = pvVar1;
  pvVar1 = malloc(*(size_t *)((int)this + 0x14));
  *(void **)((int)this + 0xc) = pvVar1;
  *(undefined4 *)this = 0xffffffff;
  puVar2 = *(undefined4 **)((int)this + 8);
  for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  puVar2 = *(undefined4 **)((int)this + 0xc);
  for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  for (uVar3 = param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar2 = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  *(undefined2 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x140) = 1;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined1 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}
