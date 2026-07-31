
undefined4 * FUN_10006460(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 in_ECX;
  
  puVar2 = (undefined4 *)_Vector_iterator<>(param_3,in_ECX);
  uVar1 = puVar2[1];
  *param_1 = *puVar2;
  param_1[1] = uVar1;
  return param_1;
}
