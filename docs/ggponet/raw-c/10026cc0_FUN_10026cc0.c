
void FUN_10026cc0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int local_18;
  int local_8;
  
  iVar1 = FUN_100118ec(0xc);
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_10003e40(2);
  }
  local_8 = local_18;
  *(undefined4 *)(local_18 + 4) = *(undefined4 *)(in_ECX + 0x54);
  *(undefined4 *)(local_18 + 8) = param_1;
  FUN_10004ac0(&local_8);
  *(undefined4 *)(in_ECX + 0x54) = 0;
  return;
}
