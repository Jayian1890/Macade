
void FUN_100036e0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(uint *)(in_ECX + 0x14) <= *(int *)(in_ECX + 0x1c) + 1U) {
    FUN_10003920(1);
  }
  local_c = *(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x1c);
  if (*(uint *)(in_ECX + 0x14) <= local_c) {
    local_c = local_c - *(int *)(in_ECX + 0x14);
  }
  if (*(int *)(*(int *)(in_ECX + 0x10) + local_c * 4) == 0) {
    uVar1 = FUN_10003b40(1);
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + local_c * 4) = uVar1;
  }
  FUN_10003b60(*(undefined4 *)(*(int *)(in_ECX + 0x10) + local_c * 4),param_1);
  *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
  return;
}
