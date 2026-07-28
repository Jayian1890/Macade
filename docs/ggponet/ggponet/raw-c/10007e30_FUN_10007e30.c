
void FUN_10007e30(void)

{
  char cVar1;
  int in_ECX;
  uint uVar2;
  
  cVar1 = IsEnd();
  if (cVar1 == '\0') {
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),
               (_Container_proxy *)
               (*(int *)(*(int *)(in_ECX + 0x10) + (*(uint *)(in_ECX + 0x18) >> 1) * 4) +
               (*(uint *)(in_ECX + 0x18) % 2) * 8));
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    uVar2 = *(int *)(in_ECX + 0x14) * 2;
    if (uVar2 < *(uint *)(in_ECX + 0x18) || uVar2 - *(uint *)(in_ECX + 0x18) == 0) {
      *(undefined4 *)(in_ECX + 0x18) = 0;
    }
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -1;
    if (*(int *)(in_ECX + 0x1c) == 0) {
      *(undefined4 *)(in_ECX + 0x18) = 0;
    }
  }
  return;
}
