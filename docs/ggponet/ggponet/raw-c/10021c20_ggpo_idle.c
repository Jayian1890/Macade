
undefined1 ggpo_idle(undefined4 *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21c20  7  ggpo_idle */
  if (param_1 == (undefined4 *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)*param_1)(param_2);
  }
  return local_5;
}
