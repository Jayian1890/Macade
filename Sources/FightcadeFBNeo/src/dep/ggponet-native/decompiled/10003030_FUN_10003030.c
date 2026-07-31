
void FUN_10003030(void)

{
  char cVar1;
  int in_ECX;
  int local_8;
  
  while( true ) {
    cVar1 = IsEnd();
    if (cVar1 != '\0') break;
    FUN_100030f0();
  }
  local_8 = *(int *)(in_ECX + 0x14);
  while (local_8 != 0) {
    local_8 = local_8 + -1;
    if (*(int *)(*(int *)(in_ECX + 0x10) + local_8 * 4) != 0) {
      FUN_100033b0(*(undefined4 *)(*(int *)(in_ECX + 0x10) + local_8 * 4),1);
    }
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 8),
               (_Container_proxy *)(*(int *)(in_ECX + 0x10) + local_8 * 4));
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_100033b0(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  return;
}
