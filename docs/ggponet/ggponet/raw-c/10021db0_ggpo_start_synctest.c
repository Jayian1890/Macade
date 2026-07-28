
undefined4 ggpo_start_synctest(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x21db0  14  ggpo_start_synctest */
  iVar1 = FUN_100118ec(0x360);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10027980(param_1,param_2,param_3);
  }
  return local_10;
}
