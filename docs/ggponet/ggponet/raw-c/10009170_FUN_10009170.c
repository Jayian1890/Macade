
undefined4 FUN_10009170(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined1 local_18 [8];
  undefined1 local_10 [8];
  undefined4 local_8;
  
  iVar1 = FUN_10008eb0();
  if (iVar1 == 0) {
    local_20 = 0;
  }
  else {
    uVar2 = FUN_10009700(local_10);
    local_20 = FUN_10009c10(uVar2);
  }
  local_8 = local_20;
  FUN_10009750(param_2,param_3,1,param_4);
  uVar2 = param_1;
  uVar3 = local_8;
  FUN_10009700(local_18);
  FUN_10009bd0(uVar2,uVar3);
  return param_1;
}
