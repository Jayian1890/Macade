
undefined4 FUN_100205f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_10008a70();
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_1000a8b0();
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *puVar2;
      puVar2 = puVar2 + 1;
      param_1 = param_1 + 1;
    }
    FUN_1000a8f0();
    uVar3 = 1;
  }
  return uVar3;
}
