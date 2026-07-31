
undefined4 * FUN_10004c60(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *local_28;
  undefined1 local_20 [8];
  undefined1 local_18 [12];
  undefined4 local_c [2];
  
  FUN_10005550(local_c,param_2);
  uVar2 = FUN_10004c30(local_18);
  cVar1 = FUN_10005710(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_10002210();
    uVar2 = FUN_10004ea0(uVar2);
    cVar1 = FUN_10005650(param_2,uVar2);
    if (cVar1 == '\0') {
      local_28 = local_c;
      goto LAB_10004cd4;
    }
  }
  local_28 = (undefined4 *)FUN_10004c30(local_20);
LAB_10004cd4:
  uVar2 = local_28[1];
  *param_1 = *local_28;
  param_1[1] = uVar2;
  return param_1;
}
