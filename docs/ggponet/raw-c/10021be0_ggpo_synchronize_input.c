
undefined1
ggpo_synchronize_input(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_5;
  
                    /* 0x21be0  15  ggpo_synchronize_input */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 4))(param_2,param_3,param_4);
  }
  return local_5;
}
