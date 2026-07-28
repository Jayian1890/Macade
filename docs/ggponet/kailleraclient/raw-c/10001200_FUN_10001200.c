
undefined4 FUN_10001200(undefined4 param_1,undefined1 param_2)

{
  ushort uVar1;
  ushort uVar2;
  void *this;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int in_stack_0000800c;
  
  FUN_1000c760();
  iVar8 = 1;
  if (*(int *)((int)this + 0x824) < in_stack_0000800c) {
    in_stack_0000800c = *(int *)((int)this + 0x824);
  }
  iVar5 = 0;
  param_2 = (undefined1)in_stack_0000800c;
  if (0 < in_stack_0000800c) {
    do {
      iVar3 = *(int *)((int)this + 0x824) - iVar5;
      uVar1 = *(ushort *)((int)this + iVar3 * 8 + 0x1e);
      puVar6 = (undefined4 *)((int)this + iVar3 * 8 + 0x1c);
      *(undefined4 *)(&param_2 + iVar8) = *puVar6;
      uVar2 = *(ushort *)((int)puVar6 + 2);
      puVar6 = (undefined4 *)puVar6[1];
      puVar7 = (undefined4 *)(&stack0x0000000c + iVar8);
      for (uVar4 = (uint)(uVar2 >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      iVar8 = iVar8 + uVar1 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < in_stack_0000800c);
  }
  FUN_10002480(this,&param_2,iVar8);
  return 0;
}
