
void __thiscall FUN_10003080(void *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (((param_1 == 0) && (iVar1 = *(int *)((int)this + 0x140), iVar1 != 2)) && (iVar1 != 3)) {
    if (iVar1 == 4) {
      *(undefined4 *)((int)this + 0x140) = 5;
      return;
    }
  }
  else {
    *(undefined4 *)((int)this + 0x140) = 6;
    if (-1 < *(int *)this) {
      Ordinal_22(*(int *)this,2);
      Ordinal_3(*(undefined4 *)this);
    }
    uVar3 = *(uint *)((int)this + 0x10);
    *(undefined4 *)this = 0xffffffff;
    puVar4 = *(undefined4 **)((int)this + 8);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    uVar3 = *(uint *)((int)this + 0x14);
    puVar4 = *(undefined4 **)((int)this + 0xc);
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    *(undefined2 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 0x18) = 0;
    *(undefined4 *)((int)this + 0x1c) = 0;
    *(undefined4 *)((int)this + 0x20) = 0;
    *(undefined4 *)((int)this + 0x24) = 0;
    *(undefined1 *)((int)this + 0x38) = 0;
    *(undefined4 *)((int)this + 0x28) = 0;
    *(undefined4 *)((int)this + 0x2c) = 0;
    *(undefined4 *)((int)this + 0x30) = 0;
    *(undefined4 *)((int)this + 0x34) = 0;
  }
  return;
}
