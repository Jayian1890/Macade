
int FUN_10010730(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int in_ECX;
  uint uVar4;
  int in_EDX;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  puVar5 = *(undefined4 **)(in_ECX + 0x34);
  local_8 = *(undefined4 **)(in_EDX + 0xc);
  if (puVar5 < puVar1) {
    puVar5 = *(undefined4 **)(in_ECX + 0x2c);
  }
  uVar4 = *(uint *)(in_EDX + 0x10);
  uVar6 = (int)puVar5 - (int)puVar1;
  if (uVar4 < (uint)((int)puVar5 - (int)puVar1)) {
    uVar6 = uVar4;
  }
  if ((uVar6 != 0) && (param_1 == -5)) {
    param_1 = 0;
  }
  *(uint *)(in_EDX + 0x10) = uVar4 - uVar6;
  *(uint *)(in_EDX + 0x14) = *(int *)(in_EDX + 0x14) + uVar6;
  if (*(code **)(in_ECX + 0x38) != (code *)0x0) {
    uVar2 = (**(code **)(in_ECX + 0x38))(uVar6);
    *(undefined4 *)(in_ECX + 0x3c) = uVar2;
    *(undefined4 *)(in_EDX + 0x30) = uVar2;
  }
  puVar5 = puVar1;
  puVar7 = local_8;
  for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  local_8 = (undefined4 *)((int)local_8 + uVar6);
  puVar3 = (undefined1 *)((int)puVar1 + uVar6);
  if (puVar3 == *(undefined1 **)(in_ECX + 0x2c)) {
    puVar1 = *(undefined4 **)(in_ECX + 0x28);
    if (*(undefined1 **)(in_ECX + 0x34) == *(undefined1 **)(in_ECX + 0x2c)) {
      *(undefined4 **)(in_ECX + 0x34) = puVar1;
    }
    uVar4 = *(uint *)(in_EDX + 0x10);
    uVar6 = *(int *)(in_ECX + 0x34) - (int)puVar1;
    if (uVar4 < uVar6) {
      uVar6 = uVar4;
    }
    if ((uVar6 != 0) && (param_1 == -5)) {
      param_1 = 0;
    }
    *(uint *)(in_EDX + 0x10) = uVar4 - uVar6;
    *(uint *)(in_EDX + 0x14) = *(int *)(in_EDX + 0x14) + uVar6;
    if (*(code **)(in_ECX + 0x38) != (code *)0x0) {
      uVar2 = (**(code **)(in_ECX + 0x38))(uVar6);
      *(undefined4 *)(in_ECX + 0x3c) = uVar2;
      *(undefined4 *)(in_EDX + 0x30) = uVar2;
    }
    puVar5 = puVar1;
    puVar7 = local_8;
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    local_8 = (undefined4 *)((int)local_8 + uVar6);
    for (uVar4 = uVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    puVar3 = (undefined1 *)((int)puVar1 + uVar6);
  }
  *(undefined4 **)(in_EDX + 0xc) = local_8;
  *(undefined1 **)(in_ECX + 0x30) = puVar3;
  return param_1;
}
