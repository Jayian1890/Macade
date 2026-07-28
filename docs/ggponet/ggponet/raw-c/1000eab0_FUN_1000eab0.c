
undefined4 * FUN_1000eab0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 in_EDX;
  int unaff_EBX;
  
  puVar1 = (undefined4 *)(**(code **)(in_ECX + 0x20))(0x40);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar2 = (**(code **)(in_ECX + 0x20))(0x5a0);
  puVar1[9] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(in_ECX + 0x24))();
    return (undefined4 *)0x0;
  }
  iVar2 = (**(code **)(in_ECX + 0x20))(unaff_EBX);
  puVar1[10] = iVar2;
  if (iVar2 == 0) {
    (**(code **)(in_ECX + 0x24))();
    (**(code **)(in_ECX + 0x24))();
    return (undefined4 *)0x0;
  }
  puVar1[0xb] = iVar2 + unaff_EBX;
  puVar1[0xe] = in_EDX;
  *puVar1 = 0;
  FUN_1000ea40(0);
  return puVar1;
}
