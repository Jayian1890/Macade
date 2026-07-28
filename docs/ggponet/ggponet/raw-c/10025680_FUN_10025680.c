
void FUN_10025680(undefined4 param_1)

{
  int iVar1;
  undefined4 *local_1c;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = FUN_100118ec(0x1104);
  if (iVar1 == 0) {
    local_1c = (undefined4 *)0x0;
  }
  else {
    local_1c = (undefined4 *)FUN_10004a40();
  }
  local_c = local_1c;
  *local_1c = 0xc;
  FUN_10025240(local_1c + 1,param_1,&local_8);
  FUN_10025240(local_c + 0x21,param_1,&local_8);
  FUN_10025240(local_c + 0x41,param_1,&local_8);
  FUN_10004ac0(&local_c);
  return;
}
