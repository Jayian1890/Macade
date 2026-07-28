
int FUN_10004b10(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [3];
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_10005550(&local_c,param_1);
  uVar2 = FUN_10004c30(local_14);
  cVar1 = FUN_10005710(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_10002210();
    uVar2 = FUN_10004ea0(uVar2);
    cVar1 = FUN_10005650(param_1,uVar2);
    if (cVar1 == '\0') goto LAB_10004bb0;
  }
  local_20[0] = 0;
  local_28 = local_c;
  local_24 = local_8;
  uVar2 = FUN_10005760(param_1,local_20);
  puVar3 = (undefined4 *)FUN_10004f30(local_30,local_28,local_24,uVar2);
  local_c = *puVar3;
  local_8 = puVar3[1];
LAB_10004bb0:
  iVar4 = FUN_100056f0();
  return iVar4 + 4;
}
