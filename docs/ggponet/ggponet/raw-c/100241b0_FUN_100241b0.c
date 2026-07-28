
void FUN_100241b0(int param_1)

{
  int iVar1;
  undefined4 local_18;
  
  iVar1 = FUN_100118ec(0x100c);
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_10008950(2);
  }
  *(undefined4 *)(local_18 + 1) = *(undefined4 *)(param_1 + 1);
  FUN_10023930(local_18);
  return;
}
