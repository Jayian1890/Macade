
void FUN_100258f0(int param_1)

{
  int iVar1;
  undefined4 *local_18;
  undefined4 *local_8;
  
  iVar1 = FUN_100118ec(0x1104);
  if (iVar1 == 0) {
    local_18 = (undefined4 *)0x0;
  }
  else {
    local_18 = (undefined4 *)FUN_10004a40();
  }
  local_8 = local_18;
  if (param_1 == 0) {
    *local_18 = 0;
  }
  else {
    *local_18 = 2;
    _sprintf((char *)(local_18 + 1),"");
  }
  FUN_10004ac0(&local_8);
  return;
}
