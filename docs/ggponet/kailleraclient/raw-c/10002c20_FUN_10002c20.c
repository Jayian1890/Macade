
void __fastcall FUN_10002c20(int *param_1)

{
  undefined4 *puVar1;
  
  if (-1 < *param_1) {
    Ordinal_22(*param_1,2);
    Ordinal_3(*param_1);
    *param_1 = -1;
  }
  free((void *)param_1[2]);
  free((void *)param_1[3]);
  if ((param_1[0x4f] != 0) && (puVar1 = (undefined4 *)param_1[0x4e], puVar1 != (undefined4 *)0x0)) {
    FUN_100026d0(puVar1);
    operator_delete(puVar1);
  }
  return;
}
