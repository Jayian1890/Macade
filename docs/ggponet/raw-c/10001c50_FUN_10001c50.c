
void FUN_10001c50(void)

{
  _Container_proxy *p_Var1;
  int in_ECX;
  
  FUN_10001720();
  p_Var1 = (_Container_proxy *)FUN_10007c60(*(undefined4 *)(in_ECX + 0x14));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),p_Var1);
  p_Var1 = (_Container_proxy *)FUN_100019c0(*(undefined4 *)(in_ECX + 0x14));
  std::allocator<std::_Container_proxy>::destroy
            ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),p_Var1);
  FUN_100033b0(*(undefined4 *)(in_ECX + 0x14),1);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}
