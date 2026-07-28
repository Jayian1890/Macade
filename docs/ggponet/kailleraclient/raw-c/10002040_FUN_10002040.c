
undefined4 * __fastcall FUN_10002040(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_1000d1fc;
  param_1[2] = 0;
  if ((DAT_1000ea80 == 0) || ((DAT_1000ea84 & 0x1f) == 0)) {
    DAT_1000ea80 = (int)realloc((void *)DAT_1000ea80,DAT_1000ea84 * 4 + 0x80);
  }
  *(undefined4 **)(DAT_1000ea80 + DAT_1000ea84 * 4) = param_1;
  DAT_1000ea84 = DAT_1000ea84 + 1;
  param_1[3] = 0;
  if (DAT_1000ec98 == 0) {
    DAT_1000ea88 = 0;
    DAT_1000eb90 = 0;
  }
  return param_1;
}
