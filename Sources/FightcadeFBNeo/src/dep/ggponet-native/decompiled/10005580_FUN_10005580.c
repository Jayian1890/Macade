
void FUN_10005580(void)

{
  undefined4 *puVar1;
  _Container_proxy *p_Var2;
  int in_ECX;
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = (undefined4 *)FUN_10004c30(local_14);
  local_c = *puVar1;
  local_8 = puVar1[1];
  puVar1 = (undefined4 *)FUN_10005ab0(local_24);
  local_1c = *puVar1;
  local_18 = puVar1[1];
  FUN_10005cb0(local_2c,local_1c,local_18,local_c,local_8);
  p_Var2 = (_Container_proxy *)FUN_10007c60(*(undefined4 *)(in_ECX + 0x18));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(in_ECX + 0x10),p_Var2);
  p_Var2 = (_Container_proxy *)FUN_100019c0(*(undefined4 *)(in_ECX + 0x18));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(in_ECX + 0x10),p_Var2);
  p_Var2 = (_Container_proxy *)FUN_100086e0(*(undefined4 *)(in_ECX + 0x18));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(in_ECX + 0x10),p_Var2);
  FUN_100033b0(*(undefined4 *)(in_ECX + 0x18),1);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}
