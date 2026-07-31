
void FUN_10007ee0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_c;
  
  if (((uint)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x1c)) % 2 == 0) &&
     (*(uint *)(in_ECX + 0x14) <= *(int *)(in_ECX + 0x1c) + 2U >> 1)) {
    FUN_100083a0(1);
  }
  uVar1 = *(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x1c);
  local_c = uVar1 >> 1;
  if (*(uint *)(in_ECX + 0x14) <= local_c) {
    local_c = local_c - *(int *)(in_ECX + 0x14);
  }
  if (*(int *)(*(int *)(in_ECX + 0x10) + local_c * 4) == 0) {
    uVar2 = FUN_100085c0(2);
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + local_c * 4) = uVar2;
  }
  FUN_1000a3d0(*(int *)(*(int *)(in_ECX + 0x10) + local_c * 4) + (uVar1 % 2) * 8,param_1);
  *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
  return;
}
