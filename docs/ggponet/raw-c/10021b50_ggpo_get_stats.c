
undefined1 ggpo_get_stats(int *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21b50  6  ggpo_get_stats */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 0x10))(param_2);
  }
  return local_5;
}
