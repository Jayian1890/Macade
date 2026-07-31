
undefined1 ggpo_set_frame_delay(int *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21c50  10  ggpo_set_frame_delay */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 0x1c))(param_2);
  }
  return local_5;
}
