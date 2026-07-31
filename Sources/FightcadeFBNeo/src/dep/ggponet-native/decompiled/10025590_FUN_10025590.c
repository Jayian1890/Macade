
void FUN_10025590(int param_1)

{
  int iVar1;
  undefined4 *local_28;
  undefined4 *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = 0;
  local_c = FUN_10025210(param_1,&local_10);
  local_8 = FUN_10025210(param_1,&local_10);
  for (local_14 = 0; local_14 < local_8; local_14 = local_14 + 1) {
    iVar1 = FUN_100118ec(0x1104);
    if (iVar1 == 0) {
      local_28 = (undefined4 *)0x0;
    }
    else {
      local_28 = (undefined4 *)FUN_10004a40();
    }
    local_18 = local_28;
    *local_28 = 0xe;
    FUN_10022310(0,param_1 + local_10 + local_14 * local_c,local_c);
    FUN_10022860("Sending streamed frame to quark",1);
    FUN_10004ac0(&local_18);
  }
  return;
}
