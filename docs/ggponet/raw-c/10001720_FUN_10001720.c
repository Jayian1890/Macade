
void FUN_10001720(void)

{
  _Container_proxy *p_Var1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  puVar2 = (undefined4 *)FUN_10007c60(*(undefined4 *)(in_ECX + 0x14));
  local_8 = (_Container_proxy *)*puVar2;
  puVar2 = (undefined4 *)FUN_10007c60(*(undefined4 *)(in_ECX + 0x14));
  *puVar2 = *(undefined4 *)(in_ECX + 0x14);
  puVar2 = (undefined4 *)FUN_100019c0(*(undefined4 *)(in_ECX + 0x14));
  *puVar2 = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  while (local_8 != *(_Container_proxy **)(in_ECX + 0x14)) {
    puVar2 = (undefined4 *)FUN_10007c60(local_8);
    p_Var1 = (_Container_proxy *)*puVar2;
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 8),local_8);
    FUN_100033b0(local_8,1);
    local_8 = p_Var1;
  }
  return;
}
