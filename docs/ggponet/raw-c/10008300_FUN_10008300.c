
void FUN_10008300(void)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  uint local_c;
  
  cVar2 = IsEnd();
  if (cVar2 == '\0') {
    uVar1 = *(int *)(in_ECX + 0x1c) + -1 + *(int *)(in_ECX + 0x18);
    local_c = uVar1 >> 1;
    if (*(uint *)(in_ECX + 0x14) <= local_c) {
      local_c = local_c - *(int *)(in_ECX + 0x14);
    }
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),
               (_Container_proxy *)
               (*(int *)(*(int *)(in_ECX + 0x10) + local_c * 4) + (uVar1 % 2) * 8));
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -1;
    if (*(int *)(in_ECX + 0x1c) == 0) {
      *(undefined4 *)(in_ECX + 0x18) = 0;
    }
  }
  return;
}
