
void FUN_1000b100(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_10001080(0x20,param_1);
  if (puVar1 != (undefined4 *)0x0) {
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = *param_2;
      param_2 = param_2 + 1;
      puVar1 = puVar1 + 1;
    }
  }
  return;
}
