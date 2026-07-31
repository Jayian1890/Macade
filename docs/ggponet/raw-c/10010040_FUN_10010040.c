
int FUN_10010040(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *in_EDX;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(param_3 + 0x20))(4);
  if (iVar1 == 0) {
    return -4;
  }
  iVar1 = FUN_100100f0(0x13,0,0,unaff_retaddr,in_EDX,param_1,&stack0xfffffff8,iVar1);
  if (iVar1 == -3) {
    *(char **)(param_3 + 0x18) = s_oversubscribed_dynamic_bit_lengt_10037334;
    (**(code **)(param_3 + 0x24))();
    return -3;
  }
  if ((iVar1 == -5) || (*in_EDX == 0)) {
    *(char **)(param_3 + 0x18) = s_incomplete_dynamic_bit_lengths_t_10037310;
    iVar1 = -3;
  }
  (**(code **)(param_3 + 0x24))();
  return iVar1;
}
