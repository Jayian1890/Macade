
void FUN_10020310(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_1001fd20(param_1);
  puVar1 = (undefined4 *)(in_ECX + 0x110 + iVar2 * 0x10);
  *param_2 = *puVar1;
  *param_3 = puVar1[1];
  return;
}
