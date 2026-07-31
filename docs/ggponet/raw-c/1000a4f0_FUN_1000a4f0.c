
void FUN_1000a4f0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_10001080(8,param_1);
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = param_2[1];
    *puVar2 = *param_2;
    puVar2[1] = uVar1;
  }
  return;
}
