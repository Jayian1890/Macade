
undefined4 __thiscall FUN_100023a0(void *this,undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_retaddr;
  
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined2 *)((int)this + 0x10) = 2;
  sVar1 = Ordinal_9(param_2);
  *(short *)((int)this + 0x12) = sVar1;
  if (sVar1 == 0) {
    return 1;
  }
  iVar2 = Ordinal_11(unaff_retaddr);
  *(int *)((int)this + 0x14) = iVar2;
  if (iVar2 == -1) {
    iVar2 = Ordinal_52(unaff_retaddr);
    if (iVar2 == 0) {
      return 1;
    }
    sVar1 = *(short *)(iVar2 + 10);
    piVar4 = (int *)**(undefined4 **)(iVar2 + 0xc);
    piVar5 = (int *)((int)this + 0x14);
    for (uVar3 = (uint)(int)sVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    for (uVar3 = (int)sVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(char *)piVar5 = (char)*piVar4;
      piVar4 = (int *)((int)piVar4 + 1);
      piVar5 = (int *)((int)piVar5 + 1);
    }
  }
  return 0;
}
