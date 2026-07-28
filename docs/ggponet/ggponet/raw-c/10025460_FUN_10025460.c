
void FUN_10025460(void)

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
  *local_18 = 0x11;
  FUN_10004ac0(&local_8);
  return;
}
