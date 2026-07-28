
void FUN_100022a0(uint param_1)

{
  uint uVar1;
  int iVar2;
  allocator<char> *in_ECX;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d7e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = param_1 | 0xf;
  uVar1 = FID_conflict_max_size();
  if (uVar1 < local_1c) {
    local_1c = param_1;
  }
  else if (local_1c / 3 < *(uint *)(in_ECX + 0x18) >> 1) {
    uVar1 = *(uint *)(in_ECX + 0x18);
    iVar2 = FID_conflict_max_size();
    if (*(uint *)(in_ECX + 0x18) <= iVar2 - (uVar1 >> 1)) {
      local_1c = (*(uint *)(in_ECX + 0x18) >> 1) + *(int *)(in_ECX + 0x18);
    }
  }
  local_8 = 0;
  std::allocator<char>::allocate(in_ECX,local_1c + 1);
  FUN_100023b5();
  return;
}
