
void FUN_100048d0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_10001080(0x10,param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
    puVar1[3] = param_2[3];
  }
  return;
}
