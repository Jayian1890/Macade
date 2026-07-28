
undefined1 ggpo_client_chat(int *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21b80  2  ggpo_client_chat */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 0xc))(param_2);
  }
  return local_5;
}
