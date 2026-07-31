
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10024240(byte *param_1,undefined4 param_2)

{
  if ((DAT_13439520 & 1) == 0) {
    DAT_13439520 = DAT_13439520 | 1;
    _DAT_134394ec = FUN_10022d40;
    _DAT_134394f0 = 0;
    _DAT_134394f4 = FUN_100241b0;
    _DAT_134394f8 = 0;
    _DAT_134394fc = FUN_10024050;
    _DAT_13439500 = 0;
    _DAT_13439504 = FUN_100233f0;
    _DAT_13439508 = 0;
    _DAT_1343950c = FUN_10023fe0;
    _DAT_13439510 = 0;
    _DAT_13439514 = FUN_10022c20;
    _DAT_13439518 = 0;
  }
  FUN_10022e60(&DAT_10031f04,param_1);
  if (*param_1 < 6) {
    (**(code **)(&DAT_134394ec + (uint)*param_1 * 8))(param_1,param_2);
  }
  else {
    FUN_10022d40(param_1,param_2);
  }
  return;
}
