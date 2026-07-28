
undefined4 * __fastcall FUN_10001c40(undefined4 *param_1)

{
  undefined1 *puVar1;
  
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[0xb] = 0;
  param_1[10] = 0x10;
  puVar1 = malloc(0x10);
  param_1[9] = puVar1;
  *puVar1 = 0;
  return param_1;
}
