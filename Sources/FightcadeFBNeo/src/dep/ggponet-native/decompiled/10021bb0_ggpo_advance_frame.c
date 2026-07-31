
undefined1 ggpo_advance_frame(int *param_1)

{
  undefined1 local_5;
  
                    /* 0x21bb0  1  ggpo_advance_frame */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 8))();
  }
  return local_5;
}
