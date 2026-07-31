
undefined4 ggpo_start_replay(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x21d10  11  ggpo_start_replay */
  iVar1 = FUN_100118ec(0x40);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10027f60(param_1,param_2);
  }
  return local_10;
}
