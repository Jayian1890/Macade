
undefined4 * __fastcall FUN_10001000(undefined4 *param_1)

{
  FUN_10002040(param_1);
  param_1[0x209] = 0;
  param_1[0x40a] = 0;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *param_1 = &PTR_FUN_1000d1d0;
  param_1[0x40b] = 3;
  return param_1;
}
