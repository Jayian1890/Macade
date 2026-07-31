
void FUN_1000abf0(void)

{
  char cVar1;
  int in_ECX;
  uint local_c;
  
  cVar1 = IsEnd();
  if (cVar1 == '\0') {
    local_c = *(int *)(in_ECX + 0x1c) + -1 + *(int *)(in_ECX + 0x18);
    if (*(uint *)(in_ECX + 0x14) <= local_c) {
      local_c = local_c - *(int *)(in_ECX + 0x14);
    }
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),
               *(_Container_proxy **)(*(int *)(in_ECX + 0x10) + local_c * 4));
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -1;
    if (*(int *)(in_ECX + 0x1c) == 0) {
      *(undefined4 *)(in_ECX + 0x18) = 0;
    }
  }
  return;
}
