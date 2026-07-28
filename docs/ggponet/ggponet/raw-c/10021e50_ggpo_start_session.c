
undefined4
ggpo_start_session(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 local_14;
  
                    /* 0x21e50  12  ggpo_start_session */
  iVar1 = FUN_100118ec(0x19d8);
  if (iVar1 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_100287f0(param_1,param_2,param_3);
  }
  FUN_10028ac0(param_4,param_5,param_6 != 0);
  return local_14;
}
