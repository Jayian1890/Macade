
undefined4
ggpo_client_connect(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x21e00  3  ggpo_client_connect */
  iVar1 = FUN_100118ec(0x2338);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10029a40(param_1,param_2,param_3,param_4);
  }
  return local_10;
}
