
int FUN_100105a0(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,int param_7)

{
  int iVar1;
  int iVar2;
  uint in_ECX;
  
  iVar1 = (**(code **)(param_7 + 0x20))(4);
  if (iVar1 == 0) {
    return -4;
  }
  iVar2 = FUN_100100f0(0x101,&DAT_1002ed60,&DAT_1002eddc,param_3,param_1,param_5,&stack0xfffffff4,
                       iVar1);
  if (iVar2 == 0) {
    if (*param_1 == 0) goto LAB_100106dd;
    iVar2 = FUN_100100f0(0,&DAT_1002ee58,&DAT_1002eed0,param_4,param_2,param_5,&stack0xfffffff4,
                         iVar1);
    if (iVar2 == 0) {
      if ((*param_2 != 0) || (in_ECX < 0x102)) {
        (**(code **)(param_7 + 0x24))();
        return 0;
      }
LAB_100106af:
      *(char **)(param_7 + 0x18) = s_empty_distance_tree_with_lengths_100373a0;
    }
    else {
      if (iVar2 == -3) {
        *(char **)(param_7 + 0x18) = s_oversubscribed_distance_tree_100373e0;
        (**(code **)(param_7 + 0x24))();
        return -3;
      }
      if (iVar2 != -5) {
        if (iVar2 == -4) goto LAB_100106e9;
        goto LAB_100106af;
      }
      *(char **)(param_7 + 0x18) = s_incomplete_distance_tree_100373c4;
    }
  }
  else {
    if (iVar2 == -3) {
      *(char **)(param_7 + 0x18) = s_oversubscribed_literal_length_tr_1003737c;
      (**(code **)(param_7 + 0x24))();
      return -3;
    }
    if (iVar2 == -4) goto LAB_100106e9;
LAB_100106dd:
    *(char **)(param_7 + 0x18) = s_incomplete_literal_length_tree_1003735c;
  }
  iVar2 = -3;
LAB_100106e9:
  (**(code **)(param_7 + 0x24))();
  return iVar2;
}
