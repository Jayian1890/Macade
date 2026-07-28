
void FUN_10023fe0(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_18;
  
  iVar1 = FUN_100118ec(0x100c);
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_10008950(5);
  }
  *(undefined4 *)(local_18 + 1) = *(undefined4 *)(param_1 + 2);
  FUN_10023930(local_18);
  *(int *)(in_ECX + 0x10a4) = (int)*(char *)(param_1 + 1);
  return;
}
