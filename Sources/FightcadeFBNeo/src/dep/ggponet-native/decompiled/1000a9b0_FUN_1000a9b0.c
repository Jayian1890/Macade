
void FUN_1000a9b0(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = IsEnd();
  if (cVar1 == '\0') {
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),
               *(_Container_proxy **)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x18) * 4));
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    if (*(uint *)(in_ECX + 0x14) <= *(uint *)(in_ECX + 0x18)) {
      *(undefined4 *)(in_ECX + 0x18) = 0;
    }
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -1;
    if (*(int *)(in_ECX + 0x1c) == 0) {
      *(undefined4 *)(in_ECX + 0x18) = 0;
    }
  }
  return;
}
